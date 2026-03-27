#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Resolves ECM source mode and range for a unit.
        Vehicle ECM has priority over backpack ECM.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        [mode, range, sourceObject] <ARRAY>
*/
params [["_unit", objNull]];

if (
    isNull _unit
    || {!alive _unit}
    || {!GVAR(ecmEnabled)}
) exitWith {["", 0, objNull]};

private _vehicle = vehicle _unit;
if (
    _vehicle isNotEqualTo _unit
    && {[_vehicle, GVAR(ecmVehicleClasses)] call FUNC(matchesClassArray)}
) exitWith {["vehicle", GVAR(ecmVehicleRange), _vehicle]};

private _backpack = backpack _unit;
if (
    _backpack isNotEqualTo ""
    && {[_backpack, GVAR(ecmBackpackClasses)] call FUNC(matchesClassArray)}
) exitWith {["backpack", GVAR(ecmBackpackRange), _unit]};

["", 0, objNull]
