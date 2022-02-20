#include "script_component.hpp"
/*
    Author:
        Tim Beswick, Bridg

    Description:
        Adds effects for hypoxia

    Parameter(s):
        None

    Return Value:
        Nothing
*/

if !(canSuspend) exitWith {
    [] spawn FUNC(applyHypoxiaEffects);
};

if (GVAR(hypoxiaLevel) == 0) exitWith {};

private _hypoxiaCoef = linearConversion [1, 100, GVAR(hypoxiaLevel), 0.5, 1.5];
private _effectDelay = 1 * _hypoxiaCoef;
private _commitDuration = 2 / _hypoxiaCoef;

private _pain = player getVariable ["ace_medical_pain", 0];
private _painModifier = 0.2 * _hypoxiaCoef;
[player, _pain + _painModifier] call ace_medical_fnc_adjustPainLevel;

titleText ["", "BLACK OUT", _effectDelay];
sleep _effectDelay;
titleText ["", "BLACK IN", _effectDelay];

private _color = ppEffectCreate ["colorCorrections", 1001];
private _blur = ppEffectCreate ["radialBlur", 1002];
private _dynamicBlur = ppEffectCreate ["DynamicBlur", 1003];
private _chroma = ppEffectCreate ["chromAberration", 1004];
_color ppEffectEnable true;
_color ppEffectAdjust [0, 0, 0, [1 * _hypoxiaCoef, 0, 0, 0.2 * _hypoxiaCoef], [0, 1 * _hypoxiaCoef, 0, 0.5 * _hypoxiaCoef], [0, 0, 0, 0]];
_color ppEffectCommit _commitDuration;
_blur ppEffectEnable true;
_blur ppEffectAdjust [0.001 * _hypoxiaCoef, 0.001 * _hypoxiaCoef, 0.15 * _hypoxiaCoef, 0.15 * _hypoxiaCoef];
_blur ppEffectCommit _commitDuration;
_dynamicBlur ppEffectEnable true;
_dynamicBlur ppEffectAdjust [0.5 * _hypoxiaCoef];
_dynamicBlur ppEffectCommit _commitDuration;
_chroma ppEffectEnable true;
_chroma ppEffectAdjust [0.09 * _hypoxiaCoef, 0.09 * _hypoxiaCoef, true];
_chroma ppEffectCommit _commitDuration;

titleText ["", "BLACK OUT", _effectDelay];
sleep _effectDelay;
titleText ["", "BLACK IN", _effectDelay];

ppEffectDestroy _blur;
ppEffectDestroy _dynamicBlur;
ppEffectDestroy _chroma;
ppEffectDestroy _color;
