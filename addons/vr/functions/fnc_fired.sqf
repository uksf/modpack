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

#define LAUNCHER_MAGAZINES ["CUP_SMAW_HEAT_M_Rubber","CUP_Stinger_M_Rubber"]

params ["_unit", "", "", "", "", "_magazine"];

_unit setAmmo [currentWeapon _unit, 10];
_unit setVehicleAmmo 1;
if (_magazine in LAUNCHER_MAGAZINES) then {
    _unit addMagazine _magazine;
};
