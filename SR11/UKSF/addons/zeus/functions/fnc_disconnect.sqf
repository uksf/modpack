/*
	Author:
		Tim Beswick

	Description:
		Handles zeus disconnect

	Parameter(s):
		0: ID <SCALAR>
		1: UID <STRING>
		2: Name <STRING>
		3: JIP <BOOLEAN>
		4: Owner <STRING>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_id", "_uid", "_name", "_jip", "_owner"];

INFO_1("%1 disconnected", _name);

if(_name == GETMVAR(GVAR(curatorName),"")) exitWith {
	SETMVAR(GVAR(curatorName), "");
	INFO("Curator name reset");
};