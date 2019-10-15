#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves vehicle data

    Parameter(s):
        0: Centre <OBJECT> (Optional)
        1: Skip update <BOOL> (Optional)

    Return Value:
        None
*/

params [["_centre", objnull], ["_skip", false]];

private _vehicles = (GVAR(dataNamespace) getVariable [QGVAR(vehicles), []]);
private _remove = [];
[GVAR(hashPersistentVehicles), {
    if (isNull _value || !(alive _value)) then {
        _remove pushBack _key;
        private _index = _vehicles findIf {_x#0 == _key};
        _vehicles deleteAt _index;
    };
}] call CBA_fnc_hashEachPair;
TRACE_1("Removing",_remove);
{[GVAR(hashPersistentVehicles), _key] call CBA_fnc_hashRem} forEach _remove;

if (!(isNull _centre)) then {
    private _objects = (_centre nearObjects CENTRE_RADIUS) select {alive _x && {!(_x isKindOf "Man" || _x isKindOf "Logic" || _x isKindOf "GroundWeaponHolder" || _x isKindOf "Static")}};
    TRACE_2("Objects around centre",_centre,_objects);
    {
        private _object = _x;
        if (isNull (attachedTo _object)) then {
            private _id = _object getVariable [QGVAR(persistenceID), ""];
            if (_id == "") then {
                _id = [_object] call FUNC(markVehicleAsPersistent);
            };
            TRACE_1("Vehicle ID",_id);
            if (!_skip) then {
                private _index = _vehicles findIf {_x#0 == _id};
                TRACE_1("Exists?",_index);
                if (_index > -1) then {
                    _vehicles set [_index, [_object] call FUNC(getVehicleData)];
                    TRACE_1("Updated",_id);
                } else {
                    _vehicles pushBack ([_object] call FUNC(getVehicleData));
                    TRACE_1("Added",_id);
                };
            };
        };
    } forEach _objects;
} else {
    {if (!(isNull _x)) then {[_x, true] call FUNC(saveVehicleData)};} forEach GVAR(persistenceMarkers);

    [GVAR(hashPersistentVehicles), {
        private _index = _vehicles findIf {_x#0 == _key};
        if (_index > -1) then {
            _vehicles set [_index, [_value] call FUNC(getVehicleData)];
        } else {
            _vehicles pushBack ([_value] call FUNC(getVehicleData));
        };
    }] call CBA_fnc_hashEachPair;
};

//TRACE_1("Vehicles saved",_vehicles);
GVAR(dataNamespace) setVariable [QGVAR(vehicles), _vehicles];
if (GVAR(dataSaved)) then {
    profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
    saveProfileNamespace;
    LOG("Saved data");
};
