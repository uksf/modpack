/*
    Author:
        Tim Beswick

    Description:
        Toggles allow unconcious on AI (ACE variable "ace_medical_enableUnconsciousnessAI")

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

(missionNamespace getVariable ["bis_fnc_curatorObjectPlaced_mouseOver", [""]]) params ["_typeName", "_unit"];
if (_typeName != "OBJECT" || {!(_unit isKindOf "CAManBase")} || {isPlayer _unit}) then {
    ["Place on an AI unit"] call ace_common_fnc_displayTextStructured;
} else {
    private _state = _unit getVariable ["ace_medical_enableUnconsciousnessAI", ace_medical_enableUnconsciousnessAI];
    if (_state != 2) then {
        if (_state isEqualTo 0) then {
            _unit setVariable ["ace_medical_enableUnconsciousnessAI", 1, true];
            ["Unit unconciousness set to '50/50'"] call ace_common_fnc_displayTextStructured;
        } else {
            _unit setVariable ["ace_medical_enableUnconsciousnessAI", 0, true];
            ["Unit unconciousness set to 'Disabled'"] call ace_common_fnc_displayTextStructured;
        };
    };
};

deleteVehicle _logic;
