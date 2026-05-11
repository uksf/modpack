#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns a CAP (Combat Air Patrol) mission.
        A fighter aircraft spawns and patrols a random airspace zone.
        A PFH monitors for nearby player aircraft — if detected, the CAP
        will attempt to engage. Times out and RTBs after the mission
        duration expires. Server only.

    Parameters:
        None

    Return Value:
        Nothing

    Example:
        call uksf_airthreat_fnc_cap
*/

if (GVAR(airspaces) isEqualTo []) exitWith {
    WARNING("No airspace zones registered for CAP");
};
if (GVAR(fighterClassnames) isEqualTo []) exitWith {
    WARNING("No fighter classnames configured");
};

private _airspace = selectRandom GVAR(airspaces);
_airspace params ["_airspacePosition", "_sizeA", "_sizeB", "_angle", "_isRectangle"];
private _spawnPosition = selectRandom GVAR(spawnPoints);
private _altitude = 800 + random 1200;

private _result = [_spawnPosition, GVAR(fighterClassnames), _airspacePosition, _altitude] call FUNC(spawnAircraft);
_result params ["_group", "_vehicle"];

if (isNull _group) exitWith {};

[_group, _vehicle, "cap"] call FUNC(registerMission);

// Patrol shape follows the airspace zone geometry
if (_isRectangle) then {
    // Four corners inset 10%, CYCLE back to first — traces the rectangle
    private _insetA = _sizeA * 0.9;
    private _insetB = _sizeB * 0.9;
    private _corners = [
        [_insetA, _insetB],
        [_insetA, -_insetB],
        [-_insetA, -_insetB],
        [-_insetA, _insetB]
    ] apply {
        _x params ["_offsetX", "_offsetY"];
        private _distance = sqrt (_offsetX ^ 2 + _offsetY ^ 2);
        private _bearing = (_angle + (_offsetX atan2 _offsetY)) mod 360;
        _airspacePosition getPos [_distance, _bearing]
    };

    {
        private _waypoint = _group addWaypoint [_x, 200];
        _waypoint setWaypointType "MOVE";
        _waypoint setWaypointSpeed "NORMAL";
    } forEach _corners;

    private _cycleWaypoint = _group addWaypoint [_corners select 0, 200];
    _cycleWaypoint setWaypointType "CYCLE";
} else {
    // Circle: 90% of radius. Ellipse: mean of the two axes × 0.9.
    private _radius = if (_sizeA == _sizeB) then {
        _sizeA * 0.9
    } else {
        ((_sizeA + _sizeB) / 2) * 0.9
    };
    private _patrolWaypoint = _group addWaypoint [_airspacePosition, 500];
    _patrolWaypoint setWaypointType "LOITER";
    _patrolWaypoint setWaypointLoiterRadius _radius;
    _patrolWaypoint setWaypointSpeed "NORMAL";
};

private _expiryTime = time + GVAR(capTimeout);

// Monitoring PFH — scans for nearby player aircraft
[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_expiryTime"];

    if (isNull _group || {!alive _vehicle} || {!alive (driver _vehicle)}) exitWith {
        [_group, _vehicle] call FUNC(handleMissionEnd);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if !(local (leader _group)) exitWith {};

    if (time > _expiryTime) exitWith {
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Scan for nearby player aircraft to engage
    private _vehiclePosition = getPosASL _vehicle;
    private _nearestThreat = objNull;
    private _nearestDistance = 8000;

    {
        private _playerVehicle = vehicle _x;
        if (alive _x && {_playerVehicle isKindOf "Air"}) then {
            private _distance = _vehiclePosition distance (getPosASL _playerVehicle);
            if (_distance < _nearestDistance) then {
                _nearestDistance = _distance;
                _nearestThreat = _playerVehicle;
            };
        };
    } forEach ALL_PLAYERS;

    if (!isNull _nearestThreat) then {
        (leader _group) reveal [_nearestThreat, 4];
        (driver _vehicle) doTarget _nearestThreat;
    };
}, 5, [_group, _vehicle, _expiryTime]] call CBA_fnc_addPerFrameHandler;

DEBUG("CAP mission spawned");
