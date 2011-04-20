<head>

<!-- Sample Key Control NetCast Web UI by nicola_12345, changes by xeros -->

<!-- Source code released under GPL License -->

<title>OpenLGTV BCM</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<meta http-equiv="Content-Style-Type" content="text/css">
<meta http-equiv="Content-Script-Type" content="text/javascript">
<link rel="stylesheet" type="text/css" href="player/styles.css"/>
<link rel="stylesheet" type="text/css" href="css/keyboard.css"/>

<SCRIPT language="JavaScript" type="text/javascript" src="js/control.js"></script>
</head>
<body>
<IMG align="right" SRC="http://openlgtv.org.ru/wiki/openlgtv_logo.png" ALT="OpenLGTV BCM" style="position: relative; right: 30px; top: 30px;"/>
	<!-- div style="position: absolute; left: 5px; top: 480px;" -->
	<!-- div style="position: absolute; right: 10px; bottom: 100px;" -->
	<div style="position: absolute; right: 30px; bottom: 300px;">
	<Table id="Keyboard" name="Keyboard" class="Keyboard" Border=0 cellspacing=0 background="Images/Keyboard/keypad.png">
		<tr>
			<td border=0 height="31px" width="44px">
			<a id="c1" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="a">
				<img id="i1" src="Images/Keyboard/1n.png" alt="a" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c2" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="b">
				<img id="i2" src="Images/Keyboard/2n.png" alt="b" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c3" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="c">
				<img id="i3" src="Images/Keyboard/3n.png" alt="c" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c4" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="d">
				<img id="i4" src="Images/Keyboard/4n.png" alt="d" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c5" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="e">
				<img id="i5" src="Images/Keyboard/5n.png" alt="e" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c6" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="1">
				<img id="i6" src="Images/Keyboard/6n.png" alt="1" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c7" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="2">
				<img id="i7" src="Images/Keyboard/7n.png" alt="2" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c8" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="3">
				<img id="i8" src="Images/Keyboard/8n.png" alt="3" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
		</tr>
		<tr>
			<td><a id="c9" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="f">
				<img id="i9" src="Images/Keyboard/9n.png" alt="f" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c10" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="g">
				<img id="i10" src="Images/Keyboard/10n.png" alt="g" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c11" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="h">
				<img id="i11" src="Images/Keyboard/11n.png" alt="h" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c12" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="i">
				<img id="i12" src="Images/Keyboard/12n.png" alt="i" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c13" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="j">
				<img id="i13" src="Images/Keyboard/13n.png" alt="j" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c14" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="4">
				<img id="i14" src="Images/Keyboard/14n.png" alt="4" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c15" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="5">
				<img id="i15" src="Images/Keyboard/15n.png" alt="5" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c16" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="6">
				<img id="i16" src="Images/Keyboard/16n.png" alt="6" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
		</tr>
		<tr>
			<td><a id="c17" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="k">
				<img id="i17" src="Images/Keyboard/17n.png" alt="k" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c18" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="l">
				<img id="i18" src="Images/Keyboard/18n.png" alt="l" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c19" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="m">
				<img id="i19" src="Images/Keyboard/19n.png" alt="m" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c20" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="n">
				<img id="i20" src="Images/Keyboard/20n.png" alt="n" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c21" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="o">
				<img id="i21" src="Images/Keyboard/21n.png" alt="o" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c22" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="7">
				<img id="i22" src="Images/Keyboard/22n.png" alt="7" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c23" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="8">
				<img id="i23" src="Images/Keyboard/23n.png" alt="8" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c24" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="9">
				<img id="i24" src="Images/Keyboard/24n.png" alt="9" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
		</tr>
		<tr>
			<td><a id="c25" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="p">
				<img id="i25" src="Images/Keyboard/25n.png" alt="p" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c26" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="q">
				<img id="i26" src="Images/Keyboard/26n.png" alt="q" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c27" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="r">
				<img id="i27" src="Images/Keyboard/27n.png" alt="r" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c28" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="s">
				<img id="i28" src="Images/Keyboard/28n.png" alt="s" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c29" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="t">
				<img id="i29" src="Images/Keyboard/29n.png" alt="t" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c30" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name=".">
				<img id="i30" src="Images/Keyboard/30n.png" alt="." style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c31" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="0">
				<img id="i31" src="Images/Keyboard/31n.png" alt="0" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c32" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="@">
				<img id="i32" src="Images/Keyboard/32n.png" alt="@" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
		</tr>
		<tr>
			<td><a id="c33" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="u">
				<img id="i33" src="Images/Keyboard/33n.png" alt="u" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c34" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="v">
				<img id="i34" src="Images/Keyboard/34n.png" alt="v" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c35" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="w">
				<img id="i35" src="Images/Keyboard/35n.png" alt="w" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c36" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="x">
				<img id="i36" src="Images/Keyboard/36n.png" alt="x" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c37" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="y">
				<img id="i37" src="Images/Keyboard/37n.png" alt="y" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c38" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="z">
				<img id="i38" src="Images/Keyboard/38n.png" alt="z" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c39" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="/">
				<img id="i39" src="Images/Keyboard/39n.png" alt="/" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c40" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="_">
				<img id="i40" src="Images/Keyboard/40n.png" alt="_" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
		</tr>
		<tr>
			<td><a id="c41" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="-">
				<img id="i41" src="Images/Keyboard/41n.png" alt="-" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c42" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="+">
				<img id="i42" src="Images/Keyboard/42n.png" alt="+" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c43" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name=":">
				<img id="i43" src="Images/Keyboard/43n.png" alt=":" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c44" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="=">
				<img id="i44" src="Images/Keyboard/44n.png" alt="=" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c45" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="&">
				<img id="i45" src="Images/Keyboard/45n.png" alt="&" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c46" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name=" ">
				<img id="i46" src="Images/Keyboard/46n.png" alt="spc" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c47" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name="'">
				<img id="i47" src="Images/Keyboard/47n.png" alt="'" style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
			<td><a id="c48" onKeyPress="javascript:setCurrent(this);return false" onClick="javascript:setCurrent(this);DirectWriteKey(this.name)" href="#" name=",">
				<img id="i48" src="Images/Keyboard/48n.png" alt="," style="text-decoration:none; color:white" border=0 height="31px" width="44px">
				</a>
			</td>
		</tr>
	</Table>
	</div>
	<!-- div style="position: absolute; left: 400px; top: 480px;" -->
	<div style="position: absolute; right: 80px; bottom: 100px;">
		<Table Border=0 cellspacing=0>
			<tr>
				<td><img src="Images/Keyboard/tapkey.png" align="middle"></td>
			</tr>
		</Table>
	</div>
	<!-- HTML only table prototype for keypad
	<div style="position: absolute; left: 400px; top: 480px; background-color: white">
		<Table Border=1 cellspacing=10>
			<tr align="center">
				<td>1<br/>.,?</td>
				<td>2<br/>ABC</td>
				<td>3<br/>DEF</td>
			</tr><tr align="center">
				<td>4<br/>GHI</td>
				<td>5<br/>JKL</td>
				<td>6<br/>MNO</td>
			</tr><tr align="center">
				<td>7<br/>PQRS</td>
				<td>8<br/>TUV</td>
				<td>9<br/>WXYZ</td>
			</tr><tr align="center">
				<td>*<br/></td>
				<td>0<br/>space</td>
				<td>#<br/></td>
			</tr>
		</Table>
	</div> -->
	<div id="footer" class="footer">
		<ul>
			<!-- li class="blank"><span></span></li -->
			<a onClick="javascript:PrevControl();" href="#" style="text-decoration:none; color:white"><li class="red"><span></span>Prev Ctrl</li></a>
			<a onClick="javascript:NextControl();" href="#" style="text-decoration:none; color:white"><li class="green"><span></span>Next Ctrl</li></a>
			<a onClick="javascript:SaveForm();" href="#" style="text-decoration:none; color:white"><li class="yellow"><span></span>Save</li></a>
			<a onClick="javascript:BackSpace();" href="#" style="text-decoration:none; color:white"><li class="blue"><span></span>BackSpace</li></a>
			<a onClick="window.NetCastBack();" href="#" style="text-decoration:none; color:white"><li id="return_bt" class="return"><span></span>Back</li></a>
			<li class="exit"><span></span>Exit</li>
		</ul>
	</div>