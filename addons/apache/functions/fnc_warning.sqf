#include "script_component.hpp"
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

params ["_heli"];

GVAR(soundHandler) = [{
    params ["_args"];
    _args params ["_heli"];

    private _damage = _heli getHitPointDamage "HitVRotor";
    if (_damage > (_heli getVariable [QGVAR(previousTailDamage), 0])) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(tailrotorDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(tailrotorFailure), 1.8] call FUNC(audio);
            };
        };
        _heli setVariable [QGVAR(previousTailDamage), _damage, true];
    };

    _damage = _heli getHitPointDamage "HitHRotor";
    if (_damage > (_heli getVariable [QGVAR(previousMainDamage), 0])) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(mainrotorDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(mainrotorFailure), 1.8] call FUNC(audio);
            };
        };
        _heli setVariable [QGVAR(previousMainDamage), _damage, true];
    };

    _damage = _heli getHitPointDamage "HitEngine1";
    if (_damage > (_heli getVariable [QGVAR(previousE1Damage), 0])) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(engineOneDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(engineOneFailure), 1.7] call FUNC(audio);
            };
        };
        _heli setVariable [QGVAR(previousE1Damage), _damage, true];
    };

    _damage = _heli getHitPointDamage "HitEngine2";
    if (_damage > (_heli getVariable [QGVAR(previousE2Damage), 0])) then {
        if (_damage > 0.4) then {
            if (_damage < 0.8) then {
                [QGVAR(engineTwoDamaged), 1.7] call FUNC(audio);
            } else {
                [QGVAR(engineTwoFailure), 1.7] call FUNC(audio);
            };
        };
        _heli setVariable [QGVAR(previousE2Damage), _damage, true];
    };

    _damage = _heli getHitPointDamage "HitGun";
    if (_damage > (_heli getVariable [QGVAR(previousGunDamage), 0])) then {
        if (_damage >= 0.8) then {
            _heli removemagazine "UK3CB_BAF_1200Rnd_30mm_M230_HEDP_T";
            _heli addmagazine "UK3CB_BAF_JAM_30mm_M230_HEDP_T";

            [QGVAR(gunActuatorFailure), 1.9] call FUNC(audio);
        };
        _heli setVariable [QGVAR(previousGunDamage), _damage, true];
    };

    _damage = _heli getHitPointDamage "HitAvionics";
    if (_damage > (_heli getVariable [QGVAR(previousInsDamage), 0])) then {
        if (_damage >= 0.8) then {
            [QGVAR(instrumentFailure), 1.7] call FUNC(audio);
        };
        _heli setVariable [QGVAR(previousInsDamage), _damage, true];
    };
}, 3, [_heli]] call cba_fnc_addPerFrameHandler;
