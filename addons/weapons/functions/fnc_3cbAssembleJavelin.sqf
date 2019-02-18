/*
    Author:
        Tim Beswick

    Description:
        Configures ACRE radio setup

    Parameters:
        None

    Return value:
        Boolean
*/
#include "script_component.hpp"

if (!(alive ACE_player)) exitWith {false};

private _assembleWeapon = {
    ACE_player selectWeapon (secondaryWeapon ACE_player);
    ACE_player removeItemFromBackpack "UK3CB_BAF_Javelin_CLU";
    ACE_player playMove "ReloadRPGKneel";
    ACE_player addWeapon "UK3CB_BAF_Javelin_Launcher";
    ACE_player selectWeapon "UK3CB_BAF_Javelin_Launcher";
};

private _disassembleWeapon = {
    [] spawn {
        ACE_player selectWeapon (secondaryWeapon ACE_player);
        ACE_player playMove "ReloadRPGKneel";
        if ("UK3CB_BAF_Javelin_Mag" in (secondaryWeaponMagazine ACE_player)) then {
            ACE_player addWeapon "UK3CB_BAF_Javelin_Slung_Tube";
            ACE_player addItemToBackpack "UK3CB_BAF_Javelin_CLU";
            ACE_player selectWeapon (primaryWeapon ACE_player);
        } else {
            ACE_player addWeapon "UK3CB_BAF_Javelin_Slung_Tube_Used";
            sleep 4;
            ACE_player removeWeapon "UK3CB_BAF_Javelin_Slung_Tube_Used";
            ACE_player addItemToBackpack "UK3CB_BAF_Javelin_CLU";
            ACE_player selectWeapon (primaryWeapon ACE_player);
            (createVehicle ["GroundWeaponHolder", getPosATL ACE_player, [], 0, "CAN_COLLIDE"]) addWeaponCargoGlobal ["UK3CB_BAF_Javelin_Slung_Tube_Used", 1];
        };
    };
};

private _handled = false;
if ("UK3CB_BAF_Javelin_Launcher" isEqualTo (secondaryWeapon ACE_player)) then {
    call _disassembleWeapon;
    _handled = true;
} else {
    if ("UK3CB_BAF_Javelin_CLU" in (backpackItems ACE_player)) then {
        if ("UK3CB_BAF_Javelin_Slung_Tube" isEqualTo (secondaryWeapon ACE_player)) then {
            ACE_player setWeaponReloadingTime [ACE_player, "UK3CB_BAF_Javelin_Launcher", 0];
            call _assembleWeapon;
            _handled = true;
            ACE_player addSecondaryWeaponItem "UK3CB_BAF_Javelin_Mag";
            ACE_player setWeaponReloadingTime [ACE_player, "UK3CB_BAF_Javelin_Launcher", 1];
        } else {
            if ("UK3CB_BAF_Javelin_Slung_Tube_Used" isEqualTo (secondaryWeapon ACE_player)) then {
                call _assembleWeapon;
                _handled = true;
            } else {
                hint "Javelin tube missing";
            };
        };
    };
};

_handled
