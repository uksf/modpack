#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(correctPilotPylon), {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;
["ace_rearm_loadoutChanged", {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;

["CAManBase", "Put", UK3CB_BAF_Weapons_Static_fnc_player_put_EH] call CBA_fnc_addClassEventHandler;
["CAManBase", "Take", UK3CB_BAF_Weapons_Static_fnc_player_take_EH] call CBA_fnc_addClassEventHandler;

ADDON = true;
