#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Deactivates ECM for a unit while preserving backpack battery state.

    Parameters:
        0: Unit <OBJECT>
        1: Show notification <BOOL>

    Return value:
        BOOLEAN
*/
params [["_unit", objNull], ["_notify", true], ["_disableVehicle", true]];

if (!isServer || {isNull _unit}) exitWith {false};
if (!(_unit getVariable [QGVAR(ecmActive), false])) then {
    if (_disableVehicle) then {
        private _source = [_unit] call FUNC(getECMSource);
        _source params ["_mode", "_range", "_sourceObject"];
        if (
            _mode isEqualTo "vehicle"
            && {!isNull _sourceObject}
            && {_sourceObject getVariable [QGVAR(ecmVehicleActive), false]}
        ) exitWith {
            _sourceObject setVariable [QGVAR(ecmVehicleActive), false, true];
            _sourceObject setVariable [QGVAR(ecmVehicleSourceSide), sideUnknown, true];
            if (_notify) then {
                [QEGVAR(common,hint), ["ECM turned off"], _unit] call CBA_fnc_targetEvent;
            };
            true
        };
    };
    false
};

private _sourceMode = _unit getVariable [QGVAR(ecmSourceMode), ""];
private _activeVehicle = _unit getVariable [QGVAR(ecmActiveVehicle), objNull];
if (
    _disableVehicle
    && {_sourceMode isEqualTo "vehicle"}
    && {!isNull _activeVehicle}
) then {
    _activeVehicle setVariable [QGVAR(ecmVehicleActive), false, true];
    _activeVehicle setVariable [QGVAR(ecmVehicleSourceSide), sideUnknown, true];
};

_unit setVariable [QGVAR(ecmActive), false, true];
_unit setVariable [QGVAR(ecmSourceMode), "", true];
_unit setVariable [QGVAR(ecmLastUpdate), CBA_missionTime, true];
_unit setVariable [QGVAR(ecmActiveVehicle), objNull, true];

if (_notify) then {
    [QEGVAR(common,hint), ["ECM turned off"], _unit] call CBA_fnc_targetEvent;
};

true
