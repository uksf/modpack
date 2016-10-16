/*
	Author:
		Tim Beswick

	Description:
		Get name for action

	Parameter(s):
		0: Curator index <SCALAR>

	Return Value:
		Name <STRING>
*/
#include "script_component.hpp"

params ["_index", ["_name", ""]];

_names = missionNamespace getVariable [QGVAR(curatorNames), ["","","","",""]];
_curatorName = (_names select _index);

if (_curatorName == (name player)) then {
	_name = format ["Zeus %1: Logout", _index + 1];
} else {
	if (_curatorName == "") then {
		_name = format ["Zeus %1: Login", _index + 1];
	} else {
		if (IS_ADMIN || isServer) then {
			_name = format ["Zeus %1: Kick %2", _index + 1, _curatorName];
		} else {
			_name = format ["Zeus %1: %2 Logged In", _index + 1, _curatorName];
		};
	};
};

_name