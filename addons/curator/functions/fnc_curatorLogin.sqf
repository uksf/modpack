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

if (isMultiplayer || {!isMultiplayer && {GVAR(curatorObjects) isEqualTo []}}) then {
    [QGVAR(curatorCreate), []] call CBA_fnc_serverEvent;
};
[QGVAR(curatorAssign), [player]] call CBA_fnc_serverEvent;
[QEGVAR(common,adminHint), [format ["%1 logged in", name player]]] call CBA_fnc_globalEvent;
[QEGVAR(common,serverLog), [format ["%1 logged in", name player]]] call CBA_fnc_serverEvent;
