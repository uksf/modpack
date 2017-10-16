/*
    Author:
        Tim Beswick

    Description:
        Deletes corpse

    Parameter(s):
        0: Unit <OBJECT>
        1: Corpse <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_unit", "_corpse"];

private _delay = 30;
if (GVAR(firstRespawn)) then {
    GVAR(firstRespawn) = false;
    _delay = 1;
    [QGVAR(respawned), [_unit]] call CBA_fnc_localEvent;
};
[{deleteVehicle _this}, _corpse, _delay] call CBA_fnc_waitAndExecute;
