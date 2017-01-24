/*
    Author:
        Tim Beswick

    Description:
        Car bomb

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Target side <SIDE>
        1: Deadman <BOOLEAN>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_car", "_side", "_deadman"];

if (local _car) then {    
    _car setVariable ["acex_headless_blacklist", true, true];
    _car setVariable [QGVAR(explode), false];
    _car setVariable [QGVAR(tracking), false];
    _car allowfleeing 0;

    _detectionHandle = [{
        params ["_args", "_idPFH"];
        _args params ["_car", "_side"];

        _nearUnits = nearestObjects [_car, ["CAManBase", "Car", "Motorcycle", "Tank"], 200, true];
        _nearUnits = _nearUnits - [_car];
        {
            if (side _x != _side) then {
                _nearUnits = _nearUnits - [_x];
            };
        } forEach _nearUnits;

        if (count _nearUnits != 0 && !(_car getVariable [QGVAR(tracking), false])) then {
            _target = _nearUnits select 0;    
            _car setVariable [QGVAR(tracking), true];
            (group _car) addWaypoint [position _target, 0];    
            _car setSpeedMode "LIMITED";
            _car setBehaviour "CARELESS";
            [{
                params ["_args", "_idPFH"];
                _args params ["_car", "_target"];

                if ((position _target) distance _car > 210 || !alive _target) exitWith {
                    [{
                        params ["_args", "_idPFH"];
                        _args params ["_car"];
                        if (count (waypoints (group _car)) > 0) then {
                            deleteWaypoint ((waypoints (group _car)) select 0);
                        };
                        if (count (waypoints (group _car)) <= 0) exitWith {
                            [_idPFH] call CBA_fnc_removePerFrameHandler;
                        };
                    }, 0, [_car]] call CBA_fnc_addPerFrameHandler;
                    _car setVariable [QGVAR(tracking), false];
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };

                if ((position _target) distance _car <= 50) exitWith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                    _car setSpeedMode "FULL";                    
                    _driver = driver _car;
                    _driver forceWeaponFire ["CarHorn", "CarHorn"];
                    [{
                        params ["_car", "_driver"];
                        if (alive _driver) exitWith {
                            _driver forceWeaponFire ["CarHorn", "CarHorn"];
                            [_car, QEGVAR(common,suicide)] call CBA_fnc_globalSay3d;
                            [{
                                params ["_car", "_driver"];
                                if (alive _driver) exitWith {
                                    _driver forceWeaponFire ["CarHorn", "CarHorn"];
                                    [{
                                        params ["_car", "_driver"];
                                        if (alive _driver) exitWith {
                                            _car setVariable [QGVAR(explode), true];
                                            _car setDamage 1;
                                        };
                                    }, [_car, _driver], 1] call CBA_fnc_waitAndExecute;
                                };
                            }, [_car, _driver], 1] call CBA_fnc_waitAndExecute;
                        };
                    }, [_car, _driver], 1] call CBA_fnc_waitAndExecute;
                };
            }, 3, [_car, _target]] call CBA_fnc_addPerFrameHandler;
        };    
    }, 5, [_car, _side]] call CBA_fnc_addPerFrameHandler;
    
    [{
        [{
            params ["_args", "_idPFH"];
            _args params ["_car", "_deadman", "_detectionHandle"];
            _driver = driver _car;

            if (!alive _driver) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                [_detectionHandle] call CBA_fnc_removePerFrameHandler;
                if ((_deadman && !isNull _driver) || _car getVariable [QGVAR(explode), false]) then {
                    "R_TBG32V_F" createVehicle (position _car);
                };
            };
        }, 0, _this] call CBA_fnc_addPerFrameHandler;                        
    }, [_car, _deadman, _detectionHandle], 1] call CBA_fnc_waitAndExecute;
};