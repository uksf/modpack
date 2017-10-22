#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(unitGroups) = [];
GVAR(firstRespawn) = false;
[QGVAR(respawned), {[QEGVAR(common,addObjectsToCurators), []] call CBA_fnc_serverEvent}] call CBA_fnc_addEventHandler;
[QEGVAR(curator,finished), {call FUNC(missionLoad)}] call CBA_fnc_addEventHandler;

ADDON = true;
