#include "script_component.hpp"

if (hasInterface) exitWith {
    call FUNC(addSwapDriverActions);

    addUserActionEventHandler ["ReloadMagazine", "Activate", FUNC(reloadTurret)];
};
