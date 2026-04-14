#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns garrison groups in chunks directly at helper positions.

    Parameters:
        0: Module logic <OBJECT>
        1: Remaining position count to occupy <NUMBER>
        2: Group side <SIDE>
        3: Unit class pool <ARRAY>

    Return Value:
        Nothing

    Example:
        [_logic, _remainingCount, _side, _unitList] call uksf_autoplace_fnc_spawnGarrisonGroups
*/
#define MAX_GROUP_SIZE 10

params ["_logic", "_remainingCount", "_side", "_unitList"];

if (isNull _logic) exitWith {};
if (_remainingCount <= 0) exitWith {
    [_logic] call FUNC(finaliseAutoplace);
};
if (_unitList isEqualTo []) exitWith {
    [_logic] call FUNC(finaliseAutoplace);
};

private _availablePositions = _logic getVariable [QGVAR(availablePositions), []];
if (_availablePositions isEqualTo []) exitWith {
    [_logic] call FUNC(finaliseAutoplace);
};

private _groupSize = _remainingCount min MAX_GROUP_SIZE;
_groupSize = _groupSize min (count _availablePositions);
if (_groupSize <= 0) exitWith {
    [_logic] call FUNC(finaliseAutoplace);
};

private _group = createGroup _side;
_group deleteGroupWhenEmpty true;

private _assignedCount = 0;
for "_index" from 0 to (_groupSize - 1) do {
    private _positionData = _availablePositions deleteAt 0;
    private _position = [0, 0, 0];
    private _direction = 0;
    if (_positionData isEqualType []) then {
        if (count _positionData >= 2 && {(_positionData#0) isEqualType []}) then {
            _position = _positionData#0;
            _direction = _positionData#1;
        } else {
            _position = _positionData;
        };
    };

    private _unit = _group createUnit [selectRandom _unitList, _position, [], 0, "NONE"];

    if (!isNull _unit) then {
        _unit setPosATL _position;
        _unit setDir _direction;
        _unit disableAI "PATH";
        _assignedCount = _assignedCount + 1;
    };
};

_logic setVariable [QGVAR(availablePositions), _availablePositions, false];

private _remainingAfterSpawn = _remainingCount - _assignedCount;
if (_remainingAfterSpawn > 0) then {
    [_logic, _remainingAfterSpawn, _side, _unitList] call FUNC(spawnGarrisonGroups);
} else {
    [_logic] call FUNC(finaliseAutoplace);
};
