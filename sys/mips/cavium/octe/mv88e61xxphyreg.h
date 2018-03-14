/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2010 Juli Mallett <jmallett@FreeBSD.org>
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
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

/*
 * Register definitions for Marvell MV88E61XX
 *
 * Note that names and definitions were gleaned from Linux and U-Boot patches
 * released by Marvell, often by looking at contextual use of the registers
 * involved, and may not be representative of the full functionality of those
 * registers and are certainly not an exhaustive enumeration of registers.
 *
 * For an exhaustive enumeration of registers, check out the QD-DSDT package
 * included in the Marvell ARM Feroceon Board Support Package for Linux.
 */

#ifndef	_MIPS_CAVIUM_OCTE_MV88E61XXPHYREG_H_
#define	_MIPS_CAVIUM_OCTE_MV88E61XXPHYREG_H_

/*
 * Port addresses & per-port registers.
 */
#define	MV88E61XX_PORT(x)	(0x10 + (x))
#define	MV88E61XX_HOST_PORT	(5)
#define	MV88E61XX_PORTS		(6)

#define	MV88E61XX_PORT_STATUS		(0x00)
#define	MV88E61XX_PORT_FORCE_MAC	(0x01)
#define	MV88E61XX_PORT_PAUSE_CONTROL	(0x02)
#define	MV88E61XX_PORT_REVISION		(0x03)
#define	MV88E61XX_PORT_CONTROL		(0x04)
#define	MV88E61XX_PORT_CONTROL2		(0x05)
#define	MV88E61XX_PORT_VLAN_MAP		(0x06)
#define	MV88E61XX_PORT_VLAN		(0x07)
#define	MV88E61XX_PORT_FILTER		(0x08)
#define	MV88E61XX_PORT_EGRESS_CONTROL	(0x09)
#define	MV88E61XX_PORT_EGRESS_CONTROL2	(0x0a)
#define	MV88E61XX_PORT_PORT_LEARN	(0x0b)
#define	MV88E61XX_PORT_ATU_CONTROL	(0x0c)
#define	MV88E61XX_PORT_PRIORITY_CONTROL	(0x0d)
#define	MV88E61XX_PORT_ETHER_PROTO	(0x0f)
#define	MV88E61XX_PORT_PROVIDER_PROTO	(0x1a)
#define	MV88E61XX_PORT_PRIORITY_MAP	(0x18)
#define	MV88E61XX_PORT_PRIORITY_MAP2	(0x19)

/*
 * Fields and values in each register.
 */
#define	MV88E61XX_PORT_STATUS_MEDIA		(0x0300)
#define	MV88E61XX_PORT_STATUS_MEDIA_10M		(0x0000)
#define	MV88E61XX_PORT_STATUS_MEDIA_100M	(0x0100)
#define	MV88E61XX_PORT_STATUS_MEDIA_1G		(0x0200)
#define	MV88E61XX_PORT_STATUS_DUPLEX		(0x0400)
#define	MV88E61XX_PORT_STATUS_LINK		(0x0800)
#define	MV88E61XX_PORT_STATUS_FC		(0x8000)

#define	MV88E61XX_PORT_CONTROL_DOUBLE_TAG	(0x0200)

#define	MV88E61XX_PORT_FILTER_MAP_DEST		(0x0080)
#define	MV88E61XX_PORT_FILTER_DISCARD_UNTAGGED	(0x0100)
#define	MV88E61XX_PORT_FILTER_DISCARD_TAGGED	(0x0200)
#define	MV88E61XX_PORT_FILTER_8021Q_MODE	(0x0c00)
#define	MV88E61XX_PORT_FILTER_8021Q_DISABLED	(0x0000)
#define	MV88E61XX_PORT_FILTER_8021Q_FALLBACK	(0x0400)
#define	MV88E61XX_PORT_FILTER_8021Q_CHECK	(0x0800)
#define	MV88E61XX_PORT_FILTER_8021Q_SECURE	(0x0c00)

/*
 * Global address & global registers.
 */
#define	MV88E61XX_GLOBAL	(0x1b)

#define	MV88E61XX_GLOBAL_STATUS		(0x00)
#define	MV88E61XX_GLOBAL_CONTROL	(0x04)
#define	MV88E61XX_GLOBAL_VTU_OP		(0x05)
#define	MV88E61XX_GLOBAL_VTU_VID	(0x06)
#define	MV88E61XX_GLOBAL_VTU_DATA_P0P3	(0x07)
#define	MV88E61XX_GLOBAL_VTU_DATA_P4P5	(0x08)
#define	MV88E61XX_GLOBAL_ATU_CONTROL	(0x0a)
#define	MV88E61XX_GLOBAL_PRIORITY_MAP	(0x18)
#define	MV88E61XX_GLOBAL_MONITOR	(0x1a)
#define	MV88E61XX_GLOBAL_REMOTE_MGMT	(0x1c)
#define	MV88E61XX_GLOBAL_STATS		(0x1d)

/*
 * Fields and values in each register.
 */
#define	MV88E61XX_GLOBAL_VTU_OP_BUSY		(0x8000)
#define	MV88E61XX_GLOBAL_VTU_OP_OP		(0x7000)
#define	MV88E61XX_GLOBAL_VTU_OP_OP_FLUSH	(0x1000)
#define	MV88E61XX_GLOBAL_VTU_OP_OP_VTU_LOAD	(0x3000)

#define	MV88E61XX_GLOBAL_VTU_VID_VALID		(0x1000)

/*
 * Second global address & second global registers.
 */
#define	MV88E61XX_GLOBAL2	(0x1c)

#define	MV88E61XX_GLOBAL2_MANAGE_2X	(0x02)
#define	MV88E61XX_GLOBAL2_MANAGE_0X	(0x03)
#define	MV88E61XX_GLOBAL2_CONTROL2	(0x05)
#define	MV88E61XX_GLOBAL2_TRUNK_MASK	(0x07)
#define	MV88E61XX_GLOBAL2_TRUNK_MAP	(0x08)
#define	MV88E61XX_GLOBAL2_RATELIMIT	(0x09)
#define	MV88E61XX_GLOBAL2_VLAN_CONTROL	(0x0b)
#define	MV88E61XX_GLOBAL2_MAC_ADDRESS	(0x0d)

/*
 * Fields and values in each register.
 */
#define	MV88E61XX_GLOBAL2_CONTROL2_DOUBLE_USE	(0x8000)
#define	MV88E61XX_GLOBAL2_CONTROL2_LOOP_PREVENT	(0x4000)
#define	MV88E61XX_GLOBAL2_CONTROL2_FLOW_MESSAGE	(0x2000)
#define	MV88E61XX_GLOBAL2_CONTROL2_FLOOD_BC	(0x1000)
#define	MV88E61XX_GLOBAL2_CONTROL2_REMOVE_PTAG	(0x0800)
#define	MV88E61XX_GLOBAL2_CONTROL2_AGE_INT	(0x0400)
#define	MV88E61XX_GLOBAL2_CONTROL2_FLOW_TAG	(0x0200)
#define	MV88E61XX_GLOBAL2_CONTROL2_ALWAYS_VTU	(0x0100)
#define	MV88E61XX_GLOBAL2_CONTROL2_FORCE_FC_PRI	(0x0080)
#define	MV88E61XX_GLOBAL2_CONTROL2_FC_PRI	(0x0070)
#define	MV88E61XX_GLOBAL2_CONTROL2_MGMT_TO_HOST	(0x0008)
#define	MV88E61XX_GLOBAL2_CONTROL2_MGMT_PRI	(0x0007)

#endif /* !_MIPS_CAVIUM_OCTE_MV88E61XXPHYREG_H_ */
