#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Emits an array of polylines as that many user-defined map markers.
        One markerID per piece; 4-arg createMarker provides explicit channel
        and creator; _USER_DEFINED prefix makes pieces user-deletable.

    Parameter(s):
        0: Polylines, each a flat [x0, y0, x1, y1, ...] array <ARRAY>

    Return Value:
        Array of created marker names <ARRAY>

    Example:
        [_polylines] call uksf_maptools_fnc_emitShape
*/
params [["_polylines", [], [[]]]];

private _channelID = currentChannel;
if (_channelID < 0) then { _channelID = 1 };
private _ownerID = getPlayerID ACE_player;

private _colour = missionNamespace getVariable ["ace_markers_currentMarkerColorConfigName", "ColorBlack"];
if (_colour isEqualTo "") then { _colour = "ColorBlack" };

private _created = [];
{
    private _markerID = GVAR(markerID);
    GVAR(markerID) = _markerID + 1;
    private _name = format ["_USER_DEFINED #%1/%2/%3", _ownerID, _markerID, _channelID];
    createMarkerLocal [_name, _x select [0, 2], _channelID, ACE_player];
    _name setMarkerShapeLocal "POLYLINE";
    _name setMarkerColorLocal _colour;
    _name setMarkerPolyline _x;
    _created pushBack _name;
} forEach _polylines;

GVAR(playerShapes) append _created;

_created
