#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Gets vehicle details
       Updates the full crew array to use unit type instead of unit
       unit is an object which will be null once the group is stored and deleted
       needs to be unit type so unit can be recreated

    Parameters:
        0: group <OBJECT>

    Return value:
        _unitDetails
*/
params ["_group"];

private _vehicle = vehicle leader _group;
private _vehiclePos = getPosATL _vehicle;
private _vehicleDir = getDir _vehicle;
private _vehicleType = typeOf _vehicle;
private _engineState = isEngineOn _vehicle;
private _fuelLevel = fuel _vehicle; // needed for vehicles made to be static
private _fullCrew = fullCrew _vehicle; // [[unit, role, cargoIndex, turretPath, personTurret, assignedUnit],  [unit, role, cargoIndex, turretPath, personTurret, assignedUnit]]
// update the fullcrew array
{
    _x set [0, typeOf (_x#0)];
} forEach _fullCrew;
private _commanderSkill = skill (leader _group);

private _unitDetails = [_vehiclePos, _vehicleDir, _vehicleType, _engineState, _fuelLevel, _fullCrew, _commanderSkill];

_unitDetails
