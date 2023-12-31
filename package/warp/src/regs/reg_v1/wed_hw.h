/*
 ***************************************************************************
 * MediaTek Inc.
 *
 * All rights reserved. source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of MediaTek. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of MediaTek, Inc. is obtained.
 ***************************************************************************

	Module Name: wifi_offload
	wed_hw.h
*/
#ifndef __WED_HW_
#define __WED_HW_

#ifndef REG_FLD
#define REG_FLD(width, shift) (shift)
#endif /*REG_FLD*/


/*1020A000*/
#define WED_REG_BASE 0

#define  WED_REV (WED_REG_BASE + 0x00000000)
#define  WED_MOD_RST (WED_REG_BASE + 0x00000008)
#define  WED_CTRL (WED_REG_BASE + 0x0000000C)
#define  WED_AXI_CTRL (WED_REG_BASE + 0x00000010)
#define  WED_EX_INT_STA (WED_REG_BASE + 0x00000020)
#define  WED_EX_INT_MSK (WED_REG_BASE + 0x00000028)
#define  WED_ST (WED_REG_BASE + 0x00000060)
#define  WED_WPDMA_ST (WED_REG_BASE + 0x00000064)
#define  WED_WDMA_ST (WED_REG_BASE + 0x00000068)
#define  WED_BM_ST (WED_REG_BASE + 0x0000006C)
#define  WED_TX_BM_CTRL (WED_REG_BASE + 0x00000080)
#define  WED_TX_BM_BASE (WED_REG_BASE + 0x00000084)
#define  WED_TX_BM_TKID (WED_REG_BASE + 0x00000088)
#define  WED_TX_BM_BLEN (WED_REG_BASE + 0x0000008C)
#define  WED_TX_BM_STS (WED_REG_BASE + 0x00000090)
#define  WED_TX_BM_INTF (WED_REG_BASE + 0x0000009C)
#define  WED_TX_BM_DYN_TH (WED_REG_BASE + 0x000000A0)
#define  WED_TX_BM_RECYC (WED_REG_BASE + 0x000000A8)
#define  WED_TX_BM_VB_FREE_0_31 (WED_REG_BASE + 0x000000B0)
#define  WED_TX_BM_VB_FREE_32_63 (WED_REG_BASE + 0x000000B4)
#define  WED_TX_BM_VB_USED_0_31 (WED_REG_BASE + 0x000000B8)
#define  WED_TX_BM_VB_USED_32_63 (WED_REG_BASE + 0x000000BC)
#define  WED_INT_STA (WED_REG_BASE + 0x00000200)
#define  WED_INT_MSK (WED_REG_BASE + 0x00000204)
#define  WED_GLO_CFG (WED_REG_BASE + 0x00000208)
#define  WED_RST_IDX (WED_REG_BASE + 0x0000020C)
#define  WED_DLY_INT_CFG (WED_REG_BASE + 0x00000210)
#define  WED_SPR (WED_REG_BASE + 0x0000021C)
#define  WED_TX0_MIB (WED_REG_BASE + 0x000002A0)
#define  WED_TX1_MIB (WED_REG_BASE + 0x000002A4)
#define  WED_RX0_MIB (WED_REG_BASE + 0x000002E0)
#define  WED_RX1_MIB (WED_REG_BASE + 0x000002E4)
#define  WED_TX0_CTRL0 (WED_REG_BASE + 0x00000300)
#define  WED_TX0_CTRL1 (WED_REG_BASE + 0x00000304)
#define  WED_TX0_CTRL2 (WED_REG_BASE + 0x00000308)
#define  WED_TX0_CTRL3 (WED_REG_BASE + 0x0000030C)
#define  WED_TX1_CTRL0 (WED_REG_BASE + 0x00000310)
#define  WED_TX1_CTRL1 (WED_REG_BASE + 0x00000314)
#define  WED_TX1_CTRL2 (WED_REG_BASE + 0x00000318)
#define  WED_TX1_CTRL3 (WED_REG_BASE + 0x0000031C)
#define  WED_RX0_CTRL0 (WED_REG_BASE + 0x00000400)
#define  WED_RX0_CTRL1 (WED_REG_BASE + 0x00000404)
#define  WED_RX0_CTRL2 (WED_REG_BASE + 0x00000408)
#define  WED_RX0_CTRL3 (WED_REG_BASE + 0x0000040C)
#define  WED_RX1_CTRL0 (WED_REG_BASE + 0x00000410)
#define  WED_RX1_CTRL1 (WED_REG_BASE + 0x00000414)
#define  WED_RX1_CTRL2 (WED_REG_BASE + 0x00000418)
#define  WED_RX1_CTRL3 (WED_REG_BASE + 0x0000041C)
#define  WED_WPDMA_INT_STA_REC (WED_REG_BASE + 0x00000500)
#define  WED_WPDMA_INT_TRIG (WED_REG_BASE + 0x00000504)
#define  WED_WPDMA_GLO_CFG (WED_REG_BASE + 0x00000508)
#define  WED_WPDMA_RST_IDX (WED_REG_BASE + 0x0000050C)

#define  WED_PCIE_CFG_BASE (WED_REG_BASE + 0x00000560)
#define  WED_PCIE_OFST (WED_REG_BASE + 0x00000564)
#define  WED_PCIE_INTS_TRIG (WED_REG_BASE + 0x00000570)
#define  WED_PCIE_INTS_REC (WED_REG_BASE + 0x00000574)
#define  WED_WPDMA_CFG_BASE (WED_REG_BASE + 0x00000580)
#define  WED_WPDMA_OFST0 (WED_REG_BASE + 0x00000584)
#define  WED_WPDMA_OFST1 (WED_REG_BASE + 0x00000588)
#define  WED_WPDMA_TX0_MIB (WED_REG_BASE + 0x000005A0)
#define  WED_WPDMA_TX1_MIB (WED_REG_BASE + 0x000005A4)
#define  WED_WPDMA_TX0_COHERENT_MIB (WED_REG_BASE + 0x000005D0)
#define  WED_WPDMA_TX1_COHERENT_MIB (WED_REG_BASE + 0x000005D4)
#define  WED_WPDMA_RX1_COHERENT_MIB (WED_REG_BASE + 0x000005F0)
#define  WED_WPDMA_RX_EXTC_FREE_TKID_MIB (WED_REG_BASE + 0x000005F8)
#define  WED_WPDMA_RX0_MIB (WED_REG_BASE + 0x000005E0)
#define  WED_WPDMA_RX1_MIB (WED_REG_BASE + 0x000005E4)
#define  WED_WPDMA_TX0_CTRL0 (WED_REG_BASE + 0x00000600)
#define  WED_WPDMA_TX0_CTRL1 (WED_REG_BASE + 0x00000604)
#define  WED_WPDMA_TX0_CTRL2 (WED_REG_BASE + 0x00000608)
#define  WED_WPDMA_TX0_CTRL3 (WED_REG_BASE + 0x0000060C)
#define  WED_WPDMA_TX1_CTRL0 (WED_REG_BASE + 0x00000610)
#define  WED_WPDMA_TX1_CTRL1 (WED_REG_BASE + 0x00000614)
#define  WED_WPDMA_TX1_CTRL2 (WED_REG_BASE + 0x00000618)
#define  WED_WPDMA_TX1_CTRL3 (WED_REG_BASE + 0x0000061C)
#define  WED_WPDMA_RX0_CTRL0 (WED_REG_BASE + 0x00000700)
#define  WED_WPDMA_RX0_CTRL1 (WED_REG_BASE + 0x00000704)
#define  WED_WPDMA_RX0_CTRL2 (WED_REG_BASE + 0x00000708)
#define  WED_WPDMA_RX0_CTRL3 (WED_REG_BASE + 0x0000070C)
#define  WED_WPDMA_RX1_CTRL0 (WED_REG_BASE + 0x00000710)
#define  WED_WPDMA_RX1_CTRL1 (WED_REG_BASE + 0x00000714)
#define  WED_WPDMA_RX1_CTRL2 (WED_REG_BASE + 0x00000718)
#define  WED_WPDMA_RX1_CTRL3 (WED_REG_BASE + 0x0000071C)
#define  WED_WDMA_TX0_BASE (WED_REG_BASE + 0x00000800)
#define  WED_WDMA_TX0_CNT (WED_REG_BASE + 0x00000804)
#define  WED_WDMA_TX0_CTX_IDX (WED_REG_BASE + 0x00000808)
#define  WED_WDMA_TX0_DTX_IDX (WED_REG_BASE + 0x0000080C)
#define  WED_WDMA_TX1_BASE (WED_REG_BASE + 0x00000810)
#define  WED_WDMA_TX1_CNT (WED_REG_BASE + 0x00000814)
#define  WED_WDMA_TX1_CTX_IDX (WED_REG_BASE + 0x00000818)
#define  WED_WDMA_TX1_DTX_IDX (WED_REG_BASE + 0x0000081C)
#define  WED_WDMA_RX0_BASE (WED_REG_BASE + 0x00000900)
#define  WED_WDMA_RX0_CNT (WED_REG_BASE + 0x00000904)
#define  WED_WDMA_RX0_CRX_IDX (WED_REG_BASE + 0x00000908)
#define  WED_WDMA_RX0_DRX_IDX (WED_REG_BASE + 0x0000090C)
#define  WED_WDMA_RX1_BASE (WED_REG_BASE + 0x00000910)
#define  WED_WDMA_RX1_CNT (WED_REG_BASE + 0x00000914)
#define  WED_WDMA_RX1_CRX_IDX (WED_REG_BASE + 0x00000918)
#define  WED_WDMA_RX1_DRX_IDX (WED_REG_BASE + 0x0000091C)
#define  WED_WDMA_RX0_THRES_CFG (WED_REG_BASE + 0x00000940)
#define  WED_WDMA_RX1_THRES_CFG (WED_REG_BASE + 0x00000944)
#define  WED_WDMA_INFO (WED_REG_BASE + 0x00000A00)
#define  WED_WDMA_GLO_CFG (WED_REG_BASE + 0x00000A04)
#define  WED_WDMA_RST_IDX (WED_REG_BASE + 0x00000A08)
#define  WED_WDMA_LOAD_DRV_IDX (WED_REG_BASE + 0x00000A10)
#define  WED_WDMA_LOAD_CRX_IDX (WED_REG_BASE + 0x00000A14)
#define  WED_WDMA_SPR (WED_REG_BASE + 0x00000A1C)

#define  WED_WDMA_INT_STA_REC (WED_REG_BASE + 0x00000A20)
#define  WED_WDMA_INT_CLR (WED_REG_BASE + 0x00000A24)
#define  WED_WDMA_INT_TRIG (WED_REG_BASE + 0x00000A28)
#define  WED_WDMA_INT_CTRL	(WED_REG_BASE + 0x00000A2C)
#define  WED_WDMA_CFG_BASE (WED_REG_BASE + 0x00000AA0)
#define  WED_WDMA_OFST0 (WED_REG_BASE + 0x00000AA4)
#define  WED_WDMA_OFST1 (WED_REG_BASE + 0x00000AA8)
#define  WED_WDMA_RX0_MIB (WED_REG_BASE + 0x00000AE0)
#define  WED_WDMA_RX1_MIB (WED_REG_BASE + 0x00000AE4)

#define  WED_IRQ_MON (WED_REG_BASE + 0x00000050)

#define  WED_TX_BM_VB_FREE_0_31  (WED_REG_BASE + 0x000000B0)
#define  WED_TX_BM_VB_FREE_32_63  (WED_REG_BASE + 0x000000B4)
#define  WED_TX_BM_VB_USED_0_31  (WED_REG_BASE + 0x000000B8)
#define  WED_TX_BM_VB_USED_32_63  (WED_REG_BASE + 0x000000BC)

#define  WED_WDMA_INT_MON (WED_REG_BASE + 0x00000A3C)
#define  WED_WPDMA_INT_CTRL (WED_REG_BASE + 0x00000520)
#define  WED_WPDMA_INT_MSK (WED_REG_BASE + 0x00000524)
#define  WED_WPDMA_INT_CLR (WED_REG_BASE + 0x00000528)
#define  WED_WPDMA_INT_MON (WED_REG_BASE + 0x0000052C)
#define  WED_WPDMA_SPR (WED_REG_BASE + 0x0000053C)
#define  WED_PCIE_INTM_REC (WED_REG_BASE + 0x00000578)
#define  WED_PCIE_INT_CTRL (WED_REG_BASE + 0x0000057c)


#define	 WED_TXD_DW0 (WED_REG_BASE + 0x00000100)
#define	 WED_TXD_DW1 (WED_REG_BASE + 0x00000104)
#define	 WED_TXD_DW2 (WED_REG_BASE + 0x00000108)
#define	 WED_TXD_DW3 (WED_REG_BASE + 0x0000010C)
#define	 WED_TXD_DW4 (WED_REG_BASE + 0x00000110)
#define	 WED_TXD_DW5 (WED_REG_BASE + 0x00000114)
#define	 WED_TXD_DW6 (WED_REG_BASE + 0x00000118)
#define	 WED_TXD_DW7 (WED_REG_BASE + 0x0000011C)
#define  WED_TXDP_CTRL (WED_REG_BASE + 0x00000130)

#define	 WED_TXP_DW0 (WED_REG_BASE + 0x00000120)
#define	 WED_TXP_DW1 (WED_REG_BASE + 0x00000124)

#define WED_TX_FREE_TO_TX_BM_TKID_MIB (WED_REG_BASE + 0x000001C0)
#define WED_TX_BM_TO_WDMA_RX_DRV_TKID_MIB (WED_REG_BASE + 0x000001C4)

#define  WED_DBG_CTRL (WED_REG_BASE + 0x00000BC0)
#define  WED_DBG_PRB0 (WED_REG_BASE + 0x00000BD0)
#define  WED_DBG_PRB1 (WED_REG_BASE + 0x00000BD4)
#define  WED_DBG_PRB2 (WED_REG_BASE + 0x00000BD8)
#define  WED_DBG_PRB3 (WED_REG_BASE + 0x00000BDC)

#define WED_CTRL2 (WED_REG_BASE + 0x0000001C)
#define WED_TX_COHERENT_MIB (WED_REG_BASE + 0x000002D0)
#define WED_WPDAM_CTRL (WED_REG_BASE + 0x00000518)
#define WED_WDMA_RX0_THRES_CFG (WED_REG_BASE + 0x00000940)
#define WED_WDMA_RX1_THRES_CFG (WED_REG_BASE + 0x00000944)
#define WED_WDMA_RX0_RECYCLE_MIB (WED_REG_BASE + 0x00000AE8)
#define WED_WDMA_RX1_RECYCLE_MIB (WED_REG_BASE + 0x00000AEC)
#define WED_WDMA_RX0_PROCESSED_MIB (WED_REG_BASE + 0x00000AF0)
#define WED_WDMA_RX1_PROCESSED_MIB (WED_REG_BASE + 0x00000AF4)
#define WED_WDMA_RX_COHERENT_MIB (WED_REG_BASE + 0x00000AF8)
#define WED_BMF_VALID_TABLE_START (WED_REG_BASE + 0x00000C00)
#define WED_BMF_VALID_TABLE_END (WED_REG_BASE + 0x00000FFC)


#define WED_REV_FLD_PROJECT							REG_FLD(16, 16)
#define WED_REV_FLD_VERSION							REG_FLD(8, 0)

#define WED_MOD_RST_FLD_WED							REG_FLD(1, 31)
#define WED_MOD_RST_FLD_TX_FREE_AGT					REG_FLD(1, 4)
#define WED_MOD_RST_FLD_WPDMA_TX_DRV				REG_FLD(1, 8)
#define WED_MOD_RST_FLD_WPDMA_RX_DRV				REG_FLD(1, 9)
#define WED_MOD_RST_FLD_WPDMA_INT_AGT				REG_FLD(1, 11)
#define WED_MOD_RST_FLD_WED_TX_DMA					REG_FLD(1, 12)
#define WED_MOD_RST_FLD_WDMA_RX_DRV					REG_FLD(1, 17)
#define WED_MOD_RST_FLD_WDMA_INT_AGT				REG_FLD(1, 19)
#define WED_MOD_RST_FLD_TX_BM						REG_FLD(1, 0)

#define WED_CTRL_FLD_MIB_RD_CLR						REG_FLD(1, 28)
#define WED_CTRL_FLD_FINAL_DIDX_RD					REG_FLD(1, 24)
#define WED_CTRL_FLD_BUSY_RSV						REG_FLD(1, 13)
#define WED_CTRL_FLD_EN_RSV							REG_FLD(1, 12)
#define WED_CTRL_FLD_WED_TX_FREE_AGT_BUSY			REG_FLD(1, 11)
#define WED_CTRL_FLD_WED_TX_FREE_AGT_EN				REG_FLD(1, 10)
#define WED_CTRL_FLD_WED_TX_BM_BUSY					REG_FLD(1, 9)
#define WED_CTRL_FLD_WED_TX_BM_EN					REG_FLD(1, 8)
#define WED_CTRL_FLD_WDMA_INT_AGT_BUSY				REG_FLD(1, 3)
#define WED_CTRL_FLD_WDMA_INT_AGT_EN				REG_FLD(1, 2)
#define WED_CTRL_FLD_WPDMA_INT_AGT_BUSY				REG_FLD(1, 1)
#define WED_CTRL_FLD_WPDMA_INT_AGT_EN				REG_FLD(1, 0)

#define WED_EX_INT_STA_FLD_RX_DRV_DMA_RECYCLE		REG_FLD(1, 24)
#define WED_EX_INT_STA_FLD_TX_DMA_W_RESP_ERR		REG_FLD(1, 22)
#define WED_EX_INT_STA_FLD_TX_DMA_R_RESP_ERR		REG_FLD(1, 21)
#define WED_EX_INT_STA_FLD_RX_DRV_BM_DMAD_COHERENT	REG_FLD(1, 20)
#define WED_EX_INT_STA_FLD_RX_DRV_INTI_WDMA_ENABLE	REG_FLD(1, 19)
#define WED_EX_INT_STA_FLD_RX_DRV_COHERENT			REG_FLD(1, 18)
#define WED_EX_INT_STA_FLD_RX_DRV_W_RESP_ERR		REG_FLD(1, 17)
#define WED_EX_INT_STA_FLD_RX_DRV_R_RESP_ERR		REG_FLD(1, 16)
#define WED_EX_INT_STA_FLD_RX_FBUF_HTH				REG_FLD(1, 13)
#define WED_EX_INT_STA_FLD_RX_FBUF_LTH				REG_FLD(1, 12)
#define WED_EX_INT_STA_FLD_TX_FBUF_HTH				REG_FLD(1, 9)
#define WED_EX_INT_STA_FLD_TX_FBUF_LTH				REG_FLD(1, 8)
#define WED_EX_INT_STA_FLD_TF_TKID_TITO_INVLD		REG_FLD(1, 4)
#define WED_EX_INT_STA_FLD_TF_TKID_WO_PYLD			REG_FLD(1, 1)
#define WED_EX_INT_STA_FLD_TF_LEN_ERR				REG_FLD(1, 0)

#define WED_EX_INT_MSK_FLD_EX_INT_MSK				REG_FLD(32, 0)

#define WED_ST_FLD_TX_ST							REG_FLD(8, 8)

#define WED_WPDMA_ST_FLD_ISR_ST						REG_FLD(8, 16)
#define WED_WPDMA_ST_FLD_TX_DRV_ST					REG_FLD(8, 8)
#define WED_WPDMA_ST_FLD_RX_DRV_ST					REG_FLD(8, 0)

#define WED_WPDMA_INT_CTRL_FLD_SUBRT_ADV			REG_FLD(1, 21)
#define WED_WPDMA_INT_CTRL_FLD_MSK_ON_DLY			REG_FLD(1, 23)
#define WED_WPDMA_INT_CTRL_FLD_MSK_ON_DLY_PRD		REG_FLD(8, 0)


#define WED_WDMA_ST_FLD_ISR_ST						REG_FLD(8, 16)
#define WED_WDMA_ST_FLD_TX_DRV_ST					REG_FLD(8, 8)
#define WED_WDMA_ST_FLD_RX_DRV_ST					REG_FLD(8, 0)

#define WED_BM_ST_FLD_FREE_AGENT_ST					REG_FLD(8, 24)
#define WED_BM_ST_FLD_REODR_AGENT_ST				REG_FLD(8, 16)
#define WED_BM_ST_FLD_TX_BMU_ST						REG_FLD(8, 8)
#define WED_BM_ST_FLD_RX_BMU_ST						REG_FLD(8, 0)

#define WED_TX_BM_CTRL_FLD_PAUSE					REG_FLD(1, 28)
#define WED_TX_BM_CTRL_FLD_RSV_GRP_NUM				REG_FLD(7, 16)
#define WED_TX_BM_CTRL_FLD_RSV_GRP_NUM_MASK			0x7f
#define WED_TX_BM_CTRL_FLD_VLD_GRP_NUM				REG_FLD(7, 0)
#define WED_TX_BM_CTRL_FLD_VLD_GRP_NUM_MASK			0x7f

#define WED_TX_BM_TKID_FLD_END_ID					REG_FLD(16, 16)
#define WED_TX_BM_TKID_FLD_START_ID					REG_FLD(16, 0)

#define WED_TX_BM_BLEN_FLD_BYTE_LEN					REG_FLD(14, 0)
#define WED_TX_BM_BLEN_FLD_BYTE_LEN_MASK			0x3fff
#define WED_TX_BM_STS_FLD_DMAD_RD					REG_FLD(1, 25)
#define WED_TX_BM_STS_FLD_DMAD_VLD					REG_FLD(1, 24)
#define WED_TX_BM_STS_FLD_DMAD_NUM					REG_FLD(5, 16)
#define WED_TX_BM_STS_FLD_FREE_NUM					REG_FLD(16, 0)

#define WED_TX_BM_INTF_FLD_FREE_TKID_RD				REG_FLD(1, 29)
#define WED_TX_BM_INTF_FLD_FREE_TKID_VLD			REG_FLD(1, 28)
#define WED_TX_BM_INTF_FLD_FREE_TKFIFO_FDEP			REG_FLD(7, 16)
#define WED_TX_BM_INTF_FLD_FREE_TKID				REG_FLD(16, 0)

#define WED_TX_BM_DYN_TH_FLD_HI_GRP_NUM				REG_FLD(7, 16)
#define WED_TX_BM_DYN_TH_FLD_HI_GRP_MASK			0x7f
#define WED_TX_BM_DYN_TH_FLD_LOW_GRP_NUM			REG_FLD(7, 0)
#define WED_TX_BM_DYN_TH_FLD_LOW_GRP_MASK			0x7f

#define WED_TX_BM_RECYC_FLD_START_GRP_IDX			REG_FLD(7, 0)

#define WED_INT_STA_FLD_FW_CLR_OWN_INT				REG_FLD(1, 31)
#define WED_INT_STA_FLD_MCU_CMD_INT					REG_FLD(1, 30)
#define WED_INT_STA_FLD_MAC_INT_5					REG_FLD(1, 29)
#define WED_INT_STA_FLD_MAC_INT_4					REG_FLD(1, 28)
#define WED_INT_STA_FLD_MAC_INT_3					REG_FLD(1, 27)
#define WED_INT_STA_FLD_MAC_INT_2					REG_FLD(1, 26)
#define WED_INT_STA_FLD_MAC_INT_1					REG_FLD(1, 25)
#define WED_INT_STA_FLD_MAC_INT_0					REG_FLD(1, 24)
#define WED_INT_STA_FLD_TX_DLY_INT					REG_FLD(1, 23)
#define WED_INT_STA_FLD_RX_DLY_INT					REG_FLD(1, 22)
#define WED_INT_STA_FLD_TX_COHERENT					REG_FLD(1, 21)
#define WED_INT_STA_FLD_RX_COHERENT					REG_FLD(1, 20)
#define WED_INT_STA_FLD_TX_DONE_INT15				REG_FLD(1, 19)
#define WED_INT_STA_FLD_TX_DONE_INT14				REG_FLD(1, 18)
#define WED_INT_STA_FLD_TX_DONE_INT13				REG_FLD(1, 17)
#define WED_INT_STA_FLD_TX_DONE_INT12				REG_FLD(1, 16)
#define WED_INT_STA_FLD_TX_DONE_INT11				REG_FLD(1, 15)
#define WED_INT_STA_FLD_TX_DONE_INT10				REG_FLD(1, 14)
#define WED_INT_STA_FLD_TX_DONE_INT9				REG_FLD(1, 13)
#define WED_INT_STA_FLD_TX_DONE_INT8				REG_FLD(1, 12)
#define WED_INT_STA_FLD_TX_DONE_INT7				REG_FLD(1, 11)
#define WED_INT_STA_FLD_TX_DONE_INT6				REG_FLD(1, 10)
#define WED_INT_STA_FLD_TX_DONE_INT5				REG_FLD(1, 9)
#define WED_INT_STA_FLD_TX_DONE_INT4				REG_FLD(1, 8)
#define WED_INT_STA_FLD_TX_DONE_INT3				REG_FLD(1, 7)
#define WED_INT_STA_FLD_TX_DONE_INT2				REG_FLD(1, 6)
#define WED_INT_STA_FLD_TX_DONE_INT1				REG_FLD(1, 5)
#define WED_INT_STA_FLD_TX_DONE_INT0				REG_FLD(1, 4)
#define WED_INT_STA_FLD_RX_DONE_INT3				REG_FLD(1, 3)
#define WED_INT_STA_FLD_RX_DONE_INT2				REG_FLD(1, 2)
#define WED_INT_STA_FLD_RX_DONE_INT1				REG_FLD(1, 1)
#define WED_INT_STA_FLD_RX_DONE_INT0				REG_FLD(1, 0)

#define WED_INT_MSK_FLD_FW_CLR_OWN_INT				REG_FLD(1, 31)
#define WED_INT_MSK_FLD_MCU_CMD_INT					REG_FLD(1, 30)
#define WED_INT_MSK_FLD_MAC_INT5					REG_FLD(1, 29)
#define WED_INT_MSK_FLD_MAC_INT4					REG_FLD(1, 28)
#define WED_INT_MSK_FLD_MAC_INT3					REG_FLD(1, 27)
#define WED_INT_MSK_FLD_MAC_INT2					REG_FLD(1, 26)
#define WED_INT_MSK_FLD_MAC_INT1					REG_FLD(1, 25)
#define WED_INT_MSK_FLD_MAC_INT0					REG_FLD(1, 24)
#define WED_INT_MSK_FLD_TX_DLY_INT					REG_FLD(1, 23)
#define WED_INT_MSK_FLD_RX_DLY_INT					REG_FLD(1, 22)
#define WED_INT_MSK_FLD_TX_COHERENT					REG_FLD(1, 21)
#define WED_INT_MSK_FLD_RX_COHERENT					REG_FLD(1, 20)
#define WED_INT_MSK_FLD_TX_DONE_INT15				REG_FLD(1, 19)
#define WED_INT_MSK_FLD_TX_DONE_INT14				REG_FLD(1, 18)
#define WED_INT_MSK_FLD_TX_DONE_INT13				REG_FLD(1, 17)
#define WED_INT_MSK_FLD_TX_DONE_INT12				REG_FLD(1, 16)
#define WED_INT_MSK_FLD_TX_DONE_INT11				REG_FLD(1, 15)
#define WED_INT_MSK_FLD_TX_DONE_INT10				REG_FLD(1, 14)
#define WED_INT_MSK_FLD_TX_DONE_INT9				REG_FLD(1, 13)
#define WED_INT_MSK_FLD_TX_DONE_INT8				REG_FLD(1, 12)
#define WED_INT_MSK_FLD_TX_DONE_INT7				REG_FLD(1, 11)
#define WED_INT_MSK_FLD_TX_DONE_INT6				REG_FLD(1, 10)
#define WED_INT_MSK_FLD_TX_DONE_INT5				REG_FLD(1, 9)
#define WED_INT_MSK_FLD_TX_DONE_INT4				REG_FLD(1, 8)
#define WED_INT_MSK_FLD_TX_DONE_INT3				REG_FLD(1, 7)
#define WED_INT_MSK_FLD_TX_DONE_INT2				REG_FLD(1, 6)
#define WED_INT_MSK_FLD_TX_DONE_INT1				REG_FLD(1, 5)
#define WED_INT_MSK_FLD_TX_DONE_INT0				REG_FLD(1, 4)
#define WED_INT_MSK_FLD_RX_DONE_INT3				REG_FLD(1, 3)
#define WED_INT_MSK_FLD_RX_DONE_INT2				REG_FLD(1, 2)
#define WED_INT_MSK_FLD_RX_DONE_INT1				REG_FLD(1, 1)
#define WED_INT_MSK_FLD_RX_DONE_INT0				REG_FLD(1, 0)

#define WED_WPDMA_INT_TRIG_FLD_RX_DONE_INT1			REG_FLD(1, 1)
#define WED_WPDMA_INT_TRIG_FLD_TX_DONE_INT0			REG_FLD(1, 4)
#define WED_WPDMA_INT_TRIG_FLD_TX_DONE_INT1			REG_FLD(1, 5)


#define WED_GLO_CFG_FLD_RX_2B_OFFSET				REG_FLD(1, 31)
#define WED_GLO_CFG_FLD_BYTE_SWAP                              REG_FLD(1, 29)
#define WED_GLO_CFG_FLD_OMIT_TX_INFO                           REG_FLD(1, 28)
#define WED_GLO_CFG_FLD_OMIT_RX_INFO                           REG_FLD(1, 27)
#define WED_GLO_CFG_FLD_FIRST_TOKEN_ONLY                       REG_FLD(1, 26)
#define WED_GLO_CFG_FLD_SW_RST                                 REG_FLD(1, 24)
#define WED_GLO_CFG_FLD_TX_BT_SIZE_BIT21                       REG_FLD(2, 22)
#define WED_GLO_CFG_FLD_MI_DEPTH_RD_8_6                        REG_FLD(3, 19)
#define WED_GLO_CFG_FLD_MI_DEPTH_RD_5_3                        REG_FLD(3, 16)
#define WED_GLO_CFG_FLD_MI_DEPTH_RD_2_0                        REG_FLD(3, 13)
#define WED_GLO_CFG_FLD_FIFO_LITTLE_ENDIAN                     REG_FLD(1, 12)
#define WED_GLO_CFG_FLD_MULTI_DMA_EN                           REG_FLD(2, 10)
#define WED_GLO_CFG_FLD_TX_BT_SIZE_BIT0                        REG_FLD(1, 9)
#define WED_GLO_CFG_FLD_DIS_BT_SIZE_ALIGN                      REG_FLD(1, 8)
#define WED_GLO_CFG_FLD_BIG_ENDIAN                             REG_FLD(1, 7)
#define WED_GLO_CFG_FLD_TX_WB_DDONE                            REG_FLD(1, 6)
#define WED_GLO_CFG_FLD_RX_BT_SIZE                             REG_FLD(2, 4)
#define WED_GLO_CFG_FLD_RX_DMA_BUSY                            REG_FLD(1, 3)
#define WED_GLO_CFG_FLD_RX_DMA_EN                              REG_FLD(1, 2)
#define WED_GLO_CFG_FLD_TX_DMA_BUSY                            REG_FLD(1, 1)
#define WED_GLO_CFG_FLD_TX_DMA_EN                              REG_FLD(1, 0)

#define WED_RST_IDX_FLD_DRX_IDX1                               REG_FLD(1, 17)
#define WED_RST_IDX_FLD_DRX_IDX0                               REG_FLD(1, 16)
#define WED_RST_IDX_FLD_DTX_IDX3                               REG_FLD(1, 3)
#define WED_RST_IDX_FLD_DTX_IDX2                               REG_FLD(1, 2)
#define WED_RST_IDX_FLD_DTX_IDX1                               REG_FLD(1, 1)
#define WED_RST_IDX_FLD_DTX_IDX0                               REG_FLD(1, 0)

#define WED_DLY_INT_CFG_FLD_TX_DLY_INT_EN                      REG_FLD(1, 31)
#define WED_DLY_INT_CFG_FLD_TX_MAX_PINT                        REG_FLD(7, 24)
#define WED_DLY_INT_CFG_FLD_TX_MAX_PTIME                       REG_FLD(8, 16)
#define WED_DLY_INT_CFG_FLD_RX_DLY_INT_EN                      REG_FLD(1, 15)
#define WED_DLY_INT_CFG_FLD_RX_MAX_PINT                        REG_FLD(7, 8)
#define WED_DLY_INT_CFG_FLD_RX_MAX_PTIME                       REG_FLD(8, 0)

#define WED_TX0_MIB_FLD_PKT_CNT                                REG_FLD(32, 0)

#define WED_TX1_MIB_FLD_PKT_CNT                                REG_FLD(32, 0)

#define WED_RX0_MIB_FLD_PKT_CNT                                REG_FLD(32, 0)

#define WED_RX1_MIB_FLD_PKT_CNT                                REG_FLD(32, 0)

#define WED_TX0_CTRL0_FLD_BASE_PTR                             REG_FLD(32, 0)

#define WED_TX0_CTRL1_FLD_MAX_CNT                              REG_FLD(12, 0)

#define WED_TX0_CTRL2_FLD_CPU_IDX                              REG_FLD(12, 0)

#define WED_TX0_CTRL3_FLD_DMA_IDX                              REG_FLD(12, 0)

#define WED_TX1_CTRL0_FLD_BASE_PTR                             REG_FLD(32, 0)

#define WED_TX1_CTRL1_FLD_MAX_CNT                              REG_FLD(12, 0)

#define WED_TX1_CTRL2_FLD_CPU_IDX                              REG_FLD(12, 0)

#define WED_TX1_CTRL3_FLD_DMA_IDX                              REG_FLD(12, 0)

#define WED_RX0_CTRL0_FLD_BASE_PTR                             REG_FLD(32, 0)

#define WED_RX0_CTRL1_FLD_MAX_CNT                              REG_FLD(12, 0)

#define WED_RX0_CTRL2_FLD_CPU_IDX                              REG_FLD(12, 0)

#define WED_RX0_CTRL3_FLD_DMA_IDX                              REG_FLD(12, 0)

#define WED_RX1_CTRL0_FLD_BASE_PTR                             REG_FLD(32, 0)

#define WED_RX1_CTRL1_FLD_MAX_CNT                              REG_FLD(12, 0)

#define WED_RX1_CTRL2_FLD_CPU_IDX                              REG_FLD(12, 0)

#define WED_RX1_CTRL3_FLD_DMA_IDX                              REG_FLD(12, 0)

#define WED_WPDMA_INT_STA_REC_FLD_INT_STA                      REG_FLD(32, 0)

#define WED_WPDMA_GLO_CFG_FLD_RX_2B_OFFSET                     REG_FLD(1, 31)
#define WED_WPDMA_GLO_CFG_FLD_BYTE_SWAP                        REG_FLD(1, 29)
#define WED_WPDMA_GLO_CFG_FLD_OMIT_TX_INFO                     REG_FLD(1, 28)
#define WED_WPDMA_GLO_CFG_FLD_OMIT_RX_INFO                     REG_FLD(1, 27)
#define WED_WPDMA_GLO_CFG_FLD_FIRST_TOKEN_ONLY                 REG_FLD(1, 26)
#define WED_WPDMA_GLO_CFG_FLD_SW_RST                           REG_FLD(1, 24)
#define WED_WPDMA_GLO_CFG_FLD_TX_BT_SIZE_BIT21                 REG_FLD(2, 22)
#define WED_WPDMA_GLO_CFG_FLD_MI_DEPTH_RD_8_6                  REG_FLD(3, 19)
#define WED_WPDMA_GLO_CFG_FLD_MI_DEPTH_RD_5_3                  REG_FLD(3, 16)
#define WED_WPDMA_GLO_CFG_FLD_MI_DEPTH_RD_2_0                  REG_FLD(3, 13)
#define WED_WPDMA_GLO_CFG_FLD_FIFO_LITTLE_ENDIAN               REG_FLD(1, 12)
#define WED_WPDMA_GLO_CFG_FLD_MULTI_DMA_EN                     REG_FLD(2, 10)
#define WED_WPDMA_GLO_CFG_FLD_TX_BT_SIZE_BIT0                  REG_FLD(1, 9)
#define WED_WPDMA_GLO_CFG_FLD_DIS_BT_SIZE_ALIGN                REG_FLD(1, 8)
#define WED_WPDMA_GLO_CFG_FLD_BIG_ENDIAN                       REG_FLD(1, 7)
#define WED_WPDMA_GLO_CFG_FLD_TX_WB_DDONE                      REG_FLD(1, 6)
#define WED_WPDMA_GLO_CFG_FLD_RX_BT_SIZE                       REG_FLD(2, 4)
#define WED_WPDMA_GLO_CFG_FLD_RX_DRV_BUSY                      REG_FLD(1, 3)
#define WED_WPDMA_GLO_CFG_FLD_RX_DRV_EN                        REG_FLD(1, 2)
#define WED_WPDMA_GLO_CFG_FLD_TX_DRV_BUSY                      REG_FLD(1, 1)
#define WED_WPDMA_GLO_CFG_FLD_TX_DRV_EN                        REG_FLD(1, 0)


#define WED_WPDMA_RST_IDX_FLD_CTX_IDX0							REG_FLD(1, 0)
#define WED_WPDMA_RST_IDX_FLD_CTX_IDX1							REG_FLD(1, 1)
#define WED_WPDMA_RST_IDX_FLD_CRX_IDX1							REG_FLD(1, 17)


#define WED_WDMA_GLO_CFG_FLD_RXDRV_CLKGATE_BYP					REG_FLD(1, 30)
#define WED_WDMA_GLO_CFG_FLD_RST_INIT_COMPLETE_FLAG				REG_FLD(1, 26)
#define WED_WDMA_GLO_CFG_FLD_DYNAMIC_DMAD_RECYCLE				REG_FLD(1, 25)
#define WED_WDMA_GLO_CFG_FLD_DYNAMIC_SKIP_DMAD_PREPARE			REG_FLD(1, 24)
#define WED_WDMA_GLO_CFG_FLD_IDLE_STATE_DMAD_SUPPLY_EN			REG_FLD(1, 23)
#define WED_WDMA_GLO_CFG_FLD_IDLE_STATE_DMAD_SUPPLY_SINGLE_DMAD_WRITE REG_FLD(1, 22)
#define WED_WDMA_GLO_CFG_FLD_AXI_W_AFTER_AW_EN					REG_FLD(1, 21)
#define WED_WDMA_GLO_CFG_FLD_WAIT_COHERENT_EN					REG_FLD(1, 20)
#define WED_WDMA_GLO_CFG_FLD_FSM_RETURN_IDLE					REG_FLD(1, 19)
#define WED_WDMA_GLO_CFG_FLD_INIT_PHASE_BYPASS					REG_FLD(1, 18)
#define WED_WDMA_GLO_CFG_FLD_INIT_PHASE_ENABLING_RXDMA_BYPASS	REG_FLD(1, 17)
#define WED_WDMA_GLO_CFG_FLD_WCOMPLETE_SEL						REG_FLD(1, 16)
#define WED_WDMA_GLO_CFG_FLD_RX_DRV_DISABLE_FSM_AUTO_IDLE		REG_FLD(1, 13)
#define WED_WDMA_GLO_CFG_FLD_BIG_ENDIAN							REG_FLD(1, 7)
#define WED_WDMA_GLO_CFG_FLD_TX_WB_DDONE						REG_FLD(1, 6)
#define WED_WDMA_GLO_CFG_FLD_RX_DRV_BUSY						REG_FLD(1, 3)
#define WED_WDMA_GLO_CFG_FLD_RX_DRV_EN							REG_FLD(1, 2)
#define WED_WDMA_GLO_CFG_FLD_TX_DRV_EN							REG_FLD(1, 0)
#define WED_WDMA_GLO_CFG_FLD_WDMA_BT_SIZE						REG_FLD(2, 4)
#define WED_WDMA_GLO_CFG_FLD_WDMA_BT_SIZE_MASK					0x3


#define WED_WDMA_RST_IDX_FLD_CRX_IDX0							REG_FLD(1, 16)
#define WED_WDMA_RST_IDX_FLD_CRX_IDX1							REG_FLD(1, 17)
#define WED_WDMA_RST_IDX_FLD_DRV_IDX0							REG_FLD(1, 24)
#define WED_WDMA_RST_IDX_FLD_DRV_IDX1							REG_FLD(1, 25)

#define WED_WDMA_INT_TRIG_FLD_RX_DONE1							REG_FLD(1, 17)
#define WED_WDMA_INT_TRIG_FLD_RX_DONE0							REG_FLD(1, 16)

#define WED_WDMA_INT_CTRL_FLD_POLL_PRD							REG_FLD(8, 0)
#define WED_WDMA_INT_CTRL_FLD_POLL_EN							REG_FLD(1, 12)
#define WED_WDMA_INT_CTRL_FLD_POLL_SRC_SEL						REG_FLD(2, 16)
#define WED_WDMA_INT_CTRL_FLD_POLL_SRC_SEL_MASK					0x3


#define WED_WDMA_RX_THRES_CFG_FLD_WAIT_BM_CNT_MAX				REG_FLD(12, 0)
#define WED_WDMA_RX_THRES_CFG_FLD_DRX_CRX_DISTANCE_THRES		REG_FLD(12, 16)
#define WED_PCIE_INT_CTRL_FLD_POLL_PRD							REG_FLD(8, 0)
#define WED_PCIE_INT_CTRL_FLD_POLL_EN							REG_FLD(2, 12)
#define WED_PCIE_INT_CTRL_FLD_SRC_SEL							REG_FLD(2, 16)
#define WED_PCIE_INT_CTRL_FLD_MSK_EN_POLA						REG_FLD(1, 20)
#define WED_DBG_CTRL_FLD_TX_BM_MEM_DBG							REG_FLD(1, 28)
#define WED_DBG_CTRL_FLD_PRB_SEL								REG_FLD(1, 0)

#endif /*_WED_HW_*/
