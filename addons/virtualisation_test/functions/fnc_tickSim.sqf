#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Forces N sim advances on a single virtualised group, bypassing the
        SIM_INTERVAL gate by rewinding lastSimTime, and the chunk slicing by
        calling fnc_simulateGroup directly. Updates groupPositionMap to mirror
        the orchestrator. Used by tests to advance sim deterministically.

    Parameter(s):
        0: Group id <STRING>
        1: Number of advances <NUMBER>
        2: Faked delta seconds per advance <NUMBER> (Optional, default 31)

    Return Value:
        Final position or nil <ARRAY>

    Example:
        [_id, 5] call uksf_virtualisation_test_fnc_tickSim
*/
params ["_id", "_count", ["_fakedDelta", 31]];

private _result = nil;

for "_i" from 1 to _count do {
    private _entry = EGVAR(virtualisation,groupDataMap) get _id;
    if (isNil "_entry") exitWith {};

    _entry set [7, CBA_missionTime - _fakedDelta];

    private _newPosition = [_id, _entry] call EFUNC(virtualisation,simulateGroup);
    if (!isNil "_newPosition") then {
        _result = _newPosition;
        private _positionIndex = EGVAR(virtualisation,groupPositionMap) findIf {(_x#0) == _id};
        if (_positionIndex >= 0) then {
            (EGVAR(virtualisation,groupPositionMap) select _positionIndex) set [1, _newPosition];
        };
    };
};

_result
