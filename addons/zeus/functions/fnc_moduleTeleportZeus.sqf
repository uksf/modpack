/*
    Author:
        Tim Beswick

    Description:
        Teleports curator to module position

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\achilles\modules_f_ares\module_header.hpp"

[[player], (position _logic), false, false] call Ares_fnc_TeleportPlayers;

#include "\achilles\modules_f_ares\module_footer.hpp"
