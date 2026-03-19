#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deletes persistent data

    Parameter(s):
        0: Data key <STRING>

    Return Value:
        None

    Example:
        [_key] call uksf_persistence_fnc_deletePersistentData
*/

if (!isServer) exitWith {};

params [["_key", GVAR(key)]];

if (_key == "") exitWith {};

WARNING_1("Deleting persistence data for key %1",_key);
profileNamespace setVariable [_key, nil];
saveProfileNamespace;
