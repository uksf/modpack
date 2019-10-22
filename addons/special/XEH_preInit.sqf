#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(movingTarget), {call FUNC(movingTarget)}] call CBA_fnc_addEventHandler;

if (isServer) then {
    ["UKSF_Target_Moving", "init", {
        params ["_target"];
        _target setVariable [QGVAR(startPosition), position _target, true];
    }, false] call CBA_fnc_addClassEventHandler;
};

ADDON = true;
