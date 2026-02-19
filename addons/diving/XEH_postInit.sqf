#include "script_component.hpp"
#include "initKeybinds.inc.sqf"

["ade_item_bag", QGVAR(bag)] call ace_common_fnc_registerItemReplacement;
["ade_item_rebreather", QGVAR(rebreather)] call ace_common_fnc_registerItemReplacement;
["ade_item_DiveComputer", QGVAR(diveComputer)] call ace_common_fnc_registerItemReplacement;

if (isServer) then {
    [QGVAR(playerDataPublish), {GVAR(playerDataHash) set _this}] call CBA_fnc_addEventHandler;
};

if (hasInterface) then {
    call FUNC(addDiverActions);

    ["loadout", {
        private _hasDiveComputer = QGVAR(diveComputer) in (assignedItems player);
        if (!_hasDiveComputer) then {
            if (GVAR(diveComputerUpdatePFHID) != -1) then {
                [false] call FUNC(toggleDiveComputer);
            };
        };

        private _hasRebreather = (vest player) in [QGVAR(rebreather), "UKSF_LARV_1", "UKSF_LARV_2"];
        if (!_hasRebreather) then {
            if (GVAR(updatePFHID) != -1) then {
                [false] call FUNC(loop);
            };
        } else {
            if (GVAR(updatePFHID) == -1) then {
                [true] call FUNC(loop);
            };
        };
    }] call CBA_fnc_addPlayerEventHandler;
};
