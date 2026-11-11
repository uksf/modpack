#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(setSurrendered), { _this call ACE_captives_fnc_setSurrendered; }] call CBA_fnc_addEventHandler;

ADDON = true;
