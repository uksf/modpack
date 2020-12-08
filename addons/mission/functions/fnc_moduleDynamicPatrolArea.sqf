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

INFO_1("1) Area module init",_this);

if !(isServer) exitWith {
    INFO("1) Area module init failed server check, exiting");
};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {
    INFO_1("1) Area module init area is empty (%1), exiting",_area);
};

GVAR(dynamicPatrolAreas) pushBack [_logic, _area];
