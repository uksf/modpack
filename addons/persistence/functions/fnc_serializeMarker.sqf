/*
    Author:
        Tim Beswick

    Description:
        Serializes a marker

    Parameter(s):
        0: Marker <STRING>

    Return Value:
        Array of marker information
*/
#include "script_component.hpp"

params ["_marker"];

private _serializedMarker = [];
if ((_marker find "respawn") == -1) then {
    private _split = _marker splitString "/";
    if (count _split > 1 && {_split#2 == "1"}) then {
        private _pos = markerPos _marker;
        private _shape = markerShape _marker;
        if (_shape != "POLYLINE") then {
            private _type = markerType _marker;
            private _brush = markerBrush _marker;
            private _size = markerSize _marker;
            private _colour = markerColor _marker;
            private _alpha = markerAlpha _marker;
            private _dir = markerDir _marker;
            private _text = markerText _marker;
            _serializedMarker = [_marker, _pos, _shape, _type, _brush, _size, _colour, _alpha, _dir, _text];
        };
    };
};

_serializedMarker
