#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        True when this object is a Zeus remote-control puppet, or the curator
        currently remote-controlling one.

        BIS_fnc_moduleRemoteControl and ZEN both publish
        bis_fnc_moduleRemoteControl_owner on the puppet AI (public variable).
        That is the cross-machine signal. isRemoteControlling also reports UAV
        control, so connected UAV operators are excluded only when a unit names
        them as its Zeus owner.

    Parameters:
        0: Unit <OBJECT>

    Return Value:
        Remote-controlled, or the active remote controller <BOOL>

    Example:
        [_unit] call uksf_statistics_fnc_zeusRemoteControlled
*/
params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};
if (!isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull])) exitWith {true};
if (!isPlayer _unit) exitWith {isRemoteControlling _unit};
if (!isRemoteControlling _unit && {isNull getAssignedCuratorLogic _unit}) exitWith {false};

private _ownsPuppet = allUnits findIf {
    (_x getVariable ["bis_fnc_moduleRemoteControl_owner", objNull]) isEqualTo _unit
} != -1;
if (_ownsPuppet) exitWith {true};

private _uav = getConnectedUAV _unit;
if (!isNull _uav && {_unit in UAVControl _uav}) exitWith {false};
isRemoteControlling _unit
