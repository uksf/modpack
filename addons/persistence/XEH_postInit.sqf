#include "script_component.hpp"

[{
    if (isServer) then {
        // DIAGNOSTIC: find rogue Object in waitUntilAndExecArray
        [{
            private _array = missionNamespace getVariable ["cba_common_waitUntilAndExecArray", []];
            {
                if !(_x isEqualType []) then {
                    diag_log format ["[UKSF] WUAE DIAGNOSTIC: index %1 is type %2, value: %3", _forEachIndex, typeName _x, _x];
                };
            } forEach _array;
            diag_log format ["[UKSF] WUAE DIAGNOSTIC: array count %1, contents: %2", count _array, _array];
        }, [], 2] call CBA_fnc_waitAndExecute;

        if (GVAR(dataSaved)) then {
            // Load objects immediately — don't block on API comparison
            call FUNC(loadServerData);

            // Run API comparison asynchronously against the snapshot
            [{
                GVAR(apiLoadComplete)
            }, {
                if (isNil QGVAR(apiLoadedSession)) then {
                    WARNING("API proofing: no session data received — comparison skipped");
                } else {
                    [GVAR(apiLoadedSession), GVAR(profileSnapshot)] call FUNC(compareApiSession);
                    GVAR(apiLoadedSession) = nil;
                };
                GVAR(profileSnapshot) = nil;
            }, [], 60, {
                ERROR("API proofing load timed out after 60 seconds — comparison skipped");
                GVAR(profileSnapshot) = nil;
            }] call CBA_fnc_waitUntilAndExecute;
        } else {
            INFO("No data saved, loading finished");
            [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
        };
    };

    if (hasInterface) then {
        call FUNC(addPersistenceActions);

        LOG("Requesting player redeploy data");
        [QGVAR(requestRedeployData), [player]] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_execNextFrame;
