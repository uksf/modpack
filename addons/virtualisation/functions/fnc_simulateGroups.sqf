#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sim tick orchestrator. Advances the chunk cursor each tick and processes
        a slice of simulatedGroupIds (~10% per tick → full pass every ~30s).
        Dispatches per-group sim advance via fnc_simulateGroup and writes
        updated positions back into groupPositionMap.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_virtualisation_fnc_simulateGroups
*/
if (count GVAR(simulatedGroupIds) == 0) exitWith {};

GVAR(simChunkCursor) = (GVAR(simChunkCursor) + 1) mod SIM_CHUNK_COUNT;

private _sliceSize = ceil ((count GVAR(simulatedGroupIds)) / SIM_CHUNK_COUNT);
private _start = GVAR(simChunkCursor) * _sliceSize;

{
    private _id = _x;
    private _entry = GVAR(groupDataMap) get _id;
    if (isNil "_entry") then { continue };

    private _newPosition = [_id, _entry] call FUNC(simulateGroup);
    if (!isNil "_newPosition") then {
        private _positionIndex = GVAR(groupPositionMap) findIf {(_x#0) == _id};
        if (_positionIndex >= 0) then {
            (GVAR(groupPositionMap) select _positionIndex) set [1, _newPosition];
        };
    };
} forEach (GVAR(simulatedGroupIds) select [_start, _sliceSize]);
