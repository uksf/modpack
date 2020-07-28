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
GVAR(dontDeleteObjectIds) = [];
GVAR(unmarkedObjectIds) = [];
GVAR(hashHasRedeployed) = [[], false] call CBA_fnc_hashCreate;
GVAR(hashFirstRespawn) = [[], true] call CBA_fnc_hashCreate;
GVAR(persistenceMarkers) = [];
GVAR(mapMarkers) = GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []];
GVAR(saveObjectQueue) = [];
GVAR(saveObjectQueueProcessing) = false;

// addMissionEventHandler ["PlayerConnected", {call FUNC(playerConnected)}];
addMissionEventHandler ["EntityRespawned", {call FUNC(entityRespawned)}];
addMissionEventHandler ["EntityKilled", {call FUNC(entityKilled)}];
addMissionEventHandler ["HandleDisconnect", {call FUNC(handleDisconnect)}];
addMissionEventHandler ["PlayerDisconnected", {call FUNC(playerDisconnected)}];

[QGVAR(shutdown), {call FUNC(shutdown)}] call CBA_fnc_addEventHandler;

[QGVAR(markObjectAsPersistent), {call FUNC(markObjectAsPersistent)}] call CBA_fnc_addEventHandler;

[QGVAR(forceLoadAbortedObject), {
    params ["_id"];

    GVAR(dontDeleteObjectIds) deleteAt (GVAR(dontDeleteObjectIds) find _id);
    publicVariable QGVAR(dontDeleteObjectIds);

    private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    private _index = _allObjects findIf {_x#0 == _id};
    if (_index == -1) then {
        WARNING_1("Forced loading of object with ID '%1' failed, could not find object data in saved objects",_id);
    } else {
        TRACE_1("Force loading object",_id);
        [_allObjects#_index, true] call FUNC(loadObjectData);
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(removeAbortedObjectFromPersistence), {
    params ["_id"];

    GVAR(dontDeleteObjectIds) deleteAt (GVAR(dontDeleteObjectIds) find _id);
    publicVariable QGVAR(dontDeleteObjectIds);

    private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    private _index = _allObjects findIf {_x#0 == _id};
    if (_index == -1) then {
        WARNING_1("Failed to unmark object with ID '%1' as persistent, could not find object data in saved objects",_id);
    } else {
        TRACE_1("Unmarking object as persistent",_id);
        GVAR(unmarkedObjectIds) pushBack _id;
        publicVariable QGVAR(unmarkedObjectIds);

        _allObjects deleteAt _index;
        GVAR(dataNamespace) setVariable [QGVAR(objects), _allObjects];
        if (GVAR(dataSaved)) then {
            profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
            saveProfileNamespace;
            LOG("Saved data");
        };
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

    private _objects = (GVAR(dataNamespace) getVariable [QGVAR(objects), []]) select {private _id = _x#0; _id != "" && {[GVAR(dontDeleteObjectIds), {_x == _id}] call EFUNC(common,arrayAny)}};
    [QGVAR(receiveAbortedObjects), [_objects], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(checkPersistentVehicleExists), {
    [{
        params ["_vehicleState"];
        _vehicleState params ["_vehicleId"];
        private _exists = [GVAR(persistentObjectsHash), _vehicleId] call CBA_fnc_hashHasKey;
        _exists
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

[QGVAR(markerCreated), {
    params ["_serializedMarker"];
    if ([GVAR(mapMarkers), {_x#0 == (_serializedMarker#0)}] call EFUNC(common,arrayNone)) then {
        GVAR(mapMarkers) pushBack _serializedMarker;
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(markerDeleted), {
    params ["_marker"];
    GVAR(mapMarkers) deleteAt (GVAR(mapMarkers) findIf {_x#0 == _marker});
}] call CBA_fnc_addEventHandler;

["acex_fortify_objectPlaced", {
    params ["", "_side", "_object"];

    _object setVariable [QGVAR(isAcexFortification), true];
    _object setVariable [QGVAR(acexFortifySide), _side];
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

GVAR(dataNamespace) setVariable [QGVAR(world), worldName];
if (GVAR(dataSaved)) then {
    profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
    saveProfileNamespace;
    LOG("Saved data");
};

if (!GVAR(overrideSavedDateTime)) then {
    private _dateTime = GVAR(dataNamespace) getVariable [QGVAR(dateTime), date];
    TRACE_1("Setting date time",_dateTime);
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
