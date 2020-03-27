#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        3CB Launcher init

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

if ((local _unit) && {!(isPlayer _unit)}) then {
    private _weapon = secondaryWeapon _unit;
    if (_weapon in ["UK3CB_BAF_AT4_AT_Launcher", "UK3CB_BAF_AT4_AP_Launcher", "UK3CB_BAF_AT4_CS_AT_Launcher", "UK3CB_BAF_AT4_CS_AP_Launcher", "UK3CB_BAF_NLAW_Launcher"]) then {
        _unit addSecondaryWeaponItem ((getArray (EGVAR(common,configWeapons) >> _weapon >> "magazines")) select 0);
    } else {
        if (_weapon isEqualTo "UK3CB_BAF_Javelin_Slung_Tube") then {
            _unit removeItemFromBackpack "UK3CB_BAF_Javelin_CLU";
            _unit removeWeapon "UK3CB_BAF_Javelin_Slung_Tube";
            _unit addWeapon "UK3CB_BAF_Javelin_Launcher";
            _unit addSecondaryWeaponItem ((getArray (EGVAR(common,configWeapons) >> "UK3CB_BAF_Javelin_Launcher" >> "magazines")) select 0);
        };
    };
};
