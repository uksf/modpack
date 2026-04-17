#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns patrol groups and assigns taskPatrol.

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
#define MAX_GROUP_SIZE 10

params ["_logic", "_area", "_numberOfPatrols", "_side", "_unitList", "_patrolRadius", "_patrolUnitCount"];

if (isNull _logic) exitWith {};
if (_area isEqualTo []) exitWith {};
if (_numberOfPatrols <= 0) exitWith {};
if (_unitList isEqualTo []) exitWith {};

private _groupSize = (_patrolUnitCount max 1) min MAX_GROUP_SIZE;
private _centre = getPosATL _logic;
_area params ["_a", "_b", "_angle", "_isRectangle"];

for "_patrolIndex" from 1 to _numberOfPatrols do {
    private _spawnPosition = _centre;

    for "_attempt" from 1 to 20 do {
        private _offsetX = 0;
        private _offsetY = 0;

        if (_isRectangle) then {
            _offsetX = random (_a * 2) - _a;
            _offsetY = random (_b * 2) - _b;
        } else {
            private _theta = random 360;
            private _radiusScale = sqrt (random 1);
            _offsetX = (cos _theta) * _a * _radiusScale;
            _offsetY = (sin _theta) * _b * _radiusScale;
        };

        private _rotatedX = (_offsetX * cos _angle) - (_offsetY * sin _angle);
        private _rotatedY = (_offsetX * sin _angle) + (_offsetY * cos _angle);
        private _candidate = [(_centre#0) + _rotatedX, (_centre#1) + _rotatedY, (_centre#2)];

        if (_candidate inArea [_centre, _a, _b, _angle, _isRectangle]) exitWith {
            _spawnPosition = _candidate;
        };
    };

    [_spawnPosition, _groupSize, _side, _unitList, {
        params ["_spawnPosition", "_patrolRadius", "_group"];
        if (isNull _group) exitWith {};
        [_group, _spawnPosition, _patrolRadius, floor(3 + random 3), "MOVE", "SAFE", "YELLOW", "NORMAL", "COLUMN"] call EFUNC(common,taskPatrol);
    }, [_spawnPosition, _patrolRadius]] call EFUNC(common,spawnGroupInfantry);
};
