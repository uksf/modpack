/*
    Author:
        Tim Beswick

    Description:
        Runs warning loop for damage

    Parameters:
        0: Heli <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_heli"];

GVAR(soundHandler) = [{
    params ["_args", "_idPFH"];
    _args params ["_heli"];

    private _damage = _heli getHitPointDamage "HitVRotor";
    if (_damage > GVAR(previousTailDamage)) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(tailrotorDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(tailrotorFailure), 1.8] call FUNC(audio);
            };
        };
        GVAR(previousTailDamage) = _damage;
    };

    _damage = _heli getHitPointDamage "HitHRotor";
    if (_damage > GVAR(previousMainDamage)) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(mainrotorDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(mainrotorFailure), 1.8] call FUNC(audio);
            };
        };
        GVAR(previousMainDamage) = _damage;
    };

    _damage = _heli getHitPointDamage "HitEngine1";
    if (_damage > GVAR(previousE1Damage)) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(engineOneDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(engineOneFailure), 1.7] call FUNC(audio);
            };
        };
        GVAR(previousE1Damage) = _damage;
    };

    _damage = _heli getHitPointDamage "HitEngine2";
    if (_damage > GVAR(previousE2Damage)) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(engineTwoDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(engineTwoFailure), 1.7] call FUNC(audio);
            };
        };
        GVAR(previousE2Damage) = _damage;
    };

    _damage = _heli getHitPointDamage "HitGun";
    if (_damage > GVAR(previousGunDamage)) then {
        if (_damage >= 0.8) then {
            _heli removemagazine "UK3CB_BAF_1200Rnd_30mm_M230_HEDP_T";
            _heli addmagazine "UK3CB_BAF_JAM_30mm_M230_HEDP_T";
            
            [QGVAR(gunActuatorFailure), 1.9] call FUNC(audio);
        };
        GVAR(previousGunDamage) = _damage;
    };

    _damage = _heli getHitPointDamage "HitAvionics";
    if (_damage > GVAR(previousInsDamage)) then {
        if (_damage >= 0.8) then {
            [QGVAR(instrumentFailure), 1.7] call FUNC(audio);
        };
        GVAR(previousInsDamage) = _damage;
    };
}, 3, [_heli]] call cba_fnc_addPerFrameHandler;
