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

	Module Name: wifi_offload
	woe_mt7915.h
*/
#ifndef _WOE_MT7915_H_
#define _WOE_MT7915_H_

#include "chip/mt7915_cr.h"
#include "token.h"
#include "mac/mac_mt/fmac/mt_fmac.h"

#define WPDMA_OFFSET 0xd7000

/*WFDMA EXT_CR*/
#define WIFI_TX_RING0_BASE	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX0_CTRL0_ADDR)
#define WIFI_TX_RING0_CNT	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX0_CTRL1_ADDR)
#define WIFI_TX_RING0_CIDX	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX0_CTRL2_ADDR)
#define WIFI_TX_RING0_DIDX	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX0_STS_ADDR)
#define WIFI_TX_RING1_BASE	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX1_CTRL0_ADDR)
#define WIFI_TX_RING1_CNT	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX1_CTRL1_ADDR)
#define WIFI_TX_RING1_CIDX	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX1_CTRL2_ADDR)
#define WIFI_TX_RING1_DIDX	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_TX1_STS_ADDR)

#define WIFI_RX_RING1_BASE	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_RX1_CTRL0_ADDR)
#define WIFI_RX_RING1_CNT	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_RX1_CTRL1_ADDR)
#define WIFI_RX_RING1_CIDX	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_RX1_CTRL2_ADDR)
#define WIFI_RX_RING1_DIDX	WF_WFDMA_EXT_WRAP_CSR_PCI_BASE(WF_WFDMA_EXT_WRAP_CSR_WED_RX1_STS_ADDR)

#define WIFI_HOST_DMA0_WPDMA_GLO_CFG WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_ADDR)
#define WIFI_RX_DATA_RING0_BASE WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL0_ADDR)
#define WIFI_RX_DATA_RING0_CNT WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL1_ADDR)
#define WIFI_RX_DATA_RING0_CIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL2_ADDR)
#define WIFI_RX_DATA_RING0_DIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL3_ADDR)
#define WIFI_RX_DATA_RING1_BASE WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING1_CTRL0_ADDR)
#define WIFI_RX_DATA_RING1_CNT WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING1_CTRL1_ADDR)
#define WIFI_RX_DATA_RING1_CIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING1_CTRL2_ADDR)
#define WIFI_RX_DATA_RING1_DIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING1_CTRL3_ADDR)

#define WIFI_INT_STA		MT_INT_SOURCE_CSR
#define WIFI_INT_MSK		MT_INT_MASK_CSR
#define WIFI_WPDMA_GLO_CFG	WF_WFDMA_HOST_DMA1_PCI_BASE(WF_WFDMA_HOST_DMA1_WPDMA_GLO_CFG_ADDR)
#define WIFI_WPDMA_GLO_CFG_FLD_TX_DMA_EN                    (0)
#define WIFI_WPDMA_GLO_CFG_FLD_TX_DMA_BUSY                  (1)
#define WIFI_WPDMA_GLO_CFG_FLD_RX_DMA_EN                    (2)
#define WIFI_WPDMA_GLO_CFG_FLD_RX_DMA_BUSY                  (3)
#define WIFI_WPDMA_RESET_PTR WF_WFDMA_HOST_DMA1_PCI_BASE(WF_WFDMA_HOST_DMA1_WPDMA_RST_DRX_PTR_ADDR)
#define WIFI_WPDMA_RESET_PTR_FLD_RST_DRX_IDX1				(17)
#define WIFI_WPDMA_RESET_PTR_FLD_RST_DTX_IDX0				(0)
#define WIFI_WPDMA_RESET_PTR_FLD_RST_DTX_IDX1				(1)


#ifdef ERR_RECOVERY
#define WIFI_MCU_INT_EVENT WF_WFDMA_MCU_DMA1_PCI_BASE(WF_WFDMA_MCU_DMA1_HOST2MCU_SW_INT_SET_ADDR)
#define WIFI_ERR_RECOV_STOP_IDLE	ERR_RECOV_STAGE_STOP_IDLE
#define WIFI_ERR_RECOV_STOP_PDMA0	ERR_RECOV_STAGE_STOP_PDMA0
#define WIFI_ERR_RECOV_RESET_PDMA0	ERR_RECOV_STAGE_RESET_PDMA0
#define WIFI_ERR_RECOV_STOP_IDLE_DONE ERR_RECOV_STAGE_STOP_IDLE_DONE
#define WIFI_TRIGGER_SER			MCU_INT_SER_TRIGGER_FROM_HOST
#endif

static inline void wifi_card_fbuf_init(unsigned char *fbuf, unsigned int pkt_pa, unsigned int tkid)
{
	struct txd_l *txd;
	CR4_TXP_MSDU_INFO *txp;

	txd = (struct txd_l *)fbuf;
	txp = (CR4_TXP_MSDU_INFO *)(fbuf+sizeof(struct txd_l));
	memset(txd, 0, sizeof(*txd));
	memset(txp, 0, sizeof(*txp));
	/*initial txd*/
	txd->txd_0 |= (sizeof(*txd) & TXD_TX_BYTE_COUNT_MASK) << TXD_TX_BYTE_COUNT_SHIFT;
	txd->txd_0 |= (FT_HIF_CTD << TXD_PKT_FT_SHIFT);
	txd->txd_1 |= (HF_802_3_FRAME << TXD_HF_SHIFT);
	txd->txd_1 |= TXD_FT;
	txd->txd_1 &=  ~(TXD_HDR_PAD_MASK);
	/*init txp*/
	txp->msdu_token = tkid;
	/*without TXD, CR4 will take care it*/
	txp->type_and_flags = 0;
	txp->buf_num = 1;
	txp->buf_ptr[0] = pkt_pa;
	txp->buf_len[0] = 0;
}


#endif /*_WOE_MT7915_H_*/
