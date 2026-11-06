#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the turrets of a vehicle that can use a weapon spotlight.
        Only listed vehicles qualify, and only their manned gun turrets with open sights and a muzzle memory point.
        The result is cached per vehicle class.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Turret paths <ARRAY>

    Example:
        [vehicle player] call uksf_vehicles_fnc_spotlightTurrets
*/
params ["_vehicle"];

GVAR(spotlightTurretCache) getOrDefaultCall [typeOf _vehicle, {
    private _listed = GVAR(spotlightVehicles) findIf {_vehicle isKindOf _x} != -1;

    (allTurrets [_vehicle, false]) select {
        private _config = [_vehicle, _x] call CBA_fnc_getTurret;
        _listed
        && {(getText (_config >> "turretInfoType")) in ["RscOptics_Offroad_01", "RscWeaponZeroing"]}
        && {(_vehicle selectionPosition [getText (_config >> "gunBeg"), "Memory"]) isNotEqualTo [0, 0, 0]}
        && {(getArray (_config >> "weapons")) findIf {
            private _weapon = configFile >> "CfgWeapons" >> _x;
            _x != "SmokeLauncher" && {(getArray (_weapon >> "magazines")) isNotEqualTo [] || {(getArray (_weapon >> "magazineWell")) isNotEqualTo []}}
        } != -1}
    }
}, true]
