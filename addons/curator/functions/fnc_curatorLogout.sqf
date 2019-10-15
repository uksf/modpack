#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Logs player out of curator

    Parameter(s):
        None

    Return Value:
        None
*/

[QGVAR(curatorUnassign), [getAssignedCuratorLogic player]] call CBA_fnc_serverEvent;
[QEGVAR(common,hint), [format ["%1 logged out", name player]]] call CBA_fnc_localEvent;
[QEGVAR(common,hint), [format ["%1 logged out", name player], true]] call CBA_fnc_globalEvent;
[QEGVAR(common,log), [format ["%1 logged out", name player]]] call CBA_fnc_serverEvent;
