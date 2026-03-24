#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an airspace patrol zone for CAP missions.
        Stores position and area dimensions for patrol waypoint generation.
        Server only.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_airthreat_fnc_moduleAirspace
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if !(isServer) exitWith {};

private _position = getPosASL _logic;
private _area = _logic getVariable ["objectarea", [2000, 2000, 0, false]];
_area params ["_sizeA", "_sizeB", "_angle", "_isRectangle"];

GVAR(airspaces) pushBack [_position, _sizeA, _sizeB, _angle, _isRectangle];

INFO_1("Registered airspace zone at %1",_position);
