#include "iwinfo.h"
#include "iwinfo_wext.h"

#include <inttypes.h>

typedef union _MACHTTRANSMIT_SETTING {
	struct  {
		unsigned short  MCS:6;  // MCS
		unsigned short  rsv:1;
		unsigned short  BW:2;   //channel bandwidth 20MHz or 40 MHz
		unsigned short  ShortGI:1;
		unsigned short  STBC:1; //SPACE
		unsigned short  eTxBF:1;
		unsigned short  iTxBF:1;
		unsigned short  MODE:3; // Use definition MODE_xxx.
	} field;
	unsigned short      word;
} MACHTTRANSMIT_SETTING;

typedef struct _RT_802_11_MAC_ENTRY {
	unsigned char           ApIdx;
	unsigned char           Addr[6];
	unsigned char           Aid;
	unsigned char           Psm;     // 0:PWR_ACTIVE, 1:PWR_SAVE
	unsigned char           MimoPs;  // 0:MMPS_STATIC, 1:MMPS_DYNAMIC, 3:MMPS_Enabled
	signed char             AvgRssi0;
	signed char             AvgRssi1;
	signed char             AvgRssi2;
	signed char             AvgRssi3;
	unsigned int            ConnectedTime;
	MACHTTRANSMIT_SETTING   TxRate;
	unsigned int            LastRxRate;
	short                   StreamSnr[3];
	short                   SoundingRespSnr[3];
#if 0
	short                   TxPER;
	short                   reserved;
#endif
} RT_802_11_MAC_ENTRY;

#define MAX_NUMBER_OF_MAC               554

typedef struct _RT_802_11_MAC_TABLE {
	unsigned long            Num;
	RT_802_11_MAC_ENTRY      Entry[MAX_NUMBER_OF_MAC]; //MAX_LEN_OF_MAC_TABLE = 32
} RT_802_11_MAC_TABLE;

#define SIOCIWFIRSTPRIV	0x8BE0
#define RTPRIV_IOCTL_GET_MAC_TABLE_STRUCT	(SIOCIWFIRSTPRIV + 0x1F)
#define RTPRIV_IOCTL_SET                 	(SIOCIWFIRSTPRIV + 0x02)
#define RTPRIV_IOCTL_GSITESURVEY            (SIOCIWFIRSTPRIV + 0x0D)

struct mtk_phy_feature {
	const char *name;
	int hwmodelist;
	int htmodelist;
};

static struct mtk_phy_feature mtk_phy_feature[7] = {};

static inline int wext_ioctl(const char *ifname, int cmd, struct iwreq *wrq)
{
	strncpy(wrq->ifr_name, ifname, IFNAMSIZ);
	return iwinfo_ioctl(cmd, wrq);
}

static int mtk_probe(const char *ifname)
{
	struct mtk_phy_feature *f = mtk_phy_feature;

	while (f->name) {
		if (strstr(ifname, f->name))
			return true;
		f++;
	}

	return false;
}

static void mtk_close(void)
{
	/* Nop */
}

static int mtk_get_mode(const char *ifname, int *buf)
{
	return wext_ops.mode(ifname, buf);
}

static int mtk_get_ssid(const char *ifname, char *buf)
{
	struct iwreq wrq = {};

	wrq.u.essid.pointer = buf;
	wrq.u.essid.length  = IW_ESSID_MAX_SIZE;

	if(wext_ioctl(ifname, SIOCGIWESSID, &wrq) >= 0)
		return 0;

	return -1;
}

static int mtk_get_bssid(const char *ifname, char *buf)
{
	return wext_ops.bssid(ifname, buf);
}

static int mtk_get_bitrate(const char *ifname, int *buf)
{
	return wext_ops.bitrate(ifname, buf);
}

static int mtk_get_channel(const char *ifname, int *buf)
{
	return wext_ops.channel(ifname, buf);
}

static int mtk_get_center_chan1(const char *ifname, int *buf)
{
	/* Not Supported */
	return -1;
}

static int mtk_get_center_chan2(const char *ifname, int *buf)
{
	/* Not Supported */
	return -1;
}

static int mtk_get_frequency(const char *ifname, int *buf)
{
	int channel;
	int freq;

	if (wext_ops.channel(ifname, &channel))
		return -1;

	if (channel < 36) {
		if (channel == 14)
			return 2484;
		freq = 2407 + channel * 5;
	} else {
		if (channel >= 182 && channel <= 196)
			freq = 4000 + channel * 5;
		else
			freq = 5000 + channel * 5;
	}

	*buf = freq;
	return 0;
}

static int mtk_get_txpower(const char *ifname, int *buf)
{
	if (wext_ops.txpower(ifname, buf))
		return -1;

	*buf = iwinfo_mw2dbm(*buf);

	return 0;
}

static int mtk_get_signal(const char *ifname, int *buf)
{
	return wext_ops.signal(ifname, buf);
}

static int mtk_get_noise(const char *ifname, int *buf)
{
	return wext_ops.noise(ifname, buf);
}

static int mtk_get_quality(const char *ifname, int *buf)
{
	return wext_ops.quality(ifname, buf);
}

static int mtk_get_quality_max(const char *ifname, int *buf)
{
	return wext_ops.quality_max(ifname, buf);
}

static int mtk_get_assoclist(const char *ifname, char *buf, int *len)
{
	struct iwreq wrq = {};
	RT_802_11_MAC_TABLE *table;
	int i;

	table = calloc(1, sizeof(RT_802_11_MAC_TABLE));
	if (!table)
		return -1;

	wrq.u.data.pointer = (caddr_t)table;
	wrq.u.data.length  = sizeof(RT_802_11_MAC_TABLE);

	if (wext_ioctl(ifname, RTPRIV_IOCTL_GET_MAC_TABLE_STRUCT, &wrq) < 0) {
		free(table);
		return -1;
	}

	*len = 0;

	for (i = 0; i < table->Num; i++) {
		RT_802_11_MAC_ENTRY *pe = &(table->Entry[i]);
		struct iwinfo_assoclist_entry *e = (struct iwinfo_assoclist_entry *)buf + i;

		memcpy(e->mac, pe->Addr, 6);

		*len += sizeof(struct iwinfo_assoclist_entry);
	}

	free(table);
	return 0;
}

static int mtk_get_txpwrlist(const char *ifname, char *buf, int *len)
{
	struct iwinfo_txpwrlist_entry entry;
	int i;

	for(i = 0; i < 21; i++) {
		entry.dbm = i;
		entry.mw  = iwinfo_mw2dbm(i);
		memcpy(&buf[i * sizeof(entry)], &entry, sizeof(entry));
	}

	*len = i * sizeof(entry);

	return 0;
}

static int mtk_get_scanlist_dump(const char *ifname, int index, char *data, size_t len)
{
	struct iwreq wrq = {};

	snprintf(wrq.ifr_name, sizeof(wrq.ifr_name), "%s", ifname);
    snprintf(data, len, "%d", index);

	wrq.u.data.pointer = data;
    wrq.u.data.length = len;

	return iwinfo_ioctl(RTPRIV_IOCTL_GSITESURVEY, &wrq);
}

struct scan_data_offset {
	int offset;
	int width;
};

enum {
	SCAN_DATA_CH,
	SCAN_DATA_SSID,
	SCAN_DATA_BSSID,
	SCAN_DATA_SECURITY,
	SCAN_DATA_RSSI,
	SCAN_DATA_NT,
	SCAN_DATA_SSID_LEN,
	SCAN_DATA_MAX
};

static int mtk_get_scanlist(const char *ifname, char *buf, int *len)
{
	struct iwinfo_scanlist_entry *e = (struct iwinfo_scanlist_entry *)buf;
	static char data[20 * 1024 + 1];
	int offsets[SCAN_DATA_MAX];
	char cmd[128];
	int index = 0;
	int total = -1;
	char *pos;

	*len = 0;

	if (!strcmp(ifname, "mt798111") || !strcmp(ifname, "mt7628"))
		ifname = "ra0";
	else if (!strcmp(ifname, "mt798112"))
		ifname = "rax0";

	sprintf(cmd, "iwpriv %s set SiteSurvey=", ifname);
	system(cmd);

	sleep(8);

	while (1) {
		if (mtk_get_scanlist_dump(ifname, index, data, sizeof(data)))
			return -1;

		sscanf(data, "\nTotal=%d", &total);

		strtok(data, "\n");
		pos = strtok(NULL, "\n");

		offsets[SCAN_DATA_CH] = strstr(pos, "Ch ") - pos;
		offsets[SCAN_DATA_SSID] = strstr(pos, "SSID ") - pos;
		offsets[SCAN_DATA_BSSID] = strstr(pos, "BSSID ") - pos;
		offsets[SCAN_DATA_SECURITY] = strstr(pos, "Security ") - pos;
		offsets[SCAN_DATA_RSSI] = strstr(pos, "Rssi") - pos;
		offsets[SCAN_DATA_NT] = strstr(pos, "NT") - pos;
		offsets[SCAN_DATA_SSID_LEN] = strstr(pos, "SSID_Len") - pos;

		while (1) {
			struct iwinfo_crypto_entry *crypto = &e->crypto;
			const char *security;
			uint8_t *mac = e->mac;
			int signal;
			int ssid_len;

			pos = strtok(NULL, "\n");
			if (!pos)
				break;

			sscanf(pos, "%d", &index);

			if (strncmp(pos + offsets[SCAN_DATA_NT], "In", 2))
				continue;;

			security = pos + offsets[SCAN_DATA_SECURITY];
			if (!strstr(security, "PSK") && !strstr(security, "OPEN"))
				continue;

			memset(crypto, 0, sizeof(struct iwinfo_crypto_entry));

			if (strstr(security, "PSK")) {
				crypto->enabled = true;

				if (strstr(security, "WPAPSK")) {
					crypto->wpa_version |= 1 << 0;
					crypto->auth_suites |= IWINFO_KMGMT_PSK;
				}

				if (strstr(security, "WPA2PSK")) {
					crypto->wpa_version |= 1 << 1;
					crypto->auth_suites |= IWINFO_KMGMT_PSK;
				}

				if (strstr(security, "WPAP3SK")) {
					crypto->wpa_version |= 1 << 2;
					crypto->auth_suites |= IWINFO_KMGMT_SAE;
				}
			}

			e->mode = IWINFO_OPMODE_MASTER;

			sscanf(pos + offsets[SCAN_DATA_CH], "%"SCNu8, &e->channel);
			sscanf(pos + offsets[SCAN_DATA_RSSI] + 1, "%d", &signal);
			e->signal = -signal + 0x100;

			sscanf(pos + offsets[SCAN_DATA_BSSID], "%02"SCNx8":%02"SCNx8":%02"SCNx8":%02"SCNx8":%02"SCNx8":%02"SCNx8"",
				mac + 0, mac + 1, mac + 2, mac + 3, mac + 4, mac + 5);

			sscanf(pos + offsets[SCAN_DATA_SSID_LEN], "%d", &ssid_len);
			memcpy(e->ssid, pos + offsets[SCAN_DATA_SSID], ssid_len);

			*len += sizeof(struct iwinfo_scanlist_entry);
			e++;

			if (index + 1 == total)
				break;
		}

		if (index + 1 == total)
			break;
	}

	return 0;
}

static int mtk_get_freqlist(const char *ifname, char *buf, int *len)
{
	if (!strcmp(ifname, "mt798111") || !strcmp(ifname, "mt7628"))
		ifname = "ra0";
	else if (!strcmp(ifname, "mt798112"))
		ifname = "rax0";
	return wext_ops.freqlist(ifname, buf, len);
}

static int mtk_get_country(const char *ifname, char *buf)
{
	sprintf(buf, "00");
	return 0;
}

static int mtk_get_countrylist(const char *ifname, char *buf, int *len)
{
	/* Stub */
	return -1;
}

static int mtk_get_hwmodelist(const char *ifname, int *buf)
{
	struct mtk_phy_feature *f = mtk_phy_feature;

	while (f->name) {
		if (strstr(ifname, f->name)) {
			*buf = f->hwmodelist;
			return 0;
		}
		f++;
	}

	return -1;
}

static int mtk_get_htmodelist(const char *ifname, int *buf)
{
	struct mtk_phy_feature *f = mtk_phy_feature;

	while (f->name) {
		if (strstr(ifname, f->name)) {
			*buf = f->htmodelist;
			return 0;
		}
		f++;
	}

	return -1;
}

static int mtk_get_htmode(const char *ifname, int *buf)
{
	return -1;
}

static int mtk_get_encryption(const char *ifname, char *buf)
{
	/* No reliable crypto info in wext */
	return -1;
}

static int mtk_get_phyname(const char *ifname, char *buf)
{
	if (strstr(ifname, "rax") || strstr(ifname, "apclix"))
		strcpy(buf, "rax0");
	else if (strstr(ifname, "ra") || strstr(ifname, "apcli"))
		strcpy(buf, "ra0");
	else
		return -1;

	return 0;
}

static int mtk_get_mbssid_support(const char *ifname, int *buf)
{
	/* No multi bssid support atm */
	return -1;
}

static int mtk_get_hardware_id(const char *ifname, char *buf)
{
	return wext_ops.hardware_id(ifname, buf);
}

static int mtk_get_hardware_name(const char *ifname, char *buf)
{
	sprintf(buf, "MediaTek");
	return 0;
}

static int mtk_get_txpower_offset(const char *ifname, int *buf)
{
	/* Stub */
	*buf = 0;
	return -1;
}

static int mtk_get_frequency_offset(const char *ifname, int *buf)
{
	/* Stub */
	*buf = 0;
	return -1;
}

const struct iwinfo_ops mtk_ops = {
	.name             = "mtk",
	.probe            = mtk_probe,
	.channel          = mtk_get_channel,
	.center_chan1     = mtk_get_center_chan1,
	.center_chan2     = mtk_get_center_chan2,
	.frequency        = mtk_get_frequency,
	.frequency_offset = mtk_get_frequency_offset,
	.txpower          = mtk_get_txpower,
	.txpower_offset   = mtk_get_txpower_offset,
	.bitrate          = mtk_get_bitrate,
	.signal           = mtk_get_signal,
	.noise            = mtk_get_noise,
	.quality          = mtk_get_quality,
	.quality_max      = mtk_get_quality_max,
	.mbssid_support   = mtk_get_mbssid_support,
	.hwmodelist       = mtk_get_hwmodelist,
	.htmodelist       = mtk_get_htmodelist,
	.htmode           = mtk_get_htmode,
	.mode             = mtk_get_mode,
	.ssid             = mtk_get_ssid,
	.bssid            = mtk_get_bssid,
	.country          = mtk_get_country,
	.hardware_id      = mtk_get_hardware_id,
	.hardware_name    = mtk_get_hardware_name,
	.encryption       = mtk_get_encryption,
	.phyname          = mtk_get_phyname,
	.assoclist        = mtk_get_assoclist,
	.txpwrlist        = mtk_get_txpwrlist,
	.scanlist         = mtk_get_scanlist,
	.freqlist         = mtk_get_freqlist,
	.countrylist      = mtk_get_countrylist,
	.close            = mtk_close
};

static void __attribute__((constructor)) init()
{
	char buf[100] = "";
	FILE *fp;

	fp = fopen("/etc/config/wireless", "r");
	if (!fp)
		return;

	fread(buf, 1, sizeof(buf) - 1, fp);
	fclose(fp);

	if (strstr(buf, "mt7628")) {
		int hwmodelist = IWINFO_80211_B | IWINFO_80211_G | IWINFO_80211_N;
		int htmodelist = IWINFO_HTMODE_HT20 | IWINFO_HTMODE_HT40;

		mtk_phy_feature[0].name = "mt7628";
		mtk_phy_feature[0].hwmodelist = hwmodelist;
		mtk_phy_feature[0].htmodelist = htmodelist;

		mtk_phy_feature[1].name = "ra";
		mtk_phy_feature[1].hwmodelist = hwmodelist;
		mtk_phy_feature[1].htmodelist = htmodelist;

		mtk_phy_feature[2].name = "apcli";
		mtk_phy_feature[2].hwmodelist = hwmodelist;
		mtk_phy_feature[2].htmodelist = htmodelist;
	} else if (strstr(buf, "mt798111") || strstr(buf, "mt798611")) {
		int hwmodelist = IWINFO_80211_A | IWINFO_80211_N | IWINFO_80211_AC | IWINFO_80211_AX;
		int htmodelist = IWINFO_HTMODE_HT20 | IWINFO_HTMODE_HT40
					| IWINFO_HTMODE_VHT20 | IWINFO_HTMODE_VHT40 | IWINFO_HTMODE_VHT80 | IWINFO_HTMODE_VHT160
					| IWINFO_HTMODE_HE20 | IWINFO_HTMODE_HE40 | IWINFO_HTMODE_HE80 | IWINFO_HTMODE_HE160;

		if (strstr(buf, "mt798111"))
			mtk_phy_feature[0].name = "mt798112";
		else
			mtk_phy_feature[0].name = "mt798612";

		mtk_phy_feature[0].hwmodelist = hwmodelist;
		mtk_phy_feature[0].htmodelist = htmodelist;

		mtk_phy_feature[1].name = "rax";
		mtk_phy_feature[1].hwmodelist = hwmodelist;
		mtk_phy_feature[1].htmodelist = htmodelist;

		mtk_phy_feature[2].name = "apclix";
		mtk_phy_feature[2].hwmodelist = hwmodelist;
		mtk_phy_feature[2].htmodelist = htmodelist;

		hwmodelist = IWINFO_80211_B | IWINFO_80211_G | IWINFO_80211_N | IWINFO_80211_AX;
		htmodelist = IWINFO_HTMODE_HT20 | IWINFO_HTMODE_HT40
						| IWINFO_HTMODE_HE20 | IWINFO_HTMODE_HE40;

		if (strstr(buf, "mt798111"))
			mtk_phy_feature[3].name = "mt798111";
		else
			mtk_phy_feature[3].name = "mt798611";

		mtk_phy_feature[3].hwmodelist = hwmodelist;
		mtk_phy_feature[3].htmodelist = htmodelist;

		mtk_phy_feature[4].name = "ra";
		mtk_phy_feature[4].hwmodelist = hwmodelist;
		mtk_phy_feature[4].htmodelist = htmodelist;

		mtk_phy_feature[5].name = "apcli";
		mtk_phy_feature[5].hwmodelist = hwmodelist;
		mtk_phy_feature[5].htmodelist = htmodelist;
	}
}
