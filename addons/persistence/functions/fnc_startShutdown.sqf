#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the server shutdown cycle

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

[QEGVAR(common,textTiles), [parseText "<t align = 'center' color = '#1a7a1a'>Server shutting down</t>", [0.25, 0.5, 0.5, 0.085], [1, 1], 2.5], [] call CBA_fnc_players] call CBA_fnc_targetEvent;

// Notify other components that shutdown is starting
[QGVAR(shutdownStarted)] call CBA_fnc_localEvent;

[{
    params ["", "_idPFH"];

    private _players = call CBA_fnc_players;
    if (_players isEqualTo []) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
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
            ["shutdown_complete"] call EFUNC(api,sendEvent);
            "uksf" callExtension "flush";

            [{SERVER_COMMAND serverCommand "#shutdown"}, [], 4] call CBA_fnc_waitAndExecute;
        }, [], 120, {
            WARNING("Shutdown save timed out after 120 seconds, forcing shutdown");
            ["shutdown_complete"] call EFUNC(api,sendEvent);
            "uksf" callExtension "flush";
            [{SERVER_COMMAND serverCommand "#shutdown"}, [], 4] call CBA_fnc_waitAndExecute;
        }] call CBA_fnc_waitUntilAndExecute;
    };

    SERVER_COMMAND serverCommand (format ["#kick %1", owner (_players#0)]);
}, 2, []] call CBA_fnc_addPerFrameHandler;
