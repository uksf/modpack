/* 
    Author:
        Tim Beswick, John_Spartan, Saul, USAF Team

    Description:
        Handles fired event for special ammo

    Parameters:
        0: Plane <OBJECT>
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

params ["_plane", "", "", "", "_ammo", "", "_projectile"];

if (local _plane) then {
    if (_ammo isEqualTo "USAF_F35A_GBU53_A") then {
        [_projectile] spawn USAF_F35A_fnc_GBU53;
    };
};
