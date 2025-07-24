#include "script_component.hpp"

[{
    tbd_m119_m119_towingList pushBack [QGVAR(landrover_lightgun.*), [0.11, -2.34, -2.03], -0.10];
}] call CBA_fnc_execNextFrame;

if (hasInterface) exitWith {
    call FUNC(addSwapDriverActions);

    addUserActionEventHandler ["ReloadMagazine", "Activate", FUNC(reloadTurret)];
};
