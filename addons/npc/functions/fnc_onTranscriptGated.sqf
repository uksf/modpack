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
if (isNull _npc) exitWith { TRACE_1("transcript with no target npc, dropping",_text); };

// Latency mask. A normal turn answers in about two seconds, so below FILLER_DELAY there
// is silence; past it, each wait-point rolls a small chance of one filler, re-rolled as
// the wait grows, and the first audio frame cancels the whole chain.
GVAR(fillerEarlyUntil) set [netId _npc, diag_tickTime + FILLER_SHORT_WINDOW];

private _token = diag_tickTime;
GVAR(pendingFiller) set [netId _npc, _token];
[_npc, _token, FILLER_DELAY, 0] call FUNC(scheduleFiller);

// Forward to the server: UID only. An NPC has no way to know a stranger's name, so the
// API labels speakers ("Soldier 1", ...) and upgrades the label only when the player
// actually introduces themselves.
private _speakerId = getPlayerUID _unit;
if (_speakerId isEqualTo "") exitWith { TRACE_1("no UID for speaker, dropping",_unit); };

TRACE_3("utterance -> server",netId _npc,_speakerId,_text);
[QGVAR(utterance), [netId _npc, _speakerId, _text, _time]] call CBA_fnc_serverEvent;
