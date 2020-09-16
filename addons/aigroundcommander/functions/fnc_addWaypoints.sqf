#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Adds waypoints to AI groups

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

_group setVariable [QGVAR(spawnPosition), _spawnPosition, true]; // used in selectStayBehindForce

// default move to staging area for all groups
[_group, _stagingAreaPosition, 50, "MOVE", "AWARE", "YELLOW", "NORMAL", "WEDGE", QUOTE(GVAR(readyAtStagingArea) = GVAR(readyAtStagingArea) + 1), [0, 0, 0], 50] call CBA_fnc_addWaypoint;

if ((vehicle (leader _group)) isKindOf "helicopter") exitWith {
    [_group, _playerPosition, 100, "SAD", "COMBAT", "AWARE", "YELLOW", "NORMAL"] call CBA_fnc_addWaypoint;
    [_group, _playerPosition, 300, "SAD", "COMBAT", "AWARE", "YELLOW", "NORMAL", QUOTE((vehicle this) flyInHeight 100)] call CBA_fnc_addWaypoint;
    [_group, _spawnPosition, 50, "MOVE", "AWARE", "YELLOW", "FULL", "FILE", QUOTE((vehicle this) land 'LAND')] call CBA_fnc_addWaypoint;
    [_group, _spawnPosition, 1, "MOVE", "AWARE", "YELLOW", "FULL", "FILE", QUOTE((group this) setVariable [ARR_2(QQGVAR(hasFinishedTask),true)])] call CBA_fnc_addWaypoint;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_playerPosition", "_groupCount", "_75Percent", "_timeout"];

    if (GVAR(readyAtStagingArea) >= _75Percent || _timeout > time) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [_group, _playerPosition, 200, "SAD", "AWARE", "YELLOW", "NORMAL", "FILE", QUOTE([group this] call FUNC(selectStayBehindForce))] call CBA_fnc_addWaypoint;
    };
}, 10, [_group, _playerPosition, _groupCount, floor (_groupCount * 0.75), time + TIMEOUT]] call CBA_fnc_addPerFrameHandler;
