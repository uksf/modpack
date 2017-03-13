/*
    Author:
        esteldunedain from ACE https://github.com/acemod/ACE3, edited by Tim Beswick

    Description:
        Loads settings from mod configs and mission description

    Parameter(s):
        None

    Return Value:
        Nothing
*/
#include "script_component.hpp"

GVAR(settings) = [];

private _fnc_parseConfigForSettings = {
    params ["_config"];

    private _countOptions = count _config;
    for "_index" from 0 to (_countOptions - 1) do {
        private _optionEntry = _config select _index;
        [_optionEntry] call FUNC(setSettingFromConfig);
    };
    if (ace_common_forceAllSettings) then {
        {
            _x set [6, true];
            false
        } count GVAR(settings);
    };
};

[configFile >> "UKSF_Settings"] call _fnc_parseConfigForSettings;
[missionConfigFile >> "UKSF_Settings"] call _fnc_parseConfigForSettings;

{
    publicVariable (_x select 0);
    false
} count GVAR(settings);
