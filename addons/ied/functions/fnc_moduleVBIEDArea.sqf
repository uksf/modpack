#include "script_component.hpp"
/*
    Author:
        Bridg, Beswick

    Description:
        VBIED area spawning module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_logic"];

if !(isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

private _numberOfVBIEDsToSpawn = _logic getVariable [QGVAR(VBIEDNumber), 0];
private _VBIEDVehiclesParsed = [_logic getVariable [QGVAR(VBIEDVehicleClasses), []]] call EFUNC(common,convertToArray);
private _moduleVBIEDChance = _logic getVariable [QGVAR(VBIEDChance), 0];

if (_VBIEDVehiclesParsed isEqualTo []) exitWith {};

[{
    params ["_args", "_idPFH"];
    _args params ["_numberOfVBIEDsToSpawn", "_logic", "_area", "_VBIEDVehiclesParsed", "_moduleVBIEDChance"];

    if (_numberOfVBIEDsToSpawn < 1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    _area deleteAt 4;
    private _areaArray = [(getPos _logic)] + _area;
    private _position = [_areaArray] call CBA_fnc_randPosArea;
    private _direction = random 360;
    private _road = [_position] call EFUNC(common,findNearRoad);
    if !(isNull _road) then {
        ([_road, 1] call FUNC(getRoadSide)) params ["_roadSide", "_direction"];
        _position = _roadSide;
    };

    private _canCreate = [GVAR(iedExcludeAreas), {[_position, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayNone);
    if (_canCreate) then {
        private _vehicle = createVehicle [selectRandom _VBIEDVehiclesParsed, _position, [], 0, "NONE"];
        _vehicle setDir (_direction + (random 40) - 20);
        [_vehicle] call EFUNC(special,carBomb);

        _vehicle addMPEventHandler ["MPKilled", {
            params ["_vehicle", "_killer", "_instigator"];

            if !(isServer) exitWith {};

            TRACE_3("",_vehicle,_killer,_instigator);
            if (side _killer != west && side _instigator != west) exitWith {};

            [QGVAR(iedDestroyed), _vehicle] call CBA_fnc_serverEvent;
        }];

        _args set [0, _numberOfVBIEDsToSpawn - 1];
    };
}, 1, [_numberOfVBIEDsToSpawn, _logic, _area, _VBIEDVehiclesParsed, _moduleVBIEDChance]] call CBA_fnc_addPerFrameHandler;
