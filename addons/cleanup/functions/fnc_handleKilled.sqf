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
    _killed = missionNameSpace getVariable [QGVAR(killed), []];
    _multiplier = if (_object isKindOf "Man") then {
        1
    } else {
        2
    };
    _killed pushBack [_object, time * _multiplier];
    missionNamespace setVariable [QGVAR(killed), _killed, true];
} else {
    _object setVariable [QGVAR(handled), false, true];
};
