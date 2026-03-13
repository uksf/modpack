#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads the previous persistence session on server.
        Resolves the mission key, creates the data namespace from API or profile,
        and extracts player UIDs when loading from profile.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_loadSession
*/

GVAR(key) = getMissionConfigValue ["persistenceKey", ""];
INFO_1("Mission Key: %1",GVAR(key));

if (GVAR(key) == "") exitWith {
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
};

GVAR(key) = format [QUOTE(GVAR(key)_%1_%2), worldName, GVAR(key)];
GVAR(dataSaved) = true;
GVAR(apiLoadComplete) = false;
GVAR(apiLoadedSession) = nil;

if (GVAR(useApiPersistence)) then {
    INFO("Using API persistence for loading");
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
} else {
    private _hash = profileNamespace getVariable [GVAR(key), []];
    TRACE_1("Loaded data",_hash);
    GVAR(dataNamespace) = [_hash] call CBA_fnc_deserializeNamespace;
    GVAR(playerUids) = [];
    {
        if (_x regexMatch "^[0-9]{17}$") then {
            GVAR(playerUids) pushBack _x;
        };
    } forEach ([GVAR(dataNamespace)] call CBA_fnc_allVariables);
};
