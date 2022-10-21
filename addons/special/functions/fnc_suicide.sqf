#include "script_component.hpp"
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

_bomber setVariable ["ace_headless_blacklist", true, true];
_bomber setVariable [QGVAR(isBomber), true, true];
_bomber setVariable [QGVAR(previousTarget), objNull, true];
_bomber allowfleeing 0;
_bomber disableAI "AUTOCOMBAT";
_bomber disableAI "COVER";
_bomber disableAI "SUPPRESSION";
_bomber disableAI "FSM";

[{
    params ["_args", "_idPFH"];
    _args params ["_bomber", "_deadman", "_car", "_distance", ["_doCharge", false], ["_doExplode", false]];

    if (_doExplode || {!alive _bomber && _deadman}) then {
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        if (_car) then {
            [_bomber, [[QGVAR(alarm), QGVAR(nokia)] select (random 1 > 0.5), 100]] remoteExecCall ["say3D", 0];
        } else {
            [_bomber, [QGVAR(trigger), 50]] remoteExecCall ["say3D", 0];
        };

        [{
            params ["_bomber", "_car"];

            private _explosion = ["IEDLandBig_Remote_Ammo", "Bo_Mk82"] select (_car);
            private _explosive = createVehicle [_explosion, _bomber, [] , 0, "CAN_COLLIDE"];

            _explosive setDamage 1;
            (vehicle _bomber) setDamage 1;
            _bomber setDamage 1;
        }, [_bomber, _car], 0.5] call CBA_fnc_waitAndExecute;
    };

    if (!alive _bomber) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _target = _bomber findNearestEnemy (getPosATL _bomber);
    if (!_doCharge && {_target != objNull} && {(_target isKindOf "CAManBase") || {(_target isKindOf "LandVehicle")}} && {alive _target} && {(_bomber distance2D _target) < _distance}) then {
        {deleteWaypoint [(group _bomber), 1]} forEach (waypoints (group _bomber));
        private _waypoint = [group _bomber, (getPosATL _target), 0, "MOVE", "CARELESS", "BLUE", "LIMITED"] call CBA_fnc_addWaypoint;
        if (_bomber distance _target <= (_distance / 4) && {[_bomber, "VIEW"] checkVisibility [eyePos _bomber, eyePos _target] > 0}) then {
            _waypoint setWaypointSpeed "FULL";
            [_bomber, [QGVAR(suicide), 150]] remoteExecCall ["say3D", 0];
            _args set [4, true];

            [{
                params ["_bomber", "_args"];

                if (alive _bomber) then {
                    _args set [5, true];
                };
            }, [_bomber, _args], 2.5] call CBA_fnc_waitAndExecute;
        };
    };
}, 1, [_bomber, _deadman, _car, _distance]] call CBA_fnc_addPerFrameHandler;
