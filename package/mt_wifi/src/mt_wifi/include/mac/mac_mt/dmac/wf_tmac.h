/*
 * Copyright (c) [2020], MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws.
 * The information contained herein is confidential and proprietary to
 * MediaTek Inc. and/or its licensors.
 * Except as otherwise provided in the applicable licensing terms with
 * MediaTek Inc. and/or its licensors, any reproduction, modification, use or
 * disclosure of MediaTek Software, and information contained herein, in whole
 * or in part, shall be strictly prohibited.
*/
/*
 ***************************************************************************
 ***************************************************************************

	Module Name:
	wf_tmac.h

	Abstract:
	Ralink Wireless Chip MAC related definition & structures

	Revision History:
	Who			When		  What
	--------	----------	  ----------------------------------------------
*/

#ifndef __WF_TMAC_H__
#define __WF_TMAC_H__

#define WF_TMAC_BASE        0x820f4000

#define TMAC_TCR            (WF_TMAC_BASE + 0x00)
#define TMAC_TCR1           (WF_TMAC_BASE + 0x08)
#define PRE_RTS_IDLE_DET_DIS    (1 << 4)
#define TX_BLINK_SEL_MASK (0x3 << 6)
#define TX_BLINK_SEL(p) (((p) & 0x3) << 6)
#define PRE_RTS_DET_GUARD_TIME_MASK (0xf << 8)
#define PRE_RTS_DET_GUARD_TIME(p) (((p) & 0xf) << 8)
#define CCA_RELD_AIFS (1 << 11)
#define PRE_RTS_SEC_IDLE_SEL_MASK (0x3 << 12)
#define PRE_RTS_SEC_IDLE_SEL(p) (((p) & 0x3) << 12)
#define RTS_SIGTA_EN (1 << 14)
#define LDPC_OFST_EN (1 << 15)
#define TMAC_TCR_TX_STREAM_NUM_MASK (0x3 << 16)
#define TMAC_TCR_TX_STREAM_NUM(p) (((p) & 0x3) << 16)
#define GET_TMAC_TCR_TX_STREAM_NUM(p) (((p) & TMAC_TCR_TX_STREAM_NUM_MASK) >> 16)
#define SCH_IDLE_SEL_MASK (0x3 << 18)
#define SCH_IDLE_SEL(p) (((p) & 0x3) << 18)
#define SCH_DET_PER_IOD (1 << 20)
#define DCH_DET_DIS (1 << 21)
#define TX_RIFS_EN (1 << 22)
#define GET_TX_RIFS_EN(p) (((p) & TX_RIFS_EN) >> 22)
#define RX_RIFS_MODE (1 << 23)
#define GET_RX_RIFS_MODE(p) (((p) & RX_RIFS_MODE) >> 23)
#define TXOP_TBTT_CONTROL (1 << 24)
#define GET_TXOP_TBTT_CONTROL(p) (((p) & TXOP_TBTT_CONTROL) >> 24)
#define TBTT_TX_STOP_CONTROL (1 << 25)
#define GET_TBTT_TX_STOP_CONTROL(p) (((p) & TBTT_TX_STOP_CONTROL) >> 25)
#define TXOP_BURST_STOP	(1 << 26)
#define GET_TXOP_BURST_STOP(p) (((p) & TXOP_BURST_STOP) >> 26)
#define RDG_RA_MODE (1 << 27)
#define GET_RDG_RA_MODE(p) (((p) & RDG_RA_MODE) >> 27)
#define RDG_RESP_EN (1 << 29)
#define GET_RDG_RESP_EN(p) (((p) & RDG_RESP_EN) >> 29)
#define GRANT_REVERSE_WHEN_NO_PENDING_FRM (1 << 30)
#define SMOOTHING (1 << 31)
#define GET_SMOOTHING(p) (((p) & SMOOTHING) >> 31)

#define TMAC_PSCR           (WF_TMAC_BASE + 0x04)
#define TMAC_PSCR1          (WF_TMAC_BASE + 0x0c)
#define APS_OFF_TIME_MASK (0xff << 1)
#define APS_OFF_TIME(p) (((p) & 0xff) << 1)
#define GET_APS_OFF_TIME(p) (((p) & APS_OFF_TIME_MASK) >> 1)
#define APS_ON_TIME_MASK (0x3f << 10)
#define APS_ON_TIME(p) (((p) & 0x3f) << 10)
#define GET_APS_ON_TIME(p) (((p) & APS_ON_TIME_MASK) >> 10)
#define APS_HALT_TIME_MASK (0x3ff << 16)
#define APS_HALT_TIME(p) (((p) & 0x3ff) << 16)
#define GET_APS_HALT_TIME(p) (((p) & APS_HALT_TIME_MASK) >> 16)
#define APS_EN (1 << 28)
#define GET_APS_EN(p) (((p) & APS_EN) >> 28)

#define TMAC_ACTXOPLR0      (WF_TMAC_BASE + 0x10)
#define AC2LIMIT_MASK (0xffff)
#define AC2LIMIT(p) (((p) & 0xffff))
#define GET_AC2LIMIT(p) (((p) & AC2LIMIT_MASK))
#define AC3LIMIT_MASK (0xffff << 16)
#define AC3LIMIT(p) (((p) & 0xffff) << 16)
#define GET_AC3LIMIT(p) (((p) & AC3LIMIT_MASK) >> 16)

#define TMAC_ACTXOPLR1      (WF_TMAC_BASE + 0x14)
#define AC0LIMIT_MASK (0xffff)
#define AC0LIMIT(p) (((p) & 0xffff))
#define GET_AC0LIMIT(p) (((p) & AC0LIMIT_MASK))
#define AC1LIMIT_MASK (0xffff << 16)
#define AC1LIMIT(p) (((p) & 0xffff) << 16)
#define GET_AC1LIMIT(p) (((p) & AC1LIMIT_MASK) >> 16)

#define TMAC_ACTXOPLR2          (WF_TMAC_BASE + 0x18)
#define AC12LIMIT_MASK (0xffff)
#define AC12LIMIT(p) (((p) & 0xffff))
#define GET_AC12LIMIT(p) (((p) & AC12LIMIT_MASK))
#define AC13LIMIT_MASK (0xffff << 16)
#define AC13LIMIT(p) (((p) & 0xffff) << 16)
#define GET_AC13LIMIT(p) (((p) & AC13LIMIT_MASK) >> 16)

#define TMAC_ACTXOPLR3      (WF_TMAC_BASE + 0x1c)
#define AC10LIMIT_MASK (0xffff)
#define AC10LIMIT(p) (((p) & 0xffff))
#define GET_AC10LIMIT(p) (((p) & AC10LIMIT_MASK))
#define AC11LIMIT_MASK (0xffff << 16)
#define AC11LIMIT(p) (((p) & 0xffff) << 16)
#define GET_AC11LIMIT(p) (((p) & AC11LIMIT_MASK) >> 16)


#define TMAC_ACTXOPLR4          (WF_TMAC_BASE + 0x60)
#define TMAC_ACTXOPLR5		(WF_TMAC_BASE + 0x64)
#define TMAC_ACTXOPLR6		(WF_TMAC_BASE + 0x68)
#define TMAC_ACTXOPLR7		(WF_TMAC_BASE + 0x6c)


#define TMAC_FP0R0 (WF_TMAC_BASE + 0x20)
#define TMAC_FP1R0 (WF_TMAC_BASE + 0x40)
#define LG_OFDM0_FRAME_POWER0_DBM_MASK (0x7f)
#define LG_OFDM0_FRAME_POWER0_DBM(p) (((p) & 0x7f))
#define LG_OFDM1_FRAME_POWER0_DBM_MASK (0x7f << 8)
#define LG_OFDM1_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 8)
#define LG_OFDM2_FRAME_POWER0_DBM_MASK (0x7f << 16)
#define LG_OFDM2_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 16)
#define LG_OFDM3_FRAME_POWER0_DBM_MASK (0x7f << 24)
#define LG_OFDM3_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 24)

#define TMAC_FP0R1 (WF_TMAC_BASE + 0x24)
#define TMAC_FP1R1 (WF_TMAC_BASE + 0x44)
#define HT20_0_FRAME_POWER0_DBM_MASK (0x7f)
#define HT20_0_FRAME_POWER0_DBM(p) (((p) & 0x7f))
#define HT20_1_FRAME_POWER0_DBM_MASK (0x7f << 8)
#define HT20_1_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 8)
#define HT20_2_FRAME_POWER0_DBM_MASK (0x7f << 16)
#define HT20_2_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 16)
#define HT20_3_FRAME_POWER0_DBM_MASK (0x7f << 24)
#define HT20_3_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 24)

#define TMAC_FP0R2 (WF_TMAC_BASE + 0x28)
#define TMAC_FP1R2 (WF_TMAC_BASE + 0x48)
#define HT40_0_FRAME_POWER0_DBM_MASK (0x7f)
#define HT40_0_FRAME_POWER0_DBM(p) (((p) & 0x7f))
#define HT40_1_FRAME_POWER0_DBM_MASK (0x7f << 8)
#define HT40_1_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 8)
#define HT40_2_FRAME_POWER0_DBM_MASK (0x7f << 16)
#define HT40_2_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 16)
#define HT40_3_FRAME_POWER0_DBM_MASK (0x7f << 24)
#define HT40_3_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 24)

#define TMAC_FP0R3 (WF_TMAC_BASE + 0x2C)
#define TMAC_FP1R3 (WF_TMAC_BASE + 0x4C)
#define CCK0_FRAME_POWER0_DBM_MASK (0x7f)
#define CCK0_FRAME_POWER0_DBM(p) (((p) & 0x7f))
#define LG_OFDM4_FRAME_POWER0_DBM_MASK (0x7f << 8)
#define LG_OFDM4_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 8)
#define CCK1_FRAME_POWER0_DBM_MASK (0x7f << 16)
#define CCK1_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 16)
#define HT40_6_FRAME_POWER0_DBM_MASK (0x7f << 24)
#define HT40_6_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 24)

#define TMAC_FP0R4 (WF_TMAC_BASE + 0x30)
#define TMAC_FP1R4 (WF_TMAC_BASE + 0x50)
#define HT20_4_FRAME_POWER0_DBM_MASK (0x7f)
#define HT20_4_FRAME_POWER0_DBM(p) (((p) & 0x7f))
#define HT20_5_FRAME_POWER0_DBM_MASK (0x7f << 8)
#define HT20_5_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 8)
#define HT40_4_FRAME_POWER0_DBM_MASK (0x7f << 16)
#define HT40_4_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 16)
#define HT40_5_FRAME_POWER0_DBM_MASK (0x7f << 24)
#define HT40_5_FRAME_POWER0_DBM(p) (((p) & 0x7f) << 24)

#define TMAC_FP0R5 (WF_TMAC_BASE + 0x34)
#define TMAC_FP1R5 (WF_TMAC_BASE + 0x54)

#define TMAC_FP0R6 (WF_TMAC_BASE + 0x38)
#define TMAC_FP1R6 (WF_TMAC_BASE + 0x58)

#define TMAC_FP0R7 (WF_TMAC_BASE + 0x3c)
#define TMAC_FP1R7 (WF_TMAC_BASE + 0x5c)


#define TMAC_CDTR (WF_TMAC_BASE + 0x90)
#define TMAC_ODTR (WF_TMAC_BASE + 0x94)

#ifdef ACK_CTS_TIMEOUT_SUPPORT
#define DEFALT_TMAC_CDTR_VALUE								0x003000E7
#define DEFALT_TMAC_ODTR_VALUE								0x001C003C
#define DEFALT_TMAC_OMDTR_VALUE								0x001C00D0
#endif/*ACK_CTS_TIMEOUT_SUPPORT*/


#define TMAC_ATCR (WF_TMAC_BASE + 0x98)
#define ATCR_TXV_TOUT_BIT       0
#define ATCR_TXV_TOUT_MASK (0xff)
#define ATCR_TXV_TOUT(p) (((p) & 0xff))
#define ATCR_GET_TXV_TOUT(p) (((p) & TXV_TOUT_MASK))
#define RIFS_TXV_TOUT_MASK (0xff << 8)
#define RIFS_TXV_TOUT(p) (((p) & 0xff) << 8)
#define GET_RIFS_TXV_TOUT(p) (((p) & RIFS_TXV_TOUT_MASK) >> 8)
#define AGG_TOUT_MASK (0xff << 16)
#define AGG_TOUT(p) (((p) & 0xff) << 16)
#define GET_AGG_TOUT(p) (((p) & AGG_TOUT_MASK) >> 16)

#define TMAC_TRCR0 (WF_TMAC_BASE + 0x9c)        /* 0x2109c */
#define TMAC_TRCR1 (WF_TMAC_BASE + 0x70)        /* 0x21070 */
#define TMAC_TR2T_CHK_BIT   0
#define TMAC_TR2T_CHK_MASK  (0x1ff)
#define CCA_SRC_SEL_MASK (0x3 << 30)
#define CCA_SRC_SEL(p) (((p) & 0x3) << 30)
#define CCA_SEC_SRC_SEL_MASK (0x3 << 28)
#define CCA_SEC_SRC_SEL(p) (((p) & 0x3) << 28)
#define I2T_CHK_EN  BIT25

#define TMAC_RRCR (WF_TMAC_BASE + 0xA0)         /* 0x210a0 */

#define TMAC_ICR_BAND_0 (WF_TMAC_BASE + 0xa4)       /* 0x210a4 */
#define TMAC_ICR_BAND_1 (WF_TMAC_BASE + 0x74)       /* 0x21074 */

#define ICR_EIFS_TIME_MASK (0x1ff)
#define ICR_EIFS_TIME(p) (((p) & 0x1ff))
#define GET_ICR_EIFS_TIME(p) (((p) & ICR_EIFS_TIME_MASK))
#define ICR_RIFS_TIME_MASK (0x1f << 10)
#define ICR_RIFS_TIME(p) (((p) & 0x1f) << 10)
#define GET_ICR_RIFS_TIME(p) (((p) & ICR_RIFS_TIME_MASK) >> 10)
#define ICR_SIFS_TIME_MASK (0x7f << 16)
#define ICR_SIFS_TIME(p) (((p) & 0x7f) << 16)
#define GET_ICR_SIFS_TIME(p) (((p) & ICR_SIFS_TIME_MASK) >> 16)
#define ICR_SLOT_TIME_MASK (0x7f << 24)
#define ICR_SLOT_TIME(p) (((p) & 0x7f) << 24)
#define GET_ICR_SLOT_TIME(p) (((p) & ICR_SLOT_TIME_MASK) >> 24)

#define TMAC_PCR (WF_TMAC_BASE + 0xb4)			/* 0x210b4 */
#define TMAC_PCR1 (WF_TMAC_BASE + 0xbc)			/* 0x210bc */
#define TMAC_PCR_FIX_OFDM_6M_RATE 0x4b
#define TMAC_PCR_AUTO_RATE 0x400
#define PTEC_FIX_RATE_MASK (0x1ff)
#define PTEC_FIX_RATE(p) (((p) & 0x1ff))
#define GET_PTEC_FIX_RATE(p) (((p) & PTEC_FIX_RATE_MASK))
#define PTEC_RATE_SEL (1 << 15)
#define GET_PTEC_RATE_SEL(p) (((p) & PTEC_RATE_SEL) >> 15)
#define PTEC_ANT_ID_MASK (0x3f << 16)
#define PTEC_ANT_ID(p) (((p) & 0x3f) << 16)
#define GET_PTEC_ANT_ID(p) (((p) & PTEC_ANT_ID_MASK) >> 16)
#define PTEC_ANT_ID_SEL (1 << 22)
#define GET_PTEC_ANT_ID_SEL(p) (((p) & PTEC_ANT_ID_SEL) >> 22)
#define PTEC_SPE_EN (1 << 23)
#define GET_PTEC_SPE_EN(p) (((p) & PTEC_SPE_EN) >> 23)
#define PTEC_ANT_PRI_MASK (0x7 << 24)
#define PTEC_ANT_PRI(p) (((p) & 0x7) << 24)
#define GET_PTEC_ANT_PRI(p) (((p) & PTEC_ANT_PRI_MASK) >> 24)
#define PTEC_ANT_PRI_SEL (1 << 27)
#define GET_PTEC_ANT_PRI_SEL(p) (((p) & PTEC_ANT_PRI_SEL) >> 27)

#define TMAC_B0BRR0		(WF_TMAC_BASE + 0xc0)		/* 0x210c0 */
#define TMAC_B1BRR0		(WF_TMAC_BASE + 0xc8)		/* 0x210c8 */
#define TMAC_B2BRR0		(WF_TMAC_BASE + 0xd0)		/* 0x210d0 */
#define TMAC_B3BRR0		(WF_TMAC_BASE + 0xd8)		/* 0x210d8 */
#define BSSID00_RESP_SPE_EN (1 << 16)

#define TMAC_B0BRR1		(WF_TMAC_BASE + 0xc4)		/* 0x210c4 */
#define TMAC_B1BRR1		(WF_TMAC_BASE + 0xcc)		/* 0x210cc */
#define TMAC_B2BRR1		(WF_TMAC_BASE + 0xd4)		/* 0x210d4 */
#define TMAC_B3BRR1		(WF_TMAC_BASE + 0xdc)		/* 0x210dc */
#define TMAC_QNCR0		(WF_TMAC_BASE + 0xe0)		/* 0x210e0 */
#define TMAC_QNCR1		(WF_TMAC_BASE + 0xe4)		/* 0x210e4 */
#define TMAC_QNCR2		(WF_TMAC_BASE + 0xe8)		/* 0x210e8 */
#define TMAC_QNCR3		(WF_TMAC_BASE + 0xec)		/* 0x210ec */
#define TMAC_QNCR4		(WF_TMAC_BASE + 0xf0)		/* 0x210f0 */
#define TMAC_CTCR0		(WF_TMAC_BASE + 0xf4)		/* 0x210f4 */

#define INS_DDLMT_REFTIME_MASK (0x3f)
#define INS_DDLMT_REFTIME(p) (((p) & 0x3f))
#define INS_DDLMT_EN (1 << 17)
#define INS_DDLMT_VHT_SMPDU_EN (1 << 18)
#define INS_DDLMT_DENSITY(p) ((p & 0xf) << 12)
#define DUMMY_DELIMIT_INSERTION (INS_DDLMT_EN | INS_DDLMT_VHT_SMPDU_EN)

#define TMAC_PCTSR      (WF_TMAC_BASE + 0x108)		/* 0x21108 */

#endif /* __WF_TMAC_H__ */

