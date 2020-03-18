#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(variableHandler) = call CBA_fnc_createNamespace;
GVAR(ammoConfig) = configFile >> "CfgAmmo";
GVAR(shockwaveArray) = [];
GVAR(suppressionArray)    = [];
GVAR(suppression_currentUnit) = objNull;
GVAR(suppression_suppressed) = false;
GVAR(suppression_threshold) = 0; // Changing value
GVAR(suppression_lastShotAt) = 0; // The time the player got shot at last time (Just creates the variable)
GVAR(suppression_maxDistance);

if (hasInterface) then {
    ["unit", {
        params ["_newPlayer"];

        GVAR(suppression_suppressed) = false;
        GVAR(suppression_currentUnit) = _newPlayer;

        GVAR(suppression_cc) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
        GVAR(suppression_cc) ppEffectCommit 0;

        GVAR(suppression_blur) ppEffectAdjust [0];
        GVAR(suppression_blur) ppEffectCommit 0;

        GVAR(suppression_rBlur) ppEffectAdjust [0, 0, 0, 0];
        GVAR(suppression_rBlur) ppEffectCommit 0;

        GVAR(suppression_threshold) = 0;
        GVAR(suppression_lastShotAt) = 0;

        GVAR(suppression_impactBlur) ppEffectAdjust [0, 0, 0, 0];
        GVAR(suppression_impactBlur) ppEffectCommit 0;

        GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
        GVAR(suppression_impactCC) ppEffectCommit 0;

        resetCamShake;
    }] call CBA_fnc_addPlayerEventHandler;

    ["zen_curatorDisplayLoaded", {
        GVAR(zeusOpen) = true;

        GVAR(suppression_suppressed) = false;

        GVAR(suppression_cc) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
        GVAR(suppression_cc) ppEffectCommit 0;

        GVAR(suppression_blur) ppEffectAdjust [0];
        GVAR(suppression_blur) ppEffectCommit 0;

        GVAR(suppression_rBlur) ppEffectAdjust [0, 0, 0, 0];
        GVAR(suppression_rBlur) ppEffectCommit 0;

        GVAR(suppression_threshold) = 0;
        GVAR(suppression_lastShotAt) = 0;

        GVAR(suppression_impactBlur) ppEffectAdjust [0, 0, 0, 0];
        GVAR(suppression_impactBlur) ppEffectCommit 0;

        GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
        GVAR(suppression_impactCC) ppEffectCommit 0;

        resetCamShake;
    }] call CBA_fnc_addEventHandler;

    ["zen_curatorDisplayUnloaded", {GVAR(zeusOpen) = false;}] call CBA_fnc_addEventHandler;
};

#include "initSettings.sqf"

ADDON = true;
