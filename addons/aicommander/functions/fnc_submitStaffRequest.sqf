#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Handles staff requests sent via CBA event.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_request", createHashMap, [createHashMap]],
    ["_forceIgnoreCooldown", false, [false]]
];

if (!isServer) exitWith {
    [QGVAR(staffRequest), [_commander, _request, _forceIgnoreCooldown]] call CBA_fnc_serverEvent;
    [false, createHashMap, "forwarded_to_server"]
};

if (isNull _commander) then {
    _commander = GVAR(commanders) param [0, objNull];
};
if (isNull _commander) exitWith {[false, createHashMap, "no_commander"]};
if !(_request isEqualType createHashMap) exitWith {[false, createHashMap, "bad_request_type"]};

private _type = toLower (_request getOrDefault ["type", ""]);
switch (_type) do {
    case "air_strike": {
        [_commander, _request, _forceIgnoreCooldown] call FUNC(requestAirStrike)
    };
    case "patrol_task": {
        private _queue = _commander getVariable [QGVAR(patrolTaskRequests), []];
        _queue pushBack _request;
        _commander setVariable [QGVAR(patrolTaskRequests), _queue];
        [true, _request, "queued"]
    };
    default {
        [false, _request, "unsupported_type"]
    };
};
