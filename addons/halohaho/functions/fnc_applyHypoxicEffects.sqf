#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs effects for Hypoxia

    Parameter(s):
        0: Player <OBJECT>

    Return Value:
        None
*/

params ["_player"];


[_player] spawn {
    params ["_player"];
    private _color = ppEffectCreate ["colorCorrections", 1001];
    private _blur = ppEffectCreate ["radialBlur", 1002];
    private _dynamicBlur = ppEffectCreate ["DynamicBlur", 1003];
    private _chroma = ppEffectCreate ["chromAberration", 1004];
    titleText ["", "BLACK OUT", 1];
    sleep 1;

    titleText ["", "BLACK IN", 1];
    _color ppEffectEnable true;
    _color ppEffectAdjust [0, 0, 0, [1.0, 0.0, 0.0, 0.2], [0, 1, 0, 0.5], [0, 0, 0, 0]];
    _color ppEffectCommit 2;
    _blur ppEffectEnable true;
    _blur ppEffectAdjust [0.001, 0.001, 0.15, 0.15];
    _dynamicBlur ppEffectEnable true;
    _dynamicBlur ppEffectAdjust [0.5];
    _chroma ppEffectEnable true;
    _chroma ppEffectAdjust [0.09, 0.09, true];
    _chroma ppEffectCommit 2;
    _blur ppEffectCommit 2;
    _dynamicBlur ppEffectCommit 2;
    titleText ["", "BLACK OUT", 1];
    sleep 1;

    titleText ["", "BLACK IN", 1];
    ppEffectDestroy _blur;
    ppEffectDestroy _dynamicBlur;
    ppEffectDestroy _chroma;
    ppEffectDestroy _color;

    GVAR(pain) = _player getVariable ["ace_medical_pain", 0];
    [_player, GVAR(pain) + 0.2] call ace_medical_fnc_adjustPainLevel;
};

