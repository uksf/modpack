#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Activates ECM for a unit.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        BOOLEAN
*/
params [["_unit", objNull]];

if (!isServer || {isNull _unit} || {!alive _unit} || {!GVAR(ecmEnabled)}) exitWith {false};
if (_unit getVariable [QGVAR(ecmActive), false]) exitWith {false};

private _source = [_unit] call FUNC(getECMSource);
_source params ["_mode", "_range", "_sourceObject"];
if (_mode isEqualTo "") exitWith {
    [QEGVAR(common,hint), ["No valid ECM source"], _unit] call CBA_fnc_targetEvent;
    false
};

if (
    _mode isEqualTo "backpack"
    && {(_unit getVariable [QGVAR(ecmBatteryRemaining), 0]) <= 0}
) exitWith {
    [QEGVAR(common,hint), ["No ECM battery available"], _unit] call CBA_fnc_targetEvent;
    false
};

_unit setVariable [QGVAR(ecmActive), true, true];
_unit setVariable [QGVAR(ecmSourceMode), _mode, true];
_unit setVariable [QGVAR(ecmLastUpdate), CBA_missionTime, true];

if (_mode isEqualTo "vehicle") then {
    _sourceObject setVariable [QGVAR(ecmVehicleActive), true, true];
    _sourceObject setVariable [QGVAR(ecmVehicleSourceSide), side group _unit, true];
    _unit setVariable [QGVAR(ecmActiveVehicle), _sourceObject, true];
} else {
    _unit setVariable [QGVAR(ecmActiveVehicle), objNull, true];
};

[QEGVAR(common,hint), [format ["ECM turned on, range = %1", round _range]], _unit] call CBA_fnc_targetEvent;

true
