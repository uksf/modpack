/*
    Author:
        Tim Beswick

    Description:
        Toggles group VCOM support

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
if (_typeName != "OBJECT" && {!(alive _unit)}) then {
    ["Place on a living unit or vehicle"] call ace_common_fnc_displayTextStructured;
} else {
    private _group = group _unit;
    if (_group getVariable ["VCOM_SupportExclude", false]) then {
        _group setVariable ["VCOM_SupportExclude", false, true];
        ["Group included in VCOM Support"] call ace_common_fnc_displayTextStructured;
    } else {
        _group setVariable ["VCOM_SupportExclude", true, true];
        ["Group excluded from VCOM Support"] call ace_common_fnc_displayTextStructured;
    };
};

deleteVehicle _logic;
