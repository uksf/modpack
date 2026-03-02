#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a persistence load chunk received from the extension callback.
        Stores chunks in a buffer array. When all chunks have arrived,
        reassembles the JSON, parses it, and populates GVAR(dataNamespace).
        Sets GVAR(apiLoadComplete) to true when finished.

    Parameter(s):
        0: Chunk JSON string <STRING>

    Return Value:
        None
*/
params ["_chunkJson"];

private _parsed = [_chunkJson, 2] call CBA_fnc_parseJSON;
if (isNil "_parsed") exitWith {
    WARNING_1("Failed to parse API load chunk JSON: %1",_chunkJson);
    GVAR(apiLoadChunks) = nil;
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
    GVAR(apiLoadComplete) = true;
};

private _index = _parsed getOrDefault ["index", 0];
private _total = _parsed getOrDefault ["total", 1];
private _data = _parsed getOrDefault ["data", ""];
private _error = _parsed getOrDefault ["error", ""];

TRACE_2("Received API load chunk",_index,_total);

// Error envelope from extension (total == 0)
if (_total == 0) exitWith {
    ERROR_1("API persistence load failed: %1",_error);
    GVAR(apiLoadChunks) = nil;
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
    GVAR(apiLoadComplete) = true;
};

// Initialise buffer on first chunk
if (isNil QGVAR(apiLoadChunks)) then {
    GVAR(apiLoadChunks) = [];
    GVAR(apiLoadChunks) resize _total;
};

GVAR(apiLoadChunks) set [_index, _data];

// Check if all chunks have arrived
private _receivedCount = {!isNil "_x"} count GVAR(apiLoadChunks);
if (_receivedCount < _total) exitWith {
    TRACE_2("Waiting for more chunks",_receivedCount,_total);
};

// All chunks received — reassemble
private _fullJson = GVAR(apiLoadChunks) joinString "";
GVAR(apiLoadChunks) = nil;

INFO_1("API persistence load: received %1 characters",count _fullJson);

// Handle empty data (no save exists)
if (_fullJson == "") exitWith {
    INFO("No API persistence data found, starting fresh");
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
    GVAR(apiLoadComplete) = true;
};

// Parse the full session JSON
private _session = [_fullJson, 2] call CBA_fnc_parseJSON;
if (isNil "_session") exitWith {
    ERROR("Failed to parse reassembled API persistence JSON");
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
    GVAR(apiLoadComplete) = true;
};

// Populate namespace from structured data
GVAR(dataNamespace) = call CBA_fnc_createNamespace;
GVAR(playerUids) = [];

// JSON encoding stringifies side types ("WEST", "EAST", etc.)
// Convert the string back to a side value on load
private _parseSide = {
    params ["_sideString"];
    switch (toUpper _sideString) do {
        case "WEST": {west};
        case "EAST": {east};
        case "INDEPENDENT": {independent};
        case "CIVILIAN": {civilian};
        default {west};
    }
};

// Objects — convert from named fields back to indexed arrays
// Field names match those written by fnc_saveDataApi.sqf
// Array order matches IDX_OBJ_* constants from script_component.hpp (indices 0-17)
private _objects = _session getOrDefault ["objects", []];
private _objectArrays = _objects apply {
    private _fortifyData = +(_x getOrDefault ["aceFortify", [false, west]]);
    if (count _fortifyData > 1 && {_fortifyData#1 isEqualType ""}) then {
        _fortifyData set [1, [_fortifyData#1] call _parseSide];
    };

    [
        _x getOrDefault ["id", ""],
        _x getOrDefault ["type", ""],
        _x getOrDefault ["position", [0, 0, 0]],
        _x getOrDefault ["vectorDirUp", [[0, 1, 0], [0, 0, 1]]],
        _x getOrDefault ["damage", 0],
        _x getOrDefault ["fuel", 0],
        _x getOrDefault ["turretWeapons", []],
        _x getOrDefault ["turretMagazines", []],
        _x getOrDefault ["pylonLoadout", []],
        _x getOrDefault ["logistics", [0, 0, 0]],
        _x getOrDefault ["attached", []],
        _x getOrDefault ["rackChannels", []],
        _x getOrDefault ["aceCargo", []],
        _x getOrDefault ["inventory", [[], [], [], []]],
        _fortifyData,
        _x getOrDefault ["aceMedical", [0, false, false]],
        _x getOrDefault ["aceRepair", [0, 0]],
        _x getOrDefault ["customName", ""]
    ]
};
GVAR(dataNamespace) setVariable [QGVAR(objects), _objectArrays];

// Deleted objects
GVAR(dataNamespace) setVariable [QGVAR(deletedObjects), _session getOrDefault ["deletedObjects", []]];

// Date time
GVAR(dataNamespace) setVariable [QGVAR(dateTime), _session getOrDefault ["dateTime", date]];

// Markers
GVAR(dataNamespace) setVariable [QGVAR(mapMarkers), _session getOrDefault ["markers", []]];

// Players — convert from named fields back to indexed arrays
private _players = _session getOrDefault ["players", createHashMap];
{
    private _uid = _x;
    private _playerData = _y;
    private _playerArray = [
        _playerData getOrDefault ["position", [0, 0, 0]],
        _playerData getOrDefault ["vehicleState", ["", "", -1]],
        _playerData getOrDefault ["direction", 0],
        _playerData getOrDefault ["animation", ""],
        _playerData getOrDefault ["loadout", []],
        _playerData getOrDefault ["damage", 0],
        _playerData getOrDefault ["aceMedical", []],
        _playerData getOrDefault ["earplugs", false],
        _playerData getOrDefault ["attachedItems", []],
        _playerData getOrDefault ["radios", []],
        _playerData getOrDefault ["diveState", [false]]
    ];
    GVAR(dataNamespace) setVariable [_uid, _playerArray];
    GVAR(playerUids) pushBack _uid;
} forEach _players;

// Custom data — restore each serialiser's data
private _customData = _session getOrDefault ["customData", createHashMap];
{
    GVAR(dataNamespace) setVariable [_x, _y];
} forEach _customData;

INFO("API persistence data loaded into namespace");
GVAR(apiLoadComplete) = true;
