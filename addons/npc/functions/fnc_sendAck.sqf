#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Tells the API trace whether Arma accepted an NPC command. The
        extension queues the event, so this never waits on the API.

    Parameter(s):
        0: NPC net ID <STRING>
        1: Turn ID <STRING>
        2: Kind: stream, streamEnd, clip, state, emote or cancel <STRING>
        3: Reason, empty when accepted <STRING>
        4: Players the command went to <NUMBER>

    Return Value:
        None

    Example:
        [_npcId, _turnId, "stream", "", count _targets] call uksf_npc_fnc_sendAck
*/
params ["_npcId", "_turnId", "_kind", ["_reason", "", [""]], ["_targets", 0, [0]]];

private _event = createHashMapFromArray [
    ["sessionId", EGVAR(api,sessionId)],
    ["npc", _npcId],
    ["turn", _turnId],
    ["kind", _kind],
    ["ok", _reason isEqualTo ""],
    ["targets", _targets]
];
if (_reason isNotEqualTo "") then { _event set ["reason", _reason] };
["npc_ack", _event] call EFUNC(api,sendEvent);
