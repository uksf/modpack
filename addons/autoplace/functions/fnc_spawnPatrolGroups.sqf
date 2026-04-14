#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns patrol groups at remaining helper positions or module centre fallback.

    Parameters:
        0: Module logic <OBJECT>
        1: Number of patrol groups <NUMBER>
        2: Group side <SIDE>
        3: Unit class pool <ARRAY>
        4: Patrol radius <NUMBER>
        5: Patrol unit count <NUMBER>

    Return Value:
        Nothing

    Example:
        [_logic, _numberOfPatrols, _side, _unitList, _patrolRadius, _patrolUnitCount] call uksf_autoplace_fnc_spawnPatrolGroups
*/
#define MAX_GROUP_SIZE 10

params ["_logic", "_numberOfPatrols", "_side", "_unitList", "_patrolRadius", "_patrolUnitCount"];

if (_numberOfPatrols <= 0) exitWith {};
if (_unitList isEqualTo []) exitWith {};
if (isNull _logic) exitWith {};

private _groupSize = (_patrolUnitCount max 1) min MAX_GROUP_SIZE;

for "_patrolIndex" from 1 to _numberOfPatrols do {
    private _availablePositions = _logic getVariable [QGVAR(availablePositions), []];
    private _spawnPosition = getPosATL _logic;

    if (_availablePositions isNotEqualTo []) then {
        private _positionData = _availablePositions deleteAt 0;
        if (_positionData isEqualType [] && {count _positionData >= 2 && {(_positionData#0) isEqualType []}}) then {
            _spawnPosition = _positionData#0;
        } else {
            _spawnPosition = _positionData;
        };
        _logic setVariable [QGVAR(availablePositions), _availablePositions, false];
    };

    [_spawnPosition, _groupSize, _side, _unitList, FUNC(spawnPatrolGroupCallback), [_spawnPosition, _patrolRadius]] call EFUNC(common,spawnGroupInfantry);
};
