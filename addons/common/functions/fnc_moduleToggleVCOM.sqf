/*
    Author:
        Tim Beswick

    Description:
        Toggles group VCOM

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
    private _state = (_unit getVariable ["VCOM_NOAI", false]);
    if (_state) then {        
        ["Group included in VCOM"] call ace_common_fnc_displayTextStructured;
    } else {
        ["Group excluded from VCOM"] call ace_common_fnc_displayTextStructured;
    };
    {
        _x setVariable ["VCOM_NOAI", !_state, true];
        false
    } count (units _group);
};

deleteVehicle _logic;
