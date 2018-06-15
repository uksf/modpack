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
#include "script_component.hpp"

params [["_centre", objnull], ["_skip", false]];

private _vehicles = (GVAR(dataNamespace) getVariable [QGVAR(vehicles), []]);

if (!(isNull _centre)) then {
    private _objects = (_centre nearObjects CENTRE_RADIUS) select {alive _x && {!(_x isKindOf "Man" || _x isKindOf "Logic")}};
    {
        private _object = _x;
        private _id = _object getVariable [QGVAR(persistenceID), ""];
        if (_id == "") then { // No ID, mark as persistent
            _id = [_object] call FUNC(markVehicleAsPersistent);
        };

        if (!_skip) then {
            private _index = _vehicles findIf {_x#0 == _id};
            if (_index > -1) then { // ID exists, update entry in _vehicles
                _vehicles set [_index, [_object] call FUNC(getVehicleData)];
            } else {  // ID not in _vehicles, add
                _vehicles pushBack ([_object] call FUNC(getVehicleData));
            };
        };
    } forEach _objects;
} else {
    // Add/update objects around markers
    {[_x, true] call FUNC(saveVehicleData)} forEach GVAR(persistenceMarkers);

    // Add/update hashed vehicles
    [GVAR(hashPersistentVehicles), {
        private _index = _vehicles findIf {_x#0 == _key};
        if (_index > -1) then { // ID exists, update entry in _vehicles
            _vehicles set [_index, [_value] call FUNC(getVehicleData)];
        } else {  // ID not in _vehicles, add
            _vehicles pushBack ([_value] call FUNC(getVehicleData));
        };
    }] call CBA_fnc_hashEachPair;
};

(GVAR(dataNamespace) setVariable [QGVAR(vehicles), _vehicles]);
profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
