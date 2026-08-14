#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Adds the authorised ACE self-interact and NPC MainActions console entries.
*/
if (!hasInterface) exitWith {};

private _fnc_children = {
    private _actions = [];
    private _toggle = [QGVAR(consoleCardsAction), "Show cards", "", {
        [!GVAR(consoleCardsEnabled)] call FUNC(consoleToggleCards);
    }, {true}, {}, nil, nil, nil, [false, false, false, false, false], {
        params ["", "", "", "_actionData"];
        _actionData set [1, ["Show cards", "Hide cards"] select GVAR(consoleCardsEnabled)];
    }] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_toggle, [], _player];

    private _inspect = [QGVAR(consoleInspectNearest), "Inspect nearest NPC", "", {
        private _npc = call FUNC(consoleNearestNpc);
        if (!isNull _npc) then {[_npc] call FUNC(consoleOpenInspector)};
    }, {!isNull (call FUNC(consoleNearestNpc))}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_inspect, [], _player];
    _actions
};

private _parent = [QGVAR(consoleActions), "NPC", "", {}, {
    (missionNamespace getVariable [QGVAR(talkerNetIds), []]) isNotEqualTo [] && {ADMIN_OR_WHITELISTED}
}, _fnc_children] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _parent, true] call ace_interact_menu_fnc_addActionToClass;

private _inspect = [QGVAR(consoleInspectNpc), "Inspect NPC", "", {[_target] call FUNC(consoleOpenInspector)}, {
    netId _target in (missionNamespace getVariable [QGVAR(registeredNetIds), []]) && {ADMIN_OR_WHITELISTED}
}] call ace_interact_menu_fnc_createAction;
["CAManBase", 0, ["ACE_MainActions"], _inspect, true] call ace_interact_menu_fnc_addActionToClass;

private _mute = [QGVAR(consoleMuteNpc), "Mute NPC", "", {
    ["mute", _target] call FUNC(consoleAction);
}, {
    netId _target in (missionNamespace getVariable [QGVAR(registeredNetIds), []])
    && {_target getVariable [QGVAR(talkable), false]}
    && {ADMIN_OR_WHITELISTED}
}] call ace_interact_menu_fnc_createAction;
["CAManBase", 0, ["ACE_MainActions"], _mute, true] call ace_interact_menu_fnc_addActionToClass;

private _unmute = [QGVAR(consoleUnmuteNpc), "Unmute NPC", "", {
    ["unmute", _target] call FUNC(consoleAction);
}, {
    netId _target in (missionNamespace getVariable [QGVAR(registeredNetIds), []])
    && {!(_target getVariable [QGVAR(talkable), false])}
    && {alive _target}
    && {ADMIN_OR_WHITELISTED}
}] call ace_interact_menu_fnc_createAction;
["CAManBase", 0, ["ACE_MainActions"], _unmute, true] call ace_interact_menu_fnc_addActionToClass;
