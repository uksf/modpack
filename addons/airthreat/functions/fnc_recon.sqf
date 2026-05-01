#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns a recon mission. A drone (80% chance) or unarmed jet (20%)
        flies to observe a random ground player. When it reaches the target
        area, it loiters and then spots a player. Has a 60% chance to trigger
        a follow-up strike mission. Falls back to a CAP mission if no valid
        ground target is found. Server only.

    Parameters:
        None

    Return Value:
        Nothing

    Example:
        call uksf_airthreat_fnc_recon
*/

private _target = [false, true] call FUNC(selectTarget);

if (isNull _target) exitWith {
    DEBUG("No valid recon target in airspace, falling back to CAP");
    call FUNC(cap);
};

private _targetPosition = getPosASL _target;
private _spawnPosition = selectRandom GVAR(spawnPoints);
private _classnames = if (random 1 < 0.8 && {GVAR(reconClassnames) isNotEqualTo []}) then {
    GVAR(reconClassnames)
} else {
    GVAR(fighterClassnames)
};

if (_classnames isEqualTo []) exitWith {
    WARNING("No recon or fighter classnames configured");
};

private _result = [_spawnPosition, _classnames, _targetPosition, 600] call FUNC(spawnAircraft);
_result params ["_group", "_vehicle"];

if (isNull _group) exitWith {};

[_group, _vehicle, "recon"] call FUNC(registerMission);

// Remove ammunition — recon only
_vehicle setVehicleAmmo 0;

// Waypoint to target area, then loiter
private _waypoint = _group addWaypoint [_targetPosition, 200];
_waypoint setWaypointType "MOVE";
_waypoint setWaypointBehaviour "CARELESS";
_waypoint setWaypointCombatMode "BLUE";
_waypoint setWaypointSpeed "NORMAL";

private _loiterWaypoint = _group addWaypoint [_targetPosition, 500];
_loiterWaypoint setWaypointType "LOITER";
_loiterWaypoint setWaypointLoiterRadius 1000;
_loiterWaypoint setWaypointSpeed "LIMITED";

// State machine: approach → loiter → spot → call strike → wait for strike → RTB
// States: "approach", "loiter", "spotted", "strikeActive", "complete"
_vehicle setVariable [QGVAR(reconState), "approach"];
_vehicle setVariable [QGVAR(reconSpotTime), -1];
_vehicle setVariable [QGVAR(reconObservedPosition), _targetPosition];

// On-station timeout starts when entering loiter. Hard backstop at 2× the
// configured timeout from spawn caps total flight time even if the drone
// never reaches the target.
private _hardExpiryTime = time + (GVAR(reconTimeout) * 2);

// Monitoring PFH
[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_targetPosition", "_hardExpiryTime"];

    if (isNull _group || {!alive _vehicle} || {!alive (driver _vehicle)}) exitWith {
        [_group, _vehicle] call FUNC(handleMissionEnd);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if !(local (leader _group)) exitWith {};

    private _state = _vehicle getVariable [QGVAR(reconState), "approach"];

    // Timeouts only fire during approach/loiter — spotted/strikeActive
    // exit via the strike lifecycle. Hard expiry is the absolute ceiling;
    // station expiry is the on-station budget set on entry to loiter.
    if (_state in ["approach", "loiter"]) then {
        private _stationExpiry = _vehicle getVariable [QGVAR(reconStationExpiry), -1];
        if (time > _hardExpiryTime || {_stationExpiry > 0 && {time > _stationExpiry}}) exitWith {
            [_group, _vehicle] call FUNC(addRtbWaypoint);
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
    };

    private _vehiclePosition = getPosASL _vehicle;

    switch (_state) do {
        case "approach": {
            // Check if we've reached the target area
            if ((_vehiclePosition distance _targetPosition) < 1500) then {
                _vehicle setVariable [QGVAR(reconState), "loiter", true];
                _vehicle setVariable [QGVAR(reconSpotTime), time + 30 + random 60];
                _vehicle setVariable [QGVAR(reconStationExpiry), time + GVAR(reconTimeout)];
                DEBUG("Recon entering loiter over target area");
            };
        };
        case "loiter": {
            // Loiter until spot time reached
            private _spotTime = _vehicle getVariable [QGVAR(reconSpotTime), 0];
            if (time >= _spotTime) then {
                // "Spot" a player — store their current position
                private _target = [false] call FUNC(selectTarget);
                if (!isNull _target) then {
                    _vehicle setVariable [QGVAR(reconObservedPosition), getPosASL _target, true];
                };
                _vehicle setVariable [QGVAR(reconState), "spotted", true];

                // 60% chance to trigger follow-up strike
                if (random 1 < 0.6) then {
                    private _observedPosition = _vehicle getVariable [QGVAR(reconObservedPosition), _targetPosition];
                    [QGVAR(reconFollowUp), [_observedPosition, _group, _vehicle]] call CBA_fnc_localEvent;
                } else {
                    // No strike called — RTB
                    _vehicle setVariable [QGVAR(reconState), "complete"];
                    [_group, _vehicle] call FUNC(addRtbWaypoint);
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };
            };
        };
        case "spotted": {
            // Waiting for strike to be dispatched — stay on station
            // State changes to "strikeActive" when server confirms strike spawned
        };
        case "strikeActive": {
            // Stay on station until strike completes — strike sets this to "complete"
        };
        case "complete": {
            [_group, _vehicle] call FUNC(addRtbWaypoint);
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
    };
}, 5, [_group, _vehicle, _targetPosition, _hardExpiryTime]] call CBA_fnc_addPerFrameHandler;

DEBUG("Recon mission spawned");
