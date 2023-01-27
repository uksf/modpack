#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Recreates a group
        Modified version of common,spawnGroup

    Parameters:
        0: uid <STRING>
        1: groupData <ARRAY> [_side, _unitDetailsArray, _waypointsArray, _combatMode]

    Return value:
        Nothing.
*/


#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_uid", "_groupData"];

private _side = _groupData#0;
private _unitDetailsArray = _groupData#1; // [[unit type, [posATL], dir, skill, behaviour, [disabled AI Features], assignedVehicleType, assignedVehicleRole, vehiclePos, engineon, vehicledir], [..........]]
private _waypointsArray = _groupData#2;
private _combatMode = _groupData#3;

private _group = createGroup _side;

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_unitPool", "_time", "_uid", "_unitDetailsArray", "_waypointsArray", "_vehicleCreated"];
    TRACE_1("6) Spawn unit iteration",_args);

    if ((count _unitDetailsArray <= 0) || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_2("6) Spawn unit all spawned or timeout",_unitDetailsArray,time > (_time + TIMEOUT));

        // create waypoints
        [_group, _waypointsArray] call FUNC(addWaypoints);

        // delete the entry from the hashmap
        GVAR(cachedGroupsData) deleteAt _uid;

        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };


// Unit details array
// [
//     [
//         _savedType, unit type, pos, dir, skill, beh, ...
//     ], // infantry
//     [], // infatnry
//     [
//         _savedType, vehicle type, array of all units in the vehicle, veh dir, veh pos, beh, ...
//     ], // vehicle
//     [] // infantry
// ]

//     private _i = _unitDetailsArray#0;
//     _i params ["_savedType"];

//     if (_savedType == SAVED_TYPE_INFANTRY) then {
//         // call FUNC(createInfGroup)
//     };


//     private _j = _unitDetailsArray#2;
//     _j params ["_savedType"];
//     if (_savedType == SAVED_TYPE_VEHICLE) then {
//         // call FUNC(createVeh)
//     };

    private _unitInfo = selectRandom _unitDetailsArray; // [unit type, [posATL], dir, skill, behaviour, [disabled AI Features], assignedVehicleType, assignedVehicleRole, vehiclePos, engineon, vehicledir]

    // creates vehicle if not yet created
    if (_unitInfo#6 isNotEqualTo '') then {
        if !(_vehicleCreated#0) then {
            private _vehicle = createVehicle [_unitInfo#6, [0,0,0], [], 0, "NONE"];
            _vehicle setDir _unitInfo#10;
            _vehicle engineOn _unitInfo#9;
            _vehicle setPos _unitInfo#8;
            _args set [6, [true, _vehicle]]; // passes back vehicle object
        };
        systemChat format ["veh obj: %1", _vehicleCreated#1];
    };

    private _unit = _group createUnit [_unitInfo#0, [0,0,0], [], 5, "NONE"];

    _unit setSkill _unitInfo#3;
    _unit setBehaviour _unitInfo #4;

    {
        _unit disableai _x;
    } forEach _unitInfo#5;

    if (_vehicleCreated#0) then {
        _unit moveInAny _vehicleCreated#1;
    } else {
        _unit setPos _unitInfo#1;
        _unit setDir _unitInfo#2;
    };

    _unitDetailsArray deleteAt (_unitDetailsArray findIf {(_x#0) isKindOf _unitInfo#0});

    // systemChat format ["pos: %1, group: %2, uda count: %3", _unitInfo#1, _group, count _unitDetailsArray];

    TRACE_1("6) Spawn unit created unit",_args);

    _args set [4, _unitDetailsArray];
}, SPAWN_DELAY, [_group, _unitPool, time, _uid, _unitDetailsArray, _waypointsArray, [false, objNull]]] call CBA_fnc_addPerFrameHandler;
