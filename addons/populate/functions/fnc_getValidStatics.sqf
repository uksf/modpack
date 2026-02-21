#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets any valid static guns in the area

    Parameters:
        0: _module <OBJECT>

    Return value:
       _statics
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

// get all statics in the area
private _statics = [];
private _staticsInArea = (_module nearEntities  [["StaticWeapon"], _radius]) select {_x inArea _area && (_x emptyPositions "" > 0)};
{
    _statics pushBack _x;
} forEach _staticsInArea;

_statics
