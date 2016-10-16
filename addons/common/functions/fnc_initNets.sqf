/*
	Author:
		Tim Beswick

	Description:
		Initialises camo net functionality

	Parameter(s):
		0: Rover <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

if(isMultiplayer && (!isServer || !isDedicated)) exitWith {};

params ["_rover"];

if(isNil {_rover getVariable QGVAR(deployed)}) then {
	_rover setVariable [QGVAR(deployed), false, true];
};

if(isNil {_rover getVariable QGVAR(netObj)}) then {
	_rover setVariable [QGVAR(netObj), objNull, true];
};
