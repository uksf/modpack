#include "script_component.hpp"
/*
    Author:
        Tim Beswick, MadMax

    Description:
        Checks if player is in water and swaps goggles accordingly.
        Mod goggles are cosmetic on land, vanilla G_B_Diving work underwater.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_diving_fnc_surfaceCheck
*/

private _goggles = goggles player;
if (_goggles isNotEqualTo QGVAR(divingMask) && _goggles isNotEqualTo "G_B_Diving") exitWith {};

private _inWater = surfaceIsWater (position player) && (position player select 2) < 0;

if (_inWater) then {
    if (_goggles isEqualTo QGVAR(divingMask)) then {
        player linkItem "G_B_Diving";
    };
    GVAR(wearMaskOnLand) = true;
} else {
    if (_goggles isEqualTo "G_B_Diving" && GVAR(wearMaskOnLand)) then {
        player linkItem QGVAR(divingMask);
    };
    if (_goggles isEqualTo QGVAR(divingMask) && !GVAR(wearMaskOnLand)) then {
        player linkItem "G_B_Diving";
    };
};
