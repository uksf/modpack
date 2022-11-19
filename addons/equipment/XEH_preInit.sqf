#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

["CAManBase", "initPost", FUNC(randomizeEquipment)] call CBA_fnc_addClassEventHandler;
