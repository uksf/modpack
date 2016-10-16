/*
	Author:
		Tim Beswick

	Description:
		Stop dead units talking to their squad

	Parameter(s):
		0: Unit <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_unit"];

_unit setVariable ["BIS_noCoreConversations", true];
