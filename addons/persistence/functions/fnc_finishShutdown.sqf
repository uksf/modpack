#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Finishes the shutdown sequence after the player drain. Fires
        shutdownFinishing so components do their final syncs, runs the
        save barrier, sends mission_ended, reports the save outcome with
        shutdown_stopping, then shuts down the server.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_finishShutdown
*/
#define MISSION_ENDED_DELIVERY_TIMEOUT 10
#define STOPPING_DELIVERY_TIMEOUT 5

[QGVAR(shutdownFinishing)] call CBA_fnc_localEvent;

if (GVAR(dataSaved)) then {
    ["shutdown_saving"] call EFUNC(api,sendEvent);
};

[{
    params ["_outcome"];

    INFO_1("Shutdown save outcome: %1",_outcome);
    if (_outcome in ["partial", "rejected", "lost", "timeout", "unsent"]) then {
        ERROR_1("Shutdown save was not stored by the API: %1",_outcome);
    };

    private _missionEndedSeq = [] call EFUNC(api,sendMissionEnded);
    [_missionEndedSeq, MISSION_ENDED_DELIVERY_TIMEOUT, {
        params ["", "_saveOutcome"];

        private _seq = ["shutdown_stopping", createHashMapFromArray [["saveOutcome", _saveOutcome]]] call EFUNC(api,sendEvent);
        [_seq, STOPPING_DELIVERY_TIMEOUT, {
            SERVER_COMMAND serverCommand "#shutdown";
        }] call FUNC(waitForDelivery);
    }, _outcome] call FUNC(waitForDelivery);
}, [], true] call FUNC(saveBarrier);
