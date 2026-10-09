#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Captures a player's state into the persistence namespace

    Parameter(s):
        0: Unit <OBJECT>
        1: Player UID <STRING>

    Return Value:
        None

    Example:
        [_unit, _uid] call uksf_persistence_fnc_storePlayerData
*/
params ["_unit", "_uid"];

private _loadout = [getUnitLoadout _unit] call EFUNC(radios,sanitiseLoadout);
private _facewear = _unit getVariable [QGVAR(facewear), goggles _unit];
if (_loadout#7 != _facewear) then {
    _loadout set [7, _facewear];
};

private _data = [
    getPosASL _unit,
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
            _role = toLower (_unit call CBA_fnc_vehicleRole);
            _index = _vehicle getCargoIndex _unit;
            if (_role == "turret") then {
                _index = _unit call CBA_fnc_turretPath;
            };
        };
        [_id, _role, _index]
    },
    direction _unit,
    animationState _unit,
    _loadout,
    damage _unit,
    [_unit, false] call ace_medical_fnc_serializeState,
    _unit getVariable ["ACE_hasEarPlugsIn", false],
    (_unit getVariable ["ace_attach_attached", []]) apply {_x#1},
    [_unit] call EFUNC(radios,serializeRadios),
    [_uid] call EFUNC(diving,getPlayerData)
];
TRACE_2("Player data",_uid,_data);

GVAR(dataNamespace) setVariable [_uid, _data];
GVAR(playerUids) pushBackUnique _uid;

if (GVAR(dataSaved)) then {
    GVAR(disconnectedPlayerPositions) set [_uid, getPos _unit];
};
