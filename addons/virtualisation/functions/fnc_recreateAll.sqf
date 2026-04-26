#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Recreates all groups
        Admin function, not available unless killswitch is on

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_virtualisation_fnc_recreateAll
*/
if (!GVAR(killswitched)) exitWith {};

INFO("Recreating all virtualised groups");

[{
    params ["", "_idPFH"];

    if (!GVAR(killswitched)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (count GVAR(groupPositionMap) == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(groupDataMap) = createHashMap;
        GVAR(groupPositionMap) = [];
        GVAR(simulatedGroupIds) = [];
    };

    private _id = GVAR(groupPositionMap)#0#0;
    GVAR(groupPositionMap) deleteAt 0;

    private _simulatedIndex = GVAR(simulatedGroupIds) findIf {_x == _id};
    if (_simulatedIndex >= 0) then { GVAR(simulatedGroupIds) deleteAt _simulatedIndex };

    private _entry = GVAR(groupDataMap) deleteAt _id;
    _entry params ["_side", "_vehicles", "_infantry", "_waypoints", "_combatMode", "_formationDirection",
                   "_simState", "", "", "", "_originalLeaderPos"];

    private _simPosition = _simState#1;
    private _rebaseDelta = [_simPosition#0 - _originalLeaderPos#0, _simPosition#1 - _originalLeaderPos#1, 0];

    private _payload = [_side, _vehicles, _infantry, _waypoints, _combatMode, _formationDirection, _rebaseDelta];
    [QGVAR(recreateGroup), [_payload]] call EFUNC(common,headlessEvent);
}, 0.2, []] call CBA_fnc_addPerFrameHandler;
