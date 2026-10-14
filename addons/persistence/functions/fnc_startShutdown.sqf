#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the server shutdown cycle.

        Broadcasts shutdownStarted globally so all machines can flush data
        and prepare for shutdown. Waits for all players to acknowledge via
        readyForShutdown, then calls finishShutdown.

        Every player's state is captured first, so a player who has not
        disconnected when the drain times out is still saved.
        Players are kicked individually as they report ready.
        HCs flush and report but are not tracked or kicked.

        A repeated shutdown request is a no-op. A shutdown requested during
        a mission end or restart save is held, and that transition hands over
        to a full shutdown save at its next safe point.

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

["shutdown_ending"] call EFUNC(api,sendEvent);

if (GVAR(transition) == "shutdown") exitWith {
    INFO("Shutdown already in progress");
};

if (GVAR(transition) != "") exitWith {
    if (!GVAR(shutdownPending)) then {
        INFO_1("Shutdown requested during mission %1 save, shutting down after that save",GVAR(transition));
    };
    GVAR(shutdownPending) = true;
};

GVAR(transition) = "shutdown";
GVAR(shutdownPending) = false;
GVAR(shutdownInProgress) = true;
if (GVAR(dataSaved)) then {
    call FUNC(snapshotPlayers);
};

LOG("Shutdown");

GVAR(shutdownExpectedDisconnectCount) = count (call CBA_fnc_players);
INFO_1("Waiting for %1 players to disconnect before shutdown",GVAR(shutdownExpectedDisconnectCount));

[QGVAR(shutdownStarted)] call CBA_fnc_globalEvent;

[{
    GVAR(shutdownDisconnectedCount) >= GVAR(shutdownExpectedDisconnectCount)
}, {
    INFO_2("All players disconnected and saved (%1 of %2), proceeding with shutdown",GVAR(shutdownDisconnectedCount),GVAR(shutdownExpectedDisconnectCount));
    call FUNC(finishShutdown);
}, [], 10, {
    WARNING_2("Shutdown timeout — saved %1 of %2 player disconnects, proceeding anyway",GVAR(shutdownDisconnectedCount),GVAR(shutdownExpectedDisconnectCount));
    call FUNC(finishShutdown);
}] call CBA_fnc_waitUntilAndExecute;
