/*
	Author:
		Tim Beswick

	Description:
		Spawns defined units on marker positions with marker waypoint positions, directly on the headless client. (IT'S CRUDE OK)
*/
if(!isServer) exitWith {};
sleep 60;

//rs_1, rs_2, rs_3, rs_4, rs_5
//rw
//_wp setWaypointType "TR UNLOAD";
//TR UNLOAD, GETOUT

//Headless clients
HCs = [];
{
	_id = owner _x;
	HCs = HCs + [_id];
} forEach (entities "HeadlessClient_F");

//Simply selectes a random HC, and spawns the group on the defined marker position. Sets waypoint on defined marker position as well.
{
	_group = [getMarkerPos "supportSpawn", independent, ["I_G_Story_Protagonist_F", "B_G_Soldier_AR_F", "B_G_medic_F", "B_G_Sharpshooter_F"]] call BIS_fnc_spawnGroup;
	_group addWaypoint [getMarkerPos "supportSpawn_wp", 0];
	_group addWaypoint [getMarkerPos "supportSpawn_wp_1", 0];
	_group addWaypoint [getMarkerPos "supportSpawn_wp_2", 0];
	_group setBehaviour "AWARE";
	_group setSpeedMode "NORMAl";
} remoteExec ["bis_fnc_call", selectRandom HCs, false];

//No spawning, but a useful thing for time acceleration to a defined time
setTimeMultiplier 90;
[{(((date select 2) > (_this select 0)) && (daytime > 4.5))}, {setTimeMultiplier 1;}, [_date]] call ace_common_fnc_waitUntilAndExecute;
