#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(presetsDone) = false;

["CAManBase", "respawn", {
    [] call FUNC(setChannelNames);
}, true, nil, true] call CBA_fnc_addClassEventHandler;

{
    [_x, "init", {
        [_this select 0, channels] call FUNC(addUseAllAction);
    }, true, exclude, true] call CBA_fnc_addClassEventHandler;
    true;
} count ["Car", "Air", "Tank", "Ship_F"];

ADDON = true;
