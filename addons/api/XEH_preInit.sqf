#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

ADDON = true;

if (isServer) then {
    call FUNC(initMission);

    // Send mission_ended and stop status push during controlled shutdown
    // MPEnded does not fire reliably during #shutdown — the process is killed
    [QEGVAR(persistence,shutdownFinishing), {
        TRACE_1("Controlled shutdown: sending mission_ended",GVAR(sessionId));
        ["mission_ended", createHashMapFromArray [
            ["sessionId", GVAR(sessionId)],
            ["map", worldName],
            ["mission", missionName],
            ["duration", time]
        ]] call FUNC(sendEvent);

        if (GVAR(statusPerFrameHandler) != -1) then {
            [GVAR(statusPerFrameHandler)] call CBA_fnc_removePerFrameHandler;
            GVAR(statusPerFrameHandler) = -1;
        };
        if (GVAR(performancePerFrameHandler) != -1) then {
            [GVAR(performancePerFrameHandler)] call CBA_fnc_removePerFrameHandler;
            GVAR(performancePerFrameHandler) = -1;
        };
    }] call CBA_fnc_addEventHandler;
};
