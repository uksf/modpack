/*
    Author:
        Tim Beswick

    Description:
        Sets unit to include in cache and caches

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "_units", "_activated"];
private ["_mouseOver", "_unit", "_excluded"];

if !(_activated && local _logic) exitWith {};

_mouseOver = missionNamespace getVariable ["bis_fnc_curatorObjectPlaced_mouseOver", [""]];
if ((_mouseOver select 0) != "OBJECT") then {
    [QUOTE(Place on a unit)] call ace_common_fnc_displayTextStructured;
} else {
    _unit = effectivecommander (_mouseOver select 1);

    if !(_unit isKindOf "CAManBase") then {
        [QUOTE(Unit must be infantry)] call ace_common_fnc_displayTextStructured;
    } else {
        if !(alive _unit) then {
            [QUOTE(Unit must be alive)] call ace_common_fnc_displayTextStructured;
        } else {
            _excluded = (group _unit) getVariable [QGVAR(excluded), false];
            if (_excluded) then {
                (group _unit) setVariable [QGVAR(excluded), false, true];
            };
        };
    };
};

deleteVehicle _logic;
