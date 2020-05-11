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

TRACE_1("Removing objects from persistent data, adding to deleted list",_remove);
{GVAR(deletedPersistentObjects) pushBackUnique _x} forEach (_remove select {!(_x in GVAR(dontDeleteObjectIds))});
{[GVAR(persistentObjectsHash), _x] call CBA_fnc_hashRem} forEach _remove;

if !(isNull _centre) then {
    private _terrainObjects = nearestTerrainObjects [_centre, [], CENTRE_RADIUS, false];
    private _nearObjects = (_centre nearObjects CENTRE_RADIUS) select {
        private _object = _x;
        [_terrainObjects, {_x == _object}] call EFUNC(common,arrayNone) &&
        {[["Building","AllVehicles","Thing"], {_object isKindOf _x}] call EFUNC(common,arrayAny)} &&
        {[["Man","ThingEffect"], {_object isKindOf _x}] call EFUNC(common,arrayNone)}
    };

    TRACE_2("Objects around centre",_centre,_nearObjects);
    {
        private _object = _x;
        if (isNull (attachedTo _object)) then {
            private _id = _object getVariable [QGVAR(persistenceID), ""];
            if (_id == "") then {
                _id = [_object] call FUNC(markObjectAsPersistent);
            };
            TRACE_1("Object ID",_id);
            if (!_skip) then {
                private _index = _objects findIf {_x#0 == _id};
                TRACE_1("Exists?",_index);
                if (_index > -1) then {
                    _objects set [_index, [_object] call FUNC(getObjectData)];
                    TRACE_1("Updated",_id);
                } else {
                    _objects pushBack ([_object] call FUNC(getObjectData));
                    TRACE_1("Added",_id);
                };
            };
        };
    } forEach _nearObjects;
} else {
    {[_x, true] call FUNC(saveObjectData)} forEach (GVAR(persistenceMarkers) select {!(isNull _x)});

    [GVAR(persistentObjectsHash), {
        private _index = _objects findIf {_x#0 == _key};
        if (_index > -1) then {
            _objects set [_index, [_value] call FUNC(getObjectData)];
        } else {
            _objects pushBack ([_value] call FUNC(getObjectData));
        };
    }] call CBA_fnc_hashEachPair;
};

INFO_1("Number of objects saved: %1",count _objects);
GVAR(dataNamespace) setVariable [QGVAR(deletedObjects), GVAR(deletedPersistentObjects)];
GVAR(dataNamespace) setVariable [QGVAR(objects), _objects];
if (GVAR(dataSaved)) then {
    profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
    saveProfileNamespace;
    LOG("Saved data");
};
