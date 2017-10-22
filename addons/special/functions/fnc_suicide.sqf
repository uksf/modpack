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
    _bomber = driver _bomber;
    _distance = _distance * 2;
};
_bomber setVariable ["acex_headless_blacklist", true, true];
_bomber setVariable [QGVAR(isBomber), true, true];
_bomber setVariable [QGVAR(previousTarget), objNull, true];
_bomber allowfleeing 0;

[{
    params ["_args", "_idPFH"];
    _args params ["_bomber", "_deadman", "_distance"];

    if ((!alive _bomber && _deadman) || {_bomber getVariable [QGVAR(explode), false]}) then {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [_bomber, [QGVAR(trigger), 100]] remoteExecCall ["say3D", 0];
        [{
            params ["_bomber"];
            createVehicle ["R_TBG32V_F", (getPosATL _bomber), [] , 0, "CAN_COLLIDE"];
            (vehicle _bomber) setDamage 1;
        }, [_bomber], 0.5] call CBA_fnc_waitAndExecute;
    };

    if (!alive _bomber) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _target = _bomber findNearestEnemy (getPosATL _bomber);
    if (!(_bomber getVariable [QGVAR(exploding), false]) && {_target != objNull} && {(_target isKindOf "CAManBase") || {(_target isKindOf "LandVehicle")}} && {alive _target} && {(_bomber distance2D _target) < _distance}) then {
        {deleteWaypoint [(group _bomber), 1]; false} count (waypoints (group _bomber));
        private _waypoint = [group _bomber, (getPosATL _target), 0, "MOVE", "CARELESS", "BLUE", "LIMITED"] call CBA_fnc_addWaypoint;
        if (_bomber distance _target <= (_distance / 5) && {[_bomber, "VIEW"] checkVisibility [eyePos _bomber, eyePos _target] > 0}) then {
            _waypoint setWaypointSpeed "FULL";
            _bomber setVariable [QGVAR(exploding), true];
            [_bomber, [QGVAR(suicide), 150]] remoteExecCall ["say3D", 0];
            [{
                params ["_bomber"];
                if (alive _bomber) exitWith {
                    _bomber setVariable [QGVAR(explode), true];
                };
            }, [_bomber], 2.5] call CBA_fnc_waitAndExecute;
        };
    };
}, 1, [_bomber, _deadman, _distance]] call CBA_fnc_addPerFrameHandler;
