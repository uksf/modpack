#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Handles sector markers
        Creates them initially if the condition is true
        Sets the marker name onto the sector module so it can be manipulated

    Parameters:
        0: The module logic <OBJECT>
        1: the size of the marker <NUMBER>

    Return value:
        Nothing
*/
#define OPFOR_COLOUR "ColorEAST"
#define BLUFOR_COLOUR "ColorWEST"
#define NONE_COLOUR "ColorGrey"

params ["_logic", "_side"];

if !(isServer) exitWith {};

if (_logic getVariable [QGVAR(sectorContested), false]) exitWith {};

private _markerColour = switch (_side) do {
    case 0: { OPFOR_COLOUR };
    case 1: { BLUFOR_COLOUR };
    default { NONE_COLOUR };
};

private _markers = _logic getVariable [QGVAR(sectorMarkers), []];
private _areaMarker = _markers#0;
private _nameMarker = _markers#1;
private _markerName = markerText _nameMarker;

_nameMarker setMarkerTextLocal _markerName+" [Contested!]";
_nameMarker setMarkerColor _markerColour;

_logic setVariable [QGVAR(sectorContested), true, true];
