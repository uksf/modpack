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
if (_car isKindOf "UKSF_O_Skoda_Base") then {
    [_car, ["White", 0.25, "Red", 0.25, "Blue", 0.25, "Green", 0.25]] call BIS_fnc_initVehicle;
};
private _side = switch (getNumber (configFile >> "CfgVehicles" >> typeOf _car >> "side")) do {
    case 1: { west };
    case 2: { independent };
    default { east };
};
private _distance = 25 + ((random 10) - 5);

[{
    params ["_args", "_idPFH"];
    _args params ["_car", "_side", "_distance"];

    if (({alive _x && {side _x != civilian} && {((side _x) getFriend (_side)) < 0.6}} count (_car nearEntities [["CAManBase", "LandVehicle"], _distance])) > 0) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
        [_car, [QGVAR(alarm), 200]] remoteExecCall ["say3D", 0];
        [{
            params ["_car"];
            [_car, [QGVAR(trigger), 50]] remoteExecCall ["say3D", 0];
            [{
                params ["_car"];
                private _pos = getPosATL _car;
                "R_TBG32V_F" createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 0.2];
                _car setDamage 1;
            }, [_car], 0.5] call CBA_fnc_waitAndExecute;
        }, [_car], 2.5] call cba_fnc_waitAndExecute;
    };

    if (!alive _car) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };
}, 5, [_car, _side, _distance]] call cba_fnc_addPerFrameHandler;
