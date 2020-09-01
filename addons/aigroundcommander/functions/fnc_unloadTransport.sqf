#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        for transport only, AI should wait for everyone / nearly everyone to be dismounted before getting next waypoint

    Parameters:
        0: _leader <OBJECT>

    Return value:
        Nothing
*/

#define TIME_PER_UNIT_CONSTANT 2

params ["_leader"];

if (!local _leader) exitWith {};

private _group = group _leader;

{unassignVehicle _x} forEach units _group;

private _spawnPos = _group getVariable [QGVAR(spawnPosition),(getPos selectRandom GVAR(carSpawns))];
private _stagingArea = _group getVariable [QGVAR(SAPos),(getPos selectRandom GVAR(stagingAreas))];
private _player = [_stagingArea] call FUNC(getPlayers);

[{
    params ["_group","_spawnPos","_player"];
    [_group,_player,100,"SAD","AWARE","YELLOW","NORMAL","LINE","[(group this)] call uksf_aigroundCommander_fnc_selectStayBehindForce;"] call CBA_fnc_addWaypoint;
},[_group,_spawnPos,_player], 2 max (count units _group) * TIME_PER_UNIT_CONSTANT] call CBA_fnc_waitAndExecute;
