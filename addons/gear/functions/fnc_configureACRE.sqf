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

[false, true] call acre_api_fnc_setupMission;
if (hasInterface) then {
    [] spawn {
        waitUntil { !isNull acre_player };

        ["ACRE_PRC117F", "default3", "uksf"] call acre_api_fnc_copyPreset;
        ["ACRE_PRC117F", "uksf", 30, "name", "AIR DISPATCH"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 31, "name", "TOWER"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 32, "name", "GROUND"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 33, "name", "WING INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 34, "name", "SQN 7 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 35, "name", "SQN 656 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 36, "name", "SQN 617 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 37, "name", "GROUND 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 38, "name", "GROUND 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 39, "name", "GROUND 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 40, "name", "AIR OPS"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 41, "name", "AIR OPS 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 42, "name", "AIR OPS 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 43, "name", "AIR OPS 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 44, "name", "AIR OPS 4"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 45, "name", "AIR OPS 5"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 46, "name", "AIR OPS 6"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 47, "name", "AIR OPS 7"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 48, "name", "AIR OPS 8"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 49, "name", "AIR OPS 9"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 50, "name", "FORMATION 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 51, "name", "FORMATION 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 52, "name", "FORMATION 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 53, "name", "FORMATION 4"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf", 54, "name", "FORMATION 5"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "uksf"] call acre_api_fnc_setPreset;

        if (!(isNil QGVAR(arsenalClosed))) then {
            [missionNamespace, "arsenalClosed", GVAR(arsenalClosed)] call BIS_fnc_removeScriptedEventHandler;
        };
        GVAR(arsenalClosed) = [missionNamespace, "arsenalClosed", {
            [] spawn {
                sleep 1;
                switch (typeOf acre_player) do {
                    case "UKSF_B_Pilot_7": {
                        private _radios = call acre_api_fnc_getCurrentRadioList;
                        _radios = _radios select {[_x, "ACRE_PRC117F"] call acre_api_fnc_isKindOf};
                        if (count _radios > 1) then {
                            [_radios select 0, 34] call acre_api_fnc_setRadioChannel;
                            [_radios select 1, 33] call acre_api_fnc_setRadioChannel;
                        } else {
                            if (count _radios > 0) then {
                                [_radios select 0, 33] call acre_api_fnc_setRadioChannel;
                            };
                        };
                    };
                    case "UKSF_B_Pilot_656": {
                        private _radios = call acre_api_fnc_getCurrentRadioList;
                        _radios = _radios select {[_x, "ACRE_PRC117F"] call acre_api_fnc_isKindOf};
                        if (count _radios > 1) then {
                            [_radios select 0, 35] call acre_api_fnc_setRadioChannel;
                            [_radios select 1, 33] call acre_api_fnc_setRadioChannel;
                        } else {
                            if (count _radios > 0) then {
                                [_radios select 0, 33] call acre_api_fnc_setRadioChannel;
                            };
                        };
                    };
                    case "UKSF_B_Pilot_617": {
                        private _radios = call acre_api_fnc_getCurrentRadioList;
                        _radios = _radios select {[_x, "ACRE_PRC117F"] call acre_api_fnc_isKindOf};
                        if (count _radios > 1) then {
                            [_radios select 0, 36] call acre_api_fnc_setRadioChannel;
                            [_radios select 1, 33] call acre_api_fnc_setRadioChannel;
                        } else {
                            if (count _radios > 0) then {
                                [_radios select 0, 33] call acre_api_fnc_setRadioChannel;
                            };
                        };
                    };
                };
            };
        }] call BIS_fnc_addScriptedEventHandler;
    };
};
