#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Handles updating of sector markers
        called after a capture

    Parameters:
        0: The module logic <OBJECT>
        1: current owner of the sector <NUMBER>

    Return value:
        Nothing
*/
#define OPFOR_COLOUR "ColorEAST"
#define BLUFOR_COLOUR "ColorWEST"
#define NONE_COLOUR "ColorGrey"

params ["_logic", "_newOwner"];

if !(isServer) exitWith {};

private _name = _logic getVariable [QGVAR(displayName), ""];
private _markers = _logic getVariable [QGVAR(sectorMarkers), []];
private _nameMarker = _markers#1;
_nameMarker setMarkerText _name;

private _markerColour = switch (_newOwner) do {
    case 0: { OPFOR_COLOUR };
    case 1: { BLUFOR_COLOUR };
    default { NONE_COLOUR };
};

{
    _x setMarkerColor _markerColour;
} forEach _markers;



