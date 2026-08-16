#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(active) = [];
GVAR(tickRunning) = false;
GVAR(targetNpc) = objNull;
GVAR(targetCandidate) = 0;
GVAR(micGateOpen) = false;
GVAR(sttHint) = "";

GVAR(consoleStates) = createHashMap;
GVAR(consoleCardsEnabled) = false;
GVAR(consoleCardsPFH) = -1;
GVAR(consoleInspectorNpc) = objNull;
GVAR(consoleInspectorPFH) = -1;
GVAR(consoleClients) = [];

[QGVAR(transcript), { _this call FUNC(onTranscriptGated); }] call CBA_fnc_addEventHandler;
[QGVAR(doWatch), {
    params ["_npc", "_target"];
    if (!isNull _npc && {local _npc}) then { _npc doWatch _target };
}] call CBA_fnc_addEventHandler;

GVAR(clipRxBuffers) = createHashMap;
GVAR(clipRxBufferTimes) = createHashMap;
GVAR(fillers) = createHashMap;
GVAR(fillerCounter) = 0;
GVAR(talkingUntil) = createHashMap;
GVAR(nearTalkers) = [];
GVAR(lastRequest) = createHashMap;
GVAR(heardTurns) = createHashMap;
[QGVAR(audioChunkSink),  { ["audio",  _this] call FUNC(onClipChunk); }] call CBA_fnc_addEventHandler;
[QGVAR(fillerChunkSink), { ["filler", _this] call FUNC(onClipChunk); }] call CBA_fnc_addEventHandler;

GVAR(streamingClips) = createHashMap;
GVAR(heardSeq) = createHashMap;
GVAR(streamSamples) = createHashMap;
GVAR(streamStart) = createHashMap;
GVAR(fillerCache) = createHashMap;
GVAR(pendingFiller) = createHashMap;
GVAR(cancelledTurns) = createHashMap;
[QGVAR(turnCancelSink), {
    params ["_npcId", ["_turnId", "", [""]]];
    if (_turnId isNotEqualTo "") then {
        GVAR(cancelledTurns) set [[_npcId, _turnId] call FUNC(turnKey), diag_tickTime];
    };
    GVAR(pendingFiller) set [_npcId, 0];
}] call CBA_fnc_addEventHandler;
GVAR(fillerBusyUntil) = createHashMap;
GVAR(streamHeld) = createHashMap;
GVAR(fillerEarlyUntil) = createHashMap;
[QGVAR(streamFrameSink), { _this call FUNC(onStreamFrameClient); }] call CBA_fnc_addEventHandler;
[QGVAR(streamEndSink),   { [_this#0, _this#1, -1, ""] call FUNC(onStreamFrameClient); }] call CBA_fnc_addEventHandler;

GVAR(emotes) = createHashMap;
GVAR(stateHints) = createHashMap;
[QGVAR(guardedStateSink), {
    params ["_npcId", "_cooperation", "_pendingWarning", "_burned", "_disclosedFactIds", "_eligibleFactId", "_mood", "_emote", "_reason", "_evidence", "_classifierMs", "_replyMs"];
    _this call FUNC(consoleApplyGuardedState);
    private _npc = objectFromNetId _npcId;
    if (isNull _npc) exitWith {};
    if (_emote isNotEqualTo "" && {(call CBA_fnc_currentUnit) distance _npc <= GVAR(audioRange)}) then {
        GVAR(emotes) set [_npcId, [_npc, _emote, diag_tickTime + GVAR(emoteHold)]];
    };
    if !(missionNamespace getVariable [QGVAR(showStateHint), false]) exitWith {};
    private _threat = [["clear", "warned"] select _pendingWarning, "burned"] select _burned;
    GVAR(stateHints) set [_npcId, [
        _npc,
        format ["%1 | %2 | %3 | disclosed %4 | eligible %5 | %6+%7ms", _cooperation, _threat, _mood, ["-", _disclosedFactIds] select (_disclosedFactIds isNotEqualTo ""), ["-", _eligibleFactId] select (_eligibleFactId isNotEqualTo ""), _classifierMs, _replyMs],
        ([_reason, _evidence] select { _x isNotEqualTo "" }) joinString " | ",
        diag_tickTime + GVAR(hintHold)
    ]];
}] call CBA_fnc_addEventHandler;
[QGVAR(debugStateSink), {_this call FUNC(consoleApplyDebugState)}] call CBA_fnc_addEventHandler;
[QGVAR(consoleClearStateSink), {GVAR(consoleStates) deleteAt (_this#0)}] call CBA_fnc_addEventHandler;
[QGVAR(consoleClearPendingSink), {
    if !((_this#0) in GVAR(consoleStates)) exitWith {};
    private _state = [_this#0] call FUNC(consoleGetState);
    _state set ["pendingWarning", false];
    _state set ["eligible", ""];
    _state set ["tag", ""];
    _state set ["reason", ""];
    _state set ["evidence", ""];
}] call CBA_fnc_addEventHandler;
[QGVAR(consoleSttSink), {
    params ["_npcId", "_text", "_addressed"];
    if !(_npcId in GVAR(consoleStates)) exitWith {};
    private _state = [_npcId] call FUNC(consoleGetState);
    _state set ["lastStt", _text];
    _state set ["addressed", _addressed];
}] call CBA_fnc_addEventHandler;

if (isServer) then {
    GVAR(rooms) = createHashMap;
    GVAR(roomTimers) = createHashMap;
    GVAR(lastSpeaker) = createHashMap;
    GVAR(watchUntil) = createHashMap;
    GVAR(activeTurnIds) = createHashMap;
    GVAR(pendingRegister) = [];
    missionNamespace setVariable [QGVAR(registeredNetIds), [], true];
    missionNamespace setVariable [QGVAR(talkerNetIds), [], true];
    missionNamespace setVariable [QGVAR(mutedNetIds), [], true];
    [QGVAR(utterance), { _this call FUNC(onUtterance); }] call CBA_fnc_addEventHandler;
    [QGVAR(consoleAction), { _this call FUNC(consoleServerAction); }] call CBA_fnc_addEventHandler;
    [QGVAR(consoleSubscribe), {
        params ["_player", "_key", "_state"];
        if (isNull _player || {!(_player in ALL_PLAYERS)}) exitWith {};
        private _authorised = (getPlayerUID _player) in WHITELIST || {admin (owner _player) > 0};
        if (!_authorised) exitWith {};
        [GVAR(consoleClients), _player, _key, _state] call EFUNC(common,streamClientsSet);
    }] call CBA_fnc_addEventHandler;
    [QGVAR(requestFillers), { _this call FUNC(pushFillersToClient); }] call CBA_fnc_addEventHandler;
    [QGVAR(register), { _this call FUNC(onUnitInit); }] call CBA_fnc_addEventHandler;
    [QGVAR(setTalkable), { _this call FUNC(setTalkable); }] call CBA_fnc_addEventHandler;
    GVAR(rxBuffers) = createHashMap;
    GVAR(rxBufferTimes) = createHashMap;
    [QEGVAR(api,command), { _this call FUNC(onApiCommand); }] call CBA_fnc_addEventHandler;
    GVAR(activeClips) = createHashMap;
    [QGVAR(requestClip), { _this call FUNC(onRequestClip); }] call CBA_fnc_addEventHandler;
    [QGVAR(guardedReset), {
        params ["_npcId"];
        if !(missionNamespace getVariable [QGVAR(allowGuardedReset), false]) exitWith {
            WARNING_1("guarded reset refused: this mission does not enable it (%1)",_npcId);
        };
        private _npc = objectFromNetId _npcId;
        if (isNull _npc) exitWith { WARNING_1("guarded reset for unknown netId: %1",_npcId); };
        if !(_npc getVariable [QGVAR(talkable), false]) exitWith {
            WARNING_1("guarded reset refused: npc is not talkable (%1)",_npcId);
        };
        if ((_npc getVariable [QGVAR(interactionProfile), "conversation"]) isNotEqualTo "guarded") exitWith {
            WARNING_1("guarded reset refused: npc is not a guarded source (%1)",_npcId);
        };
        TRACE_1("guarded reset requested",_npcId);
        [_npc, true] call FUNC(registerNpc);
    }] call CBA_fnc_addEventHandler;
    GVAR(activeStreams) = createHashMap;
};

#include "initSettings.inc.sqf"

ADDON = true;
