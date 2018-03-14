/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 1980, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef lint
static const char copyright[] =
"@(#) Copyright (c) 1980, 1993\n\
	The Regents of the University of California.  All rights reserved.\n";
#endif

#if 0
#ifndef lint
static char sccsid[] = "@(#)biff.c	8.1 (Berkeley) 6/6/93";
#endif
#endif

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/stat.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	struct stat sb;
	int ch;
	char *name;


	while ((ch = getopt(argc, argv, "")) != -1)
		switch(ch) {
		case '?':
		default:
			usage();
		}
	argc -= optind;
	argv += optind;

	if ((name = ttyname(STDIN_FILENO)) == NULL &&
	    (name = ttyname(STDOUT_FILENO)) == NULL &&
	    (name = ttyname(STDERR_FILENO)) == NULL)
		err(2, "unknown tty");

	if (stat(name, &sb))
		err(2, "stat");

	if (*argv == NULL) {
		(void)printf("is %s\n",
		    sb.st_mode & S_IXUSR ? "y" :
		    sb.st_mode & S_IXGRP ? "b" : "n");
		return (sb.st_mode & (S_IXUSR | S_IXGRP) ? 0 : 1);

	}

	switch (argv[0][0]) {
	case 'n':
		if (chmod(name, sb.st_mode & ~(S_IXUSR | S_IXGRP)) < 0)
			err(2, "%s", name);
		break;
	case 'y':
		if (chmod(name, (sb.st_mode & ~(S_IXUSR | S_IXGRP)) | S_IXUSR)
		    < 0)
			err(2, "%s", name);
		break;
	case 'b':
		if (chmod(name, (sb.st_mode & ~(S_IXUSR | S_IXGRP)) | S_IXGRP)
		    < 0)
			err(2, "%s", name);
		break;
	default:
		usage();
	}
	return (sb.st_mode & (S_IXUSR | S_IXGRP) ? 0 : 1);
}

static void
usage(void)
{
	(void)fprintf(stderr, "usage: biff [n | y | b]\n");
	exit(2);
}
