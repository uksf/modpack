#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Buffer-by-index chunk reassembly, mirroring fnc_handleApiLoadChunk.
        On first chunk for a key, initialises the buffer to size total.
        Sets chunk at index. When all chunks have arrived, joins and clears the buffer.

    Parameter(s):
        0: Key <STRING>   (e.g. "filler|<npcId>|<fillerId>")
        1: Index <NUMBER> (0-based)
        2: Total <NUMBER>
        3: Chunk <STRING> (base64 fragment)

    Return Value:
        Reassembled base64 WAV <STRING>, or nil if not yet complete.

    Example:
        private _wav = ["filler|0:1|abc123", 0, 3, _chunk] call uksf_npc_fnc_reassemble;
        if (isNil "_wav") exitWith {};
*/
params ["_key", "_index", "_total", "_chunk"];

// Buffer entry is [receivedCount, chunks] so completion is O(1) per chunk.
private _entry = GVAR(rxBuffers) get _key;
if (isNil "_entry") then {
    private _chunks = [];
    _chunks resize _total;
    _entry = [0, _chunks];
    GVAR(rxBuffers) set [_key, _entry];
};
_entry params ["_count", "_chunks"];
if (isNil {_chunks select _index}) then {
    _chunks set [_index, _chunk];
    _count = _count + 1;
    _entry set [0, _count];
};
GVAR(rxBufferTimes) set [_key, diag_tickTime];

TRACE_3("reassemble chunk",_key,_count,_total);
if (_count < _total) exitWith { nil };

private _wav = _chunks joinString "";
GVAR(rxBuffers) deleteAt _key;
GVAR(rxBufferTimes) deleteAt _key;
TRACE_1("reassemble complete",_key);
_wav
