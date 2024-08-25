CMD:help(playerid, params[])
{
	new help[2000];
	strcat(help,""COL_GREEN"ENTER "COL_EASY"- Retry."COL_BLUE"\n");
	strcat(help,""COL_GREEN"LMB "COL_EASY"- Use weapon."COL_BLUE"\n");
	strcat(help,""COL_GREEN"SPACE "COL_EASY"- Disable nitro."COL_BLUE"\n");
	strcat(help,""COL_BLUE"/rules "COL_EASY"- Server rules.\n");
	strcat(help,""COL_YELLOW"/vip "COL_EASY"- Show VIP features.\n");
	strcat(help,""COL_BLUE"/like "COL_EASY"- Like the map.\n");
	strcat(help,""COL_BLUE"/dislike "COL_EASY"- Dislike map.\n");
	strcat(help,""COL_BLUE"/set "COL_EASY"- Change account settings.\n");
	strcat(help,""COL_BLUE"/stats "COL_EASY"- Show account stats.\n");
	strcat(help,""COL_BLUE"/top "COL_EASY"- Show top 10.\n");
	strcat(help,""COL_BLUE"/flip "COL_EASY"- Flip the vehicle."COL_YELLOW"[Only VIP]\n");
	strcat(help,""COL_BLUE"/vips "COL_EASY"- Show all online VIP players.\n");
	strcat(help,""COL_BLUE"/report "COL_EASY"- The report on another player. "COL_RED"[Send reports even if the administration is offline.]\n");
	strcat(help,""COL_BLUE"/w "COL_WHITE"|"COL_BLUE" /pm "COL_WHITE"or"COL_BLUE"/re "COL_EASY"- Private message.\n");
	strcat(help,""COL_BLUE"/clear "COL_EASY"- Clear chat.\n");
	strcat(help,""COL_BLUE"/stream "COL_EASY"- Stop/Start audio stream.\n");
	strcat(help,""COL_BLUE"/sfix "COL_EASY"- Fix engine sound.\n");
	strcat(help,""COL_BLUE"/audiomsg "COL_EASY"- Enables/Disables the message that prints when a url is streamed to a client.\n");
	strcat(help,""COL_BLUE"/authors "COL_EASY"- The authors of the server.\n");
	ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Help Center - "COL_GREEN"Master Race", help, "Close", "");
	return 1;
}

CMD:pomoc(playerid, params[])
{
	new help[2000];
	strcat(help,""COL_GREEN"ENTER "COL_EASY"- Spróbuj ponownie."COL_BLUE"\n");
	strcat(help,""COL_GREEN"LMB "COL_EASY"- Użyj broni."COL_BLUE"\n");
	strcat(help,""COL_GREEN"SPACE "COL_EASY"- Wyłącz nitro."COL_BLUE"\n");
	strcat(help,""COL_BLUE"/rules "COL_EASY"- Regulamin serwera.\n");
	strcat(help,""COL_YELLOW"/vip "COL_EASY"- Funkcjonalności konta VIP.\n");
	strcat(help,""COL_BLUE"/like "COL_EASY"- Polub mapę.\n");
	strcat(help,""COL_BLUE"/dislike "COL_EASY"- Znienawidź mapę.\n");
	strcat(help,""COL_BLUE"/set "COL_EASY"- Ustawienia konta.\n");
	strcat(help,""COL_BLUE"/stats "COL_EASY"- Statystyki.\n");
	strcat(help,""COL_BLUE"/top "COL_EASY"- Wyświetl top 10 najlepszych graczy.\n");
	strcat(help,""COL_BLUE"/flip "COL_EASY"- Postaw pojazd na koła."COL_YELLOW"[Tylko VIP]\n");
	strcat(help,""COL_BLUE"/vips "COL_EASY"- Lista vip'ów online.\n");
	strcat(help,""COL_BLUE"/report "COL_EASY"- Reportowanie gracza. "COL_RED"[Wysyłaj reporty nawet jeśli nie ma adminów online.]\n");
	strcat(help,""COL_BLUE"/w "COL_WHITE"|"COL_BLUE" /pm "COL_WHITE"or"COL_BLUE"/re "COL_EASY"- Prywatna wiadomość.\n");
	strcat(help,""COL_BLUE"/czysc "COL_EASY"- Czyścisz sobie czat.\n");
	strcat(help,""COL_BLUE"/stream "COL_EASY"- Włącz/Wyłącz muzykę.\n");
	strcat(help,""COL_BLUE"/sfix "COL_EASY"- Naprawia dźwięk pojazdu jeśli się zbugował.\n");
	strcat(help,""COL_BLUE"/audiomsg "COL_EASY"- Włącza/Wyłącza informacje na czacie o streamowanym URL.\n");
	strcat(help,""COL_BLUE"/autorzy "COL_EASY"- Autorzy serwera.\n");
	ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Centrum pomocy - "COL_GREEN"Master Race", help, "Zamknij", "");
	return 1;
}

CMD:rules(playerid, params[])
{
	new content[2000];
	if(polak(playerid))
	{
		strcat(content,""COL_RED"1."COL_BLUE" Zakaz cheatowania."COL_ORANGE"[Kara: perm ban] \n");
		strcat(content,""COL_RED"2."COL_BLUE" Zakaz używania modów, które ułatwiają grę."COL_ORANGE"[Kara: perm ban]\n");
		strcat(content,""COL_RED"3."COL_BLUE" Zakaz wykorzystywania bugów."COL_ORANGE"[Kara: temp/perm ban]\n");
		strcat(content,""COL_RED"4."COL_BLUE" Zakaz spamu/floodowania/caps-lock/reklamowania."COL_ORANGE"[Kara: perm ban/uciszenie]\n");
		strcat(content,""COL_RED"5."COL_BLUE" Zakaz obrażania się. "COL_ORANGE"[Kara: czas/perm ban, uciszenie]\n");
		strcat(content,""COL_RED"6."COL_BLUE" Reportuj graczy łamiących regulamin nawet jeśli nie ma adminów online.\n");
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Regulamin - "COL_GREEN"Master Race", content, "Close", "");
	}
	else
	{
		strcat(content,""COL_RED"1."COL_BLUE" No cheating, hack."COL_ORANGE"[Penalty: perm ban] \n");
		strcat(content,""COL_RED"2."COL_BLUE" No mods that give you a handicap over other users."COL_ORANGE"[Penalty: perm ban]\n");
		strcat(content,""COL_RED"3."COL_BLUE" No bug using."COL_ORANGE"[Penalty: temp/perm ban]\n");
		strcat(content,""COL_RED"4."COL_BLUE" No spamming/flood text/caps-lock areas and advertising."COL_ORANGE"[Penalty: perm ban/mute]\n");
		strcat(content,""COL_RED"5."COL_BLUE" No insulting other players. Racism and other vulgar remarks will not be tolerated!"COL_ORANGE"[Penalty: temp/perm ban, mute]\n");
		strcat(content,""COL_RED"6."COL_BLUE" Report cheaters even if there are no admins.\n");
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Rules - "COL_GREEN"Master Race", content, "Close", "");
	}
	return 1;
}

CMD:vip(playerid, params[])
{
	new content[1000];
	if(polak(playerid))
	{
		strcat(content,""COL_RED"1."COL_BLUE" Jesteś na liście VIP'ów "COL_GREEN"/vips"COL_BLUE"\n");
		strcat(content,""COL_RED"2."COL_GREEN" Tag VIP "COL_BLUE"przed nickiem na czacie.\n");
		strcat(content,""COL_RED"3."COL_BLUE" Dostępna komenda "COL_GREEN"/flip"COL_BLUE"\n");
		strcat(content,""COL_RED"4."COL_BLUE" Premia "COL_GREEN"+2 score"COL_BLUE" po zakończeniu wyścigu.\n");
		strcat(content,""COL_WHITE"Chcesz zakupić vip? Skontaktuj się z:"COL_RED"czerwony03"COL_WHITE" lub "COL_RED"sebaqq6\n");
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Funkcje VIP - "COL_GREEN"Master Race", content, "Close", "");
	}
	else
	{
		strcat(content,""COL_RED"1."COL_BLUE" Display on "COL_GREEN"/vips"COL_BLUE" list.\n");
		strcat(content,""COL_RED"2."COL_GREEN" VIP tag "COL_BLUE"before nick on chat.\n");
		strcat(content,""COL_RED"3."COL_BLUE" Can use "COL_GREEN"/flip"COL_BLUE" command.\n");
		strcat(content,""COL_RED"4."COL_BLUE" Bonus of "COL_GREEN"+2 score"COL_BLUE" after finishing the race.\n");
		strcat(content,"Want to buy VIP? Contact server administrator!"COL_RED" (VIP cost: $1 per week)\n");
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" VIP features - "COL_GREEN"Master Race", content, "Close", "");	
	}
	
	return 1;
}


CMD:like(playerid, params[])
{
	if(polak(playerid))
	{
		if(!serwer[wyscig]) return Error(playerid, "Wyścig jeszcze nie wystartował.");
		if(tgracz[playerid][ld_used]) return Error(playerid, "Już oceniłeś tą mapę.");
	}
	else
	{
		if(!serwer[wyscig]) return Error(playerid, "The race did not start.");
		if(tgracz[playerid][ld_used]) return Error(playerid, "Already you spent its opinion on the map.");
	}
	tgracz[playerid][ld_used] = true;
	mq_format("INSERT INTO `map_like_history` (`mid`, `uid`, `like`) VALUES ('%d', '%d', '1');", ActualMapID(), sgracz[playerid][uID]);
	mq_send("QUERY");
	mq_format("UPDATE `map_lista` SET `like`=`like`+'1' WHERE `id`='%d';", ActualMapID());
	mq_send("QUERY");
	MapInfo[like]++;
	SendClientMessageToAllEN(-1, ""COL_GREY"|LIKE|"COL_WHITE" The player "COL_BLUE"%s"COL_GREEN" /like"COL_WHITE" this map.", nick(playerid));
	SendClientMessageToAllPL(-1, ""COL_GREY"|LIKE|"COL_WHITE" Gracz "COL_BLUE"%s"COL_GREEN" lubi(/like)"COL_WHITE" tą mapę.", nick(playerid));
	return 1;
}

CMD:dislike(playerid, params[])
{
	if(polak(playerid))
	{
		if(!serwer[wyscig]) return Error(playerid, "Wyścig jeszcze nie wystartował.");
		if(tgracz[playerid][ld_used]) return Error(playerid, "Już oceniłeś tą mapę.");
	}
	else
	{
		if(!serwer[wyscig]) return Error(playerid, "The race did not start.");
		if(tgracz[playerid][ld_used]) return Error(playerid, "Already you spent its opinion on the map.");
	}
	tgracz[playerid][ld_used] = true;
	mq_format("INSERT INTO `map_like_history` (`mid`, `uid`, `like`) VALUES ('%d', '%d', '0');", ActualMapID(), sgracz[playerid][uID]);
	mq_send("QUERY");
	mq_format("UPDATE `map_lista` SET `dislike`=`dislike`+'1' WHERE `id`='%d';", ActualMapID());
	mq_send("QUERY");
	MapInfo[dislike]++;
	SendClientMessageToAllEN(-1, ""COL_GREY"|DISLIKE|"COL_WHITE" The player "COL_BLUE"%s"COL_RED" /dislike"COL_WHITE" this map.", nick(playerid));
	SendClientMessageToAllPL(-1, ""COL_GREY"|DISLIKE|"COL_WHITE" Gracz "COL_BLUE"%s"COL_RED" nie lubi (/dislike)"COL_WHITE" tej mapy.", nick(playerid));
	return 1;
}

CMD:set(playerid, params[])
{
	const contstr = 1024;
	new title[128], content[contstr];
	if(polak(playerid))
	{
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Ustawienia konta", nick(playerid), sgracz[playerid][uID]);
		format(content, contstr, "Opcja\t"COL_YELLOW"Cena\n");
		format(content, contstr, "%s"COL_GREY"Zmień nick\t"COL_YELLOW"[10 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Zmień hasło\t"COL_GREEN"[darmowe]\n", content);
		format(content, contstr, "%s"COL_GREY"Zmień kolor nicku\t"COL_YELLOW"[30 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Zmień kolor pierwszy pojazdu\t"COL_YELLOW"[35 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Zmień kolor drugi pojazdu\t"COL_YELLOW"[35 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Zmień felgi\t"COL_ORANGE"[różna]\n", content);
		format(content, contstr, "%s"COL_GREY"Zmień kolor neonów\t"COL_YELLOW"[40 score]\n", content);
		Dialog_Show(playerid, SETTING, DIALOG_STYLE_TABLIST_HEADERS, title, content, "Wybierz", "Anuluj");
	}
	else
	{
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Account settings", nick(playerid), sgracz[playerid][uID]);
		format(content, contstr, "Option\t"COL_YELLOW"Cost\n");
		format(content, contstr, "%s"COL_GREY"Change nickname\t"COL_YELLOW"[10 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Change password\t"COL_GREEN"[free]\n", content);
		format(content, contstr, "%s"COL_GREY"Change nick color\t"COL_YELLOW"[30 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Change first vehicle color\t"COL_YELLOW"[35 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Change second vehicle color\t"COL_YELLOW"[35 score]\n", content);
		format(content, contstr, "%s"COL_GREY"Change wheels\t"COL_ORANGE"[differently]\n", content);
		format(content, contstr, "%s"COL_GREY"Change neon color\t"COL_YELLOW"[40 score]\n", content);
		Dialog_Show(playerid, SETTING, DIALOG_STYLE_TABLIST_HEADERS, title, content, "Select", "Cancel");
	}
	return 1;
}

Dialog:SETTING(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		const contstr = 4096;
		switch(listitem)
		{
			case 0:
			{
				if(polak(playerid)) Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana nicku", "Wpisz "COL_GREEN"nowy"COL_WHITE" nick.\n"COL_RED"Zmiana nicku kosztuje 10 score.", "Zmien", "Anuluj");
				else Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Change nickname", "Please type your "COL_GREEN"new"COL_WHITE" nickname.\n"COL_RED"Changing nickname costs 10 score.", "Change", "Cancel");
			}
			case 1:
			{
				if(polak(playerid)) Dialog_Show(playerid, CHANGEPW, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana hasła", "Wprowadź "COL_GREEN"nowe"COL_WHITE" hasło.", "Zmien", "Anuluj");
				else Dialog_Show(playerid, CHANGEPW, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Password change", "Please type your "COL_GREEN"new"COL_WHITE" password.", "Change", "Cancel");
			}
			case 2:
			{
				new title[128], content[contstr];
				if(polak(playerid))
				{
					if(GetPlayerScore(playerid) < 30) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zmienić "COL_GREEN"kolor nicku"COL_WHITE".");
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Zmiana koloru nicku", nick(playerid), sgracz[playerid][uID]);
					for(new i; i < sizeof(PlayerColors); i++)
					{
						format(content, contstr, "%s%d.\t{%06x}%s\n", content, i, PlayerColors[i] >>> 8, nick(playerid));
					}
					Dialog_Show(playerid, COLORSET, DIALOG_STYLE_TABLIST, title, content, "Zmien", "Anuluj");
				}
				else
				{
					if(GetPlayerScore(playerid) < 30) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to change "COL_GREEN"color nickname"COL_WHITE".");
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Change nick color", nick(playerid), sgracz[playerid][uID]);
					for(new i; i < sizeof(PlayerColors); i++)
					{
						format(content, contstr, "%s%d.\t{%06x}%s\n", content, i, PlayerColors[i] >>> 8, nick(playerid));
					}
					Dialog_Show(playerid, COLORSET, DIALOG_STYLE_TABLIST, title, content, "Change", "Cancel");
				}
			}
			case 3:
			{
				if(polak(playerid))
				{
					if(GetPlayerScore(playerid) < 35) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zmienić "COL_GREEN"pierwszy kolor pojazdu"COL_WHITE".");
					new title[128], content[contstr];
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Zmiana pierwszego koloru pojazdu", nick(playerid), sgracz[playerid][uID]);
					for(new i; i < 230; i++)
					{
						format(content, contstr, "%s%d.\t{%06x}KOL\n", content, i, VehicleColoursTableRGBA[i] >>> 8);
					}
					Dialog_Show(playerid, FCOLORVEH, DIALOG_STYLE_TABLIST, title, content, "Zmien", "Anuluj");
				}
				else
				{
					if(GetPlayerScore(playerid) < 35) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to change "COL_GREEN"first vehicle color"COL_WHITE".");
					new title[128], content[contstr];
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Change first vehicle color", nick(playerid), sgracz[playerid][uID]);
					for(new i; i < 230; i++)
					{
						format(content, contstr, "%s%d.\t{%06x}COL\n", content, i, VehicleColoursTableRGBA[i] >>> 8);
					}
					Dialog_Show(playerid, FCOLORVEH, DIALOG_STYLE_TABLIST, title, content, "Change", "Cancel");
				}

			}
			case 4:
			{
				if(polak(playerid))
				{
					if(GetPlayerScore(playerid) < 35) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zmienić "COL_GREEN"drugi kolor pojazdu"COL_WHITE".");
					new title[128], content[contstr];
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Zmiana drugiego koloru pojazdu", nick(playerid), sgracz[playerid][uID]);
					for(new i; i < 230; i++)
					{
						format(content, contstr, "%s%d.\t{%06x}KOL\n", content, i, VehicleColoursTableRGBA[i] >>> 8);
					}
					Dialog_Show(playerid, SCOLORVEH, DIALOG_STYLE_TABLIST, title, content, "Zmien", "Anuluj");
				}
				else
				{
					if(GetPlayerScore(playerid) < 35) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to change "COL_GREEN"second vehicle color"COL_WHITE".");
					new title[128], content[contstr];
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Change second vehicle color", nick(playerid), sgracz[playerid][uID]);
					for(new i; i < 230; i++)
					{
						format(content, contstr, "%s%d.\t{%06x}COL\n", content, i, VehicleColoursTableRGBA[i] >>> 8);
					}
					Dialog_Show(playerid, SCOLORVEH, DIALOG_STYLE_TABLIST, title, content, "Change", "Cancel");
				}

			}
			case 5:
			{
				new title[128], content[contstr];
				if(polak(playerid))
				{
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Zmiana felg", nick(playerid), sgracz[playerid][uID]);
					format(content, contstr, "Typ felg\t"COL_YELLOW"Koszt\n");
					format(content, contstr, "%s"COL_GREY"Shadow\t"COL_YELLOW"[15 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Offroad\t"COL_YELLOW"[15 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Mega\t"COL_YELLOW"[16 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Rimshine\t"COL_YELLOW"[16 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Wires\t"COL_YELLOW"[17 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Cutter\t"COL_YELLOW"[17 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Import\t"COL_YELLOW"[18 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Classic\t"COL_YELLOW"[19 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Grove\t"COL_YELLOW"[19 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Atomic\t"COL_YELLOW"[22 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Twist\t"COL_YELLOW"[23 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Trance\t"COL_YELLOW"[26 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Dollar\t"COL_YELLOW"[27 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Switch\t"COL_YELLOW"[30 score]\n", content);
					Dialog_Show(playerid, WHEELS, DIALOG_STYLE_TABLIST_HEADERS, title, content, "Zmien", "Anuluj");
				}
				else
				{
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Change wheels", nick(playerid), sgracz[playerid][uID]);
					format(content, contstr, "Wheel type\t"COL_YELLOW"Cost\n");
					format(content, contstr, "%s"COL_GREY"Shadow\t"COL_YELLOW"[15 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Offroad\t"COL_YELLOW"[15 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Mega\t"COL_YELLOW"[16 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Rimshine\t"COL_YELLOW"[16 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Wires\t"COL_YELLOW"[17 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Cutter\t"COL_YELLOW"[17 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Import\t"COL_YELLOW"[18 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Classic\t"COL_YELLOW"[19 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Grove\t"COL_YELLOW"[19 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Atomic\t"COL_YELLOW"[22 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Twist\t"COL_YELLOW"[23 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Trance\t"COL_YELLOW"[26 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Dollar\t"COL_YELLOW"[27 score]\n", content);
					format(content, contstr, "%s"COL_GREY"Switch\t"COL_YELLOW"[30 score]\n", content);
					Dialog_Show(playerid, WHEELS, DIALOG_STYLE_TABLIST_HEADERS, title, content, "Change", "Cancel");
				}
			}
			case 6:
			{
				new title[128], content[contstr];
				if(polak(playerid))
				{
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Zmiana koloru neonów", nick(playerid), sgracz[playerid][uID]);
					format(content, contstr, "%s"COL_WHITE"Biały\t"COL_ORANGE"[zmień]\n", content);
					format(content, contstr, "%s"COL_YELLOW"Yellow\t"COL_ORANGE"[zmień]\n", content);
					format(content, contstr, "%s{ED5BFF}Różowy\t"COL_ORANGE"[zmień]\n", content);
					format(content, contstr, "%s"COL_RED"Czerwony\t"COL_ORANGE"[zmień]\n", content);
					format(content, contstr, "%s"COL_GREEN"Zielony\t"COL_ORANGE"[zmień]\n", content);
					format(content, contstr, "%s"COL_DBLUE"Niebieski\t"COL_ORANGE"[zmień]\n", content);
					format(content, contstr, "%s"COL_RED"Usuń neon\t"COL_GREEN"[darmowe]\n", content);
					Dialog_Show(playerid, NEONSET, DIALOG_STYLE_TABLIST, title, content, "Zmien", "Anuluj");
				}
				else
				{
					format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Change neon color", nick(playerid), sgracz[playerid][uID]);
					format(content, contstr, "%s"COL_WHITE"White\t"COL_ORANGE"[change]\n", content);
					format(content, contstr, "%s"COL_YELLOW"Yellow\t"COL_ORANGE"[change]\n", content);
					format(content, contstr, "%s{ED5BFF}Pink\t"COL_ORANGE"[change]\n", content);
					format(content, contstr, "%s"COL_RED"Red\t"COL_ORANGE"[change]\n", content);
					format(content, contstr, "%s"COL_GREEN"Green\t"COL_ORANGE"[change]\n", content);
					format(content, contstr, "%s"COL_DBLUE"Blue\t"COL_ORANGE"[change]\n", content);
					format(content, contstr, "%s"COL_RED"Remove neon\t"COL_GREEN"[free]\n", content);
					Dialog_Show(playerid, NEONSET, DIALOG_STYLE_TABLIST, title, content, "Change", "Cancel");	
				}

			}
		}
	}
	return 1;
}

Dialog:NEONSET(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new cena;
		if(polak(playerid))
		{
			switch(listitem)
			{
				case 0:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"neony"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18652;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 1:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"neony"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18650;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 2:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"neony"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18651;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 3:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"neony"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18647;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 4:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"neony"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18649;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 5:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"neony"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18648;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 6:
				{
					cena = 0;
					sgracz[playerid][neoncolor] = 0;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, ""COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
			}
		}
		else
		{
			switch(listitem)
			{
				case 0:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"neons"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18652;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 1:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"neons"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18650;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 2:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"neons"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18651;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 3:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"neons"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18647;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 4:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"neons"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18649;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 5:
				{
					cena = 40;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"neons"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][neoncolor] = 18648;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Neon: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 6:
				{
					cena = 0;
					sgracz[playerid][neoncolor] = 0;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, ""COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
			}
		}
		mq_format("UPDATE `players` SET `neoncolor`='%d' WHERE `id`='%d';", sgracz[playerid][neoncolor], sgracz[playerid][uID]);
		mq_send("QUERY");
	}
	return 1;
}


Dialog:WHEELS(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new cena;
		if(polak(playerid))
		{
			switch(listitem)
			{
				case 0:
				{
					cena = 15;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1073;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 1:
				{
					cena = 15;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1025;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 2:
				{
					cena = 16;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1074;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 3:
				{
					cena = 16;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1075;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 4:
				{
					cena = 17;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1076;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 5:
				{
					cena = 17;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1079;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 6:
				{
					cena = 18;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1082;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 7:
				{
					cena = 19;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1077;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 8:
				{
					cena = 19;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1081;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 9:
				{
					cena = 22;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1085;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 10:
				{
					cena = 23;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1078;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 11:
				{
					cena = 26;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1084;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 12:
				{
					cena = 27;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1083;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
				case 13:
				{
					cena = 30;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE" aby zakupić te "COL_GREEN"felgi"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1080;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Felgi: "COL_BLUE"%s "COL_GREEN"zakupiono"COL_WHITE". "COL_ORANGE"(zabrano %d score)", inputtext, cena);
				}
			}
		}
		else
		{
			switch(listitem)
			{
				case 0:
				{
					cena = 15;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1073;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 1:
				{
					cena = 15;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1025;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 2:
				{
					cena = 16;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1074;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 3:
				{
					cena = 16;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1075;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 4:
				{
					cena = 17;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1076;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 5:
				{
					cena = 17;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1079;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 6:
				{
					cena = 18;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1082;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 7:
				{
					cena = 19;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1077;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 8:
				{
					cena = 19;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1081;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 9:
				{
					cena = 22;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1085;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 10:
				{
					cena = 23;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1078;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 11:
				{
					cena = 26;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1084;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 12:
				{
					cena = 27;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1083;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
				case 13:
				{
					cena = 30;
					if(GetPlayerScore(playerid) < cena) return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to purchase "COL_GREEN"wheels"COL_WHITE".");
					SetScore(playerid, GetPlayerScore(playerid) - cena);
					sgracz[playerid][wheeltype] = 1080;
					LoadVehMod(playerid, GetPlayerVehicleID(playerid));
					SendClientMessageEx(playerid, -1, "Wheels: "COL_BLUE"%s "COL_GREEN"purchased"COL_WHITE". "COL_ORANGE"(taken %d score)", inputtext, cena);
				}
			}
		}
		mq_format("UPDATE `players` SET `wheeltype`='%d' WHERE `id`='%d';", sgracz[playerid][wheeltype], sgracz[playerid][uID]);
		mq_send("QUERY");
	}
	return 1;
}

Dialog:FCOLORVEH(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(GetPlayerScore(playerid) < 35) 
		{
			if(polak(playerid)) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE", aby zmienić "COL_GREEN"pierwszy kolor pojazdu"COL_WHITE".");
			else return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to change "COL_GREEN"first vehicle color"COL_WHITE".");
		}
		SetScore(playerid, GetPlayerScore(playerid)-35);
		sgracz[playerid][vcolor1] = listitem;
		mq_format("UPDATE `players` SET `vcolor1`='%d' WHERE `id`='%d';", sgracz[playerid][vcolor1], sgracz[playerid][uID]);
		mq_send("QUERY");
		ChangeVehicleColor(GetPlayerVehicleID(playerid), sgracz[playerid][vcolor1], sgracz[playerid][vcolor2]);
		if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s {%06x}Pierwszy kolor pojazdu zmieniony! "COL_ORANGE"(zabrano 35 score)", form(), VehicleColoursTableRGBA[listitem] >>> 8);
		else SendClientMessageEx(playerid, -1, "%s {%06x}First vehicle color changed! "COL_ORANGE"(taken 35 score)", form(), VehicleColoursTableRGBA[listitem] >>> 8);
	}
	return 1;
}

Dialog:SCOLORVEH(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(GetPlayerScore(playerid) < 35) 
		{
			if(polak(playerid)) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE", aby zmienić "COL_GREEN"drugi kolor pojazdu"COL_WHITE".");
			else return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to change "COL_GREEN"second vehicle color"COL_WHITE".");
		}
		SetScore(playerid, GetPlayerScore(playerid)-35);
		sgracz[playerid][vcolor2] = listitem;
		mq_format("UPDATE `players` SET `vcolor2`='%d' WHERE `id`='%d';", sgracz[playerid][vcolor2], sgracz[playerid][uID]);
		mq_send("QUERY");
		ChangeVehicleColor(GetPlayerVehicleID(playerid), sgracz[playerid][vcolor1], sgracz[playerid][vcolor2]);
		if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s {%06x}Drugi kolor pojazdu zmieniony! "COL_ORANGE"(zabrano 35 score)", form(), VehicleColoursTableRGBA[listitem] >>> 8);
		else SendClientMessageEx(playerid, -1, "%s {%06x}Second vehicle color changed! "COL_ORANGE"(taken 35 score)", form(), VehicleColoursTableRGBA[listitem] >>> 8);
	}
	return 1;
}

Dialog:COLORSET(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(GetPlayerScore(playerid) < 30) 
		{
			if(polak(playerid)) return Error(playerid, "Nie masz wystarczająco "COL_RED"score"COL_WHITE", aby zmienić "COL_GREEN"kolor nicku"COL_WHITE".");
			else return Error(playerid, "You don't have enough "COL_RED"score"COL_WHITE" to change "COL_GREEN"color nickname"COL_WHITE".");
		}
		SetScore(playerid, GetPlayerScore(playerid)-30);
		SetPlayerColor(playerid, PlayerColors[listitem]);
		sgracz[playerid][pcolor] = GetPlayerColor(playerid);
		mq_format("UPDATE `players` SET `pcolor`='%d' WHERE `id`='%d';", sgracz[playerid][pcolor], sgracz[playerid][uID]);
		mq_send("QUERY");
		if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s {%06x}Kolor nicku zmieniony! "COL_ORANGE"(zabrano 30 score)", form(), sgracz[playerid][pcolor] >>> 8);
		else SendClientMessageEx(playerid, -1, "%s {%06x}Color changed! "COL_ORANGE"(taken 30 score)", form(), sgracz[playerid][pcolor] >>> 8);
	}
	return 1;
}

Dialog:CHANGEPW(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(strlen(inputtext) < 4)  
		{
			if(polak(playerid)) return Dialog_Show(playerid, CHANGEPW, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana hasła", "Wprowadź "COL_GREEN"nowe"COL_WHITE" hasło.\n"COL_RED"Hasło zbyt krótkie(min: 4 znaki)", "Zmien", "Anuluj");
			else return Dialog_Show(playerid, CHANGEPW, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Password change", "Please type your "COL_GREEN"new"COL_WHITE" password.\n"COL_RED"Password too short(min: 4 chars)", "Change", "Cancel");
		}
		if(strlen(inputtext) > 16)  
		{
			if(polak(playerid)) return Dialog_Show(playerid, CHANGEPW, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana hasła", "Wprowadź "COL_GREEN"nowe"COL_WHITE" hasło.\n"COL_RED"Hasło zbyt długie (max: 16 znaków)", "Zmien", "Anuluj");
			else return Dialog_Show(playerid, CHANGEPW, DIALOG_STYLE_PASSWORD, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Password change", "Please type your "COL_GREEN"new"COL_WHITE" password.\n"COL_RED"Password too long (max: 16 chars)", "Change", "Cancel");
		}
		new str[130];
		format(str, 130, "%s", MD5_Hash(inputtext));
		mq_format("UPDATE `players` SET `password`='%s' WHERE `id`='%d';", str, sgracz[playerid][uID]);
		mq_send("QUERY");
		if(polak(playerid)) 
		{
			format(str, 130, ""COL_WHITE"Nowe hasło: "COL_RED"%s", inputtext);
			ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Hasło zmienione!", str, "OK", "");
		}
		else
		{
			format(str, 130, ""COL_WHITE"New password: "COL_RED"%s\n"COL_GREEN"Remember?", inputtext);
			ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Password changed!", str, "Sure!", "");
		}
	}
	return 1;
}

Dialog:CHANGENICK(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(polak(playerid)) 
		{
			if(strlen(inputtext) < 4) return Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana nicku", "Wpisz "COL_GREEN"nowy"COL_WHITE" nick.\n"COL_RED"Zmiana nicku kosztuje 10 score.\n"COL_BLUE"Nick zbyt krótki (min: 4 znaki)", "Zmien", "Anuluj"); 
			if(strlen(inputtext) > 18) return Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana nicku", "Wpisz "COL_GREEN"nowy"COL_WHITE" nick.\n"COL_RED"Zmiana nicku kosztuje 10 score.\n"COL_BLUE"Nick zbyt długi (max: 18 znaki)", "Zmien", "Anuluj"); 
			if(GetPlayerScore(playerid) < 10) return SendClientMessageEx(playerid, -1, "%s Nie masz wystarczająco "COL_RED"score"COL_WHITE", aby zmienić "COL_GREEN"nick"COL_WHITE".", form());
		}
		else 
		{
			if(strlen(inputtext) < 4) return Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Change nickname", "Please type your "COL_GREEN"new"COL_WHITE" nickname.\n"COL_RED"Changing nickname costs 10 score.\n"COL_BLUE"Nickname too short(min: 4 chars)", "Change", "Cancel"); 
			if(strlen(inputtext) > 18) return Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Change nickname", "Please type your "COL_GREEN"new"COL_WHITE" nickname.\n"COL_RED"Changing nickname costs 10 score.\n"COL_BLUE"Nickname too long(max: 18 chars)", "Change", "Cancel"); 
			if(GetPlayerScore(playerid) < 10) return SendClientMessageEx(playerid, -1, "%s You don't have enough "COL_RED"score"COL_WHITE" to change "COL_GREEN"nickname"COL_WHITE".", form());
		}
		//sprawdzanie czy taki nick jest w db
		new query[256];
		mysql_escape_string(inputtext, inputtext, MySQL, 24);
		mysql_format(MySQL, query, 256,"SELECT * FROM `players` WHERE `name`='%s';", inputtext);
		new Cache:checkexist = mysql_query(MySQL,query);
		new rows = cache_get_row_count();
		cache_delete(checkexist, MySQL);
		if(rows) 
		{
			if(polak(playerid)) return Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana nicku", "Wpisz "COL_GREEN"nowy"COL_WHITE" nick.\n"COL_RED"Zmiana nicku kosztuje 10 score.\n"COL_BLUE"Ten nick jest już zarejestrowany!", "Zmien", "Anuluj"); 
			else return Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Change nickname", "Please type your "COL_GREEN"new"COL_WHITE" nickname.\n"COL_RED"Changing nickname costs 10 score.\n"COL_BLUE"This nickname is already registered!", "Change", "Cancel");
		}
		//end sprawdzanie
		new oldnick[24];
		GetPlayerName(playerid, oldnick, 24);
		if(SetPlayerName(playerid, inputtext))
		{
			SetScore(playerid, GetPlayerScore(playerid) - 10);
			mq_format("UPDATE `players` SET `name`='%s' WHERE `id`='%d';", nick(playerid, true), sgracz[playerid][uID]);
			mq_send("QUERY");
			new str[256];
			if(polak(playerid)) 
			{
				format(str, 256, ""COL_WHITE"Nowy nick: "COL_RED"%s\n"COL_BLUE"Pamiętaj aby zmienić nick przed wejściem na serwer w cliencie samp'a!\n"COL_ORANGE"(zabrano 10 score)", nick(playerid, true));
				ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Nick zmieniony!", str, "Zamknij", "");
				SendClientMessageToAllEx(-1, "%s "COL_BLUE"%s"COL_WHITE" jest teraz znany jako "COL_BLUE"%s"COL_WHITE".", form(), oldnick, nick(playerid));
			}
			else
			{
				format(str, 256, ""COL_WHITE"New nickname: "COL_RED"%s\n"COL_BLUE"You need change too in client samp before next connection to server.\n"COL_GREEN"Remember?\n"COL_ORANGE"(taken 10 score)", nick(playerid, true));
				ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Nickname changed!", str, "Sure!", "");
				SendClientMessageToAllEx(-1, "%s The "COL_BLUE"%s"COL_WHITE" is known as "COL_BLUE"%s"COL_WHITE".", form(), oldnick, nick(playerid));
			}
		}
		else
		{
			if(polak(playerid)) Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Zmiana nicku", "Wpisz "COL_GREEN"nowy"COL_WHITE" nick.\n"COL_RED"Zmiana nicku kosztuje 10 score.\n"COL_BLUE"Nowy nick jest niepoprawny!", "Zmien", "Anuluj"); 
			else Dialog_Show(playerid, CHANGENICK, DIALOG_STYLE_INPUT, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Change nickname", "Please type your "COL_GREEN"new"COL_WHITE" nickname.\n"COL_RED"Changing nickname costs 10 score.\n"COL_BLUE"This nickname is invalid!", "Change", "Cancel");
		}
	}
	return 1;
}

CMD:stats(playerid, params[])
{
	if(polak(playerid))
	{
		const contstr = 1024;
		new title[128], content[contstr];
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Statystyki gracza", nick(playerid), sgracz[playerid][uID]);
		format(content, contstr, ""COL_GREY"Nick:\t"COL_BLUE"%s\n", nick(playerid));
		format(content, contstr, "%s"COL_GREY"Użytkownik ID[UID]:\t"COL_BLUE"%d\n", content, sgracz[playerid][uID]);
		format(content, contstr, "%s"COL_GREY"IP:\t"COL_BLUE"%s\n", content, playerip(playerid));
		format(content, contstr, "%s"COL_GREY"Kraj:\t"COL_BLUE"%s\n", content, country(playerid));
		format(content, contstr, "%s"COL_GREY"Skin:\t"COL_BLUE"%d\n", content, sgracz[playerid][skin]);
		format(content, contstr, "%s"COL_GREY"Maxymalna prędkość:\t"COL_BLUE"%d km/h\n", content, sgracz[playerid][maxkmh]);
		format(content, contstr, "%s"COL_GREY"Score:\t"COL_BLUE"%d\n", content, GetPlayerScore(playerid));
		new day_s, hour_s, minute_s, sec_s;
		SecToTime(sgracz[playerid][TimeOnline], day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Czas online:\t"COL_BLUE"%d days, %d hours, %d minutes, %d seconds\n", content, day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Wszystkich wyścigów:\t"COL_BLUE"%d\n", content, sgracz[playerid][udzial]);
		format(content, contstr, "%s"COL_GREY"Wygrane wyścigi:\t"COL_BLUE"%d\n", content, sgracz[playerid][wygrane]);
		format(content, contstr, "%s"COL_GREY"Ukończone wyścigi:\t"COL_BLUE"%d\n", content, sgracz[playerid][ukonczone]);
		format(content, contstr, "%s"COL_GREY"Zebrane CheckPointy:\t"COL_BLUE"%d\n", content, sgracz[playerid][zebranecp]);
		if(vip(playerid))
		{
			SecToTime(sgracz[playerid][vip_stamp] - gettime(), day_s, hour_s, minute_s, sec_s);
			format(content, contstr, "%s"COL_YELLOW"Konto VIP wygasa za:\t"COL_GREEN"%d dni, %d godzin, %d minut, %d sekund\n", content, day_s, hour_s, minute_s, sec_s);
		}
		else
		{
			format(content, contstr, "%s"COL_YELLOW"VIP:\t"COL_RED"/vip\n", content);
		}
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_TABLIST, title, content, "Zamknij", "");
	}
	else
	{
		const contstr = 1024;
		new title[128], content[contstr];
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Player statistics", nick(playerid), sgracz[playerid][uID]);
		format(content, contstr, ""COL_GREY"Nick:\t"COL_BLUE"%s\n", nick(playerid));
		format(content, contstr, "%s"COL_GREY"User ID[UID]:\t"COL_BLUE"%d\n", content, sgracz[playerid][uID]);
		format(content, contstr, "%s"COL_GREY"IP:\t"COL_BLUE"%s\n", content, playerip(playerid));
		format(content, contstr, "%s"COL_GREY"Country:\t"COL_BLUE"%s\n", content, country(playerid));
		format(content, contstr, "%s"COL_GREY"Skin:\t"COL_BLUE"%d\n", content, sgracz[playerid][skin]);
		format(content, contstr, "%s"COL_GREY"Max speed:\t"COL_BLUE"%d km/h\n", content, sgracz[playerid][maxkmh]);
		format(content, contstr, "%s"COL_GREY"Score:\t"COL_BLUE"%d\n", content, GetPlayerScore(playerid));
		new day_s, hour_s, minute_s, sec_s;
		SecToTime(sgracz[playerid][TimeOnline], day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Time online:\t"COL_BLUE"%d days, %d hours, %d minutes, %d seconds\n", content, day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Total races:\t"COL_BLUE"%d\n", content, sgracz[playerid][udzial]);
		format(content, contstr, "%s"COL_GREY"Wins:\t"COL_BLUE"%d\n", content, sgracz[playerid][wygrane]);
		format(content, contstr, "%s"COL_GREY"Completed races:\t"COL_BLUE"%d\n", content, sgracz[playerid][ukonczone]);
		format(content, contstr, "%s"COL_GREY"Collected CP:\t"COL_BLUE"%d\n", content, sgracz[playerid][zebranecp]);
		if(vip(playerid))
		{
			SecToTime(sgracz[playerid][vip_stamp] - gettime(), day_s, hour_s, minute_s, sec_s);
			format(content, contstr, "%s"COL_YELLOW"VIP time left:\t"COL_GREEN"%d days, %d hours, %d minutes, %d seconds\n", content, day_s, hour_s, minute_s, sec_s);
		}
		else
		{
			format(content, contstr, "%s"COL_YELLOW"VIP:\t"COL_RED"/vip\n", content);
		}
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_TABLIST, title, content, "Close", "");
	}
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	const contstr = 1024;
	new title[128], content[contstr];
	if(polak(playerid))
	{
		if(!login(clickedplayerid)) return Error(playerid, "Ten gracz nie jest zalogowany.");
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Statystyki gracza", nick(clickedplayerid), sgracz[clickedplayerid][uID]);
		format(content, contstr, ""COL_GREY"Nick:\t"COL_BLUE"%s\n", nick(clickedplayerid));
		format(content, contstr, "%s"COL_GREY"Kraj:\t"COL_BLUE"%s\n", content, country(clickedplayerid));
		format(content, contstr, "%s"COL_GREY"Skin:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][skin]);
		format(content, contstr, "%s"COL_GREY"Maxymalna prędkość:\t"COL_BLUE"%d km/h\n", content, sgracz[clickedplayerid][maxkmh]);
		format(content, contstr, "%s"COL_GREY"Score:\t"COL_BLUE"%d\n", content, GetPlayerScore(clickedplayerid));
		new day_s, hour_s, minute_s, sec_s;
		SecToTime(sgracz[clickedplayerid][TimeOnline], day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Czas online:\t"COL_BLUE"%d dni, %d godzin, %d minut, %d sekund\n", content, day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Wyścigów:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][udzial]);
		format(content, contstr, "%s"COL_GREY"Wygranych wyścigów:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][wygrane]);
		format(content, contstr, "%s"COL_GREY"Ukończonych wyścigów:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][ukonczone]);
		format(content, contstr, "%s"COL_GREY"Zebranych CheckPointów:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][zebranecp]);
		if(vip(clickedplayerid)) format(content, contstr, "%s"COL_YELLOW"VIP:\t"COL_GREEN"TAK\n", content);
		else format(content, contstr, "%s"COL_YELLOW"VIP:\t"COL_RED"NIE\n", content);
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_TABLIST, title, content, "Zamknij", "");	
	}
	else
	{
		if(!login(clickedplayerid)) return Error(playerid, "This player is not logged in.");
		format(title, 128, ""COL_RED"»"COL_GREEN"»"COL_WHITE" %s[UID: %d] - "COL_YELLOW"Player statistics", nick(clickedplayerid), sgracz[clickedplayerid][uID]);
		format(content, contstr, ""COL_GREY"Nick:\t"COL_BLUE"%s\n", nick(clickedplayerid));
		format(content, contstr, "%s"COL_GREY"Country:\t"COL_BLUE"%s\n", content, country(clickedplayerid));
		format(content, contstr, "%s"COL_GREY"Skin:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][skin]);
		format(content, contstr, "%s"COL_GREY"Max speed:\t"COL_BLUE"%d km/h\n", content, sgracz[clickedplayerid][maxkmh]);
		format(content, contstr, "%s"COL_GREY"Score:\t"COL_BLUE"%d\n", content, GetPlayerScore(clickedplayerid));
		new day_s, hour_s, minute_s, sec_s;
		SecToTime(sgracz[clickedplayerid][TimeOnline], day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Time online:\t"COL_BLUE"%d days, %d hours, %d minutes, %d seconds\n", content, day_s, hour_s, minute_s, sec_s);
		format(content, contstr, "%s"COL_GREY"Total races:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][udzial]);
		format(content, contstr, "%s"COL_GREY"Wins:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][wygrane]);
		format(content, contstr, "%s"COL_GREY"Completed races:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][ukonczone]);
		format(content, contstr, "%s"COL_GREY"Collected CP:\t"COL_BLUE"%d\n", content, sgracz[clickedplayerid][zebranecp]);
		if(vip(clickedplayerid)) format(content, contstr, "%s"COL_YELLOW"VIP:\t"COL_GREEN"YES\n", content);
		else format(content, contstr, "%s"COL_YELLOW"VIP:\t"COL_RED"NO\n", content);
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_TABLIST, title, content, "Close", "");	
	}
	return 1;
}

CMD:top(playerid, params[])
{
	new title[100], str[1024];
	if(polak(playerid))
	{
		format(title, 100, "%s  Top Wygrane - "COL_BLUE"Master Race", form());
		format(str, 1024, ""COL_WHITE"#\tNick\t"COL_GREEN"Wygrane"COL_WHITE"/"COL_RED"Wyścigów\t"COL_WHITE"Kraj\n%s", serwer[str_topwins]);
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_TABLIST_HEADERS, title, str, "Zamknij", "");
	}
	else
	{
		format(title, 100, "%s  Top Wins - "COL_BLUE"Master Race", form());
		format(str, 1024, ""COL_WHITE"#\tNick\t"COL_GREEN"Wins"COL_WHITE"/"COL_RED"Races\t"COL_WHITE"Country\n%s", serwer[str_topwins]);
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_TABLIST_HEADERS, title, str, "Close", "");
	}
	return 1;
}

CMD:report(playerid, params[])
{
	if(polak(playerid))
	{
		if(gettime() - GetPVarInt(playerid, "ReportSpam") < 20) return Error(playerid, "Odczekaj trochę zanim wyślesz kolejny report.");
		new targetid, reason[256];
		if(sscanf(params,"ds[256]", targetid, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"UŻYJ: /report [idgracza] [powód]");
		if(targetid == playerid) return Error(playerid, "Nie możesz zreportować siebie samego.");
		if(!login(targetid)) return Error(playerid, "Ten gracz nie jest zalogowany.");
		SetPVarInt(playerid, "ReportSpam", gettime());
		for(new a; a <= GetPlayerPoolSize(); a++)
		{
			if(login(a) && admin(a))
			{
				SendClientMessageEx(a, 0xFF0000FF, "|REPORT| "COL_GREEN"%s[%d]"COL_WHITE" >> "COL_RED"%s[%d]"COL_WHITE" | Reason: %s", nick(playerid), playerid, nick(targetid), targetid, reason);
			}
		}
		mysql_escape_string(reason, reason, MySQL, 256);
		mq_format("INSERT INTO `player_report` (`uid`, `targetuid`, `reason`) VALUES ('%d', '%d', '%s');", sgracz[playerid][uID], sgracz[targetid][uID], reason);
		mq_send("REPORTQUERY");
		sgracz[targetid][ReportedTimes]++;
		mq_format("UPDATE `players` SET `ReportedTimes`='%d' WHERE `id`='%d';", sgracz[targetid][ReportedTimes], sgracz[targetid][uID]);
		mq_send("REPORTQUERY");
		SendClientMessageEx(playerid, -1, "%s "COL_GREEN"Report na gracza "COL_RED"%s"COL_GREEN" został wysłany! Dzięki!", form(), nick(targetid));
		PowiadomOOCEx(playerid, "[REPORT] %s >> %s | powod: %s", nick(playerid), nick(targetid), reason);
	}
	else
	{
		if(gettime() - GetPVarInt(playerid, "ReportSpam") < 20) return Error(playerid, "Wait a moment before you send another report.");
		new targetid, reason[256];
		if(sscanf(params,"ds[256]", targetid, reason)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /report [targetid] [reason]");
		if(targetid == playerid) return Error(playerid, "The targetid is the same as playerid.");
		if(!login(targetid)) return Error(playerid, "This playerid is not logged in.");
		SetPVarInt(playerid, "ReportSpam", gettime());
		for(new a; a <= GetPlayerPoolSize(); a++)
		{
			if(login(a) && admin(a))
			{
				SendClientMessageEx(a, 0xFF0000FF, "|REPORT| "COL_GREEN"%s[%d]"COL_WHITE" >> "COL_RED"%s[%d]"COL_WHITE" | Reason: %s", nick(playerid), playerid, nick(targetid), targetid, reason);
			}
		}
		mysql_escape_string(reason, reason, MySQL, 256);
		mq_format("INSERT INTO `player_report` (`uid`, `targetuid`, `reason`) VALUES ('%d', '%d', '%s');", sgracz[playerid][uID], sgracz[targetid][uID], reason);
		mq_send("REPORTQUERY");
		sgracz[targetid][ReportedTimes]++;
		mq_format("UPDATE `players` SET `ReportedTimes`='%d' WHERE `id`='%d';", sgracz[targetid][ReportedTimes], sgracz[targetid][uID]);
		mq_send("REPORTQUERY");
		SendClientMessageEx(playerid, -1, "%s "COL_GREEN"Report on the player "COL_RED"%s"COL_GREEN" was sent! Thanks!", form(), nick(targetid));
		PowiadomOOCEx(playerid, "[REPORT] %s >> %s | powod: %s", nick(playerid), nick(targetid), reason);
	}
	return 1;
}

CMD:pm(playerid, params[])
{
	if(polak(playerid))
	{
		if(sgracz[playerid][mute_stamp] > gettime())
		{
			SendClientMessageEx(playerid, -1, ""COL_RED"|BŁĄD|"COL_WHITE" Jesteś uciszony. Pozostało: "COL_RED"%d"COL_WHITE" sekund.", sgracz[playerid][mute_stamp] - gettime());
			return 1;
		}
		if(gettime() - GetPVarInt(playerid, "PMSpam") < 5) return Error(playerid, "Odczekaj trochę zanim wyślesz kolejną wiadomość.");
		new targetid, message[256];
		if(sscanf(params,"ds[256]", targetid, message)) return SendClientMessage(playerid, -1, ""COL_GREY"UŻYJ: /pm [idgracza] [wiadomość]");
		if(targetid == playerid) return Error(playerid, "Nie możesz wysyłać do siebie PW.");
		if(!login(targetid)) return Error(playerid, "Ten gracz nie jest zalogowany.");
		SetPVarInt(playerid, "PMSpam", gettime());
		SendClientMessageEx(playerid, -1, ""COL_GREEN"» "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(targetid), targetid, message);
		SendClientMessageEx(targetid, -1, ""COL_RED"« "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(playerid), playerid, message);
		PlayerPlaySound(targetid, 5201, 0.0, 0.0, 0.0);
		SetPVarInt(targetid, "RePMID", playerid);
	}
	else
	{
		if(sgracz[playerid][mute_stamp] > gettime())
		{
			SendClientMessageEx(playerid, -1, ""COL_RED"|ERROR|"COL_WHITE" You are muted. Time left: "COL_RED"%d"COL_WHITE" sec.", sgracz[playerid][mute_stamp] - gettime());
			return 1;
		}
		if(gettime() - GetPVarInt(playerid, "PMSpam") < 5) return Error(playerid, "Wait a moment before you send next PM.");
		new targetid, message[256];
		if(sscanf(params,"ds[256]", targetid, message)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /pm [targetid] [message]");
		if(targetid == playerid) return Error(playerid, "The targetid is the same as playerid.");
		if(!login(targetid)) return Error(playerid, "This playerid is not logged in.");
		SetPVarInt(playerid, "PMSpam", gettime());
		SendClientMessageEx(playerid, -1, ""COL_GREEN"» "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(targetid), targetid, message);
		SendClientMessageEx(targetid, -1, ""COL_RED"« "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(playerid), playerid, message);
		PlayerPlaySound(targetid, 5201, 0.0, 0.0, 0.0);
		SetPVarInt(targetid, "RePMID", playerid);
	}
	return 1;
}

CMD:w(playerid, params[])
{
	if(polak(playerid))
	{
		if(sgracz[playerid][mute_stamp] > gettime())
		{
			SendClientMessageEx(playerid, -1, ""COL_RED"|BŁĄD|"COL_WHITE" Jesteś uciszony. Pozostało: "COL_RED"%d"COL_WHITE" sekund.", sgracz[playerid][mute_stamp] - gettime());
			return 1;
		}
		if(gettime() - GetPVarInt(playerid, "PMSpam") < 5) return Error(playerid, "Odczekaj trochę zanim wyślesz kolejną wiadomość.");
		new targetid, message[256];
		if(sscanf(params,"ds[256]", targetid, message)) return SendClientMessage(playerid, -1, ""COL_GREY"UŻYJ: /w [idgracza] [wiadomość]");
		if(targetid == playerid) return Error(playerid, "Nie możesz wysyłać do siebie PW.");
		if(!login(targetid)) return Error(playerid, "Ten gracz nie jest zalogowany.");
		SetPVarInt(playerid, "PMSpam", gettime());
		SendClientMessageEx(playerid, -1, ""COL_GREEN"» "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(targetid), targetid, message);
		SendClientMessageEx(targetid, -1, ""COL_RED"« "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(playerid), playerid, message);
		PlayerPlaySound(targetid, 5201, 0.0, 0.0, 0.0);
		SetPVarInt(targetid, "RePMID", playerid);
	}
	else
	{
		if(sgracz[playerid][mute_stamp] > gettime())
		{
			SendClientMessageEx(playerid, -1, ""COL_RED"|ERROR|"COL_WHITE" You are muted. Time left: "COL_RED"%d"COL_WHITE" sec.", sgracz[playerid][mute_stamp] - gettime());
			return 1;
		}
		if(gettime() - GetPVarInt(playerid, "PMSpam") < 5) return Error(playerid, "Wait a moment before you send next PM.");
		new targetid, message[256];
		if(sscanf(params,"ds[256]", targetid, message)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /w [targetid] [message]");
		if(targetid == playerid) return Error(playerid, "The targetid is the same as playerid.");
		if(!login(targetid)) return Error(playerid, "This playerid is not logged in.");
		SetPVarInt(playerid, "PMSpam", gettime());
		SendClientMessageEx(playerid, -1, ""COL_GREEN"» "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(targetid), targetid, message);
		SendClientMessageEx(targetid, -1, ""COL_RED"« "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(playerid), playerid, message);
		PlayerPlaySound(targetid, 5201, 0.0, 0.0, 0.0);
		SetPVarInt(targetid, "RePMID", playerid);
	}
	return 1;
}

CMD:re(playerid, params[])
{
	if(polak(playerid))
	{
		if(sgracz[playerid][mute_stamp] > gettime())
		{
			SendClientMessageEx(playerid, -1, ""COL_RED"|BŁĄD|"COL_WHITE" Jesteś uciszony. Pozostało: "COL_RED"%d"COL_WHITE" sekund.", sgracz[playerid][mute_stamp] - gettime());
			return 1;
		}
		if(gettime() - GetPVarInt(playerid, "PMSpam") < 5) return Error(playerid, "Odczekaj trochę zanim wyślesz kolejną wiadomość.");
		new message[256];
		new targetid = GetPVarInt(playerid, "RePMID");
		if(targetid == -1) return Error(playerid, "Nikt ostatnio do ciebie nie napisał.");
		if(!login(targetid)) return Error(playerid, "Gracz do którego chcesz napisać nie jest zalogowany.");
		if(sscanf(params,"s[256]", message)) return SendClientMessage(playerid, -1, ""COL_GREY"UŻYJ: /re [wiadomość]");
		SetPVarInt(playerid, "PMSpam", gettime());
		SendClientMessageEx(playerid, -1, ""COL_GREEN"» "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(targetid), targetid, message);
		SendClientMessageEx(targetid, -1, ""COL_RED"« "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(playerid), playerid, message);
		PlayerPlaySound(targetid, 5201, 0.0, 0.0, 0.0);
		SetPVarInt(targetid, "RePMID", playerid);
	}
	else
	{
		if(sgracz[playerid][mute_stamp] > gettime())
		{
			SendClientMessageEx(playerid, -1, ""COL_RED"|ERROR|"COL_WHITE" You are muted. Time left: "COL_RED"%d"COL_WHITE" sec.", sgracz[playerid][mute_stamp] - gettime());
			return 1;
		}
		if(gettime() - GetPVarInt(playerid, "PMSpam") < 5) return Error(playerid, "Wait a moment before you send next PM.");
		new message[256];
		new targetid = GetPVarInt(playerid, "RePMID");
		if(targetid == -1) return Error(playerid, "No one you recently wrote.");
		if(!login(targetid)) return Error(playerid, "The re-playerid is not logged in.");
		if(sscanf(params,"s[256]", message)) return SendClientMessage(playerid, -1, ""COL_GREY"USE: /re [message]");
		SetPVarInt(playerid, "PMSpam", gettime());
		SendClientMessageEx(playerid, -1, ""COL_GREEN"» "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(targetid), targetid, message);
		SendClientMessageEx(targetid, -1, ""COL_RED"« "COL_BLUE"%s"COL_WHITE"[%d]: %s", nick(playerid), playerid, message);
		PlayerPlaySound(targetid, 5201, 0.0, 0.0, 0.0);
		SetPVarInt(targetid, "RePMID", playerid);	
	}

	return 1;
}

CMD:clear(playerid, params[])
{
	ClearChat(playerid);
	if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s Czat "COL_GREEN"wyczyszczony"COL_WHITE".", form());
	else SendClientMessageEx(playerid, -1, "%s Chat "COL_GREEN"cleared"COL_WHITE".", form());
	return 1;
}

CMD:czysc(playerid, params[])
{
	ClearChat(playerid);
	if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s Czat "COL_GREEN"wyczyszczony"COL_WHITE".", form());
	else SendClientMessageEx(playerid, -1, "%s Chat "COL_GREEN"cleared"COL_WHITE".", form());
	return 1;
}

CMD:stream(playerid, params[])
{
	if(!tgracz[playerid][astream])
	{
		StopAudioStreamForPlayer(playerid);
		tgracz[playerid][astream] = true;
		if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s Muzka "COL_RED"wyłączona"COL_WHITE".", form());
		else SendClientMessageEx(playerid, -1, "%s Music "COL_RED"stopped"COL_WHITE".", form());
	}
	else
	{
		if(strlen(serwer[songurl]) > 4) 
		{
			PlayMusic(playerid);
			tgracz[playerid][astream] = false;
			if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s "COL_GREEN"Uruchomiłeś"COL_WHITE" muzykę.", form());
			else SendClientMessageEx(playerid, -1, "%s "COL_GREEN"Playing"COL_WHITE" music.", form());
		}
		else
		{
			if(polak(playerid)) Error(playerid, "Ta mapa nie ma muzyki.");
			else Error(playerid, "Not found music.");
		}
	}
	return 1;
}

CMD:sfix(playerid, params[])
{
	if(polak(playerid))
	{
		if(!IsPlayerInAnyVehicle(playerid)) return Error(playerid, "You must be in the vehicle.");
		SendClientMessageEx(playerid, -1, "%s Bug dźwięku pojazdu "COL_GREEN"naprawiony"COL_WHITE".", form());
	}
	else
	{
		if(!IsPlayerInAnyVehicle(playerid)) return Error(playerid, "You must be in the vehicle.");
		SendClientMessageEx(playerid, -1, "%s Engine sound "COL_GREEN"fixed"COL_WHITE".", form());
	}
	PutIn(playerid, tgracz[playerid][registerveh], 0);
	return 1;
}

CMD:authors(playerid, params[])
{
	new authors[2000];
	strcat(authors,""COL_WHITE"Authors of the Master Race:\n");
	strcat(authors, ""COL_RED"sebaqq6"COL_GREY" - The main developer of the server(PAWN)"COL_RED"[Owner]"COL_GREY".\n");
	//strcat(authors, ""COL_RED"czerwony03"COL_GREY" - Midfielder and lead programmer PHP"COL_RED"[Owner]"COL_GREY".\n");
	strcat(authors,""COL_BLUE"Have fun! :)\n");
	ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Authors - "COL_GREEN"Master Race", authors, "Close", "");
	return 1;
}

CMD:autorzy(playerid, params[])
{
	new authors[2000];
	strcat(authors,""COL_WHITE"Autorzy Master Race:\n");
	strcat(authors, ""COL_RED"sebaqq6"COL_GREY" - Główny programista serwera(PAWN)"COL_RED"[Właściciel]"COL_GREY".\n");
	//strcat(authors, ""COL_RED"czerwony03"COL_GREY" - Pomocnik i główny programista PHP"COL_RED"[Właściciel]"COL_GREY".\n");
	strcat(authors,""COL_BLUE"Baw się dobrze! :)\n");
	ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" Autorzy - "COL_GREEN"Master Race", authors, "Zamknij", "");
	return 1;
}

CMD:flip(playerid, params[])
{
	if(polak(playerid))
	{
		if(!IsPlayerInAnyVehicle(playerid)) return Error(playerid, "Musisz być w aucie.");
		if(!vip(playerid)) return Error(playerid, "Musisz posiadać konto premium.");
		new currentveh;
		new Float:angle;
		currentveh = GetPlayerVehicleID(playerid);
		GetVehicleZAngle(currentveh, angle);
		SetVehicleZAngle(currentveh, angle);
		SendClientMessageEx(playerid, -1, "%s Twój pojazd został postawiony na 4 "COL_GREEN"koła"COL_WHITE".", form());
	}
	else
	{
		if(!IsPlayerInAnyVehicle(playerid)) return Error(playerid, "You must be in the vehicle.");
		if(!vip(playerid)) return Error(playerid, "You need VIP.");
		new currentveh;
		new Float:angle;
		currentveh = GetPlayerVehicleID(playerid);
		GetVehicleZAngle(currentveh, angle);
		SetVehicleZAngle(currentveh, angle);
		SendClientMessageEx(playerid, -1, "%s Your vehicle has been "COL_GREEN"flipped"COL_WHITE".", form());	
	}

	return 1;
}

CMD:vips(playerid, params[])
{
	if(polak(playerid))
	{
		new content[512];
		format(content, 512, "VIP'y online:\n");
		for(new v; v <= GetPlayerPoolSize(); v++)
		{
			if(!vip(v)) continue;
			format(content, 512, "%s\t"COL_YELLOW"%s"COL_WHITE"[%d]\n", content, nick(v), v);
		}
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" VIPy Online - "COL_GREEN"Master Race", content, "Close", "");
	}
	else
	{
		new content[512];
		format(content, 512, "Online VIP players:\n");
		for(new v; v <= GetPlayerPoolSize(); v++)
		{
			if(!vip(v)) continue;
			format(content, 512, "%s\t"COL_YELLOW"%s"COL_WHITE"[%d]\n", content, nick(v), v);
		}
		ShowPlayerDialog(playerid, INFO_DIALOG, DIALOG_STYLE_MSGBOX, ""COL_RED"»"COL_GREEN"»"COL_WHITE" VIP Players - "COL_GREEN"Master Race", content, "Close", "");	
	}
	return 1;
}

CMD:lang(playerid, params[])
{
	if(polak(playerid))
	{
		SendClientMessage(playerid, -1, "ENGLISH SET!");
		sgracz[playerid][zpolski] = false;
	}
	else
	{
		SendClientMessage(playerid, -1, "POLSKI USTAWIONY!");
		sgracz[playerid][zpolski] = true;
	}
	return 1;
}

