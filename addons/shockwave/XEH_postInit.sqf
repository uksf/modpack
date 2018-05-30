#include "script_component.hpp"

if (isNil QGVAR(exShakePFH)) then {
    GVAR(exShakePFH) = [{
        call FUNC(shockwaveHandler);
    }, 0.05] call CBA_fnc_addPerframeHandler;
};
