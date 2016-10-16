/*
	Author:
		Tim Beswick

	Description:
		Initialises ATC objects/buildings

	Parameter(s):
		0: Object <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_object"];

if(isServer) then {
	if(_object isKindOf "UKSF_ATC_Core") then {
		_ATC = createVehicle ["UKSF_ATC_CoreCore", [0,0,0], [], 0, "CAN_COLLIDE"];
		_ATC setPos (_object modelToWorld [0,0,0.5]);
		_ATC setVariable [QVAR(radarOn), false, true];
	};
};