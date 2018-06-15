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

private _data = [
    getPosASL _unit,
    [_unit] call {
        params ["_unit"];
        private _id = "";
        private _vehicle = vehicle _unit;
        if (_vehicle != _unit) then {
            _id = _vehicle getVariable [QGVAR(persistenceID), ""];
            if (_id == "") then {
                _id = [_vehicle] call FUNC(markVehicleAsPersistent);
            };
            private _role = _unit call CBA_fnc_vehicleRole;
            private _index = _vehicle getCargoIndex _unit;
            if (_role == "turret") then {
                _index = _unit call CBA_fnc_turretPath;
            };
        };
        [_id, _role, _index]
    },
    direction _unit,
    animationState _unit,
    getUnitLoadout _unit,
    damage _unit,
    [_unit] call EFUNC(common,serializeAceMedical),
    (_unit getVariable ["ace_attach_attached", []]) apply {_x#1},
    (([_unit] call acre_sys_core_fnc_getGear) select {_x call acre_sys_radio_fnc_isUniqueRadio}) apply {[_x] call acre_api_fnc_getRadioChannel}
];
TRACE_1("Player disconnect",_data);

GVAR(dataNamespace) setVariable [_uid, _data];
profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
[GVAR(hashFirstKilled), _uid, true] call CBA_fnc_hashSet;
[GVAR(hashFirstRespawn), _uid, true] call CBA_fnc_hashSet;
TRACE_1("Saved data",GVAR(dataNamespace));

[_unit] call FUNC(saveVehicleData);
