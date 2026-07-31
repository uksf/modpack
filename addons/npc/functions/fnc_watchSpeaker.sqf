#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Points the NPC at the player who just spoke to them: head track while the
        conversation runs, and a body turn first if the speaker is well outside the arc a
        head can cover. Fires on utterance, so the acknowledgement starts the moment the
        player talks, not when the reply lands. Held by a rolling deadline; every new
        utterance extends it, and the watch releases when the conversation lapses.

    Parameter(s):
        0: NPC object <OBJECT>
        1: Speaker object <OBJECT>

    Return Value:
        None

    Example:
        [_npc, _speaker] call uksf_npc_fnc_watchSpeaker
*/
params ["_npc", "_speaker"];
if (isNull _npc || {isNull _speaker} || {!alive _npc}) exitWith {};

private _npcId = netId _npc;

// No scripted body rotation: doWatch drives head AND body through the AI's own movement
// layer, which only works when nothing has been disableAI'd away. Manually stepping setDir
// fought that layer and read as jitter.
_npc doWatch _speaker;

// Rolling hold: each utterance pushes the deadline out; the watch only releases once
// nobody has spoken to this NPC for WATCH_HOLD seconds.
private _until = diag_tickTime + WATCH_HOLD;
GVAR(watchUntil) set [_npcId, _until];
[{
    params ["_npc", "_npcId", "_until"];
    if ((GVAR(watchUntil) getOrDefault [_npcId, 0]) > _until) exitWith {}; // conversation still going
    if (!isNull _npc) then { _npc doWatch objNull };
}, [_npc, _npcId, _until], WATCH_HOLD] call CBA_fnc_waitAndExecute;
