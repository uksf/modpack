#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Pure helper. Returns whether the player is within range and the FOV cone
        of the NPC (i.e. the player is looking at the NPC from close enough).

    Parameter(s):
        0: Player <OBJECT>
        1: NPC <OBJECT>

    Return Value:
        Whether the player is addressing the NPC <BOOL>

    Example:
        [player, _npc] call uksf_npc_fnc_isInGate
*/
params ["_player", "_npc"];

private _range = _npc getVariable [QGVAR(gateRange), 4];
if ((_player distance _npc) > _range) exitWith { false };

private _fov = _npc getVariable [QGVAR(gateFov), 90];
private _toNpc = (eyePos _npc) vectorDiff (eyePos _player);
if (_toNpc isEqualTo [0,0,0]) exitWith { true };
private _forward = eyeDirection _player;
private _dot = _forward vectorDotProduct (vectorNormalized _toNpc);
// Full-angle FOV -> half-angle cosine threshold
_dot >= (cos (_fov / 2))
