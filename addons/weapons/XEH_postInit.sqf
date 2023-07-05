#include "script_component.hpp"
#include "initKeybinds.sqf"

if (hasInterface) exitWith {
    addUserActionEventHandler ["ReloadMagazine", "Activate", FUNC(reloadTurret)];
};
