#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns a strike/bombing mission. A ground attack jet flies at low
        altitude to the target position and drops ordnance via script.
        After the first pass, it circles back for a second pass before RTB.
        Can be called with an explicit target position (from recon follow-up)
        or will select a ground player target.
        Runs on HC via headlessEvent.

    Parameters:
        0: Target position <ARRAY> - Explicit target position, or empty to use selectTarget (default: [])
        1: Recon vehicle <OBJECT> - Recon aircraft to notify on strike completion (default: objNull)

    Return Value:
        Nothing

    Example:
        [_targetPosition, _reconVehicle] call uksf_airthreat_fnc_strike
*/
params [["_targetPosition", [], [[]]], ["_reconVehicle", objNull, [objNull]]];

if (GVAR(strikeClassnames) isEqualTo []) exitWith {
    WARNING("No strike classnames configured");
};

if (_targetPosition isEqualTo []) then {
    private _target = [false] call FUNC(selectTarget);
    if (isNull _target) exitWith {};
    _targetPosition = getPosASL _target;
};

if (_targetPosition isEqualTo []) exitWith {};

private _spawnPosition = selectRandom GVAR(spawnPoints);

private _result = [_spawnPosition, GVAR(strikeClassnames), _targetPosition, 500] call FUNC(spawnAircraft);
_result params ["_group", "_vehicle"];

if (isNull _group) exitWith {};

[_group, _vehicle, "strike"] call FUNC(registerMission);

// Store strike target on vehicle for waypoint statement to read
_vehicle setVariable [QGVAR(strikeTarget), _targetPosition];

// First pass waypoint — fire weapons on arrival via laser target
private _waypoint1 = _group addWaypoint [_targetPosition, 50];
_waypoint1 setWaypointType "MOVE";
_waypoint1 setWaypointBehaviour "CARELESS";
_waypoint1 setWaypointCombatMode "BLUE";
_waypoint1 setWaypointSpeed "FULL";
_waypoint1 setWaypointStatements [
    "true",
    format ["[vehicle this, (vehicle this) getVariable ['%1', [0,0,0]]] call %2;", QGVAR(strikeTarget), QFUNC(executeStrikeRun)]
];

// Second pass — circle back and strike again
private _secondPassPosition = _targetPosition vectorAdd [500 - random 1000, 500 - random 1000, 0];
private _waypoint2 = _group addWaypoint [_secondPassPosition, 200];
_waypoint2 setWaypointType "MOVE";
_waypoint2 setWaypointBehaviour "CARELESS";
_waypoint2 setWaypointSpeed "NORMAL";

private _waypoint3 = _group addWaypoint [_targetPosition, 50];
_waypoint3 setWaypointType "MOVE";
_waypoint3 setWaypointBehaviour "CARELESS";
_waypoint3 setWaypointSpeed "FULL";
_waypoint3 setWaypointStatements [
    "true",
    format ["[vehicle this, (vehicle this) getVariable ['%1', [0,0,0]]] call %2;", QGVAR(strikeTarget), QFUNC(executeStrikeRun)]
];

// RTB after second pass
[_group, _vehicle] call FUNC(addRtbWaypoint);

// Safety timeout PFH — also notifies recon aircraft on completion
private _expiryTime = time + 600;

[{
    _thisArgs params ["_group", "_vehicle", "_expiryTime", "_reconVehicle"];

    private _strikeComplete = {
        [QGVAR(missionComplete), [_group, _vehicle]] call CBA_fnc_serverEvent;
        [_group, _vehicle] call FUNC(cleanupAircraft);
        [_thisHandle] call CBA_fnc_removePerFrameHandler;
        // Notify recon aircraft that strike is done
        if (!isNull _reconVehicle && {alive _reconVehicle}) then {
            _reconVehicle setVariable [QGVAR(reconState), "complete", true];
        };
    };

    if (isNull _group || {!alive _vehicle} || {isNull (driver _vehicle)}) exitWith {
        call _strikeComplete;
    };

    if !(local (leader _group)) exitWith {};

    if (time > _expiryTime) exitWith {
        call _strikeComplete;
    };
}, 30, [_group, _vehicle, _expiryTime, _reconVehicle]] call CBA_fnc_addPerFrameHandler;

INFO("Strike mission spawned");
