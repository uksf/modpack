#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Feed one streamed PCM frame into the extension's open clip, or close
        the stream on end. End only marks the turn heard when this client admitted audio.
*/
params ["_npcId", "_turnId", ["_seq", -1, [0]], ["_pcm", "", [""]]];
if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith {};

private _npc = objectFromNetId _npcId;
private _clipId = format ["%1_%2", _npcId, _turnId];

if (_seq < 0) exitWith {
    if (_clipId in GVAR(streamHeld)) exitWith {
        [{ _this call FUNC(onStreamFrameClient); }, [_npcId, _turnId, -1, ""], 0.1] call CBA_fnc_waitAndExecute;
    };

    if !(_clipId in GVAR(streamingClips)) exitWith {};

    TRACE_2("stream end",_npcId,_turnId);
    "uksf" callExtension ["audioEnd", [_clipId]];
    GVAR(streamingClips) deleteAt _clipId;
    private _turnKey = [_npcId, _turnId] call FUNC(turnKey);
    GVAR(heardTurns) set [_turnKey, diag_tickTime];
    GVAR(heardSeq) deleteAt format ["%1|seq", _turnKey];

    private _playSeconds = (GVAR(streamSamples) getOrDefault [_clipId, 0]) / STREAM_RATE;
    private _endTime = (GVAR(streamStart) getOrDefault [_clipId, diag_tickTime]) + _playSeconds;
    GVAR(streamSamples) deleteAt _clipId;
    GVAR(streamStart) deleteAt _clipId;
    GVAR(talkingUntil) set [_npcId, _endTime];
    [{
        params ["_npc", "_npcId", "_endTime"];
        if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > _endTime) exitWith {};
        if (!isNull _npc) then { _npc setRandomLip false };
    }, [_npc, _npcId, _endTime], (_endTime - diag_tickTime) max 0] call CBA_fnc_waitAndExecute;
};

if (isNull _npc) exitWith {};
private _turnKey = [_npcId, _turnId] call FUNC(turnKey);
if (_turnKey in GVAR(heardTurns)) exitWith {};
if (GVAR(active) findIf { (_x select 0) isEqualTo _clipId } >= 0) exitWith {};

private _seqKey = format ["%1|seq", _turnKey];
private _lastSeq = GVAR(heardSeq) getOrDefault [_seqKey, -1];
if (_seq <= _lastSeq) exitWith {};
GVAR(heardSeq) set [_seqKey, _seq];

if !(_clipId in GVAR(streamingClips)) then {
    GVAR(streamingClips) set [_clipId, true];
    GVAR(pendingFiller) set [_npcId, 0];
    private _wait = ((GVAR(fillerBusyUntil) getOrDefault [_npcId, 0]) - diag_tickTime) max 0;
    GVAR(streamSamples) set [_clipId, 0];
    GVAR(streamHeld) set [_clipId, []];
    [_clipId, _npc, _wait, _npcId, _turnId] call FUNC(startStream);
};

GVAR(streamSamples) set [_clipId, (GVAR(streamSamples) getOrDefault [_clipId, 0]) + (count _pcm) * 3 / 8];
TRACE_3("stream frame",_npcId,_turnId,_seq);
private _held = GVAR(streamHeld) get _clipId;
if (!isNil "_held") exitWith { _held pushBack _pcm; };
"uksf" callExtension ["audioFeed", [_clipId, _pcm]];
