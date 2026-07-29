#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. A client forwarded a finalised utterance addressed to an NPC.
        Append it to the NPC's room and (re)arm the debounce flush.

    Parameter(s):
        0: npcId <STRING>
        1: speakerId <STRING>
        2: text <STRING>
        3: t <NUMBER>

    Return Value:
        None

    Example:
        ["2:4", "76561198000000001", "Hello there", 1234.5] call uksf_npc_fnc_onUtterance
*/
params ["_npcId", "_speakerId", "_text", "_t"];

private _room = GVAR(rooms) getOrDefault [_npcId, []];
_room pushBack [_speakerId, _text, _t];
GVAR(rooms) set [_npcId, _room];

// Remember the last speaker object for the head-turn (match by UID).
{
    if (getPlayerUID _x isEqualTo _speakerId) exitWith {
        GVAR(lastSpeaker) set [_npcId, _x];
    };
} forEach allPlayers;

// Debounce: record a token and schedule a flush; only the latest token flushes.
private _token = diag_tickTime;
GVAR(roomTimers) set [_npcId, _token];
[{
    params ["_npcId", "_token"];
    if ((GVAR(roomTimers) getOrDefault [_npcId, 0]) isEqualTo _token) then {
        [_npcId] call FUNC(flushRoom);
    };
}, [_npcId, _token], GVAR(debounceSeconds)] call CBA_fnc_waitAndExecute;
