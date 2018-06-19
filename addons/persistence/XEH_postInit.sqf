#include "script_component.hpp"

if (isServer && {GVAR(enabled)}) then {
    [{
        [{
            call FUNC(loadVehicleData);
        }] call CBA_fnc_execNextFrame;
    }] call CBA_fnc_execNextFrame;
};
