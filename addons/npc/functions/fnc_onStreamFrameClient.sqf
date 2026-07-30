#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Feed one streamed PCM frame into the extension's open clip, or close
        the stream on end. The extension plays once its prebuffer is met and pauses
        rather than stopping on underrun, so frames can arrive with network jitter
        without breaking the speech.

    Parameter(s):
        0: NPC netId <STRING>
        1: Turn id <STRING>
        2: Frame sequence number <NUMBER>  (frame only)
        3: PCM base64, raw 24 kHz mono i16 <STRING>  (frame only)

    Return Value:
        None
*/
params ["_npcId", "_turnId", ["_seq", -1, [0]], ["_pcm", "", [""]]];

private _npc = objectFromNetId _npcId;
if (isNull _npc) exitWith {};

if (_seq < 0) exitWith {
    // End frame: mark the stream closed; the extension plays out its buffer.
    private _clipId = format ["%1_%2", _npcId, _turnId];
    TRACE_2("stream end",_npcId,_turnId);
    "uksf" callExtension ["audioEnd", [_clipId]];
    GVAR(streamingClips) deleteAt _clipId;
    private _turnKey = format ["%1|%2", _npcId, _turnId];
    GVAR(heardTurns) set [_turnKey, diag_tickTime];

    // Frames arrive several times faster than they play, so the mouth has to run to the
    // end of the audio, not to the end of the delivery.
    private _playSeconds = (GVAR(streamSamples) getOrDefault [_clipId, 0]) / STREAM_RATE;
    private _endTime = (GVAR(streamStart) getOrDefault [_clipId, diag_tickTime]) + _playSeconds;
    GVAR(streamSamples) deleteAt _clipId;
    GVAR(streamStart) deleteAt _clipId;
    GVAR(talkingUntil) set [_npcId, _endTime];
    [{
        params ["_npc", "_npcId", "_endTime"];
        if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > _endTime) exitWith {}; // a newer line took over
        if (!isNull _npc) then { _npc setRandomLip false };
    }, [_npc, _npcId, _endTime], (_endTime - diag_tickTime) max 0] call CBA_fnc_waitAndExecute;
};

private _turnKey = format ["%1|%2", _npcId, _turnId];
if (_turnKey in GVAR(heardTurns)) exitWith {}; // already finished this turn

// Dedupe by seq: a mid-clip join replay and the live relay can deliver the same
// frame twice.
private _seqKey = format ["%1|%2|seq", _npcId, _turnId];
private _lastSeq = GVAR(heardSeq) getOrDefault [_seqKey, -1];
if (_seq <= _lastSeq) exitWith {};
GVAR(heardSeq) set [_seqKey, _seq];

private _clipId = format ["%1_%2", _npcId, _turnId];

// First frame: supersede any prior clip for this NPC and place the source.
if !(_clipId in GVAR(streamingClips)) then {
    { if ((_x#1) isEqualTo _npc) then { "uksf" callExtension ["audioStop", [_x#0]]; }; } forEach GVAR(active);
    GVAR(active) = GVAR(active) select { (_x#1) isNotEqualTo _npc };
    GVAR(streamingClips) set [_clipId, true];
    private _delta = (getPosASL _npc) vectorDiff ((call FUNC(listenerPose)) # 0);
    private _vol = [_npc, 1] call FUNC(acreVol);
    "uksf" callExtension ["audioPlay", [_clipId, _delta#0, _delta#1, _delta#2, _vol, 0]];
    GVAR(active) pushBack [_clipId, _npc, 1];
    if (!GVAR(tickRunning)) then {
        GVAR(tickRunning) = true;
        [FUNC(tick), 0, []] call CBA_fnc_addPerFrameHandler;
    };
    GVAR(streamSamples) set [_clipId, 0];
    GVAR(streamStart) set [_clipId, diag_tickTime + SPEECH_PREBUFFER];
    // The extension holds the clip until its prebuffer fills, so starting the mouth
    // now would run it ahead of the voice. Start it when the sound does.
    [{ params ["_npc"]; if (!isNull _npc) then { _npc setRandomLip true }; }, [_npc], SPEECH_PREBUFFER] call CBA_fnc_waitAndExecute;
};

// base64 carries 3 bytes per 4 characters; the payload is 16-bit mono, so 2 bytes a sample.
GVAR(streamSamples) set [_clipId, (GVAR(streamSamples) getOrDefault [_clipId, 0]) + (count _pcm) * 3 / 8];

TRACE_3("stream frame",_npcId,_turnId,_seq);
"uksf" callExtension ["audioFeed", [_clipId, _pcm]];
