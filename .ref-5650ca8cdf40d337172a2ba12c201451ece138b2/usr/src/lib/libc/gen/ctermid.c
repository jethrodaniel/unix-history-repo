/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)ctermid.c	5.2 (Berkeley) %G%";
#endif /* LIBC_SCCS and not lint */

#include <stdio.h>
#include <paths.h>
#include <string.h>

char *
ctermid(s)
	char *s;
{
	static char def[] = _PATH_TTY;

	if (s) {
		bcopy(def, s, sizeof(_PATH_TTY));
		return(s);
	}
	return(def);
}
