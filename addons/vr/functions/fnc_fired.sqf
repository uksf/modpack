/* 
    Author:
        Tim Beswick

    Description:
        Refills ammo for VR training units

    Parameters:
        0: Unit <OBJECT>
        1: Weapon <STRING>
        2: Muzzle <STRING>
        3: Fire mode <STRING>
        4: Ammo <STRING>
        5: Magazine <STRING>
        6: Projectile <OBJECT>

    Return value:
        Nothing
*/ 
#include "script_component.hpp"

#define BASE_ROUNDS ["B_556x45_Ball","CUP_B_762x51_Tracer_White","CUP_B_762x51_Tracer_Red","B_762x51_Tracer_Red","B_127x99_Ball_Tracer_Red","CUP_R_SMAW_HEAA_N","Sh_120mm_APFSDS_Tracer_Red","Sh_120mm_HE_Tracer_Red","CUP_B_25mm_HE_Red_Tracer","CUP_B_25mm_APFSDS_Red_Tracer"]
#define REPLACE_ROUNDS ["B_556x45_Ball_Rubber","CUP_B_762x51_Tracer_White_Rubber","CUP_B_762x51_Tracer_White_Rubber","CUP_B_762x51_Tracer_White_Rubber","B_127x99_Ball_Tracer_White_Rubber","CUP_R_SMAW_HEAT_N_Rubber","Sh_120mm_APFSDS_Tracer_White_Rubber","Sh_120mm_HE_Tracer_White_Rubber","CUP_B_25mm_HE_White_Tracer_Rubber","CUP_B_25mm_APFSDS_White_Tracer_Rubber"]
#define LAUNCHER_MAGAZINES ["CUP_SMAW_HEAA_M","CUP_Stinger_M_Rubber"]

params ["_unit", "", "", "", "", "_magazine", "_projectile"];

private _index = BASE_ROUNDS find (typeOf _projectile);
if (_index > -1) then {
    private _position = getPosATL _projectile;
    private _vectorDir = vectorDir _projectile;
    private _vectorUp = vectorUp _projectile;
    private _velocity = velocity _projectile;
    deleteVehicle _projectile;

    private _newProjectile = (REPLACE_ROUNDS select _index) createVehicle (_position vectorAdd (_velocity vectorMultiply 0.1));
    _newProjectile setVectorDir _vectorDir;
    _newProjectile setVectorUp _vectorUp;
    _newProjectile setVelocity _velocity;
};

_unit setAmmo [currentWeapon _unit, 10];
_unit setVehicleAmmo 1;
if (_magazine in LAUNCHER_MAGAZINES) then {
    _unit addMagazine _magazine;
};
