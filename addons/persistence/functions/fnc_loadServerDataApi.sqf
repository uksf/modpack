#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Triggers API persistence load and waits for data.
        On success, commits the session, initialises server, and loads persistent objects.
        On timeout, starts fresh with an empty namespace.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_loadServerDataApi
*/

private _result = "uksf" callExtension ("load:" + GVAR(key));
INFO_1("Extension load triggered: %1",_result);

INFO("Waiting for API persistence data...");
[{
    GVAR(apiLoadComplete)
}, {
    if (isNil QGVAR(apiLoadedSession)) then {
        WARNING("API load completed but no session data — starting fresh");
        GVAR(dataNamespace) = call CBA_fnc_createNamespace;
        GVAR(playerUids) = [];
    } else {
        INFO("API persistence data received, committing to namespace");
        [GVAR(apiLoadedSession)] call FUNC(commitApiSession);
        GVAR(apiLoadedSession) = nil;
    };

    call FUNC(initServer);
    call FUNC(loadServerData);
}, [], 60, {
    ERROR("API persistence load timed out after 60 seconds, proceeding without data");
    GVAR(dataNamespace) = call CBA_fnc_createNamespace;
    GVAR(playerUids) = [];
    call FUNC(initServer);
    INFO("No data saved, loading finished");
    [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
}] call CBA_fnc_waitUntilAndExecute;
