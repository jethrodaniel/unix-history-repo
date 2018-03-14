/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2000 Orion Hodson <O.Hodson@cs.ucl.ac.uk>
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _CS4281_H_
#define _CS4281_H_

#define CS4281_PCI_ID 	0x60051013

/* Ball Parks */
#define CS4281PCI_BA0_SIZE 	4096
#define CS4281PCI_BA1_SIZE	65536

/* Register values */
#define CS4281PCI_HISR		0x000
#	define CS4281PCI_HISR_DMAI		0x00040000
#	define CS4281PCI_HISR_DMA(x)		(0x0100 << (x))

#define CS4281PCI_HICR		0x008
#	define CS4281PCI_HICR_EOI		0x00000003

#define CS4281PCI_HIMR		0x00c
#	define CS4281PCI_HIMR_DMAI		0x00040000
#	define CS4281PCI_HIMR_DMA(x)		(0x0100 << (x))

#define CS4281PCI_IIER		0x010

#define CS4281PCI_HDSR(x)	(0x0f0 + (x)*0x004)
#	define CS4281PCI_HDSR_CH1P		0x02000000
#	define CS4281PCI_HDSR_CH2P		0x01000000
#	define CS4281PCI_HDSR_HDTC		0x00020000
#	define CS4281PCI_HDSR_DTC		0x00010000
#	define CS4281PCI_HDSR_DRUN		0x00008000
#	define CS4281PCI_HDSR_RQ		0x00000080

#define CS4281PCI_DCA(x)	(0x110 + (x) * 0x010)
#define CS4281PCI_DCC(x)	(0x114 + (x) * 0x010)
#define CS4281PCI_DBA(x)	(0x118 + (x) * 0x010)
#define CS4281PCI_DBC(x)	(0x11c + (x) * 0x010)

#define CS4281PCI_DMR(x)	(0x150 + (x) * 0x008)
#	define CS4281PCI_DMR_DMA		0x20000000
#	define CS4281PCI_DMR_POLL		0x10000000
#	define CS4281PCI_DMR_TBC		0x02000000
#	define CS4281PCI_DMR_CBC		0x01000000
#	define CS4281PCI_DMR_SWAPC		0x00400000
#	define CS4281PCI_DMR_SIZE20		0x00100000
#	define CS4281PCI_DMR_USIGN		0x00080000
#	define CS4281PCI_DMR_BEND		0x00040000
#	define CS4281PCI_DMR_MONO		0x00020000
#	define CS4281PCI_DMR_SIZE8		0x00010000
#	define CS4281PCI_DMR_TYPE_DEMAND	0x00000000
#	define CS4281PCI_DMR_TYPE_SINGLE	0x00000040
#	define CS4281PCI_DMR_TYPE_BLOCK		0x00000080
#	define CS4281PCI_DMR_TYPE_CASCADE	0x000000c0
#	define CS4281PCI_DMR_DEC		0x00000020
#	define CS4281PCI_DMR_AUTO		0x00000010
#	define CS4281PCI_DMR_TR_PLAY		0x00000008
#	define CS4281PCI_DMR_TR_REC		0x00000004

#define CS4281PCI_DCR(x)	(0x154 + (x) * 0x008)
#	define CS4281PCI_DCR_HTCIE		0x00020000
#	define CS4281PCI_DCR_TCIE		0x00010000
#	define CS4281PCI_DCR_MSK		0x00000001

#define CS4281PCI_FCR(x)	(0x180 + (x) * 0x004)
#	define CS4281PCI_FCR_FEN		0x80000000
#	define CS4281PCI_FCR_DACZ		0x40000000
#	define CS4281PCI_FCR_PSH		0x20000000
#	define CS4281PCI_FCR_RS(x)		((x) << 24)
#	define CS4281PCI_FCR_LS(x)		((x) << 16)
#	define CS4281PCI_FCR_SZ(x)		((x) << 8)
#	define CS4281PCI_FCR_OF(x)		(x)

#define CS4281PCI_FPDR(x)	(0x190 + (x) * 0x004)

#define CS4281PCI_FCHS		0x20c
#define CS4281PCI_FSIC(x)	(0x210 + (x) * 0x004)

#define CS4281PCI_PMCS		0x344
#	define CS4281PCI_PMCS_PS_MASK		0x00000003
#define CS4281PCI_PMCS_OFFSET	(CS4281PCI_PMCS - 0x300)

#define CS4281PCI_CWPR		0x3e0
#	define CS4281PCI_CWPR_MAGIC		0x00004281

#define CS4281PCI_EPPMC		0x3e4
#	define CS4281PCI_EPPMC_FPDN		0x00004000
#define CS4281PCI_GPIOR		0x3e8

#define CS4281PCI_SPMC		0x3ec
#	define CS4281PCI_SPMC_RSTN		0x00000001
#	define CS4281PCI_SPMC_ASYN		0x00000002
#	define CS4281PCI_SPMC_WUP1		0x00000004
#	define CS4281PCI_SPMC_WUP2		0x00000008
#	define CS4281PCI_SPMC_ASDO		0x00000080
#	define CS4281PCI_SPMC_ASDI2E		0x00000100
#	define CS4281PCI_SPMC_EESPD		0x00000200
#	define CS4281PCI_SPMC_GISPEN		0x00004000
#	define CS4281PCI_SPMC_GIPPEN		0x00008000

#define CS4281PCI_CFLR		0x3f0
#define CS4281PCI_IISR		0x3f4
#define CS4281PCI_TMS		0x3f8
#define CS4281PCI_SSVID		0x3fc

#define CS4281PCI_CLKCR1	0x400
#	define CS_4281PCI_CLKCR1_DLLSS_MASK	0x0000000c
#	define CS_4281PCI_CLKCR1_DLLSS_AC97	0x00000004
#	define CS4281PCI_CLKCR1_DLLP		0x00000010
#	define CS4281PCI_CLKCR1_SWCE		0x00000020
#	define CS4281PCI_CLKCR1_DLLOS		0x00000040
#	define CS4281PCI_CLKCR1_CKRA		0x00010000
#	define CS4281PCI_CLKCR1_DLLRDY		0x01000000
#	define CS4281PCI_CLKCR1_CLKON		0x02000000

#define CS4281PCI_FRR		0x410

#define CS4281PCI_SLT12O	0x41c
#define CS4281PCI_SERMC		0x420
#	define CS4281PCI_SERMC_PTC_AC97		0x00000002
#	define CS4281PCI_SERMC_PTC_MASK		0x0000000e
#	define CS4281PCI_SERMC_ODSEN1		0x01000000
#	define CS4281PCI_SERMC_ODSEN2		0x02000000
#define CS4281PCI_SERC1		0x428
#define CS4281PCI_SERC2		0x42c

#define CS4281PCI_SLT12M	0x45c
#define CS4281PCI_ACCTL		0x460
#	define CS4281PCI_ACCTL_ESYN		0x00000002
#	define CS4281PCI_ACCTL_VFRM		0x00000004
#	define CS4281PCI_ACCTL_DCV		0x00000008
#	define CS4281PCI_ACCTL_CRW		0x00000010
#	define CS4281PCI_ACCTL_TC		0x00000040

#define CS4281PCI_ACSTS		0x464
#	define CS4281PCI_ACSTS_CRDY		0x00000001
#	define CS4281PCI_ACSTS_VSTS		0x00000002

#define CS4281PCI_ACOSV		0x468
#	define CS4281PCI_ACOSV_SLV(x)		(1 << (x - 3))
#define CS4281PCI_ACCAD		0x46c
#define CS4281PCI_ACCDA		0x470
#define CS4281PCI_ACISV		0x474
#	define CS4281PCI_ACISV_ISV(x)		(1 << (x - 3))
#define CS4281PCI_ACSAD		0x478
#define CS4281PCI_ACSDA		0x47c
#define CS4281PCI_JSPT		0x480
#define CS4281PCI_JSCTL		0x484

#define CS4281PCI_SSPM		0x740
#	define CS4281PCI_SSPM_MIXEN		0x00000040
#	define CS4281PCI_SSPM_CSRCEN		0x00000020
#	define CS4281PCI_SSPM_PSRCEN		0x00000010
#	define CS4281PCI_SSPM_JSEN		0x00000008
#	define CS4281PCI_SSPM_ACLEN		0x00000004
#	define CS4281PCI_SSPM_FMEN		0x00000002

#define CS4281PCI_DACSR		0x744
#define CS4281PCI_ADCSR		0x748
#define CS4281PCI_SSCR		0x74c

#define CS4281PCI_SRCSA		0x75c
#	define CS4281PCI_SRCSA_PLSS(x)		(x)
#	define CS4281PCI_SRCSA_PRSS(x)		((x) << 8)
#	define CS4281PCI_SRCSA_CLSS(x)		((x) << 16)
#	define CS4281PCI_SRCSA_CRSS(x)		((x) << 24)

#define CS4281PCI_PPLVC		0x760
#define CS4281PCI_PPRVC		0x764

/* Slot definitions (minimal) */
#define CS4281PCI_LPCM_PLAY_SLOT	0x00
#define CS4281PCI_RPCM_PLAY_SLOT	0x01

#define CS4281PCI_LPCM_REC_SLOT		0x0a
#define CS4281PCI_RPCM_REC_SLOT		0x0b

#define CS4281PCI_DISABLED_SLOT		0x1f

#endif /* _CS4281_H_ */
