/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#ifndef lint
static char sccsid[] = "@(#)rent.c	5.3 (Berkeley) %G%";
#endif /* not lint */

# include	"monop.ext"

/*
 *	This routine has the player pay rent
 */
rent(sqp)
reg SQUARE	*sqp; {

	reg int		rnt;
	reg PROP	*pp;
	PLAY		*plp;

	plp = &play[sqp->owner];
	printf("Owned by %s\n", plp->name);
	if (sqp->desc->morg) {
		lucky("The thing is mortgaged.  ");
		return;
	}
	switch (sqp->type) {
	  case PRPTY:
		pp = sqp->desc;
		if (pp->monop)
			if (pp->houses == 0)
				printf("rent is %d\n", rnt=pp->rent[0] * 2);
			else if (pp->houses < 5)
				printf("with %d houses, rent is %d\n",
				    pp->houses, rnt=pp->rent[pp->houses]);
			else
				printf("with a hotel, rent is %d\n",
				    rnt=pp->rent[pp->houses]);
		else
			printf("rent is %d\n", rnt = pp->rent[0]);
		break;
	  case RR:
		rnt = 25;
		rnt <<= (plp->num_rr - 1);
		if (spec)
			rnt <<= 1;
		printf("rent is %d\n", rnt);
		break;
	  case UTIL:
		rnt = roll(2, 6);
		if (plp->num_util == 2 || spec) {
			printf("rent is 10 * roll (%d) = %d\n", rnt, rnt * 10);
			rnt *= 10;
		}
		else {
			printf("rent is 4 * roll (%d) = %d\n", rnt, rnt * 4);
			rnt *= 4;
		}
		break;
	}
	cur_p->money -= rnt;
	plp->money += rnt;
}
