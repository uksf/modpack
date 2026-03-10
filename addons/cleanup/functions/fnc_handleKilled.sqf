#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Run cleanup

    Parameters:
        0: Killed object <OBJECT>

    Return value:
        Nothing

    Example:
        [_object] call uksf_cleanup_fnc_handleKilled
*/
if (!GVAR(enabled)) exitWith {};

params ["_object"];

if (!(_object getVariable [QGVAR(excluded), false])) then {
    [QGVAR(addKilled), _object] call CBA_fnc_serverEvent;
} else {
    _object setVariable [QGVAR(handled), false, true];
};
