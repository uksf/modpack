#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server-side. Builds and sends one NPC's npc_register payload. Ordinary
        registration skips the API when the id is already registered. Reset is
        the only path that may wipe guarded state.

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
if (isNull _npc || {!alive _npc}) exitWith { false };

private _sessionId = EGVAR(api,sessionId);
if (isNil "_sessionId") exitWith { TRACE_1("no session id, skipping npc register",_npc); false };

private _npcId = netId _npc;
private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
if (_reset) then {
    _npc setVariable [QGVAR(playerDropped), false, true];
    _npc setVariable [QGVAR(talkable), true, true];
    private _muted = (missionNamespace getVariable [QGVAR(mutedNetIds), []]) - [_npcId];
    missionNamespace setVariable [QGVAR(mutedNetIds), _muted, true];
};

if (_npcId in _registered && {!_reset}) exitWith {
    [_npcId, true] call FUNC(setTalkerList);
    true
};

private _mode = _npc getVariable [QGVAR(mode), "dynamic"];
private _profile = _npc getVariable [QGVAR(interactionProfile), "conversation"];

private _guarded = [];
if (_profile isEqualTo "guarded") then { _guarded = [_npc] call FUNC(guardedConfig); };
if (_profile isEqualTo "guarded" && {_guarded isEqualTo []}) exitWith {
    WARNING_1("npc %1 not registered: invalid guarded source authoring",_npcId);
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
    ["npcId", _npcId],
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
    _data set ["resetGuarded", _reset];
};

["npc_register", _data] call EFUNC(api,sendEvent);
_registered pushBackUnique _npcId;
missionNamespace setVariable [QGVAR(registeredNetIds), _registered, true];
[_npcId, true] call FUNC(setTalkerList);
call FUNC(sttPublishNames);
TRACE_3("registered npc",_npcId,_mode,_profile);
true
