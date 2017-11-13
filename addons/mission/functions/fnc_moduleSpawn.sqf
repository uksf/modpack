/*
    Author:
        Tim Beswick
        
    Description:
        Executes init patrol for spawn module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

(_this select 1) params ["_logic"];

if (!(local _logic)) exitWith {};

private _position = position _logic;
private _marker = createMarkerLocal [format ["spawn_%1_%2_%3", _position select 0, _position select 1, random 100], _position];
private _area = _logic getVariable ["objectarea", []];
_area params ["_a", "_b", "_angle", "_isRectangle"];
_marker setMarkerAlphaLocal 0;
_marker setMarkerShapeLocal (["RECTANGLE", "ELLIPSE"] select _isRectangle);
_marker setMarkerSizeLocal [_a, _b];
_marker setMarkerDirLocal (direction _logic);

[QGVAR(initPatrol), [_marker, parseNumber (_logic getVariable [QGVAR(maxGroups), 4]), parseNumber (_logic getVariable [QGVAR(groupPool), 8]), _logic getVariable [QGVAR(faction), "OPF_F"]]] call CBA_fnc_serverEvent;

