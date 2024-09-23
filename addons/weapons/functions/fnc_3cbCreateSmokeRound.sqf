
#include "script_component.hpp"
/*
    Author:
        3CB, Tim Beswick

    Description:
        3CB Create Smoke Round function replacement

    Parameter(s):
        0: Projectile <OBJECT>
        1: Position <ARRAY>
        2: Ammo <STRING>

    Return Value:
        Nothing
*/
_this spawn {
    params ["_projectile", "_position", "_ammo"];

    private _wp = (_ammo regexFind ["WP"]) isNotEqualTo [];
    private _red = (_ammo regexFind ["Red"]) isNotEqualTo [];
    private _large = (_ammo regexFind ["81"]) isNotEqualTo [];

    private _type = 0;
    _type = _type + ([0, 1] select _wp);
    _type = _type + ([0, 1] select _red);

    private _lifespan = [90, 180] select _large;

    private _baseSmoke = ["UK3CB_SmokeShellMortarWhiteBase", "UK3CB_WPSmokeShellMortarWhiteBase", "UK3CB_SmokeShellMortarRedBase"] select _type;
    private _pillarSmoke = ["UK3CB_SmokeShellMortarWhitePillar", "UK3CB_WPSmokeShellMortarWhitePillar", "UK3CB_SmokeShellMortarRedPillar"] select _type;

    private _ps1 = "#particlesource" createVehicleLocal [_position#0, _position#1, 0];
    _ps1 setParticleClass _pillarSmoke;

    sleep 2;

    private _ps2 = "#particlesource" createVehicleLocal [(_position#0) + 7, (_position#1) + 0, 0];
    _ps2 setParticleClass _baseSmoke;

    private _ps3 = "#particlesource" createVehicleLocal [(_position#0) - 4, (_position#1) - 7, 0];
    _ps3 setParticleClass _baseSmoke;

    private _ps4 = "#particlesource" createVehicleLocal [(_position#0) - 4, (_position#1) + 7, 0];
    _ps4 setParticleClass _baseSmoke;

    if (hasInterface && _wp) then {
        private _endtime = time + _lifespan;
        _position = getPosATL _ps1;

        private _priority = 400;
        private ["_effect"];
        while {_effect = ppEffectCreate ["DynamicBlur", _priority]; _effect < 0} do {
            _priority = _priority + 1;
        };

        while {time < _endtime} do {
            if ((player distance _position) < 12) then {
                _effect ppEffectEnable true;
                _effect ppEffectAdjust [5];
                _effect ppEffectCommit 2;
            } else {
                _effect ppEffectAdjust [0];
                _effect ppEffectCommit 2;
            };
            sleep 1;
        };

        _effect ppEffectEnable false;
        ppEffectDestroy _effect;
    } else {
        sleep _lifespan;
    };

    deleteVehicle _ps1;
    deleteVehicle _ps2;
    deleteVehicle _ps3;
    deleteVehicle _ps4;
};
