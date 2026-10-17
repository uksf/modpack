#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Captures players and persistent objects across frames, sends the
        save to the API, and waits for its delivery outcome. Calls the
        callback with [outcome, callback arguments]. The outcome is
        delivered, partial when the capture cap cut the save short,
        rejected, lost, timeout, unsent, or unsaved when the mission has
        no persistence key. During a shutdown it reports
        shutdown_delivering once the capture is sent.

    Parameter(s):
        0: Callback <CODE>
        1: Callback arguments <ANY>
        2: Report shutdown_delivering <BOOL> (default: false)

    Return Value:
        None

    Example:
        [{params ["_outcome", "_args"]}, []] call uksf_persistence_fnc_saveBarrier
*/
#define SAVE_DELIVERY_TIMEOUT 130

params ["_callback", ["_callbackArgs", []], ["_reportDelivering", false]];

if (!GVAR(dataSaved)) exitWith {
    ["unsaved", _callbackArgs] call _callback;
};

call FUNC(snapshotPlayers);
{
    private _marker = createVehicle [QGVAR(markerAmmo), _x, [], 0, "CAN_COLLIDE"];
    GVAR(persistenceMarkers) pushBack _marker;
} forEach (values GVAR(disconnectedPlayerPositions));

[{
    params ["_seq", "_barrierArgs", "_partial"];
    _barrierArgs params ["_callback", "_callbackArgs", "_reportDelivering"];
    if (_reportDelivering) then {
        ["shutdown_delivering"] call EFUNC(api,sendEvent);
    };
    [_seq, SAVE_DELIVERY_TIMEOUT, {
        params ["_outcome", "_deliveryArgs"];
        _deliveryArgs params ["_callback", "_callbackArgs", "_partial"];
        if (_partial && {_outcome == "delivered"}) then {
            _outcome = "partial";
        };
        GVAR(missionSaved) = _outcome == "delivered";
        [_outcome, _callbackArgs] call _callback;
    }, [_callback, _callbackArgs, _partial]] call FUNC(waitForDelivery);
}, [_callback, _callbackArgs, _reportDelivering]] call FUNC(shutdownSave);
