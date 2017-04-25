/*
    Author:
        Kex, edited by Tim Beswick

    Description:
        Initalization function; this function is called when the curator display is loaded for the first time

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        Boolean
*/
#include "script_component.hpp"

params [["_treeControl", controlNull, [controlNull]]];

private _displayReload = false;

// trick to unlock ares/achilles modules for Zeus if mission was not set up properly
if (!("achilles_modules_f_achilles" in (curatorAddons (getAssignedCuratorLogic player)))) then {
    //(createGroup sideLogic) createUnit ["Achilles_Module_Base", [0,0,0], [], 0, "NONE"];
    //(createGroup sideLogic) createUnit ["Ares_Module_Base", [0,0,0], [], 0, "NONE"];
    
    // wait until zeus has truly entered the interface
    waitUntil {!(isNull (findDisplay 312))};
    
    // Wait until Zeus modules are avaiable (e.g. respawns has to be placed before)
    waitUntil {((_tree_ctrl tvText [(_tree_ctrl tvCount []) - 1]) isEqualTo (localize "STR_ZEUS"))};
    
    [[getAssignedCuratorLogic player], {
        waitUntil {!isNil QEGVAR(common,addons)};
        (_this select 0) addCuratorAddons EGVAR(common,addons);
    }] remoteExec ["spawn", 2];
    
    // reload interface
    waitUntil {"achilles_modules_f_achilles" in (curatorAddons (getAssignedCuratorLogic player))};
    cutText ["","BLACK OUT", 0.001,true];
    uiSleep 0.1;
    (findDisplay 312) closeDisplay 0;
    uiSleep 0.1;
    openCuratorInterface;
    cutText ["","BLACK IN", 0.001, true];
    _displayReload = true;
};

//prevent drawing mines
if (!(missionnamespace getvariable ["bis_fnc_drawMinefields_active", false])) then {
    missionnamespace setvariable ["bis_fnc_drawMinefields_active", true, true];
};

// Initialize settings variables
Achilles_var_reloadDisplay = nil; 
Achilles_var_reloadVisionModes = nil;

_displayReload
