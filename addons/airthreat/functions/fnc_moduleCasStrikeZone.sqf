#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a CAS/strike trigger zone.
        Creates an invisible marker for area checking and stores zone data.
        When players enter this zone, CAS or strike missions may spawn.
        Server only.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_airthreat_fnc_moduleCasStrikeZone
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if !(isServer) exitWith {};

private _position = getPosASL _logic;
private _area = _logic getVariable ["objectarea", [500, 500, 0, false]];
_area params ["_sizeA", "_sizeB", "_angle", "_isRectangle"];
private _casProbability = parseNumber (_logic getVariable [QGVAR(casProbability), "50"]);

private _marker = createMarkerLocal [format [QGVAR(casStrike_%1_%2), _position select 0, _position select 1], _position];
_marker setMarkerShapeLocal (["ELLIPSE", "RECTANGLE"] select _isRectangle);
_marker setMarkerSizeLocal [_sizeA, _sizeB];
_marker setMarkerDirLocal _angle;
_marker setMarkerAlphaLocal 0;

GVAR(casStrikeZones) pushBack [_marker, _casProbability, time];

INFO_1("Registered CAS/strike zone at %1",_position);
