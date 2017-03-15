/*
    Author:
        Tim Beswick

    Description:
        Handles zeus disconnect

    Parameter(s):
        0: Unit <OBJECT>
        1: ID <SCALAR>
        1: UID <STRING>
        2: Name <STRING>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["", "", "", "_name"];

private _names = missionNamespace getVariable [QGVAR(curatorNames), ["","","","",""]];
private _index = _names find _name;
if (_index != -1) then {
    _names set [_index, ""];
    unassignCurator (GVAR(curatorObjects) select _index);
};
missionNamespace setVariable [QGVAR(curatorNames), _names, true];
