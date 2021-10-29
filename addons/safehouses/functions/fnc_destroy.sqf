#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Destroy safehouse

    Parameters:
        0: Anchor object <OBJECT>
        1: Killer <OBJECT>
        2: Instigator <OBJECT>

    Return value:
        Nothing
*/
params ["_anchorObject", "_killer", "_instigator"];

if !(isServer) exitWith {};

private _id = _anchorObject getVariable [QGVAR(id), ""];
private _prefabId = _anchorObject getVariable [QGVAR(prefabId), ""];
private _objects = _anchorObject getVariable [QGVAR(objects), []];

if (_id == "" || _prefabId == "") exitWith {
    ERROR("Failed to destroy safehouse");
};

{deleteVehicle _x} forEach _objects;

_anchorObject setVariable [QEGVAR(cleanup,excluded), true, true];

GVAR(locations) deleteAt _id;
GVAR(destroyed) set [_id, [_id, getPos _anchorObject, _prefabId]];

// If anchor destroyed by west, fire event
if (side _killer != west && side _instigator != west) exitWith {};
TRACE_1("Safehouse anchor destroyed",_anchorObject);

[QGVAR(destroyed), _anchorObject] call CBA_fnc_serverEvent;
