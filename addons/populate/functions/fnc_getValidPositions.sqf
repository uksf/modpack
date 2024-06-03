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

private _statics = [];

// get the area
private _areaParams = _module getVariable ["objectarea", []];
private _area = [getPos _module] + _areaParams;
if (_area isEqualTo []) exitWith {};

_area params ["", "_a", "_b"];

// get which dimension is largest to use as radius
private _radius = [_b, _a] select (_a > _b);

// get all buildings in radius then in area
private _allBuildingsInRadius = nearestTerrainObjects [_module, ["BUILDING", "HOUSE", "BUNKER"], _radius, false, true];
private _allBuildingsInArea = _allBuildingsInRadius select {_x inArea _area};

// get the building positions for the buildings
private _buildingPositions = [];
{
    private _building = _x;
    private _buildingPositionsArray = _building buildingPos -1;
    {
        private _buildingPosition = _x;
        _buildingPositions pushBack _buildingPosition;
    } forEach _buildingPositionsArray;
} forEach _allBuildingsInArea;

// get all ai buildings in the area
private _aiBuildingPositions = [];
private _aiBuildingPositionsInArea = (_module nearObjects ["CBA_BuildingPos", _radius]) select {_x inArea _area};
{
    // _aiBuildingPositions pushBack [getPos _x, getDir _x];
    _aiBuildingPositions pushBack _x;
} forEach _aiBuildingPositionsInArea;

// get statics in the area
private _occupyStatics = _module getVariable [QGVAR(occupyStaticGunsBool), false];
if (_occupyStatics) then {
    _statics = [_module] call FUNC(getValidStatics);
};

// append building positions and ai building positions
private _spawnPositions = _buildingPositions + _aiBuildingPositions;

// call out to select position function
[_spawnPositions, _statics, _module] call FUNC(selectSpawnPosition);

