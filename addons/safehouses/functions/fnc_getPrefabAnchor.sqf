#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get prefab anchor from array of objects

    Parameters:
        0: Objects <ARRAY>
        1: Module logic <OBJECT>
        2: Area <ARRAY>

    Return value:
        Objects and anchor <ARRAY>
        [Anchor object, Objects in area]
*/
params ["_objects", "_logic", "_area"];
_area params ["_a", "_b", "_angle", "_isRectangle", "_c"];

if !(isServer) exitWith {};

private _objectsInArea = _objects inAreaArray [getPos _logic, _a, _b, _angle, _isRectangle, _c];
private _houseObjects = _objectsInArea select {_x isKindOf "House"}; // TODO: May need to whitelist more object base classes here
private _sizeOrderedObjects = [_objectsInArea, _houseObjects] select (_houseObjects isNotEqualTo []);

if (_sizeOrderedObjects isEqualTo []) exitWith {
    [objNull, []]
};

_sizeOrderedObjects = _sizeOrderedObjects apply {
    private _boundingBox = boundingBox _x;
    private _volume = ((_boundingBox#1#0) - (_boundingBox#0#0)) * ((_boundingBox#1#1) - (_boundingBox#0#1)) * ((_boundingBox#1#2) - (_boundingBox#0#2));

    [_volume, 999 - (_x distance _logic), _x]
};
_sizeOrderedObjects sort false;

private _anchorObject = _sizeOrderedObjects#0#2;
_objectsInArea deleteAt (_objectsInArea find _anchorObject);

[_anchorObject, _objectsInArea]
