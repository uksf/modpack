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

CONSPICUITY_CHECK_GEAR(_weapon);
CONSPICUITY_CHECK_GEAR(primaryWeapon _player);
CONSPICUITY_CHECK_GEAR(secondaryWeapon _player);
CONSPICUITY_CHECK_GEAR(backpack _player);
CONSPICUITY_CHECK_GEAR(uniform _player);
// CONSPICUITY_CHECK_GEAR(vest _player);
// CONSPICUITY_CHECK_GEAR(headgear _player);
// CONSPICUITY_CHECK_GEAR(hmd _player);

CONSPICUITY_SET(false);
