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

GVAR(readyForShutdownCount) = 0;
GVAR(readyForShutdownExpected) = count (call CBA_fnc_players);
INFO_1("Waiting for %1 players to report ready for shutdown",GVAR(readyForShutdownExpected));

[QGVAR(shutdownStarted)] call CBA_fnc_globalEvent;

[{
    GVAR(readyForShutdownCount) >= GVAR(readyForShutdownExpected)
}, {
    INFO_1("All players ready (%1 received), proceeding with shutdown",GVAR(readyForShutdownCount));
    call FUNC(finishShutdown);
}, [], 10, {
    WARNING_2("Shutdown ready timeout — received %1 of %2, proceeding anyway",GVAR(readyForShutdownCount),GVAR(readyForShutdownExpected));
    call FUNC(finishShutdown);
}] call CBA_fnc_waitUntilAndExecute;
