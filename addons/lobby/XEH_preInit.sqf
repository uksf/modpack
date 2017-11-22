#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(unitGroups) = [];
GVAR(firstRespawn) = true;
[QGVAR(respawned), {[QEGVAR(common,addObjectsToCurators), []] call CBA_fnc_serverEvent}] call CBA_fnc_addEventHandler;

ADDON = true;
