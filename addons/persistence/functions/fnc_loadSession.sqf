#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads the previous persistence session on server.
        Resolves the mission key, deserialises the data namespace from profile,
        extracts player UIDs, and triggers the API load for proofing comparison.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_loadSession
*/

GVAR(key) = getMissionConfigValue ["persistenceKey", ""];
INFO_1("Mission Key: %1",GVAR(key));

if (GVAR(key) == "") exitWith {
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
};

GVAR(key) = format [QUOTE(GVAR(key)_%1_%2), worldName, GVAR(key)];
GVAR(dataSaved) = true;
GVAR(apiLoadComplete) = false;
GVAR(apiLoadedSession) = nil;

private _hash = profileNamespace getVariable [GVAR(key), []];
TRACE_1("Loaded data",_hash);
// TODO: When switching to API-only data source, move player data out of the root namespace.
// Currently players are stored as individual UID-keyed variables at the namespace root
// (e.g. "76561197993062869" → [playerData]). They should be stored under a single
// "players" key as a hashmap of UID → data, matching the API session format.
// This will remove the need for GVAR(playerUids) and the regex-based UID detection below.
GVAR(dataNamespace) = [_hash] call CBA_fnc_deserializeNamespace;
GVAR(playerUids) = [];
{
    if (_x regexMatch "^[0-9]{17}$") then {
        GVAR(playerUids) pushBack _x;
    };
} forEach ([GVAR(dataNamespace)] call CBA_fnc_allVariables);

// Snapshot profile data for API comparison (before loadServerData modifies the namespace)
private _profilePlayers = createHashMap;
{
    private _playerData = GVAR(dataNamespace) getVariable [_x, []];
    if (count _playerData > 0) then {
        _profilePlayers set [_x, +_playerData];
    };
} forEach GVAR(playerUids);

GVAR(profileSnapshot) = createHashMapFromArray [
    ["dateTime", +(GVAR(dataNamespace) getVariable [QGVAR(dateTime), []])],
    ["deletedObjects", +(GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []])],
    ["mapMarkers", +(GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []])],
    ["objects", +(GVAR(dataNamespace) getVariable [QGVAR(objects), []])],
    ["players", _profilePlayers],
    ["playerUids", +GVAR(playerUids)]
];

// Also snapshot serializer data
{
    _x params ["_id"];
    private _data = GVAR(dataNamespace) getVariable [_id, []];
    if (count _data > 0) then {
        GVAR(profileSnapshot) set [_id, +_data];
    };
} forEach GVAR(serializers);

// Trigger API load in parallel for proofing comparison
private _result = ("uksf" callExtension ["load", [GVAR(key)]]) select 0;
INFO_1("Proofing API load triggered: %1",_result);

if (_result == "" || {toLower (_result select [0, 5]) == "error"}) then {
    ERROR_1("Failed to trigger proofing load: %1",_result);
    GVAR(apiLoadComplete) = true;
};
