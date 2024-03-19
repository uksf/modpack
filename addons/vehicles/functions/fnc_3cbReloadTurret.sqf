#include "script_component.hpp"
/*
    Author:
        www.3commandobrigade.com, Tim Beswick

    Description:
        Resupply ammo to a vehicle's weapon from the vehicle's inventory

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit: <OBJECT>

    Return Value:
        Resupply successful <BOOLEAN>
*/
DEBUG("3cb reload");
params ["_vehicle", "_unit"];

if (!alive _unit || !alive _vehicle || _vehicle isKindOf "StaticWeapon" || !(_unit in _vehicle)) exitWith {
    DEBUG("Unit/vehicle is dead, or unit is not in this vehicle, or vehicle is static weapon");
    false
};

// Bulldog RWS and Panther RWS requires gunner to be turned out to reload
if ((
        (_vehicle isKindOf "UK3CB_BAF_Panther_Base") ||
        (_vehicle isKindOf "UK3CB_BAF_FV432_Mk3_RWS_Sand")
    ) &&
    (!isTurnedOut _unit) &&
    ([_unit] call UK3CB_BAF_Vehicles_Weapons_fnc_isPlayerOrRemoteControlled)
) exitWith {
    DEBUG("Unit is in RWS, needs to be turned out");
    false
};

private _turret = _vehicle unitTurret _unit;
if (_turret isEqualTo []) exitWith {
    DEBUG("Empty turret");
    false
};

(weaponState [_vehicle, _turret]) params ["_weapon", "_muzzle", "", "_currentMagazine", "_currentAmmo", "_roundReloadPhase", "_magazineReloadPhase"];
if !(_weapon in (_vehicle weaponsTurret _turretPath)) exitWith { // FFV
    DEBUG("FFV");
    false
};

if (_roundReloadPhase > 0 || {_magazineReloadPhase > 0}) exitWith {
    DEBUG("Currently reloading");
    false
};

(getMagazineCargo _vehicle) params ["_cargoMagazines", "_cargoMagazineQuantities"];
private _compatibleMagazines = compatibleMagazines [_weapon, _muzzle];
private _compatibleCargoMagazines = _cargoMagazines select {_x in _compatibleMagazines};
TRACE_3("",_currentMagazine,_compatibleCargoMagazines,_compatibleMagazines);

if (_compatibleCargoMagazines isEqualTo []) exitWith {
    DEBUG("No compatible magazines found in cargo to reload");
    false
};

private _magazinePresent = _currentMagazine == "";
if (_magazinePresent) then {
    TRACE_1("Current magazine is empty, nothing to refer to but there are compatible cargo mags, selecting first",_compatibleCargoMagazines);
    _currentMagazine = _compatibleCargoMagazines#0;
};

if (_currentMagazine == "") exitWith {
    ERROR("This shouldn't be reachable. Something went wrong");
    TRACE_7("",_vehicle,_turret,_weapon,_muzzle,_currentMagazine,_compatibleCargoMagazines,_compatibleMagazines);
    false
};

_vehicle addMagazineCargoGlobal [_currentMagazine, -1];

_vehicle removeMagazineTurret [_currentMagazine, _turret];
_vehicle addMagazineTurret [_currentMagazine, _turret];
if (!_magazinePresent) then {
    DEBUG("Magazine was present, adding it back with same ammo count");
    _vehicle addMagazineTurret [_currentMagazine, _turret, _currentAmmo];
};

if ((_currentMagazine == "UK3CB_BAF_1Rnd_Milan") && (_vehicle isKindOf "UK3CB_BAF_LandRover_WMIK_Milan_Base")) then {
    [_vehicle, _currentMagazine] call UK3CB_BAF_Vehicles_Landrover_fnc_milan_magazine_animation;
};

true
