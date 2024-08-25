//Global Textdraws:
new Text:box0;
new Text:box1;
new Text:linia0;
new Text:linia1;
new Text:linia2;
new Text:HeadTimeTD;
new Text:odl_tlo;
new Text:odl_text;
new Text:LewaULista;
new Text:msraceTD;
new Text:win_top10_box;
new Text:win_top10_kontur1;
new Text:win_top10_kontur2;
new Text:win_top10_kontur3;
new Text:win_top10_kontur4;
new Text:win_top10_kontur5;
new Text:win_top10_title;
new Text:win_top10_kontur6;
new Text:win_top10_time;
new Text:win_top10_lp;
new Text:win_top10_nickname;
new Text:ScreenHide;
new Text:upradartext;

stock LoadGlobalTD()
{
    box0 = TextDrawCreate(675.000000, 375.125000, "usebox");
    TextDrawLetterSize(box0, 0.000000, 11.058333);
    TextDrawTextSize(box0, 492.000000, 0.000000);
    TextDrawAlignment(box0, 1);
    TextDrawColor(box0, 0);
    TextDrawUseBox(box0, true);
    TextDrawBoxColor(box0, 102);
    TextDrawSetShadow(box0, 0);
    TextDrawSetOutline(box0, 0);
    TextDrawFont(box0, 0);
    
    linia0 = TextDrawCreate(493.500000, 392.000000, "LD_SPAC:white");
    TextDrawLetterSize(linia0, 0.000000, 0.000000);
    TextDrawTextSize(linia0, 175.500000, 1.312500);
    TextDrawAlignment(linia0, 1);
    TextDrawColor(linia0, -1);
    TextDrawSetShadow(linia0, 0);
    TextDrawSetOutline(linia0, 0);
    TextDrawFont(linia0, 4);
    
    linia1 = TextDrawCreate(494.000000, 412.250000, "LD_SPAC:white");
    TextDrawLetterSize(linia1, 0.000000, 0.000000);
    TextDrawTextSize(linia1, 175.500000, 1.312500);
    TextDrawAlignment(linia1, 1);
    TextDrawColor(linia1, -1);
    TextDrawSetShadow(linia1, 0);
    TextDrawSetOutline(linia1, 0);
    TextDrawFont(linia1, 4);
    
    linia2 = TextDrawCreate(494.000000, 429.437500, "LD_SPAC:white");
    TextDrawLetterSize(linia2, 0.000000, 0.000000);
    TextDrawTextSize(linia2, 175.500000, 1.312500);
    TextDrawAlignment(linia2, 1);
    TextDrawColor(linia2, -1);
    TextDrawSetShadow(linia2, 0);
    TextDrawSetOutline(linia2, 0);
    TextDrawFont(linia2, 4);
    
    box1 = TextDrawCreate(338.500000, 0.625000, "usebox");
    TextDrawLetterSize(box1, 0.000000, 1.044444);
    TextDrawTextSize(box1, 298.000000, 0.000000);
    TextDrawAlignment(box1, 1);
    TextDrawColor(box1, 0);
    TextDrawUseBox(box1, true);
    TextDrawBoxColor(box1, 102);
    TextDrawSetShadow(box1, 0);
    TextDrawSetOutline(box1, 0);
    TextDrawFont(box1, 0);

    HeadTimeTD = TextDrawCreate(318.000000, 2.187500, "~g~00~w~:~r~00");
    TextDrawLetterSize(HeadTimeTD, 0.250000, 0.873750);
    TextDrawAlignment(HeadTimeTD, 2);
    TextDrawColor(HeadTimeTD, -1);
    TextDrawSetShadow(HeadTimeTD, 0);
    TextDrawSetOutline(HeadTimeTD, 1);
    TextDrawBackgroundColor(HeadTimeTD, 51);
    TextDrawFont(HeadTimeTD, 3);
    TextDrawSetProportional(HeadTimeTD, 1);

    odl_tlo = TextDrawCreate(284.500000, 112.437500, "LD_POOL:ball");
    TextDrawLetterSize(odl_tlo, 0.000000, 0.000000);
    TextDrawTextSize(odl_tlo, 69.500000, 47.250000);
    TextDrawAlignment(odl_tlo, 1);
    TextDrawColor(odl_tlo, -16777104);
    TextDrawSetShadow(odl_tlo, 0);
    TextDrawSetOutline(odl_tlo, 0);
    TextDrawFont(odl_tlo, 4);
    
    odl_text = TextDrawCreate(321.000000, 122.500000, "GO!");
    TextDrawLetterSize(odl_text, 0.962000, 2.615000);
    TextDrawAlignment(odl_text, 2);
    TextDrawColor(odl_text, -1);
    TextDrawSetShadow(odl_text, 0);
    TextDrawSetOutline(odl_text, 1);
    TextDrawBackgroundColor(odl_text, 51);
    TextDrawFont(odl_text, 3);
    TextDrawSetProportional(odl_text, 1);

    LewaULista = TextDrawCreate(1.500000, 157.937500, "-");
    TextDrawLetterSize(LewaULista, 0.203999, 0.786251);
    TextDrawTextSize(LewaULista, 124.000000, 77.437500);
    TextDrawAlignment(LewaULista, 1);
    TextDrawColor(LewaULista, -1);
    TextDrawUseBox(LewaULista, true);
    TextDrawBoxColor(LewaULista, 80);
    TextDrawSetShadow(LewaULista, 0);
    TextDrawSetOutline(LewaULista, 1);
    TextDrawBackgroundColor(LewaULista, 51);
    TextDrawFont(LewaULista, 1);
    TextDrawSetProportional(LewaULista, 1);

    msraceTD = TextDrawCreate(5.500000, 430.500000, "Master Race");
    TextDrawLetterSize(msraceTD, 0.449999, 1.600000);
    TextDrawAlignment(msraceTD, 1);
    TextDrawColor(msraceTD, 16711935);
    TextDrawSetShadow(msraceTD, 0);
    TextDrawSetOutline(msraceTD, 1);
    TextDrawBackgroundColor(msraceTD, 51);
    TextDrawFont(msraceTD, 3);
    TextDrawSetProportional(msraceTD, 1);

    win_top10_box = TextDrawCreate(715.500000, 113.062500, "usebox");
    TextDrawLetterSize(win_top10_box, 0.000000, 16.430553);
    TextDrawTextSize(win_top10_box, 441.000000, 0.000000);
    TextDrawAlignment(win_top10_box, 1);
    TextDrawColor(win_top10_box, 0);
    TextDrawUseBox(win_top10_box, true);
    TextDrawBoxColor(win_top10_box, 102);
    TextDrawSetShadow(win_top10_box, 0);
    TextDrawSetOutline(win_top10_box, 0);
    TextDrawFont(win_top10_box, 0);

    win_top10_kontur1 = TextDrawCreate(443.000000, 126.875000, "LD_SPAC:white");
    TextDrawLetterSize(win_top10_kontur1, 0.000000, 0.000000);
    TextDrawTextSize(win_top10_kontur1, 330.500000, 1.750000);
    TextDrawAlignment(win_top10_kontur1, 1);
    TextDrawColor(win_top10_kontur1, -5963521);
    TextDrawSetShadow(win_top10_kontur1, 0);
    TextDrawSetOutline(win_top10_kontur1, 0);
    TextDrawFont(win_top10_kontur1, 4);

    win_top10_kontur2 = TextDrawCreate(444.500000, 110.812500, "LD_SPAC:white");
    TextDrawLetterSize(win_top10_kontur2, 0.000000, 0.000000);
    TextDrawTextSize(win_top10_kontur2, 330.500000, 1.750000);
    TextDrawAlignment(win_top10_kontur2, 1);
    TextDrawColor(win_top10_kontur2, -5963521);
    TextDrawSetShadow(win_top10_kontur2, 0);
    TextDrawSetOutline(win_top10_kontur2, 0);
    TextDrawFont(win_top10_kontur2, 4);

    win_top10_kontur3 = TextDrawCreate(443.000000, 261.875000, "LD_SPAC:white");
    TextDrawLetterSize(win_top10_kontur3, 0.000000, 0.000000);
    TextDrawTextSize(win_top10_kontur3, 330.500000, 1.750000);
    TextDrawAlignment(win_top10_kontur3, 1);
    TextDrawColor(win_top10_kontur3, -5963521);
    TextDrawSetShadow(win_top10_kontur3, 0);
    TextDrawSetOutline(win_top10_kontur3, 0);
    TextDrawFont(win_top10_kontur3, 4);

    win_top10_kontur4 = TextDrawCreate(442.500000, 111.062500, "LD_SPAC:white");
    TextDrawLetterSize(win_top10_kontur4, 0.000000, 0.000000);
    TextDrawTextSize(win_top10_kontur4, 2.000000, 152.687500);
    TextDrawAlignment(win_top10_kontur4, 1);
    TextDrawColor(win_top10_kontur4, -5963521);
    TextDrawSetShadow(win_top10_kontur4, 0);
    TextDrawSetOutline(win_top10_kontur4, 0);
    TextDrawFont(win_top10_kontur4, 4);

    win_top10_kontur5 = TextDrawCreate(464.500000, 110.750000, "LD_SPAC:white");
    TextDrawLetterSize(win_top10_kontur5, 0.000000, 0.000000);
    TextDrawTextSize(win_top10_kontur5, 2.000000, 152.687500);
    TextDrawAlignment(win_top10_kontur5, 1);
    TextDrawColor(win_top10_kontur5, -5963521);
    TextDrawSetShadow(win_top10_kontur5, 0);
    TextDrawSetOutline(win_top10_kontur5, 0);
    TextDrawFont(win_top10_kontur5, 4);

    win_top10_kontur6 = TextDrawCreate(582.500000, 111.000000, "LD_SPAC:white");
    TextDrawLetterSize(win_top10_kontur6, 0.000000, 0.000000);
    TextDrawTextSize(win_top10_kontur6, 2.000000, 152.687500);
    TextDrawAlignment(win_top10_kontur6, 1);
    TextDrawColor(win_top10_kontur6, -5963521);
    TextDrawSetShadow(win_top10_kontur6, 0);
    TextDrawSetOutline(win_top10_kontur6, 0);
    TextDrawFont(win_top10_kontur6, 4);

    win_top10_title = TextDrawCreate(443.500000, 100.187500, "Top 10 - mapname by author");
    TextDrawLetterSize(win_top10_title, 0.182999, 1.022500);
    TextDrawAlignment(win_top10_title, 1);
    TextDrawColor(win_top10_title, -1);
    TextDrawSetShadow(win_top10_title, 0);
    TextDrawSetOutline(win_top10_title, 1);
    TextDrawBackgroundColor(win_top10_title, 51);
    TextDrawFont(win_top10_title, 2);
    TextDrawSetProportional(win_top10_title, 1);

    win_top10_lp = TextDrawCreate(453.500000, 114.187500, "#~n~1~n~2~n~3~n~4~n~5~n~6~n~7~n~8~n~9~n~10");
    TextDrawLetterSize(win_top10_lp, 0.354000, 1.490624);
    TextDrawAlignment(win_top10_lp, 2);
    TextDrawColor(win_top10_lp, -1);
    TextDrawSetShadow(win_top10_lp, 0);
    TextDrawSetOutline(win_top10_lp, 1);
    TextDrawBackgroundColor(win_top10_lp, 51);
    TextDrawFont(win_top10_lp, 1);
    TextDrawSetProportional(win_top10_lp, 1);

    win_top10_nickname = TextDrawCreate(524.500000, 113.437500, "Nickname~n~nick1~n~nick2~n~nick3~n~nick4~n~nick5~n~nick6~n~nick6~n~nick8~n~nick9~n~nick10");
    TextDrawLetterSize(win_top10_nickname, 0.232500, 1.490624);
    TextDrawAlignment(win_top10_nickname, 2);
    TextDrawColor(win_top10_nickname, -1);
    TextDrawSetShadow(win_top10_nickname, 0);
    TextDrawSetOutline(win_top10_nickname, 1);
    TextDrawBackgroundColor(win_top10_nickname, 51);
    TextDrawFont(win_top10_nickname, 1);
    TextDrawSetProportional(win_top10_nickname, 1);

    win_top10_time = TextDrawCreate(610.000000, 113.000000, "Time~n~59:59.99~n~59:59.99~n~59:59.99~n~59:59.99~n~59:59.99~n~59:59.99~n~59:59.99~n~59:59.99~n~59:59.99~n~59:59.99~n~");
    TextDrawLetterSize(win_top10_time, 0.237000, 1.486249);
    TextDrawAlignment(win_top10_time, 2);
    TextDrawColor(win_top10_time, -1);
    TextDrawSetShadow(win_top10_time, 0);
    TextDrawSetOutline(win_top10_time, 1);
    TextDrawBackgroundColor(win_top10_time, 51);
    TextDrawFont(win_top10_time, 1);
    TextDrawSetProportional(win_top10_time, 1);

    ScreenHide = TextDrawCreate(-22.000000, -10.937500, "loadsc6:loadsc6");
    TextDrawLetterSize(ScreenHide, 0.000000, 0.000000);
    TextDrawTextSize(ScreenHide, 706.000000, 475.125000);
    TextDrawAlignment(ScreenHide, 1);
    TextDrawColor(ScreenHide, -1);
    TextDrawSetShadow(ScreenHide, 0);
    TextDrawSetOutline(ScreenHide, 0);
    TextDrawFont(ScreenHide, 4);

    upradartext = TextDrawCreate(85.000000, 329.437500, "~g~ENTER~w~ - Retry");
    TextDrawLetterSize(upradartext, 0.206498, 0.930625);
    TextDrawAlignment(upradartext, 2);
    TextDrawColor(upradartext, -1);
    TextDrawSetShadow(upradartext, 0);
    TextDrawSetOutline(upradartext, 1);
    TextDrawBackgroundColor(upradartext, 51);
    TextDrawFont(upradartext, 1);
    TextDrawSetProportional(upradartext, 1);

    return 1;
}

//Player Textdraws:
new PlayerText:posTD[MAX_PLAYERS];
new PlayerText:checkTD[MAX_PLAYERS];
new PlayerText:pTime[MAX_PLAYERS];
new PlayerText:nextcpTD[MAX_PLAYERS];
new PlayerText:weapontd[MAX_PLAYERS];
new PlayerText:win_top10_pArrow[MAX_PLAYERS];
new PlayerText:win_top10_pNick[MAX_PLAYERS];
new PlayerText:win_top10_pTime[MAX_PLAYERS];
new PlayerText:fps_and_ping[MAX_PLAYERS];
new PlayerText:oppData[MAX_PLAYERS];
new PlayerText:oppTitle[MAX_PLAYERS];
new PlayerText:specData[MAX_PLAYERS];

stock LoadPlayerTD(playerid)
{
    posTD[playerid] = CreatePlayerTextDraw(playerid, 566.000000, 375.625000, "~b~P~w~OSITION: ~g~0~w~/~r~0");
    PlayerTextDrawLetterSize(playerid, posTD[playerid], 0.370499, 1.473124);
    PlayerTextDrawAlignment(playerid, posTD[playerid], 2);
    PlayerTextDrawColor(playerid, posTD[playerid], -1);
    PlayerTextDrawSetShadow(playerid, posTD[playerid], 0);
    PlayerTextDrawSetOutline(playerid, posTD[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, posTD[playerid], 51);
    PlayerTextDrawFont(playerid, posTD[playerid], 3);
    PlayerTextDrawSetProportional(playerid, posTD[playerid], 1);
    
    checkTD[playerid] = CreatePlayerTextDraw(playerid, 565.500000, 396.062500, "~b~C~w~HECK~b~P~w~OINT: ~g~0~w~/~r~0");
    PlayerTextDrawLetterSize(playerid, checkTD[playerid], 0.370499, 1.473124);
    PlayerTextDrawAlignment(playerid, checkTD[playerid], 2);
    PlayerTextDrawColor(playerid, checkTD[playerid], -1);
    PlayerTextDrawSetShadow(playerid, checkTD[playerid], 0);
    PlayerTextDrawSetOutline(playerid, checkTD[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, checkTD[playerid], 51);
    PlayerTextDrawFont(playerid, checkTD[playerid], 3);
    PlayerTextDrawSetProportional(playerid, checkTD[playerid], 1);
    
    pTime[playerid] = CreatePlayerTextDraw(playerid, 567.000000, 431.000000, "~b~T~w~IME: ~y~00~w~:~g~00~w~.~r~00");
    PlayerTextDrawLetterSize(playerid, pTime[playerid], 0.370499, 1.473124);
    PlayerTextDrawAlignment(playerid, pTime[playerid], 2);
    PlayerTextDrawColor(playerid, pTime[playerid], -1);
    PlayerTextDrawSetShadow(playerid, pTime[playerid], 0);
    PlayerTextDrawSetOutline(playerid, pTime[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, pTime[playerid], 51);
    PlayerTextDrawFont(playerid, pTime[playerid], 3);
    PlayerTextDrawSetProportional(playerid, pTime[playerid], 1);

    nextcpTD[playerid] = CreatePlayerTextDraw(playerid, 567.000000, 413.375000, "~b~N~w~EXT ~b~CP~w~: ~g~0~r~m");
    PlayerTextDrawLetterSize(playerid, nextcpTD[playerid], 0.370499, 1.473124);
    PlayerTextDrawAlignment(playerid, nextcpTD[playerid], 2);
    PlayerTextDrawColor(playerid, nextcpTD[playerid], -1);
    PlayerTextDrawSetShadow(playerid, nextcpTD[playerid], 0);
    PlayerTextDrawSetOutline(playerid, nextcpTD[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, nextcpTD[playerid], 51);
    PlayerTextDrawFont(playerid, nextcpTD[playerid], 3);
    PlayerTextDrawSetProportional(playerid, nextcpTD[playerid], 1);

    weapontd[playerid] = CreatePlayerTextDraw(playerid, 577.000000, 45.062500, "NONE");
    PlayerTextDrawLetterSize(playerid, weapontd[playerid], 0.153999, 0.948126);
    PlayerTextDrawTextSize(playerid, weapontd[playerid], 1.500000, 59.937500);
    PlayerTextDrawAlignment(playerid, weapontd[playerid], 2);
    PlayerTextDrawColor(playerid, weapontd[playerid], 16711935);
    PlayerTextDrawUseBox(playerid, weapontd[playerid], true);
    PlayerTextDrawBoxColor(playerid, weapontd[playerid], -16776961);
    PlayerTextDrawSetShadow(playerid, weapontd[playerid], 0);
    PlayerTextDrawSetOutline(playerid, weapontd[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, weapontd[playerid], 51);
    PlayerTextDrawFont(playerid, weapontd[playerid], 2);
    PlayerTextDrawSetProportional(playerid, weapontd[playerid], 1);

    win_top10_pArrow[playerid] = CreatePlayerTextDraw(playerid, 448.000000, 262.500000, "~>~");
    PlayerTextDrawLetterSize(playerid, win_top10_pArrow[playerid], 0.449999, 1.600000);
    PlayerTextDrawAlignment(playerid, win_top10_pArrow[playerid], 2);
    PlayerTextDrawColor(playerid, win_top10_pArrow[playerid], -1);
    PlayerTextDrawSetShadow(playerid, win_top10_pArrow[playerid], 0);
    PlayerTextDrawSetOutline(playerid, win_top10_pArrow[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, win_top10_pArrow[playerid], 51);
    PlayerTextDrawFont(playerid, win_top10_pArrow[playerid], 1);
    PlayerTextDrawSetProportional(playerid, win_top10_pArrow[playerid], 1);

    win_top10_pNick[playerid] = CreatePlayerTextDraw(playerid, 523.500000, 262.500000, "nick");
    PlayerTextDrawLetterSize(playerid, win_top10_pNick[playerid], 0.248998, 1.600000);
    PlayerTextDrawAlignment(playerid, win_top10_pNick[playerid], 2);
    PlayerTextDrawColor(playerid, win_top10_pNick[playerid], 16711935);
    PlayerTextDrawSetShadow(playerid, win_top10_pNick[playerid], 0);
    PlayerTextDrawSetOutline(playerid, win_top10_pNick[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, win_top10_pNick[playerid], 51);
    PlayerTextDrawFont(playerid, win_top10_pNick[playerid], 1);
    PlayerTextDrawSetProportional(playerid, win_top10_pNick[playerid], 1);

    win_top10_pTime[playerid] = CreatePlayerTextDraw(playerid, 610.000000, 262.187500, "00:00.00");
    PlayerTextDrawLetterSize(playerid, win_top10_pTime[playerid], 0.248998, 1.600000);
    PlayerTextDrawAlignment(playerid, win_top10_pTime[playerid], 2);
    PlayerTextDrawColor(playerid, win_top10_pTime[playerid], 16711935);
    PlayerTextDrawSetShadow(playerid, win_top10_pTime[playerid], 0);
    PlayerTextDrawSetOutline(playerid, win_top10_pTime[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, win_top10_pTime[playerid], 51);
    PlayerTextDrawFont(playerid, win_top10_pTime[playerid], 1);
    PlayerTextDrawSetProportional(playerid, win_top10_pTime[playerid], 1);

    fps_and_ping[playerid] = CreatePlayerTextDraw(playerid, 540.500000, 3.500000, "~b~FPS~w~: ~g~0 ~b~PING~w~: ~g~0");
    PlayerTextDrawLetterSize(playerid, fps_and_ping[playerid], 0.449999, 1.600000);
    PlayerTextDrawAlignment(playerid, fps_and_ping[playerid], 2);
    PlayerTextDrawColor(playerid, fps_and_ping[playerid], -1);
    PlayerTextDrawSetShadow(playerid, fps_and_ping[playerid], 0);
    PlayerTextDrawSetOutline(playerid, fps_and_ping[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, fps_and_ping[playerid], 51);
    PlayerTextDrawFont(playerid, fps_and_ping[playerid], 2);
    PlayerTextDrawSetProportional(playerid, fps_and_ping[playerid], 1);

    oppData[playerid] = CreatePlayerTextDraw(playerid, 2.000000, 275.000000, "~n~ --- ~>~ ---~n~ --- ~>~ ---~n~ --- ~>~ ---");
    PlayerTextDrawLetterSize(playerid, oppData[playerid], 0.146500, 0.799374);
    PlayerTextDrawTextSize(playerid, oppData[playerid], 116.000000, -45.062500);
    PlayerTextDrawAlignment(playerid, oppData[playerid], 1);
    PlayerTextDrawColor(playerid, oppData[playerid], -1);
    PlayerTextDrawUseBox(playerid, oppData[playerid], true);
    PlayerTextDrawBoxColor(playerid, oppData[playerid], 9736288);
    PlayerTextDrawSetShadow(playerid, oppData[playerid], 0);
    PlayerTextDrawSetOutline(playerid, oppData[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, oppData[playerid], 51);
    PlayerTextDrawFont(playerid, oppData[playerid], 1);
    PlayerTextDrawSetProportional(playerid, oppData[playerid], 1);

    oppTitle[playerid] = CreatePlayerTextDraw(playerid, 56.500000, 268.625000, "Opponents");
    PlayerTextDrawLetterSize(playerid, oppTitle[playerid], 0.193999, 0.956875);
    PlayerTextDrawAlignment(playerid, oppTitle[playerid], 2);
    PlayerTextDrawColor(playerid, oppTitle[playerid], -16776961);
    PlayerTextDrawSetShadow(playerid, oppTitle[playerid], 0);
    PlayerTextDrawSetOutline(playerid, oppTitle[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, oppTitle[playerid], 51);
    PlayerTextDrawFont(playerid, oppTitle[playerid], 1);
    PlayerTextDrawSetProportional(playerid, oppTitle[playerid], 1);

    specData[playerid] = CreatePlayerTextDraw(playerid, 303.000000, 305.812500, "~<~ gracznazwa ~>~");
    PlayerTextDrawLetterSize(playerid, specData[playerid], 0.449999, 1.600000);
    PlayerTextDrawAlignment(playerid, specData[playerid], 2);
    PlayerTextDrawColor(playerid, specData[playerid], -65281);
    PlayerTextDrawSetShadow(playerid, specData[playerid], 0);
    PlayerTextDrawSetOutline(playerid, specData[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, specData[playerid], 51);
    PlayerTextDrawFont(playerid, specData[playerid], 1);
    PlayerTextDrawSetProportional(playerid, specData[playerid], 1);

    return ShowTD(playerid);
}

//pokazywanie
stock ShowTD(playerid)
{
    TextDrawShowForPlayer(playerid, box0);
    TextDrawShowForPlayer(playerid, HeadTimeTD);
    TextDrawShowForPlayer(playerid, linia0);
    TextDrawShowForPlayer(playerid, linia1);
    TextDrawShowForPlayer(playerid, linia2);
    TextDrawShowForPlayer(playerid, box1);
    TextDrawShowForPlayer(playerid, msraceTD);
    TextDrawShowForPlayer(playerid, upradartext);
    String_PosTD(playerid, POnline(), POnline());
    String_checkTD(playerid, 0, GetCountCheckpoints());
    String_pTime(playerid, 0, 0, 0);
    String_nextcpTD(playerid, 0);
    String_FpsPing(playerid, 0, 0);
    return 1;
}

//Sterowanie:
stock String_PosTD(playerid, miejsce, maxmiejsc)
{
    new str[128];
    if(polak(playerid)) format(str, 128, "~b~P~w~OZYCJA: ~g~%d~w~/~r~%d", miejsce, maxmiejsc);
    else format(str, 128, "~b~P~w~OSITION: ~g~%d~w~/~r~%d", miejsce, maxmiejsc);
    PlayerTextDrawSetString(playerid, posTD[playerid], str);
    PlayerTextDrawShow(playerid, posTD[playerid]);
    return 1;
}

stock String_checkTD(playerid, act, max)
{
    new str[128];
    format(str, 128, "~b~C~w~HECK~b~P~w~OINT: ~g~%d~w~/~r~%02d", act, max);
    PlayerTextDrawSetString(playerid, checkTD[playerid], str);
    PlayerTextDrawShow(playerid, checkTD[playerid]);
    return 1;
}

stock String_pTime(playerid, pmin, psec, pms)
{
    new str[128];
    if(polak(playerid)) format(str, 128, "~b~C~w~ZAS: ~y~%02d~w~:~g~%02d~w~.~r~%d", pmin, psec, pms);
    else format(str, 128, "~b~T~w~IME: ~y~%02d~w~:~g~%02d~w~.~r~%d", pmin, psec, pms);
    PlayerTextDrawSetString(playerid, pTime[playerid], str);
    PlayerTextDrawShow(playerid, pTime[playerid]);
    return 1;
}

stock String_nextcpTD(playerid, meters)
{
    new str[128];
    format(str, 128, "~b~N~w~EXT ~b~CP~w~: ~g~%03d~r~m", meters);
    PlayerTextDrawSetString(playerid, nextcpTD[playerid], str);
    PlayerTextDrawShow(playerid, nextcpTD[playerid]);
    return 1;
}

stock String_odliczTD(wartosc)
{
    new str[128];
    if(wartosc)
    { 
        if(wartosc > 1) TextDrawColor(odl_tlo, 0xFF000070); 
        else TextDrawColor(odl_tlo, 0xFFFF0070); 
        format(str, 128, "%d", wartosc);
    }
    else
    {
        TextDrawColor(odl_tlo, 0x00FF0070);
        format(str, 128, "GO!");
    } 
    TextDrawSetString(odl_text, str);
    return 1;
}

new str_ulista[512];
stock String_ulista(txt[], add)
{
    if(add)
    {
        format(str_ulista, 512, "%s%s~n~", str_ulista, txt);
        TextDrawSetString(LewaULista, str_ulista);
        TextDrawShowForAll(LewaULista);
    }
    else
    {
        format(str_ulista, 512, "");
        TextDrawHideForAll(LewaULista);
    }
    return 1;
}

stock String_weaponTD(playerid, nweap[], hidew = false)
{
    if(!hidew)
    {
        PlayerTextDrawSetString(playerid, weapontd[playerid], nweap);
        PlayerTextDrawShow(playerid, weapontd[playerid]);
    }
    else
    {
        PlayerTextDrawHide(playerid, weapontd[playerid]);
    }
    return 1;
}


stock TopWindowShow(playerid, titlestr[], nicknamestr[], timestr[])
{
    TextDrawSetString(win_top10_title, titlestr);
    TextDrawSetString(win_top10_nickname, nicknamestr);
    TextDrawSetString(win_top10_time, timestr);
    TextDrawShowForPlayer(playerid, win_top10_box);
    TextDrawShowForPlayer(playerid, win_top10_kontur1);
    TextDrawShowForPlayer(playerid, win_top10_kontur2);
    TextDrawShowForPlayer(playerid, win_top10_kontur3);
    TextDrawShowForPlayer(playerid, win_top10_kontur4);
    TextDrawShowForPlayer(playerid, win_top10_kontur5);
    TextDrawShowForPlayer(playerid, win_top10_kontur6);
    TextDrawShowForPlayer(playerid, win_top10_title);
    TextDrawShowForPlayer(playerid, win_top10_time);
    TextDrawShowForPlayer(playerid, win_top10_lp);
    TextDrawShowForPlayer(playerid, win_top10_nickname);
    mq_format("SELECT * FROM `map_result` WHERE `uid`='%d' AND `mid`='%d' ORDER BY `ems` ASC LIMIT 1;", sgracz[playerid][uID], ActualMapID());
    mq_send("OnRowPlayerGen", "d", playerid);
    return 1;
}

forward OnRowPlayerGen(playerid);
public OnRowPlayerGen(playerid)
{
    new czas[16];
    PlayerTextDrawSetString(playerid, win_top10_pNick[playerid], nick(playerid));
    new tmin, tsec, tms;
    tmin = cache_get_field_content_int(0, "min");
    tsec = cache_get_field_content_int(0, "sec");
    tms = cache_get_field_content_int(0, "ms");
    if(tmin && tsec && tms)
    {
        format(czas, 16, "%02d:%02d.%02d", tmin, tsec, tms);
    }
    else
    {
        format(czas, 16, "--:--.--");
    }
    PlayerTextDrawSetString(playerid, win_top10_pTime[playerid], czas);
    PlayerTextDrawShow(playerid, win_top10_pArrow[playerid]);
    PlayerTextDrawShow(playerid, win_top10_pNick[playerid]);
    PlayerTextDrawShow(playerid, win_top10_pTime[playerid]);
    return 1;
}

stock TopWindowHide(playerid)
{
    TextDrawHideForPlayer(playerid, win_top10_box);
    TextDrawHideForPlayer(playerid, win_top10_kontur1);
    TextDrawHideForPlayer(playerid, win_top10_kontur2);
    TextDrawHideForPlayer(playerid, win_top10_kontur3);
    TextDrawHideForPlayer(playerid, win_top10_kontur4);
    TextDrawHideForPlayer(playerid, win_top10_kontur5);
    TextDrawHideForPlayer(playerid, win_top10_kontur6);
    TextDrawHideForPlayer(playerid, win_top10_title);
    TextDrawHideForPlayer(playerid, win_top10_time);
    TextDrawHideForPlayer(playerid, win_top10_lp);
    TextDrawHideForPlayer(playerid, win_top10_nickname);
    PlayerTextDrawHide(playerid, win_top10_pArrow[playerid]);
    PlayerTextDrawHide(playerid, win_top10_pNick[playerid]);
    PlayerTextDrawHide(playerid, win_top10_pTime[playerid]);
    return 1;
}


stock String_FpsPing(playerid, fpss, ping)
{
    new str[64];
    if(fpss < 20 && ping > 110)
    {
        format(str, 64, "~b~FPS~w~: ~r~%d ~b~PING~w~: ~r~%d", fpss, ping);
    }
    else if(fpss > 20 && ping < 110)
    {
        format(str, 64, "~b~FPS~w~: ~g~%d ~b~PING~w~: ~g~%d", fpss, ping);
    }
    else if(fpss < 20 && ping < 110)
    {
        format(str, 64, "~b~FPS~w~: ~r~%d ~b~PING~w~: ~g~%d", fpss, ping);
    }
    else if(fpss > 20 && ping > 110)
    {
        format(str, 64, "~b~FPS~w~: ~g~%d ~b~PING~w~: ~r~%d", fpss, ping);
    }
    else
    {
        format(str, 64, "~b~FPS~w~: ~g~%d ~b~PING~w~: ~g~%d", fpss, ping);
    }
    PlayerTextDrawSetString(playerid, fps_and_ping[playerid], str);
    PlayerTextDrawShow(playerid, fps_and_ping[playerid]);
    return 1;
}

stock HideScreen(playerid) return TextDrawShowForPlayer(playerid, ScreenHide);
stock ShowScreen(playerid) return TextDrawHideForPlayer(playerid, ScreenHide);
stock UpRadarSet(txt[]) TextDrawSetString(upradartext, txt);

stock OppShow(playerid)
{
    if(sgracz[playerid][zpolski]) PlayerTextDrawSetString(playerid, oppTitle[playerid], "Przeciwnicy");
    else PlayerTextDrawSetString(playerid, oppTitle[playerid], "Opponents");
    PlayerTextDrawShow(playerid, oppData[playerid]);
    PlayerTextDrawShow(playerid, oppTitle[playerid]);
    return 1;
}

stock OppHide(playerid)
{
    PlayerTextDrawHide(playerid, oppData[playerid]);
    PlayerTextDrawHide(playerid, oppTitle[playerid]);
    return 1;
}

stock OppSetData(playerid, dane[])
{
    PlayerTextDrawSetString(playerid, oppData[playerid], dane);
    return 1;
}

stock String_specTD(playerid, sdat[], hides = false)
{
    if(!hides)
    {
        new strf[64];
        format(strf, 64, "~<~ %s ~>~", sdat);
        PlayerTextDrawSetString(playerid, specData[playerid], strf);
        PlayerTextDrawShow(playerid, specData[playerid]);
    }
    else
    {
        PlayerTextDrawHide(playerid, specData[playerid]);
    }
    return 1;
}