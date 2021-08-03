#include "script_component.hpp"
/*
    Author:
        Bridg, Beswick

    Description:
        Suicide area spawning module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this select 1) params ["_logic"];

TRACE_1("1) Area module init",_this);

if !(isServer) exitWith {
    INFO("1) Area module init failed server check, exiting");
};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {
    TRACE_1("1) Area module init area is empty, exiting",_area);
};

GVAR(suicideIEDAreas) pushBack [_logic, _area];
