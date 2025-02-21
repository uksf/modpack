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

params ["_logic", "_sizeXandY", "_currentOwner", "_name"];

if !(isServer) exitWith {};

private _markerColour = switch (_currentOwner) do {
    case 0: { OPFOR_COLOUR };
    case 1: { BLUFOR_COLOUR };
    default { NONE_COLOUR };
};

// Area Marker
private _markerName = format ["mkrSector_%1", random 1000];
private _sectorMarker = createMarker [_markerName, _logic];
_sectorMarker setMarkerShapeLocal "ELLIPSE";
_sectorMarker setMarkerColorLocal _markerColour;
_sectorMarker setMarkerSizeLocal _sizeXandY;
_sectorMarker setMarkerAlphaLocal 0.5;
_sectorMarker setMarkerBrush "DiagGrid";

// Label marker
private _markerName = format ["mkrSectorName_%1", random 1000];
private _sectorNameMarker = createMarker [_markerName, _logic];
_sectorNameMarker setMarkerShapeLocal "ICON";
_sectorNameMarker setMarkerColorLocal _markerColour;
_sectorNameMarker setMarkerTextLocal _name;
_sectorNameMarker setMarkerType "mil_triangle";

_logic setVariable [QGVAR(sectorMarkers), [_sectorMarker, _sectorNameMarker], true];
