#!/bin/sh /etc/rc.common

start() {
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mediatek/mt7981.dbdc.b0.dat)
    	iwpriv ra0 set "$kick"
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mediatek/mt7981.dbdc.b1.dat)
    	iwpriv rax0 set "$kick"
    	kick1=$(grep -e "KickStaRssiHigh=" /etc/wireless/mediatek/mt7981.dbdc.b0.dat)
    	iwpriv ra1 set "$kick1"
    	
    	ApCliEnable=$(grep -e "ApCliEnable=" /etc/wireless/mediatek/mt7981.dbdc.b0.dat)
    	ApCliEnable=${ApCliEnable//ApCliEnable=/}
    	if [ $ApCliEnable -eq 1 ]; then
    	ifconfig apcli0 up
    	ApCliBridge=$(grep -e "ApCliBridge=" /etc/wireless/mediatek/mt7981.dbdc.b0.dat)
    	ApCliBridge=${ApCliBridge//ApCliBridge=/}
    	if [ $ApCliBridge -eq 1 ]; then
    	brctl addif br-lan apcli0
    	else
    	ifconfig apcli0 up
    	brctl delif br-lan apcli0
    	fi
    	fi
    	
    	ApCliEnable=$(grep -e "ApCliEnable=" /etc/wireless/mediatek/mt7981.dbdc.b1.dat)
    	ApCliEnable=${ApCliEnable//ApCliEnable=/}
    	if [ $ApCliEnable -eq 1 ]; then
    	ifconfig apclix0 up
    	ApCliBridge=$(grep -e "ApCliBridge=" /etc/wireless/mediatek/mt7981.dbdc.b1.dat)
    	ApCliBridge=${ApCliBridge//ApCliBridge=/}
    	if [ $ApCliBridge -eq 1 ]; then
    	brctl addif br-lan apclix0
    	else
    	ifconfig apclix0 up
    	brctl delif br-lan apclix0
    	fi
    	fi
    	
    	FtSupport=$(grep -e "FtSupport=" /etc/wireless/mediatek/mt7981.dbdc.b1.dat)
    	FtSupport=${FtSupport//FtSupport=/}
    	if [ $FtSupport -eq 1 ]; then
    	/usr/sbin/mtkiappd -e br-lan -wi rax0 -wi ra0 &
    	else
    	killall mtkiappd
    	fi 	
}



