#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a persistence load chunk received via the API command event.
        Stores chunks in a buffer array. When all chunks have arrived,
        reassembles the SQF and parses it into GVAR(apiLoadedSession).
        Does NOT commit data to dataNamespace — the caller decides what to do.
        Sets GVAR(apiLoadComplete) to true when finished.

        Args (positional, from handleCommand): [id, index, total, data, error]

    Parameter(s):
        0: Args <ARRAY>

    Return Value:
        None

    Example:
        [_args] call uksf_persistence_fnc_handleApiLoadChunk
*/
params ["_args"];
_args params [["_id", ""], ["_index", 0], ["_total", 1], ["_data", ""], ["_error", ""]];

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
private _fullSqf = GVAR(apiLoadChunks) joinString "";
GVAR(apiLoadChunks) = nil;

INFO_1("API persistence load: received %1 characters",count _fullSqf);

// Handle empty data (no save exists)
if (_fullSqf == "") exitWith {
    INFO("No API persistence data found");
    GVAR(apiLoadedSession) = nil;
    GVAR(apiLoadComplete) = true;
};

// API emits canonical SQF str format ([[k,v],...] for hashmaps).
// parseSimpleArray accepts the structure; pair-lists become hashmaps via fnc_rebuildHashmaps.
private _parsed = parseSimpleArray _fullSqf;
if (isNil "_parsed") exitWith {
    ERROR("Failed to parseSimpleArray reassembled API persistence payload");
    GVAR(apiLoadedSession) = nil;
    GVAR(apiLoadComplete) = true;
};

GVAR(apiLoadedSession) = _parsed call FUNC(rebuildHashmaps);
INFO("API persistence SQF parsed successfully");
GVAR(apiLoadComplete) = true;
