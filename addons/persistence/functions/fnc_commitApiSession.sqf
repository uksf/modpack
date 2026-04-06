#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Commits a parsed API session hashmap into GVAR(dataNamespace).
        Creates a fresh namespace and populates it with objects, players,
        deleted objects, markers, datetime, and custom data.

        The API session is a native HashMap from CBA_fnc_parseJSON (mode 2).
        Values are already in raw positional array format matching the profile
        namespace format, so no conversion is needed.

    Parameter(s):
        0: Session hashmap <HASHMAP>

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
    private _value = _y;

    GVAR(dataNamespace) setVariable [_key, _value];
    if (_key regexMatch "^[0-9]{17}$") then {
        GVAR(playerUids) pushBack _key;
    };
} forEach _session;

INFO("API session committed to namespace");
