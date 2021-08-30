#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs effects for toxic N2

    Parameter(s):
        None

    Return Value:
        None
*/

[] spawn {
    private _color = ppEffectCreate ["colorCorrections", 1001];
    private _blur = ppEffectCreate ["radialBlur", 1002];
    private _dynamicBlur = ppEffectCreate ["DynamicBlur", 1003];
    private _chroma = ppEffectCreate ["chromAberration", 1004];
    titleText ["", "BLACK OUT", 1];
    sleep 1;

    titleText ["", "BLACK IN", 1];
    _color ppEffectEnable true;
    _color ppEffectAdjust [1, 1, 0, [0.6, 0.3, 0.3, 0.2], [0, 1, 0, 0.5], [0, 0, 0, 0]];
    _color ppEffectCommit 2;
    _blur ppEffectEnable true;
    _blur ppEffectAdjust [0.01, 0.01, 0.03, 0.03];
    _dynamicBlur ppEffectEnable true;
    _dynamicBlur ppEffectAdjust [0.5];
    _chroma ppEffectEnable true;
    _chroma ppEffectAdjust [0.15, 0.15, true];
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
};
