#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server-side. Builds and sends one NPC's npc_register payload. Split out from
        fnc_registerNpcs so a guarded source can be re-registered on its own, which is how
        the test reset clears guarded state without restarting the mission.

    Parameter(s):
        0: NPC <OBJECT>
        1: Reset guarded state and history <BOOL> (Optional, default false)

    Return Value:
        Whether the NPC was registered <BOOL>

    Example:
        [_npc, true] call uksf_npc_fnc_registerNpc
*/
if (!isServer) exitWith { false };

params ["_npc", ["_reset", false, [false]]];

private _sessionId = EGVAR(api,sessionId);
if (isNil "_sessionId") exitWith { TRACE_1("no session id, skipping npc register",_npc); false };

private _mode = _npc getVariable [QGVAR(mode), "dynamic"];
// Older missions set no profile at all, so the default has to be the behaviour they had.
private _profile = _npc getVariable [QGVAR(interactionProfile), "conversation"];

// Validated before anything is sent: an unregistered NPC is a clearer failure than one the
// API has already warmed and prerendered against authoring it cannot gate.
private _guarded = [];
if (_profile isEqualTo "guarded") then { _guarded = [_npc] call FUNC(guardedConfig); };
if (_profile isEqualTo "guarded" && {_guarded isEqualTo []}) exitWith {
    WARNING_1("npc %1 not registered: invalid guarded source authoring",netId _npc);
    false
};

private _persona = createHashMapFromArray [
    ["name", _npc getVariable [QGVAR(personaName), ""]],
    ["role", _npc getVariable [QGVAR(personaRole), ""]],
    ["language", _npc getVariable [QGVAR(personaLanguage), ""]],
    ["mood", _npc getVariable [QGVAR(personaMood), ""]],
    ["attitudeToPlayers", _npc getVariable [QGVAR(personaAttitude), ""]]
];

private _data = createHashMapFromArray [
    ["npcId", netId _npc],
    ["sessionId", _sessionId],
    ["persona", _persona],
    ["knowledge", _npc getVariable [QGVAR(knowledge), ""]],
    ["mode", _mode],
    ["interactionProfile", _profile],
    ["voiceId", _npc getVariable [QGVAR(voiceId), ""]]
];

if (_mode isEqualTo "scripted") then {
    private _lines = [];
    for "_i" from 1 to 6 do {
        private _topic = _npc getVariable [format ["%1%2", QGVAR(scriptedTopic), _i], ""];
        private _line = _npc getVariable [format ["%1%2", QGVAR(scriptedLine), _i], ""];
        if (_line isNotEqualTo "") then {
            _lines pushBack createHashMapFromArray [
                ["id", format ["s%1", _i]],
                ["topic", _topic],
                ["line", _line]
            ];
        };
    };
    _data set ["scripted", createHashMapFromArray [
        ["lines", _lines],
        ["deflection", _npc getVariable [QGVAR(deflection), ""]]
    ]];
};

if (_profile isEqualTo "guarded") then {
    _data set ["guarded", _guarded];
    // Only an explicit reset may wipe cooperation, warning, burned state and the ledger.
    // A duplicate registration on its own must leave the interaction where the player left it.
    _data set ["resetGuarded", _reset];
};

["npc_register", _data] call EFUNC(api,sendEvent);
TRACE_3("registered npc",netId _npc,_mode,_profile);
true
