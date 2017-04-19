/*
    Author:
        Tim Beswick

    Description:
        Creates curator and assigns to player

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

GVAR(curatorLogged) = true;
[QGVAR(curatorCreate), []] call CBA_fnc_serverEvent;
[QGVAR(curatorAssign), [player]] call CBA_fnc_serverEvent;
[QGVAR(adminHint), [format ["%1 logged in", name player]]] call CBA_fnc_globalEvent;

