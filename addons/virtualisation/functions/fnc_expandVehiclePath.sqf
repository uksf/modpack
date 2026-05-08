#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns async calculatePath agents for each segment. Each segment is
        [_fromPos, _toPos, _segmentType] — "MOVE" splices intermediate path
        points before the matching MOVE waypoint at _toPos, "CYCLE" splices
        before the first CYCLE waypoint.

        calculatePath fires its PathCalculated event handler twice per call
        (engine quirk): first fire delivers the real path, second delivers a
        2-element stub. Defensive pathProcessed flag suppresses the second.

    Parameter(s):
        0: Group id <STRING>
        1: Segments <ARRAY> — each [_fromPos, _toPos, _segmentType]

    Return Value:
        None

    Example:
        [_id, [[posA, posB, "MOVE"], [posB, posA, "CYCLE"]]] call uksf_virtualisation_fnc_expandVehiclePath
*/
params ["_id", "_segments"];

{
    _x params ["_fromPos", "_toPos", "_segmentType"];

    private _agent = calculatePath ["wheeled_APC", "careless", _fromPos, _toPos];
    if (isNull _agent) then {
        [QGVAR(pathExpansionCompleted), [_id, _segmentType, "no_agent", 0]] call CBA_fnc_localEvent;
        continue;
    };

    _agent setVariable [QGVAR(pathTargetId), _id];
    _agent setVariable [QGVAR(pathFromPos), _fromPos];
    _agent setVariable [QGVAR(pathToPos), _toPos];
    _agent setVariable [QGVAR(pathSegmentType), _segmentType];

    _agent addEventHandler ["PathCalculated", {
        params ["_agent", "_path"];

        if (_agent getVariable [QGVAR(pathProcessed), false]) exitWith {};
        _agent setVariable [QGVAR(pathProcessed), true];

        private _id = _agent getVariable [QGVAR(pathTargetId), ""];
        private _fromPos = _agent getVariable [QGVAR(pathFromPos), [0,0,0]];
        private _toPos = _agent getVariable [QGVAR(pathToPos), [0,0,0]];
        private _segmentType = _agent getVariable [QGVAR(pathSegmentType), "MOVE"];

        deleteVehicle _agent;

        if (_id == "") exitWith {};

        private _entry = GVAR(groupDataMap) get _id;
        if (isNil "_entry") exitWith {
            TRACE_1("path EH skipped, group recreated",_id);
            [QGVAR(pathExpansionCompleted), [_id, _segmentType, "skipped_recreated", 0]] call CBA_fnc_localEvent;
        };

        private _fullWaypoints = _entry#8;

        private _toIndex = if (_segmentType == "CYCLE") then {
            _fullWaypoints findIf { (toUpper (_x#1)) == "CYCLE" }
        } else {
            _fullWaypoints findIf {
                ((toUpper (_x#1)) == "MOVE") && {((_x#0) distance _toPos) < 0.5}
            }
        };
        if (_toIndex < 0) exitWith {
            TRACE_2("path EH skipped, target not in waypoints",_id,_toPos);
            [QGVAR(pathExpansionCompleted), [_id, _segmentType, "skipped_no_target", 0]] call CBA_fnc_localEvent;
        };

        private _intermediate = +_path;
        if (count _intermediate > 0 && {((_intermediate#0) distance _fromPos) < 1}) then {
            _intermediate deleteAt 0;
        };
        if (count _intermediate > 0 && {((_intermediate#(count _intermediate - 1)) distance _toPos) < 1}) then {
            _intermediate deleteAt (count _intermediate - 1);
        };

        if (_intermediate isEqualTo []) exitWith {
            TRACE_1("path no intermediate points",_id);
            [QGVAR(pathExpansionCompleted), [_id, _segmentType, "no_intermediate", 0]] call CBA_fnc_localEvent;
        };

        private _newWaypoints = _intermediate apply {
            [_x, "MOVE", "UNCHANGED", "NO CHANGE", "UNCHANGED", "NO CHANGE"]
        };

        _fullWaypoints insert [_toIndex, _newWaypoints];

        TRACE_4("path expanded",_id,_segmentType,_toPos,count _newWaypoints);
        [QGVAR(pathExpansionCompleted), [_id, _segmentType, "spliced", count _newWaypoints]] call CBA_fnc_localEvent;
    }];
} forEach _segments;
