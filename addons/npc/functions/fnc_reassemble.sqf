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

// Initialise buffer on first chunk for this key
if !(_key in GVAR(rxBuffers)) then {
    private _buffer = [];
    _buffer resize _total;
    GVAR(rxBuffers) set [_key, _buffer];
};

private _buffer = GVAR(rxBuffers) get _key;
_buffer set [_index, _chunk];
GVAR(rxBufferTimes) set [_key, diag_tickTime];

// Check if all chunks have arrived
private _receivedCount = {!isNil "_x"} count _buffer;
TRACE_3("reassemble chunk",_key,_receivedCount,_total);
if (_receivedCount < _total) exitWith { nil };

// All chunks received — reassemble and clear buffer
private _wav = _buffer joinString "";
GVAR(rxBuffers) deleteAt _key;
GVAR(rxBufferTimes) deleteAt _key;
TRACE_1("reassemble complete",_key);
_wav
