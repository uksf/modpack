/*
    Author:
        Tim Beswick

    Description:
        Toggles group VCOM vehicle disembark

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "", "_activated"];

if !(_activated && local _logic) exitWith {};

(missionNamespace getVariable ["bis_fnc_curatorObjectPlaced_mouseOver", [""]]) params ["_typeName", "_unit"];
if (_typeName != "OBJECT" && {!(alive _unit)}) then {
    ["Place on a living unit or vehicle"] call ace_common_fnc_displayTextStructured;
} else {
    _unit = driver (vehicle _unit);
    private _state = (_unit getVariable ["VCOM_DisembarkExclude", false]);
    if (_state) then {        
        ["Group included in VCOM Disembark"] call ace_common_fnc_displayTextStructured;
    } else {
        ["Group excluded from VCOM Disembark"] call ace_common_fnc_displayTextStructured;
    };
    {
        _x setVariable ["VCOM_DisembarkExclude", !_state, true];
        false
    } count (crew (vehicle _unit));
};

deleteVehicle _logic;
