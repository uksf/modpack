/*
    Author:
        Tim Beswick

    Description:
        Deletes corpse quicker than cleanup

    Parameter(s):
        0: Unit <OBJECT>
        1: Corpse <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["", "_corpse"];

if (GVAR(firstRespawn)) then {
    [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
    GVAR(firstRespawn) = false;
};

[QEGVAR(common,waitAndDelete), [_corpse, 10]] call CBA_fnc_serverEvent;
