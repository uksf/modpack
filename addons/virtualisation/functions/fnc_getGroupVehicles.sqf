#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets vehicle for a group

    Parameters:
        0: Group <GROUP>

    Return value:
        Array of vehicle details <ARRAY>
        [[_type, _position, _direction, _engineState, _fuel, _crewTypes], [...]]
*/
params ["_group"];

private _vehicles = [];

// Get vehicles that group units are in
private _unitsInVehicles = (units _group) select {alive _x && vehicle _x != _x};
{
    _vehicles pushBackUnique (vehicle _x);
} forEach _unitsInVehicles;

// Get vehicles that are assigned to the group (this should include any fully dismounted vehicles)
{
    _vehicles pushBackUnique _x;
} forEach (assignedVehicles _group);

_vehicles
