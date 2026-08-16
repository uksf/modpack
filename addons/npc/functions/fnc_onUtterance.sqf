#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. A client forwarded a finalised utterance addressed to an NPC.
        Append it to the NPC's room and (re)arm the debounce flush.
*/
params ["_npcId", "_speakerId", "_text", "_t", ["_gazeAddressed", false, [false]]];
TRACE_3("utterance received",_npcId,_speakerId,_gazeAddressed);

private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
if !(_npcId in _registered) exitWith {
    TRACE_1("utterance for unregistered npc, dropping",_npcId);
};

private _npc = objectFromNetId _npcId;
if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {
    TRACE_1("utterance for unknown or terminal npc, dropping",_npcId);
};

private _room = GVAR(rooms) getOrDefault [_npcId, []];
_room pushBack [_speakerId, _text, _t, _gazeAddressed];
GVAR(rooms) set [_npcId, _room];

{
    if (getPlayerUID _x isEqualTo _speakerId) exitWith { GVAR(lastSpeaker) set [_npcId, _x]; };
} forEach ALL_PLAYERS;

[GVAR(consoleClients), QGVAR(consoleSttSink), [_npcId, _text select [0, DEBUG_TEXT_MAX], _gazeAddressed]] call EFUNC(common,streamClientsFanout);

private _token = diag_tickTime;
GVAR(roomTimers) set [_npcId, _token];
[{
    params ["_npcId", "_token"];
    if ((GVAR(roomTimers) getOrDefault [_npcId, 0]) isEqualTo _token) then {
        [_npcId] call FUNC(flushRoom);
    };
}, [_npcId, _token], GVAR(debounceSeconds)] call CBA_fnc_waitAndExecute;
