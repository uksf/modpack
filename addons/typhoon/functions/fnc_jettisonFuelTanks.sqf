/*
    Author:
        HCPOOKIE, Tim Beswick

    Description:
        Drops fuel tanks

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_vehicle"];

private _driver = driver _vehicle;

{
	switch (_x) do {
		case "EF2K_fueltank": {
			_driver forceWeaponFire ["EF2K_FuelTankLauncher", "EF2K_FuelTankLauncher"];
			//_vehicle setMass [(getMass _vehicle) * 0.875, 0];
		};
		case "EF2K_CL_fueltank": {		
			_driver forceWeaponFire ["EF2K_CL_FuelTankLauncher", "EF2K_CL_FuelTankLauncher"];
			//_vehicle setMass [(getMass _vehicle) * 0.875, 0];
		};
		default {};
	};
	true
} count (magazines _vehicle);

_driver forceWeaponFire ["CUP_weapon_mastersafe", "CUP_weapon_mastersafe"];
_vehicle animate ["tank_switch", 1];
_vehicle animate ["tank_drop_ind", 0];
