#include "script_component.hpp"

[QGVAR(swapDriver), {call FUNC(swapDriverLocal)}] call CBA_fnc_addEventHandler;

if (hasInterface) exitWith {
    call FUNC(addSwapDriverActions);
    
    addUserActionEventHandler ["ReloadMagazine", "Activate", FUNC(reloadTurret)];
};
