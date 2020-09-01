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

    if (_value isEqualType "") then { // If the value is a string, special handling is needed
        if (_value != "") then { // If the string is not empty, compile the contents into a usable array
            _value = call compile _value;
        } else {
            _value = []; // String is empty, just return an empty array
        };
    };
    // Value is not a string (likely default value []), no special handling needed
    _value
};

private _units = [_module, QGVAR(unitPoolString)] call _fnc_getArrayFromModule;
private _groundVehicles = [_module, QGVAR(groundVehiclePoolString)] call _fnc_getArrayFromModule;
private _airVehicles = [_module, QGVAR(airVehiclePoolString)] call _fnc_getArrayFromModule;

{GVAR(unitPool) pushBackUnique _x;} forEach _units;
{GVAR(groundVehiclePool) pushBackUnique _x;} forEach _groundVehicles;
{GVAR(airVehiclePool) pushBackUnique _x;} forEach _airVehicles;
