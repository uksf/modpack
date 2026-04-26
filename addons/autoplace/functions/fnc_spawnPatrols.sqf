#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns patrol groups and assigns taskPatrol. Uses getSafePositionGrid for candidate positions so
        patrols do not spawn on water or inside objects, then filters to the module area shape.

    Parameters:
        0: Module logic <OBJECT>
        1: Area array <ARRAY>
        2: Number of patrol groups <NUMBER>
        3: Group side <SIDE>
        4: Unit class pool <ARRAY>
        5: Patrol radius <NUMBER>
        6: Patrol unit count <NUMBER>

    Return Value:
        Nothing

    Example:
        [_logic, _area, _numberOfPatrols, _side, _unitList, _patrolRadius, _patrolUnitCount] call uksf_autoplace_fnc_spawnPatrols
*/
#define GRID_SPACING 16
#define MIN_OBJECT_DISTANCE 3

params ["_logic", "_area", "_numberOfPatrols", "_side", "_unitList", "_patrolRadius", "_patrolUnitCount"];

if (isNull _logic) exitWith {};
if (_area isEqualTo []) exitWith {};
if (_numberOfPatrols <= 0) exitWith {};
if (_unitList isEqualTo []) exitWith {};

private _groupSize = (_patrolUnitCount max 1) min MAX_GROUP_SIZE;
private _centre = getPosATL _logic;

private _safePositions = [_centre, GRID_SPACING, 0, 0, MIN_OBJECT_DISTANCE, _area] call EFUNC(common,getSafePositionGrid);

if (_safePositions isEqualTo []) exitWith {
    WARNING_1("Autoplace found no safe patrol spawn positions: %1",_logic);
};

for "_patrolIndex" from 1 to _numberOfPatrols do {
    private _spawnPosition = selectRandom _safePositions;

    [_spawnPosition, _groupSize, _side, _unitList, {
        params ["_spawnPosition", "_patrolRadius", "_group"];
        if (isNull _group) exitWith {};
        [_group, _spawnPosition, _patrolRadius, floor(3 + random 3), "MOVE", "SAFE", "YELLOW", "NORMAL", "COLUMN"] call EFUNC(common,taskPatrol);
    }, [_spawnPosition, _patrolRadius], false, false] call EFUNC(common,spawnGroupInfantry);
};
