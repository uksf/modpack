#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Runs CAS, gets the players itself and doesn't rely on commander > getPlayers

    Parameters:
        0: Group <GROUP>

    Return value:
        Nothing
*/
params ["_group"];

private _player = selectRandom EGVAR(aiGroundCommander,killerPlayers);
if (isNull _player) exitWith {
    [leader _group] call FUNC(handleDelete);
};

private _vehicle = vehicle (leader _group);
if (_vehicle isKindOf "Helicopter") then {
    _vehicle flyInHeight 300;
    _group reveal [_player, 4];
    [_group, _player, 100, "SAD", "AWARE", "YELLOW", "NORMAL"] call CBA_fnc_addWaypoint;
} else {
    _group setVariable ["lambs_danger_disableGroupAI", true];
    _vehicle flyInHeight 500;
    [_group, _player, 2000 + random 500, "MOVE", "AWARE", "YELLOW", "NORMAL"] call CBA_fnc_addWaypoint; // TODO: This seems a bit odd
    [_group, _player, 2000 + random 500, "MOVE", "AWARE", "YELLOW", "NORMAL"] call CBA_fnc_addWaypoint; // TODO: This seems a bit odd
    [_group, _player, 20, "MOVE", "AWARE", "YELLOW", "NORMAL", "", QUOTE([vehicle this] call FUNC(doCAS))] call CBA_fnc_addWaypoint;
};

private _airSpawn = getPos (selectRandom GVAR(planeSpawns));
[_group, _airSpawn, 50, "MOVE", "AWARE", "YELLOW", "NORMAL", "", QUOTE([this] call FUNC(handleDelete))] call CBA_fnc_addWaypoint;
