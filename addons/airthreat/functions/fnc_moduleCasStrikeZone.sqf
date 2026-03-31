#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a CAS/strike trigger zone.
        Stores zone area data for player proximity checks.
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
private _casProbability = _logic getVariable [QGVAR(casProbability), 50];

private _area = [_position, _sizeA, _sizeB, _angle, _isRectangle];

GVAR(casStrikeZones) pushBack [_area, _casProbability, time];

INFO_1("Registered CAS/strike zone at %1",_position);
