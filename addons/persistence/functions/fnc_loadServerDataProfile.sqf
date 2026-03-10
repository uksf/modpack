#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads persistent data from profile namespace.
        After loading, optionally triggers an API load for proofing comparison.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_loadServerDataProfile
*/

call FUNC(loadServerData);

if (isNil {EFUNC(api,sendEvent)}) exitWith {
    INFO("API extension not available — proofing comparison skipped");
};

INFO("Profile load complete — triggering API load for proofing comparison");
private _result = "uksf" callExtension ("load:" + GVAR(key));
INFO_1("Proofing extension load triggered: %1",_result);

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
