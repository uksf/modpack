#include "script_component.hpp"

if (hasInterface) then {
    call FUNC(addActions);

    ["loadout", {
        if (goggles player == HALOHAHO_MASK && GVAR(systemPFHID) == -1) then {
            DEBUG("Player has halohaho mask, starting system");
            [] call FUNC(initSystem);
        };
    }] call CBA_fnc_addPlayerEventHandler;

    GVAR(ppColour) = ppEffectCreate ["ColorCorrections", 1569];
    GVAR(ppColour) ppEffectEnable true;
    GVAR(ppColour) ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
    GVAR(ppColour) ppEffectCommit 0;
    GVAR(ppBlur) = ppEffectCreate ["RadialBlur", 152];
    GVAR(ppBlur) ppEffectEnable true;
    GVAR(ppBlur) ppEffectAdjust [0, 0, 0, 0];
    GVAR(ppBlur) ppEffectCommit 0;
    GVAR(ppDynamicBlur) = ppEffectCreate ["DynamicBlur", 438];
    GVAR(ppDynamicBlur) ppEffectEnable true;
    GVAR(ppDynamicBlur) ppEffectAdjust [0];
    GVAR(ppDynamicBlur) ppEffectCommit 0;
    GVAR(ppChroma) = ppEffectCreate ["ChromAberration", 274];
    GVAR(ppChroma) ppEffectEnable true;
    GVAR(ppChroma) ppEffectAdjust [0, 0, true];
    GVAR(ppChroma) ppEffectCommit 0;
};
