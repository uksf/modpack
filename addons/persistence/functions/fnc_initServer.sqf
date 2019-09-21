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
#include "script_component.hpp"

TRACE_1("Server init",GVAR(dataSaved));
GVAR(hashPersistentVehicles) = [[], true] call CBA_fnc_hashCreate;
GVAR(hashFirstKilled) = [[], true] call CBA_fnc_hashCreate;
GVAR(hashFirstRespawn) = [[], true] call CBA_fnc_hashCreate;
GVAR(persistenceMarkers) = [];
GVAR(mapMarkers) = GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []];

addMissionEventHandler ["PlayerConnected", {call FUNC(playerConnected)}];
addMissionEventHandler ["EntityRespawned", {call FUNC(entityRespawned)}];
addMissionEventHandler ["EntityKilled", {call FUNC(entityKilled)}];
addMissionEventHandler ["HandleDisconnect", {call FUNC(handleDisconnect)}];
addMissionEventHandler ["PlayerDisconnected", {call FUNC(playerDisconnected)}];

[QGVAR(shutdown), {call FUNC(shutdown)}] call CBA_fnc_addEventHandler;
[QGVAR(addLogisticsMarker), {GVAR(persistenceMarkers) pushBackUnique _this}] call CBA_fnc_addEventHandler;
[QGVAR(markVehicleAsPersistent), {call FUNC(markVehicleAsPersistent)}] call CBA_fnc_addEventHandler;

[QGVAR(checkPersistentVehicleExists), {
    [{
        params ["_vehicleState"];
        _vehicleState params ["_vehicleId"];
        private _exists = [GVAR(hashPersistentVehicles), _vehicleId] call CBA_fnc_hashHasKey;
        _exists
    }, {
        params ["_vehicleState", "_client"];
        _vehicleState params ["_vehicleId", "_role", "_index"];

        private _vehicle = [GVAR(hashPersistentVehicles), _vehicleId] call CBA_fnc_hashGet;
        [QGVAR(onPersistentVehicleExists), [_vehicle, _vehicleId, _role, _index], _client] call CBA_fnc_targetEvent;
    }, _this, 10, {
        params ["_vehicleState", "_client"];
        _vehicleState params ["_vehicleId", "_role", "_index"];

        [QGVAR(onPersistentVehicleExists), [objNull, _vehicleId, _role, _index], _client] call CBA_fnc_targetEvent;
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(markerCreated), {
    params ["_serializedMarker"];
    if ((GVAR(mapMarkers) findIf {_x#0 == (_serializedMarker#0)}) == -1) then {
        GVAR(mapMarkers) pushBack _serializedMarker;
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(markerDeleted), {
    params ["_marker"];
    GVAR(mapMarkers) deleteAt (GVAR(mapMarkers) findIf {_x#0 == _marker});
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
