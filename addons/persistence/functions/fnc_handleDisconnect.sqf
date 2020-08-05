#include "script_component.hpp"
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
params ["_unit", "_id", "_uid", "_name"];

TRACE_4("HandleDisconnect",_unit,_id,_uid,_name);

[GVAR(hashHasRedeployed), _uid, false] call CBA_fnc_hashSet;
[GVAR(hashFirstRespawn), _uid, true] call CBA_fnc_hashSet;

private _data = [
    getPosASL _unit,
    /*[_unit] call {
        params ["_unit"];
        private _position = getPosASL _unit;
        private _group = group _unit;
        private _leader = leader _group;
        private _leaderID = -1;
        private _leaderPosition = [];
        private _leaderDirection = -1;
        private _offset = [];
        if (_unit == _leader) then {
            _leader = ((units _group) - [_unit])#0;
        };
        if ((_unit distance2D _leader) < 500) then {
            _leaderID = getPlayerUID _leader;
            _leaderPosition = getPosASL _leader;
            _leaderDirection = getDir _leader;
            _offset = _leader worldToModel _position;
        };
        [_position, _leaderID, _leaderPosition, _leaderDirection, _offset]
    },*/
    [_unit] call {
        params ["_unit"];
        private _id = "";
        private _role = "";
        private _index = -1;
        private _vehicle = vehicle _unit;
        if (_vehicle != _unit) then {
            _id = _vehicle getVariable [QGVAR(persistenceID), ""];
            if (_id == "") then {
                _id = [_vehicle] call FUNC(markObjectAsPersistent);
            };
            _role = _unit call CBA_fnc_vehicleRole;
            _index = _vehicle getCargoIndex _unit;
            if (_role == "turret") then {
                _index = _unit call CBA_fnc_turretPath;
            };
        };
        [_id, _role, _index]
    },
    direction _unit,
    animationState _unit,
    ([getUnitLoadout _unit] call EFUNC(radios,sanitiseLoadout)),
    damage _unit,
    [_unit] call EFUNC(common,serializeAceMedical),
    _unit getVariable ["ACE_hasEarPlugsIn", false],
    (_unit getVariable ["ace_attach_attached", []]) apply {_x#1},
    [_unit] call EFUNC(radios,serializeRadios)
];
TRACE_1("Player disconnect",_data);

GVAR(dataNamespace) setVariable [_uid, _data];
private _dateTime = date;
TRACE_1("Saving date time",_dateTime);
GVAR(dataNamespace) setVariable [QGVAR(dateTime), _dateTime];
GVAR(dataNamespace) setVariable [QGVAR(mapMarkers), GVAR(mapMarkers)];
call FUNC(saveData);

[_unit] call FUNC(saveObjectData);
