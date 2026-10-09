#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends mission_ended once per mission and stops the periodic status
        and performance push. The saved flag is true only when the save
        barrier delivered a save to the API before the mission ended.

    Parameters:
        None

    Return Value:
        None

    Example:
        [] call uksf_api_fnc_sendMissionEnded
*/

if (GVAR(missionEndedSent)) exitWith {};
GVAR(missionEndedSent) = true;

private _saved = missionNamespace getVariable [QEGVAR(persistence,missionSaved), false];
INFO_2("Sending mission_ended for %1, saved: %2",GVAR(sessionId),_saved);
["mission_ended", createHashMapFromArray [
    ["sessionId", GVAR(sessionId)],
    ["map", worldName],
    ["mission", missionName],
    ["duration", time],
    ["saved", _saved]
]] call FUNC(sendEvent);

if (GVAR(statusPerFrameHandler) != -1) then {
    [GVAR(statusPerFrameHandler)] call CBA_fnc_removePerFrameHandler;
    GVAR(statusPerFrameHandler) = -1;
};
if (GVAR(performancePerFrameHandler) != -1) then {
    [GVAR(performancePerFrameHandler)] call CBA_fnc_removePerFrameHandler;
    GVAR(performancePerFrameHandler) = -1;
};
