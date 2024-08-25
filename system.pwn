//*********************AUTORZY***********************************
//Autorem skryptu jest właściciel mail: sebaqq6@gmail.com
//*********************PRAGMA***********************************
#pragma dynamic 10000
//*********************INCLUDE***********************************
#include "includes/a_samp.inc"
#include "qqbuild.inc"
#include "includes/a_http.inc"
#include "includes/a_mysql.inc"
#include "includes/Pawn.CMD.inc"
#include "includes/sscanf2.inc"
#include "includes/dinix.inc"
#include "includes/easyDialog.inc"
#include "includes/md5.inc"
#include "includes/streamer.inc"
#include "includes/arrow.inc"
#include "includes/geolocation.inc"
#include "includes/qq.inc"
#include "includes/OPA.inc"
//*********************MODUŁY***********************************
#include "modules/define.inc"//Definicje.
#include "modules/ram.inc"//Po prostu RAM, czyli dane na których pracuje skrypt. 
#include "modules/database.inc"//Baza danych.
#include "modules/utils.inc"//Przydatne funkcje.
#include "modules/checkpoint.inc"//CheckPoint system.
#include "modules/mapmenager_mysql.inc"//Menadżer map, zarządza mapami 
#include "modules/spectator.inc"//Moduł obsługujący speca.
#include "modules/playercmd.inc"//Komendy gracza.
#include "modules/admincmd.inc"//Komendy admina.
#include "modules/textdraw.inc"//Textdrawy
#include "modules/mapcreator.inc"//Moduł do tworzenia map (zalecane pracować na lokalhoście)
//*********************BRUDNOPIS******************************
/*
i=next cheat id 7
- ever nitro kup
- fix przeciwnicy
- spec
- rakieta 
soundtrack:
despacito
shaunbaker - vip
pitbull i know want me
sandra lyng - play my drum
more than you know - axwell & ingrasso
Kalwi & Remi - Explosion
East Clubbers - Sextasy
C-Bool - Trebles
C-Bool-House Baby
Dj Hazel - Weź Pigułke - need rework
Jeckyll & Hyde - Freefall
Kim Cesarion - Undressed
mccgayver soundtrack theme
THE BEST THE BEST THE BEST THE BEST THE BEST THE BEST THE BEST THE BEST
Sandu Ciorba - Pe cimpoi
Time won't wait - filatov and karas
alexander rybak kotik
Taylor Swift - Bad blood
Alan Walker - Faded
Aronchupa - little swing
Aronchupa - litving room i cos jeszcze
Basshunter - I Can Walk On Water
Benny Hill Theme
NOMA - Brain Power
Crazy Frog - Axel F
Riptide - Vance Joy
DJ Got Us Falling  In Love - usher feat pitbull
Benny Benassi Stop Go
maja he maja ha
rasputin
Guile's theme
Mortal Kombat Theme Song Original
Caramell - Caramelldansen HD Version (Swedish Original)
Trance - 009 Sound System Dreamscape (HD)
Super Eurobeat Mix
Ultimate Nightcore Empyre One Mix
What about us - Pink
*/
//*********************SKRYPT***********************************
new VER[32];
main(){}

public OnGameModeInit()
{
	format(VER, 32, "MSRace (build: %d)", QQBUILD);
	print("\n----------------------------------");
	printf("%s system by sebaqq6 init...", VER);
	print("----------------------------------\n");
	SetGameModeText(VER);
	ConnectDB();
	printf("[LOAD]Wstepna konfiguracja...");
	SetNameTagDrawDistance(300);
	//DisableNameTagLOS();
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(false);
	EnableVehicleFriendlyFire();
	mq_format("UPDATE `players` SET `online`='0';");
	mq_send("QUERY");
	SendRconCommand("hostname •••••••••»MasterRace - Just drive...«••••••••••");
	SendRconCommand("language PL/EN/RU/ES/BR/ALL");
	Streamer_SetTickRate(100);
	AddPlayerClass(1, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);//Wiadomo.
	SetTimer("Process_Server", 100, true);//proces serwerowy.
	LoadGlobalTD();//TextDrawy
	//podium
	WygenerujPodium();
	//koniec podium.
	printf("[LOAD]Inicjalizacja systemu map...");
	MapLoader();//Inicjalizacja map loadera.
	printf("[LOAD]Wszystkie systemy zaladowane!");
	return 1;
}

public OnGameModeExit()
{
	mq_format("UPDATE `players` SET `online`='0';");
	mq_send("QUERY");
	mysql_close(MySQL), print("[CONNECT] Polaczenie z MySQL zostalo zamkniete.");
	return 1;
}

forward Process_Server();
public Process_Server()
{
	//if(GetTickCount() - serwer[ps_exe] < 100) return 1;
	serwer[ms]++;
	serwer[extrams]++;
	static second_step;
	second_step = 0;
	if(serwer[ms] == 10)//co sekunde
	{
		second_step = 1;
		serwer[ms] = 0;
		serwer[sec]++;
		serwer[eSec]--;
		if(serwer[eSec] < 0)
		{
			serwer[eMin]--;
			serwer[eSec] = 59;
		}
		//end map voting
		if(serwer[eSec] == 50 && serwer[eMin] == -1 && serwer[wyscig] == false) EndVote();
		if(serwer[eMin] == 0)
		{
			//Koniec mapy, głosowanie itd...
			if(serwer[eSec] == 0 && serwer[wyscig])
			{
				serwer[wyscig] = false;
				serwer[voting] = true;
				serwer[glosy_r] = 0;
				serwer[glosy_n] = 0;
				if(POnline())
				{
					mq_format("INSERT INTO `map_race_history` (`mid`, `count`, `count_finished`, `start`, `end`) VALUES ('%d', '%d', '%d', '%d', '%d');", ActualMapID(), POnline(), PFinished(), MapInfo[started], gettime());
					mq_send("QUERY");
					mq_format("UPDATE `map_lista` SET `played`=`played`+'1' WHERE `id`='%d';", ActualMapID());
					mq_send("QUERY");
				}
				for(new p; p <= GetPlayerPoolSize(); p++)
				{
					if(polak(p)) SendClientMessageEx(p, -1, "%s "COL_LIME"Mapa ukończona. "COL_GREEN"Głosowanie uruchomione...", form());
					else SendClientMessageEx(p, -1, "%s "COL_LIME"Map completed. "COL_GREEN"Vote started...", form());
					if(login(p))
					{
						if(polak(p)) Dialog_Show(p, VOTE, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Głosowanie", "Następna mapa czy restart tej mapy?", "Nastepna", "Restart");
						else Dialog_Show(p, VOTE, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Voting", "Next map or play again?", "Next", "Replay");
					}
				}
			}
		}
		if(serwer[odliczanie])
		{ 
			Odlicz();
		}
		else
		{
			OdliczEnd();
		}
		SecondTimer();
		reCountPos();
		RandomHostname();
		Bot();
		new hTime[24];
		static dk;
		if(serwer[eMin] == -1)
		{
			if(dk) format(hTime, 24, "~b~00~w~:~b~%02d", serwer[eSec]-50), dk = 0;
			else format(hTime, 24, "~b~00~l~:~b~%02d", serwer[eSec]-50), dk = 1;
		}
		else
		{
			if(dk) format(hTime, 24, "~r~%02d~w~:~g~%02d", serwer[eMin], serwer[eSec]), dk = 0;
			else format(hTime, 24, "~r~%02d~l~:~g~%02d", serwer[eMin], serwer[eSec]), dk = 1;
		}
		TextDrawSetString(HeadTimeTD, hTime);
	}
	if(serwer[sec] == 60)
	{
		serwer[sec] = 0;
		serwer[m]++;
	}
	if(serwer[wyscig])
	{
		for(new p; p <= GetPlayerPoolSize(); p++)
		{
			if(spawned(p))
			{
				if(!tgracz[p][ukonczyl] && login(p))
				{ 
					PickupCheck(p);
					String_pTime(p, serwer[m], serwer[sec], serwer[ms]);
					new pos = tgracz[p][CP_ID];
					GetPlayerPos(p, tgracz[p][cx], tgracz[p][cy], tgracz[p][cz]);
					tgracz[p][nextcp_distance] = floatround(GetDistanceBetweenPoints(tgracz[p][cx], tgracz[p][cy], tgracz[p][cz], CP[pos][cX], CP[pos][cY], CP[pos][cZ])-12);
					if(tgracz[p][nextcp_distance] > 0)
					{
						String_nextcpTD(p, tgracz[p][nextcp_distance]);
					}
					else
					{
						String_nextcpTD(p, 0);
					}
					String_PosTD(p, GetPos(p), POnline());
				}
				else
				{
					String_nextcpTD(p, 0);
				}
			}
			if(second_step)
			{
				if(tgracz[p][songtime] > 0) tgracz[p][songtime]--;
				else PlayMusic(p);
			}
		}
	}
	Process_CheckPoint();
	CheckRockets();
	//serwer[ps_exe] = GetTickCount();
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(!login(playerid)) return 0;
	if(sgracz[playerid][mute_stamp] > gettime())
	{
		if(polak(playerid)) SendClientMessageEx(playerid, -1, ""COL_RED"|BŁĄD|"COL_WHITE" Jesteś uciszony. Pozostało: "COL_RED"%d"COL_WHITE" sekund.", sgracz[playerid][mute_stamp] - gettime());
		else SendClientMessageEx(playerid, -1, ""COL_RED"|ERROR|"COL_WHITE" You are muted. Time left: "COL_RED"%d"COL_WHITE" sec.", sgracz[playerid][mute_stamp] - gettime());
		return 0;
	}
	new pText[512];
	if(text[0] == '`' && admin(playerid))
	{
		for(new a; a <= GetPlayerPoolSize(); a++)
		{
			if(!login(a)) continue;
			if(!admin(a)) continue;
			format(pText, 512, "@"COL_WHITE"|%d| "COL_BLUE"%s"COL_WHITE" » %s", playerid, nick(playerid), text[1]);
			SendClientMessage(a, 0xFF0000AA, pText);
		}
		return 0;
	}
	if(vip(playerid))
	{
		format(pText, 512, "|"COL_YELLOW"%d{B6C100}|VIP| {%06x}%s "COL_ORANGE"»"COL_WHITE" %s", playerid,  GetPlayerColor(playerid) >>> 8, nick(playerid), text);
	}
	else
	{
		format(pText, 512, "|"COL_BLUE"%d"COL_WHITE"| {%06x}%s "COL_ORANGE"»"COL_WHITE" %s", playerid,  GetPlayerColor(playerid) >>> 8, nick(playerid), text);
	}
	SendClientMessageToAll(-1, pText);
	format(pText, 512, "» %s",  text);
	SetPlayerChatBubble(playerid, pText, GetPlayerColor(playerid), 400.0, 15000);
	mysql_escape_string(text, text, MySQL, 256);
	mq_format("INSERT INTO `chat_log` (`uid`,`chat`) VALUES ('%d','%s');", sgracz[playerid][uID], text);
	mq_send("QUERY");
	return 0;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
    if(!login(playerid))
    {
        if(polak(playerid)) Error(playerid, "Musisz być zalogowany.");
        else Error(playerid, "You must be logged in.");
        return 0;
    }
    return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if(result == -1)
    {
    	new str[256];
    	if(polak(playerid)) format(str, 256, "Komenda "COL_BLUE"/%s "COL_RED"nie istnieje"COL_WHITE"! Jeśli potrzebujesz pomocy, wpisz: "COL_GREEN"/pomoc", cmd);
    	else format(str, 256, "Command "COL_BLUE"/%s "COL_RED"not found"COL_WHITE"! If you need help, type: "COL_GREEN"/help", cmd);
    	Error(playerid, str);
    	return 1;
    }
    return 1;
}

stock RandomHostname()
{
	if(gettime() - serwer[trand_hostname] < 8) return 1;
	switch(serwer[c_hostname])
	{
		case 0:
		{
			SendRconCommand("hostname •••••••••»Master Race - Advanced GameMode!«••••••••••");
			serwer[c_hostname]++;
		}
		case 1:
		{
			SendRconCommand("hostname •••••••••»Master Race - Check us out!«••••••••••");
			serwer[c_hostname]++;
		}
		case 2:
		{
			SendRconCommand("hostname •••••••••»Master Race - The best music!«••••••••••");
			serwer[c_hostname]++;
		}
		case 3:
		{
			SendRconCommand("hostname •••••••••»Master Race - Welcome!«••••••••••");
			serwer[c_hostname]++;
		}
		case 4:
		{
			SendRconCommand("hostname •••••••••»Master Race - Welcome!«••••••••••");
			serwer[c_hostname]++;
		}
		default:
		{
			SendRconCommand("hostname •••••••••»MasterRace - Check yourself!«••••••••••");
			serwer[c_hostname] = 0;
		}
	}
	serwer[trand_hostname] = gettime();
	return 1;
}

public OnPlayerConnect(playerid)
{
	loginset(playerid, 0);
	for(new Tpstats:x; x < Tpstats; x++)
	{
		tgracz[playerid][x] = 0;
	}
	for(new Spstats:y; y < Spstats; y++)
	{
		sgracz[playerid][y] = 0;
	}
	new kraj[24];
	GetPlayerCountry(playerid, kraj);
	if(!strcmp(kraj, "Poland", true)) sgracz[playerid][zpolski] = true;
	SetPVarInt(playerid, "RePMID", -1);
	SpdObj[playerid][0] = INVALID_OBJECT_ID;
	SpdObj[playerid][1] = INVALID_OBJECT_ID;
	SetPlayerColor(playerid, 0x00000000);
	CheckBan(playerid);
	PlayerPlaySound(playerid, 1062, 0.0, 0.0, 0.0);
	HideScreen(playerid);
	SetTimerEx("ConnectMessage", 100, false, "d", playerid);
	return 1;
}

forward ConnectMessage(playerid);
public ConnectMessage(playerid)
{
	ClearChat(playerid);
	if(polak(playerid))
	{
		SendClientMessage(playerid, -1, ""COL_YELLOW"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|"COL_GREEN"Master Race"COL_YELLOW"|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		SendClientMessageEx(playerid, -1, ""COL_EASY"Witaj "COL_BLUE"%s"COL_EASY" na międzynarodowym serwerze race!", nick(playerid));
		SendClientMessage(playerid, -1, ""COL_EASY"Przeczytaj "COL_RED"regulamin"COL_EASY" serwera: "COL_RED"/rules"COL_DBLUE" (Serwer chroniony jest przez AntyCheat)");
		SendClientMessage(playerid, -1, ""COL_EASY"Jeśli wpadłeś z trasy, "COL_RED"nie poddawaj sie"COL_EASY"! Wciśnij "COL_RED"ENTER"COL_EASY" aby wczytać ostatnią poprawną pozycje.");
		SendClientMessage(playerid, -1, ""COL_EASY"Jeśli potrzebujesz "COL_GREEN"pomocy"COL_EASY" wpisz: "COL_RED"/pomoc");
		SendClientMessage(playerid, -1, ""COL_RED"UWAGA!"COL_EASY" Serwer jest międzynarodowy, jako iż jesteś z polski, 99%% napisów będzie w Twoim jezyku!");
		SendClientMessage(playerid, -1, "                                               "COL_LIME"Powodzenia "COL_EASY"&"COL_LIME" baw się dobrze"COL_EASY"!");
		SendClientMessage(playerid, -1, ""COL_YELLOW"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|"COL_GREEN"Master Racem"COL_YELLOW"|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	}
	else
	{
		SendClientMessage(playerid, -1, ""COL_YELLOW"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|"COL_GREEN"Master Race"COL_YELLOW"|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		SendClientMessageEx(playerid, -1, ""COL_EASY"Welcome "COL_BLUE"%s"COL_EASY" on the best race server!", nick(playerid));
		SendClientMessage(playerid, -1, ""COL_EASY"Read the "COL_RED"rules"COL_EASY" of the server: "COL_RED"/rules"COL_DBLUE" (The server has AntiCheat security)");
		SendClientMessage(playerid, -1, ""COL_EASY"If you rush out from the route, "COL_RED"don't give up"COL_EASY"! Press "COL_RED"ENTER"COL_EASY" to load the last correct position!");
		SendClientMessage(playerid, -1, ""COL_EASY"For "COL_GREEN"more help"COL_EASY" type: "COL_RED"/help");
		SendClientMessage(playerid, -1, "                                               "COL_LIME"Good Luck "COL_EASY"&"COL_LIME" Have Fun"COL_EASY"!");
		SendClientMessage(playerid, -1, ""COL_YELLOW"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|"COL_GREEN"Master Race"COL_YELLOW"|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	}
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetSpawnInfo(playerid, 0, 50, CP[0][cX], CP[0][cY], CP[0][cZ], CP[0][cR], 0, 0, 0, 0, 0, 0);
	SpawnPlayer(playerid);
	tgracz[playerid][CP_ID] = 0;
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	Spec_OtherSpec(playerid);
	if(login(playerid))
	{
		mq_format("UPDATE `players` SET `online`='0' WHERE `id`='%d';", sgracz[playerid][uID]);
		mq_send("QUERY");
		mq_format("INSERT INTO `LoginHistory` (`uid`, `ip`, `gpci`, `login`, `logout`) VALUES ('%d', '%s', '%s', '%d', '%d');", sgracz[playerid][uID], sgracz[playerid][p_ip], serial(playerid, true), sgracz[playerid][login_stamp], gettime());
		mq_send("QUERY");
		switch(reason)
		{
			case 0: 
			{
				SendClientMessageToAllEN(-1, ""COL_EASY"» {%06x}%s"COL_GREY" has left the server. "COL_EASY"(Timeout)", GetPlayerColor(playerid) >>> 8, nick(playerid));
				SendClientMessageToAllPL(-1, ""COL_EASY"» {%06x}%s"COL_GREY" opuścił serwer. "COL_EASY"(Timeout)", GetPlayerColor(playerid) >>> 8, nick(playerid));
			}
			case 1:
			{
				SendClientMessageToAllEN(-1, ""COL_EASY"» {%06x}%s"COL_GREY" has left the server. "COL_EASY"(Leaving)", GetPlayerColor(playerid) >>> 8, nick(playerid));
				SendClientMessageToAllPL(-1, ""COL_EASY"» {%06x}%s"COL_GREY" opuścił serwer. "COL_EASY"(Wyszedł)", GetPlayerColor(playerid) >>> 8, nick(playerid));
			}
		}
	}
	if(SpdObj[playerid][0] != INVALID_OBJECT_ID)
	{
		DestroyDynamicObject(SpdObj[playerid][0]);
		DestroyDynamicObject(SpdObj[playerid][1]);
	}
	DestroyLaser(playerid);
	RemovePlayerNeons(playerid);
	DestroyObjWeap(playerid);
	DestroyCP(playerid);
	loginset(playerid, 0);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
	AttachHelmet(playerid);
	if(!login(playerid))
	{ 
		new golf = CreateVehicle(457, CP[0][cX], CP[0][cY], CP[0][cZ], CP[0][cR], 1, 1, 20);
		SetVehicleVirtualWorld(golf, GetPlayerVirtualWorld(playerid));
		PutPlayerInVehicle(playerid, golf, 0);
		SetTimerEx("SobeitCheck_s1", 500, false, "dd", playerid, golf);
		SetPlayerCameraPos(playerid, 942.5928, 2592.5803, 29.4263);
		SetPlayerCameraLookAt(playerid, 943.2446, 2591.8179, 29.5013);
		return 1;
	}
	if(sgracz[playerid][cheats_detected])
	{
		if(polak(playerid)) SendClientMessage(playerid, -1, "|SYSTEM|"COL_RED" Wykryto cheaty!");
		else SendClientMessage(playerid, -1, "|SYSTEM|"COL_RED" Cheats detected!");
		sgracz[playerid][cheats_detected] = false;
		if(admin(playerid) < 2) return BanPlayer(playerid, "Mod s0beit");
	}
	String_weaponTD(playerid,"NONE", true);
	SetPlayerSkin(playerid, sgracz[playerid][skin]);
	SetPlayerColor(playerid, sgracz[playerid][pcolor]);
	SetPlayerTeam(playerid, 5);
	DisableRemoteVehicleCollisions(playerid, true);
	SetPVarInt(playerid, "Spawned", 1);
	new pos = tgracz[playerid][CP_ID];
	new car;
	FixVehicle(playerid);
	sgracz[playerid][checkboom] = false;
	tgracz[playerid][nitro_status] = 0;
	if(pos)
	{
		car = LoadPlayerPos(playerid);
	}
	else
	{
		car = CreateVehicle(MapInfo[vstart], CP[pos][cX], CP[pos][cY], CP[pos][cZ], CP[pos][cR], sgracz[playerid][vcolor1], sgracz[playerid][vcolor2], 9999, 0);
		SetVehicleVirtualWorld(car, GetPlayerVirtualWorld(playerid));
		PutIn(playerid, car, 0);
	}
	GetVehiclePos(car, tgracz[playerid][startX], tgracz[playerid][startY], tgracz[playerid][startZ]);
	GetVehicleZAngle(car, tgracz[playerid][startR]);
	LoadVehMod(playerid, car);
	HideSpeedo(playerid);
	ShowSpeedo(playerid);
	TogglePlayerControllable(playerid, serwer[wyscig]);
	SetCameraBehindPlayer(playerid);
	String_checkTD(playerid, pos, GetCountCheckpoints());
	DisableRemoteVehicleCollisions(playerid, true);
	AttachHelmet(playerid);
	DestroyLaser(playerid);
	Spec_ReSpecAction(playerid, car);
	if(tgracz[playerid][buynitro])
	{
		Function(playerid, NITRO, NONE);
	}
	if(pos > 1) SetPVarInt(playerid, "FreezeActive", gettime());
	return 1;
}

forward SobeitCheck_s1(playerid, vehid);
public SobeitCheck_s1(playerid, vehid)
{
	SetPlayerCameraPos(playerid, 942.5928, 2592.5803, 29.4263);
	SetPlayerCameraLookAt(playerid, 943.2446, 2591.8179, 29.5013);
	RemovePlayerFromVehicle(playerid);
	SetTimerEx("SobeitCheck_s2", 800, false, "dd", playerid, vehid);
	/*if(IsPlayerInAnyVehicle(playerid) && GetVehicleModel(GetPlayerVehicleID(playerid)) == 457)
	{
		RemovePlayerFromVehicle(playerid);
		SetTimerEx("SobeitCheck_s2", 800, false, "dd", playerid, vehid);
	}
	else
	{
		DestroyVehicle(vehid);
		if(polak(playerid)) SendClientMessage(playerid, -1, "|SYSTEM|"COL_RED" Wykryto Cheaty/Słabe połączenie. Sprawdź to i spróbuj ponownie się podłączyć.");
		else SendClientMessage(playerid, -1, "|SYSTEM|"COL_RED" Cheats/Slow connection detected! Check and try again.");
		KickEx(playerid, -1, "Cheats/Slow connection", false);
	}*/
	return 1;
}

forward SobeitCheck_s2(playerid, vehid);
public SobeitCheck_s2(playerid, vehid)
{
	DestroyVehicle(vehid);
	new wdata[2];
	SetPlayerCameraPos(playerid, 942.5928, 2592.5803, 29.4263);
	SetPlayerCameraLookAt(playerid, 943.2446, 2591.8179, 29.5013);
	GetPlayerWeaponData(playerid, 1, wdata[0], wdata[1]);
	if(wdata[0])
	{
		sgracz[playerid][cheats_detected] = true;
	}
	else
	{
		sgracz[playerid][cheats_detected] = false;
	}
	ResetPlayerWeapons(playerid);
	LoginPlayer(playerid);
	return 1;
}


public OnPlayerDeath(playerid, killerid, reason)
{
	if(GetPVarInt(playerid, "Spawned"))
	{
		SetPVarInt(playerid, "Spawned", 0);
		if(!tgracz[playerid][ukonczyl]) tgracz[playerid][CP_ID] = tgracz[playerid][CP_ID]  - 2;
		if(tgracz[playerid][CP_ID] < 0) tgracz[playerid][CP_ID] = 0;
		CreateCP(playerid);
	}
	HideSpeedo(playerid);
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	//RETRY
	if(tgracz[playerid][specuje])
	{
		if(PRESSED(KEY_JUMP))
		{
			Spec_Prev(playerid);
		}
		else if(PRESSED(KEY_SPRINT))
		{
			Spec_Next(playerid);
		}
	}
	if((PRESSED(KEY_SECONDARY_ATTACK)  && GetPVarInt(playerid, "Spawned")) && (serwer[eSec] >= 10 || serwer[eMin] >= 1) && !tgracz[playerid][ukonczyl] && serwer[wyscig])
	{
		if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
		SetPlayerHealth(playerid, 0);
		SetPVarInt(playerid, "InCar", 0);
	}
	if(newkeys & 128 && GetPVarInt(playerid, "Spawned"))//Spacja
	{
		if(tgracz[playerid][nitro_status])
		{ 
			new vid = GetPlayerVehicleID(playerid);
			RemoveVehicleComponent(vid, tgracz[playerid][nitro_status]);
			AddVehicleComponent(vid, tgracz[playerid][nitro_status]);
		}
	}
	//WEAPON's
	if(IsPlayerInAnyVehicle(playerid) && PRESSED(4)  && serwer[wyscig])
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		switch(tgracz[playerid][weapon])
		{
			case W_ROCKET:
			{
				if(IsValidObject(gRocketObj[playerid])) return 1;
				DestroyObjWeap(playerid);
				new Float:x,
				Float:y,
				Float:z,
				Float:r,
				Float:dist = 180.0,
				Float:vx,
				Float:vy,
				Float:vz,
				Float:vspeed;
				GetVehiclePos(vehicleid, x, y, z);
				GetVehicleZAngle(vehicleid, r);
				GetVehicleVelocity(vehicleid, vx, vy, vz);
				vspeed = floatsqroot( (vx*vx)+(vy*vy)+(vz*vz) );//3790
				gRocketObj[playerid] = CreateObject(3790, x + (7.5 * floatsin(-r, degrees)), y + (7.5 * floatcos(-r, degrees)), z+0.3, 0.0, 0.0, r-90);
				MoveObject(gRocketObj[playerid], x + (dist * floatsin(-r, degrees)), y + (dist * floatcos(-r, degrees)), z, (110.0 * vspeed) + 100.0);
				tgracz[playerid][weapon] = 0;
				DestroyLaser(playerid);
				String_weaponTD(playerid,"NONE", true);
				if(polak(playerid)) GameTextForPlayer(playerid, "RAKIETA ~r~WYSTRZELONA~w~!", 2000, 4);
				else GameTextForPlayer(playerid, "ROCKET ~r~LAUNCHED~w~!", 2000, 4);
			}
			case W_RAMP:
			{
					DestroyObjWeap(playerid);
					new Float:x, Float:y, Float:z, Float:r;
					GetVehiclePos(vehicleid, x, y, z);
					GetVehicleZAngle(vehicleid, r);
					GetXYInBackOfPlayer(playerid, x, y, 7.5);
					tgracz[playerid][o_weap] = CreateDynamicObject(1503, x, y, z-0.50, 0.0,0.0, r);
					new o = tgracz[playerid][o_weap];
					o_flag[o] = F_WEAP;
					tgracz[playerid][weapon] = 0;
					String_weaponTD(playerid,"NONE", true);
					if(polak(playerid)) GameTextForPlayer(playerid, "TYLNA-RAMPA ~r~USTAWIONA~w~!", 2000, 4);
					else GameTextForPlayer(playerid, "BACK-RAMP ~r~SET~w~!", 2000, 4);
			}
			case W_HAY:
			{
					DestroyObjWeap(playerid);
					new Float:x, Float:y, Float:z, Float:r;
					GetVehiclePos(vehicleid, x, y, z);
					GetVehicleZAngle(vehicleid, r);
					GetXYInBackOfPlayer(playerid, x, y, 7.5);
					tgracz[playerid][o_weap] = CreateDynamicObject(3374, x, y, z+0.60, 0.0,0.0, r);
					new o = tgracz[playerid][o_weap];
					o_flag[o] = F_WEAP;
					tgracz[playerid][weapon] = 0;
					String_weaponTD(playerid,"NONE", true);
					if(polak(playerid)) GameTextForPlayer(playerid, "SIANO ~r~USTAWIONE~w~!", 2000, 4);
					else GameTextForPlayer(playerid, "BACK-HAY ~r~SET~w~!", 2000, 4);
			}
			case W_SPIKE:
			{
					DestroyObjWeap(playerid);
					new Float:x, Float:y, Float:z, Float:r;
					GetVehiclePos(vehicleid, x, y, z);
					GetVehicleZAngle(vehicleid, r);
					GetXYInBackOfPlayer(playerid, x, y, 7.5);
					tgracz[playerid][o_weap] = CreateDynamicObject(2899, x, y, z-0.30, 0.0,0.0, r+90);
					new o = tgracz[playerid][o_weap];
					o_flag[o] = F_WEAP;
					tgracz[playerid][weapon] = 0;
					String_weaponTD(playerid,"NONE", true);
					if(polak(playerid)) GameTextForPlayer(playerid, "KOLCZATKA ~r~USTAWIONA~w~!", 2000, 4);
					else GameTextForPlayer(playerid, "SPIKE STRIP ~r~SET~w~!", 2000, 4);
			}
		}
	}
	return 1;
}


public OnPlayerUpdate(playerid)
{
	if(!login(playerid)) return 1;
	if(IsPlayerInAnyVehicle(playerid))
	{
		if(GetPlayerState(playerid) ==  PLAYER_STATE_PASSENGER)
		{
			RemovePlayerFromVehicle(playerid);
			BanPlayer(playerid, "Passenger");
		}
		/*if(tgracz[playerid][registerveh])
		{
			static vid;
			vid = GetPlayerVehicleID(playerid);
			new Float:pHP;
			GetVehicleHealth(vid, pHP);
			if(pHP >= 270)
			{
				if(tgracz[playerid][registerveh] != vid)
				{
					RemovePlayerFromVehicle(playerid);
					SendAdminMsg("Uwaga! Gracz %s możliwy CarControl.", nick(playerid));
					PowiadomOOCEx(playerid, "Uwaga! Gracz %s możliwy CarControl.", nick(playerid));
				}
			}
		}*/
	}

	sgracz[playerid][fps_drunk] = GetPlayerDrunkLevel(playerid);
	if(sgracz[playerid][fps_drunk] < 100)
	{
		SetPlayerDrunkLevel(playerid,2000);
	}
	else
	{
		if(sgracz[playerid][fps_drunklast] != sgracz[playerid][fps_drunk])
		{
			sgracz[playerid][fps_count] = sgracz[playerid][fps_drunklast] - sgracz[playerid][fps_drunk];
			if((sgracz[playerid][fps_count] > 0) && (sgracz[playerid][fps_count] < 200))
			{
				sgracz[playerid][fps] = sgracz[playerid][fps_count];
			}
			sgracz[playerid][fps_drunklast] = sgracz[playerid][fps_drunk];
		}
	}


	if(gettime() - GetPVarInt(playerid, "FreezeActive") < 3 || !serwer[wyscig])
	{
		if(IsPlayerInAnyVehicle(playerid))
		{
			SetVehicleVelocity(GetPlayerVehicleID(playerid), 0.0, 0.0, 0.0);
		}
	}
	else
	{
		static Keys,ud,lr;
		GetPlayerKeys(playerid,Keys,ud,lr);
		if(Keys) LoadSpeed(playerid);
	}

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		for(new i = 0; i < MAX_OBJECTS; i++)
		{
			if(o_flag[i] != F_WEAP) continue;
			if(GetDynamicObjectModel(i) != 2899) continue;
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(i, x, y, z);
			if(!IsPlayerInRangeOfPoint(playerid, 3.0, x, y, z)) continue;
			static panels, doors, lights, tires;
			new carid = GetPlayerVehicleID(playerid);
			GetVehicleDamageStatus(carid, panels, doors, lights, tires);
			tires = encode_tires(1, 1, 1, 1);
			UpdateVehicleDamageStatus(carid, panels, doors, lights, tires);
			DestroyDynamicObject(i);
			o_flag[i] = F_NONE;
			if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s Twoje opony zostały "COL_RED"przebite"COL_WHITE" - zostaną one "COL_GREEN"naprawione"COL_WHITE" w ciągu paru sekund.", form());
			else SendClientMessageEx(playerid, -1, "%s You have "COL_RED"flat tires"COL_WHITE" - they will be "COL_GREEN"repaired"COL_WHITE" after few seconds.", form());
		}
	}
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(!login(playerid)) return 1;
	if(oldstate == PLAYER_STATE_DRIVER)
	{
		if(newstate == PLAYER_STATE_ONFOOT)
		{
			if(GetPVarInt(playerid, "InCar"))
			{
				PutIn(playerid, GetPVarInt(playerid, "InCarID"), 0);
			}
		}
	}
	if(oldstate == PLAYER_STATE_PASSENGER)
	{
		if(newstate == PLAYER_STATE_ONFOOT)
		{
			if(GetPVarInt(playerid, "InCar"))
			{
				PutIn(playerid, GetPVarInt(playerid, "InCarID"), 2);
			}
		}
	}
	if(oldstate == PLAYER_STATE_ONFOOT)
	{
		if(newstate == PLAYER_STATE_DRIVER || PLAYER_STATE_PASSENGER)
		{
			SetPVarInt(playerid, "InCar", 1);
			SetPVarInt(playerid, "InCarID", GetPlayerVehicleID(playerid));
		}
	}
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
		if(!tgracz[playerid][ukonczyl] && serwer[wyscig]) SetPVarInt(playerid, "InCar", 0);
		return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

stock SecondTimer()
{
	for(new p; p <= GetVehiclePoolSize(); p++)//Robienie porządku z pustymi pojazdami na mapie
	{
		if(IsValidVehicle(p))
		{
			if(!IsVehicleInUse(p))
			{
				v_noactive[p]++;
			}
			else
			{
				v_noactive[p] = 0;
			}
			if(v_noactive[p] >= 4)
			{
				v_noactive[p] = 0;
				DestroyVehicle(p);
			}
		}
	}

	for(new y; y <= GetPlayerPoolSize(); y++)//Sekundowo dla wszystkich
	{
		if(login(y))
		{
			sgracz[y][TimeOnline]++;
			SaveOnlineTime(y);
			DisableRemoteVehicleCollisions(y, true);
			CheckPing(y);
			String_FpsPing(y, sgracz[y][fps], GetPingAvarge(y));
			Process_OppData(y);
			UpdateSpeedo(y);
			if(GetPlayerMoney(y) != GetPlayerScore(y))
			{
				ResetPlayerMoney(y);
				GivePlayerMoney(y, GetPlayerScore(y));
			}
			if(GetPlayerWeapon(y))
			{
				if(GetPlayerWeapon(y) != 46)
				{
					BanPlayer(y, "Weapon hack");
				}
			}
			if(!IsPlayerInAnyVehicle(y) && spawned(y) && !tgracz[y][ukonczyl])
			{
				SetPVarInt(y, "PNoVeh", GetPVarInt(y, "PNoVeh")+1);
				if(GetPVarInt(y, "PNoVeh") >= 5)
				{
					SetPVarInt(y, "PNoVeh", 0);
					SetPlayerHealth(y, 0);
					if(polak(y)) SendClientMessageEx(y, -1, "%s Zostałeś/aś zabity/a! - Potrzebujesz pojazdu.", form());
					else SendClientMessageEx(y, -1, "%s You died - you need a new vehicle!", form());
				}
			}
			else
			{
				SetPVarInt(y, "PNoVeh", 0);
				new carid = GetPlayerVehicleID(y);
				//SendClientMessageToAllEx(-1, "speed: %d", GetVehicleSpeed(carid));
				if(GetVehicleSpeed(carid) > 360 && serwer[sh_check])
				{
					SetPVarInt(y, "SH_Warn", GetPVarInt(y, "SH_Warn") + 1);
					if(GetPVarInt(y, "SH_Warn") > 3)
					{
						BanPlayer(y, "Speed Hack");
					}
				}
				//anty vehicle HP cheat
				/*new Float:veHP = 0.0;
				GetVehicleHealth(carid, veHP);
				if(veHP <= 250.0 && !sgracz[y][checkboom])
				{
					sgracz[y][checkboom] = true;
					SetTimerEx("CheckVBoom", 1000*14, false, "d", y);
				}
				if(veHP < tgracz[y][vHP])
				{
					tgracz[y][vHP] = veHP;
				}
				else if(veHP-100.0 > tgracz[y][vHP] && tgracz[y][cheat0_p] < gettime() && !tgracz[y][ukonczyl])
				{
					printf("|DEBUG|HP Desync: niezgodnosc: %f > %f => puszczam check i ustawiam ok wartosc...", veHP-1.0, tgracz[y][vHP]);
					SetVehicleHealth(carid, tgracz[y][vHP]);
					SetTimerEx("ReCheckVHP", 100, false, "d", y);
				}*/
				new panels, doors, lights, tires;
				GetVehicleDamageStatus(carid, panels, doors, lights, tires);
				if(tires == 15 || tires == 3) SetPVarInt(y, "FixTires", GetPVarInt(y, "FixTires")+1);
				else SetPVarInt(y, "FixTires", 0);

				if(GetPVarInt(y, "FixTires") >= 4)
				{
					SetPVarInt(y, "FixTires", 0);
					UpdateVehicleDamageStatus(carid, panels, doors, lights, 0);
					if(polak(y)) SendClientMessageEx(y, -1, "%s Opony "COL_GREEN"naprawione"COL_WHITE".", form());
					else SendClientMessageEx(y, -1, "%s Tyres "COL_GREEN"repaired"COL_WHITE".", form());
				}
			}
		}
	}
	return 1;
}

forward CheckVBoom(playerid);
public CheckVBoom(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid)) sgracz[playerid][checkboom] = false;
	new carid = GetPlayerVehicleID(playerid);
	new Float:veHP = 0.0;
	GetVehicleHealth(carid, veHP);
	if(veHP <= 250.0 && sgracz[playerid][checkboom])
	{
		KickEx(playerid, -1, "Vehicle HP desync/Lag");
	}
	else
	{
		sgracz[playerid][checkboom] = false;
	}
	return 1;
}

forward ReCheckVHP(y);
public ReCheckVHP(y)
{
	new carid = GetPlayerVehicleID(y);
	new Float:veHP = 0.0;
	GetVehicleHealth(carid, veHP);
	if(veHP < tgracz[y][vHP])
	{
		tgracz[y][vHP] = veHP;
	}
	else if(veHP-100.0 > tgracz[y][vHP] && tgracz[y][cheat0_p] < gettime() && !tgracz[y][ukonczyl])
	{
		printf("|DEBUG|HP Desync: niezgodnosc: %f > %f", veHP-1.0, tgracz[y][vHP]);
		KickEx(y, -1, "Vehicle HP desync/Lag");
	}
	return 1;
}

stock CheckPing(playerid)
{
	new ping = GetPlayerPing(playerid);
	if(ping > MAX_PING)
	{
		SetPVarInt(playerid, "PingWarn", GetPVarInt(playerid, "PingWarn")+1);
		if(polak(playerid)) SendClientMessageEx(playerid, -1, ""COL_RED"|OSTRZEŻENIE|"COL_WHITE" Twój ping jest za wysoki: %d | Max: %d | Ostrzeżenia: %d/3", ping, MAX_PING, GetPVarInt(playerid, "PingWarn"));
		else SendClientMessageEx(playerid, -1, ""COL_RED"|WARNING|"COL_WHITE" Your ping is too high: %d | Max value: %d | Warnings: %d/3", ping, MAX_PING, GetPVarInt(playerid, "PingWarn"));
		if(GetPVarInt(playerid, "PingWarn") == 3)
		{
			new reas[64];
			format(reas, 64, "PING %d/%d", ping, MAX_PING);
			KickEx(playerid, -1, reas);
		}
	}
	return 1;
}

stock UpdateSpeedo(playerid)
{
	if(sgracz[playerid][upd_speedo])
	{
		new str[64];
		new vid = GetPlayerVehicleID(playerid);
		new speed = GetVehicleSpeed(vid, true);
		format(str, 64,"%d KM/H", speed);
		if(speed > sgracz[playerid][maxkmh])
		{
			sgracz[playerid][maxkmh] = speed;
			mq_format("UPDATE `players` SET `maxkmh`='%d' WHERE `id`='%d';", sgracz[playerid][maxkmh], sgracz[playerid][uID]);
			mq_send("QUERY");
		}
		SetDynamicObjectMaterialText(SpdObj[playerid][0],0,str,OBJECT_MATERIAL_SIZE_512x512,"Arial",64,true,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
		format(str, 64,"%s", GetMaterialVehHP(vid));
		SetDynamicObjectMaterialText(SpdObj[playerid][1],0,str,OBJECT_MATERIAL_SIZE_512x512,"Arial",64,true,0xFF4EFD71,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	}
	return 1;
}

public OnPlayerAirbreak(playerid)
{
	if(admin(playerid) == 4) return 1;
	if(GetVehicleSpeed(GetPlayerVehicleID(playerid), true)) return 1;
	BanTime(playerid, "AirBreak", 64);
	return 1;
}

forward Odlicz();
public Odlicz()
{
	if(!serwer[odliczanie]) return 0;
	if(serwer[count])
	{
		String_odliczTD(serwer[count]);
		for(new y; y <= GetPlayerPoolSize(); y++)
		{
			if(login(y))
			{
				new vid = GetPlayerVehicleID(y);
				new Float:pPos[3];
				GetVehiclePos(vid, pPos[0], pPos[1], pPos[2]);
				if(GetDistanceBetweenPoints(pPos[0], pPos[1], pPos[2], tgracz[y][startX], tgracz[y][startY], tgracz[y][startZ]) > 0.5)
				{
					SetVehiclePos(vid, tgracz[y][startX], tgracz[y][startY], tgracz[y][startZ]);
					SetVehicleZAngle(vid, tgracz[y][startR]);
				}
				FixVehicle(y);
				TextDrawHideForPlayer(y, odl_text);
				TextDrawHideForPlayer(y, odl_tlo);
				TextDrawShowForPlayer(y, odl_text);
				TextDrawShowForPlayer(y, odl_tlo);
				PlayerPlaySound(y, 1056, 0.0, 0.0, 0.0);
			}
		}
		serwer[count]--;
	}
	else
	{
		serwer[wyscig] = true;
		serwer[odliczanie] = false;
		serwer[ms] = 0;
		serwer[extrams] = 0;
		serwer[sec] = 0;
		serwer[m] = 0; 
		String_odliczTD(0);
		for(new x; x <= GetPlayerPoolSize(); x++)
		{
			if(login(x))
			{
				TopWindowHide(x);
				new Float:pPos[3];
				new vid = GetPlayerVehicleID(x);
				SetVehiclePos(vid, tgracz[x][startX], tgracz[x][startY], tgracz[x][startZ]);
				GetVehiclePos(vid, pPos[0], pPos[1], pPos[2]);
				SetVehicleZAngle(vid, tgracz[x][startR]);
				FixVehicle(x);
				if(GetDistanceBetweenPoints(pPos[0], pPos[1], pPos[2], tgracz[x][startX], tgracz[x][startY], tgracz[x][startZ]) > 2.0)
				{
					KickEx(x, -1, "AirBreak/Lag");
				}
				TextDrawHideForPlayer(x, odl_text);
				TextDrawHideForPlayer(x, odl_tlo);
				TextDrawShowForPlayer(x, odl_text);
				TextDrawShowForPlayer(x, odl_tlo);
				TogglePlayerControllable(x, serwer[wyscig]);
				PlayerPlaySound(x, 3200, 0.0, 0.0, 0.0);
				PlayMusic(x);
			}
		}
	}
	return 1;
}

forward OdliczEnd();
public OdliczEnd()
{
	if(serwer[count]) return 0;
	serwer[count] = MAX_ODLICZANIE;
	for(new x; x <= GetPlayerPoolSize(); x++)
	{
		if(login(x))
		{
			TextDrawHideForPlayer(x, odl_text);
			TextDrawHideForPlayer(x, odl_tlo);
			//udział
			sgracz[x][udzial]++;
			mq_format("UPDATE `players` SET `udzial`='%d' WHERE `id`='%d';", sgracz[x][udzial], sgracz[x][uID]);
			mq_send("QUERY");
			Dialog_Close(x);
		}
	}
	return 1;
}

forward UstawOKWorld();
public UstawOKWorld()
{
	if(serwer[wpid] > -1)
	{
		if(login(serwer[wpid]))
		{
			SetVehicleVirtualWorld(GetPlayerVehicleID(serwer[wpid]), 0);
			SetPlayerVirtualWorld(serwer[wpid], 0);
			DisableRemoteVehicleCollisions(serwer[wpid], true);
		}
		serwer[wpid]--;
		SetTimer("UstawOKWorld", 1000, false);
	}
	return 1;
}

forward OnPlayerFinishRace(playerid);
public OnPlayerFinishRace(playerid)
{
	if(!login(playerid)) return 0;
	if(serwer[eMin] > 2) serwer[eMin] = 1, serwer[eSec] = 59;
	SetPVarInt(playerid, "InCar", 0);
	HideSpeedo(playerid);
	serwer[zkolei]++;
	switch(serwer[zkolei])
	{
		case 0..1:
		{
			SetPlayerPos(playerid, -2818.6040,1810.0485,14.5100);
			PlayerPlaySound(playerid, 5450, 0.0, 0.0, 0.0);
			sgracz[playerid][wygrane]++;
			tgracz[playerid][podiumpos] = 1;
			mq_format("UPDATE `players` SET `wygrane`='%d' WHERE `id`='%d';", sgracz[playerid][wygrane], sgracz[playerid][uID]);
			mq_send("QUERY");
		}
		case 2:
		{
			tgracz[playerid][podiumpos] = 2;
			SetPlayerPos(playerid, -2816.6143,1807.9371,13.6500);
			PlayerPlaySound(playerid, 5450, 0.0, 0.0, 0.0);
		}
		case 3:
		{
			tgracz[playerid][podiumpos] = 3;
			SetPlayerPos(playerid, -2820.4697,1812.5128,13.0600);
			PlayerPlaySound(playerid, 5450, 0.0, 0.0, 0.0);
		}
		default:
		{
			tgracz[playerid][podiumpos] = 4;
			SetPlayerPos(playerid, -2808.6819,1818.6494, 0.0);
		}
	}
	SetPlayerFacingAngle(playerid, 309.5125);
	new sc = GetScorePos(serwer[zkolei]);
	if(vip(playerid)) sc += 2;
	SetScore(playerid, GetPlayerScore(playerid)+sc);
	SendClientMessageToAllEN(0x00FF00AA, "» {%06x}%s"COL_WHITE" finished the race | Position: "COL_RED"%d"COL_WHITE" | Time: "COL_BLUE"%02d:%02d:%02d "COL_WHITE"| Score: "COL_GREEN"+%d "COL_ORANGE"(%d)", GetPlayerColor(playerid) >>> 8, nick(playerid), serwer[zkolei], serwer[m], serwer[sec], serwer[ms], sc, GetPlayerScore(playerid));
	SendClientMessageToAllPL(0x00FF00AA, "» {%06x}%s"COL_WHITE" ukończył wyścig | Pozycja: "COL_RED"%d"COL_WHITE" | Czas: "COL_BLUE"%02d:%02d:%02d "COL_WHITE"| Score: "COL_GREEN"+%d "COL_ORANGE"(%d)", GetPlayerColor(playerid) >>> 8, nick(playerid), serwer[zkolei], serwer[m], serwer[sec], serwer[ms], sc, GetPlayerScore(playerid));
	if(polak(playerid)) SendClientMessage(playerid, -1, ""COL_GREEN"Ukończyłeś"COL_WHITE" wyścig. Czekaj na głosowanie. ("COL_YELLOW"+/- 2 min"COL_WHITE")");
	else SendClientMessage(playerid, -1, "You "COL_GREEN"finished"COL_WHITE" the race. Please wait for the vote. ("COL_YELLOW"+/- 2 min"COL_WHITE")");
	if(serwer[zkolei] <= 10)
	{
		new str[64];
		format(str, 64, "%d. %s ~>~ %02d:%02d.%02d", serwer[zkolei], nick(playerid), serwer[m], serwer[sec], serwer[ms]);
		String_ulista(str, true);
	}
	tgracz[playerid][ukonczyl] = true;
	sgracz[playerid][ukonczone]++;
	mq_format("UPDATE `players` SET `ukonczone`='%d' WHERE `id`='%d';", sgracz[playerid][ukonczone], sgracz[playerid][uID]);
	mq_send("QUERY");
	mq_format("INSERT INTO `map_result` (`uid`, `mid`, `msc`, `time`, `min`, `sec`, `ms`, `ems`) VALUES ('%d', '%d', '%d', CURRENT_TIMESTAMP, '%d', '%d', '%d', '%d');", sgracz[playerid][uID], dini_Int(CFG, "LastMap"), serwer[zkolei], serwer[m], serwer[sec], serwer[ms], serwer[extrams]);
	mq_send("QMapResult");
	SetPlayerCameraPos(playerid, -2808.9268, 1818.3375, 16.9147);
	SetPlayerCameraLookAt(playerid, -2809.6865, 1817.6796, 16.6347);
	FixVehicle(playerid);
	TogglePlayerControllable(playerid, false);
	Spec_OtherSpec(playerid);
	StartSpecMode(playerid);
	if(POnline() == PFinished())
	{
		if(serwer[eMin])
		{
			serwer[eMin] = 0;
			serwer[eSec] = 4;
		}
		else if(serwer[eSec] > 4)
		{
			serwer[eSec] = 4;
		}
	}
	return 1;
}

forward QMapResult();
public QMapResult()
{
	GenerateTop10(ActualMapID());
	ReShowTopFinish();
	return 1;
}

stock ReShowTopFinish()
{
	for(new t; t <= GetPlayerPoolSize(); t++)
	{
		if(tgracz[t][ukonczyl])
		{
			TopWindowHide(t);
			ShowTop10Map(t);
		}
	}

	return 1;
}

forward Function(playerid, type, value);
public Function(playerid, type, value)
{
	if(!IsPlayerInAnyVehicle(playerid)) return 0;
	new vid = GetPlayerVehicleID(playerid);
	switch(type)
	{
		case FIX_VEH:
		{
			FixVehicle(playerid);
			PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			if(polak(playerid)) GameTextForPlayer(playerid, "Pojazd ~g~naprawiony~w~!", 2000, 4);
			else GameTextForPlayer(playerid, "Vehicle ~g~repaired~w~!", 2000, 4);
		}
		case CHANGE_VEH:
		{
			if(!tgracz[playerid][CP_ID]) return 0;
			if(GetVehicleModel(vid) == value) return 0;
			if(!ValidVehicleModel(value)) return 0;
			HideSpeedo(playerid);
			tgracz[playerid][cheat0_p] = gettime()+5;
			new Float:tVelX, Float:tVelY, Float:tVelZ;
			new Float:tPosX, Float:tPosY, Float:tPosZ, Float:tPosR;
			new Float:veHP;
			new panels, doors, lights, tires;
			GetVehicleVelocity(vid, tVelX, tVelY, tVelZ);
			GetVehiclePos(vid, tPosX, tPosY, tPosZ);
			GetVehicleZAngle(vid, tPosR);
			GetVehicleHealth(vid, veHP);
			GetVehicleDamageStatus(vid, panels, doors, lights, tires);
			DestroyVehicle(vid);
			new ncar = CreateVehicle(value, tPosX, tPosY, tPosZ+0.65, tPosR, sgracz[playerid][vcolor1], sgracz[playerid][vcolor2], 9999);
			PutIn(playerid, ncar, 0);
			SetVehicleVelocity(ncar, tVelX, tVelY, tVelZ);
			tgracz[playerid][vHP] = veHP;
			SetVehicleHealth(ncar, tgracz[playerid][vHP]);
			UpdateVehicleDamageStatus(ncar, panels, doors, lights, tires);
			if(tgracz[playerid][nitro_status]) AddVehicleComponent(vid, tgracz[playerid][nitro_status]);
			PlayerPlaySound(playerid, 5205, 0.0, 0.0, 0.0);
			ShowSpeedo(playerid);
			LoadVehMod(playerid, ncar);
			Spec_ReSpecAction(playerid, ncar);
			if(polak(playerid)) GameTextForPlayer(playerid, "Pojazd ~g~zmieniony~w~!", 2000, 4);
			else GameTextForPlayer(playerid, "Vehicle ~g~changed~w~!", 2000, 4);
		}
		case NITRO:
		{
			if(tgracz[playerid][nitro_status]) return 0;
			tgracz[playerid][nitro_status] = 1010;
			AddVehicleComponent(vid, tgracz[playerid][nitro_status]);
			PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			if(polak(playerid)) GameTextForPlayer(playerid, "~b~Nitro ~g~dodane~w~!", 2000, 4);
			else GameTextForPlayer(playerid, "~b~Nitro ~g~added~w~!", 2000, 4);
		}
		case TAKE_NITRO:
		{
			if(GetVehicleComponentInSlot(GetPlayerVehicleID(playerid),GetVehicleComponentType(1010)) != 1010) return 0;
			RemoveVehicleComponent(vid,1010);
			PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0);
			if(polak(playerid))
			{
				SendClientMessageEx(playerid, -1, "%s Nitro "COL_RED"usunięte"COL_WHITE".", form());
				GameTextForPlayer(playerid, "~b~Nitro ~r~usuniete~w~!", 2000, 4);
			}
			else
			{
				SendClientMessageEx(playerid, -1, "%s Nitro "COL_RED"removed"COL_WHITE".", form());
				GameTextForPlayer(playerid, "~b~Nitro ~r~removed~w~!", 2000, 4);
			}
			tgracz[playerid][nitro_status] = 0;
		}
		case W_ROCKET:
		{
			if(tgracz[playerid][weapon]) return 0;
			PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
			tgracz[playerid][weapon] = W_ROCKET;
			if(polak(playerid)) String_weaponTD(playerid,"Rakieta");
			else String_weaponTD(playerid,"Rocket-Shoot");
			AttachLaser(playerid);
			if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Rakieta "COL_GREEN"dodana"COL_WHITE". Wciśnij "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" aby użyć.", form());
			else SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Rocket-Shoot "COL_GREEN"added"COL_WHITE". Press "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" to use.", form());
		}
		case W_RAMP:
		{
			if(tgracz[playerid][weapon]) return 0;
			PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
			tgracz[playerid][weapon] = W_RAMP;
			if(polak(playerid)) String_weaponTD(playerid, "Tylna-Rampa");
			else String_weaponTD(playerid,"Back-Ramp");
			if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Tylna-Rampa "COL_GREEN"dodana"COL_WHITE". Wciśnij "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" aby użyć.", form());
			else SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Back-Ramp "COL_GREEN"added"COL_WHITE". Press "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" to use.", form());
		}
		case W_HAY:
		{
			if(tgracz[playerid][weapon]) return 0;
			PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
			tgracz[playerid][weapon] = W_HAY;
			if(polak(playerid)) String_weaponTD(playerid,"Siano");
			else String_weaponTD(playerid,"Back-Hay");
			if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Siano "COL_GREEN"dodane"COL_WHITE". Wciśnij "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" aby użyć.", form());
			else SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Back-Hay "COL_GREEN"added"COL_WHITE". Press "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" to use.", form());
		}
		case W_SPIKE:
		{
			if(tgracz[playerid][weapon]) return 0;
			PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
			tgracz[playerid][weapon] = W_SPIKE;
			if(polak(playerid)) String_weaponTD(playerid,"Kolczatka");
			else String_weaponTD(playerid,"Spike Strip");
			if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Kolczatka "COL_GREEN"dodana"COL_WHITE". Wciśnij "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" aby użyć.", form());
			else SendClientMessageEx(playerid, -1, "%s "COL_BLUE"Spike Strip "COL_GREEN"added"COL_WHITE". Press "COL_ORANGE"~k~~PED_FIREWEAPON~"COL_WHITE" to use.", form());
		}
	}
	return 1;
}


public OnObjectMoved(objectid)
{
	for(new i; i <= GetPlayerPoolSize(); i++)
	{
		if(objectid != gRocketObj[i]) continue;
		new
		Float:x,
		Float:y,
		Float:z;
		GetObjectPos(gRocketObj[i], x, y, z);
		CreateExplosion(x, y, z, 11, 5.0);
		DestroyObject(gRocketObj[i]);
		gRocketObj[i] = INVALID_OBJECT_ID;
	}
	return 1;
}

stock CheckRockets()
{
	for(new p; p <= GetPlayerPoolSize(); p++)
	{
		if(!IsValidObject(gRocketObj[p])) continue;
		if(IsObjectMoving(gRocketObj[p]))
		{
			new Float:x, Float:y, Float:z;
			GetObjectPos(gRocketObj[p], x, y, z);
			for(new k; k <= GetPlayerPoolSize(); k++)
			{
				if(!login(k)) continue;
				if(IsPlayerInRangeOfPoint(k, 3.0, x, y, z))
				{
					CreateExplosion(x, y, z, 11, 6.0);
					DestroyObject(gRocketObj[p]);
					gRocketObj[p] = INVALID_OBJECT_ID;
					break;
				}
			}
		}
	}
	return 1;
}


public OnPlayerPickUpPickup(playerid, pickupid)
{
	if(tgracz[playerid][pickdelay] > gettime()) return 1;
	if(pick[pickupid][pmodel])
	{
		switch(pick[pickupid][pmodel])
		{
			case 3096://FIX_VEH
			{
				Function(playerid, FIX_VEH, NONE);
			}
			case 3594://CHANGE_VEH
			{
				if(pick[pickupid][pvalue])
				{ 
					Function(playerid, CHANGE_VEH, pick[pickupid][pvalue]);
				}
			}
			case 1010://NITRO
			{
				Function(playerid, NITRO, NONE);
			}
			case 1008://TAKE_NITRO
			{
				Function(playerid, TAKE_NITRO, NONE);
			}
			case 1636://W_ROCKET
			{
				if(tgracz[playerid][weapon]) return 1;
				serwer[sh_check] = false;
				Function(playerid, W_ROCKET, NONE);
			}
			case 1503://W_RAMP
			{
				if(tgracz[playerid][weapon]) return 1;
				Function(playerid, W_RAMP, NONE);
			}
			case 1453://W_HAY
			{
				if(tgracz[playerid][weapon]) return 1;
				Function(playerid, W_HAY, NONE);
			}
			case 2899://W_SPIKE
			{
				if(tgracz[playerid][weapon]) return 1;
				Function(playerid, W_SPIKE, NONE);
			}
		}
		tgracz[playerid][pickdelay] = gettime()+1;
	}
    return 1;
}

forward Pickup(Float:x, Float:y, Float:z, type, value);
public Pickup(Float:x, Float:y, Float:z, type, value)
{
	new pickupid;
	z += 0.40;
	switch(type)
	{
		case FIX_VEH:
		{
			pickupid = CreatePickup(3096, 1, x, y, z);
			pick[pickupid][pmodel] = 3096;
		}
		case CHANGE_VEH:
		{
			if(ValidVehicleModel(value))
			{
				pickupid = CreatePickup(3594, 1, x, y, z);
				pick[pickupid][pmodel] = 3594;
				pick[pickupid][pvalue] = value;
			}
			else return 0;
		}
		case NITRO:
		{
			pickupid = CreatePickup(1010, 1, x, y, z);
			pick[pickupid][pmodel] = 1010;
		}
		case TAKE_NITRO:
		{
			pickupid = CreatePickup(1008, 1, x, y, z);
			pick[pickupid][pmodel] = 1008;
		}
		case W_ROCKET:
		{
			pickupid = CreatePickup(1636, 1, x, y, z);
			pick[pickupid][pmodel] = 1636;
		}
		case W_RAMP:
		{
			pickupid = CreatePickup(1503, 1, x, y, z);
			pick[pickupid][pmodel] = 1503;
		}
		case W_HAY:
		{
			pickupid = CreatePickup(1453, 1, x, y, z);
			pick[pickupid][pmodel] = 1453;
		}
		case W_SPIKE:
		{
			pickupid = CreatePickup(2899, 1, x, y, z);
			pick[pickupid][pmodel] = 2899;
		}
	}
	pick[pickupid][pX] = x; 
	pick[pickupid][pY] = y;
	pick[pickupid][pZ] = z;
	return 1;
}

forward PickupCheck(playerid);
public PickupCheck(playerid)
{
	for(new p; p < MAX_PICKUPS; p++)
	{
		if(pick[p][pmodel])
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, pick[p][pX], pick[p][pY], pick[p][pZ]) && IsPlayerInAnyVehicle(playerid))
			{
				OnPlayerPickUpPickup(playerid, p);
			}
		}
	}
	return 1;
}

forward reCountPos();
public reCountPos()
{
	new temp[MAX_PLAYERS],
	fixtemp[MAX_PLAYERS],
	c_pid,
	dist[MAX_PLAYERS],
	cpdist,
	sorting = 0,
	anothersorting = POnline();
	if(anothersorting == 1)
	{
		for(new i = 0; i <= GetPlayerPoolSize(); i++)
		{
			if(login(i)) 
			{
				tgracz[i][pozycja] = 1;
				break;
			}
		}
	}
	else if(anothersorting > 1)
	{
		for(new i = 0; i <= GetPlayerPoolSize(); i++)
		{
			if(login(i))
			{
				c_pid = tgracz[i][CP_ID];
				dist[i] = c_pid*100000;
				cpdist = 100000-floatround(floatabs(GetPlayerDistanceFromPoint(i, CP[c_pid][cX], CP[c_pid][cY], CP[c_pid][cZ])*10), floatround_round);
				dist[i] += cpdist;
				temp[sorting] = dist[i];
				sorting++;
			}
		}
		quickSort(temp, 0, sizeof(temp) - 1);
		sorting = 0;
		for(new jj = 0; jj != sizeof(temp); jj++)
		{
			if(temp[jj] > 0)
			{
				fixtemp[sorting] = temp[jj];
				sorting++;
			}
		}
		for(new j = 0; j != sizeof(fixtemp); j++)
		{
			for(new i = 0; i <= GetPlayerPoolSize(); i++)
			{
				if(!login(i)) continue;
				if(dist[i] == fixtemp[j])
				{
					tgracz[i][pozycja] = anothersorting;
					anothersorting--;
				}
			}
		}
	}
	return 1;
}

stock ShowShop(playerid)
{
	if(polak(playerid))
	{
		if(serwer[wyscig]) return Error(playerid, "Wyścig już wystartował, sklep jest niedostępny.");
		new shoplist[2000];
		strcat(shoplist,"Przedmiot\tKoszt\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Nitro\t"COL_YELLOW"[30 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Rakieta\t"COL_YELLOW"[35 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Tylnia-Rampa\t"COL_YELLOW"[20 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Siano\t"COL_YELLOW"[25 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Kolczatka\t"COL_YELLOW"[21 score]\n");
		Dialog_Show(playerid, SHOP, DIALOG_STYLE_TABLIST_HEADERS, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Sklep - Przedmiot startowy", shoplist, "Kup", "Anuluj");
	}
	else
	{
		if(serwer[wyscig]) return Error(playerid, "The race started, shop offline.");
		new shoplist[2000];
		strcat(shoplist,"Item\tCost\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Nitro\t"COL_YELLOW"[30 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Rocket-Shoot\t"COL_YELLOW"[35 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Back-Ramp\t"COL_YELLOW"[20 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Back-Hay\t"COL_YELLOW"[25 score]\n");
		strcat(shoplist,""COL_RED"»"COL_WHITE" Spike Strip\t"COL_YELLOW"[21 score]\n");
		Dialog_Show(playerid, SHOP, DIALOG_STYLE_TABLIST_HEADERS, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Shop - Start item", shoplist, "Buy", "Cancel");
	}

	return 1;
}

//Function(playerid, type, value);
Dialog:SHOP(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;
	if(polak(playerid))
	{
		if(serwer[wyscig]) return Error(playerid, "Wyścig już wystartował, sklep jest niedostępny.");
		switch(listitem)
		{
			case 0:
			{
				if(!IsCarVehicle(GetPlayerVehicleID(playerid))) return Error(playerid, "Tylko samochody mogą mieć nitro."), ShowShop(playerid);
				if(GetPlayerScore(playerid) < 30) return SendClientMessageEx(playerid, -1, "%s Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby kupić ten "COL_GREEN"przedmiot"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 30);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"zakupiono"COL_WHITE".", inputtext);
				tgracz[playerid][buynitro] = true;
				Function(playerid, NITRO, NONE);
			}
			case 1:
			{
				if(GetPlayerScore(playerid) < 35) return SendClientMessageEx(playerid, -1, "%s Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby kupić ten "COL_GREEN"przedmiot"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 35);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"zakupiono"COL_WHITE".", inputtext);
				Function(playerid, W_ROCKET, NONE);
			}
			case 2:
			{
				if(GetPlayerScore(playerid) < 20) return SendClientMessageEx(playerid, -1, "%s Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby kupić ten "COL_GREEN"przedmiot"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 20);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"zakupiono"COL_WHITE".", inputtext);
				Function(playerid, W_RAMP, NONE);
			}
			case 3:
			{
				if(GetPlayerScore(playerid) < 25) return SendClientMessageEx(playerid, -1, "%s Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby kupić ten "COL_GREEN"przedmiot"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 25);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"zakupiono"COL_WHITE".", inputtext);
				Function(playerid, W_HAY, NONE);
			}
			case 4:
			{
				if(GetPlayerScore(playerid) < 21) return SendClientMessageEx(playerid, -1, "%s Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby kupić ten "COL_GREEN"przedmiot"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 21);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"zakupiono"COL_WHITE".", inputtext);
				Function(playerid, W_SPIKE, NONE);
			}
		}
	}
	else 
	{
		if(serwer[wyscig]) return Error(playerid, "The race started, shop offline.");
		switch(listitem)
		{
			case 0:
			{
				if(!IsCarVehicle(GetPlayerVehicleID(playerid))) return Error(playerid, "Only cars support nitro."), ShowShop(playerid);
				if(GetPlayerScore(playerid) < 30) return SendClientMessageEx(playerid, -1, "%s You don't have enough "COL_RED"score"COL_WHITE" to purchase this "COL_GREEN"item"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 30);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"purchased"COL_WHITE".", inputtext);
				tgracz[playerid][buynitro] = true;
				Function(playerid, NITRO, NONE);
			}
			case 1:
			{
				if(GetPlayerScore(playerid) < 35) return SendClientMessageEx(playerid, -1, "%s You don't have enough "COL_RED"score"COL_WHITE" to purchase this "COL_GREEN"item"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 35);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"purchased"COL_WHITE".", inputtext);
				Function(playerid, W_ROCKET, NONE);
			}
			case 2:
			{
				if(GetPlayerScore(playerid) < 20) return SendClientMessageEx(playerid, -1, "%s You don't have enough "COL_RED"score"COL_WHITE" to purchase this "COL_GREEN"item"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 20);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"purchased"COL_WHITE".", inputtext);
				Function(playerid, W_RAMP, NONE);
			}
			case 3:
			{
				if(GetPlayerScore(playerid) < 25) return SendClientMessageEx(playerid, -1, "%s You don't have enough "COL_RED"score"COL_WHITE" to purchase this "COL_GREEN"item"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 25);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"purchased"COL_WHITE".", inputtext);
				Function(playerid, W_HAY, NONE);
			}
			case 4:
			{
				if(GetPlayerScore(playerid) < 21) return SendClientMessageEx(playerid, -1, "%s You don't have enough "COL_RED"score"COL_WHITE" to purchase this "COL_GREEN"item"COL_WHITE".", form()), ShowShop(playerid);
				SetScore(playerid, GetPlayerScore(playerid) - 21);
				SendClientMessageEx(playerid, -1, "%s "COL_GREEN"purchased"COL_WHITE".", inputtext);
				Function(playerid, W_SPIKE, NONE);
			}
		}
	}
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(response) PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
	else PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
	return 1;
}

stock Bot()
{
	if(gettime() - serwer[t_chatbot] < 60*3) return 1;
	switch(serwer[kolej_chatbot])
	{
		case 0:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Pressing "COL_RED"ENTER"COL_WHITE" on keyboard moves you to the latest checkpoint "COL_GREEN"properly reached"COL_WHITE".");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Wciśnij "COL_RED"ENTER"COL_WHITE" aby wczytać ostatnią "COL_GREEN"poprawną pozycje"COL_WHITE".");
			serwer[kolej_chatbot]++;
		}
		case 1:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Server is secured by the "COL_RED"AntiCheat"COL_WHITE". Cheating attempt is not a good idea.");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Na serwerze czuwa "COL_RED"AntiCheat"COL_WHITE". Nie radzimy go drażnić.");
			serwer[kolej_chatbot]++;
		}
		case 4:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Invite your friends!");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Zaproś przyjaciół!");
			serwer[kolej_chatbot]++;
		}
		case 5:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Saw a "COL_RED"cheater"COL_WHITE"? Do not hesitate! Use: "COL_RED"/report [id] [reason]");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Widzisz "COL_RED"cheatera"COL_WHITE"? Nie zastanawiaj się! Użyj: "COL_RED"/report [id] [powód]");
			serwer[kolej_chatbot]++;
		}
		case 6:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Ignorance of the "COL_RED"/rules"COL_WHITE" does not exempt from compliance with it.");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Nieznajomość regulaminu"COL_RED"(/rules)"COL_WHITE" nie zwalnia z nieprzestrzegania go!");
			serwer[kolej_chatbot]++;
		}
		case 7:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" It is impossible to verify admins online. Always use "COL_RED"/report"COL_WHITE" if necessary.");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Niemożliwe jest zweryfikowanie administratorów online. Mimo wszystko zawsze używaj "COL_RED"/report"COL_WHITE" jeśli to konieczne.");
			serwer[kolej_chatbot]++;
		}
		case 8:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Earnings from the "COL_YELLOW"VIP"COL_WHITE" accounts, help us keeping the server online, and increasing players comfort!");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Środki z kont "COL_YELLOW"VIP"COL_WHITE" trafiają do wirtualnego portfela serwera.");
			serwer[kolej_chatbot]++;
		}
		case 9:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" If you see bugs/typos necessarily report them on: "COL_YELLOW"/bug");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Jeśli znalazłeś bug/literówkę, zgłoś to Adminowi lub na: "COL_YELLOW"/bug");
			serwer[kolej_chatbot]++;
		}
		case 10:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" All available commands: "COL_RED"/help");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Wszystkie dostępne komendy znajdziesz pod: "COL_RED"/pomoc");
			serwer[kolej_chatbot]++;
		}
		case 11:
		{
			SendClientMessageToAll(-1, ""COL_LIME"|TIP|"COL_WHITE" Please donate us, so that, we will be able to buy, a better server to ensure lower pings. "COL_GREEN"Thanks!");
			serwer[kolej_chatbot]++;
		}
		case 12:
		{
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Customize your account: "COL_RED"/set");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Dostosuj swoje konto na serwerze za pomocą komendy: "COL_RED"/set");
			serwer[kolej_chatbot]++;
		}
		default:
		{
			serwer[kolej_chatbot] = 0;
			SendClientMessageToAllEN(-1, ""COL_LIME"|TIP|"COL_WHITE" Double-clicks on a player on the "COL_RED"scoreboard(TAB)"COL_WHITE" will show "COL_GREEN"player stats"COL_WHITE".");
			SendClientMessageToAllPL(-1, ""COL_LIME"|TIP|"COL_WHITE" Podwójne kliknięcie na gracza "COL_RED"(TAB)"COL_WHITE" pokaże Ci jego "COL_GREEN"statystyki"COL_WHITE".");
		}
	}
	serwer[t_chatbot] = gettime();
	return 1;//SendClientMessageToAllEx(-1, ""COL_LIME"|TIP|"COL_WHITE" ");
}
//GetPlayerDistanceFromPoint(playerid, 237.9, 115.6, 1010.2)
stock Process_OppData(playerid)
{
	if(serwer[wyscig])
	{
		if(!tgracz[playerid][ukonczyl])
		{
			new oppstr[128];
			new pPozycja = tgracz[playerid][pozycja];
			new opp1name[20], opp2name[20], opp1m, opp2m, Float:opp1pos[3], Float:opp2pos[3];
			new bool:opp1ac, bool:opp2ac;
			if(pPozycja == serwer[zkolei]+1)//gdy jest pierwszy
			{
				for(new g; g <= GetPlayerPoolSize(); g++)
				{
					if(!login(g) || tgracz[g][ukonczyl]) continue;
					if(tgracz[g][pozycja] == pPozycja+1)
					{
						format(opp1name, 20, "%s", nick(g));
						GetPlayerPos(g, opp1pos[0], opp1pos[1], opp1pos[2]);
						opp1m = floatround(GetPlayerDistanceFromPoint(playerid, opp1pos[0], opp1pos[1], opp1pos[2]));
						opp1ac = true;
						if(opp1m < 0) opp1m = 0;
					}
					else if(tgracz[g][pozycja] == pPozycja+2)
					{
						format(opp2name, 20, "%s", nick(g));
						GetPlayerPos(g, opp2pos[0], opp2pos[1], opp2pos[2]);
						opp2m = floatround(GetPlayerDistanceFromPoint(playerid, opp2pos[0], opp2pos[1], opp2pos[2]));
						opp2ac = true;
						if(opp2m < 0) opp2m = 0;
					}
				}
				serwer[pierwszyid] = playerid;
				if(opp1ac && opp2ac) format(oppstr, 128, "~n~~y~%d. %s~w~~n~%d. %s ~>~ %dm~n~%d. %s ~>~ %dm", pPozycja, nick(playerid), pPozycja+1, opp1name, opp1m, pPozycja+2, opp2name, opp2m);
				else if(opp1ac && !opp2ac) format(oppstr, 128, "~n~~y~%d. %s~w~~n~%d. %s ~>~ %dm", pPozycja, nick(playerid), pPozycja+1, opp1name, opp1m);
				else format(oppstr, 128, "~n~~y~1. %s", nick(playerid));
			}
			else if(pPozycja == POnline())//gdy jest ostatni
			{
				for(new g; g <= GetPlayerPoolSize(); g++)
				{
					if(!login(g) || tgracz[g][ukonczyl]) continue;
					if(tgracz[g][pozycja] == pPozycja-1)
					{
						format(opp1name, 20, "%s", nick(g));
						GetPlayerPos(g, opp1pos[0], opp1pos[1], opp1pos[2]);
						opp1m = floatround(GetPlayerDistanceFromPoint(playerid, opp1pos[0], opp1pos[1], opp1pos[2]));
						opp1ac = true;
						if(opp1m < 0) opp1m = 0;
					}
					else if(tgracz[g][pozycja] == pPozycja-2)
					{
						format(opp2name, 20, "%s", nick(g));
						GetPlayerPos(g, opp2pos[0], opp2pos[1], opp2pos[2]);
						opp2m = floatround(GetPlayerDistanceFromPoint(playerid, opp2pos[0], opp2pos[1], opp2pos[2]));
						opp2ac = true;
						if(opp2m < 0) opp2m = 0;
					}
				}
				if(opp1ac && opp2ac) format(oppstr, 128, "~n~%d. %s ~>~ %dm~n~%d. %s ~>~ %dm~n~~y~%d. %s", pPozycja-2, opp2name, opp2m, pPozycja-1, opp1name, opp1m, pPozycja, nick(playerid));
				else if(opp1ac && !opp2ac) format(oppstr, 128, "~n~%d. %s ~>~ %dm~n~~y~%d. %s", pPozycja-1, opp1name, opp1m, pPozycja, nick(playerid));
				else format(oppstr, 128, "~n~~y~%d. %s", pPozycja, nick(playerid));	
			}
			else//gdy jest pomiędzy
			{
				for(new g; g <= GetPlayerPoolSize(); g++)
				{
					if(!login(g) || tgracz[g][ukonczyl]) continue;
					if(tgracz[g][pozycja] == pPozycja-1)
					{
						format(opp1name, 20, "%s", nick(g));
						GetPlayerPos(g, opp1pos[0], opp1pos[1], opp1pos[2]);
						opp1m = floatround(GetPlayerDistanceFromPoint(playerid, opp1pos[0], opp1pos[1], opp1pos[2]));
						opp1ac = true;
						if(opp1m < 0) opp1m = 0;
					}
					else if(tgracz[g][pozycja] == pPozycja+1)
					{
						format(opp2name, 20, "%s", nick(g));
						GetPlayerPos(g, opp2pos[0], opp2pos[1], opp2pos[2]);
						opp2m = floatround(GetPlayerDistanceFromPoint(playerid, opp2pos[0], opp2pos[1], opp2pos[2]));
						opp2ac = true;
						if(opp2m < 0) opp2m = 0;
					}
					if(opp1ac && opp2ac) format(oppstr, 128, "~n~%d. %s ~>~ %dm~n~~y~%d. %s~w~~n~%d. %s ~>~ %dm", pPozycja-1, opp1name, opp1m, pPozycja, nick(playerid), pPozycja+1, opp2name, opp2m);
					else format(oppstr, 128, "~n~~y~%d. %s", pPozycja, nick(playerid));	
				}
			}
			OppSetData(playerid, oppstr);
			OppShow(playerid);
		}
		else
		{
			OppHide(playerid);
		}
	}
	return 1;
}
