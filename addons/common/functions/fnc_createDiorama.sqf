#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a diorama of objects relative to a given centre.
        The diorama will be centred relative to the given diorama centre. The relative vertical position will also be relative to this centre.
        Handles locality weirdness with scaling, and JIP.

        To avoid unexpected results, run this at postInit.

        Created diorama objects are returned for handling in case of error.

        WARNING: Large numbers of objects may cause crashes

    Parameters:
        0: Origin Centre <POSITION ASL/OBJECT>
        1: Diorama Centre <POSITION ASL/OBJECT>
        2: Scan Radius <SCALAR>
        3: Scale <SCALAR>

    Return value:
        Array of diorama objects <ARRAY>
*/
params ["_originCentre", "_dioramaCentre", "_scanRadius", "_scale"];

if (isServer || !hasInterface) exitWith {};

private _allObjects = nearestTerrainObjects [getPos _originCentre, [], _scanRadius, false];

private _visibleObjects = _allObjects select {!(isObjectHidden _x)};

{
    private _pos = _dioramaCentre getPos [(_originCentre distance _x) * _scale, _originCentre getDir _x];
    private _heightDiff = ((getPosWorld _x) vectorDiff (getPosASL _x))#2;
    private _scaledHeightDiff = _heightDiff * _scale;
    _pos set [2, _scaledHeightDiff];

    private _object = createSimpleObject [(getModelInfo _x)#1, ATLToASL _pos, true];
    _object setDir (getDir _x);
    _object setObjectScale _scale;

    createdObjects pushBack _object;
} forEach _visibleObjects;
