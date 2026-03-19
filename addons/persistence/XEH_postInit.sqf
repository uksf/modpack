#include "script_component.hpp"

[{
    if (isServer) then {
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

// Client/HC shutdown handler — show notification and report ready
// Registered in postInit to fire after statistics' preInit shutdownStarted handler
// which flushes client buffers before this ack is sent
if (!isServer) then {
    [QGVAR(shutdownStarted), {
        if (hasInterface) then {
            [QEGVAR(common,textTiles), [parseText "<t align = 'center' color = '#1a7a1a'>Server shutting down</t>", [0.25, 0.5, 0.5, 0.085], [1, 1], 2.5]] call CBA_fnc_localEvent;
        };
        // Short delay to allow clientSync's serverEvent to be transmitted before the ack
        [{
            [QEGVAR(persistence,readyForShutdown), [player]] call CBA_fnc_serverEvent;
        }, [], 0.5] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;
};
