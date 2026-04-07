#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Receives an FPS report from a machine and updates the server-side FPS store.
        Called as a CBA server event handler.

    Parameter(s):
        0: Machine identifier <STRING> - "server", HC profile name, or player UID
        1: Machine type <STRING> - "server", "hc", or "player"
        2: FPS value <NUMBER> - floor diag_fps from the reporting machine

    Return Value:
        None

    Example:
        ["76561198012345678", "player", 42] call uksf_common_fnc_fpsReport
*/
params [["_identifier", "", [""]], ["_type", "", [""]], ["_fps", 0, [0]]];

if (_identifier isEqualTo "" || {_type isEqualTo ""}) exitWith {};

if !(_identifier in GVAR(fpsStore)) then {
    GVAR(fpsStore) set [_identifier, [0, [], _type]];
};
private _entry = GVAR(fpsStore) get _identifier;
_entry set [0, _fps];
(_entry#1) pushBack _fps;
GVAR(fpsStoreTimestamps) set [_identifier, CBA_missionTime];
