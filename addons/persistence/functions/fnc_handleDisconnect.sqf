/*
    Author:
        Tim Beswick

    Description:
        Handles client disconnect on server

    Parameter(s):
        HandleDisconnect params

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_unit", "_id", "_uid", "_name"];

TRACE_4("HandleDisconnect",_unit,_id,_uid,_name);

// player vehicle
// player radio channels
private _data = [
    getPosASL _unit,
    direction _unit,
    animationState _unit,
    getUnitLoadout _unit,
    damage _unit,
    [_unit] call EFUNC(common,serializeAceMedical),
    _attachToVehicle getVariable [QGVAR(attached), []]
];
[_unit] call FUNC(saveVehicleData);
TRACE_1("Player disconnect",_data);
GVAR(dataNamespace) setVariable [_uid, _data];
profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
[GVAR(hashFirstKilled), _uid, true] call CBA_fnc_hashSet;
[GVAR(hashFirstRespawn), _uid, true] call CBA_fnc_hashSet;
