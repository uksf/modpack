#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Builds the passive card text for up to three nearby talkable NPCs.
*/
params ["_position", ["_maximumDistance", HEARING_RADIUS, [0]]];

private _npcs = (missionNamespace getVariable [QGVAR(talkerNetIds), []]) apply {objectFromNetId _x};
_npcs = _npcs select {!isNull _x && {alive _x} && {_x getVariable [QGVAR(talkable), false]} && {_position distance _x <= _maximumDistance}};
_npcs = [_npcs, [], {_position distance _x}, "ASCEND"] call BIS_fnc_sortBy;
_npcs resize ((count _npcs) min CONSOLE_CARD_COUNT);

private _cards = _npcs apply {
    private _npc = _x;
    private _npcId = netId _npc;
    private _state = [_npcId] call FUNC(consoleGetState);
    private _name = _npc getVariable [QGVAR(personaName), name _npc];
    private _profile = _npc getVariable [QGVAR(interactionProfile), "conversation"];
    private _cooperation = _state getOrDefault ["cooperation", ""];
    private _mood = _state getOrDefault ["mood", _npc getVariable [QGVAR(personaMood), "neutral"]];
    private _status = "idle";
    if ((GVAR(fillerBusyUntil) getOrDefault [_npcId, 0]) > diag_tickTime) then {
        _status = "filler";
    } else {
        if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > diag_tickTime) then {
            _status = "speaking";
        } else {
            if ((GVAR(pendingFiller) getOrDefault [_npcId, 0]) isNotEqualTo 0) then {_status = "waiting"};
        };
    };
    private _accent = ["#c8d0d8", "#ffd36a"] select (_npc isEqualTo GVAR(targetNpc));
    format [
        "<t color='%1' size='1.05'>%2</t><br/><t color='#94a3b8'>%3 | %4 | %5</t>",
        _accent,
        [_name] call FUNC(consoleEscape),
        _profile,
        [_mood, format ["%1 %2", _mood, _cooperation]] select (_cooperation isNotEqualTo ""),
        _status
    ]
};

_cards joinString "<br/><br/>"
