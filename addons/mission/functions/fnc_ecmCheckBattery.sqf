#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Displays remaining ECM battery state.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        None
*/
params [["_unit", objNull]];

if (isNull _unit || {!alive _unit}) exitWith {};

private _source = [_unit] call FUNC(getECMSource);
_source params ["_mode"];

if (_mode isEqualTo "vehicle") exitWith {
    [format ["<t color='#4FC3F7'>ECM Battery</t><br/><t color='#4FC3F7'>|||||</t> <t color='#4FC3F7'>Vehicle-powered (infinite)</t>"]] call EFUNC(common,hint);
};

private _remaining = (_unit getVariable [QGVAR(ecmBatteryRemaining), 0]) max 0;
private _batteryTime = GVAR(ecmBatteryTime) max 1;
private _percent = (_remaining / _batteryTime) * 100;
private _bars = [_percent] call FUNC(formatBatteryBar);

[format ["<t color='#ffffff'>ECM Battery</t><br/>%1 <t color='#ffffff'>%2%3</t>", _bars, round _percent, "%"]] call EFUNC(common,hint);
