#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads persistent data from profile namespace.
        After loading completes, triggers an API load for proofing comparison.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_loadServerDataProfile
*/

// Register a one-shot handler that runs after object loading finishes.
// loadServerData is async — objects load over multiple frames via PFH,
// so we must wait before running the API comparison.
GVAR(profileLoadFinishedEHId) = [QGVAR(loadingFinished), {
    [QGVAR(loadingFinished), GVAR(profileLoadFinishedEHId)] call CBA_fnc_removeEventHandler;

    INFO("Object loading complete — triggering API load for proofing comparison");
    GVAR(apiLoadComplete) = false;
    GVAR(apiLoadedSession) = nil;

    private _result = ("uksf" callExtension ["load", [GVAR(key)]]) select 0;
    INFO_1("Proofing extension load triggered: %1",_result);

    if (_result == "" || {toLower (_result select [0, 5]) == "error"}) exitWith {
        ERROR_1("Failed to trigger proofing load: %1",_result);
    };

    [{
        GVAR(apiLoadComplete)
    }, {
        if (isNil QGVAR(apiLoadedSession)) then {
            WARNING("API proofing: no session data received — comparison skipped");
        } else {
            [GVAR(apiLoadedSession)] call FUNC(compareApiSession);
            GVAR(apiLoadedSession) = nil;
        };
    }, [], 60, {
        ERROR("API proofing load timed out after 60 seconds — comparison skipped");
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

call FUNC(loadServerData);
