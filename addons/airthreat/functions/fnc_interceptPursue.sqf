#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets up a pursuit PFH for an intercept group. Forces target
        acquisition and weapon fire on the target aircraft. Runs on HC.

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

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_target", "_expiryTime"];

    if (isNull _group || {!alive _vehicle} || {isNull (driver _vehicle)}) exitWith {
        [QGVAR(missionComplete), [_group, _vehicle]] call CBA_fnc_serverEvent;
        [_group, _vehicle] call FUNC(cleanupAircraft);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if !(local (leader _group)) exitWith {};

    if (time > _expiryTime) exitWith {
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Force target acquisition and weapon fire
    private _targetVehicle = vehicle _target;
    if (alive _target && {!isNull _targetVehicle} && {_targetVehicle isKindOf "Air"}) then {
        (leader _group) reveal [_targetVehicle, 4];
        (driver _vehicle) doTarget _targetVehicle;
        (driver _vehicle) doFire _targetVehicle;
    } else {
        // Target lost — RTB
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
}, 5, [_group, _vehicle, _target, _expiryTime]] call CBA_fnc_addPerFrameHandler;
