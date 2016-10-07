/*
	Author:
		Tim Beswick

	Description:
		Hanldes zeus login on server

	Parameter(s):
		0: Player <OBJECT>
		0: Is admin <BOOLEAN>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_unit", "_isAdmin", "_name", "_curatorName"];

_name = name _unit;
_curatorName = GETMVAR(GVAR(curatorName),"");

INFO_2("Login attempt by: %1. Current zeus: %2", _name, _curatorName);

//Logging in
if((_curatorName == "") || _isAdmin) exitWith {
	SETMVAR(GVAR(curatorName),_name);
	unassignCurator GVAR(curatorObject);
	_unit assignCurator GVAR(curatorObject);
	ctrlSetText [1020, format ["%1", _name]];
	INFO_1("%1 logged in", _name);
};

//Logging out
if(_curatorName == _name) exitWith {
	SETMVAR(GVAR(curatorName),"");
	unassignCurator GVAR(curatorObject);
	ctrlSetText [1020, format ["%1", ""]];
	INFO_1("%1 logged out", _name);
};