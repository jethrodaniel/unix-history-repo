/*	mem.h	4.7	81/03/21	*/

/*
 * Memory controller registers
 *
 * The way in which the data is stored in these registers varies
 * per cpu, so we define macros here to mask that.
 */
struct	mcr {
	int	mc_reg[3];
};

/*
 * Compute maximum possible number of memory controllers,
 * for sizing of the mcraddr array.
 */
#if VAX780
#define	MAXNMCR		4
#else
#define	MAXNMCR		1
#endif

/*
 * For each processor type we define 5 macros:
 *	M???_INH(mcr)		inhibits further crd interrupts from mcr
 *	M???_ENA(mcr)		enables another crd interrupt from mcr
 *	M???_ERR(mcr)		tells whether an error is waiting
 *	M???_SYN(mcr)		gives the syndrome bits of the error
 *	M???_ADDR(mcr)		gives the address of the error
 */
#if VAX780
#define	M780_ICRD	0x40000000	/* inhibit crd interrupts, in [2] */
#define	M780_HIERR	0x20000000	/* high error rate, in reg[2] */
#define	M780_ERLOG	0x10000000	/* error log request, in reg[2] */

#define	M780_INH(mcr)	((mcr)->mc_reg[2] = (M780_ICRD|M780_HIERR|M780_ERLOG))
#define	M780_ENA(mcr)	((mcr)->mc_reg[2] = (M780_HIERR|M780_ERLOG))
#define	M780_ERR(mcr)	((mcr)->mc_reg[2] & (M780_ERLOG))

#define	M780_SYN(mcr)	((mcr)->mc_reg[2] & 0xff)
#define	M780_ADDR(mcr)	(((mcr)->mc_reg[2] >> 8) & 0xfffff)
#endif

#if VAX750
#define	M750_ICRD	0x10000000	/* inhibit crd interrupts, in [1] */
#define	M750_UNCORR	0xc0000000	/* uncorrectable error, in [0] */
#define	M750_CORERR	0x40000000	/* correctable error, in [0] */

#define	M750_INH(mcr)	((mcr)->mc_reg[1] = M750_ICRD)
#define	M750_ENA(mcr)	((mcr)->mc_reg[0] = (M750_UNCORR|M750_CORERR), \
			    (mcr)->mc_reg[1] = 0)
#define	M750_ERR(mcr)	((mcr)->mc_reg[0] & (M750_UNCORR|M750_CORERR))

#define	M750_SYN(mcr)	((mcr)->mc_reg[0] & 0x3f)
#define	M750_ADDR(mcr)	(((mcr)->mc_reg[0] >> 8) & 0x7fff)
#endif

#if VAX730
#define	M730_CRD	0x40000000	/* crd, in [1] */
#define	M730_FTBPE	0x20000000	/* force tbuf parity error, in [1] */
#define	M730_ENACRD	0x10000000	/* enable crd interrupt, in [1] */
#define	M730_MME	0x08000000	/* mem-man enable (ala ipr), in [1] */
#define	M730_DM		0x04000000	/* diagnostic mode, in [1] */
#define	M730_DISECC	0x02000000	/* disable ecc, in [1] */

#define	M730_INH(mcr)	((mcr)->mc_reg[1] = M730_MME)
#define	M730_ENA(mcr)	((mcr)->mc_reg[1] = (M730_MME|M730_ENACRD))
#define	M730_ERR(mcr)	((mcr)->mc_reg[1] & M730_CRD)
#define	M730_SYN(mcr)	((mcr)->mc_reg[0] & 0x7f)
#define	M730_ADDR(mcr)	(((mcr)->mc_reg[0] >> 8) & 0x7fff)
#endif

#define	MEMINTVL	(60*60*10)		/* 10 minutes */

#ifdef	KERNEL
int	nmcr;
struct	mcr *mcraddr[MAXNMCR];
#endif
