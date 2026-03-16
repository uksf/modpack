#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a persistence load chunk received via the API command event.
        Stores chunks in a buffer array. When all chunks have arrived,
        reassembles the JSON and parses it into GVAR(apiLoadedSession).
        Does NOT commit data to dataNamespace — the caller decides what to do.
        Sets GVAR(apiLoadComplete) to true when finished.

    Parameter(s):
        0: Parsed chunk hashmap <HASHMAP>

    Return Value:
        None

    Example:
        [_chunkData] call uksf_persistence_fnc_handleApiLoadChunk
*/
params ["_chunkData"];

private _index = _chunkData getOrDefault ["index", 0];
private _total = _chunkData getOrDefault ["total", 1];
private _data = _chunkData getOrDefault ["data", ""];
private _error = _chunkData getOrDefault ["error", ""];

TRACE_2("Received API load chunk",_index,_total);

// Error envelope from extension (total == 0)
if (_total == 0) exitWith {
    ERROR_1("API persistence load failed: %1",_error);
    GVAR(apiLoadChunks) = nil;
    GVAR(apiLoadedSession) = nil;
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
    INFO("No API persistence data found");
    GVAR(apiLoadedSession) = nil;
    GVAR(apiLoadComplete) = true;
};

// Parse the full session JSON
private _session = [_fullJson, 2] call CBA_fnc_parseJSON;
if (isNil "_session") exitWith {
    ERROR("Failed to parse reassembled API persistence JSON");
    GVAR(apiLoadedSession) = nil;
    GVAR(apiLoadComplete) = true;
};

INFO("API persistence JSON parsed successfully");
GVAR(apiLoadedSession) = _session;
GVAR(apiLoadComplete) = true;
