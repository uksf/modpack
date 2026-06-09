#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Splits a full base64 WAV into ~8KB chunks and sends each to the
        target clients via a CBA targetEvent. Clients reassemble in sequence.

    Parameter(s):
        0: CBA event name <STRING>
        1: target clients <ARRAY of OBJECT>
        2: header <ARRAY> (kind-specific leading fields, e.g. ["audio",npcId,turnId,durationMs])
        3: full base64 WAV <STRING>

    Return Value:
        none

    Example:
        [QGVAR(audioChunkSink), _targets, ["audio",_npcId,_turnId,_durationMs,_offsetMs], _wav] call uksf_npc_fnc_pushClipChunks
*/
params ["_event", "_targets", "_header", "_wav"];
if (_targets isEqualTo []) exitWith {};

private _chunkSize = 8192;
private _len = count _wav;
private _total = ceil (_len / _chunkSize);
if (_total < 1) then { _total = 1 };

for "_i" from 0 to (_total - 1) do {
    private _start = _i * _chunkSize;
    private _chunk = _wav select [_start, _chunkSize];
    [_event, [_header, _i, _total, _chunk], _targets] call CBA_fnc_targetEvent;
};
