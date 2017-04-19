/*
    Author:
        Tim Beswick

    Description:
        Copy loadout of unit to global variable

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
if (_typeName != "OBJECT" || {!(_unit isKindOf "CAManBase")}) then {
    ["Place on a unit"] call ace_common_fnc_displayTextStructured;
} else {
    GVAR(loadout) = getUnitLoadout _unit;
};

deleteVehicle _logic;
