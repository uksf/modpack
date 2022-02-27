#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[] spawn {
    GVAR(addons) = ('true' configClasses (configFile >> "CfgPatches")) apply {configName _x};
    activateAddons GVAR(addons);
};

GVAR(configAmmo) = configFile >> "CfgAmmo";
GVAR(configMagazines) = configFile >> "CfgMagazines";
GVAR(configWeapons) = configFile >> "CfgWeapons";
GVAR(configVehicles) = configFile >> "CfgVehicles";

GVAR(fpsState) = false;

GVAR(respawnPositions) = [];

GVAR(valueCache) = createHashMap;

GVAR(edenLogicIdMap) = createHashMap;

if (hasInterface) then {
    GVAR(fpsArray) = [];

    [QGVAR(hint), {call FUNC(hint)}] call CBA_fnc_addEventHandler;
    [QGVAR(textTiles), {_this spawn BIS_fnc_textTiles}] call CBA_fnc_addEventHandler;

    GVAR(paradropInProgress) = false;
};

if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};

if (isServer) then {
    GVAR(markerID) = 100000;

    GVAR(fpsEventID) = [QGVAR(fpsGet), {call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;

    [QGVAR(addObjectsToCurators), {call FUNC(addObjectsToCurators)}] call CBA_fnc_addEventHandler;
    [QGVAR(setSideRelation), {(_this#0) setFriend [(_this#1), (_this#2)]}] call CBA_fnc_addEventHandler;
    [QGVAR(waitAndDelete), {
        [{
            deleteVehicle _this;
            [QGVAR(deleteEmptyGroups), []] call CBA_fnc_globalEvent;
        }, _this#0, _this#1] call CBA_fnc_waitAndExecute
    }] call CBA_fnc_addEventHandler;

    GVAR(updateHeadlessClientPosition) = true;
    GVAR(updateHeadlessClientDelay) = 180;
};

acex_headless_headlessClients = [];
["acex_headless_headlessClientJoined", {
    params ["_headlessClient"];

    acex_headless_headlessClients pushBackUnique _headlessClient;
}] call CBA_fnc_addEventHandler;

[QGVAR(log), {INFO(_this#0)}] call CBA_fnc_addEventHandler;
[QGVAR(deleteEmptyGroups), {{deleteGroup _x} forEach allGroups}] call CBA_fnc_addEventHandler;

[QGVAR(spawnGroup), {call FUNC(spawnGroup)}] call CBA_fnc_addEventHandler;
[QGVAR(spawnGroupInfantry), {call FUNC(spawnGroupInfantry)}] call CBA_fnc_addEventHandler;
[QGVAR(spawnGroupVehicle), {call FUNC(spawnGroupVehicle)}] call CBA_fnc_addEventHandler;

#include "initSettings.sqf"

ADDON = true;
