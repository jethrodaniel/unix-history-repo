/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2005 Olivier Houchard.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* $FreeBSD$ */

#ifndef AT91RM92REG_H_
#define AT91RM92REG_H_

/* Chip Specific limits */
#define RM9200_PLL_A_MIN_IN_FREQ	  1000000 /*   1 MHz */
#define RM9200_PLL_A_MAX_IN_FREQ	 32000000 /*  32 MHz */
#define RM9200_PLL_A_MIN_OUT_FREQ	 80000000 /*  80 MHz */
#define RM9200_PLL_A_MAX_OUT_FREQ	180000000 /* 180 MHz */
#define RM9200_PLL_A_MUL_SHIFT 16
#define RM9200_PLL_A_MUL_MASK 0x7FF
#define RM9200_PLL_A_DIV_SHIFT 0
#define RM9200_PLL_A_DIV_MASK 0xFF

/*
 * PLL B input frequency spec sheet says it must be between 1MHz and 32MHz,
 * but it works down as low as 100kHz, a frequency necessary for some
 * output frequencies to work.
 *
 * PLL Max output frequency is 240MHz.  The errata says 180MHz is the max
 * for some revisions of this part.  Be more permissive and optimistic.
 */
#define RM9200_PLL_B_MIN_IN_FREQ	   100000 /* 100 KHz */
#define RM9200_PLL_B_MAX_IN_FREQ	 32000000 /*  32 MHz */
#define RM9200_PLL_B_MIN_OUT_FREQ	 30000000 /*  30 MHz */
#define RM9200_PLL_B_MAX_OUT_FREQ	240000000 /* 240 MHz */
#define RM9200_PLL_B_MUL_SHIFT 16
#define RM9200_PLL_B_MUL_MASK 0x7FF
#define RM9200_PLL_B_DIV_SHIFT 0
#define RM9200_PLL_B_DIV_MASK 0xFF

/*
 * Memory map, from datasheet :
 * 0x00000000 - 0x0ffffffff : Internal Memories
 * 0x10000000 - 0x1ffffffff : Chip Select 0
 * 0x20000000 - 0x2ffffffff : Chip Select 1
 * 0x30000000 - 0x3ffffffff : Chip Select 2
 * 0x40000000 - 0x4ffffffff : Chip Select 3
 * 0x50000000 - 0x5ffffffff : Chip Select 4
 * 0x60000000 - 0x6ffffffff : Chip Select 5
 * 0x70000000 - 0x7ffffffff : Chip Select 6
 * 0x80000000 - 0x8ffffffff : Chip Select 7
 * 0x90000000 - 0xeffffffff : Undefined (Abort)
 * 0xf0000000 - 0xfffffffff : Peripherals
 */

/* Usart */

#define AT91RM92_USART_SIZE	0x4000
#define AT91RM92_USART0_BASE	0xffc0000
#define AT91RM92_USART0_PDC	0xffc0100
#define AT91RM92_USART0_SIZE	AT91RM92_USART_SIZE
#define AT91RM92_USART1_BASE	0xffc4000
#define AT91RM92_USART1_PDC	0xffc4100
#define AT91RM92_USART1_SIZE	AT91RM92_USART_SIZE
#define AT91RM92_USART2_BASE	0xffc8000
#define AT91RM92_USART2_PDC	0xffc8100
#define AT91RM92_USART2_SIZE	AT91RM92_USART_SIZE
#define AT91RM92_USART3_BASE	0xffcc000
#define AT91RM92_USART3_PDC	0xffcc100
#define AT91RM92_USART3_SIZE	AT91RM92_USART_SIZE

/* System Registers */

#define AT91RM92_SYS_BASE	0xffff000
#define AT91RM92_SYS_SIZE	0x1000

/*
 * PIO
 */
#define AT91RM92_PIO_SIZE	0x200
#define AT91RM92_PIOA_BASE	0xffff400
#define AT91RM92_PIOA_SIZE	AT91RM92_PIO_SIZE
#define AT91RM92_PIOB_BASE	0xffff600
#define AT91RM92_PIOB_SIZE	AT91RM92_PIO_SIZE
#define AT91RM92_PIOC_BASE	0xffff800
#define AT91RM92_PIOC_SIZE	AT91RM92_PIO_SIZE
#define AT91RM92_PIOD_BASE	0xffffa00
#define AT91RM92_PIOD_SIZE	AT91RM92_PIO_SIZE

/*
 * PMC
 */
#define AT91RM92_PMC_BASE	0xffffc00
#define AT91RM92_PMC_SIZE	0x100

/* IRQs : */
/*
 * 0: AIC
 * 1: System peripheral (System timer, RTC, DBGU)
 * 2: PIO Controller A
 * 3: PIO Controller B
 * 4: PIO Controller C
 * 5: PIO Controller D
 * 6: USART 0
 * 7: USART 1
 * 8: USART 2
 * 9: USART 3
 * 10: MMC Interface
 * 11: USB device port
 * 12: Two-wire interface
 * 13: SPI
 * 14: SSC
 * 15: SSC
 * 16: SSC
 * 17: Timer Counter 0
 * 18: Timer Counter 1
 * 19: Timer Counter 2
 * 20: Timer Counter 3
 * 21: Timer Counter 4
 * 22: Timer Counter 5
 * 23: USB Host port
 * 24: Ethernet
 * 25: AIC
 * 26: AIC
 * 27: AIC
 * 28: AIC
 * 29: AIC
 * 30: AIC
 * 31: AIC
 */

#define AT91RM92_IRQ_SYSTEM	1
#define AT91RM92_IRQ_PIOA	2
#define AT91RM92_IRQ_PIOB	3
#define AT91RM92_IRQ_PIOC	4
#define AT91RM92_IRQ_PIOD	5
#define AT91RM92_IRQ_USART0	6
#define AT91RM92_IRQ_USART1	7
#define AT91RM92_IRQ_USART2	8
#define AT91RM92_IRQ_USART3	9
#define AT91RM92_IRQ_MCI	10
#define AT91RM92_IRQ_UDP	11
#define AT91RM92_IRQ_TWI	12
#define AT91RM92_IRQ_SPI	13
#define AT91RM92_IRQ_SSC0	14
#define AT91RM92_IRQ_SSC1	15
#define AT91RM92_IRQ_SSC2	16
#define AT91RM92_IRQ_TC0	17,18,19
#define AT91RM92_IRQ_TC0C0	17
#define AT91RM92_IRQ_TC0C1	18
#define AT91RM92_IRQ_TC0C2	19
#define AT91RM92_IRQ_TC1	20,21,22
#define AT91RM92_IRQ_TC1C1	20
#define AT91RM92_IRQ_TC1C2	21
#define AT91RM92_IRQ_TC1C3	22
#define AT91RM92_IRQ_UHP	23
#define AT91RM92_IRQ_EMAC	24
#define AT91RM92_IRQ_AIC_IRQ0	25
#define AT91RM92_IRQ_AIC_IRQ1	26
#define AT91RM92_IRQ_AIC_IRQ2	27
#define AT91RM92_IRQ_AIC_IRQ3	28
#define AT91RM92_IRQ_AIC_IRQ4	29
#define AT91RM92_IRQ_AIC_IRQ5	30
#define AT91RM92_IRQ_AIC_IRQ6	31

/* Alias */
#define AT91RM92_IRQ_DBGU AT91RM92_IRQ_SYSTEM
#define AT91RM92_IRQ_PMC  AT91RM92_IRQ_SYSTEM
#define AT91RM92_IRQ_ST   AT91RM92_IRQ_SYSTEM
#define AT91RM92_IRQ_RTC  AT91RM92_IRQ_SYSTEM
#define AT91RM92_IRQ_MC   AT91RM92_IRQ_SYSTEM
#define AT91RM92_IRQ_OHCI AT91RM92_IRQ_UHP
#define AT91RM92_IRQ_AIC -1
#define AT91RM92_IRQ_CF -1

/* Timer */

#define AT91RM92_AIC_BASE	0xffff000
#define AT91RM92_AIC_SIZE	0x200

/* DBGU */
#define AT91RM92_DBGU_BASE	0xffff200
#define AT91RM92_DBGU_SIZE	0x200

#define AT91RM92_RTC_BASE	0xffffe00
#define AT91RM92_RTC_SIZE	0x100

#define AT91RM92_MC_BASE	0xfffff00
#define AT91RM92_MC_SIZE	0x100

#define AT91RM92_ST_BASE	0xffffd00
#define AT91RM92_ST_SIZE	0x100

#define AT91RM92_SPI_BASE	0xffe0000
#define AT91RM92_SPI_SIZE	0x4000
#define AT91RM92_SPI_PDC	0xffe0100

#define AT91RM92_SSC_SIZE	0x4000
#define AT91RM92_SSC0_BASE	0xffd0000
#define AT91RM92_SSC0_PDC	0xffd0100
#define AT91RM92_SSC0_SIZE	AT91RM92_SSC_SIZE	

#define AT91RM92_SSC1_BASE	0xffd4000
#define AT91RM92_SSC1_PDC	0xffd4100
#define AT91RM92_SSC1_SIZE	AT91RM92_SSC_SIZE	

#define AT91RM92_SSC2_BASE	0xffd8000
#define AT91RM92_SSC2_PDC	0xffd8100
#define AT91RM92_SSC2_SIZE	AT91RM92_SSC_SIZE	

#define AT91RM92_EMAC_BASE	0xffbc000
#define AT91RM92_EMAC_SIZE	0x4000

#define AT91RM92_TWI_BASE	0xffb8000
#define AT91RM92_TWI_SIZE	0x4000

#define AT91RM92_MCI_BASE	0xffb4000
#define AT91RM92_MCI_PDC	0xffb4100
#define AT91RM92_MCI_SIZE	0x4000

#define AT91RM92_UDP_BASE	0xffb0000
#define AT91RM92_UDP_SIZE	0x4000

#define AT91RM92_TC_SIZE	0x4000
#define AT91RM92_TC0_BASE	0xffa0000
#define AT91RM92_TC0_SIZE	AT91RM92_TC_SIZE
#define AT91RM92_TC0C0_BASE	0xffa0000
#define AT91RM92_TC0C1_BASE	0xffa0040
#define AT91RM92_TC0C2_BASE	0xffa0080

#define AT91RM92_TC1_BASE	0xffa4000
#define AT91RM92_TC1_SIZE	AT91RM92_TC_SIZE
#define AT91RM92_TC1C0_BASE	0xffa4000
#define AT91RM92_TC1C1_BASE	0xffa4040
#define AT91RM92_TC1C2_BASE	0xffa4080

/* XXX Needs to be carfully coordinated with
 * other * soc's so phyical and vm address
 * mapping are unique. XXX
 */
#define AT91RM92_OHCI_VA_BASE	0xdfe00000
#define AT91RM92_OHCI_BASE	0x00300000
#define AT91RM92_OHCI_SIZE	0x00100000

#define	AT91RM92_CF_VA_BASE	0xdfd00000
#define	AT91RM92_CF_BASE	0x51400000
#define	AT91RM92_CF_SIZE	0x00100000

/* SDRAMC */

#define AT91RM92_SDRAMC_BASE	0xfffff90
#define AT91RM92_SDRAMC_MR	0x00
#define AT91RM92_SDRAMC_MR_MODE_NORMAL	0
#define AT91RM92_SDRAMC_MR_MODE_NOP	1
#define AT91RM92_SDRAMC_MR_MODE_PRECHARGE 2
#define AT91RM92_SDRAMC_MR_MODE_LOAD_MODE_REGISTER 3
#define AT91RM92_SDRAMC_MR_MODE_REFRESH	4
#define AT91RM92_SDRAMC_MR_DBW_16	0x10
#define AT91RM92_SDRAMC_TR	0x04
#define AT91RM92_SDRAMC_CR	0x08
#define AT91RM92_SDRAMC_CR_NC_8		0x0
#define AT91RM92_SDRAMC_CR_NC_9		0x1
#define AT91RM92_SDRAMC_CR_NC_10	0x2
#define AT91RM92_SDRAMC_CR_NC_11	0x3
#define AT91RM92_SDRAMC_CR_NC_MASK	0x00000003
#define AT91RM92_SDRAMC_CR_NR_11	0x0
#define AT91RM92_SDRAMC_CR_NR_12	0x4
#define AT91RM92_SDRAMC_CR_NR_13	0x8
#define AT91RM92_SDRAMC_CR_NR_RES	0xc
#define AT91RM92_SDRAMC_CR_NR_MASK	0x0000000c
#define AT91RM92_SDRAMC_CR_NB_2		0x00
#define AT91RM92_SDRAMC_CR_NB_4		0x10
#define AT91RM92_SDRAMC_CR_NB_MASK	0x00000010
#define AT91RM92_SDRAMC_CR_NCAS_MASK	0x00000060
#define AT91RM92_SDRAMC_CR_TWR_MASK	0x00000780
#define AT91RM92_SDRAMC_CR_TRC_MASK	0x00007800
#define AT91RM92_SDRAMC_CR_TRP_MASK	0x00078000
#define AT91RM92_SDRAMC_CR_TRCD_MASK	0x00780000
#define AT91RM92_SDRAMC_CR_TRAS_MASK	0x07800000
#define AT91RM92_SDRAMC_CR_TXSR_MASK	0x78000000
#define AT91RM92_SDRAMC_SRR	0x0c
#define AT91RM92_SDRAMC_LPR	0x10
#define AT91RM92_SDRAMC_IER	0x14
#define AT91RM92_SDRAMC_IDR	0x18
#define AT91RM92_SDRAMC_IMR	0x1c
#define AT91RM92_SDRAMC_ISR	0x20
#define AT91RM92_SDRAMC_IER_RES	0x1

#endif /* AT91RM92REG_H_ */
