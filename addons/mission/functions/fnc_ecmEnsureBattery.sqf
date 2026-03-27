#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Ensures a backpack ECM battery charge exists. Consumes an item when needed.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        BOOLEAN
*/
params [["_unit", objNull]];

if (isNull _unit) exitWith {false};

private _remaining = _unit getVariable [QGVAR(ecmBatteryRemaining), 0];
if (_remaining > 0) exitWith {true};

private _batteryClass = QGVAR(ecmBattery);
if (!([_unit, _batteryClass] call ace_common_fnc_hasItem)) exitWith {false};

_unit removeItem _batteryClass;
_unit setVariable [QGVAR(ecmBatteryRemaining), GVAR(ecmBatteryTime), true];
true
