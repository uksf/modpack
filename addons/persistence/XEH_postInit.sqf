#include "script_component.hpp"

if (isServer && {GVAR(dataSaved)}) then {
    [{
        [{
            call FUNC(loadVehicleData);
        }] call CBA_fnc_execNextFrame;
    }] call CBA_fnc_execNextFrame;
};
