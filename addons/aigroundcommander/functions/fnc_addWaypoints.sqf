#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Adds waypoints to AI groups

    Parameters:
        0: Spawn position module <OBJECT>
        1: Staging area module <OBJECT>
        2: Target player <OBJECT>
        3: Nubmer of response Groups to spawn <SCALAR>
        4: Group <GROUP>

    Return value:
        Nothing
*/
#define TIMEOUT 420

params ["_spawnPosition", "_stagingArea", "_player", "_numberOfResponseGroupsToBeSpawned", "_group"];

_group setVariable [QGVAR(spawnPosition), _spawnPosition, true]; // used in selectStayBehindForce

// default move to staging area for all groups
[_group, _stagingArea, 50, "MOVE", "AWARE", "YELLOW", "NORMAL", "WEDGE", QUOTE(GVAR(readyAtStagingArea) = GVAR(readyAtStagingArea) + 1), [0, 0, 0], 50] call CBA_fnc_addWaypoint;

if ((vehicle (leader _group)) isKindOf "helicopter") exitWith {
    [_group, _player, 100, "SAD", "COMBAT", "AWARE", "YELLOW", "NORMAL"] call CBA_fnc_addWaypoint;
    [_group, _player, 300, "SAD", "COMBAT", "AWARE", "YELLOW", "NORMAL", QUOTE((vehicle this) flyInHeight 100)] call CBA_fnc_addWaypoint;
    [_group, _spawnPosition, 50, "MOVE", "AWARE", "YELLOW", "FULL", "FILE", QUOTE((vehicle this) land 'LAND')] call CBA_fnc_addWaypoint;
    [_group, _spawnPosition, 1, "MOVE", "AWARE", "YELLOW", "FULL", "FILE", QUOTE((group this) setVariable [ARR_2(QQGVAR(hasFinishedTask),false)])] call CBA_fnc_addWaypoint;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_player", "_numberOfResponseGroupsToBeSpawned", "_75Percent", "_timeout"];

    if (GVAR(readyAtStagingArea) >= _75Percent || _timeout > time) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [_group, _player, 200, "SAD", "AWARE", "YELLOW", "NORMAL", "FILE", QUOTE([group this] call FUNC(selectStayBehindForce))] call CBA_fnc_addWaypoint;
    };
}, 10, [_group, _player, _numberOfResponseGroupsToBeSpawned, floor (_numberOfResponseGroupsToBeSpawned * 0.75), time + TIMEOUT]] call CBA_fnc_addPerFrameHandler;
