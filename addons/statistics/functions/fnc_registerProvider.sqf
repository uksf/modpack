#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a statistics provider. Providers are raw event sources
        that capture game events and push them into the event buffer.

    Parameters:
        0: Provider key <STRING>
        1: Setup function <CODE> — called when collection starts, installs event handlers
        2: Locality <STRING> — "client", "server", or "all"

    Return Value:
        None

    Example:
        [_key, _setupFunction, _locality] call uksf_statistics_fnc_registerProvider
*/
params [["_key", "", [""]], ["_setupFunction", {}, [{}]], ["_locality", "client", [""]]];

if (_key isEqualTo "") exitWith {
    ERROR("registerProvider called with empty key");
};

GVAR(providers) set [_key, [_setupFunction, _locality]];
