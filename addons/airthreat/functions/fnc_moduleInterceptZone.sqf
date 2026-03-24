#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an intercept trigger zone.
        Creates an invisible marker for area checking and stores zone data.
        When player aircraft fly within this zone, interceptors may scramble.
        Server only.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_airthreat_fnc_moduleInterceptZone
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if !(isServer) exitWith {};

private _position = getPosASL _logic;
private _area = _logic getVariable ["objectarea", [10000, 10000, 0, true]];
_area params ["_sizeA", "_sizeB", "_angle", "_isRectangle"];
private _maxConcurrentIntercepts = parseNumber (_logic getVariable [QGVAR(maxConcurrentIntercepts), "2"]);

private _marker = createMarkerLocal [format [QGVAR(intercept_%1_%2), _position select 0, _position select 1], _position];
_marker setMarkerShapeLocal (["ELLIPSE", "RECTANGLE"] select _isRectangle);
_marker setMarkerSizeLocal [_sizeA, _sizeB];
_marker setMarkerDirLocal _angle;
_marker setMarkerAlphaLocal 0;

GVAR(interceptZones) pushBack [_marker, _maxConcurrentIntercepts, 0];

INFO_1("Registered intercept zone at %1",_position);
