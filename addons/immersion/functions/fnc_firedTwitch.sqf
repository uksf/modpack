#include "script_component.hpp"
/*
    Author:
        joko, Tim Beswick

    Description:
        Twitch Fired Event Handler

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/
params ["_shooter", "", "", "", "_ammo", "", "", "_ammoConfig"];

if (player == _shooter || {(vehicle player) != player}) exitWith {};

private _dist = ((positionCameraToWorld [0,0,0]) distance _shooter);
if (_dist > 60) exitWith {};

private _caliber = [_ammoConfig >> "caliber", QGVAR(twitch_) + _ammo, 0] call FUNC(readCacheValues);

if (isNil "_caliber" || {_caliber isEqualTo 0}) exitWith {};

if (_caliber isEqualType "") then {
    _caliber = getNumber (_ammoConfig >> "caliber");
    GVAR(variableHandler) setVariable [QGVAR(twitch_) + _ammo, _caliber];
};

private _maxDist = 14 + (_caliber / 1.1);
private _intensity = _dist / _maxDist;
if (_intensity >= 1) exitWith {};
_intensity = 1 - _intensity;

private _force = (0.4 + (_caliber / 23)) * _intensity;
private _length = (0.2 + (_caliber / 45));
private _frequency = (35 + (_caliber / 6)) * _intensity;

if (_force < 0) then {_force = 0;};
if (_length < 0) then {_length = 0;};
if (_frequency < 0) then {_frequency = 0;};

addCamShake [_force, _length, _frequency];

if (_caliber > 2.1) then {
    if (_intensity > 0.6) then {
        private _blurStrength = (0.45 + (_caliber * 0.03)) * _intensity;
        private _dBlur = ppEffectCreate ["DynamicBlur", 500];
        _dBlur ppEffectEnable true;
        _dBlur ppEffectAdjust [_blurStrength];
        _dBlur ppEffectCommit 0;
        _dBlur ppEffectAdjust [0];
        _dBlur ppEffectCommit 0.8;

        [{ppEffectDestroy _this;}, _dBlur, 0.8] call CBA_fnc_waitAndExecute;
    };
};
