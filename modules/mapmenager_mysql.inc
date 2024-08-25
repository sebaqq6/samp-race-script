forward  MapLoader();
public MapLoader()
{
	mq_format("SELECT `map`.*,`p`.`name` FROM `map_lista` AS `map` INNER JOIN `players` AS `p` ON `map`.`author_uid`=`p`.`id` WHERE `map`.`id`='%d' LIMIT 1;", ActualMapID());
	mq_send("OnMapInfoLoaded");
	serwer[eMin] = MAP_MAXTIME;
	serwer[eSec] = 0;
	serwer[wyscig] = false;
	serwer[m] = 0;
	serwer[sec] = 0;
	serwer[ms] = 0;
	serwer[extrams] = 0;
	serwer[zkolei] = 0;
	serwer[sh_check] = true;
	ClearObjects();
	SetWeather(14);
	SetWorldTime(0);
	DestroyAllPickups();
	DestroyAllDynamicMapIcons();
	ClearCP();
	String_ulista("-", false);
	MapLoaded++;
	return 1;
}

forward OnMapInfoLoaded();
public OnMapInfoLoaded()
{
	cache_get_field_content(0, "title", MapInfo[Nazwa], MySQL, 128);
	cache_get_field_content(0, "name", MapInfo[Autor], MySQL, 19);
	MapInfo[vstart] = cache_get_field_content_int(0, "vehstart");
	MapInfo[started] = gettime();
	MapInfo[played] = cache_get_field_content_int(0, "played");
	MapInfo[like] = cache_get_field_content_int(0, "like");
	MapInfo[dislike] = cache_get_field_content_int(0, "dislike");
	SetMapName(MapInfo[Nazwa]);
	printf("[MAP]Nazwa: %s | Autor: %s | Pojazd Startowy: %d | L/D: %d/%d | Gotowa!", MapInfo[Nazwa], MapInfo[Autor], MapInfo[vstart], MapInfo[like], MapInfo[dislike]);
	UpRadarSet(MapInfo[Nazwa]);
	GenerateTop10(ActualMapID());
	GenerateTopWins();
	mq_format("SELECT * FROM `map_data` WHERE `mid`='%d';", ActualMapID());
	mq_send("OnMapDataLoad");
	mq_format("SELECT * FROM `music` WHERE `status`='1' AND `id`>'%d' LIMIT 1;", serwer[songid]);
	mq_send("OnMusicLoad");
	WygenerujPodium();
	return 1;
}

/*
typy danych:
//cp
0 - cp road
1 - cp fly
//pickup
10 - FIX_VEH 0//Fix vehicle | FUNCTION | value = NONE
11 - CHANGE_VEH 1//Change vehicle | FUNCTION | value = vehicle model id
12 - NITRO 2//Give nitro | FUNCTION | value = NONE
13 - TAKE_NITRO 3//Take nitro | FUNCTION | value = NONE
14 - W_ROCKET 4//Adds a rocket for the player, which can fire from the vehicle. | WEAPON | value = NONE
15 - W_RAMP 5//Create a ramp on back the player | WEAPON | value = NONE
16 - W_HAY 6//Create a hay on back the player | WEAPON | VALUE = NONE
17 - W_SPIKE 7//Create a spike strip on back the player | WEAPON | VALUE = NONE
*/

forward OnMapDataLoad();
public OnMapDataLoad()
{
	mq_getdata();
	if(rekordy)
	{
		new i;
		new data_type, data_value; 
		new Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_r;
		while(i < rekordy)
		{
			data_type = cache_get_field_content_int(i, "data_type");
			data_value = cache_get_field_content_int(i, "value");
			pos_x = cache_get_field_content_float(i, "x");
			pos_y = cache_get_field_content_float(i, "y");
			pos_z = cache_get_field_content_float(i, "z");
			pos_r = cache_get_field_content_float(i, "r");
			if(data_type == 0 || data_type == 1) LoadCP(pos_x, pos_y, pos_z, pos_r, data_type);
			else if(data_type == 10) Pickup(pos_x, pos_y, pos_z, FIX_VEH, data_value);
			else if(data_type == 11) Pickup(pos_x, pos_y, pos_z, CHANGE_VEH, data_value);
			else if(data_type == 12) Pickup(pos_x, pos_y, pos_z, NITRO, data_value);
			else if(data_type == 13) Pickup(pos_x, pos_y, pos_z, TAKE_NITRO, data_value);
			else if(data_type == 14) Pickup(pos_x, pos_y, pos_z, W_ROCKET, data_value);
			else if(data_type == 15) Pickup(pos_x, pos_y, pos_z, W_RAMP, data_value);
			else if(data_type == 16) Pickup(pos_x, pos_y, pos_z, W_HAY, data_value);
			else if(data_type == 17) Pickup(pos_x, pos_y, pos_z, W_SPIKE, data_value);
			i++;
		}
	}
	PorzadkujGraczy();
	return 1;
}


forward OnMusicLoad();
public OnMusicLoad()
{
	mq_getdata();
	if(rekordy)
	{
		cache_get_field_content(0, "url", serwer[songurl], MySQL, 128);
		serwer[songid] = cache_get_field_content_int(0, "id");
		serwer[songtime] = cache_get_field_content_int(0, "time");
	}
	else
	{
		print("|INFO| Koniec plalisty, wracam do pierwszego utworu.");
		serwer[songid] = 1;
		format(serwer[songurl], 128, "http://127.0.0.1/music/1.mp3");
	}
	return 1;
}


forward  Object(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ);
public  Object(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ)
{
	if(ObjectCount > 901) return printf("|ERROR|Object >> limit obiektow przekroczony!!!");
	new f_temp;
	if(MapLoaded)
	{
		f_temp = CreateObject(modelid, X, Y, Z, rX, rY, rZ, 600.0);
		o_flag[f_temp] = F_MOBJECT;
		ObjectCount++;
	}
	return 1;
}

stock ClearObjects()
{
	for(new o; o < MAX_OBJECTS; o++)
	{
		DestroyObject(o);
		o_flag[o] = F_NONE;
	}
	DestroyAllDynamicObjects();
	ObjectCount = 0;
	return 1;
}
stock SetMapName(mapname[])
{
	new mname[128];    
	format(mname, 128, "mapname %s", mapname);
	SendRconCommand(mname);
	return 1;
}


stock PorzadkujGraczy()
{
	for(new s; s < MAX_PLAYERS; s++)
	{
		SetSpawnInfo(s, 0, 50, CP[0][cX], CP[0][cY], CP[0][cZ], CP[0][cR], 0, 0, 0, 0, 0, 0);
		for(new Tpstats:x; x < Tpstats; x++)
		{
			tgracz[s][x] = 0;
		}
		for(new r; r < MAX_CPS; r++)
		{
			for(new pploader:p; p < pploader; p++)
			{
				pPositionLoader[s][r][p] = 0;
			}
		}
		TogglePlayerSpectating(s, false);
		if(login(s))
		{
			StopAudioStreamForPlayer(s);
			DestroyCP(s);
			HideSpeedo(s);
			SetPlayerVirtualWorld(s, 5+s);
			if(IsPlayerInAnyVehicle(s)) DestroyVehicle(GetPlayerVehicleID(s));
			SpawnPlayer(s);
			String_pTime(s, 0, 0, 0);
			String_nextcpTD(s, 0);
			String_checkTD(s, 0, GetCountCheckpoints());
			String_PosTD(s, 1, POnline());
			String_weaponTD(s, "NONE", true);
			String_specTD(s, "NONE", true);
			ShowMapInfo(s);
			TopWindowHide(s);
			ShowTop10Map(s);
			OppHide(s);
		}
	}
	serwer[count] = MAX_ODLICZANIE;
	serwer[odliczanie] = true;
	serwer[wpid] = GetPlayerPoolSize()+1;
	UstawOKWorld();
	return 1;
}

Dialog:VOTE(playerid, response, listitem, inputtext[])
{
		if(!serwer[voting])
		{
			if(polak(playerid)) Error(playerid, "Głosowanie nie jest aktywne.");
			else Error(playerid, "Voting is not active.");
			return 1;
		} 
		if(response) 
		{
				serwer[glosy_n]++;
				SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|The player "COL_BLUE"%s"COL_WHITE" voted for: "COL_GREEN"NEXT MAP"COL_WHITE".", serwer[glosy_n], serwer[glosy_r], nick(playerid));
				SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|Gracz "COL_BLUE"%s"COL_WHITE" zagłosował na: "COL_GREEN"NASTĘPNA MAPA"COL_WHITE".", serwer[glosy_n], serwer[glosy_r], nick(playerid));
		}
		else 
		{
				serwer[glosy_r]++;
				SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|The player "COL_BLUE"%s"COL_WHITE" voted for: "COL_RED"REPLAY"COL_WHITE".", serwer[glosy_n], serwer[glosy_r], nick(playerid));
				SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|Gracz "COL_BLUE"%s"COL_WHITE" zagłosował na: "COL_RED"RESTART MAPY"COL_WHITE".", serwer[glosy_n], serwer[glosy_r], nick(playerid));
		}
		return 1;
}

forward EndVote();
public EndVote()
{
	serwer[voting] = false;
	SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|"COL_YELLOW"Voting completed!", serwer[glosy_n], serwer[glosy_r]);
	SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|"COL_YELLOW"Głosowanie zakończone!", serwer[glosy_n], serwer[glosy_r]);
	if(serwer[glosy_n] > serwer[glosy_r] || MapInfo[retrying] >= 3)
	{
		new query[256],lastmap,lastmapid;
		lastmap = dini_Int(CFG, "LastMap");
		printf("[LOAD]Inicjalizacja ladowania mapy(lastmap: %d)...", lastmap);
		mysql_format(MySQL,query,sizeof(query),"SELECT * FROM `map_lista` WHERE `id`>'%d' AND `status`='1' LIMIT 1;",lastmap);
		new Cache:nextone = mysql_query(MySQL,query);
		if(cache_get_row_count())
		{
			lastmapid = cache_get_field_content_int(0, "id");
			cache_delete(nextone,MySQL);
			dini_IntSet(CFG, "LastMap", lastmapid);
			printf("[LOAD]Mapa %d zostaje przygotowana do zaladowania...", ActualMapID());
		}
		else
		{
			cache_delete(nextone,MySQL);
			mysql_format(MySQL,query,sizeof(query),"SELECT * FROM `map_lista` WHERE `status`='1' ORDER BY `id` ASC LIMIT 1;");
			new Cache:firstone = mysql_query(MySQL,query);
			if(cache_get_row_count())
			{
				lastmapid = cache_get_field_content_int(0, "id");
				dini_IntSet(CFG, "LastMap", lastmapid);
				printf("[LOAD]Mapa %d zostaje przygotowana do zaladowania...", ActualMapID());
			}
			else
			{
				print("[ERROR] Blad fatalny! Nie znaleziono pierwszej mapy...");
			} 
			cache_delete(firstone,MySQL);          
		}
		MapLoader();
		if(MapInfo[retrying] >= 3)
		{
			SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_RED"FORCE"COL_WHITE"|"COL_GREEN"Force next map loading..."COL_WHITE" Reason: "COL_RED"3/3 retries.");
			SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_RED"FORCE"COL_WHITE"|"COL_GREEN"Wymuszenie następnej mapy..."COL_WHITE" Powód: "COL_RED" mapę powtórzono już 3 razy.");
		}
		else
		{
			SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|"COL_GREEN"Next map loading...", serwer[glosy_n], serwer[glosy_r]);
			SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|"COL_GREEN"Ładowanie następnej mapy...", serwer[glosy_n], serwer[glosy_r]);
		}
		MapInfo[retrying] = 0;
	}
	else
	{
		MapInfo[retrying]++;
		SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|"COL_RED"The current map has been restarted... "COL_BLUE"(Retries: %d/3)", serwer[glosy_n], serwer[glosy_r], MapInfo[retrying]);
		SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|"COL_RED"Mapa zostaje zrestartowana... "COL_BLUE"(Ilość restartów tej mapy: %d/3)", serwer[glosy_n], serwer[glosy_r], MapInfo[retrying]);
		MapLoader();
	}
	serwer[glosy_r] = 0;
	serwer[glosy_n] = 0;
	return 1;
}

Dialog:MAPINFO(playerid, response, listitem, inputtext[])
{
	if(!serwer[wyscig]) return ShowShop(playerid);
	//DISABLE:
	/*new title[100], str[1024];
	format(title, 100, "%s  Top 10 - Map: "COL_GREEN"%s"COL_WHITE" by "COL_ORANGE"%s"COL_WHITE"", form(), MapInfo[Nazwa], MapInfo[Autor]);
	format(str, 1024, ""COL_WHITE"#\tNick\tPosition\tTime\n%s", MapInfo[str_top10]);
	Dialog_Show(playerid, TOPTEN, DIALOG_STYLE_TABLIST_HEADERS, title, str, "»»", "");
	*/
	return 1;
}

Dialog:TOPTEN(playerid, response, listitem, inputtext[])
{
	 if(!serwer[wyscig]) return ShowShop(playerid);
	 return 1;
}

stock GenerateTop10(mapid)
{
		mq_format("SELECT `map`.*,`p`.`name` FROM `map_result` AS `map` JOIN (SELECT `mid`,`uid`,MIN(`ems`) AS `emss` FROM `map_result` WHERE `mid`='%d' GROUP BY `uid`) AS `cmap` ON `map`.`uid`=`cmap`.`uid` AND `map`.`ems`=`cmap`.`emss` AND `map`.`mid`=`cmap`.`mid`  INNER JOIN `players` AS `p` ON `map`.`uid`=`p`.`id` WHERE `map`.`mid`='%d' ORDER BY `map`.`ems` ASC LIMIT 10;", mapid, mapid);
		new Cache:topten = mysql_query(MySQL, mQuery);
		mq_getdata();
		new i;
		new nickname[24];
		format(MapInfo[str_top10], 1024, "");
		new miejsce;
		ClearTopUsedUID();
		format(MapInfo[win_str_nickname], 700, "Nickname~n~");
		format(MapInfo[win_str_time], 500, "Time~n~");
		if(rekordy)
		{
				while(i < rekordy)
				{
						new uid = cache_get_field_content_int(i, "uid", MySQL);
						if(!IsTopUsedUID(uid))
						{
								miejsce++;//if miejsce <= 10
								cache_get_field_content(i, "name", nickname, MySQL, 24);
								format(MapInfo[str_top10], 1024, "%s"COL_WHITE"%d.\t"COL_GREEN"%s\t"COL_BLUE"%d\t"COL_ORANGE"%d:%d.%d\n", MapInfo[str_top10], miejsce, nickname, cache_get_field_content_int(i, "msc", MySQL), cache_get_field_content_int(i, "min", MySQL), cache_get_field_content_int(i, "sec", MySQL), cache_get_field_content_int(i, "ms", MySQL));
								format(MapInfo[win_str_nickname], 700, "%s%s~n~", MapInfo[win_str_nickname], nickname);
								format(MapInfo[win_str_time], 500, "%s%02d:%02d.%02d~n~", MapInfo[win_str_time], cache_get_field_content_int(i, "min", MySQL), cache_get_field_content_int(i, "sec", MySQL), cache_get_field_content_int(i, "ms", MySQL));
								//TopUseUID(uid);
						}
						i++;
				}
		}
		cache_delete(topten, MySQL);
		return 1;
}

stock GenerateTopWins()
{
	mq_format("SELECT * FROM `players` ORDER BY `wygrane` DESC, `udzial` DESC LIMIT 10;");
	mq_send("OnTopWinsGenerated");
	return 1;
}

forward OnTopWinsGenerated();
public OnTopWinsGenerated()
{
	mq_getdata();
	new i;
	new nickname[24];
	new kraj[32];
	new miejsce;
	format(serwer[str_topwins], 1024, "");
	ClearTopUsedUID();
	if(rekordy)
	{
		while(i < cache_get_row_count())
		{
			new uid = cache_get_field_content_int(i, "id", MySQL);
			new udzialow = cache_get_field_content_int(i, "udzial", MySQL);
			if(!IsTopUsedUID(uid) && udzialow)
			{
				miejsce++;
				cache_get_field_content(i, "name", nickname, MySQL, 24);
				cache_get_field_content(i, "country", kraj, MySQL, 32);
				format(serwer[str_topwins], 1024, "%s"COL_WHITE"%d.\t"COL_GREEN"%s\t"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d\t"COL_YELLOW"%s\n", serwer[str_topwins], miejsce, nickname, cache_get_field_content_int(i, "wygrane", MySQL), udzialow, kraj);
				TopUseUID(uid);
			}
			i++;
		}
	}
	return 1;
}

Dialog:TOPWINS(playerid, response, listitem, inputtext[])
{
	dialog_MAPINFO(playerid, 1, 0, "NULL");
	return 1;
}


stock TopUseUID(c_uid)
{
	 if(lista_top_counter > MAX_TOP) return 0;
	 na_liscie[lista_top_counter] = c_uid;
	 lista_top_counter++;
	 return 1;
}
stock IsTopUsedUID(c_uid)
{
	 for(new r; r < MAX_TOP; r++)
	 {
			if(na_liscie[r] == c_uid) return 1;
	 }
	 return 0;
}
stock ClearTopUsedUID()
{
	 for(new r; r < MAX_TOP; r++)
	 {
			na_liscie[r] = 0;
	 }
	 lista_top_counter = 0;
	 return 1;
}

stock ShowMapInfo(playerid)
{
 new title[100], str[256];
 if(polak(playerid))
 {
	 format(title, 100, "%s Map info - "COL_GREEN"%s"COL_WHITE" by "COL_ORANGE"%s"COL_WHITE"", form(), MapInfo[Nazwa], MapInfo[Autor]);
	 format(str, 256, ""COL_WHITE"Nazwa:\t"COL_BLUE"%s\n"COL_WHITE"Autor:\t"COL_ORANGE"%s\n"COL_WHITE"Przegrana:\t"COL_YELLOW"%d razy\n"COL_WHITE"Like:\t"COL_GREEN"%d\n"COL_WHITE"Dislike:\t"COL_RED"%d\n{000000}msrace.com", MapInfo[Nazwa], MapInfo[Autor], MapInfo[played], MapInfo[like], MapInfo[dislike]);
	 Dialog_Show(playerid, MAPINFO, DIALOG_STYLE_TABLIST, title, str, "»»", "");
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_GREEN"%s"COL_WHITE" by "COL_ORANGE"%s"COL_BROWN"***", MapInfo[Nazwa], MapInfo[Autor]);
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_WHITE"Like: "COL_GREEN"%d "COL_WHITE"| Dislike: "COL_RED"%d"COL_BROWN"***", MapInfo[like], MapInfo[dislike]);
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_WHITE"Przegrana: "COL_ORANGE"%d razy"COL_BROWN"***", MapInfo[played]);
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_WHITE"Wyłączenie muzyki: "COL_EASY"/stream"COL_BROWN"***", MapInfo[played]);
 }
 else
 {
	 format(title, 100, "%s Map info - "COL_GREEN"%s"COL_WHITE" by "COL_ORANGE"%s"COL_WHITE"", form(), MapInfo[Nazwa], MapInfo[Autor]);
	 format(str, 256, ""COL_WHITE"Name:\t"COL_BLUE"%s\n"COL_WHITE"Author:\t"COL_ORANGE"%s\n"COL_WHITE"Played:\t"COL_YELLOW"%d times\n"COL_WHITE"Likes:\t"COL_GREEN"%d\n"COL_WHITE"Dislikes:\t"COL_RED"%d\n{000000}msrace.com", MapInfo[Nazwa], MapInfo[Autor], MapInfo[played], MapInfo[like], MapInfo[dislike]);
	 Dialog_Show(playerid, MAPINFO, DIALOG_STYLE_TABLIST, title, str, "»»", "");
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_GREEN"%s"COL_WHITE" by "COL_ORANGE"%s"COL_BROWN"***", MapInfo[Nazwa], MapInfo[Autor]);
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_WHITE"Likes: "COL_GREEN"%d "COL_WHITE"| Dislikes: "COL_RED"%d"COL_BROWN"***", MapInfo[like], MapInfo[dislike]);
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_WHITE"Played: "COL_ORANGE"%d times"COL_BROWN"***", MapInfo[played]);
	 SendClientMessageEx(playerid, 0x6E2500FF, "***"COL_WHITE"Disable audio stream: "COL_EASY"/stream"COL_BROWN"***", MapInfo[played]);
 } 
 return 1;
}

stock ShowTop10Map(playerid)
{
	new title[100];
	format(title, 100, "~y~Top 10 - Map: ~b~%s~y~ by ~g~%s", MapInfo[Nazwa], MapInfo[Autor]);
	TopWindowShow(playerid, title, MapInfo[win_str_nickname], MapInfo[win_str_time]);
	return 1;
}