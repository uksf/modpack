#include "script_component.hpp"

if (hasInterface) then {
    call FUNC(addActions);

    ["loadout", {
        if (goggles player == "G_mas_usl_jumpmask") then {
            [] call FUNC(initSystem);
        };
    }] call CBA_fnc_addPlayerEventHandler;
};
