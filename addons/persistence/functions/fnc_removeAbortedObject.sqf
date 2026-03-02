#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes an aborted object from persistence entirely

    Parameter(s):
        0: Object ID <STRING>

    Return Value:
        None
*/
params ["_id"];

GVAR(abortedObjectIds) deleteAt (GVAR(abortedObjectIds) find _id);
publicVariable QGVAR(abortedObjectIds);

private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
private _index = _allObjects findIf {_x#IDX_OBJ_ID == _id};
if (_index == -1) exitWith {
    WARNING_1("Failed to unmark object with ID '%1' as persistent, could not find object data in saved objects",_id);
};

TRACE_1("Unmarking object as persistent",_id);
GVAR(unmarkedObjectIds) pushBack _id;
publicVariable QGVAR(unmarkedObjectIds);

_allObjects deleteAt _index;
GVAR(dataNamespace) setVariable [QGVAR(objects), _allObjects];
call FUNC(saveData);
