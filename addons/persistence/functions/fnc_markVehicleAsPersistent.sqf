/*
    Author:
        Tim Beswick

    Description:
        Marks a vehicle as persistent, and assigns an ID.
        Should be called on server

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        ID <STRING>
*/
#include "script_component.hpp"

if (!isServer) exitWith {
    [QGVAR(markVehicleAsPersistent), _this] call CBA_fnc_serverEvent;
};

params ["_vehicle"];

if (_vehicle getVariable [QGVAR(persistenceID), ""] != "") exitWith {};

private _position = getPos _vehicle;
private _id = format ["%1:%2:%3:%4", typeOf _vehicle, round (_position#0), round (_position#1), round (_position#2)];

_vehicle setVariable [QGVAR(persistenceID), _id];
[GVAR(hashPersistentVehicles), _id, _vehicle] call CBA_fnc_hashSet;
TRACE_1("Vehicle marked as persistent",_id);

_id
