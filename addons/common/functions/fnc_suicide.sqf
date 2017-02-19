/*
    Author:
        Tim Beswick

    Description:
        Suicide bomber

    Parameter(s):
        0: Unit <OBJECT>
        1: Target side <SIDE>
        1: Deadman <BOOLEAN>
        1: Discrete <BOOLEAN>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_bomber", "_side", "_deadman", "_discrete"];

if (local _bomber) then {
    _bomber setVariable ["acex_headless_blacklist", true, true];
    _bomber setVariable [QGVAR(explode), false];
    _bomber setVariable [QGVAR(tracking), false];
    _bomber allowfleeing 0;

    private _explosives = [];
    if (!_discrete) then {
        _explosive = "DemoCharge_F" createVehicle position _bomber;
        _explosive attachTo [_bomber, [-0.08, 0.08, 0.15], "Pelvis"];
        _explosive setVectorDirAndUp [[0.5, 0.5, 0], [-0.5, 0.5, 0]];
        _explosive setVariable [QGVAR(bomber), _bomber];
        _explosive addEventHandler ["Hit", {_bomber = (_this select 0) getVariable [QGVAR(bomber), objNull]; _bomber setVariable [QGVAR(explode), true]; _bomber setDamage 1;}];
        _explosives pushBack _explosive;
        _explosive = "DemoCharge_F" createVehicle position _bomber;
        _explosive attachTo [_bomber, [0, 0.12, 0.15], "Pelvis"];
        _explosive setVectorDirAndUp [[1, 0, 0], [0, 1, 0]];
        _explosive setVariable [QGVAR(bomber), _bomber];
        _explosive addEventHandler ["Hit", {_bomber = (_this select 0) getVariable [QGVAR(bomber), objNull]; _bomber setVariable [QGVAR(explode), true]; _bomber setDamage 1;}];
        _explosives pushBack _explosive;
        _explosive = "DemoCharge_F" createVehicle position _bomber;
        _explosive attachTo [_bomber, [0.08, 0.08, 0.15], "Pelvis"];
        _explosive setVectorDirAndUp [[0.5, -0.5, 0], [0.5, 0.5, 0]];
        _explosive setVariable [QGVAR(bomber), _bomber];
        _explosive addEventHandler ["Hit", {_bomber = (_this select 0) getVariable [QGVAR(bomber), objNull]; _bomber setVariable [QGVAR(explode), true]; _bomber setDamage 1;}];
        _explosives pushBack _explosive;
    };

    _detectionHandle = [{
        params ["_args", "_idPFH"];
        _args params ["_bomber", "_side"];

        _nearUnits =  nearestObjects [_bomber, ["CAManBase", "Car", "Motorcycle", "Tank"], 100, true];
        _nearUnits = _nearUnits - [_bomber];
        {
            if (!(side _x == _side)) then {
                _nearUnits = _nearUnits - [_x];
            };
        } forEach _nearUnits;

        if (count _nearUnits != 0 && !(_bomber getVariable [QGVAR(tracking), false])) then {
            _target = _nearUnits select 0;
            _bomber setVariable [QGVAR(tracking), true];    
            (group _bomber) addWaypoint [position _target, 0];    
            _bomber setSpeedMode "LIMITED";
            _bomber setBehaviour "CARELESS";
            [{
                params ["_args", "_idPFH"];
                _args params ["_bomber", "_target"];

                if ((position _target) distance _bomber > 110 || !alive _target) exitWith {
                    [{
                        params ["_args", "_idPFH"];
                        _args params ["_bomber"];
                        if (count (waypoints (group _bomber)) > 0) then {
                            deleteWaypoint ((waypoints (group _bomber)) select 0);
                        };
                        if (count (waypoints (group _bomber)) <= 0) exitWith {
                            [_idPFH] call cba_fnc_removePerFrameHandler;
                        };
                    }, 0, [_bomber]] call cba_fnc_addPerFrameHandler;
                    _bomber setVariable [QGVAR(tracking), false];
                    [_idPFH] call cba_fnc_removePerFrameHandler;
                };

                if ((position _target) distance _bomber <= 15) exitWith {
                    [_idPFH] call cba_fnc_removePerFrameHandler;
                    _bomber setSpeedMode "FULL";
                    [_bomber, QEGVAR(common,suicide)] call cba_fnc_globalSay3d;
                    [{
                        params ["_bomber"];                        
                        if (alive _bomber) exitWith {
                            _bomber setVariable [QGVAR(explode), true];
                            _bomber setDamage 1;
                        };
                    }, [_bomber], 2.5] call cba_fnc_waitAndExecute;
                };
            }, 0, [_bomber, _target]] call cba_fnc_addPerFrameHandler;
        };    
    }, 5, [_bomber, _side]] call cba_fnc_addPerFrameHandler;

    [{
        params ["_args", "_idPFH"];
        _args params ["_bomber", "_deadman", "_discrete", "_explosives", "_detectionHandle"];

        if (!alive _bomber) exitWith {
            [_idPFH] call cba_fnc_removePerFrameHandler;
            [_detectionHandle] call cba_fnc_removePerFrameHandler;

            if (_deadman || _bomber getVariable [QGVAR(explode), false]) then {
                "HelicopterExploSmall" createVehicle (position _bomber);
            };
            if (!_discrete) then {
                {deleteVehicle _x} forEach _explosives;
            };
        };
    }, 0, [_bomber, _deadman, _discrete, _explosives, _detectionHandle]] call cba_fnc_addPerFrameHandler;
};