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
#include "script_component.hpp"

params ["_unit"];

private _silencer = (_unit weaponAccessories (currentWeapon _unit)) select 0;
if (_silencer isEqualTo "") exitWith {false};

[false, true] select (getNumber (configFile >> "CfgWeapons" >> _silencer >> "ItemInfo" >> "soundTypeIndex"))
