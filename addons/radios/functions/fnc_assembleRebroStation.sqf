#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a rebroadcasting station

    Parameter(s):
        0: Station box <OBJECT>
        1: Serialized data <ARRAY> (Optional)

    Return Value:
        None
*/
if (!isServer) exitWith {
    [QGVAR(assembleRebroStation), _this] call CBA_fnc_serverEvent;
};

params [["_box", objNull], ["_data", [[], 0, []]]];
_data params ["_position", "_dir"];

if (!isNull _box) then {
    _position = getPosATL _box;
    _dir = getDir _box;
    deleteVehicle _box;
};

_position set [2, 0];
_vectorUp = surfaceNormal _position;

private _equipment = createVehicle [QGVAR(rebroStationEquipment), [0,0,0], [], 0, "NONE"];
_equipment enableSimulationGlobal false;
_equipment setPosATL _position;
_equipment setDir _dir;
_equipment setVectorUp _vectorUp;

private _lid = createVehicle ["Land_PortableServer_01_cover_black_F", [0,0,0], [], 0, "NONE"];
_lid enableSimulationGlobal false;
_lid setPosATL (_equipment modelToWorld [-0.016449, 0.108398, 0.154459]);
_lid setDir (_dir + 45);
_lid setVectorUp _vectorUp;

private _router = createVehicle ["Land_Router_01_black_F", [0,0,0], [], 0, "NONE"];
_router enableSimulationGlobal false;
_router setPosATL (_equipment modelToWorld [-0.126617, -0.264648, 0.154453]);
_router setDir (_dir - 20);
_router setVectorUp _vectorUp;

private _mast = createVehicle [QGVAR(rebroStationMast), [0,0,0], [], 0, "NONE"];
_mast setPosATL (_equipment modelToWorld [0.217316, 0.00390625, -0.173073]);
_mast setDir (_dir + 180);
_mast setVectorUp _vectorUp;

_mast setVariable [QGVAR(rebroEquipment), _equipment, true];
_equipment setVariable [QGVAR(rebroMast), _mast, true];
_equipment setVariable [QGVAR(rebroObjects), [_lid, _router], true];

_equipment setVariable [QEGVAR(persistence,excluded), true];
_router setVariable [QEGVAR(persistence,excluded), true];
_lid setVariable [QEGVAR(persistence,excluded), true];
_mast setVariable [QEGVAR(persistence,excluded), true];

[{[QGVAR(initialiseRebroStation), _this] call CBA_fnc_serverEvent}, [_mast]] call CBA_fnc_execNextFrame;
