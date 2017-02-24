/*
    Author:
        Tim Beswick

    Description:
        Suicide bomber or car bomber

    Parameter(s):
        0: Unit <OBJECT>
        1: Deadman <BOOLEAN>
        1: Carbomb <BOOLEAN>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

#define DISTANCE_MOVE 100

params ["_bomber", ["_deadman", false], ["_car", false]];

if (!local _bomber || {_bomber getVariable [QGVAR(isBomber), false]}) exitWith {};
if ((_car && {(driver _bomber) isEqualTo objNull}) || (!_car && {_bomber isKindOf "LandVehicle"})) exitWith {
    [{
        params ["_bomber", "_deadman"];
        [vehicle _bomber, _deadman, true] call FUNC(suicide);
    }, [_bomber, _deadman], 1] call CBA_fnc_waitAndExecute;
};

private _distance = DISTANCE_MOVE;
if (_car) then {
    if (_bomber isKindOf "UKSF_O_Skoda_Base") then {
        [_bomber, ["White", 0.25, "Red", 0.25, "Blue", 0.25, "Green", 0.25]] call BIS_fnc_initVehicle;
    };
    _bomber = driver _bomber;
    _distance = _distance * 2;
};
if (_bomber isKindOf "UKSF_O_TK_INS_SuicideDriver") then {
    removeUniform _bomber;
    removeVest _bomber;
    removeHeadgear _bomber;
    _bomber addUniform (format ["CUP_O_TKI_Khet_Partug_0%1", floor ((random 8) + 1)]);
    _bomber addVest (format ["CUP_V_OI_TKI_Jacket%1_0%2", floor ((random 4) + 1), floor ((random 6) + 1)]);
    _bomber addHeadgear (format ["CUP_H_TKI_Pakol_%1_0%2", floor ((random 2) + 1), floor ((random 6) + 1)]);
};
_bomber setVariable ["acex_headless_blacklist", true, true];
_bomber setVariable [QGVAR(isBomber), true, true];
_bomber setVariable [QGVAR(previousTarget), objNull, true];
_bomber allowfleeing 0;
(group _bomber) setBehaviour "CARELESS";

[{
    params ["_args", "_idPFH"];
    _args params ["_bomber", "_deadman", "_distance"];

    if ((!alive _bomber && _deadman) || {_bomber getVariable [QGVAR(explode), false]}) then {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [_bomber, [QGVAR(trigger), 50]] remoteExecCall ["say3D", 0];
        [{
            params ["_bomber"];
            "R_TBG32V_F" createVehicle (getPosATL _bomber);
            (vehicle _bomber) setDamage 1;
        }, [_bomber], 0.5] call CBA_fnc_waitAndExecute;
    };

    if (!alive _bomber) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _target = _bomber findNearestEnemy (getPosATL _bomber);
    if (_target != objNull && {(_target isKindOf "CAManBase") || {(_target isKindOf "LandVehicle")}} && {alive _target} && {(_bomber getVariable [QGVAR(previousTarget), objNull]) != _target} && {(_bomber distance2D _target) < _distance}) then {
        _bomber setVariable [QGVAR(previousTarget), _target, true];
        [group _bomber] call CBA_fnc_clearWaypoints;
        [group _bomber, (getPosATL _target), 0, "MOVE", "CARELESS", "BLUE", "LIMITED"] call CBA_fnc_addWaypoint;

        [{
            params ["_args", "_idPFH"];
            _args params ["_bomber", "_target", "_distance"];

            if (_bomber distance _target <= (_distance / 5) && {[objNull, "VIEW"] checkVisibility [eyePos _bomber, eyePos _target] > 0}) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                _bomber setSpeedMode "FULL";
                [_bomber, [QGVAR(suicide), 50]] remoteExecCall ["say3D", 0];
                [{
                    params ["_bomber"];                        
                    if (alive _bomber) exitWith {                        
                        _bomber setVariable [QGVAR(explode), true];
                    };
                }, [_bomber], 2.5] call CBA_fnc_waitAndExecute;
            };
            if ((_bomber getVariable [QGVAR(previousTarget), objNull]) != _target) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };
        }, 1, [_bomber, _target, _distance]] call cba_fnc_addPerFrameHandler;
    };
}, 1, [_bomber, _deadman, _distance]] call CBA_fnc_addPerFrameHandler;
