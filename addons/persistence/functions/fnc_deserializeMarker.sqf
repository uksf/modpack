#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deserializes a marker

    Parameter(s):
        0: Serialized marker <ARRAY>

    Return Value:
        Marker
*/
params ["_serializedMarker"];
_serializedMarker params ["", "_pos", "_shape"];

private _marker = createMarker [format ["_USER_DEFINED #0/%1/1", EGVAR(common,markerID)], _pos];
_marker setMarkerShape _shape;

if (_shape == "POLYLINE") then {
    _serializedMarker params ["", "", "", "_colour", "_alpha", "_polyline"];
    _marker setMarkerColor _colour;
    _marker setMarkerAlpha _alpha;
    _marker setMarkerPolyline _polyline;
} else {
    _serializedMarker params ["", "", "", "_type", "_brush", "_size", "_colour", "_alpha", "_dir", "_text"];
    _marker setMarkerType _type;
    _marker setMarkerBrush _brush;
    _marker setMarkerSize _size;
    _marker setMarkerColor _colour;
    _marker setMarkerAlpha _alpha;
    _marker setMarkerDir _dir;
    _marker setMarkerText _text;
};

EGVAR(common,markerID) = EGVAR(common,markerID) + 1;

_marker
