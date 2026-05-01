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
GVAR(suppression_cc) ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [1, 1, 1, 1], [1, 1, 1, 0]];
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
GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [1, 1, 1, 1], [1, 1, 1, 0]];
GVAR(suppression_impactCC) ppEffectEnable true;
GVAR(suppression_impactCC) ppEffectCommit 0;

GVAR(suppression_impactBlur) = ppEffectCreate ["RadialBlur", 1002];
GVAR(suppression_impactBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(suppression_impactBlur) ppEffectCommit 0;
GVAR(suppression_impactBlur) ppEffectEnable true;

[{call FUNC(shockwaveHandler)}, 0.05] call CBA_fnc_addPerframeHandler;
[{call FUNC(suppressionHandler)}, 0.05] call CBA_fnc_addPerFrameHandler;
[{call FUNC(suppressionRecovery)}, 1] call CBA_fnc_addPerFrameHandler;
[{call FUNC(suppressionPinnedDown)}, 0.5] call CBA_fnc_addPerFrameHandler;

// Close-miss reaction test keybind — unbound by default; assign in CBA
// keybindings menu under "UKSF". Triggers the reaction at severity 1
// (bypasses the adrenaline pool) with a random pass side, for tuning.
["UKSF", "uksf_immersion_closeMissTest", ["Close-miss test", "Trigger close-miss reaction at full severity, random side"],
    { [selectRandom [-1, 1], 1] call FUNC(closeMissReaction); false }, "", [0, [false, false, false]], false] call CBA_fnc_addKeybind;

#ifdef DEBUG_MODE_FULL
addMissionEventHandler ["Draw3D", {
    if (isNull ACE_player || {!alive ACE_player}) exitWith {};

    private _playerPos = ACE_player modelToWorld [0, 0, 1];

    // Threshold rings — pure red 1m base, pure blue 2m big-round.
    // Maximally distinct primaries; green/orange washed out against sky.
    private _segments = 32;
    {
        _x params ["_radius", "_color"];
        for "_i" from 0 to (_segments - 1) do {
            private _a1 = (_i / _segments) * 360;
            private _a2 = ((_i + 1) / _segments) * 360;
            private _p1 = _playerPos vectorAdd [(sin _a1) * _radius, (cos _a1) * _radius, 0];
            private _p2 = _playerPos vectorAdd [(sin _a2) * _radius, (cos _a2) * _radius, 0];
            drawLine3D [_p1, _p2, _color, 5];
        };
    } forEach [
        [1, [1, 0, 0, 1]],
        [2, [0, 0.4, 1, 1]]
    ];

    // Active traces. Trace entry: [_spawnASL, _closestASL, _hitFlag, _expiryTickTime, _label]
    private _now = diag_tickTime;
    private _alive = [];
    {
        _x params ["_spawnASL", "_closestASL", "_hitFlag", "_expiry", "_label"];
        if (_now > _expiry) then { continue };

        private _color = if (_hitFlag) then { [1, 0.1, 0.1, 1] } else { [1, 1, 0.2, 1] };
        drawLine3D [ASLToAGL _spawnASL, ASLToAGL _closestASL, _color, 6];
        drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _color, ASLToAGL _closestASL, 0.5, 0.5, 0, _label, 2, 0.05, "RobotoCondensed", "center"];

        _alive pushBack _x;
    } forEach GVAR(closeMiss_debugTraces);

    GVAR(closeMiss_debugTraces) = _alive;
}];
#endif
