/*
    Author:
        Tim Beswick

    Description:
        Configures ACRE radio setup

    Parameters:
        None

    Return value:
        Nothing
*/
#include "script_component.hpp"

[] spawn {
    waitUntil {!(isNull acre_player)};
    
    private _channels = configProperties [configFile >> "CfgChannels", "true", false];    
    {
        private _channel = getArray _x;
        ["ACRE_PRC117F", "default3", _channel select 0, "name", _channel select 1] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", _channel select 0, "name", _channel select 1] call acre_api_fnc_setPresetChannelField;
        true
    } count _channels;

    ["ACRE_PRC117F", "default3"] call acre_api_fnc_setPreset;
    ["ACRE_PRC148", "default3"] call acre_api_fnc_setPreset;
    ["ACRE_PRC152", "default3"] call acre_api_fnc_setPreset;
    ["ACRE_PRC343", "default3"] call acre_api_fnc_setPreset;
    ["ACRE_PRC77", "default3"] call acre_api_fnc_setPreset;

    GVAR(presetsDone) = true;
};
