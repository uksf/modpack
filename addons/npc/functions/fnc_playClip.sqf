#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Play a single WAV clip positionally, anchored to an NPC. Feeds the clip
        bytes to the audio extension in base64 chunks, starts playback at the
        NPC's current world-delta from the player, and registers the clip with
        the per-frame tick that keeps its position updated.

    Parameter(s):
        0: Clip id, unique per concurrent clip <STRING>
        1: NPC object the clip is anchored to <OBJECT>
        2: Clip audio as base64-encoded 16-bit mono WAV <STRING>
        3: Gain 0..1 (Optional, default 1) <NUMBER>

    Return Value:
        The clip id, or "" on bad input <STRING>

    Example:
        ["npc1", _npc, _wavB64] call uksf_npc_fnc_playClip
*/
params [["_clipId", "", [""]], ["_npc", objNull, [objNull]], ["_wavB64", "", [""]], ["_gain", 1, [0]]];

if (_clipId isEqualTo "" || {isNull _npc} || {_wavB64 isEqualTo ""}) exitWith {
    diag_log text format ["[uksf_npc] playClip: bad args (%1)", _this];
    ""
};

// Chunk the base64 into the extension. 8 KB stays well under callExtension arg
// limits and keeps each crossing cheap.
private _chunkSize = 8192;
"uksf" callExtension ["audioOpen", [_clipId]];
private _total = count _wavB64;
private _offset = 0;
while {_offset < _total} do {
    private _length = (_total - _offset) min _chunkSize;
    "uksf" callExtension ["audioChunk", [_clipId, _wavB64 select [_offset, _length]]];
    _offset = _offset + _length;
};

// Initial position + play, then register for the per-frame tick.
private _delta = (getPosASL _npc) vectorDiff (eyePos (call CBA_fnc_currentUnit));
"uksf" callExtension ["audioPlay", [_clipId, _delta#0, _delta#1, _delta#2, _gain]];

GVAR(active) pushBack [_clipId, _npc];
if (!GVAR(tickRunning)) then {
    GVAR(tickRunning) = true;
    [FUNC(tick), 0, []] call CBA_fnc_addPerFrameHandler;
};

_clipId
