#ifndef lint
static const char rcsid[] =
  "$FreeBSD$";
#endif

/*
 * FreeBSD install - a package for the installation and maintainance
 * of non-core utilities.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * Jordan K. Hubbard
 * 18 July 1993
 *
 * Miscellaneous file access utilities.
 *
 */

#include "lib.h"
#include <err.h>
#include <fetch.h>
#include <pwd.h>
#include <time.h>
#include <sys/wait.h>

/* Quick check to see if a file exists */
Boolean
fexists(char *fname)
{
    struct stat dummy;
    if (!lstat(fname, &dummy))
	return TRUE;
    return FALSE;
}

/* Quick check to see if something is a directory or symlink to a directory */
Boolean
isdir(char *fname)
{
    struct stat sb;

    if (lstat(fname, &sb) != FAIL && S_ISDIR(sb.st_mode))
	return TRUE;
    else if (lstat(strconcat(fname, "/"), &sb) != FAIL && S_ISDIR(sb.st_mode))
	return TRUE;
    else
	return FALSE;
}

/* Check to see if file is a dir or symlink to a dir, and is empty */
Boolean
isemptydir(char *fname)
{
    if (isdir(fname)) {
	DIR *dirp;
	struct dirent *dp;

	dirp = opendir(fname);
	if (!dirp)
	    return FALSE;	/* no perms, leave it alone */
	for (dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
	    if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")) {
		closedir(dirp);
		return FALSE;
	    }
	}
	(void)closedir(dirp);
	return TRUE;
    }
    return FALSE;
}

/*
 * Returns TRUE if file is a regular file or symlink pointing to a regular
 * file
 */
Boolean
isfile(char *fname)
{
    struct stat sb;
    if (stat(fname, &sb) != FAIL && S_ISREG(sb.st_mode))
	return TRUE;
    return FALSE;
}

/* 
 * Check to see if file is a file or symlink pointing to a file and is empty.
 * If nonexistent or not a file, say "it's empty", otherwise return TRUE if
 * zero sized.
 */
Boolean
isemptyfile(char *fname)
{
    struct stat sb;
    if (stat(fname, &sb) != FAIL && S_ISREG(sb.st_mode)) {
	if (sb.st_size != 0)
	    return FALSE;
    }
    return TRUE;
}

/* Returns TRUE if file is a symbolic link. */
Boolean
issymlink(char *fname)
{
    struct stat sb;
    if (lstat(fname, &sb) != FAIL && S_ISLNK(sb.st_mode))
	return TRUE;
    return FALSE;
}

/* Returns TRUE if file is a URL specification */
Boolean
isURL(char *fname)
{
    /*
     * I'm sure there are other types of URL specifications that I could
     * also be looking for here, but for now I'll just be happy to get ftp
     * and http working.
     */
    if (!fname)
	return FALSE;
    while (isspace(*fname))
	++fname;
    if (!strncmp(fname, "ftp://", 6) || !strncmp(fname, "http://", 7))
	return TRUE;
    return FALSE;
}

#define HOSTNAME_MAX	64
/*
 * Try and fetch a file by URL, returning the directory name for where
 * it's unpacked, if successful.
 */
char *
fileGetURL(char *base, char *spec)
{
    char host[HOSTNAME_MAX], file[FILENAME_MAX];
    char pword[HOSTNAME_MAX + 40], *uname, *cp, *rp;
    char fname[FILENAME_MAX];
    char pen[FILENAME_MAX];
    char buf[8192];
    struct passwd *pw;
    FILE *ftp;
    pid_t tpid;
    int pfd[2], pstat;
    int i, status;
    size_t r, w;
    char *hint;

    rp = NULL;
    /* Special tip that sysinstall left for us */
    hint = getenv("PKG_ADD_BASE");
    if (!isURL(spec)) {
	if (!base && !hint)
	    return NULL;
	/* We've been given an existing URL (that's known-good) and now we need
	   to construct a composite one out of that and the basename we were
	   handed as a dependency. */
	if (base) {
	    strcpy(fname, base);
	    /* Advance back two slashes to get to the root of the package hierarchy */
	    cp = strrchr(fname, '/');
	    if (cp) {
		*cp = '\0';	/* chop name */
		cp = strrchr(fname, '/');
	    }
	    if (cp) {
		*(cp + 1) = '\0';
		strcat(cp, "All/");
		strcat(cp, spec);
		strcat(cp, ".tgz");
	    }
	    else
		return NULL;
	}
	else {
	    /* Otherwise, we've been given an environment variable hinting at the right location from sysinstall */
	    strcpy(fname, hint);
	    strcat(fname, spec);
            strcat(fname, ".tgz");
	}
    }
    else
	strcpy(fname, spec);

    if ((ftp = fetchGetURL(fname, NULL)) == NULL) {
	printf("Error: FTP Unable to get %s: %s\n",
	       fname, fetchLastErrString);
	return NULL;
    }
    
    if (isatty(0) || Verbose)
	printf("Fetching %s...", fname), fflush(stdout);
    pen[0] = '\0';
    if ((rp = make_playpen(pen, 0)) == NULL) {
	printf("Error: Unable to construct a new playpen for FTP!\n");
	fclose(ftp);
	return NULL;
    }
    if (pipe(pfd) == -1) {
	warn("pipe()");
	cleanup(0);
	exit(2);
    }
    if ((tpid = fork()) == -1) {
	warn("pipe()");
	cleanup(0);
	exit(2);
    }
    if (!tpid) {
	close(pfd[1]);
	dup2(pfd[0], 0);
	close(pfd[0]);
	execl("/usr/bin/tar", "tar", Verbose ? "-xzvf" : "-xzf", "-", 0);
	_exit(2);
    }
    close(pfd[0]);
    for (;;) {
	if ((r = fread(buf, 1, sizeof buf, ftp)) < 1)
	    break;
	if ((w = write(pfd[1], buf, r)) != r)
	    break;
    }
    fclose(ftp);
    close(pfd[1]);
    if (r == -1)
	warn("warning: error reading from server");
    if (w == -1)
	warn("warning: error writing to tar");
    tpid = waitpid(tpid, &pstat, 0);
    if (Verbose)
	printf("tar command returns %d status\n", WEXITSTATUS(pstat));
    if (rp && (isatty(0) || Verbose))
	printf(" Done.\n");
    return rp;
}

char *
fileFindByPath(char *base, char *fname)
{
    static char tmp[FILENAME_MAX];
    char *cp;

    if (fexists(fname) && isfile(fname)) {
	strcpy(tmp, fname);
	return tmp;
    }
    if (base) {
	strcpy(tmp, base);

	cp = strrchr(tmp, '/');
	if (cp) {
	    *cp = '\0';	/* chop name */
	    cp = strrchr(tmp, '/');
	}
	if (cp) {
	    *(cp + 1) = '\0';
	    strcat(cp, "All/");
	    strcat(cp, fname);
	    strcat(cp, ".tgz");
	    if (fexists(tmp))
		return tmp;
	}
    }

    cp = getenv("PKG_PATH");
    while (cp) {
	char *cp2 = strsep(&cp, ":");

	snprintf(tmp, FILENAME_MAX, "%s/%s.tgz", cp2 ? cp2 : cp, fname);
	if (fexists(tmp) && isfile(tmp))
	    return tmp;
    }
    return NULL;
}

char *
fileGetContents(char *fname)
{
    char *contents;
    struct stat sb;
    int fd;

    if (stat(fname, &sb) == FAIL) {
	cleanup(0);
	errx(2, __FUNCTION__ ": can't stat '%s'", fname);
    }

    contents = (char *)malloc(sb.st_size + 1);
    fd = open(fname, O_RDONLY, 0);
    if (fd == FAIL) {
	cleanup(0);
	errx(2, __FUNCTION__ ": unable to open '%s' for reading", fname);
    }
    if (read(fd, contents, sb.st_size) != sb.st_size) {
	cleanup(0);
	errx(2, __FUNCTION__ ": short read on '%s' - did not get %qd bytes",
	     fname, sb.st_size);
    }
    close(fd);
    contents[sb.st_size] = '\0';
    return contents;
}

/* Takes a filename and package name, returning (in "try") the canonical "preserve"
 * name for it.
 */
Boolean
make_preserve_name(char *try, int max, char *name, char *file)
{
    int len, i;

    if ((len = strlen(file)) == 0)
	return FALSE;
    else
	i = len - 1;
    strncpy(try, file, max);
    if (try[i] == '/') /* Catch trailing slash early and save checking in the loop */
	--i;
    for (; i; i--) {
	if (try[i] == '/') {
	    try[i + 1]= '.';
	    strncpy(&try[i + 2], &file[i + 1], max - i - 2);
	    break;
	}
    }
    if (!i) {
	try[0] = '.';
	strncpy(try + 1, file, max - 1);
    }
    /* I should probably be called rude names for these inline assignments */
    strncat(try, ".",  max -= strlen(try));
    strncat(try, name, max -= strlen(name));
    strncat(try, ".",  max--);
    strncat(try, "backup", max -= 6);
    return TRUE;
}

/* Write the contents of "str" to a file */
void
write_file(char *name, char *str)
{
    FILE *fp;
    int len;

    fp = fopen(name, "w");
    if (!fp) {
	cleanup(0);
	errx(2, __FUNCTION__ ": cannot fopen '%s' for writing", name);
    }
    len = strlen(str);
    if (fwrite(str, 1, len, fp) != len) {
	cleanup(0);
	errx(2, __FUNCTION__ ": short fwrite on '%s', tried to write %d bytes", name, len);
    }
    if (fclose(fp)) {
	cleanup(0);
	errx(2, __FUNCTION__ ": failure to fclose '%s'", name);
    }
}

void
copy_file(char *dir, char *fname, char *to)
{
    char cmd[FILENAME_MAX];

    if (fname[0] == '/')
	snprintf(cmd, FILENAME_MAX, "cp -r %s %s", fname, to);
    else
	snprintf(cmd, FILENAME_MAX, "cp -r %s/%s %s", dir, fname, to);
    if (vsystem(cmd)) {
	cleanup(0);
	errx(2, __FUNCTION__ ": could not perform '%s'", cmd);
    }
}

void
move_file(char *dir, char *fname, char *to)
{
    char cmd[FILENAME_MAX];

    if (fname[0] == '/')
	snprintf(cmd, FILENAME_MAX, "mv %s %s", fname, to);
    else
	snprintf(cmd, FILENAME_MAX, "mv %s/%s %s", dir, fname, to);
    if (vsystem(cmd)) {
	cleanup(0);
	errx(2, __FUNCTION__ ": could not perform '%s'", cmd);
    }
}

/*
 * Copy a hierarchy (possibly from dir) to the current directory, or
 * if "to" is TRUE, from the current directory to a location someplace
 * else.
 *
 * Though slower, using tar to copy preserves symlinks and everything
 * without me having to write some big hairy routine to do it.
 */
void
copy_hierarchy(char *dir, char *fname, Boolean to)
{
    char cmd[FILENAME_MAX * 3];

    if (!to) {
	/* If absolute path, use it */
	if (*fname == '/')
	    dir = "/";
	snprintf(cmd, FILENAME_MAX * 3, "tar cf - -C %s %s | tar xpf -",
 		 dir, fname);
    }
    else
	snprintf(cmd, FILENAME_MAX * 3, "tar cf - %s | tar xpf - -C %s",
 		 fname, dir);
#ifdef DEBUG
    printf("Using '%s' to copy trees.\n", cmd);
#endif
    if (system(cmd)) {
	cleanup(0);
	errx(2, __FUNCTION__ ": could not perform '%s'", cmd);
    }
}

/* Unpack a tar file */
int
unpack(char *pkg, char *flist)
{
    char args[10], suffix[80], *cp;

    args[0] = '\0';
    /*
     * Figure out by a crude heuristic whether this or not this is probably
     * compressed.
     */
    if (strcmp(pkg, "-")) {
	cp = strrchr(pkg, '.');
	if (cp) {
	    strcpy(suffix, cp + 1);
	    if (strchr(suffix, 'z') || strchr(suffix, 'Z'))
		strcpy(args, "-z");
	}
    }
    else
	strcpy(args, "-z");
    strcat(args, " -xpf");
    if (vsystem("tar %s '%s' %s", args, pkg, flist ? flist : "")) {
	warnx("tar extract of %s failed!", pkg);
	return 1;
    }
    return 0;
}

/* Using fmt, replace all instances of:
 *
 * %F	With the parameter "name"
 * %D	With the parameter "dir"
 * %B	Return the directory part ("base") of %D/%F
 * %f	Return the filename part of %D/%F
 *
 * Does not check for overflow - caution!
 *
 */
void
format_cmd(char *buf, char *fmt, char *dir, char *name)
{
    char *cp, scratch[FILENAME_MAX * 2];

    while (*fmt) {
	if (*fmt == '%') {
	    switch (*++fmt) {
	    case 'F':
		strcpy(buf, name);
		buf += strlen(name);
		break;

	    case 'D':
		strcpy(buf, dir);
		buf += strlen(dir);
		break;

	    case 'B':
		sprintf(scratch, "%s/%s", dir, name);
		cp = &scratch[strlen(scratch) - 1];
		while (cp != scratch && *cp != '/')
		    --cp;
		*cp = '\0';
		strcpy(buf, scratch);
		buf += strlen(scratch);
		break;

	    case 'f':
		sprintf(scratch, "%s/%s", dir, name);
		cp = &scratch[strlen(scratch) - 1];
		while (cp != scratch && *(cp - 1) != '/')
		    --cp;
		strcpy(buf, cp);
		buf += strlen(cp);
		break;

	    default:
		*buf++ = *fmt;
		break;
	    }
	    ++fmt;
	}
	else
	    *buf++ = *fmt++;
    }
    *buf = '\0';
}
