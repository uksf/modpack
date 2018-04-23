#include "script_component.hpp"

ADDON = false;

["UKSF_B_Rifleman", "init", {
    params ["_unit"];
    if (local _unit) then {
        _unit setUnitTrait ["audibleCoef", 0.7];
    };
}, true, [], true] call CBA_fnc_addClassEventHandler;

[QEGVAR(lobby,respawned), {
    player setUnitTrait ["audibleCoef", 0.7];
}] call CBA_fnc_addEventHandler;

ADDON = true;
