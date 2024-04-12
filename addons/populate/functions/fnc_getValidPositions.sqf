#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets any valid building positions AND AI Building Positions in the area

    Parameters:
        0: _module <OBJECT>

    Return value:
        Nothing
*/
params ["_module"];

if !(isServer) exitWith {};

// get the area
private _areaParams = _module getVariable ["objectarea", []];
private _area = [getPos _module] + _areaParams;
if (_area isEqualTo []) exitWith {};

_area params ["", "_a", "_b"];

// get which dimension is largest to use as radius
private _radius = [_b, _a] select (_a > _b);

TRACE_4("",_area,_a,_b,_radius);

// get all buildings in radius then in area
private _allBuildingsInRadius = nearestTerrainObjects [_module, ["BUILDING", "HOUSE"], _radius, false, true];
TRACE_1("",_allBuildingsInRadius);

private _allBuildingsInArea = _allBuildingsInRadius inAreaArray _area;

// // get all ai buildings in radius then in area
// private _allAiBuildingPositionsInRadius = GVAR(aiBuildingPositions) select {_x distance2D _module <= _radius};
// private _aiBuildingPositions = _allAiBuildingPositionsInRadius inAreaArray _area;

// // get the building positions for the buildings
// private _buildingPositions = [];
// {
//     private _building = _x;
//     private _buildingPositionsArray = _building buildingPos -1;
//     {
//         private _buildingPosition = _x;
//         _buildingPositions pushBack _buildingPosition;
//     } forEach _buildingPositionsArray;
// } forEach _allBuildingsInArea;

// // append building positions and ai building positions
// private _spawnPositions = _buildingPositions + _aiBuildingPositions;

// // call out to select position function
// [_spawnPositions, _module] call FUNC(selectSpawnPosition);

