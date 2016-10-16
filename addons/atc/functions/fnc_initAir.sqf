/*
	Author:
		Tim Beswick

	Description:
		Initialises air vehicles for ATC

	Parameter(s):
		0: Object <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_object"];

if ((isServer && !hasInterface) || !isMultiplayer) then {
	_targets = missionNamespace getVariable [QGVAR(airTargets), []];
	_targets pushBack _object;
	missionNamespace setVariable [QGVAR(airTargets), _targets, true];
};