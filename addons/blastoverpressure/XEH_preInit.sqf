#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(ammoConfigCache) = createHashMap;
GVAR(fortificationClassCache) = createHashMap;

#include "initSettings.inc.sqf"

[QGVAR(processFortifications), {
    _this call FUNC(processFortifications);
}] call CBA_fnc_addEventHandler;

ADDON = true;
