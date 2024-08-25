#define sqluser "user"//your sql user
#define sqlpass "pass"//your sql password
#define sqldb "race_server"//your sql database name
#define sqlhost "127.0.0.1"//sql host

new MySQL;
new mQuery[1024];
#define mq_format( mysql_format(MySQL, mQuery, 1024,
#define mq_send( mysql_pquery(MySQL, mQuery,
#define mq_getdata() new rekordy, pola; cache_get_data(rekordy, pola, MySQL)

forward OnAccountLoad(playerid);
public OnAccountLoad(playerid)
{
	//***********************************************************************************************************************************
	sgracz[playerid][uID] = cache_get_field_content_int(0, "id");
	SetPlayerScore(playerid, cache_get_field_content_int(0, "score"));
	sgracz[playerid][udzial] = cache_get_field_content_int(0, "udzial");
	sgracz[playerid][ukonczone] = cache_get_field_content_int(0, "ukonczone");
	sgracz[playerid][wygrane] = cache_get_field_content_int(0, "wygrane");
	sgracz[playerid][zebranecp] = cache_get_field_content_int(0, "zebranecp");
	sgracz[playerid][skin] = cache_get_field_content_int(0, "skin");
	sgracz[playerid][TimeOnline] = cache_get_field_content_int(0, "TimeOnline");
	sgracz[playerid][maxkmh] = cache_get_field_content_int(0, "maxkmh");
	sgracz[playerid][adminlvl] = cache_get_field_content_int(0, "adminlvl");
	sgracz[playerid][ReportedTimes] = cache_get_field_content_int(0, "ReportedTimes");
	sgracz[playerid][mute_stamp] = cache_get_field_content_int(0, "mute_stamp");
	sgracz[playerid][vcolor1] = cache_get_field_content_int(0, "vcolor1");
	sgracz[playerid][vcolor2] = cache_get_field_content_int(0, "vcolor2");
	sgracz[playerid][pcolor] = cache_get_field_content_int(0, "pcolor");
	sgracz[playerid][wheeltype] = cache_get_field_content_int(0, "wheeltype");
	sgracz[playerid][neoncolor] = cache_get_field_content_int(0, "neoncolor");
	sgracz[playerid][vip_stamp] = cache_get_field_content_int(0, "vip");
	//***********************************************************************************************************************************
	SetSpawnInfo(playerid, 0, sgracz[playerid][skin], CP[0][cX], CP[0][cY], CP[0][cZ], CP[0][cR], 0, 0, 0, 0, 0, 0);
	format(sgracz[playerid][p_ip], 24, "%s", playerip(playerid));//cache ip
	sgracz[playerid][login_stamp] = gettime();
	mq_format("UPDATE `players` SET `country`='%s', `ip`='%s', `online`='1', `LastOnline`='%d' WHERE `id`='%d';", country(playerid, true), playerip(playerid, true), gettime(), sgracz[playerid][uID]);
	mq_send("QUERY");
	ShowScreen(playerid);
	ShowMapInfo(playerid);
	LoadPlayerTD(playerid);
	if(!serwer[wyscig]) ShowTop10Map(playerid);
	PlayerPlaySound(playerid, 1063, 0.0, 0.0, 0.0);
	if(serwer[wyscig]) PlayMusic(playerid);
	loginset(playerid, 1);
	SendClientMessageToAllEN(-1, "%s {%06x}%s"COL_YELLOW"[%s]"COL_WHITE" has "COL_GREEN"logged"COL_WHITE" on to the game.", form(), sgracz[playerid][pcolor] >>> 8, nick(playerid), country(playerid));
	SendClientMessageToAllPL(-1, "%s {%06x}%s"COL_YELLOW"[%s]"COL_GREEN" zalogował"COL_WHITE" się do gry.", form(), sgracz[playerid][pcolor] >>> 8, nick(playerid), country(playerid));
	if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s Hasło "COL_GREEN"poprawne"COL_WHITE"! Witaj z powrotem!", form());
	else SendClientMessageEx(playerid, -1, "%s Login "COL_GREEN"succeeded"COL_WHITE"! Welcome back!", form());
	if(admin(playerid)) SendClientMessageEx(playerid, 0xFF0000FF, "»» You are admin. You have a "COL_WHITE"[%d]"COL_RED" permission level. Use: "COL_GREEN"/acmd", admin(playerid));
	if(!IsPlayerInAnyVehicle(playerid)) SpawnPlayer(playerid);
	return 1;
}

forward OnAccountRegister(playerid);
public OnAccountRegister(playerid)
{
    //***********************************************************************************************************************************
    sgracz[playerid][uID] = cache_insert_id();
    sgracz[playerid][skin] = 50;
    sgracz[playerid][login_stamp] = gettime();
    sgracz[playerid][vcolor1] = 25;
    sgracz[playerid][vcolor2] = 25;
    sgracz[playerid][pcolor] = def_pcolor;
    //***********************************************************************************************************************************
    printf("[NEW ACCOUNT]Name: %s | UID: %d | Country: %s | IP: %s", nick(playerid), sgracz[playerid][uID], country(playerid), playerip(playerid));
    SetSpawnInfo(playerid, 0, sgracz[playerid][skin], CP[0][cX], CP[0][cY], CP[0][cZ], CP[0][cR], 0, 0, 0, 0, 0, 0);
    format(sgracz[playerid][p_ip], 24, "%s", playerip(playerid));//cache ip
    sgracz[playerid][login_stamp] = gettime();
    ShowScreen(playerid);
    ShowMapInfo(playerid);
    LoadPlayerTD(playerid);
    if(!serwer[wyscig]) ShowTop10Map(playerid);
    PlayerPlaySound(playerid, 1063, 0.0, 0.0, 0.0);
    if(serwer[wyscig]) PlayMusic(playerid);
    loginset(playerid, 1);
    SendClientMessageToAllEN(-1, "%s {%06x}%s"COL_YELLOW"[%s]"COL_WHITE" has "COL_GREEN"logged"COL_WHITE" on to the game.", form(), sgracz[playerid][pcolor] >>> 8, nick(playerid), country(playerid));
    SendClientMessageToAllPL(-1, "%s {%06x}%s"COL_YELLOW"[%s] "COL_GREEN" zalogował"COL_WHITE" się do gry.", form(), sgracz[playerid][pcolor] >>> 8, nick(playerid), country(playerid));
    if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s Rejestracja "COL_GREEN"powiodła się"COL_WHITE"! Powodzenia!", form());
    else SendClientMessageEx(playerid, -1, "%s Register "COL_GREEN"succeeded"COL_WHITE"! Good luck!", form());
    if(!IsPlayerInAnyVehicle(playerid)) SpawnPlayer(playerid);
    return 1;
}

native GetConsoleVarAsInt(const varname[]);
stock ConnectDB()
{
	new serverPort = GetConsoleVarAsInt("port");
	if(serverPort == 7777)
	{
		MySQL = mysql_connect(sqlhost, sqluser, sqldb, sqlpass, 3306, true, 3);
		print("[CONNECT]Lacze z "sqlhost"...");
	}
	else
	{
		MySQL = mysql_connect("127.0.0.1", sqluser, sqldb, sqlpass, 3306, true, 3);
		print("[CONNECT]Lacze z  localhost...");
	}
	if(mysql_errno() != 0) printf("[CONNECT]BLAD POLACZENIA Z BAZA DANYCH! - EXIT..."), SendRconCommand("exit");
	else printf("[CONNECT]Polaczono z baza danych.");
	return 1;
}

stock LoginPlayer(playerid)
{
	mq_format("SELECT `password` FROM `players` WHERE `name`='%s' LIMIT 1;", nick(playerid, true));
	mq_send("OnAccountCheck", "d", playerid);
	return 1;
}

forward OnAccountCheck(playerid);
public OnAccountCheck(playerid)
{
	mq_getdata();
	if(rekordy)
	{
		cache_get_field_content(0, "password", sgracz[playerid][upass], MySQL, 128);
		if(polak(playerid)) Dialog_Show(playerid, LOGOWANIE, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" LOGOWANIE - MasterRace", ""COL_WHITE"Aby "COL_GREEN"zagrać"COL_WHITE" musisz się "COL_BLUE"zalogować"COL_WHITE".", "Login", "Wyjdz");
		else Dialog_Show(playerid, LOGOWANIE, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" LOGIN - MasterRace", ""COL_WHITE"In order to "COL_GREEN"play"COL_WHITE", you "COL_BLUE"need to login"COL_WHITE".", "Login", "Quit");
	}
	else
	{
		if(polak(playerid)) Dialog_Show(playerid, REJESTRACJA, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" REJESTRACJA - MasterRace", ""COL_WHITE"Aby "COL_GREEN"zagrać"COL_WHITE" musisz się "COL_RED"zarejestrować"COL_WHITE".", "Rejestruj", "Wyjdz");
		else Dialog_Show(playerid, REJESTRACJA, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" REGISTER - MasterRace", ""COL_WHITE"In order to "COL_GREEN"play"COL_WHITE", you "COL_RED"need to register"COL_WHITE".", "Register", "Quit");
	}
	return 1;
}

Dialog:LOGOWANIE(playerid, response, listitem, inputtext[])
{
	if(!response) return KickEx(playerid, -1, "Click 'Quit'.", false);
	if(!strlen(inputtext)) 
	{
		if(polak(playerid)) Dialog_Show(playerid, LOGOWANIE, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" LOGOWANIE - MasterRace", ""COL_WHITE"Aby "COL_GREEN"zagrać"COL_WHITE" musisz się "COL_BLUE"zalogować"COL_WHITE".", "Login", "Wyjdz");
		else Dialog_Show(playerid, LOGOWANIE, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" LOGIN - MasterRace", ""COL_WHITE"In order to "COL_GREEN"play"COL_WHITE", you "COL_BLUE"need to login"COL_WHITE".", "Login", "Quit");
		return 1;	
	}
	new str[130];
	format(str, 130, "%s", MD5_Hash(inputtext));
	if(!strcmp(str, sgracz[playerid][upass], true))
	{
		mq_format("SELECT * FROM `players` WHERE `name`='%s' LIMIT 1;", nick(playerid, true));
		mq_send("OnAccountLoad", "d", playerid);
	}
	else
	{
		SetPVarInt(playerid, "BadPass", GetPVarInt(playerid, "BadPass")+1);
		if(GetPVarInt(playerid, "BadPass") == 3) return KickEx(playerid, -1, "3/3 bad password.'");
		if(polak(playerid)) 
		{
			format(str, 130, ""COL_WHITE"Aby "COL_GREEN"zagrać"COL_WHITE" musisz się "COL_BLUE"zalogować"COL_WHITE".\nBłędnych prób: "COL_RED"%d/3", GetPVarInt(playerid, "BadPass"));
			Dialog_Show(playerid, LOGOWANIE, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" LOGIN - MasterRace", str, "Login", "Quit");
		}
		else
		{
			format(str, 130, ""COL_WHITE"In order to "COL_GREEN"play"COL_WHITE", you "COL_BLUE"need to login"COL_WHITE".\nBad password: "COL_RED"%d/3", GetPVarInt(playerid, "BadPass"));
			Dialog_Show(playerid, LOGOWANIE, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" LOGIN - MasterRace", str, "Login", "Quit");
		}
	}
	return 1;
}

Dialog:REJESTRACJA(playerid, response, listitem, inputtext[])
{
	if(!response) return KickEx(playerid, -1, "Click 'Quit'.", false);
	if(polak(playerid))
	{
		if(strlen(inputtext) < 4) return Dialog_Show(playerid, REJESTRACJA, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" REJESTRACJA - MasterRace", ""COL_WHITE"Aby "COL_GREEN"zagrać"COL_WHITE" musisz się "COL_RED"zarejestrować"COL_WHITE".\nHasło za krótkie(min: 4 znaki).", "Rejestruj", "Wyjdz");
		if(strlen(inputtext) > 16) return Dialog_Show(playerid, REJESTRACJA, DIALOG_STYLE_PASSWORD, " "COL_RED"»"COL_GREEN"»"COL_WHITE" REJESTRACJA - MasterRace", ""COL_WHITE"Aby "COL_GREEN"zagrać"COL_WHITE" musisz się "COL_RED"zarejestrować"COL_WHITE".\nHasło za długie(max: 16 znaków).", "Rejestruj", "Wyjdz");
	}
	else
	{
		if(strlen(inputtext) < 4) return Dialog_Show(playerid, REJESTRACJA, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" REGISTER - MasterRace", ""COL_WHITE"In order to "COL_GREEN"play"COL_WHITE", you "COL_RED"need to register"COL_WHITE".\nPassword too short(min: 4 chars).", "Register", "Quit");
		if(strlen(inputtext) > 16) return Dialog_Show(playerid, REJESTRACJA, DIALOG_STYLE_PASSWORD, " "COL_RED"»"COL_GREEN"»"COL_WHITE" REGISTER - MasterRace", ""COL_WHITE"In order to "COL_GREEN"play"COL_WHITE", you "COL_RED"need to register"COL_WHITE".\nPassword too long(max: 16 chars).", "Register", "Quit");
	}
	new str[130];
	format(str, 130, "%s", MD5_Hash(inputtext));
	mq_format("INSERT INTO `players` (`name`, `password`, `ip`, `country`, `skin`, `LastOnline`, `online`, `vcolor1`, `vcolor2`, `pcolor`) VALUES ('%s', '%s', '%s', '%s', '50', '%d', '1', '25', '25', '%d');", nick(playerid, true), str, playerip(playerid, true), country(playerid, true), gettime(), def_pcolor);
	mq_send("OnAccountRegister", "d", playerid);
	return 1;
}

stock SaveOnlineTime(playerid)
{
	if(gettime() - GetPVarInt(playerid, "SaveOnlineT") < 30) return 1;
	SetPVarInt(playerid, "SaveOnlineT", gettime());
	mq_format("UPDATE `players` SET `TimeOnline`='%d' WHERE `id`='%d';", sgracz[playerid][TimeOnline], sgracz[playerid][uID]);
	mq_send("QUERY");
	return 1;
}

stock CheckBan(playerid)
{
	mq_format("SELECT `BanList`.*,FROM_UNIXTIME(`BanList`.`time`) as `times`,FROM_UNIXTIME(`BanList`.`time_end`) as `time_ends`,`u1`.`name` AS `admin_nick`,`u2`.`name` AS `user_nick`,(`BanList`.`time_end`-UNIX_TIMESTAMP(CURRENT_TIMESTAMP)) as `left` FROM `BanList` LEFT OUTER JOIN `players` AS `u1` ON `BanList`.`aid`=`u1`.`id` LEFT OUTER JOIN `players` AS `u2` ON `BanList`.`uid`=`u2`.`id` WHERE `BanList`.`time_end`>UNIX_TIMESTAMP(CURRENT_TIMESTAMP) AND (`u2`.`name` LIKE '%s' OR  (`BanList`.`ip`='%s' AND `BanList`.`ip_on`='1') OR (`BanList`.`gpci`='%s' AND `BanList`.`gpci_on`='1'));", nick(playerid, true), playerip(playerid, true), serial(playerid, true));
	mq_send("OnBanChecked", "d", playerid);
	return 1;
}

forward OnBanChecked(playerid);
public OnBanChecked(playerid)
{
	mq_getdata();
	new b_id, b_ip[20], b_serial[50], reason[128], b_admin[20], b_user[20], b_start[32], b_end[24], left_time;
	new ip_on, gpci_on, a_id;
	new i;
	if(rekordy)
	{
		while(i < cache_get_row_count())
		{
			b_id = cache_get_field_content_int(i, "id");
			ip_on = cache_get_field_content_int(i, "ip_on");
			cache_get_field_content(i, "ip", b_ip);
			gpci_on = cache_get_field_content_int(i, "gpci_on");
			cache_get_field_content(i, "gpci", b_serial);
			cache_get_field_content(i, "reason", reason);
			a_id = cache_get_field_content_int(i, "aid");
			if(a_id)
			{
				cache_get_field_content(i, "admin_nick", b_admin);
			}
			else
			{
				format(b_admin, 20, "SYSTEM");
			}
			cache_get_field_content(i, "user_nick", b_user);
			cache_get_field_content(i, "times", b_start);
			cache_get_field_content(i, "time_ends", b_end);
			left_time = cache_get_field_content_int(i, "left");
			if(compare(nick(playerid), b_user))
			{
			 	ShowBanInfo(playerid, b_id, b_admin, b_user, b_start, b_end, reason, left_time);
			 	break;
			}
			else if(compare(playerip(playerid), b_ip) && ip_on)
			{
				ShowBanInfo(playerid, b_id, b_admin, b_user, b_start, b_end, reason, left_time);
				break;
			}
			else if(compare(serial(playerid), b_serial) && gpci_on)
			{
				ShowBanInfo(playerid, b_id, b_admin, b_user, b_start, b_end, reason, left_time);
				break;
			}
			i++;
		}
	}
	return 1;
}

stock ShowBanInfo(playerid, banid, admin[], user[], nadane[], koniec[], powod[], dokonca)
{
	const contstr = 1600;
	new title[128], content[contstr];
	if(polak(playerid))
	{
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" BAN INFO"COL_RED"[ID: %d]", banid);
		format(content, contstr, ""COL_GREY"Ban ID:\t\t"COL_RED"%d\n", banid);
		format(content, contstr, "%s"COL_GREY"Admin:\t\t"COL_RED"%s\n", content, admin);
		if(compare(user, "NULL"))
		{
			format(content, contstr, "%s"COL_GREY"Konto:\t"COL_YELLOW"Nie zarejestrowane\n", content);
		}
		else
		{
			format(content, contstr, "%s"COL_GREY"Konto:\t"COL_YELLOW"%s\n", content, user);
		}
		format(content, contstr, "%s"COL_GREY"IP:\t\t"COL_YELLOW"%s\n", content, playerip(playerid));
		format(content, contstr, "%s"COL_GREY"Powód:\t"COL_ORANGE"%s\n", content, powod);
		format(content, contstr, "%s"COL_GREY"Data nadania:\t"COL_BLUE"%s\n", content, nadane);
		format(content, contstr, "%s"COL_GREY"Wygasa:\t"COL_BLUE"%s\n", content, koniec);
		new day_s, hour_s, minute_s, sec_s;
		SecToTime(dokonca, day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Pozostało:\t"COL_GREEN"%dd, %dh, %dm, %ds\n", content,  day_s, hour_s, minute_s, sec_s);
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, title, content, "Zamknij", "");
		KickEx(playerid, -1, "Ban is active", false);
	}
	else
	{
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" BAN INFO"COL_RED"[ID: %d]", banid);
		format(content, contstr, ""COL_GREY"Ban ID:\t\t"COL_RED"%d\n", banid);
		format(content, contstr, "%s"COL_GREY"Admin:\t\t"COL_RED"%s\n", content, admin);
		if(compare(user, "NULL"))
		{
			format(content, contstr, "%s"COL_GREY"Account:\t"COL_YELLOW"Not registered\n", content);
		}
		else
		{
			format(content, contstr, "%s"COL_GREY"Account:\t"COL_YELLOW"%s\n", content, user);
		}
		format(content, contstr, "%s"COL_GREY"IP:\t\t"COL_YELLOW"%s\n", content, playerip(playerid));
		format(content, contstr, "%s"COL_GREY"Reason:\t"COL_ORANGE"%s\n", content, powod);
		format(content, contstr, "%s"COL_GREY"Date of grant:\t"COL_BLUE"%s\n", content, nadane);
		format(content, contstr, "%s"COL_GREY"End date:\t"COL_BLUE"%s\n", content, koniec);
		new day_s, hour_s, minute_s, sec_s;
		SecToTime(dokonca, day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Time left:\t"COL_GREEN"%dd, %dh, %dm, %ds\n", content,  day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"(Dates are consistent with the time zone: Central European Time)\n", content);
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, title, content, "Close", "");
		KickEx(playerid, -1, "Ban is active", false);
	}
	return 1;
}

stock BanPlayer(playerid, reason[])
{
	new perm  = MAX_VALUE;
	mq_format("INSERT INTO `BanList` (`uid`, `aid`, `time`, `time_end`, `ip_on`, `ip`, `gpci_on`, `gpci`, `reason`) VALUES ('%d', '0', '%d', '%d', '1', '%s', '0', '%s', '%s');", sgracz[playerid][uID], gettime(), perm, playerip(playerid, true), serial(playerid, true), reason);
	mq_send("BANQUERY");
	SendClientMessageToAllEN(0xFF0000AA, "|BAN| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"SYSTEM"COL_WHITE" | Reason: %s.", nick(playerid), reason);
	SendClientMessageToAllPL(0xFF0000AA, "|BAN| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"SYSTEM"COL_WHITE" | Powód: %s.", nick(playerid), reason);
	KickEx(playerid, -1, reason, false);
	return 1;
}

stock BanTime(playerid, reason[], days)
{
	new czas = (days*24*60*60)+gettime();
	mq_format("INSERT INTO `BanList` (`uid`, `aid`, `time`, `time_end`, `ip_on`, `ip`, `gpci_on`, `gpci`, `reason`) VALUES ('%d', '0', '%d', '%d', '1', '%s', '0', '%s', '%s');", sgracz[playerid][uID], gettime(), czas, playerip(playerid, true), serial(playerid, true), reason);
	mq_send("BANQUERY");
	SendClientMessageToAllEN(0xFF0000AA, "|BAN| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"SYSTEM"COL_WHITE" | Reason: %s | Time: %d days", nick(playerid), reason, days);
	SendClientMessageToAllPL(0xFF0000AA, "|BAN| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"SYSTEM"COL_WHITE" | Powód: %s | Czas: %d dni", nick(playerid), reason, days);
	KickEx(playerid, -1, reason, false);
	return 1;
}

public OnQueryError(errorid, error[], callback[], query[], connectionHandle)
{
	switch(errorid)
	{
		case 2013:
		{
			printf("[CONNECT]Polaczenie z baza danych utracone - blokuje serwer...");
			SendRconCommand("password blockbymysql");
			SetGameModeText("MAINTANCE");
			for(new k; k <= GetPlayerPoolSize(); k++)
			{
				if(IsPlayerConnected(k))
				{
					KickEx(k, -1, "MAINTANCE");
				}
			}
		}
	}
	printf("|QERROR| eid: %d | err: %s | call: %s | query: %s", errorid, error, callback, query);
	return 1;
}
