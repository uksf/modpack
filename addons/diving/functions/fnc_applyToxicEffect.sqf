#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Applies a toxic visual effect with configurable colour, blur, and optional pain

    Parameter(s):
        0: Colour tint <ARRAY> - [r, g, b, a]
        1: Radial blur <ARRAY> - [x, y, width, height]
        2: Chromatic aberration <NUMBER>
        3: Commit time <NUMBER> - seconds for effect transition
        4: Pain amount <NUMBER> - 0 for no pain

    Return Value:
        None

    Example:
        [[1, 0, 0, 0.2], [0.001, 0.001, 0.15, 0.15], 0.09, 2, 0.1] call uksf_diving_fnc_applyToxicEffect
*/
params ["_colourTint", "_radialBlur", "_chromaAmount", "_commitTime", "_painAmount"];

[_colourTint, _radialBlur, _chromaAmount, _commitTime, _painAmount] spawn {
    params ["_colourTint", "_radialBlur", "_chromaAmount", "_commitTime", "_painAmount"];

    private _colour = ppEffectCreate ["colorCorrections", 1001];
    private _blur = ppEffectCreate ["radialBlur", 1002];
    private _dynamicBlur = ppEffectCreate ["DynamicBlur", 1003];
    private _chroma = ppEffectCreate ["chromAberration", 1004];
    cutText ["", "BLACK OUT", 1];
    sleep 1;

    cutText ["", "BLACK IN", 1];
    _colour ppEffectEnable true;
    _colour ppEffectAdjust [1, 1, 0, _colourTint, [0, 1, 0, 0.5], [0, 0, 0, 0]];
    _colour ppEffectCommit _commitTime;
    _blur ppEffectEnable true;
    _blur ppEffectAdjust _radialBlur;
    _dynamicBlur ppEffectEnable true;
    _dynamicBlur ppEffectAdjust [0.5];
    _chroma ppEffectEnable true;
    _chroma ppEffectAdjust [_chromaAmount, _chromaAmount, true];
    _chroma ppEffectCommit _commitTime;
    _blur ppEffectCommit _commitTime;
    _dynamicBlur ppEffectCommit _commitTime;
    cutText ["", "BLACK OUT", 1];
    sleep 1;

    cutText ["", "BLACK IN", 1];
    ppEffectDestroy _blur;
    ppEffectDestroy _dynamicBlur;
    ppEffectDestroy _chroma;
    ppEffectDestroy _colour;

    if (_painAmount > 0) then {
        private _pain = player getVariable ["ace_medical_pain", 0];
        [player, _pain + _painAmount] call ace_medical_fnc_adjustPainLevel;
    };
};
