#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        This function makes an AI swing their searchlight from left to right.
        It will randomly swing from 10 oclock to 2 oclock at random intervals.

    Parameters:
        0: _operator <OBJECT>

    Return value:
        Nothing
*/

params ["_operator"];

_operator action ["SearchlightOn", vehicle _operator];

// set once to keep the same 10 and 2oclock
private _dir = getDir _operator;
private _posATL = getPosATL _operator;

[{
    params ["_args", "_idPFH"];
    _args params ["_operator", "_dir", "_posATL"];

    if (!alive _operator) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    private _watchingLeftPos = _operator getVariable [QGVAR(watchingLeftPos), true];


    if (_watchingLeftPos) exitWith {
        private _heightAdjustedPos = _posATL getPos [0.5, (_dir + random(45))];
        _heightAdjustedPos set [2, _posATL#2 + 1.4];

        _operator doWatch (_heightAdjustedPos);
        _operator setVariable [QGVAR(watchingLeftPos), false, true];
    };

    private _heightAdjustedPos = _posATL getPos [0.5, (_dir - random(45))];
    _heightAdjustedPos set [2, _posATL#2 + 1.4];

    _operator doWatch (_heightAdjustedPos);
    _operator setVariable [QGVAR(watchingLeftPos), true, true];


}, 20 + random 40, [_operator, _dir, _posATL]] call cba_fnc_addPerFrameHandler;


