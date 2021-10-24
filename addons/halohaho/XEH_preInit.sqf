#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(oxygenConnected) = false;1

private _action = [QGVAR(linkOxygen),"Link Oxygen","",{[_target] call FUNC(initSystem)}, {goggles _target == "G_mas_usl_jumpmask" && !GVAR(oxygenConnected)}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

["CAManBase", "init", {
    params ["_unit"];


}, true, [], true] call CBA_fnc_addClassEventHandler;

ADDON = true;
