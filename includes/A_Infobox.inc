/*
	Include: A_Infobox
	Include by: Azure
	Version: 2.00
	Release: 15.07.2013
	native InfoText(playerid,overview[50],text[200],time);
	native InfoTextForAll(overview[50],text[200],time);
*/
new Text:InfoBoxTextdraw[2];
new Text:InfoBoxPLTextdraw[MAX_PLAYERS][2];
new Text:InfoBoxPLTextdrawAll[MAX_PLAYERS][2];
new bool:InfoTextState[MAX_PLAYERS];
new InfoTextStateAll[MAX_PLAYERS];
new InfoBoxTimer[MAX_PLAYERS];
new InfoBoxTimerAll[MAX_PLAYERS];

forward InfoBoxHide(playerid);
forward InfoBoxHideAll();

public OnGameModeInit()
{
	InfoBoxTextdraw[0] = TextDrawCreate(630.000000, 350.000000, "~n~~n~~n~~n~~n~~n~~n~~n~");
	TextDrawBackgroundColor(InfoBoxTextdraw[0], 255);
	TextDrawFont(InfoBoxTextdraw[0], 1);
	TextDrawLetterSize(InfoBoxTextdraw[0], 0.500000, 1.000000);
	TextDrawColor(InfoBoxTextdraw[0], 120);
	TextDrawSetOutline(InfoBoxTextdraw[0], 0);
	TextDrawSetProportional(InfoBoxTextdraw[0], 1);
	TextDrawSetShadow(InfoBoxTextdraw[0], 1);
	TextDrawUseBox(InfoBoxTextdraw[0], 1);
	TextDrawBoxColor(InfoBoxTextdraw[0], 336860270);
	TextDrawTextSize(InfoBoxTextdraw[0], 480.000000, 0.000000);
	
	InfoBoxTextdraw[1] = TextDrawCreate(630.000000, 350.000000, "_");
	TextDrawBackgroundColor(InfoBoxTextdraw[1], 255);
	TextDrawFont(InfoBoxTextdraw[1], 1);
	TextDrawLetterSize(InfoBoxTextdraw[1], 0.500000, 1.500000);
	TextDrawColor(InfoBoxTextdraw[1], -1);
	TextDrawSetOutline(InfoBoxTextdraw[1], 0);
	TextDrawSetProportional(InfoBoxTextdraw[1], 1);
	TextDrawSetShadow(InfoBoxTextdraw[1], 1);
	TextDrawUseBox(InfoBoxTextdraw[1], 1);
	TextDrawBoxColor(InfoBoxTextdraw[1], 255);
	TextDrawTextSize(InfoBoxTextdraw[1], 480.000000, 0.000000);
	
	return CallLocalFunction("__OnGameModeInit","");
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit __OnGameModeInit
forward __OnGameModeInit();

stock InfoTextForAll(overview[50],text[200],time)
{
	for(new i=0; i<MAX_PLAYERS; i++)
	{
		if(!InfoTextStateAll[i] && !InfoTextState[i])
		{
			KillTimer(InfoBoxTimerAll[i]);
			TextDrawShowForPlayer(i,InfoBoxTextdraw[0]);
			TextDrawShowForPlayer(i,InfoBoxTextdraw[1]);
			
			InfoBoxPLTextdrawAll[i][0] = TextDrawCreate(509.000000, 350.000000, overview);
			TextDrawBackgroundColor(InfoBoxPLTextdrawAll[i][0], 255);
			TextDrawFont(InfoBoxPLTextdrawAll[i][0], 2);
			TextDrawLetterSize(InfoBoxPLTextdrawAll[i][0], 0.300000, 1.299998);
			TextDrawColor(InfoBoxPLTextdrawAll[i][0], -65281);
			TextDrawSetOutline(InfoBoxPLTextdrawAll[i][0], 1);
			TextDrawSetProportional(InfoBoxPLTextdrawAll[i][0], 1);
			
			InfoBoxPLTextdrawAll[i][1] = TextDrawCreate(487.000000, 369.000000, text);
			TextDrawBackgroundColor(InfoBoxPLTextdrawAll[i][1], 255);
			TextDrawFont(InfoBoxPLTextdrawAll[i][1], 1);
			TextDrawLetterSize(InfoBoxPLTextdrawAll[i][1], 0.259999, 0.899999);
			TextDrawColor(InfoBoxPLTextdrawAll[i][1], -1);
			TextDrawSetOutline(InfoBoxPLTextdrawAll[i][1], 1);
			TextDrawSetProportional(InfoBoxPLTextdrawAll[i][1], 1);			
			
			TextDrawShowForPlayer(i,InfoBoxPLTextdrawAll[i][0]);
			TextDrawShowForPlayer(i,InfoBoxPLTextdrawAll[i][1]);
			InfoTextStateAll[i]=true;
			InfoBoxTimerAll[i]=SetTimer("InfoBoxHideAll",time,0);
		}
	}
}

stock InfoText(playerid,overview[50],text[200],time)
{
	if(!InfoTextState[playerid] && !InfoTextStateAll[playerid])
	{
		KillTimer(InfoBoxTimer[playerid]);
		TextDrawShowForPlayer(playerid,InfoBoxTextdraw[0]);
		TextDrawShowForPlayer(playerid,InfoBoxTextdraw[1]);

		InfoBoxPLTextdraw[playerid][0] = TextDrawCreate(509.000000, 350.000000, overview);
		TextDrawBackgroundColor(InfoBoxPLTextdraw[playerid][0], 255);
		TextDrawFont(InfoBoxPLTextdraw[playerid][0], 2);
		TextDrawLetterSize(InfoBoxPLTextdraw[playerid][0], 0.300000, 1.299998);
		TextDrawColor(InfoBoxPLTextdraw[playerid][0], -65281);
		TextDrawSetOutline(InfoBoxPLTextdraw[playerid][0], 1);
		TextDrawSetProportional(InfoBoxPLTextdraw[playerid][0], 1);
			
		InfoBoxPLTextdraw[playerid][1] = TextDrawCreate(487.000000, 369.000000, text);
		TextDrawBackgroundColor(InfoBoxPLTextdraw[playerid][1], 255);
		TextDrawFont(InfoBoxPLTextdraw[playerid][1], 1);
		TextDrawLetterSize(InfoBoxPLTextdraw[playerid][1], 0.259999, 0.899999);
		TextDrawColor(InfoBoxPLTextdraw[playerid][1], -1);
		TextDrawSetOutline(InfoBoxPLTextdraw[playerid][1], 1);
		TextDrawSetProportional(InfoBoxPLTextdraw[playerid][1], 1);				
						
	 	TextDrawShowForPlayer(playerid,InfoBoxPLTextdraw[playerid][0]);
	 	TextDrawShowForPlayer(playerid,InfoBoxPLTextdraw[playerid][1]);
	 	InfoTextState[playerid]=true;
		InfoBoxTimer[playerid]=SetTimerEx("InfoBoxHide",time,0,"u",playerid);
	}
}

public InfoBoxHide(playerid)
{
	if(!InfoTextState[playerid]) return 1;
	TextDrawHideForPlayer(playerid,InfoBoxTextdraw[0]);
	TextDrawHideForPlayer(playerid,InfoBoxTextdraw[1]);
	TextDrawHideForPlayer(playerid,InfoBoxPLTextdraw[playerid][0]);
 	TextDrawHideForPlayer(playerid,InfoBoxPLTextdraw[playerid][1]);
 	TextDrawDestroy(InfoBoxPLTextdraw[playerid][0]);
 	TextDrawDestroy(InfoBoxPLTextdraw[playerid][1]);
 	InfoTextState[playerid]=false; 
	KillTimer(InfoBoxTimer[playerid]);
 	return 1;
}

public InfoBoxHideAll()
{
	for(new i=0; i<MAX_PLAYERS; i++)
	{
		TextDrawHideForPlayer(i,InfoBoxTextdraw[0]);
		TextDrawHideForPlayer(i,InfoBoxTextdraw[1]);
		TextDrawHideForPlayer(i,InfoBoxPLTextdrawAll[i][0]);
		TextDrawHideForPlayer(i,InfoBoxPLTextdrawAll[i][1]);
		TextDrawDestroy(InfoBoxPLTextdrawAll[i][0]);
		TextDrawDestroy(InfoBoxPLTextdrawAll[i][1]);
		InfoTextStateAll[i]=false; 
		KillTimer(InfoBoxTimerAll[i]);
	}
	return 1;
}