#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles a visualisation on or off. Updates local state and notifies server.
        Some toggle keys map to multiple provider keys (e.g. "aicommander" toggles both ground and air).

    Parameter(s):
        0: Key <STRING> - visualisation toggle key

    Return Value:
        None
*/
params ["_key"];
TRACE_1("visualiseToggle",_key);

private _current = GVAR(visualiseActiveToggles) getOrDefault [_key, false];
private _newState = !_current;
GVAR(visualiseActiveToggles) set [_key, _newState];
DEBUG_2("visualiseToggle: key=%1 newState=%2",_key,_newState);

// Map toggle keys to provider keys
private _providerKeys = switch (_key) do {
    case "aicommander": { ["aicommander_ground", "aicommander_air"] };
    case "rebronetwork": { ["rebroconnections", "rebronetwork"] };
    default { [_key] };
};

{
    [QGVAR(visualiseStreamToggle), [player, _x, _newState]] call CBA_fnc_serverEvent;
} forEach _providerKeys;
