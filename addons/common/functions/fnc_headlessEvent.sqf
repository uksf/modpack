#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Selects a random headless client as remove event target
        If no headless clients, uses server as target

    Parameter(s):
        0: Event name <STRING>
        1: Event parameters <ANY>

    Return Value:
        None

    Example:
        [_eventName, _params] call uksf_common_fnc_headlessEvent
*/
params [["_eventName", "", [""]], ["_params", []]];

if (ace_headless_headlessClients isEqualTo []) exitWith {
    [_eventName, _params] call CBA_fnc_serverEvent;
};

[_eventName, _params, selectRandom ace_headless_headlessClients] call CBA_fnc_targetEvent;
