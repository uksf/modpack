/*
    Author:
        Tim Beswick

    Description:
        Toggles whether the group can support friendly units

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "", "_activated"];

if !(_activated && local _logic) exitWith {
    deleteVehicle _logic;
};
deleteVehicle _logic;

(missionNamespace getVariable ["bis_fnc_curatorObjectPlaced_mouseOver", [""]]) params ["_typeName", "_unit"];
if (_typeName != "OBJECT" || {!(_unit isKindOf "CAManBase")} || {isPlayer _unit}) then {
    ["Place on an AI unit"] call ace_common_fnc_displayTextStructured;
} else {
    private _state = _unit getVariable [QGVAR(hasRadio), true];
    if (!_state) then {
        _unit setVariable [QGVAR(hasRadio), true, true];
        ["Unit will support"] call ace_common_fnc_displayTextStructured;
    } else {
        _unit setVariable [QGVAR(hasRadio), false, true];
        ["Unit won't support"] call ace_common_fnc_displayTextStructured;
    };
};
