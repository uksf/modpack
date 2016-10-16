/*
	Author:
		Tim Beswick

	Description:
		Conceal land rover net.

	Parameter(s):
		0: Rover <OBJECT>
		1: Unit <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_rover", "_unit"];

success = {
	params ["_args"];
	_args params ["_rover", "_unit"];
	_net = _rover getVariable [QGVAR(netObj), objNull];
	if(_net != objNull) then {
		deleteVehicle _net;
		_rover setVariable [QGVAR(netObj), objNull, true];
		_rover setVariable [QGVAR(deployed), false, true];
	};
	[_unit, "", 2] call ace_common_fnc_doAnimation;
};

fail = {
	params ["_args"];
	_args params ["_rover", "_unit"];
	hint "Could not conceal net";
	[_unit, "", 2] call ace_common_fnc_doAnimation;
};

[_unit, "Acts_carFixingWheel", 1] call ace_common_fnc_doAnimation;
[15, [_rover, _unit], {call success}, {call fail}, "Concealing Net"] call ace_common_fnc_progressBar;
