/*
	Author:
		Tim Beswick

	Description:
		Attempts zeus login

	Parameter(s):
		None

	Return Value:
		None
*/
#include "script_component.hpp"

_admin = if (serverCommandAvailable "#logout" || isServer) then {
	true
} else {
	false
};

INFO_1("Logging in, admin: %1", _admin);

[player, _admin] remoteExecCall [QFUNC(serverLogin), 2, false];

if(dialog) exitWith {
	closeDialog 0;
};