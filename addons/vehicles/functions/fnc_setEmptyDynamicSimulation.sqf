#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Server only. Puts an alive, empty, simulated land vehicle under dynamic simulation, so the engine
        stops simulating it while no player is near. Takes a crewed vehicle out of dynamic simulation, because
        a crewed vehicle under dynamic simulation stays asleep and its AI crew cannot move it.
        Does nothing when the empty vehicle dynamic simulation setting is off.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None

    Example:
        [vehicle player] call uksf_vehicles_fnc_setEmptyDynamicSimulation
*/
params [["_vehicle", objNull, [objNull]]];

if (!isServer || {!GVAR(emptyDynamicSimulation)} || {isNull _vehicle} || {!(_vehicle isKindOf "LandVehicle")}) exitWith {};

private _crewed = (crew _vehicle) findIf {alive _x} != -1;
private _shouldSleep = alive _vehicle && {!_crewed} && {simulationEnabled _vehicle || {dynamicSimulationEnabled _vehicle}};

if (_shouldSleep isNotEqualTo (dynamicSimulationEnabled _vehicle)) then {
    _vehicle enableDynamicSimulation _shouldSleep;
};
