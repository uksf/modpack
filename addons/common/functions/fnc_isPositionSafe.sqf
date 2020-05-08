#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Checks if position is safe (positionASL)

    Parameters:
        0: Position <ARRAY>
        1: Search radius, minimum distance from objects or object used to calculate search radius <NUMBER, OBJECT>
        2: Object direction to rotate bounding checks by (Optional) <SCALAR>
        3: Objects to check position safety against (Optional) <ARRAY>
        4: Object types to ignore during safety checks (Optional) <ARRAY>

    Return value:
        Boolean
*/
params [["_position", [], [[]]], ["_check", 5, [0, objNull]], ["_objectDirection", -1, [0]], ["_objects", [], [[]]], ["_ignore", SAFE_POSITION_OBJECTS_IGNORE, [[]]]];

TRACE_2("Checking safety of position",_position,_check);

if (count _position isEqualTo 2) then {
    _position =+ _position;
    _position pushBack 0;
};

private _object = objNull;
if (_check isEqualType objNull) then {
    _object = _check;
    private _boundingBox = 2 boundingBoxReal _check;
    private _maxWidth = abs ((_boundingBox#1#0) - (_boundingBox#0#0));
    private _maxLength = abs ((_boundingBox#1#1) - (_boundingBox#0#1));

    _check = (_maxWidth max _maxLength) * 2;
};

_check = _check min 50;
TRACE_3("Checking safety of position",_object,_position,_check);

// check water, water accepts -1, 0 or 2
// if ((_position isFlatEmpty [-1, -1, -1, 1, 2]) isEqualTo []) exitWith {false};

if (_objects isEqualTo []) then {
    _objects = _position nearObjects _check;
};

private _distance = _check * 2;
_objects = _objects select {
    private _checkObject = _x;
    [_ignore, {_checkObject isKindOf _x}] call FUNC(arrayNone) &&
    {(_checkObject distance _position) < _distance} //&&
    // {([[QGVAR(scope_), typeOf _x] joinString "", {GVAR(configVehicles) >> typeOf _x >> "scope"}] call FUNC(readCacheValues)) > 1}
};
TRACE_1("Filtered nearby objects",_objects);

// _objects append (nearestTerrainObjects [_position, [], _check, false, true]);

// filter out thin objects that should not realistically harm position safety, not ideal
// _objects = _objects select {
//     (abs (((0 boundingBoxReal _x)#1#2) - ((0 boundingBoxReal _x)#0#2))) >= 1.5
// };
// TRACE_1("Filtered nearby objects",_objects);

// check if under surface
// private _z = lineIntersectsSurfaces [AGLToASL _position, (AGLToASL _position) vectorAdd [0, 0, 50], objNull, objNull, false, 1, "GEOM", "NONE"] isEqualTo [];

if (isNull _object) exitWith {_objects isEqualTo []};

// check bounding box intersections if object provided
[_objects, {[[_object, _position], _x, _objectDirection] call FUNC(inBoundingBox)}] call FUNC(arrayNone)
