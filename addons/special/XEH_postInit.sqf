#include "script_component.hpp"

if (isServer) then {
    ["UKSF_Target_Moving", "init", {
        (_this select 0) setVariable [QGVAR(startPosition), position (_this select 0), true];
    }, false, [], true] call CBA_fnc_addClassEventHandler;
};
