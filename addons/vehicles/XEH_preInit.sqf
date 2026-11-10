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
    private _missing = _count;
    if (_vehicle turretLocal _path) then {
        private _before = {(_x select 0) isEqualTo _magazine && {(_x select 1) isEqualTo _path}} count magazinesAllTurrets [_vehicle, true];
        for "_i" from 1 to _count do {_vehicle addMagazineTurret [_magazine, _path]};
        private _after = {(_x select 0) isEqualTo _magazine && {(_x select 1) isEqualTo _path}} count magazinesAllTurrets [_vehicle, true];
        _missing = _count - ((_after - _before) max 0);
    };
    if (_missing > 0) then {
        private _holder = createVehicle ["GroundWeaponHolder", getPosATL _vehicle, [], 0, "CAN_COLLIDE"];
        _holder addMagazineCargoGlobal [_magazine, _missing];
    };
}] call CBA_fnc_addEventHandler;
[QGVAR(smokeReloadResult), {params ["_message"]; hint _message}] call CBA_fnc_addEventHandler;

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
