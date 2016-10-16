/*
	Author:
		Tim Beswick

	Description:
		Stop ATC Radar

	Parameter(s):
		0: Object <OBJECT>
		1: Unit <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_object", "_unit"];

_object setVariable [QGVAR(radarOn), false, true]; 
_unit setVariable [QGVAR(isOperator), false, true]