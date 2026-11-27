#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Pure helper. Returns whether the player is within range and the FOV cone
        of the NPC (i.e. the player is looking at the NPC from close enough).

    Parameters:
        0: Player <OBJECT>
        1: NPC <OBJECT>

    Return value:
        Whether the NPC is in range and in view <BOOL>

    Example:
        [player, cursorObject] call uksf_npc_fnc_isInGate
*/
params ["_player", "_npc"];

private _range = _npc getVariable [QGVAR(gateRange), GVAR(gateRange)];
if (_range < 0 || {(_player distanceSqr _npc) > (_range * _range)}) exitWith { false };

private _fov = _npc getVariable [QGVAR(gateFov), GVAR(gateFov)];
private _toNpc = (eyePos _npc) vectorDiff (eyePos _player);
if (_toNpc isEqualTo [0,0,0]) exitWith { true };
private _forward = eyeDirection _player;
private _dot = _forward vectorDotProduct (vectorNormalized _toNpc);
_dot >= (cos (_fov / 2))
