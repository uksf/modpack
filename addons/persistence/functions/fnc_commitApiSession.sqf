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

{
    private _key = _x;
    private _value = _session getVariable [_key, nil];
    if (isNil "_value") then { continue };

    GVAR(dataNamespace) setVariable [_key, _value];
    if (_key regexMatch "^[0-9]{17}$") then {
        GVAR(playerUids) pushBack _key;
    };
} forEach ([_session] call CBA_fnc_allVariables);

INFO("API session committed to namespace");
