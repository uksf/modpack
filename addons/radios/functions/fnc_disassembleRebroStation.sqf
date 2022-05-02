#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Disassembles a rebroadcasting station

    Parameter(s):
        0: Station equipment <OBJECT>

    Return Value:
        None
*/
if (!isServer) exitWith {
    [QGVAR(disassembleRebroStation), _this] call CBA_fnc_serverEvent;
};

TRACE_1("disassemble",_this);

params ["_equipment"];

private _mast = _equipment getVariable [QGVAR(rebroMast), objNull];
private _objects = _equipment getVariable [QGVAR(rebroObjects), [objNull]];

[QGVAR(removeRebroStation), _mast] call CBA_fnc_globalEvent;

{
    [_mast, _x] call acre_api_fnc_removeRackFromVehicle;
} forEach ([_mast] call acre_api_fnc_getVehicleRacks);

private _position = getPosATL _equipment;
private _dir = getDir _equipment;
private _vectorUp = vectorUp _equipment;
_position set [2, 0];

{deleteVehicle _x} forEach _objects;
deleteVehicle _equipment;
deleteVehicle _mast;

private _box = createVehicle [QGVAR(rebroStationBox), [0,0,0], [], 0, "NONE"];
_box setPosATL _position;
_box setDir _dir;
_box setVectorUp _vectorUp;
