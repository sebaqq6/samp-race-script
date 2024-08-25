stock StartSpecMode(playerid)
{
	for(new g; g <= GetPlayerPoolSize(); g++)
	{
		if(!login(g)) continue;
		if(tgracz[g][ukonczyl]) continue;
		if(!IsPlayerInAnyVehicle(g)) continue;
		TogglePlayerSpectating(playerid, true);
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(g));
		tgracz[playerid][specid] = g;
		String_specTD(playerid, nick(g));
		tgracz[playerid][specuje] = true;
		if(polak(playerid)) SendClientMessageEx(playerid, -1, "%s Używaj SPACJA/LSHIFT zmieniać gracza.", form());
		else SendClientMessageEx(playerid, -1, "%s SpecMode enabled, use LSHIFT/SPACE to change player.", form());
		break;
	}
	return 1;
}

stock Spec_ReSpecAction(playerid, vehid)
{
	for(new g; g <= GetPlayerPoolSize(); g++)
	{
		if(!login(g)) continue;
		if(!tgracz[g][specuje]) continue;
		if(tgracz[g][specid] == playerid)
		{
			TogglePlayerSpectating(g, true);
			PlayerSpectateVehicle(g, vehid);
			String_specTD(g, nick(playerid));
		}
	}
	return 1;
}

stock Spec_OtherSpec(playerid)
{
	for(new g; g <= GetPlayerPoolSize(); g++)
	{
		if(!login(g)) continue;
		if(!tgracz[g][specuje]) continue;
		if(tgracz[g][specid] == playerid)
		{
			if(!Spec_Next(g))
			{
				if(!Spec_Prev(g))
				{
					TogglePlayerSpectating(g, false);
					if(!tgracz[g][progress_podium])
					{
						tgracz[g][progress_podium] = true;
						SetTimerEx("SetPodium", 1500, false, "d", g);
					}
				}
			}
		}
	}
	return 1;
}

stock Spec_Next(playerid)
{
	new bool:znalazl = false;
	for(new g; g <= GetPlayerPoolSize(); g++)
	{
		if(!login(g)) continue;
		if(tgracz[g][specuje]) continue;
		if(!IsPlayerInAnyVehicle(g)) continue;
		if(g > tgracz[playerid][specid])
		{
			TogglePlayerSpectating(playerid, true);
			PlayerSpectateVehicle(playerid, GetPlayerVehicleID(g));
			tgracz[playerid][specid] = g;
			String_specTD(playerid, nick(g));
			znalazl = true;
			break;
		}
	}
	return znalazl;
}

stock Spec_Prev(playerid)
{
	new bool:znalazl = false;
	for(new g = GetPlayerPoolSize(); g >= 0; g--)
	{
		if(!login(g)) continue;
		if(tgracz[g][specuje]) continue;
		if(!IsPlayerInAnyVehicle(g)) continue;
		if(g < tgracz[playerid][specid])
		{
			TogglePlayerSpectating(playerid, true);
			PlayerSpectateVehicle(playerid, GetPlayerVehicleID(g));
			tgracz[playerid][specid] = g;
			String_specTD(playerid, nick(g));
			znalazl = true;
			break;
		}
	}
	return znalazl;
}

forward SetPodium(playerid);
public SetPodium(playerid)
{
	tgracz[playerid][progress_podium] = false;
	switch(tgracz[playerid][podiumpos])
	{
		case 0..1:
		{
			SetPlayerPos(playerid, -2818.6040,1810.0485,14.5100);
		}
		case 2:
		{
			SetPlayerPos(playerid, -2816.6143,1807.9371,13.6500);
		}
		case 3:
		{
			SetPlayerPos(playerid, -2820.4697,1812.5128,13.0600);
		}
		default:
		{
			SetPlayerPos(playerid, -2808.6819,1818.6494, 0.0);
		}
	}
	SetPlayerFacingAngle(playerid, 309.5125);
	SetPlayerCameraPos(playerid, -2808.9268, 1818.3375, 16.9147);
	SetPlayerCameraLookAt(playerid, -2809.6865, 1817.6796, 16.6347);
	TogglePlayerControllable(playerid, false);
	return 1;
}