forward  LoadCP(Float:X, Float:Y, Float:Z, Float:R, typec);
public LoadCP(Float:X, Float:Y, Float:Z, Float:R, typec)
{
    CP[cpid][cX] = X;
    CP[cpid][cY] = Y;
    CP[cpid][cZ] = Z;
    CP[cpid][cR] = R;
    if(!cpid)
    {
        CP[cpid][ctype] = 0;
    }
    else
    {
        CP[cpid][ctype] = typec;
    }
    new tempcpid = cpid;
    cpid++;
    return tempcpid;
}

stock ClearCP()
{
    for(new c; c < MAX_CPS; c++)
    {
        CP[c][cX]  = 0;
        CP[c][cY] = 0;
        CP[c][cZ] = 0;
        CP[c][cR] = 0;
        CP[c][ctype] = 0;
    }
    cpid = 0;
    return 1;
}

stock GetCountCheckpoints() return cpid;

stock CreateCP(playerid)
{
    new pos = tgracz[playerid][CP_ID];
    DestroyCP(playerid);
    new f_temp;
    if(pos != GetCountCheckpoints())
    {
        if(!CP[pos][ctype])
        {
            tgracz[playerid][Pick] = CreateDynamicObject(19945, CP[pos][cX], CP[pos][cY], CP[pos][cZ]-1.5, 0.0, 0.0, 0.0, -1, -1, playerid, 500.0,  500.0);
            f_temp = tgracz[playerid][Pick];
            o_flag[f_temp] = F_CP;
        }
        else
        {
            SetPlayerRaceCheckpoint(playerid, 3,  CP[pos][cX], CP[pos][cY], CP[pos][cZ],  CP[pos+1][cX], CP[pos+1][cY], CP[pos+1][cZ], 15.0);
        }
        tgracz[playerid][PickT] = CreateDynamicObject(19947, CP[pos+1][cX], CP[pos+1][cY], CP[pos+1][cZ]-1.5, 0.0, 0.0, 0.0, -1, -1, playerid, 500.0,  500.0);
        f_temp = tgracz[playerid][PickT];
        o_flag[f_temp] = F_CP;
        if(!CP[pos][ctype])
        {
            tgracz[playerid][Mic] = CreateDynamicMapIcon(CP[pos][cX], CP[pos][cY], CP[pos][cZ], 0, 0xFF0000AA, -1, -1, playerid,  1000.0, MAPICON_GLOBAL);
        }
        tgracz[playerid][MicT] = CreateDynamicMapIcon(CP[pos+1][cX], CP[pos+1][cY], CP[pos+1][cZ], 0, 0x0000FFAA, -1, -1, playerid, 500.0, MAPICON_LOCAL);
    }
    for(new l; l < 13; l++)
    {
        //f_temp = parrow[playerid][l];
        //if(o_flag[f_temp] == F_ARROW) DestroyPlayerArrow(playerid, parrow[playerid][l]), o_flag[f_temp] = F_NONE;
        if(pos == GetCountCheckpoints()-1) return 1;
        if(CP[pos][ctype]) return 1;
        parrow[playerid][l] = CreatePlayerArrow(playerid, CP[pos][cX], CP[pos][cY], CP[pos][cZ]+l, CP[pos+1][cX], CP[pos+1][cY], CP[pos+1][cZ]);
        f_temp = parrow[playerid][l];
        o_flag[f_temp] = F_ARROW;
        PointPlayerArrowAtObject(playerid, parrow[playerid][l], tgracz[playerid][PickT]);
    }
    return 1;
}

stock DestroyCP(playerid)
{
    DisablePlayerRaceCheckpoint(playerid);
    new f_temp = tgracz[playerid][Pick];
    if(o_flag[f_temp] == F_CP) DestroyDynamicObject(tgracz[playerid][Pick]), o_flag[f_temp] = F_NONE;
    f_temp = tgracz[playerid][PickT];
    if(o_flag[f_temp] == F_CP) DestroyDynamicObject(tgracz[playerid][PickT]), o_flag[f_temp] = F_NONE;
    DestroyDynamicMapIcon(tgracz[playerid][Mic]);
    DestroyDynamicMapIcon(tgracz[playerid][MicT]);
    for(new l; l < 13; l++)
    {
        f_temp = parrow[playerid][l];
        if(o_flag[f_temp] == F_ARROW) 
        {
            DestroyPlayerArrow(playerid, parrow[playerid][l]);
            o_flag[f_temp] = F_NONE;
        }
        parrow[playerid][l] = 0;
    }
    return 1;
}

stock Process_CheckPoint()
{
    new pos;
    for(new i; i <= GetPlayerPoolSize(); i++)
    {
        pos = tgracz[i][CP_ID];
        if(IsPlayerInRangeOfPoint(i, 13.0, CP[pos][cX], CP[pos][cY], CP[pos][cZ]) && IsPlayerInAnyVehicle(i) && serwer[wyscig] && !tgracz[i][ukonczyl] && login(i) && !CP[pos][ctype])
        {
            SavePlayerPos(i);
            if(pos)
            { 
                PlayerPlaySound(i, 5201, 0.0, 0.0, 0.0); 
            }
            CallRemoteFunction("OnPlayerCollectCP", "dd", i, pos);
            tgracz[i][CP_ID]++;
            CreateCP(i);
            String_checkTD(i, tgracz[i][CP_ID], GetCountCheckpoints());
            sgracz[i][zebranecp]++;
            mq_format("UPDATE `players` SET `zebranecp`='%d' WHERE `id`='%d';", sgracz[i][zebranecp], sgracz[i][uID]);
            mq_send("QUERY");
            if(tgracz[i][CP_ID] == GetCountCheckpoints()) OnPlayerFinishRace(i);
        }
    }
    return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
    new pos = tgracz[playerid][CP_ID];
    if(IsPlayerInAnyVehicle(playerid) && serwer[wyscig] && !tgracz[playerid][ukonczyl] && login(playerid))
    {
        if(pos)
        { 
            PlayerPlaySound(playerid, 5201, 0.0, 0.0, 0.0);
        }
        CallRemoteFunction("OnPlayerCollectCP", "dd", playerid, pos);
        SavePlayerPos(playerid);
        tgracz[playerid][CP_ID]++;
        CreateCP(playerid);
        String_checkTD(playerid, tgracz[playerid][CP_ID], GetCountCheckpoints());
        sgracz[playerid][zebranecp]++;
        mq_format("UPDATE `players` SET `zebranecp`='%d' WHERE `id`='%d';", sgracz[playerid][zebranecp], sgracz[playerid][uID]);
        mq_send("QUERY");
        if(tgracz[playerid][CP_ID] == GetCountCheckpoints()) OnPlayerFinishRace(playerid);
    }
    return 1;
}

//Wczytywanie pozycji i prędkosci

forward SavePlayerPos(playerid);
public SavePlayerPos(playerid)
{
    new pos = tgracz[playerid][CP_ID];
    if(pPositionLoader[playerid][pos][used]) return 1;
    new vehicleid = GetPlayerVehicleID(playerid);
    GetVehiclePos(vehicleid, pPositionLoader[playerid][pos][PosX], pPositionLoader[playerid][pos][PosY], pPositionLoader[playerid][pos][PosZ]);
    GetVehicleZAngle(vehicleid, pPositionLoader[playerid][pos][PosR]);
    GetVehicleVelocity(vehicleid, pPositionLoader[playerid][pos][VolX], pPositionLoader[playerid][pos][VolY], pPositionLoader[playerid][pos][VolZ]);
    pPositionLoader[playerid][pos][vmodel] = GetVehicleModel(vehicleid);
    pPositionLoader[playerid][pos][used] = true;
    return 1;
}

stock LoadPlayerPos(playerid)
{
    new pos = tgracz[playerid][CP_ID];
    new vehicleid = CreateVehicle(pPositionLoader[playerid][pos][vmodel], CP[pos][cX], CP[pos][cY], CP[pos][cZ]+0.8, pPositionLoader[playerid][pos][PosR], sgracz[playerid][vcolor1], sgracz[playerid][vcolor2], 9999, 0);
    SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));
    PutIn(playerid, vehicleid, 0);
    SetPVarInt(playerid, "FreezeActive", gettime());
    if(pPositionLoader[playerid][pos][PosX] != 0.0)
    {
        SetVehiclePos(vehicleid, pPositionLoader[playerid][pos][PosX], pPositionLoader[playerid][pos][PosY], pPositionLoader[playerid][pos][PosZ]);
    }
    else
    {
        SetVehiclePos(vehicleid, CP[pos][cX], CP[pos][cY], CP[pos][cZ]);
    }
    SetVehicleZAngle(vehicleid, pPositionLoader[playerid][pos][PosR]);
    SetPVarInt(playerid, "CanLoadSpeed", 1);
    return vehicleid;
}

stock LoadSpeed(playerid)
{
    if(GetPVarInt(playerid, "CanLoadSpeed"))
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        new pos = tgracz[playerid][CP_ID]-1;
        if(pos < 0) pos = 0;
        SetVehicleVelocity(vehicleid, pPositionLoader[playerid][pos][VolX], pPositionLoader[playerid][pos][VolY], pPositionLoader[playerid][pos][VolZ]);
        SetPVarInt(playerid, "CanLoadSpeed", 0);
        for(new r = pos+1; r < GetCountCheckpoints(); r++)//resetowanie savów przed nim.
        {
            pPositionLoader[playerid][r][used] = false;
        }
    }
    return 1;
}

stock RandomModelArrow()
{
    switch(random(3))
    {
        case 0:
        {
            return 19607;
        }
        case 1:
        {
            return 19606;
        }
        case 2:
        {
            return 19605;
        }
    }
    return 19607;
}