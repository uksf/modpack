#include "script_component.hpp"

if (isServer) then {
    missionNamespace setVariable [QGVAR(killed), [], true];
    [{
        call FUNC(cleanupCheck);
    }, [], 5] call CBA_fnc_waitAndExecute;
};
