#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Builds and validates the guarded-source block of an NPC's registration
        payload. Runs before the payload is sent, so bad authoring fails loudly at mission
        start instead of half-registering a source the API cannot gate.

        Canonical fact text is engine-owned: the API decides when each fact unlocks and
        composes the sentence itself. A fact repeated in Knowledge or in a topic cue would
        reach the model through the ordinary prompt path and defeat the gate, so that is
        rejected here rather than silently leaked.

    Parameter(s):
        0: NPC <OBJECT>

    Return Value:
        Guarded config <HASHMAP>, or <ARRAY> [] when the authoring is invalid

    Example:
        [_npc] call uksf_npc_fnc_guardedConfig
*/
params ["_npc"];

private _npcId = netId _npc;

// Guarded gating owns what is said, so there is nothing for a fixed scripted line to do.
private _mode = _npc getVariable [QGVAR(mode), "dynamic"];
if (_mode isNotEqualTo "dynamic") exitWith {
    WARNING_2("guarded source %1 rejected: mode is '%2', guarded requires dynamic",_npcId,_mode);
    []
};

private _concern = _npc getVariable [QGVAR(guardedConcern), ""];
if (_concern isEqualTo "") exitWith {
    WARNING_1("guarded source %1 rejected: no guarded concern",_npcId);
    []
};

private _knowledge = toLower (_npc getVariable [QGVAR(knowledge), ""]);
private _facts = [];
private _seen = [];
private _invalid = false;

for "_i" from 1 to GUARDED_FACT_COUNT do {
    private _topic = _npc getVariable [format ["%1%2", QGVAR(guardedTopic), _i], ""];
    private _fact = _npc getVariable [format ["%1%2", QGVAR(guardedFact), _i], ""];
    if (_topic isEqualTo "" || {_fact isEqualTo ""}) then {
        WARNING_2("guarded source %1 rejected: slot %2 needs both a topic and a fact",_npcId,_i);
        _invalid = true;
        continue;
    };

    private _lowerFact = toLower _fact;
    if (_lowerFact in _seen) then {
        WARNING_2("guarded source %1 rejected: slot %2 repeats an earlier fact",_npcId,_i);
        _invalid = true;
        continue;
    };
    if (_knowledge isNotEqualTo "" && {_lowerFact in _knowledge}) then {
        WARNING_2("guarded source %1 rejected: fact %2 also appears in Knowledge",_npcId,_i);
        _invalid = true;
        continue;
    };
    if (_lowerFact in (toLower _topic)) then {
        WARNING_2("guarded source %1 rejected: topic %2 quotes its own fact",_npcId,_i);
        _invalid = true;
        continue;
    };

    _seen pushBack _lowerFact;
    _facts pushBack createHashMapFromArray [
        ["id", format ["g%1", _i]],
        ["topic", _topic],
        ["text", _fact]
    ];
};

if (_invalid) exitWith { [] };

createHashMapFromArray [["concern", _concern], ["facts", _facts]]
