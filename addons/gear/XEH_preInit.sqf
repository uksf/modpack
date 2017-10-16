#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QEGVAR(lobby,respawned), {
    player addEventHandler ["Put", "_this call UK3CB_BAF_Weapons_Static_fnc_player_put_EH"];
	player addEventHandler ["Take", "_this call UK3CB_BAF_Weapons_Static_fnc_player_take_EH"];
}] call CBA_fnc_addEventHandler;

ADDON = true;
