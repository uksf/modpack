#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(aircraft) = [];

["Air", "init", {
    GVAR(aircraft) pushBack _this#0;
}, true, nil, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
