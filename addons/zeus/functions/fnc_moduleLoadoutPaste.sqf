/*
    Author:
        Tim Beswick

    Description:
        Paste loadout from global variable to unit

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
if (_typeName != "OBJECT" || {!(_unit isKindOf "CAManBase")} || {!(alive _unit)}) then {
    ["Place on a living unit"] call ace_common_fnc_displayTextStructured;
} else {
    if (GVAR(loadout) isEqualTo "") then {
        ["Copy a loadout first"] call ace_common_fnc_displayTextStructured;
    } else {
        _unit setUnitLoadout GVAR(loadout);
        ["Loadout pasted"] call ace_common_fnc_displayTextStructured;
    };
};
