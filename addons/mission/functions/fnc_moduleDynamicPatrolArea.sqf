#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Dynamic patrol area spawning module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this select 1) params ["_logic"];

if !(isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

GVAR(dynamicPatrolAreas) pushBack [_logic, _area];
