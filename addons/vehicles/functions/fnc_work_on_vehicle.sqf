/*
    Author:
        Tim Beswick

    Description:
        Performs work on vehicle.

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Animation Source <STRING>
        2: Animation end phase <SCALAR>
        3: Label <STING>

    Return Value:
        None
*/
#include "script_component.hpp"

_this spawn {
    params ["_veh", "_animationSource", "_endPhase", "_label"];

    private _duration = getNumber(configFile >> "CfgVehicles" >> (typeOf _veh) >> "AnimationSources" >> _animationSource >> "animPeriod");
    player playMove "acts_carfixingwheel";
    _veh animateSource [_animationSource, _endPhase];
    private _progressBar = [_duration, _label] call UK3CB_BAF_Vehicles_Weapons_fnc_progress_bar;
    private _playerAnimation = ((primaryWeapon player) isEqualTo (currentWeapon player));
    private _phase = _veh animationSourcePhase _animationSource;
    while { _phase != _endPhase } do {
        if !([_veh] call UK3CB_BAF_Vehicles_Weapons_fnc_can_work_on_vehicle) exitWith {
            _veh animateSource [_animationSource, 1 - _endPhase, 10];
            [_progressBar] call UK3CB_BAF_Vehicles_Weapons_fnc_kill_progress_bar;
        };

        if (_playerAnimation) then {
            if ((animationState player) != "acts_carfixingwheel") then {
                player switchMove "acts_carfixingwheel";
            };
        };

        sleep 0.1;
        _phase = _veh animationSourcePhase _animationSource;
    };
    player switchMove "";
};
