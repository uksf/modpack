#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Updates ECM state for a unit, draining backpack battery while active.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        None
*/
params [["_unit", objNull]];

if (!isServer || {isNull _unit}) exitWith {};

private _lastUpdate = _unit getVariable [QGVAR(ecmLastUpdate), CBA_missionTime];
private _now = CBA_missionTime;
private _delta = (_now - _lastUpdate) max 0;
_unit setVariable [QGVAR(ecmLastUpdate), _now, true];

if (!(_unit getVariable [QGVAR(ecmActive), false])) exitWith {};

private _source = [_unit] call FUNC(getECMSource);
_source params ["_mode"];
if (_mode isEqualTo "") exitWith {
    [_unit, false, false] call FUNC(ecmDeactivate);
    [QEGVAR(common,hint), ["ECM turned off"], _unit] call CBA_fnc_targetEvent;
};

_unit setVariable [QGVAR(ecmSourceMode), _mode, true];

if (_mode isEqualTo "vehicle") exitWith {};

private _remaining = (_unit getVariable [QGVAR(ecmBatteryRemaining), 0]) max 0;
if (_remaining <= 0) exitWith {
    [_unit, false, false] call FUNC(ecmDeactivate);
    [QEGVAR(common,hint), ["ECM battery depleted"], _unit] call CBA_fnc_targetEvent;
};

_remaining = _remaining - _delta;
_remaining = _remaining max 0;
_unit setVariable [QGVAR(ecmBatteryRemaining), _remaining, true];

if (_remaining <= 0) then {
    [_unit, false, false] call FUNC(ecmDeactivate);
    [QEGVAR(common,hint), ["ECM battery depleted"], _unit] call CBA_fnc_targetEvent;
};
