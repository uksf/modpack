#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Devirtualise any groups in radius from position

    Parameter(s):
        0: Position <ARRAY>
        1: Radius <SCALAR>

    Return Value:
        None

    Example:
        call uksf_virtualisation_fnc_devirtualiseNearby
*/

if (!isServer) exitWith {
    [QGVAR(devirtualiseNearby), _this] call CBA_fnc_serverEvent;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_position", "_radius"];

    private _positions = GVAR(groupPositionMap) apply {_x#1};
    private _indices = _positions inAreaArrayIndexes [_position, _radius, _radius, 0, false];
    private _match = _indices findIf {(_positions#_x) distance2D _position < _radius};
    private _groupIndex = if (_match < 0) then {-1} else {_indices#_match};

    if (_groupIndex == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _id = GVAR(groupPositionMap)#_groupIndex#0;
    GVAR(groupPositionMap) deleteAt _groupIndex;

    private _simulatedIndex = GVAR(simulatedGroupIds) findIf {_x == _id};
    if (_simulatedIndex >= 0) then { GVAR(simulatedGroupIds) deleteAt _simulatedIndex };
    GVAR(simPhases) deleteAt _id;

    private _entry = GVAR(groupDataMap) deleteAt _id;
    _entry params ["_side", "_vehicles", "_infantry", "_waypoints", "_combatMode", "_formationDirection",
                   "_simState", "", "", "", "_originalLeaderPos"];

    private _simPosition = _simState#1;
    private _rebaseDelta = [_simPosition#0 - _originalLeaderPos#0, _simPosition#1 - _originalLeaderPos#1, 0];

    private _payload = [_side, _vehicles, _infantry, _waypoints, _combatMode, _formationDirection, _rebaseDelta];
    [QGVAR(recreateGroup), [_payload, true]] call EFUNC(common,headlessEvent);
}, 0.2, _this] call CBA_fnc_addPerFrameHandler;
