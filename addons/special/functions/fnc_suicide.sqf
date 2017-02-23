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

params ["_bomber", ["_deadman", false], ["_car", false]];

if (!local _bomber || {_bomber getVariable [QGVAR(isBomber), false]}) exitWith {};

_bomber setVariable ["acex_headless_blacklist", true, true];
_bomber setVariable [QGVAR(isBomber), true, true];
_bomber setVariable [QGVAR(tracking), false, true];
_bomber setVariable [QGVAR(previousTarget), objNull, true];
_bomber allowfleeing 0;
(group _bomber) setBehaviour "CARELESS";
private _man = _bomber;
if (_car) then {
    #define DISTANCE_MOVE 200
    #define DISTANCE_EXPLODE 50
    _man = driver _bomber;
} else {
    #define DISTANCE_MOVE 100
    #define DISTANCE_EXPLODE 25
};
if (_man isKindOf "UKSF_O_TK_INS_SuicideDriver") then {
    removeUniform _man;
    removeVest _man;
    removeHeadgear _man;
    _man addUniform (format ["CUP_O_TKI_Khet_Partug_0%1", floor ((random 8) + 1)]);
    _man addVest (format ["CUP_V_OI_TKI_Jacket%1_0%2", floor ((random 4) + 1), floor ((random 6) + 1)]);
    _man addHeadgear (format ["CUP_H_TKI_Pakol_%1_0%2", floor ((random 2) + 1), floor ((random 6) + 1)]);
};

[{
    params ["_args", "_idPFH"];
    _args params ["_bomber", "_deadman"];

    if ((!alive _bomber && _deadman) || {_bomber getVariable [QGVAR(explode), false]}) then {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [_bomber, [QGVAR(trigger), 50]] remoteExecCall ["say3D", 0];
        [{
            params ["_bomber"];
            "R_TBG32V_F" createVehicle (getPosATL _bomber);
            _bomber setDamage 1;
        }, [_bomber], 0.5] call CBA_fnc_waitAndExecute;
    };

    if (!alive _bomber) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _target = _bomber findNearestEnemy (getPosATL _bomber);
    if (_target != objNull && {_target isKindOf "CAManBase"} && {alive _target} && {(_bomber getVariable [QGVAR(previousTarget), objNull]) != _target} && {(_bomber distance2D _target) < DISTANCE_MOVE}) then {
        _bomber setVariable [QGVAR(previousTarget), _target, true];
        [group _bomber] call CBA_fnc_clearWaypoints;
        [group _bomber, (getPosATL _target), 0, "MOVE", "CARELESS", "BLUE", "LIMITED"] call CBA_fnc_addWaypoint;

        [{
            params ["_args", "_idPFH"];
            _args params ["_bomber", "_target"];

            if (_bomber distance _target <= DISTANCE_EXPLODE && {[objNull, "VIEW"] checkVisibility [eyePos _bomber, eyePos _target] > 0}) exitWith {
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
        }, 1, [_bomber, _target]] call cba_fnc_addPerFrameHandler;
    };
}, 1, [_bomber, _deadman]] call CBA_fnc_addPerFrameHandler;
