#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Return array of ACE interactions for aborted object

    Parameter(s):
        0: Target <OBJECT>
        1: Player <OBJECT>
        2: Params <ARRAY>
            0: Id <STRING>

    Return Value:
        ARRAY
*/
params ["_target", "", "_params"];
_params params ["_id"];

private _actions = [];

private _action = [QGVAR(forceLoadAbortedObject), "Force Load Aborted Object", "", {
    params ["_target", "", "_params"];
    _params params ["_id"];

    [QGVAR(removeAbortedObjectGhost), _id] call CBA_fnc_globalEvent;
    [QGVAR(forceLoadAbortedObject), _id] call CBA_fnc_serverEvent;
}, {true}, {}, [_id]] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _target];

private _action = [QGVAR(removeAbortedObjectFromPersistence), "Remove Aborted Object From Persistence", "", {
    params ["_target", "", "_params"];
    _params params ["_id"];

    [QGVAR(removeAbortedObjectGhost), _id] call CBA_fnc_globalEvent;
    [QGVAR(removeAbortedObjectFromPersistence), _id] call CBA_fnc_serverEvent;
}, {
    params ["", "", "_params"];
    _params params ["_id"];

    [GVAR(unmarkedObjectIds), {_x == _id}] call EFUNC(common,arrayNone)
}, {}, [_id]] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _target];

_actions
