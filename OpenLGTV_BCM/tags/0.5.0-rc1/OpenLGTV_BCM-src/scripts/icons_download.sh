#!/bin/sh
# links_images_preload.sh script by xeros
# Source code released under GPL License

# TODO: store last properly downloaded and unpacked icons archive hash
echo "OpenLGTV_BCM-INFO: icons_download.sh: running..."

icons_dir="/home/netcast_icons/www"
ilink1="http://svn.openlgtv.org.ru/OpenLGTV_BCM/tags/0.5.0-rc1/addons/images/www/icons-SVN20120426.zip"
ilink2="http://addon.vpscript.com/icons-SVN20120426.zip"
ilink3="http://dl.dropbox.com/u/43758310/icons.zip"
ilink4="http://smarttv.net46.net/icons.zip"
ilink5="http://smarttv.abcz8.com/icons.zip"
ilink6="http://smarttv.awardspace.info/icons.xxx"
imd5="422fe11f1151752d716c10c6ca16b999"
imd5_last="`cat "$icons_dir/icons.md5" 2>/dev/null`"
useragent="Mozilla/5.0 (X11; Linux i686; rv:12.0) Gecko/20100101 Firefox/12.0"
ilinks_count=6
unpacked_ok=0
try_count=0

if [ "$imd5" != "$imd5_last" ]
then
    echo "OpenLGTV_BCM-INFO: icons_download.sh: OpenLGTV BCM upgrade/downgrade detected - downloading currently supported icons..."
    while [ "$unpacked_ok" -eq 0 -a "$try_count" -lt 10 ]
    do
	PING_OK=""
	while [ -z "$PING_OK" -a "$try_count" -lt 10 ]
	do
	    try_count=$((${try_count}+1))
	    rnd=$RANDOM
	    let "rnd %= $ilinks_count"
	    case $rnd in
		0) ilink="$ilink1";;
		1) ilink="$ilink2";;
		2) ilink="$ilink3";;
		3) ilink="$ilink4";;
		4) ilink="$ilink5";;
		*) ilink="$ilink6";;
	    esac
	    ihost="`echo $ilink | awk -F/ '{print $3}'`"
	    # ugly workaround for disabled pings on dl.dropbox.com
	    [ "$ihost" = "dl.dropbox.com" ] && ihost="dropbox.com"
	    echo "OpenLGTV_BCM-INFO: icons_download.sh: trying to use download link: $ilink"
	    [ -n "$ihost" ] && PING_OK="`ping -4 -c 1 $ihost 2>/dev/null | grep '64 bytes from'`"
	    sleep 3
	done
	cur_dir=`pwd`
	mkdir -p "$icons_dir"
	cd "$icons_dir"
	wget -q -c -U "$useragent" "$ilink" -O /tmp/icons.zip
	md5s="`md5sum /tmp/icons.zip`"
	if [ "${md5s:0:32}" != "$imd5" ]
	then
	    echo "OpenLGTV_BCM-ERROR: icons_download.sh: icons downloaded but zip file checksum mismatch: \"${md5s:0:32}\" != \"$imd5\", retrying to download again..."
	    #exit 1
	else
	    echo "OpenLGTV_BCM-INFO: icons_download.sh: icons downloaded and checksum is OK, unzipping..."
	    unzip -o /tmp/icons.zip && unpacked_ok=1 || echo "OpenLGTV_BCM-ERROR: icons_download.sh: unzipping failed, retrying to download again..."
	fi
	rm -f /tmp/icons.zip
    done
fi
[ "$unpacked_ok" = "1" ] && echo "$imd5" > "$icons_dir/icons.md5"
cd "$cur_dir"
echo "OpenLGTV_BCM-INFO: icons_download.sh: exit"
