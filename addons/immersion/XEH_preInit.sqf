#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(variableHandler) = call CBA_fnc_createNamespace;
GVAR(shockwaveArray) = [];
GVAR(playerFiredForceEHID) = -1;
GVAR(playerFiredRecoilEHID) = -1;

GVAR(ammoConfig) = configFile >> "CfgAmmo";

if (hasInterface) then {
    ["unit", {
        params ["_newPlayer", "_oldPlayer"];

        if (GVAR(playerFiredForceEHID) != -1) then {
            _oldPlayer removeEventHandler ["Fired", GVAR(playerFiredForceEHID)];
        };
        if (GVAR(playerFiredRecoilEHID) != -1) then {
            _oldPlayer removeEventHandler ["Fired", GVAR(playerFiredRecoilEHID)];
        };

        if (GVAR(force)) then {
            GVAR(playerFiredForceEHID) = _newPlayer addEventHandler ["Fired", {call FUNC(firedPlayerForce)}];
        };
        if (GVAR(recoil)) then {
            GVAR(playerFiredRecoilEHID) = _newPlayer addEventHandler ["Fired", {call FUNC(firedPlayerRecoil)}];
        };

        resetCamShake;
    }] call CBA_fnc_addPlayerEventHandler;

    ["zen_curatorDisplayLoaded", {GVAR(zeusOpen) = true;}] call CBA_fnc_addEventHandler;
    ["zen_curatorDisplayUnloaded", {GVAR(zeusOpen) = false;}] call CBA_fnc_addEventHandler;
};

#include "initSettings.sqf"

ADDON = true;
