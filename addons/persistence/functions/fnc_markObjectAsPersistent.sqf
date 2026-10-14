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

    Example:
        [_object, _id] call uksf_persistence_fnc_markObjectAsPersistent
*/
if (!isMultiplayer || is3DEN) exitWith {};

if (!isServer) exitWith {
    [QGVAR(markObjectAsPersistent), _this] call CBA_fnc_serverEvent;
};

params ["_object", ["_id", "", [""]]];

private _existingId = _object getVariable [QGVAR(persistenceID), ""];
if (_existingId != "") exitWith {_existingId};

private _holder = [GVAR(persistentObjectsHash), _id] call CBA_fnc_hashGet;
if (_id != "" && {!isNil "_holder"} && {_holder isEqualType objNull} && {!isNull _holder} && {_holder != _object}) exitWith {
    WARNING_3("Persistence ID %1 already belongs to %2, not assigning it to %3",_id,_holder,_object);
    ""
};

if (_id == "") then {
    _id = format ["%1_%2", typeOf _object, call CBA_fnc_createUUID];
    TRACE_1("Object marked as persistent has no ID, generating one",_id);
};

_object setVariable [QGVAR(persistenceID), _id];
[GVAR(persistentObjectsHash), _id, _object] call CBA_fnc_hashSet;
TRACE_2("Object marked as persistent",_object,_id);

_id
