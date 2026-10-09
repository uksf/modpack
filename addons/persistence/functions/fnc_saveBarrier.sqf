#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Captures players and persistent objects across frames, sends the
        save to the API, and waits for its delivery outcome. Calls the
        callback with [outcome, callback arguments]. The outcome is
        delivered, rejected, lost, timeout, unsent, or unsaved when the
        mission has no persistence key.

    Parameter(s):
        0: Callback <CODE>
        1: Callback arguments <ANY>

    Return Value:
        None

    Example:
        [{params ["_outcome", "_args"]}, []] call uksf_persistence_fnc_saveBarrier
*/
#define SAVE_DELIVERY_TIMEOUT 130

params ["_callback", ["_callbackArgs", []]];

if (!GVAR(dataSaved)) exitWith {
    ["unsaved", _callbackArgs] call _callback;
};

call FUNC(snapshotPlayers);
{
    private _marker = createVehicle [QGVAR(markerAmmo), _x, [], 0, "CAN_COLLIDE"];
    GVAR(persistenceMarkers) pushBack _marker;
} forEach (values GVAR(disconnectedPlayerPositions));

[{
    params ["_seq", "_barrierArgs"];
    [_seq, SAVE_DELIVERY_TIMEOUT, {
        params ["_outcome", "_barrierArgs"];
        _barrierArgs params ["_callback", "_callbackArgs"];
        GVAR(missionSaved) = _outcome == "delivered";
        [_outcome, _callbackArgs] call _callback;
    }, _barrierArgs] call FUNC(waitForDelivery);
}, [_callback, _callbackArgs]] call FUNC(shutdownSave);
