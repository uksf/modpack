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

// Latency mask. Most turns only get one if the reply runs late, and the first audio frame
// cancels it; the rest fire early, at a slightly different beat each time, so the NPC
// sometimes grunts before he answers and sometimes just answers.
private _delay = FILLER_DELAY;
if (random 1 < FILLER_EARLY_CHANCE) then { _delay = FILLER_EARLY_MIN + random FILLER_EARLY_SPREAD; };
// An early filler is betting the reply is nearly here, so it gets a short noise; anything
// firing at or after the usual answer time is covering a genuine wait.
GVAR(fillerEarlyUntil) set [netId _npc, diag_tickTime + FILLER_DELAY];

private _token = diag_tickTime;
GVAR(pendingFiller) set [netId _npc, _token];
[_npc, _token, _delay, 0] call FUNC(scheduleFiller);

// Forward to the server: [npcId, speakerId(UID), text, t]
private _speakerId = getPlayerUID _unit;
if (_speakerId isEqualTo "") exitWith { TRACE_1("no UID for speaker, dropping",_unit); };

TRACE_3("utterance -> server",netId _npc,_speakerId,_text);
[QGVAR(utterance), [netId _npc, _speakerId, _text, _time]] call CBA_fnc_serverEvent;
