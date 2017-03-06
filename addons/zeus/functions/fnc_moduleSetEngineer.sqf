/*
    Author:
        Tim Beswick

    Description:
        Sets unit to ACE engineer

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
    ["Place on a unit"] call ace_common_fnc_displayTextStructured;
} else {
    _unit = effectivecommander _unit;
    if !(_unit isKindOf "CAManBase") then {
            ["Place on a unit"] call ace_common_fnc_displayTextStructured;
    } else {
        if !(alive _unit) then {
            ["Place on a living unit"] call ace_common_fnc_displayTextStructured;
        } else {
            _engineer = [_unit] call ace_repair_fnc_isEngineer;
            if (!_engineer) then {
                _unit setVariable ["ACE_IsEngineer", true, true];
                ["Unit set as Engineer"] call ace_common_fnc_displayTextStructured;
            };
        };
    };
};

deleteVehicle _logic;
