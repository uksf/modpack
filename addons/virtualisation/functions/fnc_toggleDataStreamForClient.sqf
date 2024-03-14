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
    private _startStream = GVAR(dataStreamClientObjects) isEqualTo [];
    GVAR(dataStreamClientObjects) pushback _player;

    if (!_startStream) exitWith {};

    GVAR(previousGroupCount) = -1;
    [{
        params ["", "_idPFH"];

        GVAR(dataStreamClientObjects) = GVAR(dataStreamClientObjects) - [objNull];
        if (GVAR(dataStreamClientObjects) isEqualTo []) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        private _currentGroupCount = count GVAR(groupPositionMap);
        if (_currentGroupCount != GVAR(previousGroupCount)) then {
            GVAR(previousGroupCount) = _currentGroupCount;

            {
                [QGVAR(streamData), [GVAR(groupPositionMap), GVAR(groupDataMap)], _x] call CBA_fnc_targetEvent;
            } forEach GVAR(dataStreamClientObjects);
        };
    }, 5, []] call CBA_fnc_addPerFrameHandler;
} else {
    GVAR(dataStreamClientObjects) deleteAt (GVAR(dataStreamClientObjects) find _player);
    [QGVAR(streamData), [[], createHashMap], _player] call CBA_fnc_targetEvent;
};
