#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(curatorInitComplete) = false;
GVAR(curatorObjects) = [objNull,objNull,objNull,objNull,objNull];
missionNamespace setVariable [QGVAR(curatorNames), ["","","","",""], true];

GVAR(pingCount) = 0;
GVAR(pingTime) = 0;

ADDON = true;
