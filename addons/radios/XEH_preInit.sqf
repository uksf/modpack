#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(presetsDone) = false;
[] call FUNC(setChannelNames);

{
    [_x, "init", {
        [_this select 0, channels] call FUNC(addUseAllAction);
    }, true, nil, true] call CBA_fnc_addClassEventHandler;
    true;
} count ["Car", "Air", "Tank", "Ship_F"];

ADDON = true;
