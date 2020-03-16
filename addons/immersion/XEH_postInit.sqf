#include "script_component.hpp"

if (isNil QGVAR(exShakePFH)) then {
    GVAR(exShakePFH) = [{
        call FUNC(shockwaveHandler);
    }, 0.05] call CBA_fnc_addPerframeHandler;
};

GVAR(force_lastShot) = -1;
GVAR(force_multiplier) = 0;

GVAR(force_CC) = ppEffectCreate ["colorCorrections", 1799];
GVAR(force_CC) ppEffectEnable true;
GVAR(force_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
GVAR(force_CC) ppEffectCommit 0;

GVAR(force_RBlur) = ppEffectCreate ["RadialBlur", 1939];
GVAR(force_RBlur) ppEffectEnable true;
GVAR(force_RBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(force_RBlur) ppEffectCommit 0;
