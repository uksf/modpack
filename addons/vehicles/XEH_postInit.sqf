#include "script_component.hpp"

[QGVAR(swapDriver), {call FUNC(swapDriverLocal)}] call CBA_fnc_addEventHandler;

if (hasInterface) exitWith {
    call FUNC(addSwapDriverActions);

    // Reload bug in here maybe?
    addUserActionEventHandler ["ReloadMagazine", "Activate", FUNC(reloadTurret)];
};
