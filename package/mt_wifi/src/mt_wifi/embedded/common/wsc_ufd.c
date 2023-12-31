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
	wsc_ufd.c

	Abstract:

	Revision History:
	Who			When			What
*/

#include "rt_config.h"

#ifdef WSC_INCLUDED

static const RTMP_STRING *XML_DECLARE_START = "<?xml";
static const RTMP_STRING *XML_DECLARE_END = "?>";
static const RTMP_STRING *XML_SSID_START = "<ssid";
static const RTMP_STRING *XML_SSID_END = "</ssid>";
static const RTMP_STRING *XML_AUTH_START = "<authentication>";
static const RTMP_STRING *XML_AUTH_END = "</authentication>";
static const RTMP_STRING *XML_ENCR_START = "<encryption>";
static const RTMP_STRING *XML_ENCR_END = "</encryption>";
static const RTMP_STRING *XML_KEY_START = "<networkKey";
static const RTMP_STRING *XML_KEY_END = "</networkKey>";
static const RTMP_STRING *XML_KEY_INDEX_START = "<keyIndex>";
static const RTMP_STRING *XML_KEY_INDEX_END = "</keyIndex>";

static const RTMP_STRING *XML_GUID_MARK = "CFG_GUID";
static const RTMP_STRING *XML_AP_GUID_MARK = "CFG_AP_GUID";
static const RTMP_STRING *XML_SSID_MARK = "CFG_SSID";
static const RTMP_STRING *XML_AUTH_MARK = "CFG_AUTH";
static const RTMP_STRING *XML_ENCR_MARK = "CFG_ENCR";
static const RTMP_STRING *XML_KEY_MARK = "CFG_KEY";

static const RTMP_STRING *XML_TEMPLATE =
"<?xml version=\"1.0\"?>\n"
"<wirelessProfile>\n"
"	<config>\n"
"		<configId>CFG_GUID</configId>\n"
"		<configAuthorId>CFG_AP_GUID</configAuthorId>\n"
"		<configAuthor>Ralink WPS AP</configAuthor>\n"
"	</config>\n"
"	<ssid xml:space=\"preserve\">CFG_SSID</ssid>\n"
"	<connectionType>ESS</connectionType>\n"
"	<channel2Dot4>0</channel2Dot4>\n"
"	<channel5Dot0>0</channel5Dot0>\n"
"	<primaryProfile>\n"
"		<authentication>CFG_AUTH</authentication>\n"
"		<encryption>CFG_ENCR</encryption>\n"
"		<networkKey xml:space=\"preserve\">CFG_KEY</networkKey>\n"
"		<keyProvidedAutomatically>0</keyProvidedAutomatically>\n"
"		<ieee802Dot1xEnabled>0</ieee802Dot1xEnabled>\n"
"	</primaryProfile>\n"
"</wirelessProfile>\n";


static struct {
	RTMP_STRING *auth_str;
	USHORT	auth_type;
} *PWSC_UFD_AUTH_TYPE, WSC_UFD_AUTH_TYPE[] = {
	{"open", WSC_AUTHTYPE_OPEN},
	{"shared", WSC_AUTHTYPE_SHARED},
	{"WPA", WSC_AUTHTYPE_WPA},
	{"WPA2", WSC_AUTHTYPE_WPA2},
	{"WPAPSK", WSC_AUTHTYPE_WPAPSK},
	{"WPA2PSK", WSC_AUTHTYPE_WPA2PSK},
	{NULL,}
};

static struct {
	RTMP_STRING *encr_str;
	USHORT	encr_type;
} *PWSC_UFD_ENCR_TYPE, WSC_UFD_ENCR_TYPE[] = {
	{"none", WSC_ENCRTYPE_NONE},
	{"WEP", WSC_ENCRTYPE_WEP},
	{"TKIP", WSC_ENCRTYPE_TKIP},
	{"AES", WSC_ENCRTYPE_AES},
	{NULL,}
};

BOOLEAN	WscPassXmlDeclare(
	INOUT RTMP_STRING **pXmlData)
{
	RTMP_STRING *ptr;

	MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
		"======> WscPassXmlDeclare\n");

	ptr = rtstrstr(*pXmlData, (RTMP_STRING *)XML_DECLARE_START);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscPassXmlDeclare: missing XML Declare <?xml\n");
		return FALSE;
	}

	ptr = rtstrstr(*pXmlData, (RTMP_STRING *)XML_DECLARE_END);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"XML syntax error: missing XML Declare ?>\n");
		return FALSE;
	}

	(*pXmlData) = ptr + strlen(XML_DECLARE_END);

	MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
		"<====== WscPassXmlDeclare\n");

	return TRUE;
}


BOOLEAN WscGetXmlSSID(
	IN  RTMP_STRING *pXmlData,
	OUT PNDIS_802_11_SSID pSsid)
{
	RTMP_STRING *ptr, *pBuffer = pXmlData;

	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_SSID_START);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlSSID: missing <ssid\n");
		return FALSE;
	}

	pBuffer = ptr + strlen(XML_SSID_START);

	ptr = rtstrstr(pBuffer, ">");
	if (ptr)
		pBuffer = ptr + 1;

	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_SSID_END);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlSSID: missing </ssid>\n");
		return FALSE;
	}

	pSsid->SsidLength = (UINT)(ptr - pBuffer);
	RTMPZeroMemory(pSsid->Ssid, NDIS_802_11_LENGTH_SSID);
	if ((pSsid->SsidLength > 0) && (pSsid->SsidLength < 33)) {
		RTMPMoveMemory(pSsid->Ssid, pBuffer, pSsid->SsidLength);
	} else {
		pSsid->SsidLength = 0;
		return FALSE;
	}

	return TRUE;
}


BOOLEAN WscGetXmlAuth(
	IN  RTMP_STRING *pXmlData,
	OUT USHORT *pAuthType)
{
	RTMP_STRING *ptr, *pBuffer = pXmlData;
	RTMP_STRING AuthStr[10] = {0};
	UINT AuthStrLen = 0;

	*pAuthType = 0;
	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_AUTH_START);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlAuth: missing %s\n", XML_AUTH_START);
		return FALSE;
	}

	pBuffer = ptr + strlen(XML_AUTH_START);

	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_AUTH_END);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlAuth: missing %s\n", XML_AUTH_END);
		return FALSE;
	}

	AuthStrLen = (UINT)(ptr - pBuffer);
	if ((AuthStrLen > 0) && (AuthStrLen <= 10)) {
		RTMPMoveMemory(AuthStr, pBuffer, AuthStrLen);

		for (PWSC_UFD_AUTH_TYPE = WSC_UFD_AUTH_TYPE;
			PWSC_UFD_AUTH_TYPE->auth_str; PWSC_UFD_AUTH_TYPE++) {
			if (strcmp(AuthStr, PWSC_UFD_AUTH_TYPE->auth_str) == 0) {
				*pAuthType = PWSC_UFD_AUTH_TYPE->auth_type;
				return TRUE;
			}
		}
	}

	return FALSE;
}


BOOLEAN WscGetXmlEncr(
	IN  RTMP_STRING *pXmlData,
	OUT USHORT *pEncrType)
{
	RTMP_STRING *ptr, *pBuffer = pXmlData;
	RTMP_STRING EncrStr[10] = {0};
	UINT	EncrStrLen = 0;

	*pEncrType = 0;
	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_ENCR_START);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlEncr: missing %s\n", XML_ENCR_START);
		return FALSE;
	}

	pBuffer = ptr + strlen(XML_ENCR_START);

	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_ENCR_END);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlEncr: missing %s\n", XML_ENCR_END);
		return FALSE;
	}

	EncrStrLen = (UINT)(ptr - pBuffer);
	if ((EncrStrLen > 0) && (EncrStrLen <= 10)) {
		RTMPMoveMemory(EncrStr, pBuffer, EncrStrLen);

		for (PWSC_UFD_ENCR_TYPE = WSC_UFD_ENCR_TYPE;
		PWSC_UFD_ENCR_TYPE->encr_str; PWSC_UFD_ENCR_TYPE++) {
			if (strcmp(EncrStr, PWSC_UFD_ENCR_TYPE->encr_str) == 0) {
				*pEncrType = PWSC_UFD_ENCR_TYPE->encr_type;
				return TRUE;
			}
		}
	}

	return FALSE;
}


BOOLEAN WscGetXmlKey(
	IN  RTMP_STRING *pXmlData,
	OUT PUCHAR pKey,
	OUT PUSHORT pKeyLen)
{
	RTMP_STRING *ptr, *pBuffer = pXmlData;
	UINT	KeyLen = 0;

	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_KEY_START);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlKey: missing %s\n", XML_KEY_START);
		return FALSE;
	}

	pBuffer = ptr + strlen(XML_KEY_START);

	ptr = rtstrstr(pBuffer, ">");
	if (ptr)
		pBuffer = ptr + 1;

	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_KEY_END);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlKey: missing %s\n", XML_KEY_END);
		return FALSE;
	}

	KeyLen = (UINT)(ptr - pBuffer);
	if ((KeyLen >= 8) && (KeyLen <= 64)) {
		RTMPMoveMemory(pKey, pBuffer, KeyLen);
		*pKeyLen = KeyLen;
	} else {
		return FALSE;
	}

	return TRUE;
}


BOOLEAN WscGetXmlKeyIndex(
	IN  RTMP_STRING *pXmlData,
	OUT PUCHAR pKeyIndex)
{
	RTMP_STRING *ptr, *pBuffer = pXmlData;

	*pKeyIndex = 1;
	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_KEY_INDEX_START);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlKeyIndex: missing %s\n", XML_KEY_INDEX_START);
		return FALSE;
	}

	pBuffer = ptr + strlen(XML_KEY_INDEX_START);

	ptr = rtstrstr(pBuffer, (RTMP_STRING *)XML_KEY_INDEX_END);
	if (ptr == NULL) {
		MTWF_DBG(NULL, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscGetXmlKeyIndex: missing %s\n", XML_KEY_INDEX_END);
		return FALSE;
	}

	*pKeyIndex = *(--ptr) - 0x30;

	return TRUE;
}



BOOLEAN	WscReadProfileFromUfdFile(
	IN PRTMP_ADAPTER pAd,
	IN UCHAR ApIdx,
	IN RTMP_STRING *pUfdFileName)
{
	PWSC_CREDENTIAL pCredential = &pAd->ApCfg.MBSSID[ApIdx].wdev.WscControl.WscProfile.Profile[0];
	RTMP_OS_FS_INFO osFSInfo;
	RTMP_OS_FD file_r;
	ssize_t rv, fileLen = 0;
	RTMP_STRING *pXmlData = NULL;
	RTMP_STRING *ptmpXmlData = NULL;
	BOOLEAN RV = TRUE;
	char tempStr[64] = {0};

	if (pUfdFileName == NULL) {
		MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"--> %s: pUfdFileName is NULL\n", __func__);
		return FALSE;
	}

	RtmpOSFSInfoChange(&osFSInfo, TRUE);

	file_r = RtmpOSFileOpen(pUfdFileName, O_RDONLY, 0);
	if (IS_FILE_OPEN_ERR(file_r)) {
		MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"--> %s: Error opening file %s\n",
			__func__, pUfdFileName);
		RtmpOSFSInfoChange(&osFSInfo, FALSE);
		return FALSE;
	}

	while ((rv = RtmpOSFileRead(file_r, tempStr, 64)) > 0)
		fileLen += rv;

	os_alloc_mem(pAd, (UCHAR **)&pXmlData, fileLen+1);
	if (pXmlData == NULL) {
		RtmpOSFileClose(file_r);
		RtmpOSFSInfoChange(&osFSInfo, FALSE);
		MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"pXmlData mem alloc fail. (fileLen = %d)\n",
			(int)fileLen);
		return FALSE;
	}
	RTMPZeroMemory(pXmlData, fileLen+1);
	RtmpOSFileSeek(file_r, 0);
	rv = RtmpOSFileRead(file_r, (RTMP_STRING *)pXmlData, fileLen);
	RtmpOSFileClose(file_r);
	if (rv != fileLen) {
		MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"RtmpOSFileRead fail, fileLen = %d\n",
			(int)fileLen);
		RtmpOSFSInfoChange(&osFSInfo, FALSE);
		goto ReadErr;
	}

	RtmpOSFSInfoChange(&osFSInfo, FALSE);

	MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
		"WscReadProfileFromUfdFile\n");
	ptmpXmlData = pXmlData;
	if (WscPassXmlDeclare(&ptmpXmlData)) {
		if (WscGetXmlSSID(ptmpXmlData, &pCredential->SSID)) {
			MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
				"SSID = %s(%d)\n",
				pCredential->SSID.Ssid,
				pCredential->SSID.SsidLength);
		} else {
			RV = FALSE;
			goto FreeXmlData;
		}

		if (WscGetXmlAuth(ptmpXmlData, &pCredential->AuthType)) {
			MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
				"Credential.AuthType = 0x%04x\n",
				pCredential->AuthType);
		} else {
			RV = FALSE;
			goto FreeXmlData;
		}

		if (WscGetXmlEncr(ptmpXmlData, &pCredential->EncrType)) {
			MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
				"Credential.EncrType = 0x%04x\n",
				pCredential->EncrType);
		} else {
			RV = FALSE;
			goto FreeXmlData;
		}

		pCredential->KeyLength = 0;
		RTMPZeroMemory(pCredential->Key, 64);
		if (WscGetXmlKey(ptmpXmlData, pCredential->Key,
			&pCredential->KeyLength)) {
			MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
				"Credential.Key = %s (%d)\n",
				pCredential->Key, pCredential->KeyLength);
		} else {
			RV = FALSE;
			goto FreeXmlData;
		}

		/*
		*	If we cannot find keyIndex in .wfc file,
		*	use default value 1.
		*/
		if (WscGetXmlKeyIndex(ptmpXmlData, &pCredential->KeyIndex)) {
			MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
				"pCredential->KeyIndex = %d\n",
				pCredential->KeyIndex);
		}

		MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"WscReadProfileFromUfdFile OK\n");

		WscWriteConfToPortCfg(pAd,
		&pAd->ApCfg.MBSSID[ApIdx].wdev.WscControl,
		&pAd->ApCfg.MBSSID[ApIdx].wdev.WscControl.WscProfile.Profile[0],
		TRUE);

		pAd->WriteWscCfgToDatFile = ApIdx;

		RtmpOsTaskWakeUp(&(pAd->wscTask));

FreeXmlData:
		if (pXmlData)
			os_free_mem(pXmlData);

		return RV;
	}

ReadErr:
	if (pXmlData)
		os_free_mem(pXmlData);
	return FALSE;
}


BOOLEAN	WscWriteProfileToUfdFile(
	IN  PRTMP_ADAPTER pAd,
	IN  UCHAR ApIdx,
	IN  RTMP_STRING *pUfdFileName)
{
	PWSC_CTRL pWscControl = &pAd->ApCfg.MBSSID[ApIdx].wdev.WscControl;
	PWSC_CREDENTIAL pCredential = &pWscControl->WscProfile.Profile[0];
	RTMP_OS_FS_INFO osFSInfo;
	RTMP_OS_FD file_w;
	RTMP_STRING *offset, *pXmlTemplate = (RTMP_STRING *)XML_TEMPLATE;
	BOOLEAN	bFound = FALSE, bRtn = TRUE;
	UCHAR Guid[UUID_LEN_HEX];
	UCHAR Guid_Str[UUID_LEN_STR];

	if (pUfdFileName == NULL) {
		MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"--> %s: pUfdFileName is NULL\n", __func__);
		return FALSE;
	}

	RtmpOSFSInfoChange(&osFSInfo, TRUE);

	file_w = RtmpOSFileOpen(pUfdFileName, O_WRONLY|O_TRUNC|O_CREAT, 0);
	if (IS_FILE_OPEN_ERR(file_w)) {
		MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
			"--> %s: Error opening file %s\n",
			__func__, pUfdFileName);
		RtmpOSFSInfoChange(&osFSInfo, FALSE);
		return FALSE;
	}

	WscCreateProfileFromCfg(pAd, AP_MODE, pWscControl, &pWscControl->WscProfile);

	WscGenerateUUID(pAd, &Guid[0], &Guid_Str[0], ApIdx, TRUE, FALSE);

	offset = rtstrstr(pXmlTemplate, (RTMP_STRING *)XML_GUID_MARK);
	if (offset != NULL) {
		RtmpOSFileWrite(file_w, (RTMP_STRING *)pXmlTemplate, (int)(offset - pXmlTemplate));
		RtmpOSFileWrite(file_w, (RTMP_STRING *)&Guid_Str[0], (int)UUID_LEN_STR);
		pXmlTemplate = offset + strlen(XML_GUID_MARK);
	}

	offset = rtstrstr(pXmlTemplate, (RTMP_STRING *)XML_AP_GUID_MARK);
	if (offset != NULL) {
		RtmpOSFileWrite(file_w, (RTMP_STRING *)pXmlTemplate, (int)(offset - pXmlTemplate));
		RtmpOSFileWrite(file_w, (RTMP_STRING *)&pWscControl->Wsc_Uuid_Str[0], (int)UUID_LEN_STR);
		pXmlTemplate = offset + strlen(XML_AP_GUID_MARK);
	}

	offset = rtstrstr(pXmlTemplate, (RTMP_STRING *)XML_SSID_MARK);
	if (offset != NULL) {
		RtmpOSFileWrite(file_w, (RTMP_STRING *)pXmlTemplate, (int)(offset - pXmlTemplate));
		RtmpOSFileWrite(file_w, (RTMP_STRING *)&pCredential->SSID.Ssid[0], (int)pCredential->SSID.SsidLength);
		pXmlTemplate = offset + strlen(XML_SSID_MARK);
	}

	offset = rtstrstr(pXmlTemplate, (RTMP_STRING *)XML_AUTH_MARK);
	if (offset != NULL) {
		RtmpOSFileWrite(file_w, (RTMP_STRING *)pXmlTemplate, (int)(offset - pXmlTemplate));
		for (PWSC_UFD_AUTH_TYPE = WSC_UFD_AUTH_TYPE; PWSC_UFD_AUTH_TYPE->auth_str; PWSC_UFD_AUTH_TYPE++) {
			if (PWSC_UFD_AUTH_TYPE->auth_type == pCredential->AuthType) {
				RtmpOSFileWrite(file_w,
				(RTMP_STRING *)PWSC_UFD_AUTH_TYPE->auth_str,
				(int)strlen(PWSC_UFD_AUTH_TYPE->auth_str));
				bFound = TRUE;
				break;
			}
		}
		pXmlTemplate = offset + strlen(XML_AUTH_MARK);
		if (bFound == FALSE) {
			MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
				"--> %s: Unknow Auth Type(=%x)\n", __func__, pCredential->AuthType);
			bRtn = FALSE;
			goto out;
		}
	}

	offset = rtstrstr(pXmlTemplate, (RTMP_STRING *)XML_ENCR_MARK);
	if (offset != NULL) {
		bFound = FALSE;
		RtmpOSFileWrite(file_w, (RTMP_STRING *)pXmlTemplate, (int)(offset - pXmlTemplate));
		for (PWSC_UFD_ENCR_TYPE = WSC_UFD_ENCR_TYPE; PWSC_UFD_ENCR_TYPE->encr_str; PWSC_UFD_ENCR_TYPE++) {
			if (PWSC_UFD_ENCR_TYPE->encr_type == pCredential->EncrType) {
				RtmpOSFileWrite(file_w,
				(RTMP_STRING *)PWSC_UFD_ENCR_TYPE->encr_str,
				(int)strlen(PWSC_UFD_ENCR_TYPE->encr_str));
				bFound = TRUE;
			}
		}
		pXmlTemplate = offset + strlen(XML_ENCR_MARK);
		if (bFound == FALSE) {
			MTWF_DBG(pAd, DBG_CAT_SEC, CATSEC_WPS, DBG_LVL_INFO,
				"--> %s: Unknow Encr Type(=%x)\n",
				__func__, pCredential->EncrType);
			bRtn = FALSE;
			goto out;
		}
	}

	offset = rtstrstr(pXmlTemplate, (RTMP_STRING *)XML_KEY_MARK);
	if (offset != NULL) {
		if (pCredential->EncrType != WSC_ENCRTYPE_NONE) {
			RtmpOSFileWrite(file_w, (RTMP_STRING *)pXmlTemplate, (int)(offset - pXmlTemplate));
			RtmpOSFileWrite(file_w,
					(RTMP_STRING *)pCredential->Key,
					(int)pCredential->KeyLength);
			pXmlTemplate = offset + strlen(XML_KEY_MARK);
		} else {
			RtmpOSFileWrite(file_w, (RTMP_STRING *)XML_ENCR_END, (int)strlen(XML_ENCR_END));
			RtmpOSFileWrite(file_w, (RTMP_STRING *)"\n", (int)1);
			pXmlTemplate = offset + strlen(XML_KEY_MARK) + strlen(XML_KEY_END) + 1; /* 1: '\n' */
		}
	}
	RtmpOSFileWrite(file_w, (RTMP_STRING *)pXmlTemplate, (int)strlen(pXmlTemplate));

out:
	RtmpOSFileClose(file_w);
	RtmpOSFSInfoChange(&osFSInfo, FALSE);

	return bRtn;
}
#endif /* WSC_INCLUDED */
