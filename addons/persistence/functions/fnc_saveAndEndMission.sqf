#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves persistence data to the API, then asks clients and headless
        clients to flush their statistics and waits for their reports before
        it ends or restarts the mission. The transition runs whatever the save
        outcome is.

        A repeated request while a transition runs is a no-op. A shutdown
        requested meanwhile takes over before the mission ends or restarts.

    Parameter(s):
        0: Transition, "end" or "restart" <STRING>

    Return Value:
        None

    Example:
        ["restart"] call uksf_persistence_fnc_saveAndEndMission
*/
#define CLIENT_STATISTICS_GRACE 3
#define HANDOVER_TO_SHUTDOWN INFO_1("Mission %1 handing over to the pending shutdown",GVAR(transition)); GVAR(transition) = ""; call FUNC(startShutdown)

params [["_transition", "end", [""]]];

if (!isServer) exitWith {
    [QGVAR(saveAndEndMission), [_transition]] call CBA_fnc_serverEvent;
};

if !(_transition in ["end", "restart"]) exitWith {
    WARNING_1("Unknown mission transition: %1",_transition);
};

if (GVAR(transition) != "") exitWith {
    INFO_2("Mission %1 requested while %2 is in progress, continuing %2",_transition,GVAR(transition));
};

GVAR(transition) = _transition;
INFO_1("Saving before mission %1",_transition);

[{
    params ["_outcome", "_transition"];

    INFO_2("Save before mission %1: %2",_transition,_outcome);
    if (GVAR(shutdownPending)) exitWith {
        HANDOVER_TO_SHUTDOWN;
    };

    [QGVAR(missionTransitionStarted), [_transition]] call CBA_fnc_globalEvent;
    [{
        params ["_transition"];

        if (GVAR(shutdownPending)) exitWith {
            HANDOVER_TO_SHUTDOWN;
        };

        if (_transition == "restart") then {
            if !(SERVER_COMMAND serverCommand "#restart") then {
                ERROR("Server refused #restart, mission continues");
                GVAR(transition) = "";
                if (GVAR(shutdownPending)) then {
                    call FUNC(startShutdown);
                };
            };
        } else {
            [] call BIS_fnc_endMissionServer;
        };
    }, [_transition], CLIENT_STATISTICS_GRACE] call CBA_fnc_waitAndExecute;
}, _transition] call FUNC(saveBarrier);
