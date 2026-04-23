#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns a vehicle patrol and delegates waypointing.

    Parameters:
        0: Spawn position <ARRAY>
        1: Destination position <ARRAY>
        2: Unit class pool <ARRAY>
        3: Vehicle class pool <ARRAY>
        4: Side <SIDE>
        5: Fill percentage <NUMBER>
        6: Waypoint behaviour <STRING>
        7: Waypoint speed <STRING>
        8: Turn around <BOOL>

    Return Value:
        Nothing

    Example:
        [_spawnPosition, _destinationPosition, _unitClasses, _vehicleClasses, _side, _fillPercentage, _waypointBehaviour, _waypointSpeed, _turnAround] call uksf_vehiclepatrols_fnc_spawnPatrol
*/

params [
    ["_spawnPosition", [], [[]]],
    ["_destinationPosition", [], [[]]],
    ["_unitClasses", [], [[]]],
    ["_vehicleClasses", [], [[]]],
    ["_side", east, [sideUnknown]],
    ["_fillPercentage", 100, [0]],
    ["_waypointBehaviour", "SAFE", [""]],
    ["_waypointSpeed", "NORMAL", [""]],
    ["_turnAround", false, [true]]
];

if (_spawnPosition isEqualTo []) exitWith {};
if (_destinationPosition isEqualTo []) exitWith {};
if (_vehicleClasses isEqualTo []) exitWith {};

private _vehicleClass = selectRandom _vehicleClasses;
private _vehicle = createVehicle [_vehicleClass, ASLToAGL _spawnPosition, [], 0, "NONE"];
if (isNull _vehicle) exitWith {};

_vehicle setDir ((_spawnPosition getDir _destinationPosition));

createVehicleCrew _vehicle;
private _crewGroup = createGroup [_side, true];
if (isNull _crewGroup || isNull(effectiveCommander _vehicle)) exitWith {
    if !(isNull _crewGroup) then { deleteGroup _crewGroup; };
    deleteVehicle _vehicle;
};

(crew _vehicle) joinSilent _crewGroup;
if ((units _crewGroup) isEqualTo []) exitWith {
    deleteGroup _crewGroup;
    deleteVehicle _vehicle;
};

private _cargoSeats = (_vehicle emptyPositions "cargo") max 0;
private _passengerCount = floor (_cargoSeats * ((_fillPercentage max 0 min 100) / 100));

if (_unitClasses isNotEqualTo []) then {
    for "_index" from 1 to _passengerCount do {
        private _unit = _crewGroup createUnit [selectRandom _unitClasses, [0, 0, 1000], [], 0, "NONE"];
        _unit assignAsCargo _vehicle;
        _unit moveInCargo _vehicle;
    };
};

[_vehicle, _crewGroup, _destinationPosition, _waypointBehaviour, _waypointSpeed, _turnAround, _spawnPosition] call FUNC(addPatrolWaypoint);
