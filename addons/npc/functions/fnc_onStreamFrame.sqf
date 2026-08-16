#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Relays one streamed PCM frame from the API to nearby clients, and
        closes the stream on npc_audio_end. Frames are stored even with nobody in
        range so a later walk-up can replay them.

    Parameter(s):
        0: Type "npc_audio_frame" or "npc_audio_end" <STRING>
        1: Args <ARRAY>

    Return Value:
        None
*/
params ["_type", "_args"];
_args params ["_npcId", "_turnId"];
if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith {};

private _npc = objectFromNetId _npcId;
private _stream = GVAR(activeStreams) getOrDefault [_npcId, []];
if (_stream isNotEqualTo [] && {(_stream select 0) isNotEqualTo _turnId}) then {
    GVAR(activeStreams) deleteAt _npcId;
    _stream = [];
};

if (_type isEqualTo "npc_audio_frame") exitWith {
    if (isNull _npc || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {
        TRACE_1("stream frame for terminal npc, dropping",_npcId);
    };
    _args params ["", "", "_seq", "_pcm"];
    if (_seq isEqualTo 0) then {
        private _speaker = GVAR(lastSpeaker) getOrDefault [_npcId, objNull];
        if (!isNull _speaker) then { [_npc, _speaker] call FUNC(watchSpeaker); };
    };
    if (_stream isEqualTo []) then { _stream = [_turnId, [], diag_tickTime]; };
    (_stream select 1) set [_seq, _pcm];
    _stream set [2, diag_tickTime];
    GVAR(activeStreams) set [_npcId, _stream];
    private _targets = ALL_PLAYERS select { _x distance _npc <= GVAR(audioRange) };
    if (_targets isEqualTo []) exitWith {};
    TRACE_4("relay frame",_npcId,_turnId,_seq,count _targets);
    [QGVAR(streamFrameSink), [_npcId, _turnId, _seq, _pcm], _targets] call CBA_fnc_targetEvent;
};

if (_stream isEqualTo []) then { _stream = [_turnId, [], diag_tickTime]; };
TRACE_2("relay end",_npcId,_turnId);
[QGVAR(streamEndSink), [_npcId, _turnId], ALL_PLAYERS] call CBA_fnc_targetEvent;
GVAR(activeStreams) deleteAt _npcId;
