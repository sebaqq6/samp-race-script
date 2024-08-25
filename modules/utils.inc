stock form()
{
	new frm[64];
	format(frm, 64, ""COL_RED"»"COL_GREEN"»"COL_WHITE"");
	return frm;
}


stock nick(p, escape = false)
{
	new n[24];
	GetPlayerName(p, n, 24);
	if(escape) mysql_escape_string(n, n);
	return n;
}

stock playerip(p, escape = false)
{
	new n[24];
	GetPlayerIp(p, n, 24);
	if(escape) mysql_escape_string(n, n);
	return n;
}

native gpci(playerid, serial [], len);
stock serial(p, escape = false)
{
	new n[64];
	gpci(p,  n, 64);
	if(escape) mysql_escape_string(n, n);
	return n;
}

stock country(p, escape = false)
{
	new n[256];
	GetPlayerCountry(p, n);
	if(admin(p) == 4) format(n, 256, "Nevermind");
	if(escape) mysql_escape_string(n, n);
	return n;
}


stock KickEx(playerid, admin, reason[], message = true)
{
	if(message)
	{
		if(admin == -1)
		{
			SendClientMessageToAllEN(0xFF0000AA, "|KICK| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"SYSTEM"COL_WHITE" | Reason: %s.", nick(playerid), reason);
			SendClientMessageToAllPL(0xFF0000AA, "|KICK| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"SYSTEM"COL_WHITE" | Powód: %s.", nick(playerid), reason);
		}
		else
		{
			SendClientMessageToAllEN(0xFF0000AA, "|KICK| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Reason: %s", nick(playerid), nick(admin), reason);
			SendClientMessageToAllPL(0xFF0000AA, "|KICK| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Powód: %s", nick(playerid), nick(admin), reason);
		}
	}
	printf("|KICK| %s | Reason: %s", nick(playerid), reason);
	return SetTimerEx("KickExRun", 30, false, "d", playerid);
}
forward KickExRun(playerid); 
public  KickExRun(playerid) return Kick(playerid);

stock SendClientMessageEx(playerid, color, const text[], {Float, _}:...)
{
	static
	args,
	str[256];
    /*
    *  Custom function that uses #emit to format variables into a string.
    *  This code is very fragile; touching any code here will cause crashing!
    */
    if ((args = numargs()) == 3)
    {
    	format(str, 256, "%s", text);
    	SendClientMessage(playerid, color, str);
    }
    else
    {
    	while (--args >= 3)
    	{
            #emit LCTRL 5
            #emit LOAD.alt args
            #emit SHL.C.alt 2
            #emit ADD.C 12
            #emit ADD
            #emit LOAD.I
            #emit PUSH.pri
    	}
        #emit PUSH.S text
        #emit PUSH.C 256
        #emit PUSH.C str
        #emit PUSH.S 8
        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4
    	SendClientMessage(playerid, color, str);
        #emit RETN
    }
    return 1;
}


stock SendClientMessageToAllEx(color, const text[], {Float, _}:...)
{
    static
    args,
    str[256];
    /*
    *  Custom function that uses #emit to format variables into a string.
    *  This code is very fragile; touching any code here will cause crashing!
    */
    if ((args = numargs()) == 2)
    {
        SendClientMessageToAll(color, text);
    }
    else
    {
        while (--args >= 2)
        {
            #emit LCTRL 5
            #emit LOAD.alt args
            #emit SHL.C.alt 2
            #emit ADD.C 12
            #emit ADD
            #emit LOAD.I
            #emit PUSH.pri
        }
        #emit PUSH.S text
        #emit PUSH.C 256
        #emit PUSH.C str
        #emit LOAD.S.pri 8
        #emit ADD.C 4
        #emit PUSH.pri
        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4
        SendClientMessageToAll(color, str);
        #emit RETN
    }
    return 1;
}

stock SendClientMessageToAllPL(color, const text[], {Float, _}:...)
{
    static
    args,
    str[256];
    /*
    *  Custom function that uses #emit to format variables into a string.
    *  This code is very fragile; touching any code here will cause crashing!
    */
    if ((args = numargs()) == 2)
    {
        for(new p; p <= GetPlayerPoolSize(); p++)
        {
        	if(polak(p)) SendClientMessage(p, color, text);
        }
    }
    else
    {
        while (--args >= 2)
        {
            #emit LCTRL 5
            #emit LOAD.alt args
            #emit SHL.C.alt 2
            #emit ADD.C 12
            #emit ADD
            #emit LOAD.I
            #emit PUSH.pri
        }
        #emit PUSH.S text
        #emit PUSH.C 256
        #emit PUSH.C str
        #emit LOAD.S.pri 8
        #emit ADD.C 4
        #emit PUSH.pri
        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4
        for(new p; p <= GetPlayerPoolSize(); p++)
        {
        	if(polak(p)) SendClientMessage(p, color, str);
        }
        #emit RETN
    }
    return 1;
}

stock SendClientMessageToAllEN(color, const text[], {Float, _}:...)
{
    static
    args,
    str[256];
    /*
    *  Custom function that uses #emit to format variables into a string.
    *  This code is very fragile; touching any code here will cause crashing!
    */
    if ((args = numargs()) == 2)
    {
        for(new p; p <= GetPlayerPoolSize(); p++)
        {
        	if(!polak(p)) SendClientMessage(p, color, text);
        }
    }
    else
    {
        while (--args >= 2)
        {
            #emit LCTRL 5
            #emit LOAD.alt args
            #emit SHL.C.alt 2
            #emit ADD.C 12
            #emit ADD
            #emit LOAD.I
            #emit PUSH.pri
        }
        #emit PUSH.S text
        #emit PUSH.C 256
        #emit PUSH.C str
        #emit LOAD.S.pri 8
        #emit ADD.C 4
        #emit PUSH.pri
        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4
        for(new p; p <= GetPlayerPoolSize(); p++)
        {
        	if(!polak(p)) SendClientMessage(p, color, str);
        }
        #emit RETN
    }
    return 1;
}

stock PowiadomOOCEx(user, const text[], {Float, _}:...)
{
    static
    args,
    str[256];
    /*
    *  Custom function that uses #emit to format variables into a string.
    *  This code is very fragile; touching any code here will cause crashing!
    */
    if ((args = numargs()) == 2)
    {
        PowiadomOOC(user, text);
    }
    else
    {
        while (--args >= 2)
        {
            #emit LCTRL 5
            #emit LOAD.alt args
            #emit SHL.C.alt 2
            #emit ADD.C 12
            #emit ADD
            #emit LOAD.I
            #emit PUSH.pri
        }
        #emit PUSH.S text
        #emit PUSH.C 256
        #emit PUSH.C str
        #emit LOAD.S.pri 8
        #emit ADD.C 4
        #emit PUSH.pri
        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4
        PowiadomOOC(user, str);
        #emit RETN
    }
    return 1;
}

stock VehicleDriverID(vehicleid)
{
	for (new i; i <= GetPlayerPoolSize(); i++)
	{
		if ((IsPlayerConnected(i)) && (GetPlayerVehicleID(i)==vehicleid) && (GetPlayerState(i)==2))  return i;
	}
	return -1;
}

stock IsVehicleInUse(vehicleid) 
{
	new vdid = VehicleDriverID(vehicleid);
	if(vdid != -1)
	{
		return 1;
	}
	return 0;
}

stock admin(playerid) return sgracz[playerid][adminlvl];

stock spawned(playerid) return GetPVarInt(playerid, "Spawned");
stock spawnedset(playerid, val) SetPVarInt(playerid, "Spawned", val);

stock login(playerid)
{
	if(GetPlayerVirtualWorld(playerid) > 499 || !IsPlayerConnected(playerid)) return 0;
	return 1;
}

stock loginset(playerid, val)
{
	if(val) SetPlayerVirtualWorld(playerid, 0);
	else SetPlayerVirtualWorld(playerid, 500+playerid);
	return 1;
}


stock POnline()
{
	new x;
	for (new i; i <= GetPlayerPoolSize(); i++)
	{
		if(login(i)) x++;
	}
	return x;
}

stock PFinished()
{
	new x;
	for (new i; i <= GetPlayerPoolSize(); i++)
	{
		if(login(i) && tgracz[i][ukonczyl]) x++;
	}
	return x;
}

stock GetVehicleSpeed(vehicleid, checkz = false)
{
	if(!vehicleid) return 0;
	new Float:Vx, Float:Vy, Float:Vz;
	GetVehicleVelocity(vehicleid, Vx, Vy, Vz);
	new Float:rtn;
	if(!checkz)
	{
		rtn = floatsqroot(floatpower(Vx*100*Vx,2) + floatpower(Vy*100*Vy,2));
	}
	else
	{
		rtn = floatsqroot(floatpower(Vx*100*Vx,2) + floatpower(Vy*100*Vy,2) + floatpower(Vz*100*Vz,2));
	}
	return floatround(rtn);
}

stock Float:GetDistanceBetweenPoints(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2) return VectorSize(x1-x2, y1-y2, z1-z2);

forward Freeze(playerid, tog);
public  Freeze(playerid, tog) return TogglePlayerControllable(playerid, tog);

stock GetScorePos(poz)
{
	switch(poz)
	{
		case 0..1: return 6;
		case 2: return 5;
		case 3: return 4;
		case 4: return 3;
		case 5: return 2; 
		default: return 1;
	}

	return 1;
}

stock SetScore(playerid, scr)
{
	SetPlayerScore(playerid, scr);
	mq_format("UPDATE `players` SET `score`='%d' WHERE `id`='%d'", GetPlayerScore(playerid), sgracz[playerid][uID]);
	mq_send("QueryScore");
	return 1;
}

stock FixVehicle(playerid)
{
	tgracz[playerid][vHP] = 1000.0;
	tgracz[playerid][cheat0_p] = gettime()+5;
	SetTimerEx("FixVehFin", 100, false, "d", playerid);
	return 1;
}

forward FixVehFin(playerid);
public FixVehFin(playerid)
{
	new vid = GetPlayerVehicleID(playerid);
	SetVehicleHealth(vid, tgracz[playerid][vHP]);
	RepairVehicle(vid);
	return 1;
}

stock GetXYInBackOfPlayer(const playerid, &Float:xx, &Float:yy, const Float:distance)
{
	new Float:aa;
	GetPlayerPos(playerid, xx, yy, aa);
	GetPlayerFacingAngle(playerid, aa);
	if(IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleZAngle(GetPlayerVehicleID(playerid),aa);
	}
	xx -= (distance * floatsin(-aa, degrees));
	yy -= (distance * floatcos(-aa, degrees));
	return 1;
}

stock DestroyObjWeap(playerid)
{
	new o = tgracz[playerid][o_weap];
	if(o_flag[o] == F_WEAP)
	{
		DestroyDynamicObject(tgracz[playerid][o_weap]);
		o_flag[o] = F_NONE;
	}
	return 1;
}

encode_tires(tires1, tires2, tires3, tires4) 
{
	return tires1 | (tires2 << 1) | (tires3 << 2) | (tires4 << 3);
}

stock GetDynamicObjectModel(oid)
{
	if(IsValidDynamicObject(oid))
	{
		return Streamer_GetIntData(STREAMER_TYPE_OBJECT, oid, E_STREAMER_MODEL_ID);
	}
	return 0;
}

stock quickSort(array[], left, right)
{
	new
	tempLeft = left,
	tempRight = right,
	pivot = array[(left + right) / 2],
	tempVar
	;
	while(tempLeft <= tempRight)
	{
		while(array[tempLeft] < pivot) tempLeft++;
		while(array[tempRight] > pivot) tempRight--;
		
		if(tempLeft <= tempRight)
		{
			tempVar = array[tempLeft], array[tempLeft] = array[tempRight], array[tempRight] = tempVar;
			tempLeft++, tempRight--;
		}
	}
	if(left < tempRight) quickSort(array, left, tempRight);
	if(tempLeft < right) quickSort(array, tempLeft, right);
}

stock GetPos(playerid) 
{
	if(tgracz[playerid][pozycja] < 1) tgracz[playerid][pozycja] = 1;
	return tgracz[playerid][pozycja];
}

stock DestroyAllPickups()
{
	for(new p; p < MAX_PICKUPS; p++)
	{
		DeletePick(p);
	}
	return 1;
}

stock DeletePick(pickid)
{
	DestroyPickup(pickid);
	for(new pickdata:x; x < pickdata; x++)
	{
		pick[pickid][x] = 0;
	}
	return 1;
}

stock SecToTime(seconds, &days, &hours, &minutes, &secc)
{
	while(seconds > 59)
	{
		seconds -= 60;
		minutes++;
	}
	while(minutes > 59)
	{
		minutes -= 60;
		hours++;
	}
	while(hours > 23)
	{
		hours -= 24;
		days++;
	}
	secc = seconds;
	return 1;
}

stock ActualMapID() return dini_Int(CFG, "LastMap");

stock GetMaterialVehHP(vehicleid)
{
	new str[64];
	format(str, 64, "_________");//9
	new Float:hp;
	GetVehicleHealth(vehicleid, hp);
	switch(floatround(hp))
	{
		case 950..1000:
		{
			format(str, 64, "{00FF00}__________");
		}
		case 850..949:
		{
			format(str, 64, "{00FF00}________");
		}
		case 750..849:
		{
			format(str, 64, "{00FF00}_______");
		}
		case 650..749:
		{
			format(str, 64, "{FFFF00}______");
		}
		case 600..649:
		{
			format(str, 64, "{FFFF00}_____");
		}
		case 550..599:
		{
			format(str, 64, "{FFFF00}____");
		}
		case 490..549:
		{
			format(str, 64, "{FF0000}___");
		}
		case 400..489:
		{
			format(str, 64, "{FF0000}__");
		}
		case 370..399:
		{
			format(str, 64, "{FF0000}_");
		}
		case 0..369:
		{
			format(str, 64, " ");
		}
	}
	return str;
}

stock ShowSpeedo(playerid)
{
	if(sgracz[playerid][upd_speedo]) return 0;
	SpdObj[playerid][0] = CreateDynamicObject(19482,0.0,0.0,0.0,0.0,0.0,0.0,-1,-1,playerid,200.0);
	SpdObj[playerid][1] = CreateDynamicObject(19482,0.0,0.0,0.0,0.0,0.0,0.0,-1,-1,playerid,200.0);
	new Float:x,Float:y,Float:z;
	GetVehicleModelInfo(GetVehicleModel(GetPlayerVehicleID(playerid)),VEHICLE_MODEL_INFO_SIZE,x,y,z);
	AttachDynamicObjectToVehicle(SpdObj[playerid][0],GetPlayerVehicleID(playerid), x- 2.55, y-(-3.0), z-(-3.4),0.0,0.0,270.0);
	SetDynamicObjectMaterialText(SpdObj[playerid][1],0,"_________",OBJECT_MATERIAL_SIZE_512x512,"Arial",64,true,0xFF4EFD71,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(SpdObj[playerid][1],GetPlayerVehicleID(playerid), x- 2.55, y-(-3.0), z-(-3.4), 0.0,0.0,270.0);
	Streamer_Update(playerid);
	sgracz[playerid][upd_speedo] = true;
	return 1;
}

stock HideSpeedo(playerid)
{
	if(!sgracz[playerid][upd_speedo]) return 0;
	sgracz[playerid][upd_speedo] = false;
	DestroyDynamicObject(SpdObj[playerid][0]);
	DestroyDynamicObject(SpdObj[playerid][1]);
	SpdObj[playerid][0] = INVALID_OBJECT_ID;
	SpdObj[playerid][1] = INVALID_OBJECT_ID;
	return 1;
}

stock ShowTopWins(playerid)
{
	new title[100], str[1024];
	if(polak(playerid))
	{
		format(title, 100, "%s  Top Wygrane - "COL_BLUE"Master Race", form());
		format(str, 1024, ""COL_WHITE"#\tNick\t"COL_GREEN"Wygrane"COL_WHITE"/"COL_RED"Wyścigów\t"COL_WHITE"Kraj\n%s", serwer[str_topwins]);
	}
	else
	{
		format(title, 100, "%s  Top Wins - "COL_BLUE"Master Race", form());
		format(str, 1024, ""COL_WHITE"#\tNick\t"COL_GREEN"Wins"COL_WHITE"/"COL_RED"Races\t"COL_WHITE"Country\n%s", serwer[str_topwins]);	
	}

	Dialog_Show(playerid, TOPWINS, DIALOG_STYLE_TABLIST_HEADERS, title, str, "»»", "");
	return 1;
}

stock AttachHelmet(playerid)
{
	switch(GetPlayerSkin(playerid))
	{
           #define SPAO{%0,%1,%2,%3,%4,%5} SetPlayerAttachedObject(playerid, 1, RandomHelmet[random(sizeof(RandomHelmet))], 2, (%0), (%1), (%2), (%3), (%4), (%5));
		case 0, 65, 74, 149, 208, 273:  SPAO{0.070000, 0.000000, 0.000000, 88.000000, 75.000000, 0.000000}
		case 1..6, 8, 14, 16, 22, 27, 29, 33, 41..49, 82..84, 86, 87, 119, 289: SPAO{0.070000, 0.000000, 0.000000, 88.000000, 77.000000, 0.000000}
		case 7, 10: SPAO{0.090000, 0.019999, 0.000000, 88.000000, 90.000000, 0.000000}
		case 9: SPAO{0.059999, 0.019999, 0.000000, 88.000000, 90.000000, 0.000000}
		case 11..13: SPAO{0.070000, 0.019999, 0.000000, 88.000000, 90.000000, 0.000000}
		case 15: SPAO{0.059999, 0.000000, 0.000000, 88.000000, 82.000000, 0.000000}
		case 17..21: SPAO{0.059999, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 23..26, 28, 30..32, 34..39, 57, 58, 98, 99, 104..118, 120..131: SPAO{0.079999, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 40: SPAO{0.050000, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 50, 100..103, 148, 150..189, 222: SPAO{0.070000, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 51..54: SPAO{0.100000, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 55, 56, 63, 64, 66..73, 75, 76, 78..81, 133..143, 147, 190..207, 209..219, 221, 247..272, 274..288, 290..293: SPAO{0.070000, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 59..62: SPAO{0.079999, 0.029999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 77: SPAO{0.059999, 0.019999, 0.000000, 87.000000, 82.000000, 0.000000}
		case 85, 88, 89: SPAO{0.070000, 0.039999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 90..97: SPAO{0.050000, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 132: SPAO{0.000000, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 144..146: SPAO{0.090000, 0.000000, 0.000000, 88.000000, 82.000000, 0.000000}
		case 220: SPAO{0.029999, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 223, 246: SPAO{0.070000, 0.050000, 0.000000, 88.000000, 82.000000, 0.000000}
		case 224..245: SPAO{0.070000, 0.029999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 294: SPAO{0.070000, 0.019999, 0.000000, 91.000000, 84.000000, 0.000000}
		case 295: SPAO{0.050000, 0.019998, 0.000000, 86.000000, 82.000000, 0.000000}
		case 296..298: SPAO{0.064999, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
		case 299: SPAO{0.064998, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		default: SPAO{0.064998, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
	}
	return 1;
}

stock Error(playerid, string[])
{
	if(polak(playerid)) SendClientMessageEx(playerid, 0xFF0000AA, "|BŁĄD|"COL_WHITE" %s", string);
	else SendClientMessageEx(playerid, 0xFF0000AA, "|ERROR|"COL_WHITE" %s", string);
	return 1;
}

stock VirtualSet(playerid, virtid)
{
	if(!login(playerid)) return 0;
	SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), virtid);
	SetPlayerVirtualWorld(playerid, virtid);
	return 1;
}

stock compare(text1[], text2[], bool:ignorec = true)
{
	if(!strcmp(text1, text2, ignorec)) return 1;
	return 0;
}


stock IsRCVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 441: return 1;
		case 464: return 1;
		case 465: return 1;
		case 501: return 1;
		case 564: return 1;
		case 594: return 1;
	}
	return 0;
}

stock IsMotorVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 448:return 1;
		case 461:return 1;
		case 462:return 1;
		case 463:return 1;
		case 468:return 1;
		case 521:return 1;
		case 522:return 1;
		case 523:return 1;
		case 581:return 1;
		case 586:return 1;
		case 471:return 1;
	}
	return 0;
}

stock IsBoatVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 430:return 1;
		case 446:return 1;
		case 452:return 1;
		case 453:return 1;
		case 454:return 1;
		case 472:return 1;
		case 473:return 1;
		case 484:return 1;
		case 493:return 1;
		case 595:return 1;
	}
	return 0;
}


stock IsBicycleVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 481:return 1;
		case 509:return 1;
		case 510:return 1;
	}
	return 0;
}

stock IsHeliVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 417:return 1;
		case 425:return 1;
		case 447:return 1;
		case 469:return 1;
		case 487:return 1;
		case 488:return 1;
		case 497:return 1;
		case 548:return 1;
		case 563:return 1;
	}
	return 0;
}

stock IsPlaneVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 460:return 1;
		case 476:return 1;
		case 511:return 1;
		case 512:return 1;
		case 513:return 1;
		case 519:return 1;
		case 520:return 1;
		case 553:return 1;
		case 577:return 1;
		case 592:return 1;
		case 593:return 1;
	}
	return 0;
}

stock IsCarVehicle(vehicleid)
{
	if(!IsPlaneVehicle(vehicleid) && !IsHeliVehicle(vehicleid) && !IsBicycleVehicle(vehicleid) && !IsBoatVehicle(vehicleid) && !IsMotorVehicle(vehicleid) && !IsRCVehicle(vehicleid)) return 1;
	return 0;
}

stock LoadVehMod(playerid, vehicleid)
{
	if(!IsValidVehicle(vehicleid)) return 0;
	//koła
	if(sgracz[playerid][wheeltype] && IsCarVehicle(vehicleid))
	{
		AddVehicleComponent(vehicleid, sgracz[playerid][wheeltype]);
	}
	//neony
	RemovePlayerNeons(playerid);
	new f_temp;
	if(sgracz[playerid][neoncolor] && IsCarVehicle(vehicleid))
	{
		neon[playerid][0] = CreateDynamicObject(sgracz[playerid][neoncolor], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		neon[playerid][1] = CreateDynamicObject(sgracz[playerid][neoncolor], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		neon[playerid][2] = CreateDynamicObject(sgracz[playerid][neoncolor], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		neon[playerid][3] = CreateDynamicObject(sgracz[playerid][neoncolor], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		f_temp = neon[playerid][0];
		o_flag[f_temp] = F_NEON;
		f_temp = neon[playerid][1];
		o_flag[f_temp] = F_NEON;
		f_temp = neon[playerid][2];
		o_flag[f_temp] = F_NEON;
		f_temp = neon[playerid][3];
		o_flag[f_temp] = F_NEON;
		AttachDynamicObjectToVehicle(neon[playerid][0], vehicleid, -0.909999, -0.009999, -0.649999, 0.000000, 0.000000, 0.000000);
		AttachDynamicObjectToVehicle(neon[playerid][1], vehicleid, 0.914999, -0.009999, -0.649999, 0.000000, 0.000000, 0.000000);
		AttachDynamicObjectToVehicle(neon[playerid][2], vehicleid, 0.034999, 2.225003, -0.629999, 0.000000, 0.000000, -88.589958);
		AttachDynamicObjectToVehicle(neon[playerid][3], vehicleid, 0.034999, -2.034998, -0.629999, 0.000000, 0.000000, -88.589958);
	}
	else if(sgracz[playerid][neoncolor] && GetVehicleModel(vehicleid) == 522)
	{
		neon[playerid][0] = CreateDynamicObject(sgracz[playerid][neoncolor], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		f_temp = neon[playerid][0];
		o_flag[f_temp] = F_NEON;
		AttachDynamicObjectToVehicle(neon[playerid][0], vehicleid, 0.0, -0.2, 0.5, 0.000000, 0.000000, 0.000000);
	}
	return 1;
}

stock RemovePlayerNeons(playerid)
{
	new f_temp;
	f_temp = neon[playerid][0];
	if(IsValidDynamicObject(f_temp) && o_flag[f_temp] == F_NEON) DestroyDynamicObject(f_temp), o_flag[f_temp] = F_NONE;
	f_temp = neon[playerid][1];
	if(IsValidDynamicObject(f_temp) && o_flag[f_temp] == F_NEON) DestroyDynamicObject(f_temp), o_flag[f_temp] = F_NONE;
	f_temp = neon[playerid][2];
	if(IsValidDynamicObject(f_temp) && o_flag[f_temp] == F_NEON) DestroyDynamicObject(f_temp), o_flag[f_temp] = F_NONE;
	f_temp = neon[playerid][3];
	if(IsValidDynamicObject(f_temp) && o_flag[f_temp] == F_NEON) DestroyDynamicObject(f_temp), o_flag[f_temp] = F_NONE;
	return 1;
}

stock ClearChatAll()
{
	for(new c; c < 100; c++)
	{
		SendClientMessageToAll(-1, " ");
	}
	return 1;
}

stock ClearChat(playerid)
{
	for(new c; c < 100; c++)
	{
		SendClientMessage(playerid, -1, " ");
	}
	return 1;
}

stock PutIn(playerid, vehicleid, seat)
{
	if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
	tgracz[playerid][registerveh] = vehicleid;
	PutPlayerInVehicle(playerid, tgracz[playerid][registerveh], seat);
	return 1;
}

stock vip(playerid)
{
	if(sgracz[playerid][vip_stamp] > gettime() && login(playerid)) return 1;
	return 0;
}

stock AttachLaser(playerid)
{
	DestroyLaser(playerid);
	new vehicle = GetPlayerVehicleID(playerid);
	if(vehicle)
	{
		laser[playerid] = CreateDynamicObject(18643, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		AttachDynamicObjectToVehicle(laser[playerid], vehicle, 0.0, 0.0, 0.5, 0.0, 0.0, 90.0);
	}
	return 1;
}

stock DestroyLaser(playerid)
{
	if(GetDynamicObjectModel(laser[playerid]) == 18643)
	{
		DestroyDynamicObject(laser[playerid]);
		laser[playerid] = 0;
	}
	return 1;
}

stock GetPingAvarge(playerid)
{
	sgracz[playerid][avarge_ping] = GetPlayerPing(playerid);
	if(random(1))
	{
		sgracz[playerid][avarge_ping] += random(5);
	}
	else
	{
		sgracz[playerid][avarge_ping] -=random(5);
	}
	return sgracz[playerid][avarge_ping];
}

stock immunity(playerid)
{
	if(compare(nick(playerid), "sebaqq6", false)) return 1;
	if(compare(nick(playerid), "czerwony03", false)) return 1;
	return 0;
}

stock PowiadomOOC(usid, const wiadomosc[])
{
	new wstr[512];
	format(wstr, 512, "gg.redtm.pl/pull.php?nr=seba&msg=%s", wiadomosc);
	HTTP(usid, HTTP_HEAD, wstr, "", "SendHTTPGG");
	return 1;
}

stock polak(playerid) return sgracz[playerid][zpolski];

stock SendAdminMsg(const text[], {Float, _}:...)
{
	static
	args,
	str[256];
    /*
    *  Custom function that uses #emit to format variables into a string.
    *  This code is very fragile; touching any code here will cause crashing!
    */
    if ((args = numargs()) == 3)
    {
    	for(new a; a <= GetPlayerPoolSize(); a++)
    	{
    		if(login(a) && admin(a))
    		{
    			SendClientMessageEx(a, 0xFF0000FF, text);
    		}
    	}
    }
    else
    {
    	while (--args >= 3)
    	{
            #emit LCTRL 5
            #emit LOAD.alt args
            #emit SHL.C.alt 2
            #emit ADD.C 12
            #emit ADD
            #emit LOAD.I
            #emit PUSH.pri
    	}
        #emit PUSH.S text
        #emit PUSH.C 256
        #emit PUSH.C str
        #emit PUSH.S 8
        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4
    	for(new a; a <= GetPlayerPoolSize(); a++)
    	{
    		if(login(a) && admin(a))
    		{
    			SendClientMessageEx(a, 0xFF0000FF, str);
    		}
    	}
        #emit RETN
    }
    return 1;
}

stock WygenerujPodium()
{
	CreateObject(19547, -2863.85, 1764.38, 8.92,   0.00, 0.00, 0.00);
	CreateObject(17472, -2841.81, 1790.91, 16.37,   0.00, 0.00, 338.03);
	CreateObject(17472, -2810.22, 1773.53, 16.37,   0.00, 0.00, 9.93);
	CreateObject(17472, -2858.19, 1822.83, 16.37,   0.00, 0.00, 287.00);
	CreateObject(791, -2895.07, 1815.62, 21.24,   0.00, 0.00, 0.00);
	CreateObject(791, -2830.38, 1741.63, 21.24,   0.00, 0.00, 0.00);
	CreateObject(800, -2811.61, 1792.94, 11.68,   0.00, 0.00, 0.00);
	CreateObject(759, -2830.82, 1817.33, 9.63,   0.00, 0.00, 0.00);
	CreateObject(759, -2832.66, 1800.84, 12.11,   0.00, 0.00, 0.00);
	CreateObject(11413, -2841.25, 1792.68, 12.13,   0.00, 0.00, 0.00);
	CreateObject(11413, -2832.52, 1783.67, 13.89,   0.00, 0.00, 0.00);
	CreateObject(17472, -2865.61, 1775.80, 38.76,   0.00, 0.00, 320.34);
	CreateObject(19841, -2861.97, 1779.75, 33.52,   0.00, 0.00, 136.66);
	CreateObject(18763, -2820.65, 1812.36, 9.56,   0.00, 0.00, 39.97);
	CreateObject(3524, -2818.49, 1812.17, 11.48,   0.00, 0.00, 130.69);
	CreateObject(3509, -2825.09, 1791.35, 11.89,   0.00, 0.00, 0.00);
	CreateObject(759, -2830.82, 1817.33, 9.63,   0.00, 0.00, 0.00);
	CreateObject(759, -2832.66, 1800.84, 12.11,   0.00, 0.00, 0.00);
	CreateObject(18763, -2818.72, 1810.06, 11.01,   0.00, 0.00, 39.97);
	CreateObject(18763, -2816.79, 1807.76, 10.15,   0.00, 0.00, 39.97);
	CreateObject(3524, -2816.61, 1809.90, 11.48,   0.00, 0.00, 130.69);
	CreateObject(3524, -2820.42, 1814.47, 10.03,   0.00, 0.00, 130.69);
	CreateObject(3524, -2814.69, 1807.57, 10.54,   0.00, 0.00, 130.69);
	CreateObject(8483, -2837.73, 1794.33, 18.14,   0.00, 0.00, 45.75);
	CreateObject(3509, -2842.24, 1804.91, 10.56,   0.00, 0.00, 0.00);
	CreateObject(18720, -2819.87, 1809.09, 13.47,   0.00, 0.00, 0.00);
	CreateObject(18742, -2816.36, 1812.06, 9.50,   0.00, 0.00, 0.00);
	new pierwszy = CreateObject(19353, -2817.5971, 1810.9821, 12.3036, 0.0000, 0.0000, 35.9644);
	SetObjectMaterialText(pierwszy, "1", 0, 50, "Arial", 50, 1, -256, 0, 1);
	new drugi = CreateObject(19353, -2815.7133, 1808.6887, 11.6045, 0.0000, 0.0000, 39.9707);
	SetObjectMaterialText(drugi, "2", 0, 50, "Arial", 50, 1, -16730675, 0, 1);
	new trzeci = CreateObject(19353, -2819.5415, 1813.2648, 11.2172, 0.0000, 0.0000, 40.0306);
	SetObjectMaterialText(trzeci, "3", 0, 50, "Arial", 40, 1, -1, 0, 1);
	return 1;
}

stock PlayMusic(playerid)
{
	if(strlen(serwer[songurl]) > 4) 
	{
		PlayAudioStreamForPlayer(playerid, serwer[songurl]);
		tgracz[playerid][songtime] = serwer[songtime];
	}
	return 1;
}