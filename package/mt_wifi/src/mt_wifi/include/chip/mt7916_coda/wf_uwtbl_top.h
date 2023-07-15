//[File]            : wf_uwtbl_top.h
//[Revision time]   : Wed Dec 16 10:27:08 2020
//[Description]     : This file is auto generated by CODA
//[Copyright]       : Copyright (C) 2020 Mediatek Incorportion. All rights reserved.

#ifndef __WF_UWTBL_TOP_REGS_H__
#define __WF_UWTBL_TOP_REGS_H__

#include "hal_common.h"

#ifdef __cplusplus
extern "C" {
#endif


//****************************************************************************
//
//                     WF_UWTBL_TOP CR Definitions                     
//
//****************************************************************************

#define WF_UWTBL_TOP_BASE                                      0x820C4000

#define WF_UWTBL_TOP_KTVLBR0_ADDR                              (WF_UWTBL_TOP_BASE + 0x0000) // 4000
#define WF_UWTBL_TOP_UCR_ADDR                                  (WF_UWTBL_TOP_BASE + 0x0090) // 4090
#define WF_UWTBL_TOP_WDUCR_ADDR                                (WF_UWTBL_TOP_BASE + 0x0094) // 4094
#define WF_UWTBL_TOP_KTCR_ADDR                                 (WF_UWTBL_TOP_BASE + 0x0098) // 4098
#define WF_UWTBL_TOP_WIUCR_ADDR                                (WF_UWTBL_TOP_BASE + 0x00A0) // 40A0
#define WF_UWTBL_TOP_WMUDR_ADDR                                (WF_UWTBL_TOP_BASE + 0x00A4) // 40A4
#define WF_UWTBL_TOP_WMUMR_ADDR                                (WF_UWTBL_TOP_BASE + 0x00A8) // 40A8
#define WF_UWTBL_TOP_DFR_ADDR                                  (WF_UWTBL_TOP_BASE + 0x1FE0) // 5FE0
#define WF_UWTBL_TOP_DMY0_ADDR                                 (WF_UWTBL_TOP_BASE + 0x1FF0) // 5FF0
#define WF_UWTBL_TOP_DMY1_ADDR                                 (WF_UWTBL_TOP_BASE + 0x1FF4) // 5FF4




/* =====================================================================================

  ---KTVLBR0 (0x820C4000 + 0x0000)---

    VLB[31..0]                   - (RW) Valid Lookaside Buffer for key table
                                     Each bit is mapped to 1 entry in key table
                                     The max # = # of wlan_entry + (# of MBSS+ # of BSS) * (# of band)

 =====================================================================================*/
#define WF_UWTBL_TOP_KTVLBR0_VLB_ADDR                          WF_UWTBL_TOP_KTVLBR0_ADDR
#define WF_UWTBL_TOP_KTVLBR0_VLB_MASK                          0xFFFFFFFF                // VLB[31..0]
#define WF_UWTBL_TOP_KTVLBR0_VLB_SHFT                          0

/* =====================================================================================

  ---UCR (0x820C4000 + 0x0090)---

    PN_INCR_MODE[0]              - (RW) The condition of PN+1
    RESERVED1[15..1]             - (RO) Reserved bits
    MAX_BIPN_RANGE[31..16]       - (RW) Max BIPN range
                                     Replay check is checked by the following condition
                                     oldBIPN < newBIPN <= oldBIPN+ MAX_BIPN_RANGE

 =====================================================================================*/
#define WF_UWTBL_TOP_UCR_MAX_BIPN_RANGE_ADDR                   WF_UWTBL_TOP_UCR_ADDR
#define WF_UWTBL_TOP_UCR_MAX_BIPN_RANGE_MASK                   0xFFFF0000                // MAX_BIPN_RANGE[31..16]
#define WF_UWTBL_TOP_UCR_MAX_BIPN_RANGE_SHFT                   16
#define WF_UWTBL_TOP_UCR_PN_INCR_MODE_ADDR                     WF_UWTBL_TOP_UCR_ADDR
#define WF_UWTBL_TOP_UCR_PN_INCR_MODE_MASK                     0x00000001                // PN_INCR_MODE[0]
#define WF_UWTBL_TOP_UCR_PN_INCR_MODE_SHFT                     0

/* =====================================================================================

  ---WDUCR (0x820C4000 + 0x0094)---

    GROUP[3..0]                  - (RW) The selected group of key table/uwtbl
                                     128 entries for each group
    RESERVED4[30..4]             - (RO) Reserved bits
    TARGET[31]                   - (RW) select the target of table

 =====================================================================================*/
#define WF_UWTBL_TOP_WDUCR_TARGET_ADDR                         WF_UWTBL_TOP_WDUCR_ADDR
#define WF_UWTBL_TOP_WDUCR_TARGET_MASK                         0x80000000                // TARGET[31]
#define WF_UWTBL_TOP_WDUCR_TARGET_SHFT                         31
#define WF_UWTBL_TOP_WDUCR_GROUP_ADDR                          WF_UWTBL_TOP_WDUCR_ADDR
#define WF_UWTBL_TOP_WDUCR_GROUP_MASK                          0x0000000F                // GROUP[3..0]
#define WF_UWTBL_TOP_WDUCR_GROUP_SHFT                          0

/* =====================================================================================

  ---KTCR (0x820C4000 + 0x0098)---

    TARGET_IDX[10..0]            - (RW) Target index if write command of KTCR is performed
                                     if OPERATION = search, the free key entry is shown in this field
    RESERVED11[13..11]           - (RO) Reserved bits
    OPERATION[15..14]            - (RW) The operation if write command of KTCR is performed
    RESERVED16[29..16]           - (RO) Reserved bits
    REASON[31..30]               - (RO) The reason code for the operation of KTCR

 =====================================================================================*/
#define WF_UWTBL_TOP_KTCR_REASON_ADDR                          WF_UWTBL_TOP_KTCR_ADDR
#define WF_UWTBL_TOP_KTCR_REASON_MASK                          0xC0000000                // REASON[31..30]
#define WF_UWTBL_TOP_KTCR_REASON_SHFT                          30
#define WF_UWTBL_TOP_KTCR_OPERATION_ADDR                       WF_UWTBL_TOP_KTCR_ADDR
#define WF_UWTBL_TOP_KTCR_OPERATION_MASK                       0x0000C000                // OPERATION[15..14]
#define WF_UWTBL_TOP_KTCR_OPERATION_SHFT                       14
#define WF_UWTBL_TOP_KTCR_TARGET_IDX_ADDR                      WF_UWTBL_TOP_KTCR_ADDR
#define WF_UWTBL_TOP_KTCR_TARGET_IDX_MASK                      0x000007FF                // TARGET_IDX[10..0]
#define WF_UWTBL_TOP_KTCR_TARGET_IDX_SHFT                      0

/* =====================================================================================

  ---WIUCR (0x820C4000 + 0x00A0)---

    WLAN_IDX[9..0]               - (RW) Target for clearing or updating
    RESERVED10[17..10]           - (RO) Reserved bits
    PNSN_CLEAR[18]               - (W1) Clear PN/SN* to 0
    RESERVED19[19]               - (RO) Reserved bits
    MASK_UPDATE[20]              - (W1) Mask Update
                                     WTBL loads target wlan_idx & dw and update the target field by WMUDR & WMUMR
    RESERVED21[23..21]           - (RO) Reserved bits
    DW[27..24]                   - (RW) Target double word
    RESERVED28[30..28]           - (RO) Reserved bits
    IU_BUSY[31]                  - (RO) Indirect update status
                                     HW will set up this bit when it is updating WTBL.

 =====================================================================================*/
#define WF_UWTBL_TOP_WIUCR_IU_BUSY_ADDR                        WF_UWTBL_TOP_WIUCR_ADDR
#define WF_UWTBL_TOP_WIUCR_IU_BUSY_MASK                        0x80000000                // IU_BUSY[31]
#define WF_UWTBL_TOP_WIUCR_IU_BUSY_SHFT                        31
#define WF_UWTBL_TOP_WIUCR_DW_ADDR                             WF_UWTBL_TOP_WIUCR_ADDR
#define WF_UWTBL_TOP_WIUCR_DW_MASK                             0x0F000000                // DW[27..24]
#define WF_UWTBL_TOP_WIUCR_DW_SHFT                             24
#define WF_UWTBL_TOP_WIUCR_MASK_UPDATE_ADDR                    WF_UWTBL_TOP_WIUCR_ADDR
#define WF_UWTBL_TOP_WIUCR_MASK_UPDATE_MASK                    0x00100000                // MASK_UPDATE[20]
#define WF_UWTBL_TOP_WIUCR_MASK_UPDATE_SHFT                    20
#define WF_UWTBL_TOP_WIUCR_PNSN_CLEAR_ADDR                     WF_UWTBL_TOP_WIUCR_ADDR
#define WF_UWTBL_TOP_WIUCR_PNSN_CLEAR_MASK                     0x00040000                // PNSN_CLEAR[18]
#define WF_UWTBL_TOP_WIUCR_PNSN_CLEAR_SHFT                     18
#define WF_UWTBL_TOP_WIUCR_WLAN_IDX_ADDR                       WF_UWTBL_TOP_WIUCR_ADDR
#define WF_UWTBL_TOP_WIUCR_WLAN_IDX_MASK                       0x000003FF                // WLAN_IDX[9..0]
#define WF_UWTBL_TOP_WIUCR_WLAN_IDX_SHFT                       0

/* =====================================================================================

  ---WMUDR (0x820C4000 + 0x00A4)---

    UPDATE_DATA[31..0]           - (RW) Data to update wlan entry

 =====================================================================================*/
#define WF_UWTBL_TOP_WMUDR_UPDATE_DATA_ADDR                    WF_UWTBL_TOP_WMUDR_ADDR
#define WF_UWTBL_TOP_WMUDR_UPDATE_DATA_MASK                    0xFFFFFFFF                // UPDATE_DATA[31..0]
#define WF_UWTBL_TOP_WMUDR_UPDATE_DATA_SHFT                    0

/* =====================================================================================

  ---WMUMR (0x820C4000 + 0x00A8)---

    UPDATE_MASK[31..0]           - (RW) Mask of data to update wlan entry

 =====================================================================================*/
#define WF_UWTBL_TOP_WMUMR_UPDATE_MASK_ADDR                    WF_UWTBL_TOP_WMUMR_ADDR
#define WF_UWTBL_TOP_WMUMR_UPDATE_MASK_MASK                    0xFFFFFFFF                // UPDATE_MASK[31..0]
#define WF_UWTBL_TOP_WMUMR_UPDATE_MASK_SHFT                    0

/* =====================================================================================

  ---DFR (0x820C4000 + 0x1FE0)---

    DEBUG_FSM[31..0]             - (RO) debug fsm

 =====================================================================================*/
#define WF_UWTBL_TOP_DFR_DEBUG_FSM_ADDR                        WF_UWTBL_TOP_DFR_ADDR
#define WF_UWTBL_TOP_DFR_DEBUG_FSM_MASK                        0xFFFFFFFF                // DEBUG_FSM[31..0]
#define WF_UWTBL_TOP_DFR_DEBUG_FSM_SHFT                        0

/* =====================================================================================

  ---DMY0 (0x820C4000 + 0x1FF0)---

    DMY0[31..0]                  - (RW) Dummy Register with default value 0 for ECO purpose

 =====================================================================================*/
#define WF_UWTBL_TOP_DMY0_DMY0_ADDR                            WF_UWTBL_TOP_DMY0_ADDR
#define WF_UWTBL_TOP_DMY0_DMY0_MASK                            0xFFFFFFFF                // DMY0[31..0]
#define WF_UWTBL_TOP_DMY0_DMY0_SHFT                            0

/* =====================================================================================

  ---DMY1 (0x820C4000 + 0x1FF4)---

    DMY1[31..0]                  - (RW) Dummy Register with default value 1 for ECO purpose

 =====================================================================================*/
#define WF_UWTBL_TOP_DMY1_DMY1_ADDR                            WF_UWTBL_TOP_DMY1_ADDR
#define WF_UWTBL_TOP_DMY1_DMY1_MASK                            0xFFFFFFFF                // DMY1[31..0]
#define WF_UWTBL_TOP_DMY1_DMY1_SHFT                            0

#ifdef __cplusplus
}
#endif

#endif // __WF_UWTBL_TOP_REGS_H__
