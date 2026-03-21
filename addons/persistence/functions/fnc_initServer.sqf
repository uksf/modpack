#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises persistence on server.
        Creates state hashes, registers mission and CBA event handlers,
        then restores the saved session state.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_initServer
*/
TRACE_1("Server init",GVAR(dataSaved));

// State initialisation
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
if (isNil QGVAR(playerUids)) then {
    GVAR(playerUids) = [];
};
GVAR(shutdownSavingComplete) = false;
GVAR(serializers) = [];
GVAR(deserializers) = [];

if (GVAR(loadMapMarkers)) then {
    GVAR(mapMarkers) = GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []];
};

// Mission event handlers
addMissionEventHandler ["EntityRespawned", {call FUNC(entityRespawned)}];
addMissionEventHandler ["EntityKilled", {call FUNC(entityKilled)}];
addMissionEventHandler ["HandleDisconnect", {call FUNC(handleDisconnect)}];
addMissionEventHandler ["BuildingChanged", {
    params ["", "_newObject", "_isRuin"];

    if (_isRuin) then {
        _newObject setVariable [QGVAR(excluded), true];
    };
}];

// Core events
[QGVAR(registerSerializer), {call FUNC(registerSerializer)}] call CBA_fnc_addEventHandler;
[QGVAR(markObjectAsPersistent), {call FUNC(markObjectAsPersistent)}] call CBA_fnc_addEventHandler;
[QGVAR(forceLoadAbortedObject), {call FUNC(forceLoadAbortedObject)}] call CBA_fnc_addEventHandler;
[QGVAR(removeAbortedObjectFromPersistence), {call FUNC(removeAbortedObject)}] call CBA_fnc_addEventHandler;
[QGVAR(requestRedeployData), {call FUNC(requestRedeployData)}] call CBA_fnc_addEventHandler;
[QGVAR(checkPersistentVehicleExists), {call FUNC(checkPersistentVehicleExists)}] call CBA_fnc_addEventHandler;
[QGVAR(setObjectCargo), {[{call FUNC(setObjectCargo)}, _this] call CBA_fnc_execNextFrame}] call CBA_fnc_addEventHandler;
[QGVAR(addLogisticsMarker), {GVAR(persistenceMarkers) pushBackUnique _this}] call CBA_fnc_addEventHandler;

// Map marker events
[QGVAR(markerCreated), {
    params ["_serializedMarker"];

    GVAR(mapMarkers) deleteAt (GVAR(mapMarkers) findIf {_x#0 == _serializedMarker#0});
    GVAR(mapMarkers) pushBack _serializedMarker;
}] call CBA_fnc_addEventHandler;

[QGVAR(markerDeleted), {
    params ["_marker"];

    GVAR(mapMarkers) deleteAt (GVAR(mapMarkers) findIf {_x#0 == _marker});
}] call CBA_fnc_addEventHandler;

// ACE fortify integration
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

// Data request events
[QGVAR(requestPersistentObjectsHash), {
    params ["_player"];

    private _objects = [];
    [GVAR(persistentObjectsHash), {_objects pushBack [_key, _value]}] call CBA_fnc_hashEachPair;
    [QGVAR(receivePersistentObjectsHash), [_objects], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(requestAbortedObjects), {
    params ["_player"];

    private _objects = (GVAR(dataNamespace) getVariable [QGVAR(objects), []]) select {
        private _id = _x#IDX_OBJ_ID;
        _id != "" && {_id in GVAR(abortedObjectIds)}
    };
    [QGVAR(receiveAbortedObjects), [_objects], _player] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

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

// Shutdown events
[QGVAR(startShutdown), {call FUNC(startShutdown)}] call CBA_fnc_addEventHandler;
[QGVAR(readyForShutdown), {
    params [["_player", objNull, [objNull]]];

    if (isNull _player || {!isPlayer _player}) exitWith {};

    [{
        params ["_player"];

        SERVER_COMMAND serverCommand (format ["#kick %1", owner _player]);
    }, [_player], 1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

call FUNC(restoreSessionState);
