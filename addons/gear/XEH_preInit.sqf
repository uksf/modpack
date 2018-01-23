#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QEGVAR(lobby,respawned), {
    call FUNC(configureACRE);
}] call CBA_fnc_addEventHandler;

["CAManBase", "Put", UK3CB_BAF_Weapons_Static_fnc_player_put_EH] call CBA_fnc_addClassEventHandler;
["CAManBase", "Take", UK3CB_BAF_Weapons_Static_fnc_player_take_EH] call CBA_fnc_addClassEventHandler;

ADDON = true;
