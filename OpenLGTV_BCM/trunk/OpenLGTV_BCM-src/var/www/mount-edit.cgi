#!/usr/bin/haserl
# mount-edit.cgi by xeros, nicola_12345
# Source code released under GPL License
content-type: text/html

<html>
<? include/keycontrol.cgi.inc ?>
	<div style="position: absolute; left: 10px; top: 10px; width:880px; font-size:16px;">
		<form id="URL" name="URL" action="mount-edit.cgi" method="GET">
			<? 
			    if [ "$FORM_type" = "etherwake" ]
			    then
				input_file=/mnt/user/cfg/ethwaketab
				export pagename="Ether Wake"
				log_info="$pagename"
			    else
				input_file=/mnt/user/cfg/ndrvtab
				export pagename="Network Shares"
				log_info="NetShare mounts"
			    fi
			    include/header_links.cgi.inc
			?>
			<div id="textOnly" style="background-color:white;height:50px;">
				<div style="position: relative; left: 5px; top: 0px;">
					<?
					    [ "$FORM_type" != "etherwake" ] && echo "<br /><center><b>Note: Relative destination mount paths need FAT/NTFS formated USB storage device.</b></center><br />" && automntname="AutoMount"
					    [ "$FORM_type" = "etherwake" ]  && echo "<br /><center><b>Wake remotely machines which support WakeOnLan feature</b></center><br />" && automntname="AutoWake on boot"
					?>
				</div>
			</div>

<?
# 0|1#cifs|nfs#[url]#NetShare(mount path on USB stick)#[options]#[username]#[password] - up to 0.5.0-beta1
# 0|1#cifs|nfs#[url]#NetShare(mount path on USB stick)#[options]#[username]#[password]#[0|1] - changed by 0.5.0-beta2 (added field for dir listing cache)
# 0|1#cifs|nfs#[url]#NetShare(mount path on USB stick)#[options]#[username]#[password]#[0|1]#[pings]# - changed by 0.5.0-beta4 (added field with number of pings to try)

id="$FORM_id"

if [ -n "$FORM_qURL" -a -n "$FORM_action" -a -n "$id" ]
then
    automount=0
    precache=0
    fs_type="$FORM_radio1"
    [ "$FORM_check1" = "automount" ] && automount=1
    [ "$FORM_check2" = "precache"  ] && precache=1
    cp -f ${input_file} ${input_file}.bck
    if [ "$FORM_qPath" != "" ]
    then
	qPath="$FORM_qPath"
    else
	[ "$FORM_type" != "etherwake" ] && qPath="NetShare"
    fi
    if [ "$FORM_type" = "etherwake" -a -z "$FORM_qPassw" ]
    then
	# try to resolve MAC from IP or hostname if MAC was not specified
	[ -n "$FORM_qUser"  ] && FORM_qPassw=`arping -fc 3 "$FORM_qUser" | grep -m1 Unicast | cut -d" " -f5 | tr -d '[]'`
	[ -z "$FORM_qPassw" ] && IP_MAC=`arping -fc 3 "$FORM_qURL" | grep -m1 Unicast | awk '{print $4 "|" $5}' | tr -d '[]'` && FORM_qPassw="${IP_MAC#*|}"
	[ -z "$FORM_qUser" -a -n "$IP_MAC" ] && FORM_qUser="${IP_MAC%|*}"
    fi
    [ "$fs_type" = "nfs"  -a "${FORM_qOpts:0:4}" = "user"   ] && FORM_qOpts="" # workaround for changing fs_type without changing options
    [ "$fs_type" = "cifs" -a "${FORM_qOpts:0:6}" = "nolock" ] && FORM_qOpts=""
    [ -z "$FORM_qOpts" -a "$FORM_type" != "etherwake" ] && FORM_qOpts=`grep "$fs_type" /etc/default/mountopts | cut -d\| -f2`
    if [ "`cat ${input_file} | wc -l`" -lt "$id" ]
    then
	if [ "$FORM_type" = "etherwake" ]
	then
	    # (autowake on boot:0/1)#(hostname)#[ip.address]#(MAC:address)#[pa:ss:wo:rd]#[options]#
	    echo "$automount#$FORM_qURL#$FORM_qUser#$FORM_qPassw#$qPath##" >> ${input_file}
	else
	    echo "$automount#$fs_type#$FORM_qURL#$qPath#$FORM_qOpts#$FORM_qUser#$FORM_qPassw#$precache#$FORM_qPin#" >> ${input_file}
	fi
    else
	if [ "$FORM_type" = "etherwake" ]
	then
	    sed -i -e "$id s?.*?$automount#$FORM_qURL#$FORM_qUser#$FORM_qPassw#$qPath##?" ${input_file}
	else
	    sed -i -e "$id s?.*?$automount#$fs_type#$FORM_qURL#$qPath#$FORM_qOpts#$FORM_qUser#$FORM_qPassw#$precache#$FORM_qPin#?" ${input_file}
	fi
    fi
fi

if [ -f "${input_file}" -a "$id" != "" ]
then
    [ "$id" -le "`cat ${input_file} | wc -l`" ] && ndrv="`head -n $FORM_id ${input_file} | tail -n 1`"
    ndrv_2="${ndrv#*\#}"
    ndrv_3="${ndrv_2#*\#}"
    ndrv_4="${ndrv_3#*\#}"
    ndrv_5="${ndrv_4#*\#}"
    ndrv_6="${ndrv_5#*\#}"
    ndrv_7="${ndrv_6#*\#}"
    ndrv_8="${ndrv_7#*\#}"
    ndrv_9="${ndrv_8#*\#}"
    # INFO: workaround for old type of config, with less fields
    [ "$ndrv_9" = "$ndrv_8" ] && ndrv_9=""
    automount="${ndrv%%#*}"
    if [ "$FORM_type" = "etherwake" ]
    then
	ew_autowake="${ndrv%%#*}"
	ew_name="${ndrv_2%%#*}"
	ew_ip="${ndrv_3%%#*}"
	ew_mac="${ndrv_4%%#*}"
	ew_pass="${ndrv_5%%#*}"
	ew_opt="${ndrv_6%%#*}"
	# ugly variables but make the code changes minimal
	src="${ew_name}"
	uname="${ew_ip}"
	pass="${ew_mac}"
	dst="${ew_pass}"
    else
	fs_type="${ndrv_2%%#*}"
	src="${ndrv_3%%#*}"
	dst="${ndrv_4%%#*}"
	opt="${ndrv_5%%#*}"
	uname="${ndrv_6%%#*}"
	pass="${ndrv_7%%#*}"
	precache="${ndrv_8%%#*}"
	pings="${ndrv_9%%#*}"
    fi
fi

mount_err_code=0

if [ "$FORM_mount" = "1" ]
then
    echo "OpenLGTV_BCM-INFO: WebUI: NetShare mounts - trying to mount NetShare id: $id by WebUI..." >> /var/log/OpenLGTV_BCM.log
    /etc/rc.d/rc.mount-netshare WebUI_MOUNT "$id" >> /var/log/OpenLGTV_BCM.log 2>&1
    export mount_err_code="$?"
fi

if [ "$FORM_wake" = "1" ]
then
    echo "OpenLGTV_BCM-INFO: WebUI: EtherWake - trying to wake id: $id by WebUI..." >> /var/log/OpenLGTV_BCM.log
    /etc/rc.d/rc.ether-wake WebUI_WAKE "$id" >> /var/log/OpenLGTV_BCM.log 2>&1
    export mount_err_code="$?"
fi

[ "$mount_err_code" -ne "0" ] && export mounting_error=1
[ "$dst" = "" -a "$FORM_type" != "etherwake" ] && dst="NetShare"

if [ "$FORM_umount" = "1" ]
then
    #share_path="`grep -m 1 "$dst " /proc/mounts | cut -d' ' -f2`"
    share_path="`cat /proc/mounts | cut -d' ' -f2 | grep -m 1 "$dst\$"`"
    echo "OpenLGTV_BCM-INFO: WebUI: NetShare mounts - trying to unmount NetShare: $share_path id: $id by WebUI..." >> /var/log/OpenLGTV_BCM.log
    umount "$share_path" >> /var/log/OpenLGTV_BCM.log 2>&1
fi

[ "$FORM_type" = "" ] && FORM_type=netshare

?>
			<center>
			    <div id="link11Parent" style="background-color:white;height:40px;">
				<?
				    action=mount
				    #if [ -z "`egrep "^[^ ]* $dst " /proc/mounts`" ]
				    if [ -z "`cat /proc/mounts | cut -d' ' -f2 | grep -m 1 "$dst\$"`" ]
				    then
					if [ -f "${input_file}" ]
					then
					    input_rest="value=\"Mount\" style=\"width:100px\""
					else
					    input_rest="value=\"Mount button: You need to save first to be able to mount\" style=\"width:600px\" disabled"
					fi
				    else
					action=umount
					input_rest="value=\"Unmount\" style=\"width:400px\""
				    fi
				    [ "$FORM_type" = "etherwake" ] && action=wake && input_rest="value=\"Wake\" style=\"width:100px\""
				    echo -n "<input type=\"button\" id=\"link11\" onKeyPress=\"javascript:window.location='mount-edit.cgi?${action}=1&id=${id}&type=${FORM_type}';\" onClick=\"javascript:window.location='mount-edit.cgi?${action}=1&id=${id}&type=${FORM_type}';\" ${input_rest} />"
				?>
			    </div>
			</center>
			<div id="txtURLParent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 7px; height:23;">
					<? [ "$FORM_type" = "etherwake" ] && echo "Name:" || echo "URL:" ?>
				</div>
				<div style="position: relative; left: 100px; top: -22px;">
				    <input id="txtURL" name="qURL" type="textarea" style="width:750px" onFocus='javascript:PageElements[currElementIndex].focused=true;' onBlur='javascript:PageElements[currElementIndex].focused=false;' value='<? echo "$src" ?>'/>
				</div>
			</div>
			<div id="txtUserParent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 7px; height:23;">
					<? [ "$FORM_type" = "etherwake" ] && echo "IP address:" || echo "Username:" ?>
				</div>
				<div style="position: relative; left: 100px; top: -22px;">
					<input id="txtUser" name="qUser" type="textarea" style="width:500px" onFocus='javascript:PageElements[currElementIndex].focused=true;' onBlur='javascript:PageElements[currElementIndex].focused=false;' value='<? echo "$uname" ?>'/>
				</div>
			</div>
			<div id="txtPasswParent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 7px; height:23;">
					<? [ "$FORM_type" = "etherwake" ] && echo "MAC:" || echo "Password:" ?>
				</div>
				<div style="position: relative; left: 100px; top: -22px;">
					<input id="txtPassw" name="qPassw" type="textarea" style="width:500px" onFocus='javascript:PageElements[currElementIndex].focused=true;' onBlur='javascript:PageElements[currElementIndex].focused=false;' value='<? echo "$pass" ?>'/>
				</div>
			</div>
			<div id="txtPathParent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 7px; height:23;">
					<? [ "$FORM_type" = "etherwake" ] && echo "Password:" || echo "Mount path:" ?>
				</div>
				<div style="position: relative; left: 100px; top: -22px;">
					<input id="txtPath" name="qPath" type="textarea" style="width:500px" onFocus='javascript:PageElements[currElementIndex].focused=true;' onBlur='javascript:PageElements[currElementIndex].focused=false;' value='<? echo "$dst" ?>'/>
				</div>
			</div>
			<? [ "$FORM_type" = "etherwake" ] && echo "<!--" ?>
			<div id="txtPinParent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 7px; height:23;">
					<? echo "Tries/Pings:" ?>
				</div>
				<div style="position: relative; left: 100px; top: -22px;">
					<input id="txtPin" name="qPin" type="textarea" style="width:50px; text-align: center;" onFocus='javascript:PageElements[currElementIndex].focused=true;' onBlur='javascript:PageElements[currElementIndex].focused=false;' value='<? echo "$pings" ?>'/>
				</div>
			</div>
			<div id="txtOptsParent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 7px; height:23;">
					<? echo "Options:" ?>
				</div>
				<div style="position: relative; left: 100px; top: -22px;">
					<input id="txtOpts" name="qOpts" type="textarea" style="width:750px" onFocus='javascript:PageElements[currElementIndex].focused=true;' onBlur='javascript:PageElements[currElementIndex].focused=false;' value='<? echo "$opt" ?>'/>
				</div>
			</div>
			<div id="radio1Parent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 5px;">
					Network Protocol: 
					<?
					    [ "$fs_type" = "cifs" ] && cifs_ck="checked" || nfs_ck="checked"
					    echo "<input type='radio' name='radio1' value='cifs' $cifs_ck> CIFS"
					    echo "<input type='radio' name='radio1' value='nfs' $nfs_ck> NFS"
					?>
					&nbsp; [ 'Options' field is only for tuning mount options! ]
				</div>
			</div>
			<? [ "$FORM_type" = "etherwake" ] && echo "-->" ?>
			<div id="check1Parent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 5px;">
				<?
				    [ "$automount" = "1" ] && amnt_ck="checked"
				    echo "<input type='checkbox' name='check1' value='automount' $amnt_ck> $automntname"
				?>
				</div>
			</div>
			<? [ "$FORM_type" = "etherwake" ] && echo "<!--" ?>
			<div id="check2Parent" style="background-color:white;height:40px; font-size:16px;">
				<div style="position: relative; left: 5px; top: 5px;">
				<?
				    [ "$precache" = "1" ] && pcache_ck="checked"
				    echo "<input type='checkbox' name='check2' value='precache' $pcache_ck> Precache directory listing for media player (do not enable when there is no invisible dirs problem)"
				?>
				</div>
			</div>
			<? 
			    [ "$FORM_type" = "etherwake" ] && echo "-->"
			    echo "<input type='hidden' name='type' value='$FORM_type'><input type='hidden' name='action' value='$FORM_type'>"
			?>
			<input type="hidden" name="save" value="1">
			<? echo "<input type='hidden' name='id' value='$id'>" ?>
			<!-- div id="textOnly" style="background-color:white;height:64px;" -->
			<div id="textOnly" style="background-color:white;height:44px;">
				<div style="position: relative; left: 5px; top: 5px;">
				    <?
					if [ "$FORM_save" = "1" ]
					then
					    echo "OpenLGTV_BCM-INFO: WebUI: $log_info file: ${input_file} changed by WebUI..." >> /var/log/OpenLGTV_BCM.log
					    echo '<center><font size="+3" color="red"><b><span id="spanSAVED">SETTINGS SAVED !!!</span></b></font></center>'
					else
					    if [ "$mounting_error" = "1" ]
					    then
						echo "<center><font size=\"+2\" color=\"red\"><b>Mounting ERROR with error code: $mount_err_code !!!</b></font></center>"
					    else
						echo '<center><font size="+2" color="red"><b>Remember to save settings before trying to use mount button</b></font></center>'
					    fi
					fi
				    ?>
				</div>
			</div>
			<!-- div id="legendParent" style="position: absolute; left: 620px; top: 290px; width: 230px; height: 110px; background-color: #434343;" -->
			<div id="legendParent" style="position: absolute; left: 620px; top: 290px; width: 230px; height: 40px; background-color: white">
			    <div id="legend" style="position: relative; left: 25px; top: 5px;">
				<img src="Images/Keyboard/pause_button.png" align="top"><font size="+2" style="color: black;" id="caps"><b> CapsLock</b></font>
			    </div>
			</div>
		</form>
	</div>	
</body>
</html>
