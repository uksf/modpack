/*
    Author:
        Tim Beswick

    Description:
        Inits gear and texture for unit/vehicle

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_bomber"];

if (!local _bomber) exitWith {};

if (_bomber isKindOf "UKSF_O_Skoda_Base") exitWith {
    [_bomber, ["White", 0.25, "Red", 0.25, "Blue", 0.25, "Green", 0.25]] call BIS_fnc_initVehicle;
};
if (_bomber isKindOf "UKSF_O_TK_INS_Suicide_Driver") exitWith {
    removeUniform _bomber;
    removeVest _bomber;
    removeHeadgear _bomber;
    _bomber forceAddUniform (format ["CUP_O_TKI_Khet_Partug_0%1", floor ((random 8) + 1)]);
    _bomber addVest (format ["CUP_V_OI_TKI_Jacket%1_0%2", floor ((random 4) + 1), floor ((random 6) + 1)]);
    _bomber addHeadgear (format ["CUP_H_TKI_Pakol_%1_0%2", floor ((random 2) + 1), floor ((random 6) + 1)]);
};
