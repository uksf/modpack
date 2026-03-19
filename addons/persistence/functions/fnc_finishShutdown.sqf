#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Finishes the shutdown sequence after all players have acknowledged
        readyForShutdown (or timeout). Fires the shuttingDown event for
        server-side components to do final syncs, then saves persistence
        data and shuts down the server.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_finishShutdown
*/

TRACE_1("Finishing shutdown: firing shuttingDown",diag_tickTime);
[QGVAR(shuttingDown)] call CBA_fnc_localEvent;

TRACE_1("Proceeding with persistence save",GVAR(dataSaved));
if (GVAR(dataSaved)) then {
    {
        private _marker = createVehicle [QGVAR(markerAmmo), _x, [], 0, "CAN_COLLIDE"];
        GVAR(persistenceMarkers) pushBack _marker;
    } forEach (values GVAR(disconnectedPlayerPositions));
    call FUNC(shutdownSave);
} else {
    GVAR(shutdownSavingComplete) = true;
};

[{
    GVAR(shutdownSavingComplete)
}, {
    TRACE_1("Sending shutdown_complete and flushing extension",diag_tickTime);
    ["shutdown_complete"] call EFUNC(api,sendEvent);
    private _flushResult = "uksf" callExtension "flush";
    TRACE_1("Extension flush result",_flushResult);

    [{SERVER_COMMAND serverCommand "#shutdown"}, [], 5] call CBA_fnc_waitAndExecute;
}, [], 120, {
    WARNING("Shutdown save timed out after 120 seconds, forcing shutdown");
    ["shutdown_complete"] call EFUNC(api,sendEvent);
    "uksf" callExtension "flush";
    [{SERVER_COMMAND serverCommand "#shutdown"}, [], 5] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_waitUntilAndExecute;
