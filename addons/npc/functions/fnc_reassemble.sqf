#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Buffer-by-index chunk reassembly. Rejects oversized or out-of-range totals.
*/
params ["_key", "_index", "_total", "_chunk"];
if (_total < 1 || {_total > CLIP_CHUNKS_MAX} || {_index < 0} || {_index >= _total}) exitWith { nil };

private _entry = GVAR(rxBuffers) get _key;
if (isNil "_entry") then {
    private _chunks = [];
    _chunks resize _total;
    _entry = [0, _chunks];
    GVAR(rxBuffers) set [_key, _entry];
};
_entry params ["_count", "_chunks"];
if (count _chunks != _total) exitWith { nil };
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
