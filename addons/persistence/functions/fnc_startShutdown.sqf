#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the server shutdown cycle.

        Broadcasts shutdownStarted globally so all machines can flush data
        and prepare for shutdown. Waits for all players to acknowledge via
        readyForShutdown, then calls finishShutdown.

        Players are kicked individually as they report ready.
        HCs flush and report but are not tracked or kicked.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_startShutdown
*/

if (!isServer) exitWith {
    [QGVAR(startShutdown)] call CBA_fnc_serverEvent;
};

if (GVAR(shutdownInProgress)) exitWith {
    WARNING("Shutdown already in progress, ignoring duplicate call");
};

GVAR(shutdownInProgress) = true;

LOG("Shutdown");

GVAR(shutdownExpectedDisconnectCount) = count (call CBA_fnc_players);
INFO_1("Waiting for %1 players to disconnect before shutdown",GVAR(shutdownExpectedDisconnectCount));

[QGVAR(shutdownStarted)] call CBA_fnc_globalEvent;

[{
    GVAR(shutdownDisconnectedCount) >= GVAR(shutdownExpectedDisconnectCount)
}, {
    INFO_2("All players disconnected and saved (%1 of %2), proceeding with shutdown",GVAR(shutdownDisconnectedCount),GVAR(shutdownExpectedDisconnectCount));
    call FUNC(finishShutdown);
}, [], 30, {
    WARNING_2("Shutdown timeout — saved %1 of %2 player disconnects, proceeding anyway",GVAR(shutdownDisconnectedCount),GVAR(shutdownExpectedDisconnectCount));
    call FUNC(finishShutdown);
}] call CBA_fnc_waitUntilAndExecute;
