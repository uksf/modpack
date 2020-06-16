#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(correctPilotPylon), {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;
["ace_rearm_loadoutChanged", {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;

["CAManBase", "Put", UK3CB_BAF_Weapons_Static_fnc_player_put_EH] call CBA_fnc_addClassEventHandler;
["CAManBase", "Take", UK3CB_BAF_Weapons_Static_fnc_player_take_EH] call CBA_fnc_addClassEventHandler;

["ace_arsenal_displayOpened", {
    if !(isNull (EGVAR(common,configWeapons) >> (primaryWeapon ace_arsenal_center) >> "uk3cb_underbarrel_baseWeapon")) then {
        private _weapon = primaryWeapon ace_arsenal_center;
        private _baseWeapon = getText (EGVAR(common,configWeapons) >> _weapon >> "uk3cb_underbarrel_baseWeapon");

        if (_baseWeapon != "" && _weapon != _baseWeapon) then {
            private _items = primaryWeaponItems ace_arsenal_center;
            private _ammo = ace_arsenal_center ammo _weapon;
            private _mag = currentMagazine ace_arsenal_center;
            ace_arsenal_center addMagazine _mag;
            ace_arsenal_center addWeapon _baseWeapon;
            {ace_arsenal_center addPrimaryWeaponItem _x;} forEach _items;
            ace_arsenal_center setAmmo [_baseWeapon, _ammo];
        };
    };
}] call CBA_fnc_addEventHandler;

["ace_arsenal_displayClosed", {
    if !(isNull (EGVAR(common,configWeapons) >> (primaryWeapon ace_arsenal_center) >> "uk3cb_underbarrel_baseWeapon")) then {
        private _acc = (primaryWeaponItems ace_arsenal_center)#3;
        private _weapon = primaryWeapon ace_arsenal_center;

        if (_acc == "") then {
            private _baseWeapon = getText (EGVAR(common,configWeapons) >> _weapon >> "uk3cb_underbarrel_baseWeapon");

            if (_baseWeapon != "" && _weapon != _baseWeapon) then {
                private _items = primaryWeaponItems ace_arsenal_center;
                private _ammo = ace_arsenal_center ammo _weapon;
                private _mag = currentMagazine ace_arsenal_center;
                ace_arsenal_center addMagazine _mag;
                ace_arsenal_center addWeapon _baseWeapon;
                {ace_arsenal_center addPrimaryWeaponItem _x;} forEach _items;
                ace_arsenal_center setAmmo [_baseWeapon, _ammo];
            };
        } else {
            private _accType = (getText (EGVAR(common,configWeapons) >> _acc >> "uk3cb_underbarrel_altWeapon"));
            private _altWeapon = (getText (EGVAR(common,configWeapons) >> _weapon >> _accType));

            if (_altWeapon != "" && _weapon != _altWeapon) then {
                private _items = primaryWeaponItems ace_arsenal_center;
                private _ammo = ace_arsenal_center ammo _weapon;
                private _mag = currentMagazine ace_arsenal_center;
                ace_arsenal_center addMagazine _mag;
                ace_arsenal_center addWeapon _altWeapon;
                {ace_arsenal_center addPrimaryWeaponItem _x;} forEach _items;
                ace_arsenal_center setAmmo [_altWeapon, _ammo];
            };
        };
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
