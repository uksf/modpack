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

private _leader = leader _group;
// private _commanderSkill = skill _leader; // TODO: Not used

private _vehicle = vehicle _leader;
private _type = typeOf _vehicle;
private _position = getPosATL _vehicle;
private _direction = getDir _vehicle;
private _engineState = isEngineOn _vehicle;
private _fuel = fuel _vehicle; // needed for vehicles made to be static
private _crewTypes = (fullCrew _vehicle) select {typeOf _x#0}; // [[unit, role, cargoIndex, turretPath, personTurret, assignedUnit],  [unit, role, cargoIndex, turretPath, personTurret, assignedUnit]]

[_type, _position, _direction, _engineState, _fuel, _crewTypes]
