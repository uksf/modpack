/*
    Author:
        Kex, edited by Tim Beswick

    Description:
        Initalization function; this function is called when the curator display is loaded for the first time

    Parameter(s):
        None

    Return Value:
        Boolean
*/
#include "script_component.hpp"

private _displayReload = false;

if (!isMultiplayer) then {
    (getAssignedCuratorLogic player) addCuratorAddons (EGVAR(common,addons) - (curatorAddons (getAssignedCuratorLogic player)));
};

if (!(missionnamespace getvariable ["bis_fnc_drawMinefields_active", false])) then {
    missionnamespace setvariable ["bis_fnc_drawMinefields_active", true, true];
};

Achilles_var_reloadDisplay = nil; 
Achilles_var_reloadVisionModes = nil;

_displayReload
