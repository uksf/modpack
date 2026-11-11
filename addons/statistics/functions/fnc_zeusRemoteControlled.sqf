#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        True when this object is a Zeus remote-control puppet, or the curator
        currently remote-controlling one.

        The BIS puppet owner and engine controller identify puppets. UAV
        operators are not treated as Zeus remote controllers.

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
if (!isNull (remoteControlled _unit)) exitWith {!unitIsUAV _unit};
if (!isPlayer _unit || {!isRemoteControlling _unit}) exitWith {false};
private _uav = getConnectedUAV _unit;
if (!isNull _uav && {_unit in (UAVControl [_uav, "driver"]) || {_unit in (UAVControl [_uav, "gunner"])}}) exitWith {false};
true
