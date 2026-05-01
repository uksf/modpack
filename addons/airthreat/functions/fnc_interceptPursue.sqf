#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets up a pursuit PFH for an intercept group. Forces target
        acquisition and weapon fire on the target aircraft. Server only.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>
        2: Target player <OBJECT>

    Return Value:
        Nothing

    Example:
        [_group, _vehicle, _target] call uksf_airthreat_fnc_interceptPursue
*/
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
    if (alive _target && {!isNull _targetVehicle} && {_targetVehicle isKindOf "Air"}) then {
        // Chase: keep waypoint pinned to current target position
        if (waypoints _group isNotEqualTo []) then {
            [_group, 0] setWaypointPosition [getPos _targetVehicle, 100];
        };

        (leader _group) reveal [_targetVehicle, 4];
        _driverUnit doTarget _targetVehicle;
        _driverUnit doFire _targetVehicle;

        // Force-fire missiles each tick — doFire alone is unreliable when
        // engagement geometry isn't textbook.
        {
            _driverUnit fireAtTarget [_targetVehicle, _x];
        } forEach _missileWeapons;
    } else {
        // Target lost — RTB
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
}, 5, [_group, _vehicle, _target, _expiryTime, _missileWeapons]] call CBA_fnc_addPerFrameHandler;
