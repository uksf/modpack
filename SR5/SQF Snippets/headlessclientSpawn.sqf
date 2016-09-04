/*
	Author:
		Tim Beswick

	Description:
		Spawns defined units on marker positions with marker waypoint positions, directly on the headless client. (IT'S CRUDE OK)
*/
if(!isServer) exitWith {};

//rs_1, rs_2, rs_3, rs_4, rs_5
//rw
//_wp setWaypointType "TR UNLOAD";
//TR UNLOAD, GETOUT

//Unit arrays
_6 = (configFile >> "CfgGroups" >> "East" >> "UKSF_Laraka" >> "Infantry" >> "Laraka_6");
_10 = (configFile >> "CfgGroups" >> "East" >> "UKSF_Laraka" >> "Infantry" >> "Laraka_10");
_hiluxU = ["Laraka_Hilux_Unarmed_Populated"];
_hiluxA = ["Laraka_Hilux_DSHKM"];
_uazU = ["Laraka_Uaz_Unarmed_Populated"];
_uazA = ["Laraka_Uaz_DSHKM"];
_date = date select 2;

sleep 60;

//Simply selectes a random HC, and spawns the group on the defined marker position. Sets waypoint on defined marker position as well.

//No spawning, but a useful thing for time acceleration to a defined time
setTimeMultiplier 90;
[{(((date select 2) > (_this select 0)) && (daytime > 4.5))}, {setTimeMultiplier 1;}, [_date]] call ace_common_fnc_waitUntilAndExecute;
