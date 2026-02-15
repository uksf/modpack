#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds or removes player to list of clients to stream virtualisation data to

    Parameters:
        0: Player <OBJECT>
        1: State <Boolean>

    Return value:
        Nothing
*/
params ["_player", "_on"];

if (_player == player) exitWith {}; // Guard against overwriting the same data in singleplayer/local MP

if (_on) then {
    GVAR(dataStreamClientObjects) pushBack _player;
    [QGVAR(streamData), [GVAR(groupPositionMap), GVAR(groupDataMap)], _player] call CBA_fnc_targetEvent;
} else {
    GVAR(dataStreamClientObjects) deleteAt (GVAR(dataStreamClientObjects) find _player);
    [QGVAR(streamData), [[], createHashMap], _player] call CBA_fnc_targetEvent;
};
