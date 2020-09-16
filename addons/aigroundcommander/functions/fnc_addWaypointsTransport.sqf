#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Adds waypoints to AI transport groups to move to staging areas then dismount

    Parameters:
        0: Spawn position <ARRAY>
        1: Staging area position <ARRAY>
        2: Player position <ARRAY>
        3: Group count <SCALAR>
        4: Group <GROUP>

    Return value:
        Nothing
*/
#define TIMEOUT 420

params ["_spawnPosition", "_stagingAreaPosition", "_playerPosition", "_groupCount", "_group"];

_group setVariable [QGVAR(spawnPosition), _spawnPosition, true];
_group setVariable [QGVAR(playerPosition), _playerPosition, true];

[_group, _stagingAreaPosition, 50, "MOVE", "AWARE", "YELLOW", "NORMAL", "FILE", QUOTE(GVAR(readyAtStagingArea) = GVAR(readyAtStagingArea) + 1)] call CBA_fnc_addWaypoint;

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_playerPosition", "", "_75Percent", "_timeout"];

    if (GVAR(readyAtStagingArea) >= _75Percent || _timeout > time) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [_group, _playerPosition, 300, "GETOUT", "AWARE", "YELLOW", "NORMAL", "FILE", QUOTE([this] call FUNC(unloadTransport))] call CBA_fnc_addWaypoint;
    };
}, 10, [_group, _playerPosition, _groupCount, floor (_groupCount * 0.75), time + TIMEOUT]] call CBA_fnc_addPerFrameHandler;
