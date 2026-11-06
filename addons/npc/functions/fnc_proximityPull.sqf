#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Iterates the server-broadcast talkable NPC list (no nearEntities
        scan), pruning null/dead, and on the rising edge of entering an NPC's
        audio range requests its in-flight clip from the server so a late joiner
        hears the current sentence from the right offset. Per-NPC debounced.
        Prunes heard and cancelled turn ids older than 60 s, even while dead,
        and syncs the STT mic gate to NPC range.

    Parameter(s):
        0: PFH args <ARRAY>
        1: PFH id <NUMBER>

    Return Value:
        None

    Example:
        [uksf_npc_fnc_proximityPull, 0.5, []] call CBA_fnc_addPerFrameHandler
*/
params ["", "_idPFH"];

{ if (diag_tickTime - _y > 60) then { GVAR(heardTurns) deleteAt _x; }; } forEach GVAR(heardTurns);
{ if (diag_tickTime - _y > 60) then { GVAR(cancelledTurns) deleteAt _x; }; } forEach GVAR(cancelledTurns);

call FUNC(sttSync);

private _player = call CBA_fnc_currentUnit;
if (!alive _player) exitWith { GVAR(nearTalkers) = []; };

private _range = missionNamespace getVariable [QGVAR(audioRange), 30];
private _ids = missionNamespace getVariable [QGVAR(talkerNetIds), []];
private _near = [];
{
    private _npc = objectFromNetId _x;
    if (isNull _npc || {!alive _npc} || {_npc distance _player > _range}) then { continue };
    _near pushBack _x;
    if !(_x in GVAR(nearTalkers)) then {
        if (diag_tickTime - (GVAR(lastRequest) getOrDefault [_x, -1e9]) > 3) then {
            GVAR(lastRequest) set [_x, diag_tickTime];
            [QGVAR(requestClip), [_x, _player]] call CBA_fnc_serverEvent;
        };
    };
} forEach _ids;
GVAR(nearTalkers) = _near;
