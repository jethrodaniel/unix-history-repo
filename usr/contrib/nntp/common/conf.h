/*
 * Configuration information for use by NNTP server and support
 * programs.  Change these as appropriate for your system.
 */

/*
 * Compile time options.
 */

#undef	ALONE		/* True if we're running without inetd */
#undef	FASTFORK	/* True if we don't want to read active file on start */
#undef	BSD_42		/* 4.2 compatability code -- if this is defined, */
			/* DBM probably wants to be defined as well. */
#undef	DBM		/* True if we want to use the old dbm(3x) libraries */
			/* If you define this, change CFLAGS in makefile to */
			/* be -ldbm */
#define	LOG		/* True if we want copious logging info */

#ifdef BSD_42		/* This is a logical, warranted assumption */
#   ifndef DBM		/* which will probably get me in trouble. */
#	define DBM	/* Kill it if you have 4.2 *and* ndbm.  */
#   endif
#endif

/*
 * Your domain.  This is for the inews generated From: line,
 * assuming that it doesn't find one in the article's head.
 * Suggestions are .UUCP if you don't belong to the Internet.
 * If your hostname returns the fully-qualified domain name
 * as some 4.3 BSD systems do, simply undefine DOMAIN.
 *
 * e.g.  #define	DOMAIN		"berkeley.edu"
 */

#undef	DOMAIN

/*
 * The host which is actually running the server; this is for
 * inews, so it knows where to send the articles.
 */

#define	SERVER_HOST	"ucbvax"

/*
 * Person (user name) to post news as.
 */

#define	POSTER		"nobody"

/*
 * Logging facility; normally this will be LOG_DAEMON, but
 * if you have LOG defined, you can get a large amount of
 * output, and it's nice to have it wind up in a special
 * file.
 *
 * This is only of concern if you have 4.3 BSD.
 */

#ifndef BSD_42
#define LOG_FACILITY	LOG_LOCAL7
#endif

/*
 * The person to send bugs to; this is printed in response
 * to the "help" command.  Unless you've modified the
 * server to some degree, I suggest leaving this as it is,
 * so I hear about problems.
 */

#define	BUGS_TO		"Phil Lapsley (phil@berkeley.edu, ...!ucbvax!phil)"

/*
 * These files are generated by the support programs, and are needed
 * by the NNTP server.  Make sure that whatever directory you
 * decide these files should go is writable by whatever uid you
 * have the sypport programs run under.
 */

#define STAT_FILE	"/usr/spool/news/lib/mgdstats"
#define NGDATE_FILE	"/usr/spool/news/lib/groupdates"

/*
 * Some commonly used programs and files.
 */

#define	ACTIVE_FILE	"/usr/spool/news/lib/active"
#define ACCESS_FILE	"/usr/spool/news/lib/nntp_access"
#define HISTORY_FILE	"/usr/spool/news/lib/history"
#define	SPOOLDIR	"/usr/spool/news/"		/* Need trailing / */
#define INEWS		"/usr/spool/news/lib/inews"
#define RNEWS		"/usr/bin/rnews"		/* Link to inews? */

/*
 * Some miscellaneous stuff
 */

#define MAX_GROUPS	450		/* Maximum groups in active file */
#define	MAX_ARTICLES	4096		/* Maximum number of articles/group */
#define READINTVL	60 * 10		/* 10 minutes b/n chking active file */

/*
 * This is defined in RFC 977; don't change.
 */

#define MAX_STRLEN	512		/* Maximum message line length */
