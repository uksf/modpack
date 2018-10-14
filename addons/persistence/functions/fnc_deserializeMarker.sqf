/*
    Author:
        Tim Beswick

    Description:
        Deerializes a marker

    Parameter(s):
        0: Serialized marker <ARRAY>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_serializedMarker"];
_serializedMarker params ["", "_pos", "_shape", "_type", "_brush", "_size", "_colour", "_alpha", "_dir", "_text"];

private _marker = createMarker [format ["_USER_DEFINED #0/%1/1", EGVAR(common,markerID)], _pos];
_marker setMarkerShape _shape;
_marker setMarkerType _type;
_marker setMarkerBrush _brush;
_marker setMarkerSize _size;
_marker setMarkerColor _colour;
_marker setMarkerAlpha _alpha;
_marker setMarkerDir _dir;
_marker setMarkerText _text;

EGVAR(common,markerID) = EGVAR(common,markerID) + 1;
