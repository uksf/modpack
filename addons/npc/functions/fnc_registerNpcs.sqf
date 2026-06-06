#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server-side. Scans all units for the uksf_npc_talkable attribute and
        registers each with the API broker (npc_register). npcId = netId.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_registerNpcs
*/

if (!isServer) exitWith {};

private _sessionId = EGVAR(api,sessionId);
if (isNil "_sessionId") exitWith { TRACE_1("no session id, skipping npc register",_sessionId); };

{
    private _npc = _x;
    if !(_npc getVariable [QGVAR(talkable), false]) then { continue };

    private _mode = _npc getVariable [QGVAR(mode), "dynamic"];

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

    ["npc_register", _data] call EFUNC(api,sendEvent);
    TRACE_2("registered npc",netId _npc,_mode);
} forEach allUnits;
