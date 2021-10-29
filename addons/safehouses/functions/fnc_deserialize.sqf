#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deserializes safehouse data from persistence save

    Parameters:
        0: Serialized safehouse data

    Return value:
        Nothing
*/
params ["_data"];
_data params ["_prefabs", "_destroyed", "_locations"];

if !(isServer) exitWith {};

{
    _x params ["_id"];

    // Prefab IDs in the mission take priority over persistence data
    if !(_id in GVAR(prefabs)) then {
        GVAR(prefabs) set [_id, _x];
    };
} forEach _prefabs;

{
    _x params ["_id", "_position", "_prefabId"];

    private _index = GVAR(locationModules) findIf {_x#0 == _id};
    private _logic = (GVAR(locationModules) deleteAt _index)#1;
    deleteVehicle _logic;

    if (_prefabId in GVAR(prefabs)) then {
        [_id, _position, _prefabId] call FUNC(loadDestroyed);
    } else {
        ERROR_1("Could not find prefab id %1 for destroyed safehouse id %2",_prefabId,_id);
    };
} forEach _destroyed;

{
    _x params ["_id", "_prefabId"];

    private _index = GVAR(locationModules) findIf {_x#0 == _id};
    if (_index != -1) then {
        if (_prefabId in GVAR(prefabs)) then {
            private _location = GVAR(locationModules)#_index;
            _location set [2, _prefabId];
        } else {
            ERROR_2("Could not find prefab id %1 for location id %2, a random prefab will be selected for the location",_prefabId,_id);
        };
    };
} forEach _locations;
