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

    // A short reply can finish arriving before the filler it queued behind has finished
    // sounding. Closing it now would end a clip that has not been opened, so wait for the
    // release and come back.
    if (_clipId in GVAR(streamHeld)) exitWith {
        [{ _this call FUNC(onStreamFrameClient); }, [_npcId, _turnId, -1, ""], 0.1] call CBA_fnc_waitAndExecute;
    };

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

// First frame: stop the filler being armed, then either open the clip now or hold it
// until a filler that is already sounding has finished.
if !(_clipId in GVAR(streamingClips)) then {
    GVAR(streamingClips) set [_clipId, true];
    GVAR(pendingFiller) set [_npcId, 0]; // the reply is here; arm no more fillers

    // Cutting a filler off part-way sounds worse than the pause it was covering, so the
    // reply queues behind it. Frames keep arriving meanwhile and are held, not dropped.
    private _wait = ((GVAR(fillerBusyUntil) getOrDefault [_npcId, 0]) - diag_tickTime) max 0;
    GVAR(streamSamples) set [_clipId, 0];
    GVAR(streamHeld) set [_clipId, []];
    [_clipId, _npc, _wait] call FUNC(startStream);
};

// base64 carries 3 bytes per 4 characters; the payload is 16-bit mono, so 2 bytes a sample.
GVAR(streamSamples) set [_clipId, (GVAR(streamSamples) getOrDefault [_clipId, 0]) + (count _pcm) * 3 / 8];

TRACE_3("stream frame",_npcId,_turnId,_seq);
private _held = GVAR(streamHeld) get _clipId;
if (!isNil "_held") exitWith { _held pushBack _pcm; }; // still waiting out a filler
"uksf" callExtension ["audioFeed", [_clipId, _pcm]];
