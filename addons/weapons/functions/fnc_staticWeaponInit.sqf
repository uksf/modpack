#include "script_component.hpp"
#include "\a3\editor_f\Data\Scripts\dikCodes.h"
/*
    Author:
        www.3commandobrigade.com, Tim Beswick

    Description:
        Correct the weapon loadout for use by the pilot

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None
*/

/*if ((alive player)) then {
    player addEventHandler ["Put", "call UK3CB_BAF_Weapons_Static_fnc_player_put_EH"];
    player addEventHandler ["Take", "call UK3CB_BAF_Weapons_Static_fnc_player_take_EH"];
};*/

// UK3CB_BAF_Weapons_Static_fnc_load_static_weapon = compile preprocessFileLineNumbers "\UK3CB_BAF_Equipment\static_weapons\functions\fn_load_static_weapon.sqf";
// UK3CB_BAF_Weapons_Static_fnc_getout_of_static_weapon = compile preprocessFileLineNumbers "\UK3CB_BAF_Equipment\static_weapons\functions\fn_getout_of_static_weapon.sqf";
// UK3CB_BAF_Weapons_Static_fnc_toggle_range_table = compile preprocessFileLineNumbers "\UK3CB_BAF_Equipment\static_weapons\functions\fn_toggle_range_table.sqf";
// UK3CB_BAF_Weapons_Static_fnc_rapid_deploy_weapon = compile preprocessFileLineNumbers "\UK3CB_BAF_Equipment\static_weapons\functions\fn_rapid_deploy_weapon.sqf";

UK3CB_BAF_Weapons_Static_fnc_addMagazine = {
   private ["_weaponPlatform", "_magName", "_gunner"];

    _weaponPlatform = _this select 0;
    _magName = _this select 1;
    _gunner = gunner _weaponPlatform;

    if (isNull _gunner) then {
        // Call the command on the PC controlling the weapon platform
        if (local _weaponPlatform) then {
            //hint "Magazine loaded";
            _weaponPlatform addMagazines [_magName, 1];
        } else {
            UK3CB_PV_AddMagazine = _this;

            if (isServer) then {
                (owner _weaponPlatform) publicVariableClient "UK3CB_PV_AddMagazine";
            } else {
                publicVariableServer "UK3CB_PV_AddMagazine";
            };
        };
    } else {
        // Call the command on the PC controlling the gunner
        if (local _gunner) then {
            //hint "Magazine loaded";
            //diag_log "*** Add magazine (local gunner)";
            _weaponPlatform addMagazines [_magName, 1];

            // auto fire weapon - eg, 81mm mortar
            // if (getNumber(configFile >> "cfgVehicles" >> typeof _weaponPlatform >> "UK3CB_AutoFire") == 1) then {
                // //diag_log format ["*** Autofire for %1", (weapons _weaponPlatform select 0)];
                // Code removed due to an A3 bug - weapon uses default elevation when firing
                // _weaponPlatform fire [currentMuzzle _gunner, currentWeaponMode _gunner, _magName];
            // };
        } else {
            UK3CB_PV_AddMagazine = _this;

            if (isServer) then {
                (owner _gunner) publicVariableClient "UK3CB_PV_AddMagazine";
            } else {
                publicVariableServer "UK3CB_PV_AddMagazine";
            };
        };
    };
};

"UK3CB_PV_AddMagazine" addPublicVariableEventHandler {
    (_this select 1) call UK3CB_BAF_Weapons_Static_fnc_addMagazine;
};

UK3CB_BAF_Weapons_Static_fnc_setRoundsInMagazine = {
   private ["_weaponPlatform","_magName","_rounds"];

    _weaponPlatform = _this select 0;
    _magName = _this select 1;
    _rounds = _this select 2;

    if (local _weaponPlatform) then {
        _weaponPlatform setMagazineTurretAmmo [_magName, _rounds, [0]];
    } else {
        UK3CB_PV_SetRoundsInMagazine = _this;

        if (isServer) then {
            (owner _weaponPlatform) publicVariableClient "UK3CB_PV_SetRoundsInMagazine";
        } else {
            publicVariableServer "UK3CB_PV_SetRoundsInMagazine";
        };
    };
};

"UK3CB_PV_SetRoundsInMagazine" addPublicVariableEventHandler {
    (_this select 1) call UK3CB_BAF_Weapons_Static_fnc_setRoundsInMagazine;
};

UK3CB_BAF_Weapons_Static_fnc_removeMagazine = {
   private ["_weaponPlatform","_magName"];

    _weaponPlatform = _this select 0;
    _magName = _this select 1;

    if (local _weaponPlatform) then {
        _weaponPlatform removeMagazineTurret [_magName, [0]];
    } else {
        UK3CB_PV_RemoveMagazine = _this;

        if (isServer) then {
            (owner _weaponPlatform) publicVariableClient "UK3CB_PV_RemoveMagazine";
        } else {
            publicVariableServer "UK3CB_PV_RemoveMagazine";
        };
    };
};

"UK3CB_PV_RemoveMagazine" addPublicVariableEventHandler {
    (_this select 1) call UK3CB_BAF_Weapons_Static_fnc_removeMagazine;
};

UK3CB_BAF_Weapons_Static_fnc_lock = {
   private ["_weaponPlatform","_condition"];

    _weaponPlatform = _this select 0;
    _condition = _this select 1;

    if (local _weaponPlatform) then {
        _weaponPlatform lockTurret [[0], _condition];
    } else {
        UK3CB_PV_Lock = _this;

        if (isServer) then {
            (owner _weaponPlatform) publicVariableClient "UK3CB_PV_Lock";
        } else {
            publicVariableServer "UK3CB_PV_Lock";
        };
    };
};

"UK3CB_PV_Lock" addPublicVariableEventHandler {
    (_this select 1) call UK3CB_BAF_Weapons_Static_fnc_lock;
};

UK3CB_BAF_Weapons_Static_fnc_setOwnerToServer = {
    private ["_weaponPlatform"];
    _weaponPlatform = _this select 0;

    if (isServer) then {
        _weaponPlatform setOwner 1;
    } else {
        UK3CB_PV_SetOwnerToServer = _this;
        publicVariableServer "UK3CB_PV_SetOwnerToServer";
    };
};

"UK3CB_PV_SetOwnerToServer" addPublicVariableEventHandler {
    (_this select 1) call UK3CB_BAF_Weapons_Static_fnc_setOwnerToServer;
};
