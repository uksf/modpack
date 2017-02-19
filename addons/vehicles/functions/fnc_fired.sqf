/*
    Author:
        Tim Beswick

    Description:
        Deletes empty magazines

    Parameters:
        0: Vehicle <OBJECT>
        1: Weapon <String>
        2: Muzzle <String>
        3: Fire mode <String>
        4: Ammo <String>
        5: Magazine <String>
        6: Projectile <OBJECT>

    Return value:
        Nothing
*/ 
#include "script_component.hpp"

params ["_vehicle", "_weapon", "", "", "", "_magazine", ""];

private _turret = [];
{
    if ((_vehicle currentWeaponTurret _x) isEqualTo _weapon) exitWith {
        _turret = _x;
    };
    false
} count (allTurrets _vehicle);

if ((count _turret) > 0) then {
    if ((_vehicle magazineTurretAmmo [_magazine, _turret]) isEqualTo 0) then {
        _vehicle removeMagazineTurret [_magazine, _turret];    
    };

    if ((player isEqualTo _vehicle turretUnit _turret) && {cameraView != "EXTERNAL"})  then {
        enableCamShake true;
        if (_weapon in ["CUP_Vhmg_M2_static", "CUP_Vgmg_MK19_veh", "CUP_Vlmg_M240_veh"]) then {
            addCamShake [0.25, 0.5, 25];
        };
    };
};
