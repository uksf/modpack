#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Relays one streamed PCM frame from the API to nearby clients, and
        closes the stream on npc_audio_end. Completed frames stay until streamStale
        so a later walk-up can replay them.
*/
params ["_type", "_args"];
_args params ["_npcId", "_turnId"];
if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith {};

private _npc = objectFromNetId _npcId;
private _clip = GVAR(activeClips) getOrDefault [_npcId, []];
if (_clip isNotEqualTo [] && {(_clip select 0) isEqualTo _turnId}) exitWith {
    TRACE_2("stream dropped, complete clip already admitted",_npcId,_turnId);
};

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
    if (_stream isEqualTo []) then { _stream = [_turnId, [], diag_tickTime, false, []]; };
    if (_stream param [3, false]) exitWith {};
    (_stream select 1) set [_seq, _pcm];
    _stream set [2, diag_tickTime];
    GVAR(activeStreams) set [_npcId, _stream];
    private _targets = ALL_PLAYERS select { _x distance _npc <= GVAR(audioRange) };
    if (_targets isEqualTo []) exitWith {};
    private _listeners = _stream param [4, []];
    { _listeners pushBackUnique _x } forEach _targets;
    _stream set [4, _listeners];
    TRACE_4("relay frame",_npcId,_turnId,_seq,count _targets);
    [QGVAR(streamFrameSink), [_npcId, _turnId, _seq, _pcm], _targets] call CBA_fnc_targetEvent;
};

if (_stream isEqualTo []) then { _stream = [_turnId, [], diag_tickTime, false, []]; };
_stream set [2, diag_tickTime];
_stream set [3, true];
GVAR(activeStreams) set [_npcId, _stream];
private _targets = _stream param [4, []];
if (!isNull _npc) then {
    { _targets pushBackUnique _x } forEach (ALL_PLAYERS select { _x distance _npc <= GVAR(audioRange) });
};
TRACE_2("relay end",_npcId,_turnId);
if (_targets isNotEqualTo []) then {
    [QGVAR(streamEndSink), [_npcId, _turnId], _targets] call CBA_fnc_targetEvent;
};
