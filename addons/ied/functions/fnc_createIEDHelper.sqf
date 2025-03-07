#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Create IED helper object to detect destruction or force destruction

    Parameters:
        0: Explosive <OBJECT>

    Return value:
        None
*/
params ["_explosive"];

private _helper = createVehicle [QGVAR(helper), [0, 0, 0], [], 0, "NONE"];
_helper attachTo [_explosive, [0,0,0]];
_helper setVariable [QGVAR(explosive), _explosive, true];

_helper addMPEventHandler ["MPKilled", {
    params ["_helper"];

    if !(isServer) exitWith {};

    private _nearbyEntities = _helper nearEntities [["CAManBase", "Car", "Motorcycle", "Tank"], 20];
    if (_nearbyEntities isEqualTo []) then {
        [QGVAR(iedDestroyed), _helper] call CBA_fnc_serverEvent;
    };

    private _explosive = _helper getVariable [QGVAR(explosive), objNull];
    _explosive setDamage 1;
    deleteVehicle _helper;
}];
