#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds module area to dynamic patrol exclude areas

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_logic"];

if (!(local _logic)) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

GVAR(dynamicPatrolExcludeAreas) pushBack [_logic, _area];
