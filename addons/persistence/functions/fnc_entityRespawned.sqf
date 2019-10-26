#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles entity respawned

    Parameter(s):
        EntityRespawned params

    Return Value:
        None
*/
params ["_entity", "_corpse"];

TRACE_2("EntityRespawned",_entity,_corpse);

if (!(isPlayer _entity)) exitWith {};

private _uid = getPlayerUID _entity;
private _firstRespawn = [GVAR(hashFirstRespawn), _uid] call CBA_fnc_hashGet;
if (_firstRespawn) then {
    [GVAR(hashFirstRespawn), _uid, false] call CBA_fnc_hashSet;
    [QGVAR(firstRespawn), nil, _entity] call CBA_fnc_targetEvent;
};

deleteVehicle _corpse;
