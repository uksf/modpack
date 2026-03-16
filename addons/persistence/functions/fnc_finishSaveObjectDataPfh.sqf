#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Finishes object saving, collects all remaining persistence data
        (dateTime, mapMarkers, serializers), and saves everything to namespace

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_finishSaveObjectDataPfh
*/
GVAR(shutdownSavingComplete) = true;

// Save dateTime, mapMarkers, and serializer data
private _dateTime = date;
TRACE_1("Saving date time",_dateTime);
GVAR(dataNamespace) setVariable [QGVAR(dateTime), _dateTime];
GVAR(dataNamespace) setVariable [QGVAR(mapMarkers), GVAR(mapMarkers)];

{
    _x params ["_id", "_function"];

    private _data = [] call _function;
    GVAR(dataNamespace) setVariable [_id, _data];
} forEach GVAR(serializers);

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
