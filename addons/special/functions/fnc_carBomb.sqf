/*
    Author:
        Tim Beswick

    Description:
        Empty car bomb

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_car"];

if (!local _car || {_car getVariable [QGVAR(isBomber), false]}) exitWith {};

_car setVariable [QGVAR(isBomber), true, true];
if ((driver _car) != objNull) then {
    _car deleteVehicleCrew (driver _car);
};
private _distance = 25 + ((random 10) - 5);

[{
    params ["_args", "_idPFH"];
    _args params ["_car", "_distance"];

    if (({alive _x && {side _x != civilian} && {((side _x) getFriend (side _car)) < 0.6}} count (_car nearEntities [["CAManBase", "Car", "Motorcycle", "Tank"], _distance])) > 0) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
        [_car, [QGVAR(alarm), 200]] remoteExecCall ["say3D", 0];
        [{
            [_car, [QGVAR(trigger), 50]] remoteExecCall ["say3D", 0];
            [{
                params ["_car"];
                _pos = getPosATL _car;
                "R_TBG32V_F" createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 0.2];
                _car setDamage 1;
            }, [_car], 0.5] call CBA_fnc_waitAndExecute;
        }, [_car], 2.5] call cba_fnc_waitAndExecute;
    };    
}, 5, [_car, _distance]] call cba_fnc_addPerFrameHandler;
