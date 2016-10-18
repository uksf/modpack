/*
	Author:
		Tim Beswick

	Description:
		Run statement for action

	Parameter(s):
		0: Curator index <SCALAR>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_index", ["_statement", {}]];

_names = missionNamespace getVariable [QGVAR(curatorNames), ["","","","",""]];
_curatorName = (_names select _index);

if (_curatorName == (name player)) then {
	//Logout
	_statement = {
		[[_this select 2], {
			_names = missionNamespace getVariable [QGVAR(curatorNames), ["","","","",""]];
			_names set [(_this select 0), ""];
			missionNamespace setVariable [QGVAR(curatorNames), _names, true];
			unassignCurator (GVAR(curatorObjects) select (_this select 0));

			[[(_this select 0)], {
				if (IS_ADMIN || (isServer && hasInterface)) then {
					hint format ["Zeus %1 logged out", (_this select 0) + 1];
				};
			}] remoteExecCall ["bis_fnc_call", 0, false];
		}] remoteExecCall ["bis_fnc_call", 2, false];

		hint format ["Logged out of Zeus %1", (_this select 2) + 1];
	};
} else {
	if (_curatorName == "") then {
		if (!((name player) in _names)) then {
			//Login
			_statement = {
				[[_this select 2, player], {
					_names = missionNamespace getVariable [QGVAR(curatorNames), ["","","","",""]];
					_names set [(_this select 0), name (_this select 1)];
					missionNamespace setVariable [QGVAR(curatorNames), _names, true];
					(_this select 1) assignCurator (GVAR(curatorObjects) select (_this select 0));

					[[(_this select 0), (_this select 1)], {
						if (IS_ADMIN || (isServer && hasInterface)) then {
							hint format ["%1 logged into Zeus %2", name (_this select 1), (_this select 0) + 1];
						};
					}] remoteExecCall ["bis_fnc_call", 0, false];
				}] remoteExecCall ["bis_fnc_call", 2, false];

				hint format ["Logged into Zeus %1", (_this select 2) + 1];
			};
		};
	} else {
		if (IS_ADMIN || isServer) then {
			//Kick
			_statement = {
				[[_this select 2], {
					_names = missionNamespace getVariable [QGVAR(curatorNames), ["","","","",""]];
					_names set [(_this select 0), ""];
					missionNamespace setVariable [QGVAR(curatorNames), _names, true];
					unassignCurator (GVAR(curatorObjects) select (_this select 0));

					[[(_this select 0)], {
						if (IS_ADMIN || (isServer && hasInterface)) then {
							hint format ["Zeus %1 kicked", (_this select 0) + 1];
						};
					}] remoteExecCall ["bis_fnc_call", 0, false];
				}] remoteExecCall ["bis_fnc_call", 2, false];
			};
		};
	};
};

_statement