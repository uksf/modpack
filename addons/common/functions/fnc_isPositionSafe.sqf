#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Checks if position is safe (positionASL)

    Parameters:
        0: Position <ARRAY>
        1: Search radius, minimum distance from objects or object used to calculate search radius <NUMBER, OBJECT>

    Return value:
        Boolean
*/
params [["_position", [], [[]]], ["_check", 5, [0, objNull]]];

// convert to position3D for surface and bounding box checks
if (count _position isEqualTo 2) then {
    _position =+ _position;
    _position pushBack 0;
};

private _bbCheck = objNull;

if (_check isEqualType objNull) then {
    _bbCheck = _check;
    private _bb = boundingBoxReal _check;
    private _maxWidth = abs ((_bb select 1 select 0) - (_bb select 0 select 0));
    private _maxLength = abs ((_bb select 1 select 1) - (_bb select 0 select 1));

    // get radius from object bounding box
    _check = (_maxWidth max _maxLength) * 2;
};

// cap radius at 50m
_check = _check min 50;

// check water, water accepts -1, 0 or 2
if ((_position isFlatEmpty [-1, -1, -1, 1, 2]) isEqualTo []) exitWith {false};

// in order for an object to be detected by nearObjects and nearestTerrainObjects, the object's pivot (not bounding box) must be in search radius

// get near entities and filter ignored objects and game logics
private _objs = _position nearObjects ["All", _check];
_objs = _objs select {
    !(_x isKindOf "Logic") &&
    {([[QGVAR(scope_), typeOf _x] joinString "", {GVAR(configVehicles) >> typeOf _x >> "scope"}] call FUNC(readCacheValues)) > 1}
};

// get terrain objects, 2d search radius
_objs append (nearestTerrainObjects [_position, [], _check, false, true]);

// filter out thin objects that should not realistically harm position safety, not ideal
_objs = _objs select {
    (abs (((boundingBoxReal _x) select 1 select 2) - ((boundingBoxReal _x) select 0 select 2))) >= 1.5
};

// check if under surface
private _z = lineIntersectsSurfaces [AGLToASL _position, (AGLToASL _position) vectorAdd [0, 0, 50], objNull, objNull, false, 1, "GEOM", "NONE"] isEqualTo [];

if (isNull _bbCheck) exitWith {_z && {_objs isEqualTo []}};

// check bounding box intersections if object provided
_z && {_objs findIf {[[_bbCheck, _position], _x] call FUNC(inBoundingBox)} < 0}
