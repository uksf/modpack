#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the video feeds that the MPU-5 Feeds page can send to a TOC screen.
        Lists only the helmet cameras and UAVs that cTab itself tracks, so enemy aircraft and cameras never appear.
        Each feed uses the ATAK TOC screen feed format.

    Parameter(s):
        None

    Return Value:
        Feeds of [name, type, net ID, camera index] <ARRAY>

    Example:
        call uksf_ctab_fnc_mpu5Feeds
*/

private _feeds = [];
{
    if (alive _x) then {
        _feeds pushBack [format ["Helmet - %1", name _x], "helmet", netId _x, -1];
    };
} forEach (missionNamespace getVariable ["cTabHcamlist", []]);

{
    if (alive _x) then {
        private _config = configOf _x;
        private _name = getText (_config >> "displayName");
        _feeds pushBack [format ["Camera - %1", _name], "vehicle", netId _x, 0];
        if (getText (_config >> "uavCameraGunnerPos") != "" && {getText (_config >> "uavCameraGunnerDir") != ""}) then {
            _feeds pushBack [format ["TGP - %1", _name], "vehicle", netId _x, 1];
        };
    };
} forEach (missionNamespace getVariable ["cTabUAVlist", []]);

_feeds
