#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves persistence data to the API, then ends or restarts the mission.
        The transition runs whatever the save outcome is.

    Parameter(s):
        0: Transition, "end" or "restart" <STRING>

    Return Value:
        None

    Example:
        ["restart"] call uksf_persistence_fnc_saveAndEndMission
*/
params [["_transition", "end", [""]]];

if (!isServer) exitWith {
    [QGVAR(saveAndEndMission), [_transition]] call CBA_fnc_serverEvent;
};

if !(_transition in ["end", "restart"]) exitWith {
    WARNING_1("Unknown mission transition: %1",_transition);
};

if (GVAR(shutdownInProgress) || GVAR(saveBarrierInProgress)) exitWith {
    WARNING_1("Shutdown or save already in progress, ignoring mission %1",_transition);
};

GVAR(saveBarrierInProgress) = true;
INFO_1("Saving before mission %1",_transition);
[QGVAR(missionTransitionStarted), [_transition]] call CBA_fnc_globalEvent;

[{
    params ["_outcome", "_transition"];

    INFO_2("Save before mission %1: %2",_transition,_outcome);
    if (_transition == "restart") then {
        if !(SERVER_COMMAND serverCommand "#restart") then {
            ERROR("Server refused #restart, mission continues");
            GVAR(saveBarrierInProgress) = false;
        };
    } else {
        [] call BIS_fnc_endMissionServer;
    };
}, _transition] call FUNC(saveBarrier);
