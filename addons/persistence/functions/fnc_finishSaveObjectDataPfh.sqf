#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops object saving PFH and saves data to namespace

    Parameter(s):
        None

    Return Value:
        None
*/
GVAR(shutdownSavingComplete) = true;

private _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
_objects = _objects select {!(isNil {_x#IDX_OBJ_ID}) && {_x#IDX_OBJ_ID != ""}};

private _remove = [];
[GVAR(persistentObjectsHash), {
    if (isNull _value || {!(alive _value)}) then {
        _remove pushBack _key;
        private _index = _objects findIf {_x#IDX_OBJ_ID == _key};
        _objects deleteAt _index;
    };
}] call CBA_fnc_hashEachPair;

TRACE_1("Removing objects from persistent data, adding to deleted list",_remove);
{GVAR(deletedPersistentObjects) pushBackUnique _x} forEach (_remove select {!(_x in GVAR(abortedObjectIds))});
{[GVAR(persistentObjectsHash), _x] call CBA_fnc_hashRem} forEach _remove;

INFO_1("Number of objects saved: %1",count _objects);
GVAR(dataNamespace) setVariable [QGVAR(deletedObjects), GVAR(deletedPersistentObjects)];
GVAR(dataNamespace) setVariable [QGVAR(objects), _objects];
call FUNC(saveData);
