#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets up a pursuit PFH for an intercept group. Chases the target with
        waypoint updates and reveal/doTarget hints, but only forces a missile
        shot when the geometry is realistic (forward cone, valid range) and
        the per-airframe cooldown has elapsed. Server only.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>
        2: Target player <OBJECT>

    Return Value:
        Nothing

    Example:
        [_group, _vehicle, _target] call uksf_airthreat_fnc_interceptPursue
*/
// Engagement envelope — gate AI weapons release on realistic geometry so
// missiles aren't lobbed rear-aspect / out of range.
#define MISSILE_RANGE_MIN 2000
#define MISSILE_RANGE_MAX 12000
// Forward cone (dot product of nose vs target bearing). 0.5 ≈ 60° half-angle.
#define MISSILE_CONE      0.5
// Seconds between forced shots from same airframe (prevents spam).
#define FIRE_COOLDOWN     25

params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]], ["_target", objNull, [objNull]]];

private _expiryTime = time + GVAR(interceptTimeout);

// Cache missile/rocket weapons once — loadout is static per airframe and the
// BIS_fnc_itemType filter is wasted work each tick.
private _missileWeapons = (weapons _vehicle) select {
    toLower ((_x call BIS_fnc_itemType) select 1) in ["missilelauncher", "rocketlauncher"]
};

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_target", "_expiryTime", "_missileWeapons"];

    private _driverUnit = driver _vehicle;
    if (isNull _group || {!alive _vehicle} || {!alive _driverUnit}) exitWith {
        [_group, _vehicle] call FUNC(handleMissionEnd);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if !(local (leader _group)) exitWith {};

    if (time > _expiryTime) exitWith {
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _targetVehicle = vehicle _target;
    if !(alive _target && {!isNull _targetVehicle} && {_targetVehicle isKindOf "Air"}) exitWith {
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Chase: keep waypoint pinned to current target position
    if (waypoints _group isNotEqualTo []) then {
        [_group, 0] setWaypointPosition [getPos _targetVehicle, 100];
    };

    (leader _group) reveal [_targetVehicle, 4];
    _driverUnit doTarget _targetVehicle;

    // Engagement envelope gate — only force a shot when target is in front
    // cone and within plausible missile range. AI handles its own engagement
    // when geometry doesn't qualify.
    private _toTarget = (getPosASL _targetVehicle) vectorDiff (getPosASL _vehicle);
    private _range = vectorMagnitude _toTarget;
    if (_range < MISSILE_RANGE_MIN || _range > MISSILE_RANGE_MAX) exitWith {};

    private _bearing = (vectorNormalized _toTarget) vectorDotProduct (vectorDir _vehicle);
    if (_bearing < MISSILE_CONE) exitWith {};

    // Per-airframe cooldown — don't spam fireAtTarget every tick
    private _lastShot = _vehicle getVariable [QGVAR(lastInterceptShot), -1e6];
    if (time - _lastShot < FIRE_COOLDOWN) exitWith {};

    if (_missileWeapons isEqualTo []) exitWith {};
    _driverUnit fireAtTarget [_targetVehicle, selectRandom _missileWeapons];
    _vehicle setVariable [QGVAR(lastInterceptShot), time];
    TRACE_3("Intercept fire",_range,_bearing,_vehicle);
}, 5, [_group, _vehicle, _target, _expiryTime, _missileWeapons]] call CBA_fnc_addPerFrameHandler;
