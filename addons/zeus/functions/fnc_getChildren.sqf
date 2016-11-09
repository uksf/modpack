/*
	Author:
		Tim Beswick

	Description:
		Zeus action children

	Parameter(s):
		None

	Return Value:
		Array of actions <ARRAY>
*/
#include "script_component.hpp"

_actions = [];

_action = [QGVAR(zeusAction_1), [0] call FUNC(getName), ZEUS_ICON, [0] call FUNC(actionStatement), {true}, {}, 0] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(zeusAction_2), [1] call FUNC(getName), ZEUS_ICON, [1] call FUNC(actionStatement), {true}, {}, 1] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(zeusAction_3), [2] call FUNC(getName), ZEUS_ICON, [2] call FUNC(actionStatement), {true}, {}, 2] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(zeusAction_4), [3] call FUNC(getName), ZEUS_ICON, [3] call FUNC(actionStatement), {true}, {}, 3] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(zeusAction_5), [4] call FUNC(getName), ZEUS_ICON, [4] call FUNC(actionStatement), {true}, {}, 4] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(zeusAction_kickall), QUOTE(Kick All), ZEUS_ICON, {	
	[{
		{unassignCurator _x} forEach GVAR(curatorObjects);
		missionNamespace setVariable [QGVAR(curatorNames), ["","","","",""], true];
	}] remoteExecCall ["bis_fnc_call", 2, false];
	hint "All Zeuses kicked";
}, {IS_ADMIN || isServer}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_actions