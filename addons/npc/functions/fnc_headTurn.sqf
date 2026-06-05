#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Runs on the NPC owner (server or headless client). Turns the NPC to watch
        the addresser for the clip duration, then releases. doWatch is Argument-Local
        so this function must execute where the NPC is local — it is only ever invoked
        via CBA_fnc_targetEvent targeting the NPC object, which routes accordingly.
        Effect is Global so all clients see the head-turn without further broadcasting.

    Parameter(s):
        0: npc <OBJECT>
        1: speaker <OBJECT>
        2: duration in milliseconds <NUMBER>

    Return Value:
        none

    Example:
        [_npc, _speaker, _durationMs] call uksf_npc_fnc_headTurn
*/
params ["_npc", "_speaker", "_durationMs"];
if (isNull _npc || {!alive _npc}) exitWith {};

if (!isNull _speaker) then { _npc doWatch _speaker; };

[{
    params ["_npc"];
    if (isNull _npc) exitWith {};
    _npc doWatch objNull;
}, [_npc], (_durationMs / 1000) max 0.5] call CBA_fnc_waitAndExecute;
