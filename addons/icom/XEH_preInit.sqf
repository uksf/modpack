#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(scanInProgress) = false;

private _action = [QGVAR(icomScan),"ICOM Scan","",{[_target] call FUNC(icomScan)}, {([_target, QGVAR(icomScanner)] call ace_common_fnc_hasItem) && !GVAR(scanInProgress)}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;


ADDON = true;
