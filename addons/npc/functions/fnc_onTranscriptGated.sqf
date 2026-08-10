#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Local. Handles a finalised transcript: if the player is addressing an NPC,
        play a filler immediately (latency mask) and forward the utterance to the
        server for debounce/turn batching. Drops silently if no target NPC is set
        or if the speaker has no UID.

    Parameter(s):
        0: unit  <OBJECT>
        1: text  <STRING>
        2: uttId <STRING>
        3: time  <NUMBER>
        (args forwarded from QGVAR(transcript) event)

    Return Value:
        None

    Example:
        [player, "hello", "utt-001", diag_tickTime] call uksf_npc_fnc_onTranscriptGated
*/
params ["_unit", "_text", "_uttId", "_time"];

private _npc = GVAR(targetNpc);

// Everyone close enough hears the words — speech is not directional. Every talkable NPC
// in earshot gets the utterance and the API decides who answers: the one named, or the
// one being looked at when no name is used. Sending only to the gaze target meant naming
// an NPC you were not facing reached nobody at all.
private _heard = (call CBA_fnc_currentUnit) nearEntities [["CAManBase"], HEARING_RADIUS];
_heard = _heard select { alive _x && {_x getVariable [QGVAR(talkable), false]} };
if (_heard isEqualTo []) exitWith { TRACE_1("transcript with no npc in earshot, dropping",_text); };

// Latency mask, for the NPC actually being addressed by gaze. A turn the API drops sends
// npc_turn_cancel back, which stops this loop.
if (!isNull _npc && {_npc in _heard}) then {
    GVAR(fillerEarlyUntil) set [netId _npc, diag_tickTime + FILLER_SHORT_WINDOW];
    private _token = diag_tickTime;
    GVAR(pendingFiller) set [netId _npc, _token];
    [_npc, _token, FILLER_DELAY, 0] call FUNC(scheduleFiller);
};

// Forward to the server: UID only. An NPC has no way to know a stranger's name, so the
// API labels speakers ("Soldier 1", ...) and upgrades the label only when the player
// actually introduces themselves.
private _speakerId = getPlayerUID _unit;
if (_speakerId isEqualTo "") exitWith { TRACE_1("no UID for speaker, dropping",_unit); };

{
    private _isGazeTarget = _x isEqualTo _npc;
    TRACE_3("utterance -> server",netId _x,_speakerId,_isGazeTarget);
    [QGVAR(utterance), [netId _x, _speakerId, _text, _time, _isGazeTarget]] call CBA_fnc_serverEvent;
} forEach _heard;
