#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an exclusion zone where players will not be targeted
        by air threat missions. Stores zone area data for target filtering.
        Server only.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_airthreat_fnc_moduleExclusionZone
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if !(isServer) exitWith {};

private _position = getPosASL _logic;
private _area = _logic getVariable ["objectarea", [500, 500, 0, false]];
_area params ["_sizeA", "_sizeB", "_angle", "_isRectangle"];

GVAR(exclusionZones) pushBack [_position, _sizeA, _sizeB, _angle, _isRectangle];

TRACE_1("Registered exclusion zone at %1",_position);
