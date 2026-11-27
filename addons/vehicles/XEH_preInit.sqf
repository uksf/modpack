#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"
#include "initSettings.inc.sqf"

GVAR(driverCompartmentHash) = createHashMap;
GVAR(cargoCompartmentHash) = createHashMap;
GVAR(turretCompartmentHash) = createHashMap;

[QGVAR(swapDriver), {call FUNC(swapDriverLocal)}] call CBA_fnc_addEventHandler;
[QGVAR(reloadSmoke), {call FUNC(reloadSmoke)}] call CBA_fnc_addEventHandler;
[QGVAR(addSmokeMagazine), {
    params ["_vehicle", "_magazine", "_path", "_count"];
    if (isNull _vehicle) exitWith {};
    if !(_vehicle turretLocal _path) exitWith {
        private _holder = createVehicle ["GroundWeaponHolder", getPosATL _vehicle, [], 0, "CAN_COLLIDE"];
        _holder addMagazineCargoGlobal [_magazine, _count];
    };
    private _weapons = (_vehicle weaponsTurret _path) select {_magazine in compatibleMagazines _x};
    private _ready = if (_weapons isEqualTo []) then {0} else {(weaponState [_vehicle, _path, _weapons select 0]) select 4};
    if (_ready > 0) exitWith {
        for "_i" from 1 to _count do {_vehicle addMagazineTurret [_magazine, _path]};
    };
    private _kept = (magazinesAllTurrets [_vehicle, true]) select {
        (_x select 0) isEqualTo _magazine && {(_x select 1) isEqualTo _path} && {(_x select 2) > 0}
    } apply {_x select 2};
    _vehicle removeMagazinesTurret [_magazine, _path];
    for "_i" from 1 to _count do {_vehicle addMagazineTurret [_magazine, _path]};
    {_vehicle addMagazineTurret [_magazine, _path, _x]} forEach _kept;
}] call CBA_fnc_addEventHandler;
[QGVAR(smokeReloadResult), {params ["_message"]; _message call CBA_fnc_notify}] call CBA_fnc_addEventHandler;

GVAR(spotlightVehicles) = [
    "UK3CB_BAF_Jackal_Base",
    "UK3CB_BAF_Husky_Base",
    "UK3CB_BAF_LandRover_WMIK_Base",
    "CUP_Mastiff_Base",
    "CUP_Ridgback_Base",
    "CUP_Wolfhound_Base",
    "UK3CB_BAF_FV432_Mk3_Base",
    "CUP_Challenger2_base",
    "UK3CB_BAF_RHIB_Base",
    "RHICC_MAIN",
    "Helmatic"
];
GVAR(markingLaserClasses) = createHashMap;
GVAR(markingLasers) = [];
GVAR(markingLaserHandle) = -1;
GVAR(spotlightTurretCache) = createHashMap;
GVAR(nightVisionCameraCache) = createHashMap;
GVAR(spotlights) = [];
GVAR(spotlightCleanupHandle) = -1;
[QGVAR(setSpotlight), {call FUNC(setSpotlight)}] call CBA_fnc_addEventHandler;
[QGVAR(setEmptyDynamicSimulation), {call FUNC(setEmptyDynamicSimulation)}] call CBA_fnc_addEventHandler;

ADDON = true;
