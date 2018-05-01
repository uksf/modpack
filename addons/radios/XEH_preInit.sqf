#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(presetsDone) = false;

[QEGVAR(lobby,respawned), {
    [] call FUNC(setChannelNames);
}] call CBA_fnc_addEventHandler;

{
    [_x, "init", {
        [_this select 0, channels] call FUNC(addUseAllAction);
    }, true, exclude, true] call CBA_fnc_addClassEventHandler;
    true;
} count ["Car", "Air", "Tank", "Ship_F"];

ADDON = true;
