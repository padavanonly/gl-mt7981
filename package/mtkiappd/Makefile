#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mtkiappd
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_CONFIG_DEPENDS := \
	CONFIG_MTK_CHIP_MT7615E_DBDC \
	CONFIG_PACKAGE_mtkiappd_DUAL_BAND

include $(INCLUDE_DIR)/package.mk

define Package/mtkiappd
	SECTION:=net
	CATEGORY:=Network
	TITLE:=MTK 802.11f supporting daemon
	SUBMENU:=Wireless
endef

define Package/mtkiappd/description
	Mtkiappd is an optional user space component for MT76xx SoftAP driver.
endef

define Package/mtkiappd/config
config PACKAGE_mtkiappd_DUAL_BAND
        bool "dual band"
		depends on MTK_CHIP_MT7615E
		default y if TARGET_ramips_mt7621_DEVICE_phicomm_k2p
		default n
endef

ifeq ($(CONFIG_PACKAGE_mtkiappd_DUAL_BAND),y)
	WIRELESS_IOCTL_PARAM:=-wi ra0 -wi rax0
else
	WIRELESS_IOCTL_PARAM:=-wi ra0 -wi rai0
endif

define Package/mtkiappd/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_DIR) $(1)/usr/share/mtkiappd

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mtkiappd $(1)/usr/sbin/
	$(INSTALL_DATA) ./files/firewall.include $(1)/usr/share/mtkiappd/
endef

$(eval $(call BuildPackage,mtkiappd))
