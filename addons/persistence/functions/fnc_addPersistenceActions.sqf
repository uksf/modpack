#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds persistence actions

    Parameter(s):
        None

    Return Value:
        None
*/
params ["_unit"];

private _fnc_children = {
    private _actions = [];

    private _action = [QGVAR(shutdown), "Save and Shutdown", "", {[] call FUNC(shutdown)}, {MULTIPLAYER_ADMIN_OR_WHITELISTED}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(showPersistentObjects), "Show Persistent Objects", "", {[] call FUNC(showPersistentObjects)}, {MULTIPLAYER_ADMIN_OR_WHITELISTED && {GVAR(persistentObjectIconsPFHID) == -1}}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(hidePersistentObjects), "Hide Persistent Object Markers", "", {
        [GVAR(persistentObjectIconsPFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(persistentObjectIconsPFHID) = -1;
        [QGVAR(stopPersistentObjectsHash), [player]] call CBA_fnc_serverEvent;
    }, {MULTIPLAYER_ADMIN_OR_WHITELISTED && {GVAR(persistentObjectIconsPFHID) != -1}}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(showAbortedObjects), "Show Aborted Objects", "", {[QGVAR(requestAbortedObjects), [player]] call CBA_fnc_serverEvent}, {MULTIPLAYER_ADMIN_OR_WHITELISTED && {count GVAR(dontDeleteObjectIds) > 0} && {GVAR(abortedObjects) isEqualTo []}}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(hideabortedObjects), "Hide Aborted Objects", "", {
        [GVAR(abortedObjectPFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(abortedObjectPFHID) = -1;
        {deleteVehicle (_x#1)} forEach GVAR(abortedObjectInteractionObjects);
        GVAR(abortedObjectInteractionObjects) = [];
        GVAR(abortedObjects) = [];
    }, {MULTIPLAYER_ADMIN_OR_WHITELISTED && {!(GVAR(abortedObjects) isEqualTo [])}}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _actions
};

if (local _unit && {!(_unit getVariable [QGVAR(actionsAdded), false])}) then {
    private _action = [QGVAR(actions), "Persistence", "", {}, {true}, _fnc_children] call ace_interact_menu_fnc_createAction;
    [_unit, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
    _unit setVariable [QGVAR(actionsAdded), true];
};
