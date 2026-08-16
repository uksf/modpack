#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Handles the npc_guarded_state command. Emotes go to players in
        audio range. Inspector telemetry goes only to subscribed console clients.
*/
if (!isServer) exitWith {};

params ["_args"];

if (!(_args isEqualType []) || {count _args < GUARDED_STATE_FIELDS}) exitWith {
    WARNING_1("npc_guarded_state with unexpected shape: %1",_args);
};

_args params [
    "_npcId", "_cooperation", "_pendingWarning", "_burned", "_disclosedFactIds", "_eligibleFactId",
    "_mood", "_emote", "_reason", "_evidence", "_classifierMs", "_replyMs"
];

private _strings = [_npcId, _cooperation, _disclosedFactIds, _eligibleFactId, _mood, _emote, _reason, _evidence];
if ((_strings findIf { !(_x isEqualType "") }) != -1) exitWith {
    WARNING_1("npc_guarded_state with a non-string field: %1",_args);
};
if ((([_pendingWarning, _burned] findIf { !(_x isEqualType false) }) != -1)) exitWith {
    WARNING_2("npc_guarded_state threat state is not boolean: %1 %2",_pendingWarning,_burned);
};
if ((([_classifierMs, _replyMs] findIf { !(_x isEqualType 0) || {_x < 0} }) != -1)) exitWith {
    WARNING_2("npc_guarded_state timings are not non-negative numbers: %1 %2",_classifierMs,_replyMs);
};

if (_npcId isEqualTo "") exitWith { WARNING_1("npc_guarded_state with no npcId: %1",_args); };
if !(_cooperation in GUARDED_BANDS) exitWith { WARNING_2("npc_guarded_state %1 with unknown cooperation band: %2",_npcId,_cooperation); };
if !(_mood in GUARDED_MOODS) exitWith { WARNING_2("npc_guarded_state %1 with unknown mood: %2",_npcId,_mood); };

private _factIds = [];
if (_disclosedFactIds isNotEqualTo "") then { _factIds = _disclosedFactIds splitString ","; };
if (_eligibleFactId isNotEqualTo "") then { _factIds pushBack _eligibleFactId; };
if ((_factIds findIf { !(_x in GUARDED_FACT_IDS) }) != -1) exitWith {
    WARNING_2("npc_guarded_state %1 with an unknown fact id: %2",_npcId,_factIds);
};

private _npc = objectFromNetId _npcId;
if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {
    TRACE_1("npc_guarded_state for unknown or terminal npc",_npcId);
};

_emote = _emote select [0, EMOTE_MAX];
_reason = _reason select [0, HINT_TEXT_MAX];
_evidence = _evidence select [0, HINT_TEXT_MAX];

private _payload = [_npcId, _cooperation, _pendingWarning, _burned, _disclosedFactIds, _eligibleFactId, _mood, _emote, _reason, _evidence, _classifierMs, _replyMs];
private _targets = ALL_PLAYERS select { _x distance _npc <= GVAR(audioRange) };
{ _targets pushBackUnique _x } forEach ([GVAR(consoleClients)] call EFUNC(common,streamClientsTargets));
if (_targets isNotEqualTo []) then {
    [QGVAR(guardedStateSink), _payload, _targets] call CBA_fnc_targetEvent;
};
TRACE_2("guarded state fanned out",_npcId,count _targets);
