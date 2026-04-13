#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Registers destination patrol module logic for diagnostics and validation.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_vehiclepatrols_fnc_modulePatrolDestination
*/

(_this select 1) params ["_logic"];

if ((local _logic) isEqualTo false) exitWith {};
if (isServer isEqualTo false) exitWith {};

GVAR(destinationModules) pushBackUnique _logic;
