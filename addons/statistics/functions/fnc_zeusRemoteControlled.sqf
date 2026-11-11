#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        True when this object is a Zeus remote-control puppet, or the curator
        currently remote-controlling one.

        The engine identifies the controller and puppet. The published BIS
        owner variable remains a fallback for puppet detection. UAV operators
        are not treated as Zeus remote controllers.

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
private _controlled = remoteControlled _unit;
if (isNull _controlled) exitWith {false};
if (!isPlayer _unit) exitWith {true};
!unitIsUAV _controlled
