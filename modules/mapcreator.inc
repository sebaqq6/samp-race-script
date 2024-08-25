/*CMD:createmapstart(playerid, params[])
{
	if(admin(playerid) < 4) return 0;
	new name[32];
	new mapid, vehstart;
	if(sscanf(params,"dds[32]", mapid, vehstart, name)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /createmapstart [mapid] [vehstart] [name]");
	new data_str[1024];
	new name_str[32];
	format(data_str, 1024, "INSERT INTO `map_lista` (`id`, `author_uid`, `title`, `vehstart`) VALUES ('%d', '%d', '%s', '%d');\r\n", mapid, sgracz[playerid][uID], name, vehstart);
	format(name_str, 32, "data_map_%d.txt", mapid);
	new File:handle = fopen(name_str, io_append);
	fwrite(handle, data_str);
	fclose(handle);
	SendClientMessageEx(playerid, 0xFFFF00FF, "[NEW MAP]%s [%s]", data_str, name_str);
	format(data_str, 128, "/createmapcp %d 0", mapid);
	PC_EmulateCommand(playerid, data_str);
	return 1;
}


CMD:createmapcp(playerid, params[])
{
	if(admin(playerid) < 4) return 0;
	new mapid, cptype;
	if(sscanf(params,"dd", mapid, cptype)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /createmapcp [mapid] [cptype[0-road][1-fly]]");
	if(cptype > 1) Error(playerid, "Za duże cptype.");
	if(cptype < 0) Error(playerid, "Za małe cptype.");
	if(!IsPlayerInAnyVehicle(playerid)) Error(playerid, "Musisz być w aucie.");
	new data_str[1024];
	new name_str[32];
	new Float:pPos[4];
	GetVehiclePos(GetPlayerVehicleID(playerid), pPos[0], pPos[1], pPos[2]);
	GetVehicleZAngle(GetPlayerVehicleID(playerid), pPos[3]);
	tgracz[playerid][mapcreator_cplastpos][0] = pPos[0];
	tgracz[playerid][mapcreator_cplastpos][1] = pPos[1];
	tgracz[playerid][mapcreator_cplastpos][2] = pPos[2];
	format(data_str, 1024, "INSERT INTO `map_data` (`mid`, `data_type`, `x`, `y`, `z`, `r`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f');\r\n", mapid, cptype, pPos[0], pPos[1], pPos[2], pPos[3]);
	format(name_str, 32, "data_map_%d.txt", mapid);
	new File:handle = fopen(name_str, io_append);
	fwrite(handle, data_str);
	fclose(handle);
	SendClientMessageEx(playerid, 0x00FF00FF, "[CP] mapid: %d |  cptype: %d [%s]", mapid, cptype, name_str);
	return 1;
}

CMD:createmappick(playerid, params[])
{
	if(admin(playerid) < 4) return 0;
	new mapid, picktype, pickvalue;
	if(sscanf(params,"ddd", mapid, picktype, pickvalue)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /createmappick [mapid] [picktype] [pickvalue]"), SendClientMessage(playerid, -1, ""COL_GREY"ID's picktype: 0-fix, 1-change, 2-nitro, 3-Tnitro, 4-rocket, 5-ramp, 6-hay, 7-spike");
	if(picktype < 0 || picktype > 7) return Error(playerid, "Invalid pickup ID");
	if(!IsPlayerInAnyVehicle(playerid)) Error(playerid, "Musisz być w aucie.");
	new data_str[1024];
	new name_str[32];
	new Float:pPos[4];
	GetVehiclePos(GetPlayerVehicleID(playerid), pPos[0], pPos[1], pPos[2]);
	GetVehicleZAngle(GetPlayerVehicleID(playerid), pPos[3]);
	format(data_str, 1024, "INSERT INTO `map_data` (`mid`, `data_type`, `x`, `y`, `z`, `r`, `value`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f', '%d');\r\n", mapid, picktype+10, pPos[0], pPos[1], pPos[2], pPos[3], pickvalue);
	format(name_str, 32, "data_map_%d.txt", mapid);
	new File:handle = fopen(name_str, io_append);
	fwrite(handle, data_str);
	fclose(handle);
	SendClientMessageEx(playerid, 0x0000FFFF, "[PICKUP] mapid: %d | picktype: %d | pickvalue: %d [%s]", mapid, picktype, pickvalue, name_str);
	return 1;
}


CMD:createmaptogcpd(playerid, params[])
{
	if(admin(playerid) < 4) return 0;
	tgracz[playerid][mapcreator_cpd] = true;
	if(tgracz[playerid][mapcreator_cpd]) SetTimerEx("mapcreator_CheckPointDistance", 1000, false, "d", playerid);
	return 1;
}

forward mapcreator_CheckPointDistance(playerid);
public mapcreator_CheckPointDistance(playerid)
{
	if(tgracz[playerid][mapcreator_cpd])
	{
		SetTimerEx("mapcreator_CheckPointDistance", 1000, false, "d", playerid);
		new tempStr[64];
		new Float:pPos[3];
		GetVehiclePos(GetPlayerVehicleID(playerid), pPos[0], pPos[1], pPos[2]);
		format(tempStr, 64, "%dM", GetDistanceBetweenPoints(pPos[0], pPos[1], pPos[2], tgracz[playerid][mapcreator_cplastpos][0], tgracz[playerid][mapcreator_cplastpos][1], tgracz[playerid][mapcreator_cplastpos][2]));
		GameTextForPlayer(playerid, tempStr, 1000, 1);
	}
	return 1;
}*/

enum mcreator_data
{
	bool:mc_block,
	bool:mc_enabled,
	mc_mapid,
	Float:mc_lastcpX,
	Float:mc_lastcpY,
	Float:mc_lastcpZ,
	mc_ctype,
	mc_ccount,
	mc_pickstep,
};

new mcreator[mcreator_data];

CMD:createmap(playerid, params[])
{
	if(admin(playerid) < 4) return 0;
	if(mcreator[mc_block]) return SendClientMessage(playerid, 0xFF0000FF, "YOU MUST RESTART SERVER");
	new name[32];
	new mapid, vehstart;
	if(sscanf(params,"dds[32]", mapid, vehstart, name)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /createmapstart [mapid] [vehstart] [name]");
	mcreator[mc_mapid] = mapid;
	mcreator[mc_ctype] = 0;
	mcreator[mc_enabled] = true;
	mcreator[mc_block] = true;
	new data_str[1024];
	new name_str[32];
	format(data_str, 1024, "INSERT INTO `map_lista` (`id`, `author_uid`, `title`, `vehstart`) VALUES ('%d', '%d', '%s', '%d');\r\n", mapid, sgracz[playerid][uID], name, vehstart);
	format(name_str, 32, "data_map_%d.txt", mapid);
	new File:handle = fopen(name_str, io_append);
	fwrite(handle, data_str);
	fclose(handle);
	mcreator_CreateCP(playerid, 0);
	SetTimerEx("Process_MapCreator", 1000, false, "d", playerid);
	SendClientMessageEx(playerid, 0xFFFF00FF, "[NEW MAP]N: %s | V: %d | MID: %d", name, vehstart, mapid);
	return 1;
}

CMD:createcp(playerid, params[])
{
	if(admin(playerid) < 4) return 0;
	new cptype;
	if(sscanf(params,"d", cptype)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /createcp [cptype]");
	if(mcreator[mc_enabled])
	{
		mcreator[mc_ctype] = cptype;
		mcreator_CreateCP(playerid, cptype);
	}
	return 1;
}
//picktype: 0-fix, 1-change, 2-nitro, 3-Tnitro, 4-rocket, 5-ramp, 6-hay, 7-spike");
forward Process_MapCreator(playerid);
public Process_MapCreator(playerid)
{
	if(!login(playerid)) mcreator[mc_enabled] = false;
	else
	{
		new Float:pPos[4];
		GetVehiclePos(GetPlayerVehicleID(playerid), pPos[0], pPos[1], pPos[2]);
		if(GetDistanceBetweenPoints(pPos[0], pPos[1], pPos[2], mcreator[mc_lastcpX], mcreator[mc_lastcpY], mcreator[mc_lastcpZ]) > 80)
		{
			mcreator_CreateCP(playerid, mcreator[mc_ctype]);
			if(mcreator[mc_pickstep] < 4) mcreator[mc_pickstep]++;
		}

		
	 	if(GetDistanceBetweenPoints(pPos[0], pPos[1], pPos[2], mcreator[mc_lastcpX], mcreator[mc_lastcpY], mcreator[mc_lastcpZ]) > 40 && mcreator[mc_pickstep] == 4)
		{
			mcreator[mc_pickstep] = 0;
			new rand_picktype = random(10);
			new data_str[1024];
			new name_str[32];
			tgracz[playerid][pickdelay] = gettime()+3;
			switch(rand_picktype)
			{
				case 2..7: 
				{
					if(rand_picktype == TAKE_NITRO) rand_picktype = NITRO;//disable take nitro ;d
					Pickup(pPos[0], pPos[1], pPos[2], rand_picktype, 0);
					format(data_str, 1024, "INSERT INTO `map_data` (`mid`, `data_type`, `x`, `y`, `z`, `r`, `value`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f', '%d');\r\n", mcreator[mc_mapid], 10+rand_picktype, pPos[0], pPos[1], pPos[2], pPos[3], 0);
					format(name_str, 32, "data_map_%d.txt", mcreator[mc_mapid]);
					new File:handle = fopen(name_str, io_append);
					fwrite(handle, data_str);
					fclose(handle);
					SendClientMessageEx(playerid, PlayerColors[random(sizeof(PlayerColors))], "*** PICKUP CREATED! (type: %d)", rand_picktype);
				}
				default: 
				{
					Pickup(pPos[0], pPos[1], pPos[2], 0, 0);
					format(data_str, 1024, "INSERT INTO `map_data` (`mid`, `data_type`, `x`, `y`, `z`, `r`, `value`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f', '%d');\r\n", mcreator[mc_mapid], 10, pPos[0], pPos[1], pPos[2], pPos[3], 0);
					format(name_str, 32, "data_map_%d.txt", mcreator[mc_mapid]);
					new File:handle = fopen(name_str, io_append);
					fwrite(handle, data_str);
					fclose(handle);
					SendClientMessageEx(playerid, PlayerColors[random(sizeof(PlayerColors))], "*** PICKUP CREATED! (type: %d)", rand_picktype);
				}
			}
		}
		new strTemp[128];
		format(strTemp, 128, "~w~LAST ~r~CP~w~: ~g~%d~w~/~w~80~b~M", floatround(GetDistanceBetweenPoints(pPos[0], pPos[1], pPos[2], mcreator[mc_lastcpX], mcreator[mc_lastcpY], mcreator[mc_lastcpZ])));
		GameTextForPlayer(playerid, strTemp, 500, 4);
	}
	if(mcreator[mc_enabled]) SetTimerEx("Process_MapCreator", 100, false, "d", playerid);
	return 1;
}

stock mcreator_CreateCP(playerid, type)
{
	new data_str[1024];
	new name_str[32];
	format(name_str, 32, "data_map_%d.txt", mcreator[mc_mapid]);
	new Float:pPos[4];
	GetVehiclePos(GetPlayerVehicleID(playerid), pPos[0], pPos[1], pPos[2]);
	GetVehicleZAngle(GetPlayerVehicleID(playerid), pPos[3]);
	mcreator[mc_lastcpX] = pPos[0];
	mcreator[mc_lastcpY] = pPos[1];
	mcreator[mc_lastcpZ] = pPos[2];
	CreateDynamicObject(19946, pPos[0], pPos[1], pPos[2], 0.0, 0.0, 0.0, _, _, playerid);
	format(data_str, 1024, "INSERT INTO `map_data` (`mid`, `data_type`, `x`, `y`, `z`, `r`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f');\r\n", mcreator[mc_mapid], type, pPos[0], pPos[1], pPos[2], pPos[3]);
	new File:handle = fopen(name_str, io_append);
	fwrite(handle, data_str);
	fclose(handle);
	mcreator[mc_ccount]++;
	SendClientMessageEx(playerid, PlayerColors[random(sizeof(PlayerColors))], ">> CP CREATED! (type: %d | count: %d)", type, mcreator[mc_ccount]);
	return 1;
}