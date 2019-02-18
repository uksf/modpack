#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if unit should be conspicuous based on their gear and settings

    Parameters:
        0: Player <OBJECT>
        1: Held weapon <STRING>
        2: Inventory array <STRING>

    Return value:
        Unique ID <SCALAR>
*/

params ["_player", ["_weapon", currentWeapon _player]];

// Ignore pilots
if (_player isKindOf "UKSF_B_Pilot") exitWith {};

CHECK_GEAR_CONSPICUITY(_weapon);
CHECK_GEAR_CONSPICUITY(primaryWeapon _player);
CHECK_GEAR_CONSPICUITY(secondaryWeapon _player);
CHECK_GEAR_CONSPICUITY(backpack _player);
// CHECK_GEAR_CONSPICUITY(uniform _player);
// CHECK_GEAR_CONSPICUITY(vest _player);
// CHECK_GEAR_CONSPICUITY(headgear _player);
// CHECK_GEAR_CONSPICUITY(hmd _player);

SET_CONSPICUOUS(false);
