#!/bin/sh
# Core network modules
#?modprobe mii.ko
modprobe usbnet.ko
# Pegasus network chipset module
modprobe pegasus.ko
# Asix network chipset module
modprobe asix.ko
# MCS7830 network chipset module
modprobe mcs7830.ko
# DM9601 network chipset module
modprobe dm9601.ko

# CDROM filesystem modules
#modprobe cdrom.ko
#modprobe isofs.ko
#modprobe sr_mod.ko
# CIFS/Samba filesystem module with max buffer size 127Kbyte
#modprobe cifs.ko CIFSMaxBufSize=130048
modprobe cifs.ko
# EXT2 filesystem module
#modprobe ext2.ko
# Journaling layer for EXT3 filesystem
#modprobe jbd.ko
# EXT3 filesystem module
#modprobe ext3.ko
# NFS filesystem modules
#modprobe sunrpc.ko
#modprobe lockd.ko
#modprobe nfs.ko

# USB2Serial and mini_fo modules
#modprobe usbserial.ko
#modprobe pl2303.ko
#modprobe mini_fo.ko
