/*
 *                     RCS keyword table and match operation
 */

/* Copyright (C) 1982, 1988, 1989 Walter Tichy
   Copyright 1990, 1991 by Paul Eggert
   Distributed under license by the Free Software Foundation, Inc.

This file is part of RCS.

RCS is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

RCS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RCS; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

Report problems and direct all questions to:

    rcs-bugs@cs.purdue.edu

*/



/* $Log: rcskeys.c,v $
 * Revision 1.3  1994/05/15  22:15:14  rgrimes
 * To truely have the OLD behavior of RCS by default make the expansion
 * of $FreeBSD$ false by default.  This should keep them out
 * of the pre 2.x repository. (Or at least make them useless in it).
 *
 * Revision 1.2  1994/05/14  07:00:23  rgrimes
 * Add new option -K from David Dawes that allows you to turn on and off
 * specific keyword substitution during a rcs co command.
 * Add the new keyword FreeBSD that is IDENTICAL in operation to $Id: rcskeys.c,v 1.3 1994/05/15 22:15:14 rgrimes Exp $.
 *
 * Revision 1.1.1.1  1993/06/18  04:22:12  jkh
 * Updated GNU utilities
 *
 * Revision 5.2  1991/08/19  03:13:55  eggert
 * Say `T const' instead of `const T'; it's less confusing for pointer types.
 * (This change was made in other source files too.)
 *
 * Revision 5.1  1991/04/21  11:58:25  eggert
 * Don't put , just before } in initializer.
 *
 * Revision 5.0  1990/08/22  08:12:54  eggert
 * Add -k.  Ansify and Posixate.
 *
 * Revision 4.3  89/05/01  15:13:02  narten
 * changed copyright header to reflect current distribution rules
 * 
 * Revision 4.2  87/10/18  10:36:33  narten
 * Updating version numbers. Changes relative to 1.1 actuallyt
 * relative to 4.1
 * 
 * Revision 1.2  87/09/24  14:00:10  narten
 * Sources now pass through lint (if you ignore printf/sprintf/fprintf 
 * warnings)
 * 
 * Revision 4.1  83/05/04  10:06:53  wft
 * Initial revision.
 * 
 */


#include "rcsbase.h"

libId(keysId, "$Id: rcskeys.c,v 1.3 1994/05/15 22:15:14 rgrimes Exp $")


char const *const Keyword[] = {
    /* This must be in the same order as rcsbase.h's enum markers type. */
	nil,
	AUTHOR, DATE, HEADER, IDH,
	LOCKER, LOG, RCSFILE, REVISION, SOURCE, STATE,
	FREEBSD
};


/* Expand all keywords by default */

static int ExpandKeyword[] = {
	nil,
	true, true, true, true,
	true, true, true, true, true, true,
	false
};

	enum markers
trymatch(string)
	char const *string;
/* function: Checks whether string starts with a keyword followed
 * by a KDELIM or a VDELIM.
 * If successful, returns the appropriate marker, otherwise Nomatch.
 */
{
        register int j;
	register char const *p, *s;
	for (j = sizeof(Keyword)/sizeof(*Keyword);  (--j);  ) {
		if (!ExpandKeyword[j])
			continue;
		/* try next keyword */
		p = Keyword[j];
		s = string;
		while (*p++ == *s++) {
			if (!*p)
			    switch (*s) {
				case KDELIM:
				case VDELIM:
				    return (enum markers)j;
				default:
				    return Nomatch;
			    }
		}
        }
        return(Nomatch);
}


setIncExc(arg)
	char *arg;
/* Sets up the ExpandKeyword table according to command-line flags */
{
	char *key;
	int include = 0, j;

	arg += 2;
	switch (*arg++) {
	    case 'e':
		include = false;
		break;
	    case 'i':
		include = true;
		break;
	    default:
		return(false);
	}
	if (include)
		for (j = sizeof(Keyword)/sizeof(*Keyword);  (--j);  )
			ExpandKeyword[j] = false;
	key = strtok(arg, ",");
	while (key) {
		for (j = sizeof(Keyword)/sizeof(*Keyword);  (--j);  )
			if (!strcmp(key, Keyword[j]))
				ExpandKeyword[j] = include;
		key = strtok(NULL, ",");
	}
	return(true);
}

