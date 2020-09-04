#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        For transport only, AI should wait for everyone / nearly everyone to be dismounted before getting next waypoint

    Parameters:
        0: Leader <OBJECT>

    Return value:
        Nothing
*/
#define TIME_PER_UNIT 2

params ["_leader"];

if !(local _leader) exitWith {};

private _group = group _leader;
{unassignVehicle _x} forEach units _group;

private _spawnPos = _group getVariable [QGVAR(spawnPosition), getPos (selectRandom GVAR(carSpawns))];
private _stagingArea = _group getVariable [QGVAR(stagingArea), getPos (selectRandom GVAR(stagingAreas))];
private _player = [_stagingArea] call FUNC(getPlayer);
// TODO: Need to handle when no player is selected

[{
    params ["_group", "_spawnPos", "_player"];

    [_group, _player, 100, "SAD", "AWARE", "YELLOW", "NORMAL", "LINE", QUOTE([group this] call FUNC(selectStayBehindForce))] call CBA_fnc_addWaypoint;
}, [_group, _spawnPos, _player], (2 max (count units _group)) * TIME_PER_UNIT] call CBA_fnc_waitAndExecute;
