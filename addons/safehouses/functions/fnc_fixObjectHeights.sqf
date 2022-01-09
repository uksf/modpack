#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Fixes object heights based on detection of surface intersection

    Parameters:
        0: Object <OBJECT>

    Return value:
        Nothing
*/
#define OFFSET_END [0, 0, -20]
#define OFFSET_ABOVE [0, 0, 0.1]

params ["_object"];

if !(isServer) exitWith {};

private _objectPosition = getPosASL _object;
private _virtualPosition = +_objectPosition;
private _intersectionPosition = [];
private _difference = 0;
while {_difference == 0} do {
    private _intersectionsBelow = lineIntersectsSurfaces [_virtualPosition, _virtualPosition vectorAdd OFFSET_END, _object, objNull, true, 1];

    if (_intersectionsBelow isEqualTo []) exitWith {
        DEBUG_1("No intersection below object. Cannot determine if height needs fixing for %1",typeOf _object);
        break;
    };

    private _intersection = _intersectionsBelow#0;
    _intersectionPosition = [_objectPosition#0, _objectPosition#1, _intersection#0#2];
    _difference = _intersectionPosition distance _objectPosition;

    _virtualPosition = _virtualPosition vectorAdd OFFSET_ABOVE;
};

if (_difference == 0) exitWith {
    WARNING_1("Failed to resolve position for fixing height for %1",typeOf _object);
};

private _correctedPosition = [_objectPosition#0, _objectPosition#1, _objectPosition#2 - _difference];
_object setPosASL _correctedPosition;

DEBUG_5("Obj %1. Pos %2. Intpos %3. Diff %4. Cor %5.",typeOf _object,_objectPosition,_intersectionPosition,_difference,_correctedPosition);
