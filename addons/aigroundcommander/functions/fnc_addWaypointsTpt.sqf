#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        for transport
        adds waypoints to AI groups to move to staging areas then dismount

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

_group setVariable [QGVAR(spawnPosition), _spawnPosition, true];
_group setVariable [QGVAR(stagingArea), _stagingArea, true];

[_group, _stagingArea, 50, "MOVE", "AWARE", "YELLOW", "NORMAL", "FILE", QUOTE(GVAR(readyAtStagingArea) = GVAR(readyAtStagingArea) + 1)] call CBA_fnc_addWaypoint;

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_player", "", "_75Percent", "_timeout"];

    if (GVAR(readyAtStagingArea) >= _75Percent || _timeout > time) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [_group, _player, 300, "GETOUT", "AWARE", "YELLOW", "NORMAL", "FILE", QUOTE([this] call FUNC(unloadTransport))] call CBA_fnc_addWaypoint;
    };
}, 10, [_group, _player, _numberOfResponseGroupsToBeSpawned, floor (_numberOfResponseGroupsToBeSpawned * 0.75), time + TIMEOUT]] call CBA_fnc_addPerFrameHandler;
