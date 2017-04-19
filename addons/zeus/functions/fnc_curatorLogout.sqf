/*
    Author:
        Tim Beswick

    Description:
        Unassigns and deletes curator

    Parameter(s):
        0: Kicked <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params [["_kicked", false]];

[QGVAR(curatorUnassign), [getAssignedCuratorLogic player]] call CBA_fnc_serverEvent;
if (_kicked) then {
    ["You were kicked"] call ace_common_fnc_displayTextStructured;
} else {
    [QGVAR(adminHint), [format ["%1 logged out", name player]]] call CBA_fnc_globalEvent;
};
