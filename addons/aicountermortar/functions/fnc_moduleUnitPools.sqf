#include "script_component.hpp"
/*
    Author:
        Adam Bridgford

    Description:
        Gets the units specified in the module

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

if (!isServer) exitWith {};

private _fnc_getArrayFromModule = {
    params ["_module", "_property"];

    private _value = _module getVariable [_property, []];
    [_value] call EFUNC(common,convertToArray)
};

private _units = [_module, QGVAR(unitPoolString)] call _fnc_getArrayFromModule;
private _groundVehicles = [_module, QGVAR(groundVehiclePoolString)] call _fnc_getArrayFromModule;
private _airVehicles = [_module, QGVAR(airVehiclePoolString)] call _fnc_getArrayFromModule;

{GVAR(unitPool) pushBackUnique _x;} forEach _units;
{GVAR(groundVehiclePool) pushBackUnique _x;} forEach _groundVehicles;
{GVAR(airVehiclePool) pushBackUnique _x;} forEach _airVehicles;
