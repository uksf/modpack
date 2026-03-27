#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client-side activation request for ECM. Handles local backpack battery item
        consumption when starting a fresh backpack battery charge.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        None
*/
params [["_unit", objNull]];

if (!hasInterface || {isNull _unit} || {_unit isNotEqualTo player}) exitWith {};
if (!GVAR(ecmEnabled) || {_unit getVariable [QGVAR(ecmActive), false]}) exitWith {};

private _source = [_unit] call FUNC(getECMSource);
_source params ["_mode"];

if (_mode isEqualTo "") exitWith {
    ["No valid ECM source"] call EFUNC(common,hint);
};

if (_mode isEqualTo "backpack") then {
    private _remaining = _unit getVariable [QGVAR(ecmBatteryRemaining), 0];
    if (_remaining <= 0) then {
        if (!([_unit, QGVAR(ecmBattery)] call ace_common_fnc_hasItem)) exitWith {
            ["No ECM battery available"] call EFUNC(common,hint);
        };

        _unit removeItem QGVAR(ecmBattery);
        _unit setVariable [QGVAR(ecmBatteryRemaining), GVAR(ecmBatteryTime), true];
    };
};

[QGVAR(ecmRequestActivate), [_unit]] call CBA_fnc_serverEvent;
