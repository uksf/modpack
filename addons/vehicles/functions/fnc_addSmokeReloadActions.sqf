#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds an ACE interaction to ground vehicles that refills their smoke launchers,
        from outside the vehicle and from inside it.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_vehicles_fnc_addSmokeReloadActions
*/

private _action = [
    QGVAR(reloadSmoke),
    "Reload Smoke Launchers",
    "\A3\ui_f\data\igui\cfg\actions\reload_ca.paa",
    {[_target, true, _player] call FUNC(reloadSmoke)},
    {[_target, false] call FUNC(reloadSmoke)}
] call ace_interact_menu_fnc_createAction;
["LandVehicle", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
["LandVehicle", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
