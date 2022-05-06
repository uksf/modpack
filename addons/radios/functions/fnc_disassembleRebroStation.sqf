#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Disassembles a rebroadcasting station

    Parameter(s):
        0: Station equipment <OBJECT>
        1: Disassembling unit <OBJECT>

    Return Value:
        None
*/
params ["_equipment", "_player"];

private _mast = _equipment getVariable [QGVAR(rebroMast), objNull];
private _objects = _equipment getVariable [QGVAR(rebroObjects), [objNull]];

[QGVAR(deinitialiseRebroStation), [_mast]] call CBA_fnc_serverEvent;

private _position = getPosATL _equipment;
private _dir = getDir _equipment;
private _vectorUp = vectorUp _equipment;
_position set [2, 0];

{deleteVehicle _x} forEach _objects;
deleteVehicle _equipment;
deleteVehicle _mast;

private _box = createVehicle [QGVAR(rebroStationBox), _position, [], 0, "NONE"];
// _box setPosATL _position;
_box setDir _dir;
_box setVectorUp _vectorUp;
