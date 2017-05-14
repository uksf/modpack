/*
    Author:
        Tim Beswick

    Description:
        Toggles unit cache state

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
    private _unit = effectivecommander _unit;
    if !(_unit isKindOf "CAManBase") then {
        ["Unit must be infantry"] call ace_common_fnc_displayTextStructured;
    } else {
        if !(alive _unit) then {
            ["Unit must be alive"] call ace_common_fnc_displayTextStructured;
        } else {
            if (!((group _unit) getVariable [QGVAR(excluded), false])) then {
                [_unit] call FUNC(disableCache);
                ["Group excluded from caching"] call ace_common_fnc_displayTextStructured;
            } else {
                (group _unit) setVariable [QGVAR(excluded), false, true];
                ["Group included in caching"] call ace_common_fnc_displayTextStructured;
            };
        };
    };
};

deleteVehicle _logic;
