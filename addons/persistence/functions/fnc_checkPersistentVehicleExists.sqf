#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Waits for a persistent vehicle to exist in the hash, then notifies the client

    Parameter(s):
        0: Vehicle state <ARRAY> [vehicleId, role, index]
        1: Client <OBJECT>

    Return Value:
        None

    Example:
        [_vehicleState, _client] call uksf_persistence_fnc_checkPersistentVehicleExists
*/
params ["_vehicleState", "_client"];
_vehicleState params ["_vehicleId", "_role", "_index"];

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
