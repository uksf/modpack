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

// Latency mask, but only if the reply is actually late. A filler on every turn is a tell
// in itself and wears out fast, and a fast turn now beats the delay outright — the first
// audio frame cancels the pending filler by bumping the token.
private _token = diag_tickTime;
GVAR(pendingFiller) set [netId _npc, _token];
[{
    params ["_npc", "_token"];
    if (isNull _npc) exitWith {};
    if ((GVAR(pendingFiller) getOrDefault [netId _npc, 0]) isNotEqualTo _token) exitWith {}; // speech already started
    [_npc] call FUNC(playFiller);
}, [_npc, _token], FILLER_DELAY] call CBA_fnc_waitAndExecute;

// Forward to the server: [npcId, speakerId(UID), text, t]
private _speakerId = getPlayerUID _unit;
if (_speakerId isEqualTo "") exitWith { TRACE_1("no UID for speaker, dropping",_unit); };

TRACE_3("utterance -> server",netId _npc,_speakerId,_text);
[QGVAR(utterance), [netId _npc, _speakerId, _text, _time]] call CBA_fnc_serverEvent;
