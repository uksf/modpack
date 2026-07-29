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

// In SP / listen-server (isServer && hasInterface), report under BOTH "server" and
// the player's UID so the HUD shows server FPS and the 3D icon shows player FPS.
private _reports = [];
if (isServer) then {
    _reports pushBack ["server", "server"];
};
if (hasInterface) then {
    _reports pushBack [getPlayerUID player, "player"];
};
if (!isServer && !hasInterface) then {
    _reports pushBack [profileName, "hc"];
};

if (!isNil QGVAR(fpsReportingPFH)) then {
    [GVAR(fpsReportingPFH)] call CBA_fnc_removePerFrameHandler;
};

GVAR(fpsReportingPFH) = [{
    params ["_args"];
    _args params ["_reports"];

    private _fps = floor diag_fps;

    {
        _x params ["_identifier", "_type"];
        if (isServer) then {
            [_identifier, _type, _fps] call FUNC(fpsReport);
        } else {
            [QGVAR(fpsReport), [_identifier, _type, _fps]] call CBA_fnc_serverEvent;
        };
    } forEach _reports;
}, 1, [_reports]] call CBA_fnc_addPerFrameHandler;
