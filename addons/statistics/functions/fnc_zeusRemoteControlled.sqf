#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        True when this object is a Zeus remote-control puppet, or the curator
        currently remote-controlling one.

        BIS_fnc_moduleRemoteControl and ZEN both publish
        bis_fnc_moduleRemoteControl_owner on the puppet AI (public variable).
        That is the cross-machine signal. isRemoteControlling covers the curator
        object on the machine where the command works. A curator who is also a
        normal shooter is only excluded while some unit names them as owner.

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
if (isRemoteControlling _unit) exitWith {true};
if (!isPlayer _unit || {isNull getAssignedCuratorLogic _unit}) exitWith {false};

allUnits findIf {
    (_x getVariable ["bis_fnc_moduleRemoteControl_owner", objNull]) isEqualTo _unit
} != -1
