/*	ungetc.c	4.2	83/09/25	*/

#include <stdio.h>

ungetc(c, iop)
	register FILE *iop;
{
	if (c == EOF)
		return (-1);
	if ((iop->_flag&_IOREAD) == 0 || iop->_ptr <= iop->_base)
		if (iop->_ptr == iop->_base && iop->_cnt == 0)
			*iop->_ptr++;
		else
			return (EOF);
	iop->_cnt++;
	*--iop->_ptr = c;
	return (c);
}
