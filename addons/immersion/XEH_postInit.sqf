#include "script_component.hpp"

GVAR(firing_lastShot) = -1;
GVAR(firing_multiplier) = 0;

GVAR(firing_CC) = ppEffectCreate ["colorCorrections", 1799];
GVAR(firing_CC) ppEffectEnable true;
GVAR(firing_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
GVAR(firing_CC) ppEffectCommit 0;

GVAR(firing_RBlur) = ppEffectCreate ["RadialBlur", 1939];
GVAR(firing_RBlur) ppEffectEnable true;
GVAR(firing_RBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(firing_RBlur) ppEffectCommit 0;

GVAR(suppression_cc) = ppEffectCreate ["colorCorrections", 1501];
GVAR(suppression_cc) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
GVAR(suppression_cc) ppEffectEnable true;
GVAR(suppression_cc) ppEffectCommit 0;

GVAR(suppression_blur) = ppEffectCreate ["DynamicBlur", 800];
GVAR(suppression_blur) ppEffectAdjust [0];
GVAR(suppression_blur) ppEffectCommit 0.3;
GVAR(suppression_blur) ppEffectEnable true;

GVAR(suppression_rBlur) = ppEffectCreate ["RadialBlur", 1003];
GVAR(suppression_rBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(suppression_rBlur) ppEffectCommit 0;
GVAR(suppression_rBlur) ppEffectEnable true;

GVAR(suppression_impactCC) = ppEffectCreate ["colorCorrections", 1499];
GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
GVAR(suppression_impactCC) ppEffectEnable true;
GVAR(suppression_impactCC) ppEffectCommit 0;

GVAR(suppression_impactBlur) = ppEffectCreate ["RadialBlur", 1002];
GVAR(suppression_impactBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(suppression_impactBlur) ppEffectCommit 0;
GVAR(suppression_impactBlur) ppEffectEnable true;

[{call FUNC(shockwaveHandler)}, 0.05] call CBA_fnc_addPerframeHandler;
[{call FUNC(suppressionHandler)}] call CBA_fnc_addPerFrameHandler;
[{call FUNC(suppressionRecovery)}, 1] call CBA_fnc_addPerFrameHandler;
[{call FUNC(suppressionPinnedDown)}, 0.5] call CBA_fnc_addPerFrameHandler;
