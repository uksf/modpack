#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Variant D: layered effect. Small physical impulse + small yaw flinch +
        moderate fatigue spike + brief PP tunnel. None overpowering on its
        own; aiming for cumulative "discombobulated" feel without any single
        cue dominating.

    Parameters:
        0: Severity <SCALAR> (0..1)

    Return value:
        None

    Example:
        [1] call uksf_immersion_fnc_debugCloseMiss_combined
*/
params [["_severity", 1, [0]]];

// Impulse (smaller than variant A)
private _magnitude = _severity * 40;
private _dir = getDir ACE_player;
private _side = selectRandom [-1, 1];
private _perp = [sin (_dir + 90 * _side), cos (_dir + 90 * _side), 0];
private _impulse = _perp vectorMultiply _magnitude;
ACE_player addForce [_impulse, ACE_player selectionPosition "head", false];

// Yaw flinch (smaller than variant B)
private _flinch = (_severity * (0.5 + random 0.5)) * selectRandom [-1, 1];
ACE_player setDir ((getDir ACE_player) + _flinch);

// Fatigue (smaller than variant C)
private _newFatigue = ((getFatigue ACE_player) + (_severity * 0.2)) min 1;
ACE_player setFatigue _newFatigue;

// Brief PP tunnel cue (radial blur with vignette offset, fades fast)
private _rBlur = ppEffectCreate ["RadialBlur", 1850];
_rBlur ppEffectEnable true;
_rBlur ppEffectAdjust [_severity * 0.04, _severity * 0.04, 0.08, 0.08];
_rBlur ppEffectCommit 0.05;

[{
    params ["_handle"];
    _handle ppEffectAdjust [0, 0, 0, 0];
    _handle ppEffectCommit 0.4;
    [{
        params ["_handle"];
        _handle ppEffectEnable false;
        ppEffectDestroy _handle;
    }, [_handle], 0.5] call CBA_fnc_waitAndExecute;
}, [_rBlur], 0.2] call CBA_fnc_waitAndExecute;

systemChat format ["[immersion debug D] combined: force=%1 flinch=%2 fatigue+%3", _magnitude, _flinch, _severity * 0.2];
