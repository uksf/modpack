#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Force loads an object that previously failed to load

    Parameter(s):
        0: Object ID <STRING>

    Return Value:
        None

    Example:
        [_id] call uksf_persistence_fnc_forceLoadAbortedObject
*/
params ["_id"];

GVAR(abortedObjectIds) deleteAt (GVAR(abortedObjectIds) find _id);
publicVariable QGVAR(abortedObjectIds);

private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
private _index = _allObjects findIf {_x#IDX_OBJ_ID == _id};
if (_index == -1) exitWith {
    WARNING_1("Forced loading of object with ID '%1' failed, could not find object data in saved objects",_id);
};

TRACE_1("Force loading object",_id);
private _object = _allObjects#_index;
_object set [IDX_OBJ_FAILEDLASTLOAD, false];
[_object, true] call FUNC(loadObjectData);
