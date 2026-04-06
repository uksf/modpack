#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an intercept trigger zone.
        Stores zone area data for player aircraft proximity checks.
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
private _maxConcurrentIntercepts = _logic getVariable [QGVAR(maxConcurrentIntercepts), 2];

private _area = [_position, _sizeA, _sizeB, _angle, _isRectangle];

GVAR(interceptZones) pushBack [_area, _maxConcurrentIntercepts];

TRACE_1("Registered intercept zone at %1",_position);
