#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Local. Handles a finalised transcript: every talkable NPC in earshot gets
        the utterance. Fillers arm only for the gaze target. The server gets one
        event per utterance, even when no NPC heard it, so ignored speech is traced.
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

if (!isNull _npc && {_npc in _heard}) then {
    GVAR(fillerEarlyUntil) set [netId _npc, diag_tickTime + GVAR(fillerShortWindow)];
    private _token = diag_tickTime;
    GVAR(pendingFiller) set [netId _npc, _token];
    [_npc, _token, GVAR(fillerDelay), 0] call FUNC(scheduleFiller);
};

private _gazeId = ["", netId _npc] select (!isNull _npc && {_npc in _heard});
TRACE_3("utterance -> server",count _heard,getPlayerUID _unit,_gazeId);
[QGVAR(utterance), [getPlayerUID _unit, _text, _time, _uttId, _heard apply { netId _x }, _gazeId]] call CBA_fnc_serverEvent;
