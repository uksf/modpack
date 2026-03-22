#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Commits a parsed API session namespace into GVAR(dataNamespace).
        Creates a fresh namespace and populates it with objects, players,
        deleted objects, markers, datetime, and custom data.

        The API session is a CBA namespace (Location) from CBA_fnc_parseJSON.
        Values are already in raw positional array format matching the profile
        namespace format, so no conversion is needed.

        WARNING: This function is not currently called from any production code path.

    Parameter(s):
        0: Session namespace <LOCATION>

    Return Value:
        None

    Example:
        [_session] call uksf_persistence_fnc_commitApiSession
*/
params ["_session"];

GVAR(dataNamespace) = call CBA_fnc_createNamespace;
GVAR(playerUids) = [];

// Known keys that map directly to namespace variables
private _knownKeys = [QGVAR(objects), QGVAR(deletedObjects), QGVAR(dateTime), QGVAR(mapMarkers)];

// Copy all variables from the API namespace to the data namespace
{
    private _key = _x;
    private _value = _session getVariable [_key, nil];
    if (isNil "_value") then { continue };

    if (_key in _knownKeys) then {
        GVAR(dataNamespace) setVariable [_key, _value];
    } else {
        if (_key regexMatch "^[0-9]{17}$") then {
            GVAR(dataNamespace) setVariable [_key, _value];
            GVAR(playerUids) pushBack _key;
        } else {
            // Custom data
            GVAR(dataNamespace) setVariable [_key, _value];
        };
    };
} forEach ([_session] call CBA_fnc_allVariables);

INFO("API session committed to namespace");
