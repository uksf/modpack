/*
    Author:
        Tim Beswick

    Description:
        Toggles unit cleanup state

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "_units", "_activated"];

if !(_activated && local _logic) exitWith {};

(missionNamespace getVariable ["bis_fnc_curatorObjectPlaced_mouseOver", [""]]) params ["_typeName", "_unit"];
if (_typeName != "OBJECT") then {
    ["Place on a unit or vehicle"] call ace_common_fnc_displayTextStructured;
} else {
    if (!(_unit getVariable [QGVAR(excluded), false])) then {
        _unit setVariable [QGVAR(excluded), true, true];
        ["Unit excluded from cleanup"] call ace_common_fnc_displayTextStructured;
    } else {
        _unit setVariable [QGVAR(excluded), false, true];
        if (!(_unit getVariable [QGVAR(handled), false]) && {!(alive _unit)}) then {
            [_unit] call FUNC(handleKilled);
            ["Unit included in cleanup"] call ace_common_fnc_displayTextStructured;
        };
    };
};

deleteVehicle _logic;
