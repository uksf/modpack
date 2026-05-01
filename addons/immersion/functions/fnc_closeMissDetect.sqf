#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Detects whether a fired projectile will pass within the close-miss
        threshold of the local player using closest-approach prediction
        from spawn position and velocity. If predicted to pass within
        threshold, schedules the reaction at the predicted time of closest
        approach. Threshold widens for high-hit ammo (.50 cal+).

        When closeMiss_debug is enabled, near misses (within 2x threshold)
        are recorded for visualisation and logged.

    Parameters:
        0: Ammo class <STRING>
        1: Projectile <OBJECT>

    Return value:
        None

    Example:
        [_ammo, _projectile] call uksf_immersion_fnc_closeMissDetect
*/
params ["_ammo", "_projectile"];

if (isNull _projectile) exitWith {};

private _projVel = velocity _projectile;
private _v2 = _projVel vectorDotProduct _projVel;
if (_v2 < 1) exitWith {};

private _player = GVAR(suppression_currentUnit);
if (isNull _player || {!alive _player}) exitWith {};

private _projPos = getPosASL _projectile;
private _playerPos = eyePos _player;
private _relPos = _projPos vectorDiff _playerPos;

private _t = -((_relPos vectorDotProduct _projVel) / _v2);
if (_t < 0 || {_t > CLOSEMISS_MAX_LOOKAHEAD_SEC}) exitWith {};

private _closestOffset = _relPos vectorAdd (_projVel vectorMultiply _t);
private _closestDist = vectorMagnitude _closestOffset;

private _hit = [[QGVAR(hit_), _ammo] joinString "", {EGVAR(common,configAmmo) >> _ammo >> "hit"}] call EFUNC(common,readCacheValues);
private _threshold = if (_hit >= CLOSEMISS_BIG_HIT_THRESHOLD) then { CLOSEMISS_DETECTION_BIG } else { CLOSEMISS_DETECTION_BASE };
private _hitFlag = _closestDist <= _threshold;

TRACE_5("closeMiss detect",_ammo,_hit,_t,_closestDist,_threshold);

#ifdef DEBUG_MODE_FULL
if (_closestDist <= (_threshold * 2)) then {
    private _closestASL = _playerPos vectorAdd _closestOffset;
    private _label = format ["%1 d=%2m t=%3s hit=%4", _ammo, _closestDist toFixed 2, _t toFixed 2, _hit];
    GVAR(closeMiss_debugTraces) pushBack [_projPos, _closestASL, _hitFlag, diag_tickTime + 5, _label];
};
#endif

if (!_hitFlag) exitWith {};

private _playerRight = (vectorDir _player) vectorCrossProduct [0, 0, 1];
private _sideValue = _closestOffset vectorDotProduct _playerRight;
private _bulletSide = if (_sideValue > 0) then { 1 } else { -1 };

TRACE_3("closeMiss detect schedule",_bulletSide,_closestDist,_t);

[FUNC(closeMissReaction), [_bulletSide], _t] call CBA_fnc_waitAndExecute;
