/*
    Author:
    	Tim Beswick

    Description:
    	Run cleanup

    Parameters:
    	0: Killed object <OBJECT>

    Return value:
    	Nothing
*/
#include "script_component.hpp"

params ["_object"];

if (!(_object getVariable [QGVAR(excluded), false])) then {
    _delay = if (_object isKindOf "Man") then {
        GVAR(delay)
    } else {
        (GVAR(delay) * 2)
    };
    [{
        if (!(_this getVariable [QGVAR(excluded), false])) then {
            deleteVehicle _this;          
        };
    }, _object, _delay] call CBA_fnc_waitAndExecute;
} else {
    _object setVariable [QGVAR(handled), false, true];
};