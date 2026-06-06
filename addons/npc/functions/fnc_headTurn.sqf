#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Runs on the NPC owner. Turns the NPC to watch the addresser for the clip
        duration, then releases. doWatch is Argument-Local, so this is invoked via
        CBA_fnc_targetEvent targeting the NPC; the global effect needs no rebroadcast.

    Parameter(s):
        0: npc <OBJECT>
        1: speaker <OBJECT>
        2: duration in milliseconds <NUMBER>

    Return Value:
        none

    Example:
        [_npc, _speaker, _durationMs] call uksf_npc_fnc_headTurn
*/
params ["_npc", "_speaker", "_durationMs"];
if (isNull _npc || {!alive _npc}) exitWith {};

private _npcId = netId _npc;
if (!isNull _speaker) then { _npc doWatch _speaker; };

private _duration = (_durationMs / 1000) max 0.5;
private _endTime = diag_tickTime + _duration;
GVAR(talkingUntil) set [_npcId, _endTime];
[{
    params ["_npc", "_npcId", "_endTime"];
    if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > _endTime) exitWith {};
    if (!isNull _npc) then { _npc doWatch objNull };
}, [_npc, _npcId, _endTime], _duration] call CBA_fnc_waitAndExecute;
