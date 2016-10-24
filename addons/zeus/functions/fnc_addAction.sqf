/*
	Author:
		Tim Beswick

	Description:
		Init EH for player

	Parameter(s):
		None

	Return Value:
		None
*/
#include "script_component.hpp"

if (local player && !(player getVariable [QGVAR(actionsAdded), false])) then {
	_action = [QGVAR(zeusMainAction), QUOTE(Zeus), ZEUS_ICON, {}, {true}, {call FUNC(getChildren)}] call ace_interact_menu_fnc_createAction;
	_path = [player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
	player setVariable [QGVAR(actionsAdded), true, true];
};