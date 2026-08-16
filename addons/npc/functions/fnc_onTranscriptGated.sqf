#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Local. Handles a finalised transcript: every talkable NPC in earshot gets
        the utterance. Fillers arm only for the gaze target.
*/
params ["_unit", "_text", "_uttId", "_time"];

private _npc = GVAR(targetNpc);
private _player = call CBA_fnc_currentUnit;
private _heard = [];
{
    private _candidate = objectFromNetId _x;
    if (isNull _candidate || {!alive _candidate} || {!(_candidate getVariable [QGVAR(talkable), false])}) then { continue };
    if ((_player distance _candidate) <= GVAR(hearingRadius)) then { _heard pushBack _candidate };
} forEach (missionNamespace getVariable [QGVAR(talkerNetIds), []]);
if (_heard isEqualTo []) exitWith { TRACE_1("transcript with no npc in earshot, dropping",_text); };

if (!isNull _npc && {_npc in _heard}) then {
    GVAR(fillerEarlyUntil) set [netId _npc, diag_tickTime + GVAR(fillerShortWindow)];
    private _token = diag_tickTime;
    GVAR(pendingFiller) set [netId _npc, _token];
    [_npc, _token, GVAR(fillerDelay), 0] call FUNC(scheduleFiller);
};

private _speakerId = getPlayerUID _unit;
if (_speakerId isEqualTo "") exitWith { TRACE_1("no UID for speaker, dropping",_unit); };

{
    private _isGazeTarget = _x isEqualTo _npc;
    TRACE_3("utterance -> server",netId _x,_speakerId,_isGazeTarget);
    [QGVAR(utterance), [netId _x, _speakerId, _text, _time, _isGazeTarget]] call CBA_fnc_serverEvent;
} forEach _heard;
