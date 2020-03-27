#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets whether unit weapon has suppressor

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Has suppressor <BOOL>
*/
params ["_unit"];

private _silencer = (_unit weaponAccessories (currentWeapon _unit)) select 0;
if (_silencer isEqualTo "") exitWith {false};

[false, true] select (getNumber (GVAR(configWeapons) >> _silencer >> "ItemInfo" >> "soundTypeIndex"))
