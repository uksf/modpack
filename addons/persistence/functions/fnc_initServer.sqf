#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises persistence on server

    Parameter(s):
        None

    Return Value:
        None
*/
TRACE_1("Server init",GVAR(dataSaved));

GVAR(missionObjects) = [];
GVAR(persistentObjectsHash) = [[], true] call CBA_fnc_hashCreate;
GVAR(deletedPersistentObjects) = GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []];
GVAR(abortedObjectIds) = [];
GVAR(unmarkedObjectIds) = [];
GVAR(hashHasRedeployed) = [[], false] call CBA_fnc_hashCreate;
GVAR(hashFirstRespawn) = [[], true] call CBA_fnc_hashCreate;
GVAR(hashBodies) = [[], objNull] call CBA_fnc_hashCreate;
GVAR(persistenceMarkers) = [];
GVAR(mapMarkers) = [];
GVAR(saveObjectQueue) = [];
GVAR(disconnectedPlayerPositions) = createHashMap;
GVAR(shutdownSavingComplete) = false;
GVAR(serializers) = [];
GVAR(deserializers) = [];

if (GVAR(loadMapMarkers)) then {
    GVAR(mapMarkers) = GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []];
};

addMissionEventHandler ["EntityRespawned", {call FUNC(entityRespawned)}];
addMissionEventHandler ["EntityKilled", {call FUNC(entityKilled)}];
addMissionEventHandler ["HandleDisconnect", {call FUNC(handleDisconnect)}];
addMissionEventHandler ["BuildingChanged", {
    params ["", "_newObject", "_isRuin"];

    // TODO: Persistent ruins?
    if (_isRuin) then {
        _newObject setVariable [QGVAR(excluded), true];
    };
}];

[QGVAR(shutdown), {call FUNC(shutdown)}] call CBA_fnc_addEventHandler;

[QGVAR(registerSerializer), {call FUNC(registerSerializer)}] call CBA_fnc_addEventHandler;
[QGVAR(markObjectAsPersistent), {call FUNC(markObjectAsPersistent)}] call CBA_fnc_addEventHandler;

[QGVAR(forceLoadAbortedObject), {
    params ["_id"];

    GVAR(abortedObjectIds) deleteAt (GVAR(abortedObjectIds) find _id);
    publicVariable QGVAR(abortedObjectIds);

    private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    private _index = _allObjects findIf {_x#IDX_OBJ_ID == _id};
    if (_index == -1) then {
        WARNING_1("Forced loading of object with ID '%1' failed, could not find object data in saved objects",_id);
    } else {
        TRACE_1("Force loading object",_id);
        private _object = _allObjects#_index;
        _object set [IDX_OBJ_FAILEDLASTLOAD, false];
        [_object, true] call FUNC(loadObjectData);
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(removeAbortedObjectFromPersistence), {
    params ["_id"];

    GVAR(abortedObjectIds) deleteAt (GVAR(abortedObjectIds) find _id);
    publicVariable QGVAR(abortedObjectIds);

    private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    private _index = _allObjects findIf {_x#IDX_OBJ_ID == _id};
    if (_index == -1) then {
        WARNING_1("Failed to unmark object with ID '%1' as persistent, could not find object data in saved objects",_id);
    } else {
        TRACE_1("Unmarking object as persistent",_id);
        GVAR(unmarkedObjectIds) pushBack _id;
        publicVariable QGVAR(unmarkedObjectIds);

        _allObjects deleteAt _index;
        GVAR(dataNamespace) setVariable [QGVAR(objects), _allObjects];
        call FUNC(saveData);
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(requestRedeployData), {
    params ["_player"];

    private _uid = getPlayerUID _player;
    private _hasRedeployed = [GVAR(hashHasRedeployed), _uid] call CBA_fnc_hashGet;
    if !(_hasRedeployed) then {
        [GVAR(hashHasRedeployed), _uid, true] call CBA_fnc_hashSet;
        private _data = GVAR(dataNamespace) getVariable [_uid, []];
        TRACE_1("Sending player redeploy data",_data);
        if (count _data > 0) then {
            [QGVAR(receiveRedeployData), _data, _player] call CBA_fnc_targetEvent;
        };
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(requestPersistentObjectsHash), {
    params ["_player"];

    private _objects = [];
    [GVAR(persistentObjectsHash), {_objects pushBack [_key, _value];}] call CBA_fnc_hashEachPair;
    [QGVAR(receivePersistentObjectsHash), [_objects], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(requestAbortedObjects), {
    params ["_player"];

    private _objects = (GVAR(dataNamespace) getVariable [QGVAR(objects), []]) select {private _id = _x#IDX_OBJ_ID; _id != "" && {[GVAR(abortedObjectIds), {_x == _id}] call EFUNC(common,arrayAny)}};
    [QGVAR(receiveAbortedObjects), [_objects], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(checkPersistentVehicleExists), {
    [{
        params ["_vehicleState"];
        _vehicleState params ["_vehicleId"];

        [GVAR(persistentObjectsHash), _vehicleId] call CBA_fnc_hashHasKey
    }, {
        params ["_vehicleState", "_client"];
        _vehicleState params ["_vehicleId", "_role", "_index"];

        private _vehicle = [GVAR(persistentObjectsHash), _vehicleId] call CBA_fnc_hashGet;
        [QGVAR(onPersistentVehicleExists), [_vehicle, _vehicleId, _role, _index], _client] call CBA_fnc_targetEvent;
    }, _this, 10, {
        params ["_vehicleState", "_client"];
        _vehicleState params ["_vehicleId", "_role", "_index"];

        [QGVAR(onPersistentVehicleExists), [objNull, _vehicleId, _role, _index], _client] call CBA_fnc_targetEvent;
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(addLogisticsMarker), {GVAR(persistenceMarkers) pushBackUnique _this}] call CBA_fnc_addEventHandler;

[QGVAR(requestPersistenceMarkers), {
    params ["_player"];

    private _positions = (GVAR(persistenceMarkers) - [objNull]) apply {[getPosATL _x]};
    [QGVAR(receivePersistenceMarkers), [_positions], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(requestDisconnectedPositions), {
    params ["_player"];

    private _data = [];
    {_data pushBack [_x, _y]} forEach GVAR(disconnectedPlayerPositions);
    [QGVAR(receiveDisconnectedPositions), [_data], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(requestInspectSavedData), {
    params ["_player"];

    private _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    private _deletedObjects = GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []];

    private _lines = [];
    _lines pushBack format ["--- Persistence Data Summary ---"];
    _lines pushBack format ["Saved objects: %1", count _objects];
    _lines pushBack format ["Deleted object IDs: %1", count _deletedObjects];
    _lines pushBack format ["Aborted object IDs: %1", count GVAR(abortedObjectIds)];
    _lines pushBack format ["Persistence markers: %1", count (GVAR(persistenceMarkers) - [objNull])];
    _lines pushBack format ["Disconnected players: %1", count GVAR(disconnectedPlayerPositions)];
    _lines pushBack format ["Serializers: %1", count GVAR(serializers)];
    _lines pushBack format ["Map markers: %1", count GVAR(mapMarkers)];

    private _typeCounts = createHashMap;
    {
        private _type = _x#IDX_OBJ_TYPE;
        if (!isNil "_type" && {_type isEqualType ""}) then {
            _typeCounts set [_type, (_typeCounts getOrDefault [_type, 0]) + 1];
        };
    } forEach _objects;

    if (count _typeCounts > 0) then {
        _lines pushBack "--- Object Types ---";
        private _sorted = [];
        {_sorted pushBack [_y, _x]} forEach _typeCounts;
        _sorted sort false;
        {_lines pushBack format ["  %1: %2", _x#1, _x#0]} forEach (_sorted select [0, 15 min count _sorted]);
        if (count _sorted > 15) then {
            _lines pushBack format ["  ... and %1 more types", count _sorted - 15];
        };
    };

    {INFO_1("InspectData: %1",_x)} forEach _lines;
    [QGVAR(receiveInspectSavedData), [_lines], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(setObjectCargo), {[{call FUNC(setObjectCargo)}, _this] call CBA_fnc_execNextFrame}] call CBA_fnc_addEventHandler;

[QGVAR(markerCreated), {
    params ["_serializedMarker"];

    GVAR(mapMarkers) deleteAt (GVAR(mapMarkers) findIf {_x#0 == _serializedMarker#0});
    GVAR(mapMarkers) pushBack _serializedMarker;
}] call CBA_fnc_addEventHandler;

[QGVAR(markerDeleted), {
    params ["_marker"];

    GVAR(mapMarkers) deleteAt (GVAR(mapMarkers) findIf {_x#0 == _marker});
}] call CBA_fnc_addEventHandler;

["acex_fortify_objectPlaced", {
    params ["", "_side", "_object"];

    _object setVariable [QGVAR(isAceFortification), true];
    _object setVariable [QGVAR(aceFortifySide), _side];
    [_object] call FUNC(markObjectAsPersistent);
}] call CBA_fnc_addEventHandler;

["acex_fortify_objectDeleted", {
    params ["", "", "_object"];

    private _id = _object getVariable [QGVAR(persistenceID), ""];
    if (_id == "") exitWith {
        WARNING("Object has no id so cannot remove from persistence hash. Object saving should filter out null objects.");
    };

    [GVAR(persistentObjectsHash), _id] call CBA_fnc_hashRem;
}] call CBA_fnc_addEventHandler;

call FUNC(saveData);

if (!GVAR(overrideSavedDateTime)) then {
    private _dateTime = GVAR(dataNamespace) getVariable [QGVAR(dateTime), date];
    TRACE_1("Setting datetime",_dateTime);
    setDate _dateTime;
} else {
    WARNING("Saved datetime overridden by mission");
};

private _markers = +GVAR(mapMarkers);
GVAR(mapMarkers) = [];
{
    private _marker = [_x] call FUNC(deserializeMarker);
    GVAR(mapMarkers) pushBack ([_marker] call FUNC(serializeMarker));
} forEach _markers;
