#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Forces a unit to swing its searchlight from left to right at specified intervals

    Parameters:
        0: Areas or IDs or display names <ARRAY>
        1: Rating change <SCALAR>

    Return value:
        Nothing

    Example in unit init:
        [this] call uksf_extras_fnc_swingSearchLight;
*/
params ["_unit"];

_unit action ["SearchlightOn", vehicle _unit];

private _dir = getDir _unit;
private _pos = getPos _unit;

[{
    params ["_args", "_idPFH"];
    _args params ["_unit", "_dir", "_pos"];

    if (!alive _unit) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    private _watchingLeftPos = _unit getVariable [QGVAR(watchingLeftPos), true];


    if (_watchingLeftPos) exitWith {
        _unit doWatch (_pos getPos [200, (_dir + random(45))]);
        _unit setVariable [QGVAR(watchingLeftPos), false, true];
    };

    _unit doWatch (_pos getPos [200, (_dir - random(45))]);
    _unit setVariable [QGVAR(watchingLeftPos), true, true];


}, 20 + random 40, [_unit, _dir, _pos]] call cba_fnc_addPerFrameHandler;
