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

#ifndef __MTK_VENDOR_NL80211_H
#define __MTK_VENDOR_NL80211_H
/*
 * This header file defines the userspace API to the wireless stack. Please
 * be careful not to break things - i.e. don't move anything around or so
 * unless you can demonstrate that it breaks neither API nor ABI.
 *
 */

#include <linux/types.h>

#ifndef GNU_PACKED
#define GNU_PACKED  __attribute__ ((packed))
#endif /* GNU_PACKED */

#define MTK_NL80211_VENDOR_ID	0x0ce7

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

/**
 * enum mtk_nl80211_vendor_commands - supported mtk nl80211 vendor commands
 *
 * @MTK_NL80211_VENDOR_SUBCMD_UNSPEC: Reserved value 0
 * @MTK_NL80211_VENDOR_SUBCMD_TEST: Test for nl80211command/event
 * @MTK_NL80211_VENDOR_SUBCMD_AMNT_CTRL = 0x000000ae:
 * @MTK_NL80211_VENDOR_SUBCMD_CSI_CTRL = 0x000000c2:
 * @MTK_NL80211_VENDOR_SUBCMD_AP_RFEATURE: command to set radio information
 * @MTK_NL80211_VENDOR_SUBCMD_AP_WIRELESS: command to set wireless information
 * @MTK_NL80211_VENDOR_SUBCMD_SET_DOT11V_WNM:
 * @MTK_NL80211_VENDOR_SUBCMD_GET_CAP: command to get capability information
 *  from wifi driver, it requres mtk_nl80211_vendor_attr_get_cap attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_GET_RUNTIME_INFO: command to get run time information
 *  from wifi driver, it requres mtk_nl80211_vendor_attr_get_runtime_info attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_GET_STATISTIC: command to get statistic information
 *  from wifi driver, it requres mtk_nl80211_vendor_attr_get_static_info attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_GET_STATIC_INFO:
 * @MTK_NL80211_VENDOR_SUBCMD_MAC: command to set or get mac register
 *  information to/from wifi driver, require mtk_nl80211_vendor_attrs_mac
 *  attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_STATISTICS: command to get statistic information
 *  in string from wifi driver, this command is used to be compatible with
 *  old iwpriv stat command, it requres mtk_nl80211_vendor_attrs_statistics
 *  attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_VENDOR_SET: command to set old iwpriv set command
 *  string to wifi driver, it requires mtk_nl80211_vendor_attrs_vendor_set attributes,
 *  please note that this command is just used to be compatible with old iwpriv
 *  set command, and it will be discarded in some time.
 * @MTK_NL80211_VENDOR_SUBCMD_VENDOR_SHOW: command to set old iwpriv show command
 *  string to wifi driver, require mtk_nl80211_vendor_attrs_vendor_show attributes,
 *  please note that this command is just used to be compatible with old iwpriv
 *  show command, and it will be discarded in some time.
 * @MTK_NL80211_VENDOR_SUBCMD_WAPP_REQ: command to set or get wapp requred
 *  information from wifi driver, require mtk_nl80211_vendor_attr_wapp_req attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_AP_SECURITY: command to set ap security configurations
 *  to a specific bss in wifi driver, it requires mtk_nl80211_vendor_attrs_ap_security
 *  attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_AP_VOW:  command to set ap vow configurations
 *  it requires mtk_nl80211_vendor_attrs_ap_vow attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_MWDS: command to set ap/apcli MWDS configuration
 *  it requeris mtk_nl80211_vendor_attrs_mwds_set attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_AP_BSS:  command to set ap bss configurations
 *  it requires mtk_nl80211_vendor_attrs_ap_bss attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_AP_RADIO: command to set ap phy or global configurations
 *  it requires mtk_nl80211_vendor_attrs_ap_radio attributes.
 * @MTK_NL80211_VENDOR_CMD_MAX: highest used command number
 * @__MTK_NL80211_VENDOR_CMD_AFTER_LAST: internal use
 * @MTK_NL80211_VENDOR_SUBCMD_SET_WMM:  command to set wmm configurations
 *  it requires mtk_nl80211_vendor_attrs_wmm attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_FT: command to set ft configurations
 *  it requires mtk_nl80211_vendor_attrs_ft attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_ACTION:  command to set action
 *  it requires mtk_nl80211_vendor_attrs_set_action attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_QOS:  command used by QoS
 *  it requires mtk_nl80211_vendor_attrs_qos attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_OFFCHANNEL_INFO: command to set offchannel_info
 *  it requires mtk_nl80211_vendor_attrs_offchannel_info attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_DFS:  command used by DFS
 *  it requires mtk_nl80211_vendor_attrs_dfs attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_EASYMESH:  command used by Easymesh
 *  it requires mtk_nl80211_vendor_attr_easymesh attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_AP_MONITOR:  command to set ap monitor
 *  it requires mtk_nl80211_vendor_attrs_ap_monitor attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_VLAN:  command to set vlan configurations
 *  it requires mtk_nl80211_vendor_attrs_vlan attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_BA:  command to set block ack configurations
 *  it requires mtk_nl80211_vendor_attrs_ap_ba attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_MLO_PRESET_LINK(0xe3): command to preset the mlo linkid
 *  it requires mtk_nl80211_vendor_attrs_mlo_preset_link attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_TXPOWER: command to set tx power configurations.
 *  it requires mtk_nl80211_vendor_attrs_tx_power attributes
 * @MTK_NL80211_VENDOR_SUBCMD_SET_EDCA: command to set tx burst configurations.
 *  it requires mtk_nl80211_vendor_attrs_edca attribures
 * @MTK_NL80211_VENDOR_SUBCMD_SET_MULTICAST_SNOOPING: command to set AP multicast
 *  snooping related configurations, it requires mtk_nl80211_vendor_attrs_mcast_snoop attributes
 * @MTK_NL80211_VENDOR_SUBCMD_GET_RADIO_STATS: command to get per radio stats,
 *  it requires MTK_NL80211_VENDOR_ATTR_RADIO_STATS attributes
 * @MTK_NL80211_VENDOR_SUBCMD_GET_SSID_STATS: command to get  per BSS stats
 *  it requires MTK_NL80211_VENDOR_ATTR_SSID_STATS attributes
 * @MTK_NL80211_VENDOR_SUBCMD_GET_STA: command to get STA's information and stats
 *  it requires MTK_NL80211_VENDOR_ATTR_STA attributes
 * @MTK_NL80211_VENDOR_SUBCMD_SET_MBO: command to set STA's Non preferred channel information
 *  it requires MTK_NL80211_VENDOR_ATTR_SET_MBO_NPC attributes
 * @MTK_NL80211_VENDOR_SUBCMD_HQA: command to forward qatool hqa cmd to set/get
 *  it requires MTK_NL80211_VENDOR_ATTR_HQA attributes
 * @MTK_NL80211_VENDOR_SUBCMD_SET_MLO_IE: command to set MLO IE configurations
 *  it requires mtk_nl80211_vendor_attrs_mlo_ie attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_PMKID: command to set PMKID configurations
 *  it requires mtk_nl80211_vendor_attrs_pmkid attributes.
 * @MTK_NL80211_VENDOR_SUBCMD_SET_V10CONVERTER: command to set v10converter
 *  it requires mtk_nl80211_vendor_attr_v10convertor attributes
 * @MTK_NL80211_VENDOR_SUBCMD_SET_APPROXYREFRESH: command to set v10converter
 *  it requires mtk_nl80211_vendor_attr_apropxyrefresh attributes
 */
enum mtk_nl80211_vendor_commands {
	MTK_NL80211_VENDOR_SUBCMD_UNSPEC = 0,
	MTK_NL80211_VENDOR_SUBCMD_TEST = 1,

/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_SUBCMD_AMNT_CTRL = 0x000000ae,
	MTK_NL80211_VENDOR_SUBCMD_CSI_CTRL = 0x000000c2,
	MTK_NL80211_VENDOR_SUBCMD_AP_RFEATURE,
	MTK_NL80211_VENDOR_SUBCMD_AP_WIRELESS,
	MTK_NL80211_VENDOR_SUBCMD_SET_DOT11V_WNM,
	MTK_NL80211_VENDOR_SUBCMD_GET_CAP,
	MTK_NL80211_VENDOR_SUBCMD_GET_RUNTIME_INFO,
	MTK_NL80211_VENDOR_SUBCMD_GET_STATISTIC,
	MTK_NL80211_VENDOR_SUBCMD_GET_STATIC_INFO,
	MTK_NL80211_VENDOR_SUBCMD_MAC,
	MTK_NL80211_VENDOR_SUBCMD_STATISTICS,
	MTK_NL80211_VENDOR_SUBCMD_VENDOR_SET,
	MTK_NL80211_VENDOR_SUBCMD_VENDOR_SHOW,
	MTK_NL80211_VENDOR_SUBCMD_WAPP_REQ,
	MTK_NL80211_VENDOR_SUBCMD_SET_AP_SECURITY,
	MTK_NL80211_VENDOR_SUBCMD_SET_AP_VOW,
	MTK_NL80211_VENDOR_SUBCMD_SET_MWDS,
	MTK_NL80211_VENDOR_SUBCMD_SET_COUNTRY,
	MTK_NL80211_VENDOR_SUBCMD_SET_CHANNEL,
	MTK_NL80211_VENDOR_SUBCMD_SET_AUTO_CH_SEL,
	MTK_NL80211_VENDOR_SUBCMD_SET_SCAN,
	MTK_NL80211_VENDOR_SUBCMD_SET_ACL,
	MTK_NL80211_VENDOR_SUBCMD_SET_AP_BSS,
	MTK_NL80211_VENDOR_SUBCMD_SET_AP_RADIO,
	MTK_NL80211_VENDOR_SUBCMD_SET_WMM,
	MTK_NL80211_VENDOR_SUBCMD_SET_FT,
	MTK_NL80211_VENDOR_SUBCMD_SET_ACTION,
	MTK_NL80211_VENDOR_SUBCMD_QOS,
	MTK_NL80211_VENDOR_SUBCMD_OFFCHANNEL_INFO,
	MTK_NL80211_VENDOR_SUBCMD_DFS,
	MTK_NL80211_VENDOR_SUBCMD_EASYMESH,
	MTK_NL80211_VENDOR_SUBCMD_SET_AP_MONITOR,
	MTK_NL80211_VENDOR_SUBCMD_SET_VLAN,
	MTK_NL80211_VENDOR_SUBCMD_SET_BA,
	MTK_NL80211_VENDOR_SUBCMD_SET_MLO_PRESET_LINK,
	MTK_NL80211_VENDOR_SUBCMD_SET_TXPOWER,
	MTK_NL80211_VENDOR_SUBCMD_SET_EDCA,
	MTK_NL80211_VENDOR_SUBCMD_SET_MULTICAST_SNOOPING,
	MTK_NL80211_VENDOR_SUBCMD_GET_RADIO_STATS,
	MTK_NL80211_VENDOR_SUBCMD_GET_BSS_STATS,
	MTK_NL80211_VENDOR_SUBCMD_GET_STA,
	MTK_NL80211_VENDOR_SUBCMD_SET_MBO,
	MTK_NL80211_VENDOR_SUBCMD_HQA,
	MTK_NL80211_VENDOR_SUBCMD_SET_ATE,
	MTK_NL80211_VENDOR_SUBCMD_SET_MLO_IE,
	MTK_NL80211_VENDOR_SUBCMD_SET_PMKID,
	MTK_NL80211_VENDOR_SUBCMD_SET_V10CONVERTER,
	MTK_NL80211_VENDOR_SUBCMD_SET_APPROXYREFRESH,
	/* add new commands above here */

	/* used to define NL80211_CMD_MAX below */
	__MTK_NL80211_VENDOR_CMD_AFTER_LAST,
	MTK_NL80211_VENDOR_CMD_MAX = __MTK_NL80211_VENDOR_CMD_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_ssid_stats - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_GET_RADIO_STATS.
 * Information in these attributes is used to get per BSS stats
 * and counters.
 *
 * @MTK_NL80211_VENDOR_ATTR_RADIO_STATS: per radio stats, struct wifi_radio_stats.
 */
enum mtk_nl80211_vendor_attrs_radio_stats {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_RADIO_STATS_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_RADIO_STATS,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_RADIO_STATS_LAST,
	MTK_NL80211_VENDOR_ATTR_RADIO_STATS_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_RADIO_STATS_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_ssid_stats - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_GET_SSID_STATS.
 * Information in these attributes is used to get per BSS stats
 * and counters.
 *
 * @MTK_NL80211_VENDOR_ATTR_SSID_STATS: per BSS stats, struct wifi_bss_stats.
 */
enum mtk_nl80211_vendor_attrs_bss_stats {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_BSS_STATS_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_BSS_STATS,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_BSS_STATS_LAST,
	MTK_NL80211_VENDOR_ATTR_BSS_STATS_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_BSS_STATS_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_sta - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_GET_STA.
 * Information in these attributes is used to get STA information
 * and counters.
 *
 * @MTK_NL80211_VENDOR_ATTR_STA: STA's information and counters, struct wifi_station.
 */
enum mtk_nl80211_vendor_attrs_sta {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_STA_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_STA,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_STA_LAST,
	MTK_NL80211_VENDOR_ATTR_STA_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_STA_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_events - MediaTek nl80211 asynchoronous event identifiers
 *
 * @MTK_NL80211_VENDOR_EVENT_UNSPEC: Reserved value 0
 *
 * @MTK_NL80211_VENDOR_EVENT_TEST: Test for nl80211command/event
 *  it requires mtk_nl80211_vendor_attr_test attributes.
 * @MTK_NL80211_VENDOR_EVENT_RSP_WAPP_EVENT: command used by wapp event
 *  it requires mtk_nl80211_vendor_attr_event_rsp_wapp_event attributes.
 * @MTK_NL80211_VENDOR_EVENT_OFFCHANNEL_INFO: command by Easymesh
 *  it requires mtk_nl80211_vendor_attr_event_offchannel_info attributes.
 * @MTK_NL80211_VENDOR_EVENT_SEND_ML_INFO: command used by wifi7 multilink operation
 *  it requires mtk_nl80211_vendor_attr_event_send_ml_info attributes.
 * @MTK_NL80211_VENDOR_EVENT_MLO_EVENT: command by uplayer app such as supplicant
 *  it requires NL80211_ATTR_VENDOR_DATA attributes.
 * @MTK_NL80211_VENDOR_EVENT_STA_PROFILE_EVENT：event used by hostapd to get per-STA
 *  profile for MLO FT
 */
enum mtk_nl80211_vendor_events {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_EVENT_UNSPEC = 0,
	MTK_NL80211_VENDOR_EVENT_TEST,

	MTK_NL80211_VENDOR_EVENT_RSP_WAPP_EVENT,
	MTK_NL80211_VENDOR_EVENT_OFFCHANNEL_INFO,
	MTK_NL80211_VENDOR_EVENT_SEND_ML_INFO,
	MTK_NL80211_VENDOR_EVENT_MLO_EVENT,
	MTK_NL80211_VENDOR_EVENT_STA_PROFILE_EVENT,

	/* add new events above here */
	/* used to define NL80211_EVENT_MAX below */
	__MTK_NL80211_VENDOR_EVENT_AFTER_LAST,
	MTK_NL80211_VENDOR_EVENT_MAX = __MTK_NL80211_VENDOR_EVENT_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_test - Specifies the values for vendor test
 * command MTK_NL80211_VENDOR_ATTR_TEST
 * @MTK_NL80211_VENDOR_ATTR_TEST：enable nl80211 test
 */
enum mtk_nl80211_vendor_attr_test {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_TEST_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_TEST,

	__MTK_NL80211_VENDOR_ATTR_TEST_LAST,
	MTK_NL80211_VENDOR_ATTR_TEST_MAX =
	__MTK_NL80211_VENDOR_ATTR_TEST_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_event_test - Specifies the values for vendor test
 * event MTK_NL80211_VENDOR_ATTR_TEST
 * @MTK_NL80211_VENDOR_ATTR_TEST：receive nl80211 test event
 */
enum mtk_nl80211_vendor_attr_event_test {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_EVENT_TEST_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_EVENT_TEST,

	__MTK_NL80211_VENDOR_ATTR_EVENT_TEST_LAST,
	MTK_NL80211_VENDOR_ATTR_EVENT_TEST_MAX =
	__MTK_NL80211_VENDOR_ATTR_EVENT_TEST_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_wnm - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_DOT11V_WNM.
 * Information in these attributes is used to set/get wnm information
 * to/from driver from/to user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_WNM_CMD:
 * @MTK_NL80211_VENDOR_ATTR_WNM_BTM_REQ: BTM request frame
 * @MTK_NL80211_VENDOR_ATTR_WNM_BTM_RSP:
 */
enum mtk_nl80211_vendor_attrs_dot11v_wnm {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_DOT11V_WNM_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_DOT11V_WNM_CMD,
	MTK_NL80211_VENDOR_ATTR_DOT11V_WNM_BTM_REQ,
	MTK_NL80211_VENDOR_ATTR_DOT11V_WNM_BTM_RSP,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_DOT11V_WNM_AFTER_LAST,
	MTK_NL80211_VENDOR_DOT11V_WNM_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_DOT11V_WNM_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_vendor_set - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_VENDOR_SET.
 * Information in these attributes is used to set information
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_VENDOR_SET_CMD_STR: command string
 */
enum mtk_nl80211_vendor_attrs_vendor_set {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_VENDOR_SET_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_VENDOR_SET_CMD_STR,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_VENDOR_SET_AFTER_LAST,
	MTK_NL80211_VENDOR_ATTR_VENDOR_SET_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_VENDOR_SET_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_vendor_show - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_VENDOR_SHOW.
 * Information in these attributes is used to get information
 * from driver to user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_CMD_STR: command string
 * @MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_RSP_STR: show rsp string buffer
 */
enum mtk_nl80211_vendor_attrs_vendor_show {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_CMD_STR,
	MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_RSP_STR,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_AFTER_LAST,
	MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_VENDOR_SHOW_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_statistics - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_STATISTICS.
 * Information in these attributes is used to get wnm information
 * to/from driver from/to user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_STATISTICS_STR: statistic information string
 */
enum mtk_nl80211_vendor_attrs_statistics {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_STATISTICS_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_STATISTICS_STR,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_STATISTICS_AFTER_LAST,
	MTK_NL80211_VENDOR_ATTR_STATISTICS_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_STATISTICS_AFTER_LAST - 1
};

/**
 * structure mac_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_MAC_WRITE_PARAM and MTK_NL80211_VENDOR_ATTR_MAC_SHOW_PARAM.
 * Information in this structure is used to get/set mac register information
 * from/to driver.
 *
 * @start: start mac address
 * @end: end mac address
 * @value: value for the mac register
 */
struct GNU_PACKED mac_param {
	unsigned int start;
	unsigned int end;
	unsigned int value;
};

/**
 * enum mtk_nl80211_vendor_attrs_mac - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_MAC.
 * Information in these attributes is used to get/set mac information
 * from/to driver.
 *
 * @MTK_NL80211_VENDOR_ATTR_MAC_WRITE_PARAM: params, refer to struct GNU_PACKED mac_param
 * @MTK_NL80211_VENDOR_ATTR_MAC_SHOW_PARAM: params, refer to struct GNU_PACKED mac_param
 * @MTK_NL80211_VENDOR_ATTR_MAC_RSP_STR: RSP string
 */
enum mtk_nl80211_vendor_attrs_mac {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_MAC_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_MAC_WRITE_PARAM,
	MTK_NL80211_VENDOR_ATTR_MAC_SHOW_PARAM,
	MTK_NL80211_VENDOR_ATTR_MAC_RSP_STR,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_MAC_AFTER_LAST,
	MTK_NL80211_VENDOR_ATTR_MAC_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_MAC_AFTER_LAST - 1
};

/**
 * enum mtk_vendor_attr_authmode - This enum defines the value of
 * MTK_NL80211_VENDOR_ATTR_AP_SECURITY_AUTHMODE.
 * Information in these attributes is used set auth mode of a specific bss.
 */
enum mtk_vendor_attr_authmode {
	NL80211_AUTH_OPEN,
	NL80211_AUTH_SHARED,
	NL80211_AUTH_WEPAUTO,
	NL80211_AUTH_WPA,
	NL80211_AUTH_WPAPSK,
	NL80211_AUTH_WPANONE,
	NL80211_AUTH_WPA2,
	NL80211_AUTH_WPA2MIX,
	NL80211_AUTH_WPA2PSK,
	NL80211_AUTH_WPA3,
	NL80211_AUTH_WPA3_192,
	NL80211_AUTH_WPA3PSK,
	NL80211_AUTH_WPA2PSKWPA3PSK,
	NL80211_AUTH_WPA2PSKMIXWPA3PSK,
	NL80211_AUTH_WPA1WPA2,
	NL80211_AUTH_WPAPSKWPA2PSK,
	NL80211_AUTH_WPA_AES_WPA2_TKIPAES,
	NL80211_AUTH_WPA_AES_WPA2_TKIP,
	NL80211_AUTH_WPA_TKIP_WPA2_AES,
	NL80211_AUTH_WPA_TKIP_WPA2_TKIPAES,
	NL80211_AUTH_WPA_TKIPAES_WPA2_AES,
	NL80211_AUTH_WPA_TKIPAES_WPA2_TKIPAES,
	NL80211_AUTH_WPA_TKIPAES_WPA2_TKIP,
	NL80211_AUTH_OWE,
	NL80211_AUTH_FILS_SHA256,
	NL80211_AUTH_FILS_SHA384,
	NL80211_AUTH_WAICERT,
	NL80211_AUTH_WAIPSK,
	NL80211_AUTH_DPP,
	NL80211_AUTH_DPPWPA2PSK,
	NL80211_AUTH_DPPWPA3PSK,
	NL80211_AUTH_DPPWPA3PSKWPA2PSK,
	NL80211_AUTH_WPA2_ENT_OSEN
};

/**
 * enum mtk_vendor_attr_encryptype - This enum defines the value of
 * MTK_NL80211_VENDOR_ATTR_AP_SECURITY_ENCRYPTYPE.
 * Information in these attributes is used set encryption type of a specific bss.
 */
enum mtk_vendor_attr_encryptype {
	NL80211_ENCRYPTYPE_NONE,
	NL80211_ENCRYPTYPE_WEP,
	NL80211_ENCRYPTYPE_TKIP,
	NL80211_ENCRYPTYPE_AES,
	NL80211_ENCRYPTYPE_CCMP128,
	NL80211_ENCRYPTYPE_CCMP256,
	NL80211_ENCRYPTYPE_GCMP128,
	NL80211_ENCRYPTYPE_GCMP256,
	NL80211_ENCRYPTYPE_TKIPAES,
	NL80211_ENCRYPTYPE_TKIPCCMP128,
	NL80211_ENCRYPTYPE_WPA_AES_WPA2_TKIPAES,
	NL80211_ENCRYPTYPE_WPA_AES_WPA2_TKIP,
	NL80211_ENCRYPTYPE_WPA_TKIP_WPA2_AES,
	NL80211_ENCRYPTYPE_WPA_TKIP_WPA2_TKIPAES,
	NL80211_ENCRYPTYPE_WPA_TKIPAES_WPA2_AES,
	NL80211_ENCRYPTYPE_WPA_TKIPAES_WPA2_TKIPAES,
	NL80211_ENCRYPTYPE_WPA_TKIPAES_WPA2_TKIP,
	NL80211_ENCRYPTYPE_SMS4
};

#define MAX_WEP_KEY_LEN 32
/**
 * structure wep_key_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_AP_SECURITY_WEPKEY. Information in this structure
 * is used to set wep key information to a specific bss in wifi driver.
 *
 * @key_idx: key index
 * @key_len: key length
 * @key: key value
 */
struct GNU_PACKED wep_key_param {
	unsigned char key_idx;
	unsigned int key_len;
	unsigned char key[MAX_WEP_KEY_LEN];
};

/**
 * structure vow_group_en_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_AP_VOW_ATC_EN_INFO &
 * MTK_NL80211_VENDOR_ATTR_AP_VOW_BW_CTL_EN_INFO.
 * Information in this structure is used to set vow airtime control enable configuration
 * to a specific group in wifi driver.
 *
 * @group: vow group
 * @en: Enable/Disable
 */
struct GNU_PACKED vow_group_en_param {
	unsigned int group;
	unsigned int en;
};

/**
 * structure vow_group_en_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_AP_VOW_MIN_RATE_INFO &
 * MTK_NL80211_VENDOR_ATTR_AP_VOW_MAX_RATE_INFO.
 * Information in this structure is used to set vow airtime rate configuration
 * to a specific group in wifi driver.
 *
 * @group: vow group
 * @rate: vow rate
 */
struct GNU_PACKED vow_rate_param {
	unsigned int group;
	unsigned int rate;
};

/**
 * structure vow_group_en_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_AP_VOW_MIN_RATIO_INFO &
 * MTK_NL80211_VENDOR_ATTR_AP_VOW_MAX_RATIO_INFO.
 * Information in this structure is used to set vow airtime ratio configuration
 * to a specific group in wifi driver.
 *
 * @group: vow group
 * @ratio: vow ratio
 */
struct GNU_PACKED vow_ratio_param {
	unsigned int group;
	unsigned int ratio;
};

/**
 * structure vlan_policy_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_VLAN_POLICY_INFO.
 * Information in this structure is used to set vlan policy configuration
 * to a specific group in wifi driver.
 *
 * @direction: vlan direction
 * @policy: vlan policy
 */
struct GNU_PACKED vlan_policy_param {
	unsigned int direction;
	unsigned int policy;
};

/**
 * structure ap_11r_params - This structure defines the payload format of
 * MTK_NL80211_VENDOR_SUBCMD_SET_FT.
 * Information in this structure is used to set ft configuration
 * to wifi driver.
 *
 * @nas_identifier: r0kh-id value
 * @nas_id_len: r0kh-id length
 * @r1_key_holder: r1kh-id value
 * @own_mac: interface's mac addr
 * @reassociation_deadline: reassociation deadline value
 */
struct GNU_PACKED ap_11r_params {
	unsigned char nas_identifier[64];
	int nas_id_len;
	unsigned char r1_key_holder[ETH_ALEN];
	unsigned char own_mac[ETH_ALEN];
	unsigned int reassociation_deadline;
};

/**
 * structure mlo_per_sta_profile - This structure defines the mlo ie format of
 * MTK_NL80211_VENDOR_SUBCMD_SET_MLO_IE.
 * Information in this structure is used to set MLO IE configuration
 * to wifi driver.
 *
 * @link_id: link id
 * @addr: per sta link mac addr
 * @dtim: dtim
 * @beacon_interval: beacon interval
 * @nstr_bmap: nstr bitmap
 * @complete_profile: complete profile bit
 * @mac_addr_present: mac addr present bit
 * @bcn_intvl_present: bcn intvl present bit
 * @dtim_present: dtim present bit
 * @nstr_present: nstr present bit
 */
struct GNU_PACKED mlo_per_sta_profile {
	unsigned char link_id;
	unsigned char addr[6];
	unsigned short dtim;
	unsigned short beacon_interval;
	unsigned short nstr_bmap;
	unsigned int complete_profile:1;
	unsigned int mac_addr_present:1;
	unsigned int bcn_intvl_present:1;
	unsigned int dtim_present:1;
	unsigned int nstr_present:1;
};

/**
 * structure wpa_mlo_ie_parse - This structure defines the mlo ie format of
 * MTK_NL80211_VENDOR_SUBCMD_SET_MLO_IE.
 * Information in this structure is used to set MLO IE configuration
 * to wifi driver.
 *
 * @type: type
 * @ml_addr: peer mld mac addr
 * @common_info_len: mlo ie common info len
 * @link_id: link id
 * @bss_para_change_count: bss para change count
 * @medium_sync_delay: medium sync delay
 * @eml_cap: eml capability
 * @mld_cap: peer mld capability
 * @ml_link_num: all link num
 * @valid: valid bit
 * @link_id_present: link id present bit
 * @bss_para_change_cnt_present: bss para change count bit
 * @medium_sync_delay_present: medium sync delay present bit
 * @eml_cap_present: eml cap present bit
 * @mld_cap_present: mld cap present bit
 * @profiles: per sta profile
 */
struct GNU_PACKED wpa_mlo_ie_parse {
	unsigned char type;
	unsigned char ml_addr[6];
	unsigned char common_info_len;
	unsigned char link_id;
	unsigned char bss_para_change_count;
	unsigned short medium_sync_delay;
	unsigned short eml_cap;
	unsigned short mld_cap;
	unsigned char ml_link_num;
	unsigned int valid:1;
	unsigned int link_id_present:1;
	unsigned int bss_para_change_cnt_present:1;
	unsigned int medium_sync_delay_present:1;
	unsigned int eml_cap_present:1;
	unsigned int mld_cap_present:1;

	struct GNU_PACKED mlo_per_sta_profile profiles[3];
};

/**
 * structure ba_mactid_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_AP_BA_SETUP_INFO &
 * MTK_NL80211_VENDOR_ATTR_AP_BA_ORITEARDOWN_INFO &
 * MTK_NL80211_VENDOR_ATTR_AP_BA_RECTEARDOWN_INFO
 * Information in this structure is used to set ft configuration
 * to wifi driver.
 *
 * @mac_addr
 * @tid
 */
struct GNU_PACKED ba_mactid_param {
	unsigned char mac_addr[6];
	unsigned char tid;
};

/**
 * enum mtk_nl80211_vendor_attrs_ap_vow - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_AP_VOW.
 * Information in these attributes is used to set vow configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_ATF_EN_INFO: u8, air time fairness enable attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_ATC_EN_INFO: refer to vow_group_en_param
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_BW_EN_INFO: u8, air time bw enalbe attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_BW_CTL_EN_INFO: refer to vow_group_en_param
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_MIN_RATE_INFO: refer to vow_rate_param
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_MAX_RATE_INFO: refer to vow_rate_param
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_MIN_RATIO_INFO: refer to vow_ratio_param
 * @MTK_NL80211_VENDOR_ATTR_AP_VOW_MAX_RATIO_INFO: refer to vow_ratio_param
 */
enum mtk_nl80211_vendor_attrs_ap_vow{
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_AP_VOW_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_ATF_EN_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_ATC_EN_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_BW_EN_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_BW_CTL_EN_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_MIN_RATE_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_MAX_RATE_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_MIN_RATIO_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_VOW_MAX_RATIO_INFO,
	__MTK_NL80211_VENDOR_ATTR_AP_VOW_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_VOW_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_AP_VOW_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_ap_monitor - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_AP_MONITOR.
 * Information in these attributes is used to set ap monitor configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AP_MONITOR_ENABLE: u8, air monitor enable attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_MONITOR_RULE: u8 array[3] air monitor rule attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_MONITOR_STA: u8 array[6], air monitor mac address attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_MONITOR_IDX: u8, air monitor index attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_MONITOR_CLR: None, air monitor clear attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_MONITOR_STA0: u8 array[6], air monitor mac address with idx 0 attributes
 */
enum mtk_nl80211_vendor_attrs_ap_monitor {
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_ENABLE,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_RULE,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_STA,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_IDX,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_CLR,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_STA0,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_STA_ID,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_MAX_PKT,
	MTK_NL80211_VENDOR_ATTR_AP_MONITOR_GET_RESULT,

	__MTK_NL80211_VENDOR_ATTR_AP_MONITOR_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_MONITOR_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_AP_MONITOR_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_ap_ba - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_BA.
 * Information in these attributes is used to set bss configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AP_BA_DECLINE_INFO: u8, BA decline attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_HT_BA_WSIZE_INFO: u16, BA tx and rx window size
 * @MTK_NL80211_VENDOR_ATTR_AP_BA_EN_INFO: u8, BA enable attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_BA_SETUP_INFO: refer to ba_mactid_param
 * @MTK_NL80211_VENDOR_ATTR_AP_BA_ORITEARDOWN_INFO: refer to ba_mactid_param
 * @MTK_NL80211_VENDOR_ATTR_AP_BA_RECTEARDOWN_INFO: refer to ba_mactid_param
 */
enum mtk_nl80211_vendor_attrs_ap_ba {
	MTK_NL80211_VENDOR_ATTR_AP_BA_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_AP_BA_DECLINE_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_HT_BA_WSIZE_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_BA_EN_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_BA_SETUP_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_BA_ORITEARDOWN_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_BA_RECTEARDOWN_INFO,
	__MTK_NL80211_VENDOR_ATTR_AP_BA_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_BA_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_AP_BA_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_ap_bss - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_AP_BSS.
 * Information in these attributes is used to set bss configuration
 * to driver from user application.
 *
 * MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_MODE: u8, wireless mode attributes
 * MTK_NL80211_VENDOR_ATTR_HT_TX_STREAM_INFO: u32, ht tx stream attributes
 * MTK_NL80211_VENDOR_ATTR_ASSOCREQ_RSSI_THRES_INFO: char, assocreq rssi thres attributes
 * MTK_NL80211_VENDOR_ATTR_AP_MPDU_DENSITY: u8, mpdu density attributes
 * MTK_NL80211_VENDOR_ATTR_AP_AMSDU_EN: u8, enable AMSDU attributes
 * MTK_NL80211_VENDOR_ATTR_AP_CNT_THR: u8, HtBssCoexApCntThr attributes
 * MTK_NL80211_VENDOR_ATTR_AP_HT_EXT_CHA: u8, HtExtcha attributes
 * MTK_NL80211_VENDOR_ATTR_AP_HT_PROTECT: u8, HtProtect attributes
 * MTK_NL80211_VENDOR_ATTR_AP_DISALLOW_NON_VHT:u8, VhtDisallowNonVht attributes
 * MTK_NL80211_VENDOR_ATTR_AP_ETXBF_EN_COND:u8, ETxBfEnCond attributes
 * MTK_NL80211_VENDOR_ATTR_AP_PMF_SHA256:u8, PMF_SHA256 attributes
 * MTK_NL80211_VENDOR_ATTR_AP_BCN_INT:u16, beacon interval attributes
 * MTK_NL80211_VENDOR_ATTR_AP_DTIM_INT:u8, dtim interval attributes
 * MTK_NL80211_VENDOR_ATTR_AP_HIDDEN_SSID:u8, hide ssid attributes
 * MTK_NL80211_VENDOR_ATTR_AP_HT_OP_MODE:u8, ht operation mode attributes
 * MTK_NL80211_VENDOR_ATTR_MURU_OFDMA_DL_EN: u8, muru ofdma dl enable attributes
 * MTK_NL80211_VENDOR_ATTR_MURU_OFDMA_UL_EN: u8, muru ofdma ul enable attributes
 * MTK_NL80211_VENDOR_ATTR_MU_MIMO_DL_EN: u8, mu mimo dl enable attributes
 * MTK_NL80211_VENDOR_ATTR_MU_MIMO_UL_EN: u8, mu mimo ul enable attributes
 * MTK_NL80211_VENDOR_ATTR_AP_BSS_MAX_IDLE: u32, bss max idle time(seconds) attributes
 * MTK_NL80211_VENDOR_ATTR_RTS_BW_SIGNALING: u8, RTS BW signaling config attributes
 */
enum mtk_nl80211_vendor_attrs_ap_bss {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_AP_BSS_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_MODE,
	MTK_NL80211_VENDOR_ATTR_HT_TX_STREAM_INFO,
	MTK_NL80211_VENDOR_ATTR_ASSOCREQ_RSSI_THRES_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_MPDU_DENSITY,
	MTK_NL80211_VENDOR_ATTR_AP_AMSDU_EN,
	MTK_NL80211_VENDOR_ATTR_AP_CNT_THR,
	MTK_NL80211_VENDOR_ATTR_AP_HT_EXT_CHA,
	MTK_NL80211_VENDOR_ATTR_AP_HT_PROTECT,
	MTK_NL80211_VENDOR_ATTR_AP_DISALLOW_NON_VHT,
	MTK_NL80211_VENDOR_ATTR_AP_ETXBF_EN_COND,
	MTK_NL80211_VENDOR_ATTR_AP_PMF_SHA256,
	MTK_NL80211_VENDOR_ATTR_AP_BCN_INT,
	MTK_NL80211_VENDOR_ATTR_AP_DTIM_INT,
	MTK_NL80211_VENDOR_ATTR_AP_HIDDEN_SSID,
	MTK_NL80211_VENDOR_ATTR_AP_HT_OP_MODE,
	MTK_NL80211_VENDOR_ATTR_MURU_OFDMA_DL_EN,
	MTK_NL80211_VENDOR_ATTR_MURU_OFDMA_UL_EN,
	MTK_NL80211_VENDOR_ATTR_MU_MIMO_DL_EN,
	MTK_NL80211_VENDOR_ATTR_MU_MIMO_UL_EN,
	MTK_NL80211_VENDOR_ATTR_AP_BSS_MAX_IDLE,
	MTK_NL80211_VENDOR_ATTR_RTS_BW_SIGNALING,

	__MTK_NL80211_VENDOR_ATTR_AP_BSS_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_BSS_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_AP_BSS_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_ap_radio - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_AP_RADIO.
 * Information in these attributes is used to set phy or global configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AP_IEEE80211H_INFO: u8, ieee80211h enable attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_ACKCTS_TOUT_EN_INFO: u8, ACKCTS timeout config enable attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_DISTANCE_INFO: u32, ACK timeout by distacne attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_CCK_ACK_TOUT_INFO: u32, ACK timeout by CCK mode attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_OFDM_ACK_TOUT_INFO: u32, ACK timeout by OFDM mode attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_OFDMA_ACK_TOUT_INFO: u32, ACK timeout by OFDMA mode attributes
 * @MTK_NL80211_VENDOR_ATTR_AP_2G_CSA_SUPPORT: u8, 2G CSA support enable attributes
 */
enum mtk_nl80211_vendor_attrs_ap_radio {
	MTK_NL80211_VENDOR_ATTR_AP_RADIO_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_AP_IEEE80211H_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_ACKCTS_TOUT_EN_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_DISTANCE_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_CCK_ACK_TOUT_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_OFDM_ACK_TOUT_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_OFDMA_ACK_TOUT_INFO,
	MTK_NL80211_VENDOR_ATTR_AP_2G_CSA_SUPPORT,

	__MTK_NL80211_VENDOR_ATTR_AP_RADIO_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_RADIO_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_AP_RADIO_AFTER_LAST - 1
};
/**
 * enum mtk_nl80211_vendor_attrs_wmm - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_WMM.
 * Information in these attributes is used to set wmm configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_WMM_AP_AIFSN_INFO: array, ap aifsn value, AC0:AC1:AC2:AC3
 * @MTK_NL80211_VENDOR_ATTR_WMM_AP_CWMIN_INFO: array, ap cwmin value, AC0:AC1:AC2:AC3
 * @MTK_NL80211_VENDOR_ATTR_WMM_AP_CWMAX_INFO: array, ap cwmax value, AC0:AC1:AC2:AC3
 * @MTK_NL80211_VENDOR_ATTR_WMM_AP_TXOP_INFO: array, ap txop value, AC0:AC1:AC2:AC3
 */
enum mtk_nl80211_vendor_attrs_wmm{
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_WMM_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_WMM_AP_AIFSN_INFO,
	MTK_NL80211_VENDOR_ATTR_WMM_AP_CWMIN_INFO,
	MTK_NL80211_VENDOR_ATTR_WMM_AP_CWMAX_INFO,
	MTK_NL80211_VENDOR_ATTR_WMM_AP_TXOP_INFO,
	__MTK_NL80211_VENDOR_ATTR_WMM_AFTER_LAST,
	MTK_NL80211_VENDOR_WMM_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_WMM_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_vlan - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_VLAN.
 * Information in these attributes is used to set vlan configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_VLAN_EN_INFO: u8, vlan enable attributes
 * @MTK_NL80211_VENDOR_ATTR_VLAN_ID_INFO: u16, vlan id attributes
 * @MTK_NL80211_VENDOR_ATTR_VLAN_PRIORITY_INFO: u8, vlan priority attributes
 * @MTK_NL80211_VENDOR_ATTR_VLAN_TAG_INFO: u8, vlan tag attributes
 * @MTK_NL80211_VENDOR_ATTR_VLAN_POLICY_INFO: refer to vlan_policy_param
 */
enum mtk_nl80211_vendor_attrs_vlan{
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_VLAN_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_VLAN_EN_INFO,
	MTK_NL80211_VENDOR_ATTR_VLAN_ID_INFO,
	MTK_NL80211_VENDOR_ATTR_VLAN_PRIORITY_INFO,
	MTK_NL80211_VENDOR_ATTR_VLAN_TAG_INFO,
	MTK_NL80211_VENDOR_ATTR_VLAN_POLICY_INFO,
	__MTK_NL80211_VENDOR_ATTR_VLAN_AFTER_LAST,
	MTK_NL80211_VENDOR_VLAN_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_VLAN_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_mbo - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_MBO.
 * Information in these attributes is used to set MBO configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_SET_MBO_NPC to set npc list into unsigned char npc_value[MBO_NPC_MAX_LEN];
 */
enum mtk_nl80211_vendor_attrs_mbo {
	MTK_NL80211_VENDOR_ATTR_MBO_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_SET_MBO_NPC,
	__MTK_NL80211_VENDOR_ATTR_MBO_LAST,
	MTK_NL80211_VENDOR_ATTR_MBO_MAX =
	__MTK_NL80211_VENDOR_ATTR_MBO_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_ft - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_FT.
 * Information in these attributes is used to set ft configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_SET_FTIE: struct ap_11r_params, ap ftie value, r0kh-id and r1kh-id
 */
enum mtk_nl80211_vendor_attrs_ft {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_FT_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SET_FTIE,

	__MTK_NL80211_VENDOR_ATTR_FT_LAST,
	MTK_NL80211_VENDOR_ATTR_FT_MAX =
	__MTK_NL80211_VENDOR_ATTR_FT_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_mlo_ie - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_MLO_IE.
 * Information in these attributes is used to set mlo ie configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_SET_AUTH_MLO_IE: struct wpa_ml_ie_parse, ap mlo ie value
 */
enum mtk_nl80211_vendor_attrs_mlo_ie {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_MLO_IE_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SET_AUTH_MLO_IE,

	__MTK_NL80211_VENDOR_ATTR_MLO_IE_LAST,
	MTK_NL80211_VENDOR_ATTR_MLO_IE_MAX =
	__MTK_NL80211_VENDOR_ATTR_MLO_IE_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_pmkid - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_PMKID.
 * Information in these attributes is used to set pmkid cache configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_SUBCMD_SET_PMKSA_CACHE
 */
enum mtk_nl80211_vendor_attrs_pmkid {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_PMKID_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SET_PMKSA_CACHE,

	__MTK_NL80211_VENDOR_ATTR_PMKID_LAST,
	MTK_NL80211_VENDOR_ATTR_PMKID_MAX =
	__MTK_NL80211_VENDOR_ATTR_PMKID_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_mlo_preset_link - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_MLO_PRESET_LINK.
 * Information in these attributes is used to set mlo link id
 * to driver from user application such as wpa_supplicant.
 *
 * @MTK_NL80211_VENDOR_ATTR_MLO_PRESET_LINK_INFO: u8, set mlo link id value, 0, 1 or other
 */
enum mtk_nl80211_vendor_attrs_mlo_preset_link{
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_MLO_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_MLO_PRESET_LINKID_INFO,
	__MTK_NL80211_VENDOR_ATTR_MLO_PRESET_LINKID_AFTER_LAST,
	MTK_NL80211_VENDOR_MLO_PRESET_LINKID_ATTR_MAX =
	__MTK_NL80211_VENDOR_ATTR_MLO_PRESET_LINKID_AFTER_LAST - 1
};


/**
 * enum mtk_nl80211_vendor_attrs_ap_security - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_AP_SECURITY.
 * Information in these attributes is used to set security information
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_AUTHMODE:  u32, auth mode attributes, refer to mtk_vendor_attr_authmode
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_ENCRYPTYPE: u32, encryptype, refer to mtk_vendor_attr_encryptype
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_REKEYINTERVAL: u32, rekey interval in seconds
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_REKEYMETHOD: u8, 0-by time, 1-by pkt count
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_DEFAULTKEYID: u8, default key index
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_WEPKEY: refer to wep_key_param
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PASSPHRASE: string
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PMF: u8 1-support pmf, 0-not support pmf
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PMF_REQUIRE: u8 1-pmf is required, 0-pmf is not required
 * @MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PMF_SHA256: u8 1-pmfsha256 is desired, 0-pmfsha256 is not desired
 */
enum mtk_nl80211_vendor_attrs_ap_security {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_AUTHMODE,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_ENCRYPTYPE,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_REKEYINTERVAL,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_REKEYMETHOD,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_DEFAULTKEYID,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_WEPKEY,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PASSPHRASE,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PMF_CAPABLE,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PMF_REQUIRE,
	MTK_NL80211_VENDOR_ATTR_AP_SECURITY_PMF_SHA256,
	/* add attributes here, update the policy in nl80211.c */

	__MTK_NL80211_VENDOR_ATTR_AP_SECURITY_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_SECURITY_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_AP_SECURITY_AFTER_LAST - 1
};


/**
 * enum mtk_vendor_attr_ap_wireless - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_AP_WIRELESS.
 * Information in these attributes is used to set wireless information
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_FIXED_MCS:  u8, fixed mcs
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_FIXED_OFDMA: u8,  0-disable, 1-DL, 2-UL
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_PPDU_TX_TYPE: u8, 0-SU, 1-MU, 2-LEGACY
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_NUSERS_OFDMA: u8, NumUsersOFDMA
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_BA_BUFFER_SIZE:  u8, ba req buffer size
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_MIMO: u8, 0-DL, 1-UL
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_AMPDU: u8, 0-disable, 1-enable
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_AMSDU: u8, 0-disable, 1-enable
 * @MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_CERT: u8 cert mode, 0-disable, 1-enable
 */
enum mtk_vendor_attr_ap_wireless {
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_FIXED_MCS,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_FIXED_OFDMA,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_PPDU_TX_TYPE,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_NUSERS_OFDMA,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_BA_BUFFER_SIZE,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_MIMO,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_AMPDU,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_AMSDU,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_CERT,

	/* keep last */
	__MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_AFTER_LAST,
	MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_MAX =
	__MTK_NL80211_VENDOR_ATTR_AP_WIRELESS_AFTER_LAST - 1
};



/**
 * enum mtk_nl80211_vendor_attrs_ap_rfeature - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_AP_RFEATURE.
 * Information in these attributes is used to set radio information
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_HE_GI:  u8, he gi attributes, 0-0.8; 1-1.6; 2-3.2
 * @MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_HE_LTF: u8, he ltf attribute, 0-3.2; 1-6.4; 2-12.8
 * @MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_TRIG_TYPE: string,  "<en>,<type>",
 *  en: 0-disable,1-enable; type: 0~7
 * @MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_TRIG_TYPE_EN: u8, 0-disable, 1-enable
 * @MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_ACK_PLCY: u8, 0-4
 */
enum mtk_nl80211_vendor_attrs_ap_rfeature {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_HE_GI,
	MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_HE_LTF,
	MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_TRIG_TYPE,
	MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_ACK_PLCY,

	__MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_RFEATURE_ATTR_MAX =
	__MTK_NL80211_VENDOR_ATTR_AP_RFEATURE_AFTER_LAST - 1
};


/**
 * enum mtk_nl80211_vendor_attr_get_static_info - Specifies the vendor attribute values
 * to get static info
 */
enum mtk_nl80211_vendor_attr_get_static_info {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_CHIP_ID,
	MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_DRIVER_VER,
	MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_COEXISTENCE,
	MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_WIFI_VER,
	MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_WAPP_SUPPORT_VER,

	__MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_LAST,
	MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_MAX =
	__MTK_NL80211_VENDOR_ATTR_GET_STATIC_INFO_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_get_runtime_info - Specifies the vendor attribute values
 * to get runtime info
 * @MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_ACS_REFRESH_PERIOD: u32, ACS check period.
 * @MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_CHANNEL_LAST_CHANGE: u32, The accumulated
 *   time since the current Channel came into use. unit:us.
 * @MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_MAX_NUM_OF_SSIDS: u8, Max number of ssid.
 * @MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_EXTENSION_CHANNEL: u8, Secondary extension
 *   channel position. 0:none; 1:above; 3:below
 * @MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_TRANSMITPOWER: u8, the current transmit
 *   power level as a percentage of full power.

 */
enum mtk_nl80211_vendor_attr_get_runtime_info {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_MAX_NUM_OF_STA,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_CHAN_LIST,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_OP_CLASS,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_BSS_INFO,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_NOP_CHANNEL_LIST,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_WMODE,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_WAPP_WSC_PROFILES,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_PMK_BY_PEER_MAC,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_802_11_AUTHENTICATION_MODE,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_802_11_MAC_ADDRESS,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_802_11_CURRENTCHANNEL,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_ACS_REFRESH_PERIOD,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_CHANNEL_LAST_CHANGE,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_MAX_NUM_OF_SSIDS,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_EXTENSION_CHANNEL,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_TRANSMITPOWER,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_GET_80211H,

	__MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_LAST,
	MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_MAX =
	__MTK_NL80211_VENDOR_ATTR_GET_RUNTIME_INFO_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_get_statistic - Specifies the vendor attribute values
 * to get statistic info
 */
enum mtk_nl80211_vendor_attr_get_statistic {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_GET_STATISTIC_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_GET_802_11_STATISTICS,
	MTK_NL80211_VENDOR_ATTR_GET_TX_PWR,
	MTK_NL80211_VENDOR_ATTR_GET_AP_METRICS,
	MTK_NL80211_VENDOR_ATTR_GET_802_11_PER_BSS_STATISTICS,
	MTK_NL80211_VENDOR_ATTR_GET_CPU_TEMPERATURE,

	_MTK_NL80211_VENDOR_ATTR_GET_STATISTIC_LAST,
	MTK_NL80211_VENDOR_ATTR_GET_STATISTIC_MAX =
	_MTK_NL80211_VENDOR_ATTR_GET_STATISTIC_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_wapp_req - Specifies the vendor attribute values
 * to request wifi info
 */
enum mtk_nl80211_vendor_attr_wapp_req {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_WAPP_REQ_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_WAPP_REQ,

	__MTK_NL80211_VENDOR_ATTR_WAPP_REQ_LAST,
	MTK_NL80211_VENDOR_ATTR_WAPP_REQ_MAX =
	__MTK_NL80211_VENDOR_ATTR_WAPP_REQ_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_event_rsp_wapp_event - Specifies the vendor attribute values
 * to get wifi info event
 */
enum mtk_nl80211_vendor_attr_event_rsp_wapp_event {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_EVENT_RSP_WAPP_EVENT_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_EVENT_RSP_WAPP_EVENT,

	__MTK_NL80211_VENDOR_ATTR_EVENT_RSP_WAPP_EVENT_LAST,
	MTK_NL80211_VENDOR_ATTR_EVENT_RSP_WAPP_EVENT_MAX =
	__MTK_NL80211_VENDOR_ATTR_EVENT_RSP_WAPP_EVENT_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_get_cap - Specifies the vendor attribute values
 * to get capability info
 */
enum mtk_nl80211_vendor_attr_get_cap {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_CAC_CAP,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_MISC_CAP,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_HT_CAP,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_VHT_CAP,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_HE_CAP,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_WF6_CAPABILITY,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_QUERY_11H_CAPABILITY,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_QUERY_RRM_CAPABILITY,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_QUERY_KVR_CAPABILITY,

	__MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_LAST,
	MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_MAX =
	__MTK_NL80211_VENDOR_ATTR_GET_CAP_INFO_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_mwds_set - Specifies the vendor attribute values
 * MTK_NL80211_VENDOR_ATTR_MWDS_ENABLE: u8, enable/disable MWDS attribute
 * MTK_NL80211_VENDOR_ATTR_MWDS_ENABLE: u8, clear/show MWDS autotes result attribute
 */
enum mtk_nl80211_vendor_attrs_mwds_set {
	MTK_NL80211_VENDOR_ATTR_MWDS_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_MWDS_ENABLE,
	MTK_NL80211_VENDOR_ATTR_MWDS_INFO,

	__MTK_NL80211_VENDOR_ATTR_MWDS_LAST,
	MTK_NL80211_VENDOR_MWDS_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_MWDS_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_country_set - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_COUNTRY.
 * Information in these attributes is used to set country code/region/string
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_COUNTRY_SET_CODE: string, Country code
 * @MTK_NL80211_VENDOR_ATTR_COUNTRY_SET_REGION: u32, Region code
 * @MTK_NL80211_VENDOR_ATTR_COUNTRY_SET_NAME: string, Country string
 */
enum mtk_nl80211_vendor_attrs_country_set {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_COUNTRY_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_COUNTRY_SET_CODE,
	MTK_NL80211_VENDOR_ATTR_COUNTRY_SET_REGION,
	MTK_NL80211_VENDOR_ATTR_COUNTRY_SET_NAME,

	__MTK_NL80211_VENDOR_ATTR_COUNTRY_LAST,
	MTK_NL80211_VENDOR_ATTR_COUNTRY_MAX = __MTK_NL80211_VENDOR_ATTR_COUNTRY_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attrs_chan_set - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_CHANNEL.
 * Information in these attributes are used to set channel and bandwidth
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_CHAN_SET_NUM: u8, channel ID
 * @MTK_NL80211_VENDOR_ATTR_CHAN_SET_FREQ: u32, frequency
 * @MTK_NL80211_VENDOR_ATTR_CHAN_SET_BW: u32, channel bandwidth
 * @MTK_NL80211_VENDOR_ATTR_CHAN_SET_HT_EXTCHAN: u8, HT 40 extension channel
 * @MTK_NL80211_VENDOR_ATTR_CHAN_SET_HT_COEX: u8, HT 20/40 coex
 */
enum mtk_nl80211_vendor_attrs_chan_set {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_CHAN_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_CHAN_SET_NUM,
	MTK_NL80211_VENDOR_ATTR_CHAN_SET_FREQ,
	MTK_NL80211_VENDOR_ATTR_CHAN_SET_BW,
	MTK_NL80211_VENDOR_ATTR_CHAN_SET_HT_EXTCHAN,
	MTK_NL80211_VENDOR_ATTR_CHAN_SET_HT_COEX,

	__MTK_NL80211_VENDOR_ATTR_CHAN_LAST,
	MTK_NL80211_VENDOR_ATTR_CHAN_MAX = __MTK_NL80211_VENDOR_ATTR_CHAN_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_auto_ch_sel - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_AUTO_CH_SEL.
 * Information in these attributes are used to trigger acs operation
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_AUTO_CH_SEL: u8, the algorithm used for acs
 * @MTK_NL80211_VENDOR_ATTR_AUTO_CH_CHECK_TIME: u32, the check time for periodic acs
 */
enum mtk_nl80211_vendor_attr_auto_ch_sel {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_AUTO_CH_SEL_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_AUTO_CH_SEL,
	MTK_NL80211_VENDOR_ATTR_AUTO_CH_CHECK_TIME,

	__MTK_NL80211_VENDOR_ATTR_AUTO_CH_SEL_LAST,
	MTK_NL80211_VENDOR_ATTR_AUTO_CH_SEL_MAX =
	__MTK_NL80211_VENDOR_ATTR_AUTO_CH_SEL_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_scan - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_SCAN.
 * Information in these attributes are used to trigger scan operation
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_SCAN_TYPE: u8, the type of scan
 * @MTK_NL80211_VENDOR_ATTR_SCAN_CLEAR: without value, to clear scan result
 * @MTK_NL80211_VENDOR_ATTR_SCAN_SSID: ssid, the ssid for full scan
 * @MTK_NL80211_VENDOR_ATTR_PARTIAL_SCAN_INTERVAL: u32, the interval of continous partial scans
 * @MTK_NL80211_VENDOR_ATTR_PARTIAL_SCAN_NUM_OF_CH: u8, the scanned ch num before restoring for partial scan
 * @MTK_NL80211_VENDOR_ATTR_OFFCH_SCAN_TARGET_CH: u32, the target ch for offch scan
 * @MTK_NL80211_VENDOR_ATTR_OFFCH_SCAN_ACTIVE: u8, passive or active for offch scan
 * @MTK_NL80211_VENDOR_ATTR_OFFCH_SCAN_DURATION: u32, the duration for offch scan
 * @MTK_NL80211_VENDOR_ATTR_SCAN_DUMP_BSS_START_INDEX: u32, first bss indx for scan dump
 * @MTK_NL80211_VENDOR_ATTR_GET_SCAN_RESULT: scan result information string
 */
enum mtk_nl80211_vendor_attr_scan{
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_SCAN_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SCAN_TYPE,
	MTK_NL80211_VENDOR_ATTR_SCAN_CLEAR,
	MTK_NL80211_VENDOR_ATTR_SCAN_SSID,
	MTK_NL80211_VENDOR_ATTR_PARTIAL_SCAN_INTERVAL,
	MTK_NL80211_VENDOR_ATTR_PARTIAL_SCAN_NUM_OF_CH,
	MTK_NL80211_VENDOR_ATTR_OFFCH_SCAN_TARGET_CH,
	MTK_NL80211_VENDOR_ATTR_OFFCH_SCAN_ACTIVE,
	MTK_NL80211_VENDOR_ATTR_OFFCH_SCAN_DURATION,
	MTK_NL80211_VENDOR_ATTR_SCAN_DUMP_BSS_START_INDEX,
	MTK_NL80211_VENDOR_ATTR_GET_SCAN_RESULT,

	__MTK_NL80211_VENDOR_ATTR_SCAN_LAST,
	MTK_NL80211_VENDOR_ATTR_SCAN_MAX =
	__MTK_NL80211_VENDOR_ATTR_SCAN_LAST - 1
};

/**
 * enum mtk_vendor_attr_scantype - This enum defines the value of
 * MTK_NL80211_VENDOR_ATTR_SCAN_TYPE.
 * Information in these attributes is used to set the scan type.
 */
enum mtk_vendor_attr_scantype{
	NL80211_FULL_SCAN,
	NL80211_PARTIAL_SCAN,
	NL80211_OFF_CH_SCAN,
	NL80211_2040_OVERLAP_SCAN
};

/**
 * enum mtk_nl80211_vendor_attr_set_action - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_ACTION
 * Information in these attributes are used to trigger action
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_SET_ACTION_OFFCHAN_ACTION_FRAME: without value, to
 * trigger offchannel action
 * @MTK_NL80211_VENDOR_ATTR_SET_ACTION_QOS_ACTION_FRAME: without value, to set qos
 */
enum mtk_nl80211_vendor_attr_set_action {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_SET_ACTION_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SET_ACTION_OFFCHAN_ACTION_FRAME,
	MTK_NL80211_VENDOR_ATTR_SET_ACTION_QOS_ACTION_FRAME,

	__MTK_NL80211_VENDOR_ATTR_SET_ACTION_LAST,
	MTK_NL80211_VENDOR_ATTR_SET_ACTION_MAX =
	__MTK_NL80211_VENDOR_ATTR_SET_ACTION_LAST - 1
};

/**
* enum mtk_nl80211_vendor_attr_qos - This enum defines
* attributes required for MTK_NL80211_VENDOR_SUBCMD_QOS
* Information in these attributes are used by QoS
* to driver from user application.
*
* @MTK_NL80211_VENDOR_ATTR_QOS_UP_TUPLE_EXPIRED_NOTIFY:
* @MTK_NL80211_VENDOR_ATTR_GET_PMK_BY_PEER_MAC:
*/
enum mtk_nl80211_vendor_attr_qos {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_QOS_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_QOS_UP_TUPLE_EXPIRED_NOTIFY,
	MTK_NL80211_VENDOR_ATTR_GET_PMK_BY_PEER_MAC,

	__MTK_NL80211_VENDOR_ATTR_QOS_LAST,
	MTK_NL80211_VENDOR_ATTR_QOS_MAX =
	__MTK_NL80211_VENDOR_ATTR_QOS_LAST - 1
};

/**
* enum mtk_nl80211_vendor_attr_subcmd_offchannel_info - This enum defines
* attributes required for MTK_NL80211_VENDOR_SUBCMD_OFFCHANNEL_INFO
* Information in these attributes are used by offchannel_feature
* to driver from user application.
*
* @MTK_NL80211_VENDOR_ATTR_SUBCMD_OFF_CHANNEL_INFO:
*/
enum mtk_nl80211_vendor_attr_subcmd_offchannel_info {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_SUBCMD_OFF_CHANNEL_INFO_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SUBCMD_OFF_CHANNEL_INFO,

	__MTK_NL80211_VENDOR_ATTR_SUBCMD_OFF_CHANNEL_INFO_LAST,
	MTK_NL80211_VENDOR_ATTR_SUBCMD_OFF_CHANNEL_INFO_MAX =
	__MTK_NL80211_VENDOR_ATTR_SUBCMD_OFF_CHANNEL_INFO_LAST - 1
};

/**
* enum mtk_nl80211_vendor_attr_event_offchannel_info - This enum defines
* attributes required for MTK_NL80211_VENDOR_SUBCMD_EVENT_OFFCHANNEL_INFO
* Information in these attributes are used by driver generate event send to user application
*
* @MTK_NL80211_VENDOR_ATTR_EVENT_OFF_CHANNEL_INFO: scan result to app
*/
enum mtk_nl80211_vendor_attr_event_offchannel_info {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_EVENT_OFF_CHANNEL_INFO_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_EVENT_OFF_CHANNEL_INFO,

	__MTK_NL80211_VENDOR_ATTR_EVENT_OFF_CHANNEL_INFO_LAST,
	MTK_NL80211_VENDOR_ATTR_EVENT_OFF_CHANNEL_INFO_MAX =
	__MTK_NL80211_VENDOR_ATTR_EVENT_OFF_CHANNEL_INFO_LAST - 1
};

/**
* enum mtk_nl80211_vendor_attr_dfs - This enum defines
* attributes required for MTK_NL80211_VENDOR_SUBCMD_DFS
* Information in these attributes are used by DFS feature
*
* @MTK_NL80211_VENDOR_ATTR_DFS_SET_ZERO_WAIT: set zero wait
* @MTK_NL80211_VENDOR_ATTR_DFS_GET_ZERO_WAIT: get zero wait info
* @MTK_NL80211_VENDOR_ATTR_DFS_CAC_STOP: set cac stop
*/
enum mtk_nl80211_vendor_attr_dfs {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_DFS_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_DFS_SET_ZERO_WAIT,
	MTK_NL80211_VENDOR_ATTR_DFS_GET_ZERO_WAIT,
	MTK_NL80211_VENDOR_ATTR_DFS_CAC_STOP,

	__MTK_NL80211_VENDOR_ATTR_DFS_LAST,
	MTK_NL80211_VENDOR_ATTR_DFS_MAX =
	__MTK_NL80211_VENDOR_ATTR_DFS_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_easymesh - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_EASYMESH
 * Information in these attributes are used by Easymesh
 *
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_SSID: string, set easymesh ssid
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_PSK: psk, set easymesh psk
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_PMK: pmk, set easymesh pmk
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_GET_ASSOC_REQ_FRAME: get info
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_GET_DPP_FRAME: get info
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_WAPP_IE: ie, set ie from wapp
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_CANCEL_ROC: without value, to cancel roc
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_DEL_CCE_IE: without value, to delete cce ie
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_R3_DPP_URI: url, dpp url
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_R3_1905_SEC_ENABLED: bool, set security of 1905
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_R3_ONBOARDING_TYPE: bool, set onboarding type
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_BHBSS: char, set bhbss enable/disable
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_FHBSS: char, set fhbss enable/disable
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_START_ROC: roc req data , to start ROC
 * @MTK_NL80211_VENDOR_ATTR_GET_SPT_REUSE_REQ: srg info , to get spt reuse req
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_MAP_CH: map_ch , set channel for Easymesh
 * @MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_MAP_ENABLE: char , set MAP  enable/disable
 *
 */
enum mtk_nl80211_vendor_attr_easymesh {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_EASYMESH_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_SSID,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_PSK,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_PMK,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_GET_ASSOC_REQ_FRAME,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_GET_DPP_FRAME,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_WAPP_IE,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_CANCEL_ROC,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_DEL_CCE_IE,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_R3_DPP_URI,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_R3_1905_SEC_ENABLED,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_R3_ONBOARDING_TYPE,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_BHBSS,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_FHBSS,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_START_ROC,
	MTK_NL80211_VENDOR_ATTR_GET_SPT_REUSE_REQ,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_MAP_CH,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_SET_MAP_ENABLE,

	__MTK_NL80211_VENDOR_ATTR_EASYMESH_LAST,
	MTK_NL80211_VENDOR_ATTR_EASYMESH_MAX =
	__MTK_NL80211_VENDOR_ATTR_EASYMESH_LAST - 1
};
/**
 * mtk_nl80211_vendor_attr_acl_mode - Specifies the vendor cmd  mode for ACL
 *MTK_NL80211_VENDOR_ATTR_ACL_POLICY: u8, the mode of acl, 0 /1 /2 (disable, black list, white list)
 *MTK_NL80211_VENDOR_ATTR_ACL_ADD_MAC: nest, add acl entry, the format like this, [mac_addr][mac_addr][...]
 *MTK_NL80211_VENDOR_ATTR_ACL_DEL_MAC: nest, del acl entry, the format like this, [mac_addr][mac_addr][...]
 *MTK_NL80211_VENDOR_ATTR_ACL_SHOW_ALL: without value, show all stas in list
 *MTK_NL80211_VENDOR_ATTR_ACL_CLEAR_ALL: without value, clear all stas in list
 */
enum mtk_nl80211_vendor_attr_acl_mode {
	MTK_NL80211_VENDOR_ATTR_ACL_INVALID,
	MTK_NL80211_VENDOR_ATTR_ACL_POLICY = 1,
	MTK_NL80211_VENDOR_ATTR_ACL_ADD_MAC = 2,
	MTK_NL80211_VENDOR_ATTR_ACL_DEL_MAC = 3,
	MTK_NL80211_VENDOR_ATTR_ACL_SHOW_ALL = 4,
	MTK_NL80211_VENDOR_ATTR_ACL_CLEAR_ALL = 5,
	__MTK_NL80211_VENDOR_ATTR_AP_ACL_AFTER_LAST,
	MTK_NL80211_VENDOR_AP_ACL_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_AP_ACL_AFTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_acl_policy - Specifies the vendor attribute values
 * to set acl policy.
 *MTK_NL80211_VENDOR_ATTR_ACL_DISABLE: u8, disable the acl
 *MTK_NL80211_VENDOR_ATTR_ACL_ENABLE_WHITE_LIST: u8, enter the white list mode
 *MTK_NL80211_VENDOR_ATTR_ACL_ENABLE_BLACK_LIST: u8, enter the black list mode
 */
enum mtk_nl80211_vendor_attr_acl_policy {
	MTK_NL80211_VENDOR_ATTR_ACL_DISABLE = 0,
	MTK_NL80211_VENDOR_ATTR_ACL_ENABLE_WHITE_LIST = 1,
	MTK_NL80211_VENDOR_ATTR_ACL_ENABLE_BLACK_LIST = 2,
};
/**
 * enum mtk_nl80211_vendor_attrs_tx_power - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_TXPOWER.
 * Information in these attributes is used to set AP Power configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_PERCENTAGE: u8, Power Drop Percentage, work after channel set.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_MAX: u8, set max tx power.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_INFO: u8, set cmd to fw for show pwr info.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_PERCENTAGE_EN: u8, enable power percentage.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_DROP_CTRL: u8, power drop by percentage, work immediatelly.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_DECREASE: u8, power drop by specific value.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_SKU_CTRL: u8, sku function enable/disable.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_SKU_INFO: u8, show sku information.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_MU: struct, MU power setting.
 * @MTK_NL80211_VENDOR_ATTR_TXPWR_MGMT: u8, management frame power specific.
 */
enum mtk_nl80211_vendor_attrs_tx_power{
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_TXPWR_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_TXPWR_PERCENTAGE,
	MTK_NL80211_VENDOR_ATTR_TXPWR_MAX,
	MTK_NL80211_VENDOR_ATTR_TXPWR_INFO,
	MTK_NL80211_VENDOR_ATTR_TXPWR_PERCENTAGE_EN,
	MTK_NL80211_VENDOR_ATTR_TXPWR_DROP_CTRL,
	MTK_NL80211_VENDOR_ATTR_TXPWR_DECREASE,
	MTK_NL80211_VENDOR_ATTR_TXPWR_SKU_CTRL,
	MTK_NL80211_VENDOR_ATTR_TXPWR_SKU_INFO,
	MTK_NL80211_VENDOR_ATTR_TXPWR_MU,
	MTK_NL80211_VENDOR_ATTR_TXPWR_MGMT,
	__MTK_NL80211_VENDOR_ATTR_TXPWR_AFTER_LAST,
	MTK_NL80211_VENDOR_TXPWR_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_TXPWR_AFTER_LAST - 1
};
/**
 * structure mu_power_param - This structure defines the payload format of
 * MTK_NL80211_VENDOR_ATTR_TXPWR_MU
 * Information in this structure is used to set ft configuration
 * to wifi driver.
 *
 * @en: enable/disable
 * @value: power in dBm:
 */
struct GNU_PACKED mu_power_param {
	unsigned int en;
	unsigned int value;
};
/**
 * enum mtk_nl80211_vendor_attrs_edca - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_EDCA.
 * Information in these attributes is used to set AP Power configuration
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_TX_BURST: u8, Tx Burst enable/disable.

 */
enum mtk_nl80211_vendor_attrs_edca{
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_EDCA_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_TX_BURST,
	__MTK_NL80211_VENDOR_ATTR_EDCA_AFTER_LAST,
	MTK_NL80211_VENDOR_EDCA_ATTR_MAX = __MTK_NL80211_VENDOR_ATTR_EDCA_AFTER_LAST - 1
};

/**
  * enum mtk_nl80211_vendor_attrs_mcast_snoop
  * This enum defines attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_MULTICAST_SNOOPING.
  * Information in these attributes is used to set multicast snooping configuration
  * to driver from user application.
  *
  * @MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_ENABLE: u8, 0-disable, 1-enable
  * @MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_UNKNOWN_PLCY: u8, 0-unknown drop, 1-unknown flooding
  * @MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_ENTRY_ADD: string
  * @MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_ENTRY_DEL: string
  * @MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_DENY_LIST: string
  * @MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_FLOODINGCIDR: string
  */
enum mtk_nl80211_vendor_attrs_mcast_snoop{
	MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_INVALID = 0,
	MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_ENABLE,
	MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_UNKNOWN_PLCY,
	MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_ENTRY_ADD,
	MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_ENTRY_DEL,
	MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_DENY_LIST,
	MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_FLOODINGCIDR,
	__MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_AFTER_LAST,
	MTK_NL80211_VENDOR_MCAST_SNOOP_ATTR_MAX =
		__MTK_NL80211_VENDOR_ATTR_MCAST_SNOOP_AFTER_LAST - 1
};


/**
 * enum mtk_nl80211_vendor_attr_ate - Specifies the vendor attribute values
 * to request wifi info
 *
 * @MTK_NL80211_VENDOR_ATTR_HQA: struct hqa_frame
 */
enum mtk_nl80211_vendor_attr_hqa {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_HQA_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_HQA,

	__MTK_NL80211_VENDOR_ATTR_HQA_AFTER_LAST,
	MTK_NL80211_VENDOR_ATTR_HQA_MAX =
		__MTK_NL80211_VENDOR_ATTR_HQA_AFTER_LAST - 1
};


/**
 * enum mtk_nl80211_vendor_attrs_ate - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_ATE.
 * Information in these attributes is used to set security information
 * to driver from user application.
 *
 *
 * @MTK_NL80211_VENDOR_ATTR_ATE_ACTION: u32,  set action mode
 * @MTK_NL80211_VENDOR_ATTR_ATE_MCS: u32, set mcs
 * @MTK_NL80211_VENDOR_ATTR_ATE_NSS: u32, set nss
 * @MTK_NL80211_VENDOR_ATTR_ATE_TXSTBC: u32, set stbc
 * @MTK_NL80211_VENDOR_ATTR_ATE_TXMODE: u32, set txmode
 * @MTK_NL80211_VENDOR_ATTR_ATE_TXGI: u32, set tx gi
 * @MTK_NL80211_VENDOR_ATTR_ATE_TXPE: u32, set tx pe
 * @MTK_NL80211_VENDOR_ATTR_ATE_PAYLOAD: u32, set payload
 * @MTK_NL80211_VENDOR_ATTR_ATE_FIXEDPAYLOAD: u32, set fixed payload
 * @MTK_NL80211_VENDOR_ATTR_ATE_TXPOWER: u32, set tx power
 * @MTK_NL80211_VENDOR_ATTR_ATE_CHANNEL: u32, set channel
 * @MTK_NL80211_VENDOR_ATTR_ATE_TXBW: u32, set tx bw
 * @MTK_NL80211_VENDOR_ATTR_ATE_TXANT: u32, tx ant
 * @MTK_NL80211_VENDOR_ATTR_ATE_RXANT: u32, rx ant
 */
enum mtk_nl80211_vendor_attr_ate {
	/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_ATE_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_ATE_ACTION,
	MTK_NL80211_VENDOR_ATTR_ATE_MCS,
	MTK_NL80211_VENDOR_ATTR_ATE_NSS,
	MTK_NL80211_VENDOR_ATTR_ATE_TXSTBC,
	MTK_NL80211_VENDOR_ATTR_ATE_TXMODE,
	MTK_NL80211_VENDOR_ATTR_ATE_TXGI,
	MTK_NL80211_VENDOR_ATTR_ATE_TXPE,
	MTK_NL80211_VENDOR_ATTR_ATE_PAYLOAD,
	MTK_NL80211_VENDOR_ATTR_ATE_FIXEDPAYLOAD,
	MTK_NL80211_VENDOR_ATTR_ATE_TXPOWER,
	MTK_NL80211_VENDOR_ATTR_ATE_CHANNEL,
	MTK_NL80211_VENDOR_ATTR_ATE_TXBW,
	MTK_NL80211_VENDOR_ATTR_ATE_TXANT,
	MTK_NL80211_VENDOR_ATTR_ATE_RXANT,

	__MTK_NL80211_VENDOR_ATTR_ATE_AFTER_LAST,
	MTK_NL80211_VENDOR_ATTR_ATE_MAX =
		__MTK_NL80211_VENDOR_ATTR_ATE_AFTER_LAST - 1
};

/**
 * enum mtk_vendor_attr_ateaction - This enum defines the value of
 * MTK_NL80211_VENDOR_ATTR_ATE_ACTION.
 * Information in these attributes is used set ate action mode of testmode
 */

enum mtk_vendor_attr_ateaction {
	NL80211_ATE_ACTION_ATESTART,
	NL80211_ATE_ACTION_ATESTOP,
	NL80211_ATE_ACTION_TXCARR,
	NL80211_ATE_ACTION_TXCONT,
	NL80211_ATE_ACTION_TXFRAME,
	NL80211_ATE_ACTION_TXSTOP,
	NL80211_ATE_ACTION_RXFRAME,
	NL80211_ATE_ACTION_RXSTOP,
};

/**
 * enum mtk_nl80211_vendor_attr_v10convertor - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_V10CONVERTER.
 * Information in these attributes is used to v10converter
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_SET_V10CONVERTER: u8, enable/disable v10convertor
 */
enum mtk_nl80211_vendor_attr_v10converter {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_V10CONVERTER_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SET_V10CONVERTER,

	__MTK_NL80211_VENDOR_ATTR_V10CONVERTER_LAST,
	MTK_NL80211_VENDOR_ATTR_V10CONVERTER_MAX =
	__MTK_NL80211_VENDOR_ATTR_V10CONVERTER_LAST - 1
};

/**
 * enum mtk_nl80211_vendor_attr_apropxyrefresh - This enum defines
 * attributes required for MTK_NL80211_VENDOR_SUBCMD_SET_APPROXYREFRESH.
 * Information in these attributes is used to approxyrefresh
 * to driver from user application.
 *
 * @MTK_NL80211_VENDOR_ATTR_SET_APPROXYREFRESH: u8, enable/disable ap proxy refresh
 */
enum mtk_nl80211_vendor_attr_apropxyrefresh {
/* don't change the order or add anything between, this is ABI! */
	MTK_NL80211_VENDOR_ATTR_APPROXYREFRESH_INVALID = 0,

	MTK_NL80211_VENDOR_ATTR_SET_APPROXYREFRESH,

	__MTK_NL80211_VENDOR_ATTR_APPROXYREFRESH_LAST,
	MTK_NL80211_VENDOR_ATTR_APPROXYREFRESH_MAX =
	__MTK_NL80211_VENDOR_ATTR_APPROXYREFRESH_LAST - 1
};

#endif /* __MTK_VENDOR_NL80211_H */
