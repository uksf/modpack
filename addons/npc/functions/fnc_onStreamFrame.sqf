#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Relays one streamed PCM frame from the API to nearby clients, and
        closes the stream on npc_audio_end. Frames are raw 24 kHz mono i16 base64,
        not WAV — clients append them to an open extension clip.

    Parameter(s):
        0: Type "npc_audio_frame" or "npc_audio_end" <STRING>
        1: Args <ARRAY>

    Return Value:
        None
*/
params ["_type", "_args"];
_args params ["_npcId", "_turnId"];

private _npc = objectFromNetId _npcId;
if (isNull _npc) exitWith { TRACE_1("stream frame for unknown netId",_npcId); };
private _targets = allPlayers select { _x distance _npc <= GVAR(audioRange) };
if (_targets isEqualTo []) exitWith {};

if (_type isEqualTo "npc_audio_frame") exitWith {
    _args params ["", "", "_seq", "_pcm"];
    [QGVAR(streamFrameSink), [_npcId, _turnId, _seq, _pcm], _targets] call CBA_fnc_targetEvent;
    // Track the open stream so a mid-clip joiner can be replayed the frames so far.
    // Entry is [turnId, frames]; the frames array is indexed by seq.
    private _stream = GVAR(activeStreams) getOrDefault [_npcId, [_turnId, []]];
    (_stream select 1) set [_seq, _pcm];
    GVAR(activeStreams) set [_npcId, _stream];
};

// npc_audio_end: tell clients the clip is complete, then reclaim the buffer.
[QGVAR(streamEndSink), [_npcId, _turnId], _targets] call CBA_fnc_targetEvent;
GVAR(activeStreams) deleteAt _npcId;
