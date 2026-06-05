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

// Latency mask: play a random pre-cached filler in this NPC's voice now.
[_npc] call FUNC(playFiller);

// Forward to the server: [npcId, speakerId(UID), text, t]
private _speakerId = getPlayerUID _unit;
if (_speakerId isEqualTo "") exitWith { TRACE_1("no UID for speaker, dropping",_unit); };

[QGVAR(utterance), [netId _npc, _speakerId, _text, _time]] call CBA_fnc_serverEvent;
