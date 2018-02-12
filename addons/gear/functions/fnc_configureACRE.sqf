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

if (hasInterface) then {
    [] spawn {
        waitUntil { !isNull acre_player };

        ["ACRE_PRC343", "default3" ] call acre_api_fnc_setPreset;
        ["ACRE_PRC77", "default3" ] call acre_api_fnc_setPreset;
        ["ACRE_PRC117F", "default3", 10, "name", "RAMC"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 10, "name", "RAMC"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 30, "name", "AIR DISPATCH"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 30, "name", "AIR DISPATCH"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 31, "name", "TOWER"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 31, "name", "TOWER"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 32, "name", "GROUND"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 32, "name", "GROUND"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 33, "name", "WING INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 33, "name", "WING INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 34, "name", "SQN 7 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 34, "name", "SQN 7 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 35, "name", "SQN 656 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 35, "name", "SQN 656 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 36, "name", "SQN 617 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 36, "name", "SQN 617 INTERCOM"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 37, "name", "GROUND 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 37, "name", "GROUND 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 38, "name", "GROUND 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 38, "name", "GROUND 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 39, "name", "GROUND 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 39, "name", "GROUND 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 40, "name", "AIR OPS"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 40, "name", "AIR OPS"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 41, "name", "AIR OPS 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 41, "name", "AIR OPS 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 42, "name", "AIR OPS 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 42, "name", "AIR OPS 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 43, "name", "AIR OPS 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 43, "name", "AIR OPS 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 44, "name", "AIR OPS 4"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 44, "name", "AIR OPS 4"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 45, "name", "AIR OPS 5"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 45, "name", "AIR OPS 5"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 46, "name", "AIR OPS 6"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 46, "name", "AIR OPS 6"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 47, "name", "AIR OPS 7"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 47, "name", "AIR OPS 7"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 48, "name", "AIR OPS 8"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 48, "name", "AIR OPS 8"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 49, "name", "AIR OPS 9"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 49, "name", "AIR OPS 9"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 50, "name", "FORMATION 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 50, "name", "FORMATION 1"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 51, "name", "FORMATION 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 51, "name", "FORMATION 2"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 52, "name", "FORMATION 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 52, "name", "FORMATION 3"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 53, "name", "FORMATION 4"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 53, "name", "FORMATION 4"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3", 54, "name", "FORMATION 5"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC152", "default3", 54, "name", "FORMATION 5"] call acre_api_fnc_setPresetChannelField;
        ["ACRE_PRC117F", "default3"] call acre_api_fnc_setPreset;
        ["ACRE_PRC152", "default3" ] call acre_api_fnc_setPreset;
        ["ACRE_PRC148", "default3" ] call acre_api_fnc_setPreset;
        ["ACRE_PRC77", "default3" ] call acre_api_fnc_setPreset;
    };
};
