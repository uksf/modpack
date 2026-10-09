#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Polls the extension every 0.5 s for the delivery outcome of an
        acknowledged event without blocking the game thread, then calls
        the callback with [outcome, callback arguments]

    Parameter(s):
        0: Delivery sequence number <NUMBER>
        1: Poll timeout in seconds <NUMBER>
        2: Callback <CODE>
        3: Callback arguments <ANY>

    Return Value:
        None

    Example:
        [_seq, 130, {params ["_outcome", "_args"]}, []] call uksf_persistence_fnc_waitForDelivery
*/
params ["_seq", "_timeout", "_callback", ["_callbackArgs", []]];

if (_seq <= 0) exitWith {
    ["unsent", _callbackArgs] call _callback;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_seq", "_deadline", "_callback", "_callbackArgs"];

    private _outcome = ("uksf" callExtension ["delivered", [_seq toFixed 0]])#0;
    if (_outcome == "pending" && {diag_tickTime < _deadline}) exitWith {};
    if (_outcome == "pending") then {
        _outcome = "timeout";
    };

    [_idPFH] call CBA_fnc_removePerFrameHandler;
    INFO_2("Delivery outcome for event %1: %2",_seq,_outcome);
    [_outcome, _callbackArgs] call _callback;
}, 0.5, [_seq, diag_tickTime + _timeout, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
