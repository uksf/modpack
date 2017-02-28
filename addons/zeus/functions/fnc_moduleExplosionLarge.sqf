/*
    Author:
        Tim Beswick

    Description:
        Spawns a large explosion on module position

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\achilles\modules_f_ares\module_header.hpp"

private _pos = getPos _logic;
private _ied = "Bo_Mk82" createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 0.1];
_ied setDamage 1;

#include "\achilles\modules_f_ares\module_footer.hpp"
