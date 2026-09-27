#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. A client forwarded one finalised utterance and the NPCs in its
        earshot. Append it to each live NPC's room and (re)arm the debounce flush,
        then send the utterance and each NPC's outcome to the API trace.
*/
params ["_speakerId", "_text", "_t", ["_uttId", -1, [0]], ["_heard", [], [[]]], ["_gazeId", "", [""]]];

private _utt = format ["%1:%2", _speakerId, _uttId];
private _speaker = objNull;
{
    if (getPlayerUID _x isEqualTo _speakerId) exitWith { _speaker = _x };
} forEach ALL_PLAYERS;
private _speakerName = ["Player", name _speaker] select (!isNull _speaker);

private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
private _outcomes = _heard apply {
    private _npcId = _x;
    private _npc = objectFromNetId _npcId;
    private _reason = switch (true) do {
        case (_speakerId isEqualTo ""): { "no uid" };
        case !(_npcId in _registered): { "unregistered" };
        case (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}): { "terminal" };
        default { "" };
    };
    if (_reason isEqualTo "") then {
        private _gazeAddressed = _npcId isEqualTo _gazeId;
        private _room = GVAR(rooms) getOrDefault [_npcId, []];
        _room pushBack [_speakerId, _text, _t, _gazeAddressed, _utt];
        GVAR(rooms) set [_npcId, _room];
        if (!isNull _speaker) then { GVAR(lastSpeaker) set [_npcId, _speaker] };

        [GVAR(consoleClients), QGVAR(consoleSttSink), [_npcId, _text select [0, DEBUG_TEXT_MAX], _gazeAddressed, _speakerName]] call EFUNC(common,streamClientsFanout);

        private _token = diag_tickTime;
        GVAR(roomTimers) set [_npcId, _token];
        [{
            params ["_npcId", "_token"];
            if ((GVAR(roomTimers) getOrDefault [_npcId, 0]) isEqualTo _token) then {
                [_npcId] call FUNC(flushRoom);
            };
        }, [_npcId, _token], GVAR(debounceSeconds)] call CBA_fnc_waitAndExecute;
        _reason = "accepted";
    };
    TRACE_2("utterance outcome",_npcId,_reason);
    [_npcId, _reason]
};

private _event = createHashMapFromArray [
    ["sessionId", EGVAR(api,sessionId)],
    ["utt", _utt],
    ["uid", _speakerId],
    ["name", _speakerName],
    ["text", _text],
    ["t", _t],
    ["heard", _outcomes]
];
if (_gazeId isNotEqualTo "") then { _event set ["gaze", _gazeId] };
if (_heard isEqualTo []) then { _event set ["reason", "no npc in earshot"] };
["npc_utterance", _event] call EFUNC(api,sendEvent);
