/*
    Author:
        Tim Beswick

    Description:
        Checks unit stance and returns contextual animation

    Parameter(s):
        0 : Unit to check <OBJECT>

    Return Value:
        Animation name <STRING>
*/
#include "script_component.hpp"

params ["_unit", "_animation"];

switch (stance _unit) do {
    case ("STAND"): {
        if (currentWeapon _unit != "") then {
            if ((currentWeapon _unit) isKindOf ["Rifle", configFile >> "CfgWeapons"]) then {
                _animation = "amovpercmstpslowwrfldnon";
            };
            if ((currentWeapon _unit) isKindOf ["Pistol", configFile >> "CfgWeapons"]) then {
                _animation = "amovpercmstpslowwpstdnon";
            };
            if ((currentWeapon _unit) isKindOf ["Launcher", configFile >> "CfgWeapons"]) then {
                _animation = "amovpercmstpsraswlnrdnon";
            };
            if ((currentWeapon _unit) isKindOf ["Binocular", configFile >> "CfgWeapons"]) then {
                _animation = "amovpercmstpsoptwbindnon";
            };
        } else {
            _animation = "amovpercmstpsnonwnondnon"
        };
    };
    case ("CROUCH"): {
        if (currentWeapon _unit != "") then {
            if ((currentWeapon _unit) isKindOf ["Rifle", configFile >> "CfgWeapons"]) then {
                _animation = "amovpknlmstpslowwrfldnon";
            };
            if ((currentWeapon _unit) isKindOf ["Pistol", configFile >> "CfgWeapons"]) then {
                _animation = "amovpknlmstpslowwpstdnon";
            };
            if ((currentWeapon _unit) isKindOf ["Launcher", configFile >> "CfgWeapons"]) then {
                _animation = "amovpknlmstpsraswlnrdnon";
            };
            if ((currentWeapon _unit) isKindOf ["Binocular", configFile >> "CfgWeapons"]) then {
                _animation = "amovpknlmstpsoptwbindnon";
            };
        } else {
            _animation = "amovpknlmstpsnonwnondnon"
        };
    };
    case ("PRONE"): {
        if (currentWeapon _unit != "") then {
            if ((currentWeapon _unit) isKindOf ["Rifle", configFile >> "CfgWeapons"]) then {
                _animation = "amovppnemstpsraswrfldnon";
            };
            if ((currentWeapon _unit) isKindOf ["Pistol", configFile >> "CfgWeapons"]) then {
                _animation = "amovppnemstpsraswpstdnon";
            };
            if ((currentWeapon _unit) isKindOf ["Launcher", configFile >> "CfgWeapons"]) then {
                _animation = "amovpercmstpslowwrfldnon";
            };
            if ((currentWeapon _unit) isKindOf ["Binocular", configFile >> "CfgWeapons"]) then {
                _animation = "amovppnemstpsoptwbindnon";
            };
        } else {
            _animation = "amovppnemstpsnonwnondnon"
        };
    };
};

_animation