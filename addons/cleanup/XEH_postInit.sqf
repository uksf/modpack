#include "script_component.hpp"

if (isServer) then {
    [QGVAR(addKilled), {GVAR(killed) pushback [_this, CBA_missionTime]}] call CBA_fnc_addEventHandler;
};
