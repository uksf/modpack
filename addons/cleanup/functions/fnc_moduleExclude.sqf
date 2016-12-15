/*
	Author:
		Tim Beswick

	Description:
		Sets unit to exclude from cleanup

	Parameter(s):
		0: The module logic <OBJECT>
		1: Synchronized units <ARRAY>
		2: Activated <BOOL>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_logic", "_units", "_activated"];
private ["_mouseOver", "_unit", "_excluded"];

if !(_activated && local _logic) exitWith {};

_mouseOver = GETMVAR(bis_fnc_curatorObjectPlaced_mouseOver,[""]);

if ((_mouseOver select 0) != "OBJECT") then {
	[QUOTE(Place on a unit or vehicle)] call ace_common_fnc_displayTextStructured;
} else {
	_unit = _mouseOver select 1;
	_excluded = _unit getVariable [QGVAR(excluded), false];
	if (!_excluded) then {
		_unit setVariable [QGVAR(excluded), true, true];
	};
};

deleteVehicle _logic;
