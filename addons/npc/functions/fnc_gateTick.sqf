#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Per-frame client gate. Sets GVAR(targetNpc) to the NPC the local player
        is addressing (nearest talkable in range+FOV) or objNull, and drives the
        ACRE mic capture gate on the rising/falling edge.

    Parameter(s):
        0: PFH args <ARRAY>
        1: PFH id <NUMBER>
*/
params ["", "_idPFH"];

private _player = call CBA_fnc_currentUnit;
private _best = objNull;
if (alive _player) then {
    private _nearest = 1e9;
    {
        if (_x getVariable [QGVAR(talkable), false] && {[_player, _x] call FUNC(isInGate)}) then {
            private _distance = _player distance _x;
            if (_distance < _nearest) then { _nearest = _distance; _best = _x; };
        };
    } forEach (_player nearEntities [["CAManBase"], GATE_SCAN_RADIUS]);
};

if (_best isEqualTo GVAR(targetNpc)) exitWith {};

GVAR(targetNpc) = _best;
private _hasTarget = !isNull _best;
if (_hasTarget isEqualTo GVAR(micGateOpen)) exitWith {};
GVAR(micGateOpen) = _hasTarget;
[_hasTarget] call acre_sys_core_fnc_setMicCaptureGate;
TRACE_2("mic gate",_hasTarget,_best);
