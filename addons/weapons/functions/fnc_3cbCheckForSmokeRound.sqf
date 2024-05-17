
#include "script_component.hpp"
/*
    Author:
        3CB, Tim Beswick

    Description:
        3CB Check For Smoke Round function replacement

    Parameter(s):
        0: Projectile <OBJECT>
        1: Ammo <STRING>

    Return Value:
        Nothing
*/
params ["_projectile", "_ammo"];

private _types = ["UK3CB_BAF_Smoke_60mm_AMOS", "UK3CB_BAF_Smoke_81mm_AMOS", "UK3CB_BAF_WPSmoke_60mm_AMOS", "UK3CB_BAF_WPSmoke_81mm_AMOS", "UK3CB_BAF_SmokeRed_60mm_AMOS", "UK3CB_BAF_SmokeRed_81mm_AMOS"];

if !(_ammo in _types) exitWith {false};

[_projectile, _ammo] spawn {
    params ["_projectile", "_ammo"];

    sleep 2;

    private _position = [0,0,0];
    private _next = [0,0,0];
    waitUntil {
        sleep 0.1;
        _position = _next;
        _next = getPosATL _projectile;
        (_next select 2) < 1.0
    };

    [_projectile, _position, _ammo] remoteExecCall ["UK3CB_BAF_Weapons_Ammo_fnc_create_smoke_round"];
};

true
