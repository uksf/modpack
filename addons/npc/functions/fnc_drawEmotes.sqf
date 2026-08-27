#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client Draw3D handler. Renders the guarded source's floating emote above the NPC, and
        under it the compact state hint when a test mission has asked for one. Emote text is
        feedback the player reads, never something the NPC says, so it never touches the
        audio path.

        Entries expire on their own deadline and are dropped here, so a dead or despawned NPC
        leaves nothing drawn and nothing held.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_drawEmotes
*/

if ((count GVAR(emotes)) + (count GVAR(stateHints)) == 0) exitWith {};

private _now = diag_tickTime;

// keys returns a snapshot, so an expired entry can be deleted while iterating.
{
    (GVAR(emotes) get _x) params ["_npc", "_text", "_expiry"];
    if (_now > _expiry || {isNull _npc} || {!alive _npc}) then { GVAR(emotes) deleteAt _x; continue };
    drawIcon3D ["", [1, 0.85, 0.4, 1], (getPosVisual _npc) vectorAdd [0, 0, EMOTE_HEIGHT], 0, 0, 0, _text, 1, 0.04, "RobotoCondensed", "center", false];
} forEach (keys GVAR(emotes));

{
    (GVAR(stateHints) get _x) params ["_npc", "_state", "_detail", "_expiry"];
    if (_now > _expiry || {isNull _npc} || {!alive _npc}) then { GVAR(stateHints) deleteAt _x; continue };
    private _position = (getPosVisual _npc) vectorAdd [0, 0, EMOTE_HEIGHT];
    drawIcon3D ["", [0.7, 0.85, 1, 1], _position, 0, 0, 0, _state, 1, 0.028, "RobotoCondensed", "center", false, 0, 30];
    if (_detail isNotEqualTo "") then {
        drawIcon3D ["", [0.7, 0.85, 1, 0.8], _position, 0, 0, 0, _detail, 1, 0.024, "RobotoCondensed", "center", false, 0, 55];
    };
} forEach (keys GVAR(stateHints));
