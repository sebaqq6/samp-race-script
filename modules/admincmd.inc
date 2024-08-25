CMD:acmd(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    new a_cmd[2000];
    strcat(a_cmd,""COL_RED"Penalties:\n");
    strcat(a_cmd,""COL_BLUE"/kick "COL_EASY"- Kick player."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/mute "COL_EASY"- Mute player."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/block "COL_EASY"- Simple perm ban(only user)."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/ban "COL_EASY"- Ban perm player(user + ip)."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/tban "COL_EASY"- Time ban(user + ip)."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/eban "COL_EASY"- Extra perm ban."COL_BLUE"[Lvl: 4]\n");
    strcat(a_cmd,""COL_RED"Other:\n");
    strcat(a_cmd,""COL_BLUE"` "COL_EASY"- Admin chat."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/check "COL_EASY"- Checking the most important information about the player."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/vehgodtest "COL_EASY"- Vehicle godmode test."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/fvote "COL_EASY"- Forcing a vote."COL_BLUE"[Lvl: 2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/setscore "COL_EASY"- Set player score."COL_BLUE"[Lvl: 3,4]\n");
    strcat(a_cmd,""COL_BLUE"/setveh "COL_EASY"- Set player vehicle."COL_BLUE"[Lvl: 3,4]\n");
    strcat(a_cmd,""COL_BLUE"/setadmin "COL_EASY"- Set player admin LVL."COL_BLUE"[Lvl: 4]\n");
    strcat(a_cmd,""COL_BLUE"/setweather "COL_EASY"- Set weather."COL_BLUE"[Lvl: 2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/settime "COL_EASY"- Set time."COL_BLUE"[Lvl: 2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/cc "COL_EASY"- Clear all players chat."COL_BLUE"[Lvl: 1,2,3,4]\n");
    strcat(a_cmd,""COL_BLUE"/setvip "COL_EASY"- Set player VIP."COL_BLUE"[Lvl: 4]\n");
    strcat(a_cmd,""COL_BLUE"/getuid "COL_EASY"- Get user ID."COL_BLUE"[Lvl: 4]\n");
    strcat(a_cmd,""COL_BLUE"/removerecords "COL_EASY"- Remove player all records."COL_BLUE"[Lvl: 4]\n");
    strcat(a_cmd,""COL_BLUE"/mysql "COL_EASY"- Show MySQL stats."COL_BLUE"[Lvl: 4]\n");
    ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Admin Commands", a_cmd, "Close", "");
    return 1;
}

CMD:kick(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    new targetid, reason[128];
    if(sscanf(params,"ds[128]", targetid, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /kick [targetid] [reason]");
    if(!IsPlayerConnected(targetid)) return Error(playerid, "Target ID is not connect.");
    if(admin(playerid) < admin(targetid)) return Error(playerid, "Access denied.");
    KickEx(targetid, playerid, reason);
    return 1;
}

CMD:mute(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    new targetid, minutes, reason[128];
    if(sscanf(params,"dds[128]", targetid, minutes, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /mute [targetid] [minutes] [reason]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    if(admin(playerid) < admin(targetid)) return Error(playerid, "Access denied.");
    sgracz[targetid][mute_stamp] = 60*minutes+gettime();
    mq_format("UPDATE `players` SET `mute_stamp`='%d' WHERE `id`='%d';", sgracz[targetid][mute_stamp], sgracz[targetid][uID]);
    mq_send("QUERY");
    SendClientMessageToAllEN(0xFF0000AA, "|MUTE| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Reason: %s | Time: %d min", nick(targetid), nick(playerid), reason, minutes);
    SendClientMessageToAllPL(0xFF0000AA, "|MUTE| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Powód: %s | Czas: %d min", nick(targetid), nick(playerid), reason, minutes);
    return 1;
}

CMD:block(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    new targetid, reason[128];
    if(sscanf(params,"ds[128]", targetid, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /block [targetid] [reason]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    if(admin(playerid) < admin(targetid)) return Error(playerid, "Access denied.");
    mysql_escape_string(reason, reason);
    new perm  = MAX_VALUE;
    mq_format("INSERT INTO `BanList` (`uid`, `aid`, `time`, `time_end`, `ip_on`, `ip`, `gpci_on`, `gpci`, `reason`) VALUES ('%d', '%d', '%d', '%d', '0', '%s', '0', '%s', '%s');", sgracz[targetid][uID], sgracz[playerid][uID], gettime(), perm, playerip(targetid, true), serial(targetid, true), reason);
    mq_send("BANQUERY");
    SendClientMessageToAllEN(0xFF0000AA, "|BLOCK| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Reason: %s", nick(targetid), nick(playerid), reason);
    SendClientMessageToAllPL(0xFF0000AA, "|BLOKADA| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Powód: %s", nick(targetid), nick(playerid), reason);
    KickEx(targetid, playerid, reason, false);
    return 1;
}

CMD:tban(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    new targetid, day_s, hour_s, minute_s, reason[128];
    if(sscanf(params,"dddds[128]", targetid, day_s, hour_s, minute_s, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /tban [targetid] [days] [hours] [minutes] [reason]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    if(admin(playerid) < admin(targetid)) return Error(playerid, "Access denied.");
    mysql_escape_string(reason, reason);
    new czas =(60*minute_s)+(hour_s*60*60)+(day_s*24*60*60)+gettime();
    mq_format("INSERT INTO `BanList` (`uid`, `aid`, `time`, `time_end`, `ip_on`, `ip`, `gpci_on`, `gpci`, `reason`) VALUES ('%d', '%d', '%d', '%d', '1', '%s', '0', '%s', '%s');", sgracz[targetid][uID], sgracz[playerid][uID], gettime(), czas, playerip(targetid, true), serial(targetid, true), reason);
    mq_send("BANQUERY");
    SendClientMessageToAllEN(0xFF0000AA, "|BAN| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Reason: %s | Time: %dd, %dh, %dm", nick(targetid), nick(playerid), reason, day_s, hour_s, minute_s);
    SendClientMessageToAllPL(0xFF0000AA, "|BAN| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Powód: %s | Czas: %dd, %dg, %dm", nick(targetid), nick(playerid), reason, day_s, hour_s, minute_s);
    KickEx(targetid, playerid, reason, false);
    return 1;
}

CMD:ban(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    new targetid, reason[128];
    if(sscanf(params,"ds[128]", targetid, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /ban [targetid] [reason]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    if(admin(playerid) < admin(targetid)) return Error(playerid, "Access denied.");
    mysql_escape_string(reason, reason);
    new perm  = MAX_VALUE;
    mq_format("INSERT INTO `BanList` (`uid`, `aid`, `time`, `time_end`, `ip_on`, `ip`, `gpci_on`, `gpci`, `reason`) VALUES ('%d', '%d', '%d', '%d', '1', '%s', '0', '%s', '%s');", sgracz[targetid][uID], sgracz[playerid][uID], gettime(), perm, playerip(targetid, true), serial(targetid, true), reason);
    mq_send("BANQUERY");
    SendClientMessageToAllEN(0xFF0000AA, "|BAN| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Reason: %s", nick(targetid), nick(playerid), reason);
    SendClientMessageToAllPL(0xFF0000AA, "|BAN| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Powód: %s", nick(targetid), nick(playerid), reason);
    KickEx(targetid, playerid, reason, false);
    return 1;
}

CMD:eban(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new targetid, reason[128];
    if(sscanf(params,"ds[128]", targetid, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /perm [targetid] [reason]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    if(admin(playerid) < admin(targetid)) return Error(playerid, "Access denied.");
    mysql_escape_string(reason, reason);
    new perm  = MAX_VALUE;
    mq_format("INSERT INTO `BanList` (`uid`, `aid`, `time`, `time_end`, `ip_on`, `ip`, `gpci_on`, `gpci`, `reason`) VALUES ('%d', '%d', '%d', '%d', '1', '%s', '1', '%s', '%s');", sgracz[targetid][uID], sgracz[playerid][uID], gettime(), perm, playerip(targetid, true), serial(targetid, true), reason);
    mq_send("BANQUERY");
    SendClientMessageToAllEN(0xFF0000AA, "|BAN| "COL_WHITE"Player: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Reason: %s", nick(targetid), nick(playerid), reason);
    SendClientMessageToAllPL(0xFF0000AA, "|BAN| "COL_WHITE"Gracz: "COL_BLUE"%s"COL_WHITE" | Admin: "COL_RED"%s"COL_WHITE" | Powód: %s", nick(targetid), nick(playerid), reason);
    KickEx(targetid, playerid, reason, false);
    return 1;
}

CMD:check(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    new targetid;
    if(sscanf(params,"d", targetid)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /check [targetid]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    const contstr = 1024;
    new title[128], content[contstr];
    format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d][ID: %d] - "COL_YELLOW"Admin Check", nick(targetid), sgracz[targetid][uID], targetid);
    format(content, contstr, ""COL_GREY"Nick:\t"COL_BLUE"%s\n", nick(targetid));
    format(content, contstr, "%s"COL_GREY"IP:\t"COL_BLUE"%s\n", content, playerip(targetid));
    format(content, contstr, "%s"COL_GREY"Country:\t"COL_BLUE"%s\n", content, country(targetid));
    format(content, contstr, "%s"COL_GREY"Actual speed(X, Y):\t"COL_BLUE"%d km/h\n", content, GetVehicleSpeed(GetPlayerVehicleID(targetid)));
    format(content, contstr, "%s"COL_GREY"Actual speed(X, Y, Z):\t"COL_BLUE"%d km/h\n", content, GetVehicleSpeed(GetPlayerVehicleID(targetid), true));
    format(content, contstr, "%s"COL_RED"Reported times:\t"COL_BLUE"%d\n", content, sgracz[targetid][ReportedTimes]);
    format(content, contstr, "%s"COL_GREY"Virtual World:\t"COL_BLUE"%d\n", content, GetPlayerVirtualWorld(targetid));
    if(tgracz[targetid][nitro_status])
    {
        format(content, contstr, "%s"COL_GREY"Nitro:\t"COL_GREEN"YES\n", content);
    }
    else
    {
        format(content, contstr, "%s"COL_GREY"Nitro:\t"COL_RED"NO\n", content);
    }
    ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_TABLIST, title, content, "Close", "");
    return 1;
}

CMD:fvote(playerid, params[])
{
    if(admin(playerid) < 2) return 0;
    if(serwer[eMin] < 1 || !serwer[wyscig]) return Error(playerid, "At the moment you can't run force voting. Please try again later.");
    new nxmap;
    if(!sscanf(params,"d", nxmap))
    {
        if(nxmap >= 0 && admin(playerid) >= 4)
        {
            serwer[temp_mapid] = ActualMapID();
            dini_IntSet(CFG, "LastMap", nxmap-1);
            SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" You set next map id: %d", nxmap);
        }
    }
    serwer[eMin] = 0;
    serwer[eSec] = 3;
    SendClientMessageToAllEN(-1, ""COL_GREY"|VOTE|"COL_WHITE" Admin "COL_BLUE"%s"COL_WHITE" forced a vote!", nick(playerid));
    SendClientMessageToAllPL(-1, ""COL_GREY"|VOTE|"COL_WHITE" Admin "COL_BLUE"%s"COL_WHITE" wymusił głosowanie!", nick(playerid));
    return 1;
}

CMD:setscore(playerid, params[])
{
    if(admin(playerid) < 3) return 0;
    new targetid, sc;
    if(sscanf(params,"dd", targetid, sc)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /setscore [targetid] [sc]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    SetScore(targetid, sc);
    SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" You set for "COL_BLUE"%s"COL_RED" score to "COL_GREEN"%d"COL_RED".", nick(targetid), GetPlayerScore(targetid));
    return 1;
}

CMD:setveh(playerid, params[])
{
    if(admin(playerid) < 3) return 0;
    new targetid, model;
    if(sscanf(params,"dd", targetid, model)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /setveh [targetid] [model]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    if(Function(targetid, CHANGE_VEH, model)) SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" You set for "COL_BLUE"%s"COL_RED" vehicle model to "COL_GREEN"%d"COL_RED".", nick(targetid), model);
    else Error(playerid, "Invalid model ID.");
    return 1;
}

CMD:setadmin(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new targetid, lvl;
    if(sscanf(params,"dd", targetid, lvl)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /setadmin [targetid] [level]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    sgracz[targetid][adminlvl] = lvl;
    mq_format("UPDATE `players` SET `adminlvl`='%d' WHERE `id`='%d';", sgracz[targetid][adminlvl], sgracz[targetid][uID]);
    mq_send("QUERY");
    SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" You set for "COL_BLUE"%s"COL_RED" admin level to "COL_GREEN"%d"COL_RED".", nick(targetid), sgracz[targetid][adminlvl]);
    return 1;
}

CMD:setweather(playerid, params[])
{
    if(admin(playerid) < 2) return 0;
    new weather;
    if(sscanf(params,"d", weather)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /setweather [weatherid]");
    SetWeather(weather);
    SendClientMessageToAllEx(-1, "|INFO|"COL_RED" Admin "COL_BLUE"%s"COL_RED" set weather to "COL_GREEN"ID: %d"COL_RED".", nick(playerid), weather);
    return 1;
}

CMD:settime(playerid, params[])
{
    if(admin(playerid) < 2) return 0;
    new time;
    if(sscanf(params,"d", time)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /settime [time]");
    if(time > 23 || time < 0) return Error(playerid, "Invalid value, use: "COL_GREEN"0 - 23.");
    SetWorldTime(time);
    SendClientMessageToAllEx(-1, "|INFO|"COL_RED" Admin "COL_BLUE"%s"COL_RED" set time to "COL_GREEN"%d:00"COL_RED".", nick(playerid), time);
    return 1;
}

CMD:cc(playerid, params[])
{
    if(admin(playerid) < 1) return 0;
    ClearChatAll();
    SendClientMessageToAllEx(-1, "|INFO|"COL_RED" Admin "COL_BLUE"%s"COL_RED" cleared all players "COL_GREEN"chat"COL_RED".", nick(playerid));
    return 1;
}

CMD:stest(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new song;
    if(sscanf(params,"d", song)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /stest [id]");
    PlayerPlaySound(playerid, song, 0.0, 0.0, 0.0);
    SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" Sound: "COL_GREEN"%d"COL_RED".", song);
    return 1;
}

CMD:setvip(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new targetid, days;
    if(sscanf(params,"dd", targetid, days)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /setvip [targetid] [days]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    sgracz[targetid][vip_stamp] = (60*60*24*days) + gettime();
    mq_format("UPDATE `players` SET `vip`='%d' WHERE `id`='%d';", sgracz[targetid][vip_stamp], sgracz[targetid][uID]);
    mq_send("QUERY");
    SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" You set for "COL_BLUE"%s"COL_RED" VIP to "COL_GREEN"%d"COL_RED" days.", nick(targetid), days);
    return 1;
}

CMD:cpick(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new pickid, val;
    if(sscanf(params,"dd", pickid, val))
    { 
        SendClientMessage(playerid, -1, ""COL_GREY"USE: /cpick [id] [value(0)]");
        SendClientMessage(playerid, -1, ""COL_GREY"ID's: 0-fix, 1-change, 2-nitro, 3-Tnitro, 4-rocket, 5-ramp, 6-hay, 7-spike");
        return 1; 
    }
    if(pickid < 0 || pickid >7) return Error(playerid, "Invalid pickup ID");
    new Float:pPos[3];
    GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
    if(Pickup(pPos[0], pPos[1], pPos[2], pickid, val))
    {
        SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" Pick ID: "COL_GREEN"%d"COL_RED" created.", pickid);
    }
    else
    {
        Error(playerid, "Invalid pickup values.");
    }
    return 1;
}


CMD:mysql(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new stats[150]; 
    mysql_stat(stats);
    ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, "MySQL Stats - MasterRace", stats, "Close", "");
    SendClientMessage(playerid, 0xFF0000AA, stats);
    return 1;
}

CMD:getuid(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new nazwa[24];
    if(sscanf(params,"s", nazwa)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /getuid [name]");
    mysql_escape_string(nazwa, nazwa);
    mq_format("SELECT `id` FROM `players` WHERE `name`='%s' LIMIT 1;", nazwa);
    mq_send("OnAdminGetUID", "ds", playerid, nazwa);
    return 1;
}

forward OnAdminGetUID(playerid, nam[]);
public OnAdminGetUID(playerid, nam[])
{
    mq_getdata();
    if(rekordy)
    {
        SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" User: "COL_BLUE"%s"COL_RED" | UID: "COL_GREEN"%d"COL_RED".", nam, cache_get_field_content_int(0, "id"));
    }
    else
    {
        SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" User: "COL_BLUE"%s"COL_RED" not found.", nam);
    }
    return 1;
}

CMD:removerecords(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new uid;
    if(sscanf(params,"d", uid)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /removerecords [userid]");
    mq_format("DELETE FROM `map_result` WHERE `uid`='%d';", uid);
    mq_send("OnAdminDelRecord", "d", playerid);
    SendClientMessageEx(playerid, -1, "|INFO|"COL_RED" All records of player UID "COL_BLUE"%d"COL_RED" deleted!", uid);
    return 1;
}

forward OnAdminDelRecord(playerid);
public OnAdminDelRecord(playerid)
{
    GenerateTop10(ActualMapID());
    ReShowTopFinish();
    return 1;
}

CMD:vehgodtest(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new targetid, Float:hp;
    if(sscanf(params,"df", targetid, hp)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /vehgod [targetid] [-VALUEHP]");
    if(!login(targetid)) return Error(playerid, "Target ID is not logged in.");
    if(!IsPlayerInAnyVehicle(targetid)) return Error(playerid, "Target ID is not in the vehicle.");
    new vid = GetPlayerVehicleID(targetid);
    new Float:VehHP;
    GetVehicleHealth(vid, VehHP);
    SendClientMessageEx(playerid, -1, "|VEHGOD|"COL_RED" Player "COL_BLUE"%s"COL_RED" : vehicle HP: "COL_GREEN"%f", nick(targetid), VehHP);
    SendClientMessageEx(playerid, -1, "|VEHGOD|"COL_RED" RUN... "COL_YELLOW"%f-%f=%f"COL_RED" (True? Checking...)", VehHP, hp, VehHP - hp);
    SetVehicleHealth(vid, VehHP-hp);
    SetTimerEx("VehGodTest", 500, false, "ddff", targetid, playerid, VehHP, hp);
    return 1;
}

forward VehGodTest(playerid, adminid, Float:val1, Float:val2);
public VehGodTest(playerid, adminid, Float:val1, Float:val2)
{
    if(!IsPlayerInAnyVehicle(playerid)) return Error(playerid, "Checking failed! Target ID is not in the vehicle.");
    new Float:wynik;
    new vid = GetPlayerVehicleID(playerid);
    GetVehicleHealth(vid, wynik);
    SendClientMessageEx(adminid, -1, "|VEHGOD|"COL_RED" RESULT: "COL_YELLOW"%f-%f="COL_BLUE"%f", val1, val2, wynik);
    return 1;
}

CMD:streamall(playerid, params[])
{
    if(admin(playerid) < 4) return 0;
    new link[256];
    if(sscanf(params,"s[256]", link)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /streamall [link]");
    for(new p; p <= GetPlayerPoolSize(); p++)
    {
        if(!login(p)) continue;
        tgracz[p][astream] = false;
        PlayAudioStreamForPlayer(p, link);
    }
    return 1;
}
