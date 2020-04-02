#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Marks an object as persistent, and assigns an ID.
        Should be called on server

    Parameter(s):
        0: Object <OBJECT>
        1: ID <STRING>

    Return Value:
        ID <STRING>
*/
if (!isMultiplayer || is3DEN) exitWith {};

if (!isServer) exitWith {
    [QGVAR(markVehicleAsPersistent), _this] call CBA_fnc_serverEvent;
};

params ["_object", ["_id", "", [""]]];

// ID already set
if (_object getVariable [QGVAR(persistenceID), ""] != "") exitWith {};

// Generate ID if empty
if (_id == "") then {
    _id = format ["%1_%2_%3", typeOf _object, diag_frameNo, round random 99999];
    TRACE_1("Object marked as persistent has no ID, generating one",_id);
};

_object setVariable [QGVAR(persistenceID), _id];
[GVAR(hashPersistentVehicles), _id, _object] call CBA_fnc_hashSet;
TRACE_2("Object marked as persistent",_object,_id);

_id
