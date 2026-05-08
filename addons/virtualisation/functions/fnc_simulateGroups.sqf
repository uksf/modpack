#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sim tick orchestrator. Cursor advances each tick (mod SIM_INTERVAL).
        Processes only groups whose simPhase matches the cursor — phases are
        assigned at virtualisation time and never change, so each group ticks
        exactly once per SIM_INTERVAL ticks regardless of insertions or
        removals between ticks. New groups are assigned a phase != current
        cursor so they tick within at most SIM_INTERVAL ticks.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_virtualisation_fnc_simulateGroups
*/
if (count GVAR(simulatedGroupIds) == 0) exitWith {};

GVAR(simCursor) = (GVAR(simCursor) + 1) mod SIM_INTERVAL;
private _cursor = GVAR(simCursor);

{
    private _id = _x;
    if ((GVAR(simPhases) getOrDefault [_id, -1]) != _cursor) then { continue };

    private _entry = GVAR(groupDataMap) get _id;
    if (isNil "_entry") then { continue };

    private _newPosition = [_id, _entry] call FUNC(simulateGroup);
    if (!isNil "_newPosition") then {
        private _positionIndex = GVAR(groupPositionMap) findIf {(_x#0) == _id};
        if (_positionIndex >= 0) then {
            (GVAR(groupPositionMap) select _positionIndex) set [1, _newPosition];
        };
    };
} forEach GVAR(simulatedGroupIds);
