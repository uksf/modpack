#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Configures ACRE radio setup
        Runs before ACRE gives the player's radios their IDs, so radios held at spawn get the named preset

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_radios_fnc_setChannelNames
*/

private _channels = configProperties [configFile >> "CfgChannels", "true", false];
{
    private _channel = getArray _x;
    ["ACRE_PRC117F", "default3", _channel#0, "name", _channel#1] call acre_api_fnc_setPresetChannelField;
    ["ACRE_PRC152", "default3", _channel#0, "description", _channel#1] call acre_api_fnc_setPresetChannelField;
} forEach _channels;

["ACRE_PRC117F", "default3"] call acre_api_fnc_setPreset;
["ACRE_PRC148", "default3"] call acre_api_fnc_setPreset;
["ACRE_PRC152", "default3"] call acre_api_fnc_setPreset;
["ACRE_PRC343", "default3"] call acre_api_fnc_setPreset;
["ACRE_PRC77", "default3"] call acre_api_fnc_setPreset;
