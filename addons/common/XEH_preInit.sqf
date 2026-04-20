#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(debugGridPositionMarkers) = [];
GVAR(debugSpheres) = [];
GVAR(debugSingletonSphere) = objNull;
GVAR(debugAttachedSphere) = objNull;

GVAR(addons) = ('true' configClasses (configFile >> "CfgPatches")) apply {configName _x};
[] spawn {activateAddons GVAR(addons)};

GVAR(configAmmo) = configFile >> "CfgAmmo";
GVAR(configMagazines) = configFile >> "CfgMagazines";
GVAR(configWeapons) = configFile >> "CfgWeapons";
GVAR(configVehicles) = configFile >> "CfgVehicles";

GVAR(respawnPositions) = [];

GVAR(valueCache) = createHashMap;

GVAR(edenLogicIdMap) = createHashMap;

if (hasInterface) then {
    GVAR(fpsHudMode) = 0;
    uiNamespace setVariable [QGVAR(fpsHudControl), controlNull];
    GVAR(fpsHudPFH) = -1;

    [QGVAR(fpsHudData), {_this call FUNC(fpsHudUpdate)}] call CBA_fnc_addEventHandler;

    [QGVAR(hint), {call FUNC(hint)}] call CBA_fnc_addEventHandler;
    [QGVAR(textTiles), {_this spawn BIS_fnc_textTiles}] call CBA_fnc_addEventHandler;

    GVAR(paradropInProgress) = false;
};

if (isServer) then {
    GVAR(markerID) = 100000;

    GVAR(fpsStore) = createHashMap;
    GVAR(fpsStoreTimestamps) = createHashMap;
    [QGVAR(fpsReport), {_this call FUNC(fpsReport)}] call CBA_fnc_addEventHandler;

    [QGVAR(fpsHudRequest), {
        params ["_player"];
        private _data = [];
        {
            private _identifier = _x;
            private _lastUpdate = GVAR(fpsStoreTimestamps) getOrDefault [_identifier, 0];
            if (CBA_missionTime - _lastUpdate > 10) then { continue };

            private _entry = GVAR(fpsStore) get _identifier;
            private _type = if (_identifier isEqualTo "server") then {
                "server"
            } else {
                private _isPlayer = false;
                {
                    if (getPlayerUID _x isEqualTo _identifier) exitWith { _isPlayer = true };
                } forEach ALL_PLAYERS;
                if (_isPlayer) then { "player" } else { "hc" };
            };
            _data pushBack [_identifier, _entry#0, _type];
        } forEach keys GVAR(fpsStore);
        [QGVAR(fpsHudData), _data, _player] call CBA_fnc_targetEvent;
    }] call CBA_fnc_addEventHandler;

    [QGVAR(addObjectsToCurators), {call FUNC(addObjectsToCurators)}] call CBA_fnc_addEventHandler;
    [QGVAR(setSideRelation), {(_this#0) setFriend [(_this#1), (_this#2)]}] call CBA_fnc_addEventHandler;
    [QGVAR(waitAndDelete), {
        [{
            deleteVehicle _this;
            [QGVAR(deleteEmptyGroups), []] call CBA_fnc_globalEvent;
        }, _this#0, _this#1] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;

    GVAR(updateHeadlessClientPosition) = true;
    GVAR(updateHeadlessClientDelay) = 180;

    // Export OCAP data when persistence shutdown starts
    [QEGVAR(persistence,shutdownStarted), {
        ["ocap_exportData", [west]] call CBA_fnc_localEvent;
    }] call CBA_fnc_addEventHandler;
};

[QGVAR(notify), {_this call CBA_fnc_notify}] call CBA_fnc_addEventHandler;
[QGVAR(log), {INFO(_this#0)}] call CBA_fnc_addEventHandler;
[QGVAR(deleteEmptyGroups), {{deleteGroup _x} forEach allGroups}] call CBA_fnc_addEventHandler;

[QGVAR(spawnGroupInfantry), {call FUNC(spawnGroupInfantry)}] call CBA_fnc_addEventHandler;
[QGVAR(spawnGroupVehicle), {call FUNC(spawnGroupVehicle)}] call CBA_fnc_addEventHandler;

#include "initSettings.inc.sqf"

ADDON = true;
