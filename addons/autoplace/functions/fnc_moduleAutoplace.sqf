#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Eden module entrypoint for one-shot AI building occupation.

    Parameters:
        0: Logic module arguments <ARRAY>

    Return Value:
        Nothing

    Example:
        [_this] call uksf_autoplace_fnc_moduleAutoplace
*/
(_this#1) params ["_logic"];

if (!isServer) exitWith {};
if (isNull _logic) exitWith {};
if (_logic getVariable [QGVAR(processed), false]) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

_logic setVariable [QGVAR(processed), true, true];

[_logic, _area] call FUNC(runAutoplace);
