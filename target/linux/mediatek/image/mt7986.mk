KERNEL_LOADADDR := 0x48080000

define Device/mt7986a-ax6000-spim-nor-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-spim-nor-rfb
  DEVICE_DTS := mt7986a-spim-nor-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-nor-rfb
endef
TARGET_DEVICES += mt7986a-ax6000-spim-nor-rfb

define Device/mt7986a-ax6000-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax6000-spim-nand-rfb

define Device/mt7986a-ax8400-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax8400-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax8400-spim-nand-rfb

define Device/mt7986a-ax6000-snfi-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-snfi-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-snfi-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-snfi-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax6000-snfi-nand-rfb

define Device/mt7986a-ax6000-emmc-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-emmc-rfb
  DEVICE_DTS := mt7986a-emmc-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-emmc-rfb
  DEVICE_PACKAGES := mkf2fs e2fsprogs blkid blockdev losetup kmod-fs-ext4 \
		     kmod-mmc kmod-fs-f2fs kmod-fs-vfat kmod-nls-cp437 \
		     kmod-nls-iso8859-1
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax6000-emmc-rfb

define Device/mt7986a-ax7800-emmc-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax7800-emmc-rfb
  DEVICE_DTS := mt7986a-emmc-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-emmc-rfb
  DEVICE_PACKAGES := mkf2fs e2fsprogs blkid blockdev losetup kmod-fs-ext4 \
		     kmod-mmc kmod-fs-f2fs kmod-fs-vfat kmod-nls-cp437 \
		     kmod-nls-iso8859-1
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax7800-emmc-rfb

define Device/mt7986a-ax6000-2500wan-spim-nor-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-2500wan-spim-nor-rfb
  DEVICE_DTS := mt7986a-2500wan-spim-nor-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-2500wan-nor-rfb
endef
TARGET_DEVICES += mt7986a-ax6000-2500wan-spim-nor-rfb

define Device/mt7986a-ax6000-2500wan-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-2500wan-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-2500wan-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-2500wan-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax6000-2500wan-spim-nand-rfb

define Device/mt7986a-ax6000-2500wan-gsw-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-2500wan-gsw-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-2500wan-gsw-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-2500wan-gsw-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax6000-2500wan-gsw-spim-nand-rfb

define Device/mt7986a-ax6000-2500wan-sd-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax6000-2500wan-sd-rfb
  DEVICE_DTS := mt7986a-2500wan-sd-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-2500wan-sd-rfb
  DEVICE_PACKAGES := mkf2fs e2fsprogs blkid blockdev losetup kmod-fs-ext4 \
		     kmod-mmc kmod-fs-f2fs kmod-fs-vfat kmod-nls-cp437 \
		     kmod-nls-iso8859-1
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax6000-2500wan-sd-rfb

define Device/mt7986a-ax8400-2500wan-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax8400-2500wan-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-2500wan-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-2500wan-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax8400-2500wan-spim-nand-rfb

define Device/mt7986a-ax7800-spim-nor-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax7800-spim-nor-rfb
  DEVICE_DTS := mt7986a-spim-nor-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-nor-rfb
endef
TARGET_DEVICES += mt7986a-ax7800-spim-nor-rfb

define Device/mt7986a-ax7800-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax7800-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax7800-spim-nand-rfb

define Device/mt7986a-ax7800-2500wan-spim-nor-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax7800-2500wan-spim-nor-rfb
  DEVICE_DTS := mt7986a-2500wan-spim-nor-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-2500wan-nor-rfb
endef
TARGET_DEVICES += mt7986a-ax7800-2500wan-spim-nor-rfb

define Device/mt7986a-ax7800-2500wan-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986a-ax7800-2500wan-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986a-2500wan-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986a-2500wan-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986a-ax7800-2500wan-spim-nand-rfb

define Device/mt7986b-ax6000-spim-nor-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-spim-nor-rfb
  DEVICE_DTS := mt7986b-spim-nor-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-nor-rfb
endef
TARGET_DEVICES += mt7986b-ax6000-spim-nor-rfb

define Device/mt7986b-ax6000-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986b-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986b-ax6000-spim-nand-rfb

define Device/mt7986b-ax6000-snfi-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-snfi-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986b-snfi-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-snfi-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986b-ax6000-snfi-nand-rfb

define Device/mt7986b-ax6000-emmc-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-emmc-rfb
  DEVICE_DTS := mt7986b-emmc-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-emmc-rfb
  DEVICE_PACKAGES := mkf2fs e2fsprogs blkid blockdev losetup kmod-fs-ext4 \
		     kmod-mmc kmod-fs-f2fs kmod-fs-vfat kmod-nls-cp437 \
		     kmod-nls-iso8859-1
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986b-ax6000-emmc-rfb

define Device/mt7986b-ax6000-2500wan-spim-nor-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-2500wan-spim-nor-rfb
  DEVICE_DTS := mt7986b-2500wan-spim-nor-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-nor-rfb
endef
TARGET_DEVICES += mt7986b-ax6000-2500wan-spim-nor-rfb

define Device/mt7986b-ax6000-2500wan-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-2500wan-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986b-2500wan-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-2500wan-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986b-ax6000-2500wan-spim-nand-rfb

define Device/mt7986b-ax6000-2500wan-gsw-spim-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-2500wan-gsw-spim-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986b-2500wan-gsw-spim-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-2500wan-gsw-spim-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986b-ax6000-2500wan-gsw-spim-nand-rfb

define Device/mt7986b-ax6000-2500wan-snfi-nand-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-2500wan-snfi-nand-rfb (SPI-NAND,UBI)
  DEVICE_DTS := mt7986b-2500wan-snfi-nand-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-2500wan-snfi-snand-rfb
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986b-ax6000-2500wan-snfi-nand-rfb

define Device/mt7986b-ax6000-2500wan-sd-rfb
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := mt7986b-ax6000-2500wan-sd-rfb
  DEVICE_DTS := mt7986b-2500wan-sd-rfb
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986b-2500wan-sd-rfb
  DEVICE_PACKAGES := mkf2fs e2fsprogs blkid blockdev losetup kmod-fs-ext4 \
		     kmod-mmc kmod-fs-f2fs kmod-fs-vfat kmod-nls-cp437 \
		     kmod-nls-iso8859-1
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mt7986b-ax6000-2500wan-sd-rfb

define Device/mediatek_mt7986-fpga
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := MTK7986 FPGA
  DEVICE_DTS := mt7986-fpga
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  IMAGE/sysupgrade.bin := append-kernel | pad-to 256k | \
       append-rootfs | pad-rootfs | append-metadata
endef
TARGET_DEVICES += mediatek_mt7986-fpga

define Device/mediatek_mt7986-fpga-ubi
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := MTK7986 FPGA (UBI)
  DEVICE_DTS := mt7986-fpga-ubi
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := mediatek,mt7986-fpga,ubi
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  IMAGE_SIZE := 65536k
  KERNEL_IN_UBI := 1
  IMAGES += factory.bin
  IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef
TARGET_DEVICES += mediatek_mt7986-fpga-ubi

define Device/xiaomi_redmi-router-ax6000-uboot
   DEVICE_VENDOR := Xiaomi
   DEVICE_MODEL := Redmi Router AX6000 (uboot layout)
   DEVICE_DTS := mt7986a-xiaomi-redmi-router-ax6000-uboot
   DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
   DEVICE_PACKAGES :=luci-app-mtk l1profile wireless-tools kmod-conninfra kmod-warp kmod-mt_wifi ipv6helper kmod-mediatek_hnat bash autocore-arm mtkhnat_util kmod-leds-ws2812b
   UBINIZE_OPTS := -E 5
   BLOCKSIZE := 128k
   PAGESIZE := 2048
   KERNEL_IN_UBI := 1
   IMAGES := factory.bin sysupgrade.bin
   IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
   IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
 endef
 TARGET_DEVICES += xiaomi_redmi-router-ax6000-uboot

define Device/xiaomi_redmi-router-ax6000
   DEVICE_VENDOR := Xiaomi
   DEVICE_MODEL := Redmi Router AX6000
   DEVICE_DTS := mt7986a-xiaomi-redmi-router-ax6000
   DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
   DEVICE_PACKAGES :=luci-app-mtk l1profile wireless-tools kmod-conninfra kmod-warp kmod-mt_wifi ipv6helper kmod-mediatek_hnat bash autocore-arm mtkhnat_util kmod-leds-ws2812b
   UBINIZE_OPTS := -E 5
   BLOCKSIZE := 128k
   PAGESIZE := 2048
   IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
 endef
 TARGET_DEVICES += xiaomi_redmi-router-ax6000
 
 define Device/tplink_tl-common
   DEVICE_VENDOR := TP-Link
   DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
   UBINIZE_OPTS := -E 5
   BLOCKSIZE := 128k
   PAGESIZE := 2048
   KERNEL_IN_UBI := 1
   IMAGES := factory.bin sysupgrade.bin
   IMAGE/factory.bin := append-ubi | check-size $$$$(IMAGE_SIZE)
   IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
endef

define Device/tplink_tl-xdr6086
   DEVICE_MODEL := TL-XDR6086
   DEVICE_DTS := mt7986a-tl-xdr6086
   $(call Device/tplink_tl-common)
endef
TARGET_DEVICES += tplink_tl-xdr6086

define Device/tplink_tl-xdr6088
   DEVICE_MODEL := TL-XDR6088
   DEVICE_DTS := mt7986a-tl-xdr6088
   $(call Device/tplink_tl-common)
endef
TARGET_DEVICES += tplink_tl-xdr6088
