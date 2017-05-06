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

[QGVAR(curatorAssign), [player]] call CBA_fnc_serverEvent;
[QEGVAR(common,hint), [format ["%1 logged in", name player]]] call CBA_fnc_localEvent;
[QEGVAR(common,hint), [format ["%1 logged in", name player], true]] call CBA_fnc_globalEvent;
[QEGVAR(common,log), [format ["%1 logged in", name player]]] call CBA_fnc_serverEvent;
