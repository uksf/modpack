#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates safehouse from prefab

    Parameters:
        0: Location logic <OBJECT>
        1: Prefab data <ARRAY>

    Return value:
        Nothing
*/
params ["_logic", "_prefab"];
_prefab params ["_centre", "_area", "_anchorObjectData", "_objectData"];
_area params ["_a", "_b", "_angle", "_isRectangle", "_c"];

if !(isServer) exitWith {};

private _locationCentre = getPos _logic;
_locationCentre set [2, _centre#2];
_logic setPos _locationCentre;

// Find terrain objects and delete
// Try find a terrain object that matches an anchor object and use that as object data offset centre

private _radius = ((_a ^ 2) + (_b ^ 2)) ^ 0.5;
private _terrainObjects = nearestTerrainObjects [_locationCentre, [], _radius, true];
_terrainObjects = _terrainObjects inAreaArray [_locationCentre, _a, _b, _angle, _isRectangle, _c];
{deleteVehicle _x} forEach _terrainObjects;

private _anchorObject = [_logic, _anchorObjectData] call FUNC(createSafehouseObject);

private _objects = [];
{
    private _object = [_anchorObject, _x] call FUNC(createSafehouseObject);
    _objects pushBack _object;
} forEach _objectData;

_anchorObject setVariable [QEGVAR(cleanup,excluded), true, true];
_anchorObject setVariable [QGVAR(safehouseLocation), _logic];
_anchorObject setVariable [QGVAR(safehouseObjects), _objects];

_anchorObject addMPEventHandler ["MPKilled", {
    params ["_anchorObject", "_killer", "_instigator"];

    if (side _killer != west && side _instigator != west) exitWith {};
    TRACE_1("Safehouse anchor destroyed",_anchorObject);

    [_anchorObject] call FUNC(destroySafehouse);
}];

// TODO:
// Mark all objects as persistent
// Mark all objects as belonging to a safehouse (use PID of anchor object)
// Add safehouse id to persistence
// Killed EH on anchor object, when destroyed:
    // Delete all safehouse objects
    // Remove id from persistence
    // Add id to destroyed persistence
    // Create destruction object (destroyed anchor) and mark as persistent and exclude from cleanup
