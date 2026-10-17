#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Wrapper for 3CB turret reload function replacement

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit: <OBJECT>

    Return Value:
        Resupply successful <BOOLEAN>

    Example:
        call UK3CB_BAF_Vehicles_Weapons_fnc_resupply_ammo
*/
private _return = call FUNC(3cb_reloadTurret);

_return
