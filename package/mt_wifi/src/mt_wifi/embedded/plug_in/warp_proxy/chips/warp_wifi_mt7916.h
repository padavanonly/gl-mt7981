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
	warp_wifi_mt7916.h
*/
#ifndef _WARP_WIFI_MT7916_H_
#define _WARP_WIFI_MT7916_H_

#include <rt_config.h>
#include <rtmp_comm.h>
#include <rt_os_util.h>
#include <rt_os_net.h>
#include <hdev/hdev_basic.h>
#include <os/rt_linux_txrx_hook.h>

#include <wifi_sys_notify.h>
#include <mcu/andes_core.h>
#include <mcu/mt_cmd.h>

#include "chip/mt7916_cr.h"
#include "token.h"
#include "mac/mac_mt/fmac/mt_fmac.h"

#define WPDMA_OFFSET 0xd7000

#ifdef ERR_RECOVERY
#define WIFI_MCU_INT_EVENT WF_WFDMA_MCU_DMA0_PCI_BASE(WF_WFDMA_MCU_DMA0_HOST2MCU_SW_INT_SET_ADDR)
#define WIFI_ERR_RECOV_STOP_IDLE	ERR_RECOV_STAGE_STOP_IDLE
#define WIFI_ERR_RECOV_STOP_PDMA0	ERR_RECOV_STAGE_STOP_PDMA0
#define WIFI_ERR_RECOV_RESET_PDMA0	ERR_RECOV_STAGE_RESET_PDMA0
#define WIFI_ERR_RECOV_STOP_IDLE_DONE ERR_RECOV_STAGE_STOP_IDLE_DONE
#define WIFI_TRIGGER_SER			MCU_INT_SER_TRIGGER_FROM_HOST
#endif

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

#define WIFI_RX_DATA_RING0_BASE WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING4_CTRL0_ADDR)
#define WIFI_RX_DATA_RING0_CNT WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING4_CTRL1_ADDR)
#define WIFI_RX_DATA_RING0_CIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING4_CTRL2_ADDR)
#define WIFI_RX_DATA_RING0_DIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING4_CTRL3_ADDR)
#define WIFI_RX_DATA_RING1_BASE WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING5_CTRL0_ADDR)
#define WIFI_RX_DATA_RING1_CNT WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING5_CTRL1_ADDR)
#define WIFI_RX_DATA_RING1_CIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING5_CTRL2_ADDR)
#define WIFI_RX_DATA_RING1_DIDX WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RX_RING5_CTRL3_ADDR)

#define WIFI_HOST_DMA0_WPDMA_GLO_CFG WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_ADDR)

#define WIFI_INT_STA		MT_INT_SOURCE_CSR
#define WIFI_INT_MSK		MT_INT_MASK_CSR
#define WIFI_WPDMA_GLO_CFG	WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_ADDR)
#define WIFI_WPDMA_GLO_CFG_FLD_TX_DMA_EN                    (0)
#define WIFI_WPDMA_GLO_CFG_FLD_TX_DMA_BUSY                  (1)
#define WIFI_WPDMA_GLO_CFG_FLD_RX_DMA_EN                    (2)
#define WIFI_WPDMA_GLO_CFG_FLD_RX_DMA_BUSY                  (3)
#define WIFI_WPDMA_RESET_PTR WF_WFDMA_HOST_DMA0_PCI_BASE(WF_WFDMA_HOST_DMA0_WPDMA_RST_DRX_PTR_ADDR)
#define WIFI_WPDMA_RESET_PTR_FLD_RST_DRX_IDX1				(17)
#define WIFI_WPDMA_RESET_PTR_FLD_RST_DTX_IDX0				(0)
#define WIFI_WPDMA_RESET_PTR_FLD_RST_DTX_IDX1				(1)


#endif /*_WARP_WIFI_MT7916_H_*/
