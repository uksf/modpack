#include "script_component.hpp"

if (hasInterface) then {
    ["loadout", {
        private _hasMask = (goggles player) == "G_mas_usl_jumpmask";
        if (_hasMask) then {
            [player, goggles player] call ace_goggles_fnc_applyGlassesEffect;
			[player] call FUNC(initSystem);
		};
    }] call CBA_fnc_addPlayerEventHandler;
};
