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

if (!canSuspend) exitWith {
    [] spawn FUNC(applyHypoxiaEffects);
};

if (GVAR(hypoxiaLevel) >= GVAR(maxHypoxiaLevel)) then {
    ace_advanced_fatigue_anReserve = linearConversion [5, 80, GVAR(hypoxiaLevel), 2300, 10];
};

if (GVAR(hypoxiaLevel) < 15) exitWith {};

private _hypoxiaCoef = linearConversion [15, 100, GVAR(hypoxiaLevel), 0.5, 1.5];
private _effectDuration = 1 * _hypoxiaCoef;
private _recoveryDuration = 2.5 * _effectDuration;

private _painModifier = 0.05 * _hypoxiaCoef;
[player, _painModifier] call ace_medical_fnc_adjustPainLevel;

TRACE_5("Applying hypoxia effects",GVAR(hypoxiaLevel),_hypoxiaCoef,_effectDuration,_pain,_painModifier);

if (GVAR(hypoxiaLevel) > 60 && (random 2) > 1) then {
    titleText ["", "BLACK OUT", _effectDuration];
    sleep _effectDuration;
    titleText ["", "BLACK IN", _effectDuration / 2];
    sleep _effectDuration / 2;
};

GVAR(ppColour) ppEffectAdjust [1, 1, 0, [0.05 * _hypoxiaCoef, 0, 0, 0.45 * _hypoxiaCoef], [1, 1, 1, 0.15 / _hypoxiaCoef], [0, 0, 0, 0]];
GVAR(ppColour) ppEffectCommit _effectDuration;
GVAR(ppBlur) ppEffectAdjust [0.05 * _hypoxiaCoef, 0.05 * _hypoxiaCoef, 0.3 * _hypoxiaCoef, 0.3 * _hypoxiaCoef];
GVAR(ppBlur) ppEffectCommit _effectDuration;
GVAR(ppDynamicBlur) ppEffectAdjust [0.4 * _hypoxiaCoef];
GVAR(ppDynamicBlur) ppEffectCommit _effectDuration;
GVAR(ppChroma) ppEffectAdjust [0.02 * _hypoxiaCoef, 0.02 * _hypoxiaCoef, true];
GVAR(ppChroma) ppEffectCommit _effectDuration;
sleep _effectDuration;

GVAR(ppColour) ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
GVAR(ppColour) ppEffectCommit _recoveryDuration;

if (GVAR(hypoxiaLevel) > 40 && (random 2) > 1) then {
    titleText ["", "BLACK OUT", _effectDuration];
    sleep _effectDuration;
    titleText ["", "BLACK IN", _effectDuration / 2];
};
