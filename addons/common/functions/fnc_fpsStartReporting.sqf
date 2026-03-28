#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts periodic FPS reporting to the server. Runs on all machines.
        Server writes directly to the store, clients and HCs send via CBA server event.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_common_fnc_fpsStartReporting
*/

private _identifier = if (isServer) then {
    "server"
} else {
    if (hasInterface) then {
        getPlayerUID player
    } else {
        profileName
    };
};

if (!isNil QGVAR(fpsReportingPFH)) then {
    [GVAR(fpsReportingPFH)] call CBA_fnc_removePerFrameHandler;
};

GVAR(fpsReportingPFH) = [{
    params ["_identifier"];

    private _fps = floor diag_fps;

    if (isServer) then {
        [_identifier, _fps] call FUNC(fpsReport);
    } else {
        [QGVAR(fpsReport), [_identifier, _fps]] call CBA_fnc_serverEvent;
    };
}, 1, _identifier] call CBA_fnc_addPerFrameHandler;
