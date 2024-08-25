stock MapLoader()
{
    new temp;
    if(!dini_Exists(CFG))
    {
        dini_Create(CFG);
        printf("[LOAD]Stworzono plik "CFG"...");
        dini_IntSet(CFG, "LastMap", 1);
        printf("[LOAD]Ladowanie mapy 'map_1.amx'...");
    }
    else
    {
        printf("[LOAD]Ladowanie mapy 'map_%d.amx'...", dini_Int(CFG, "LastMap"));
    }
    temp = dini_Int(CFG, "LastMap");
    printf("[LOAD]MapLoader zglasza zaladowanie mapy %d...", temp);
    LoadMapFS(temp);
    if(MapLoaded)
    {
        temp = dini_Int(CFG, "LastMap");
        printf("[LOAD]Mapa 'map_%d.amx' zostala zaladowana...", temp);
        dini_IntSet(CFG, "LastMap", temp);
    }
    else
    {
        temp = dini_Int(CFG, "LastMap");
        printf("[LOAD]Mapa 'map_%d.amx' NIE zostala zaladowana... Zeruje licznik map...", temp);
        dini_IntSet(CFG, "LastMap", 1);
        LoadMapFS(1);
    }
    return 1;
}

forward  MLOAD();
public MLOAD()
{
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
    mq_format("SELECT `map`.*,`p`.`name` FROM `map_lista` AS `map` INNER JOIN `players` AS `p` ON `map`.`author_uid`=`p`.`id` WHERE `map`.`id`='%d' LIMIT 1;", ActualMapID());
    mq_send("OnMapInfoLoaded");
    return 1;
}

forward OnMapInfoLoaded();
public OnMapInfoLoaded()
{
    cache_get_field_content(0, "title", MapInfo[Nazwa], MySQL, 128);
    cache_get_field_content(0, "songurl", serwer[songurl], MySQL, 128);
    cache_get_field_content(0, "name", MapInfo[Autor], MySQL, 19);
    if(strlen(serwer[songurl]) < 4)
    {
      format(serwer[songurl], 128, "http://msrace.com/play.pls");
    }
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
    PorzadkujGraczy();
    WygenerujPodium();
    LoadStaticObjects();
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


stock LoadMapFS(mapid)
{
    new str[100];
    MapLoaded = 0;
    if(serwer[temp_mapid])
    {
      format(str, 100, "unloadfs map_%d", serwer[temp_mapid]);
      SendRconCommand(str);
      printf("[LOAD]Wyladowano mape: %s", str);
    }
    if(serwer[temp_sysmapid])
    {
      format(str, 100, "unloadfs map_%d", serwer[temp_sysmapid]);
      SendRconCommand(str);
      printf("[LOAD]Wyladowano mape: %s", str);
    }
    serwer[temp_mapid] = 0;
    format(str, 100, "loadfs map_%d", mapid);
    SendRconCommand(str);
    serwer[temp_sysmapid] = mapid;
    printf("[LOAD]Zaladowano mape: %s", str);
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
      if(polak(playerid)) Error(playerid, "GĂ„Ä…Ă˘â‚¬Ĺˇosowanie nie jest aktywne.");
      else Error(playerid, "Voting is not active.");
      return 1;
    } 
    if(response) 
    {
        serwer[glosy_n]++;
        SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|The player "COL_BLUE"%s"COL_WHITE" voted for: "COL_GREEN"NEXT MAP"COL_WHITE".", serwer[glosy_n], serwer[glosy_r], nick(playerid));
        SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_GREEN"%d"COL_WHITE"/"COL_RED"%d"COL_WHITE"|Gracz "COL_BLUE"%s"COL_WHITE" zagĂ„Ä…Ă˘â‚¬ĹˇosowaĂ„Ä…Ă˘â‚¬Ĺˇ na: "COL_GREEN"NASTÄ‚â€ž