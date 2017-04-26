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

if (!("achilles_modules_f_achilles" in (curatorAddons (getAssignedCuratorLogic player)))) then {
    waitUntil {!(isNull (findDisplay 312))};
    waitUntil {((_tree_ctrl tvText [(_tree_ctrl tvCount []) - 1]) isEqualTo (localize "STR_ZEUS"))};
    waitUntil {"achilles_modules_f_achilles" in (curatorAddons (getAssignedCuratorLogic player))};
    cutText ["","BLACK OUT", 0.001,true];
    uiSleep 0.1;
    (findDisplay 312) closeDisplay 0;
    uiSleep 0.1;
    openCuratorInterface;
    cutText ["","BLACK IN", 0.001, true];
    _displayReload = true;
};

(getAssignedCuratorLogic player) addCuratorAddons (EGVAR(common,addons) - (curatorAddons (getAssignedCuratorLogic player)));

if (!(missionnamespace getvariable ["bis_fnc_drawMinefields_active", false])) then {
    missionnamespace setvariable ["bis_fnc_drawMinefields_active", true, true];
};

Achilles_var_reloadDisplay = nil; 
Achilles_var_reloadVisionModes = nil;

_displayReload
