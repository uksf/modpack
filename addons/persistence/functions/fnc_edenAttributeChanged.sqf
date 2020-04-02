#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles 3den events for setting persistence ID

    Parameter(s):
        0: Object <OBJECT>
        1: Persistent (Optional) <BOOLEAN>
        2: Delete (Optional) <BOOLEAN>

    Return Value:
        ID <STRING>
*/
if (!is3DEN) exitWith {};

if (_this isEqualTo []) exitWith {
    {[_x] call FUNC(edenAttributeChanged);} forEach (all3DENEntities select 0);
};

params ["_object", ["_persistent", false], ["_delete", false]];

if (!_persistent) then {
    _persistent = (_object get3DENAttribute QGVAR(persistent))#0;
};

private _id = (_object get3DENAttribute QGVAR(persistenceID))#0;
if (_id isEqualType true) then {
    _id = "";
};


if (_delete) exitWith {
    _object clear3DENAttribute QGVAR(persistenceID);
    private _index = GVAR(edenPersistenceIdHash)#2 find _object;
    if (_index != -1) then {
        // Object is in the hash, remove it
        [GVAR(edenPersistenceIdHash), GVAR(edenPersistenceIdHash)#1#_index] call CBA_fnc_hashRem;
    };
};

// Vehicle is marked as persistent
if (_persistent) then {
    // ID is already set
    if (_id != "") then {
        // ID is already in the hash
        if ([GVAR(edenPersistenceIdHash), _id] call CBA_fnc_hashHasKey) then {
            // ID in hash has a different object associated with it
            if (_object != ([GVAR(edenPersistenceIdHash), _id] call CBA_fnc_hashGet)) then {
                // Generate new ID for this object and set attribute and add to hash
                _id = format ["%1_%2_%3", typeOf _object, diag_frameNo, round random 99999];
                _object set3DENAttribute [QGVAR(persistenceID), _id];
                [GVAR(edenPersistenceIdHash), _id, _object] call CBA_fnc_hashSet;
            };
        } else {
            private _index = GVAR(edenPersistenceIdHash)#2 find _object;
            if (_index != -1) then {
                // Object is already in the hash but the ID is different, update the ID in the hash
                [GVAR(edenPersistenceIdHash), GVAR(edenPersistenceIdHash)#1#_index] call CBA_fnc_hashRem;
                [GVAR(edenPersistenceIdHash), _id, _object] call CBA_fnc_hashSet;
            } else {
                // ID or object are not in the hash
                [GVAR(edenPersistenceIdHash), _id, _object] call CBA_fnc_hashSet;
            };
        };
    } else {
        // ID has not been set, generate and set attribute and add to hash
        _id = format ["%1_%2_%3", typeOf _object, diag_frameNo, round random 99999];
        _object set3DENAttribute [QGVAR(persistenceID), _id];
        [GVAR(edenPersistenceIdHash), _id, _object] call CBA_fnc_hashSet;
    };
} else {
    // Vehicle is not marked as persistent, set its ID to empty, and remove ID from hash if present
    _object clear3DENAttribute QGVAR(persistenceID);
    if ([GVAR(edenPersistenceIdHash), _id] call CBA_fnc_hashHasKey) then {
        [GVAR(edenPersistenceIdHash), _id] call CBA_fnc_hashRem;
    };
};

_id
