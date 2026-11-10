#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"
#include "initSettings.inc.sqf"

GVAR(driverCompartmentHash) = createHashMap;
GVAR(cargoCompartmentHash) = createHashMap;
GVAR(turretCompartmentHash) = createHashMap;

[QGVAR(swapDriver), {call FUNC(swapDriverLocal)}] call CBA_fnc_addEventHandler;
[QGVAR(reloadSmoke), {call FUNC(reloadSmoke)}] call CBA_fnc_addEventHandler;
GVAR(smokeTransaction) = 0;
[QGVAR(addSmokeMagazine), {
    params ["_vehicle", "_token", "_index", "_magazine", "_path", "_count"];
    if (isNull _vehicle) exitWith {};
    if !(_vehicle turretLocal _path) exitWith {
        if (isServer) then {
            if (((_vehicle getVariable [QGVAR(smokePending), []]) param [0, -1]) isEqualTo _token) then {
                [QGVAR(addSmokeMagazine), _this, _vehicle turretOwner _path] call CBA_fnc_ownerEvent;
            };
        } else {
            [QGVAR(addSmokeMagazine), _this] call CBA_fnc_serverEvent;
        };
    };
    private _applied = _vehicle getVariable [QGVAR(smokeApplied), []];
    private _appliedIndex = _applied findIf {(_x select 0) isEqualTo _token && {(_x select 1) isEqualTo _index}};
    if (_appliedIndex >= 0) exitWith {
        [QGVAR(smokeAcknowledge), [_vehicle, _token, _index, (_applied select _appliedIndex) select 2]] call CBA_fnc_serverEvent;
    };
    private _before = {(_x select 0) isEqualTo _magazine && {(_x select 1) isEqualTo _path}} count magazinesAllTurrets [_vehicle, true];
    for "_i" from 1 to _count do {_vehicle addMagazineTurret [_magazine, _path]};
    private _after = {(_x select 0) isEqualTo _magazine && {(_x select 1) isEqualTo _path}} count magazinesAllTurrets [_vehicle, true];
    private _missing = _count - ((_after - _before) max 0);
    if (_missing > 0) then {
        private _holder = createVehicle ["GroundWeaponHolder", getPosATL _vehicle, [], 0, "CAN_COLLIDE"];
        _holder addMagazineCargoGlobal [_magazine, _missing];
    };
    _applied pushBack [_token, _index, _missing];
    _vehicle setVariable [QGVAR(smokeApplied), _applied];
    [QGVAR(smokeAcknowledge), [_vehicle, _token, _index, _missing]] call CBA_fnc_serverEvent;
}] call CBA_fnc_addEventHandler;
[QGVAR(smokeAcknowledge), {
    params ["_vehicle", "_token", "_index", "_missing"];
    if (!isServer || {isNull _vehicle}) exitWith {};
    private _pending = _vehicle getVariable [QGVAR(smokePending), []];
    if (count _pending != 4 || {(_pending select 0) isNotEqualTo _token}) exitWith {};
    _pending params ["", "_unit", "_count", "_acknowledged"];
    if (_index in _acknowledged) exitWith {};
    _acknowledged pushBack _index;
    if (_missing > 0) then {_vehicle setVariable [QGVAR(smokeDeliveryFailed), true]};
    if (count _acknowledged isEqualTo _count) then {
        _vehicle setVariable [QGVAR(smokePending), nil];
        _vehicle setVariable [QGVAR(smokeBusy), false];
        private _message = if (_vehicle getVariable [QGVAR(smokeDeliveryFailed), false]) then {"Smoke ammunition could not be loaded; dropped nearby."} else {"Smoke ammunition refilled."};
        _vehicle setVariable [QGVAR(smokeDeliveryFailed), nil];
        if (!isNull _unit) then {[QGVAR(smokeReloadResult), [_message], _unit] call CBA_fnc_targetEvent};
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
