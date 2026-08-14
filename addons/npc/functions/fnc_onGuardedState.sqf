#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Handles the npc_guarded_state command: the API's account of the guarded turn
        it has just spoken. Carries no canonical fact text — only the disclosed fact's id — so
        nothing here can leak intel the player has not earned.

        Every field is validated before anything leaves the server: the payload shape, each
        field's type, the fixed enums, the fact ids, and the timings. A payload that fails any
        of it is dropped whole, so a malformed or forged command cannot draw arbitrary text on
        a client or carry an unbounded id list to one. Free text is clamped, then the result
        goes to the clients already in audio range, which is the same set that heard the reply.

        Wire shape, one command per emitted guarded turn:
            ["npc_guarded_state", npcId, cooperation, pendingWarning, burned,
             disclosedFactIds, eligibleFactId, mood, emote, reason, evidence,
             classifierMs, replyMs]
        cooperation is one of closed/guarded/engaged/cooperative, mood one of
        neutral/angry/afraid/sad/happy, and disclosedFactIds a comma-separated list of g1-g3.
        Trailing fields beyond the last one read here are ignored, so the API can extend the
        command without breaking an older mission build.

    Parameter(s):
        0: Args <ARRAY> (from the QEGVAR(api,command) payload tail)

    Return Value:
        None

    Example:
        [_args] call uksf_npc_fnc_onGuardedState
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

// Types before values: params defaults would quietly stand in for a wrong type, and a
// substituted field would then be fanned out as if the API had sent it.
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

// Ids only. Nothing here may carry fact text, so anything outside the fixed id set — an
// overlong string, a sentence, a forged slot — takes the whole payload out.
private _factIds = [];
if (_disclosedFactIds isNotEqualTo "") then { _factIds = _disclosedFactIds splitString ","; };
if (_eligibleFactId isNotEqualTo "") then { _factIds pushBack _eligibleFactId; };
if ((_factIds findIf { !(_x in GUARDED_FACT_IDS) }) != -1) exitWith {
    WARNING_2("npc_guarded_state %1 with an unknown fact id: %2",_npcId,_factIds);
};

private _npc = objectFromNetId _npcId;
// A source that has died or gone down is finished for the session, so a state command that
// arrives behind that terminal cleanup renders nothing.
if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {
    TRACE_1("npc_guarded_state for unknown or terminal npc",_npcId);
};

_emote = _emote select [0, EMOTE_MAX];
_reason = _reason select [0, HINT_TEXT_MAX];
_evidence = _evidence select [0, HINT_TEXT_MAX];

private _targets = allPlayers select {
    _x distance _npc <= GVAR(audioRange)
    || {(getPlayerUID _x) in WHITELIST}
    || {admin (owner _x) > 0}
};
if (_targets isEqualTo []) exitWith { TRACE_1("npc_guarded_state with nobody in range",_npcId); };

[
    QGVAR(guardedStateSink),
    [_npcId, _cooperation, _pendingWarning, _burned, _disclosedFactIds, _eligibleFactId, _mood, _emote, _reason, _evidence, _classifierMs, _replyMs],
    _targets
] call CBA_fnc_targetEvent;
TRACE_2("guarded state fanned out",_npcId,count _targets);
