#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves object data

    Parameter(s):
        0: Centre <OBJECT> (Optional)
        1: Skip update <BOOL> (Optional)

    Return Value:
        None
*/
params [["_centre", objnull], ["_skip", false]];
// e
private _objects = GVAR(dataNamespace) getVariable [QGVAR(vehicles), []];
if (_objects isEqualTo []) then {
    _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
} else {
    WARNING("Found old data saved with vehicles name whilst saving, loading and removing");
    GVAR(dataNamespace) setVariable [QGVAR(objects), _objects];
    GVAR(dataNamespace) setVariable [QGVAR(vehicles), nil];
};

private _remove = [];
[GVAR(persistentObjectsHash), {
    if (isNull _value || {!(alive _value)}) then {
        _remove pushBack _key;
        private _index = _objects findIf {_x#0 == _key};
        _objects deleteAt _index;
    };
}] call CBA_fnc_hashEachPair;
//

// e
TRACE_1("Removing objects from persistent data, adding to deleted list",_remove);
{GVAR(deletedPersistentObjects) pushBackUnique _x} forEach (_remove select {!(_x in GVAR(dontDeleteObjectIds))});
{[GVAR(persistentObjectsHash), _x] call CBA_fnc_hashRem} forEach _remove;
//

if !(isNull _centre) then {
    private _terrainObjects = nearestTerrainObjects [_centre, [], CENTRE_RADIUS, false];
    private _nearObjects = (_centre nearObjects CENTRE_RADIUS) select {
        private _object = _x;
        [_terrainObjects, {_x == _object}] call EFUNC(common,arrayNone) &&
        {[["Building", "AllVehicles", "Thing"], {_object isKindOf _x}] call EFUNC(common,arrayAny)} &&
        {[["Man", "ThingEffect"], {_object isKindOf _x}] call EFUNC(common,arrayNone)}
    };
    _nearObjects = _nearObjects apply {[_x, _skip]};

    TRACE_2("Objects around centre",_centre,_nearObjects);
    GVAR(saveObjectQueue) append _nearObjects;

    if !(GVAR(saveObjectQueueProcessing)) then {
        call FUNC(startSaveObjectDataPfh);
    };


} else {
    {[_x, true] call FUNC(saveObjectData)} forEach (GVAR(persistenceMarkers) select {!(isNull _x)});

    // e
    [GVAR(persistentObjectsHash), {
        private _index = _objects findIf {_x#0 == _key};
        if (_index > -1) then {
            _objects set [_index, [_value] call FUNC(getObjectData)];
        } else {
            _objects pushBack ([_value] call FUNC(getObjectData));
        };
    }] call CBA_fnc_hashEachPair;
};

// e
INFO_1("Number of objects saved: %1",count _objects);
GVAR(dataNamespace) setVariable [QGVAR(deletedObjects), GVAR(deletedPersistentObjects)];
GVAR(dataNamespace) setVariable [QGVAR(objects), _objects];
if (GVAR(dataSaved)) then {
    profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
    saveProfileNamespace;
    LOG("Saved data");
};
//

// TODO: utilise queue and once per frame handling for centre objects, and another queue for near objects
// - saving should be performed after near object queue is processed
// - revise flow for shutdown to accommodate queue processing
