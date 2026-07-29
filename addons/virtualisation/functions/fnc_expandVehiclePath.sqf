#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-segment vehicle path planning. Spawns the actual segment vehicle
        (hidden, sim disabled, damage off), drops a man agent in as driver,
        attaches PathCalculated EH on the agent, then setDestination triggers
        planning. First EH fire stores the path and cleans up agent + vehicle;
        AGENT_TIMEOUT is a fallback if the EH never fires.
        _slot is ["linear", _waypointIndex] or ["cycleReturn"].

    Parameter(s):
        0: Group id <STRING>
        1: Segments <ARRAY> — each [_fromPos, _toPos, _vehicleType, _behaviour, _slot]

    Return Value:
        None

    Example:
        [_id, [[posA, posB, "B_MRAP_01_F", "SAFE", ["linear", 1]]]] call uksf_virtualisation_fnc_expandVehiclePath
*/
#define AGENT_TIMEOUT 30

params ["_id", "_segments"];

{
    _x params ["_fromPos", "_toPos", "_vehicleType", "_behaviour", "_slot"];

    private _vehicle = createVehicle [_vehicleType, _fromPos, [], 0, "NONE"];
    if (isNull _vehicle) then {
        [QGVAR(pathExpansionCompleted), [_id, _slot, "no_vehicle", 0]] call CBA_fnc_localEvent;
        continue;
    };
    _vehicle hideObjectGlobal true;
    _vehicle enableSimulationGlobal false;
    _vehicle allowDamage false;

    private _agent = createAgent ["C_man_1", _fromPos, [], 0, "NONE"];
    if (isNull _agent) then {
        deleteVehicle _vehicle;
        [QGVAR(pathExpansionCompleted), [_id, _slot, "no_agent", 0]] call CBA_fnc_localEvent;
        continue;
    };
    _agent hideObjectGlobal true;
    _agent allowDamage false;
    _agent moveInDriver _vehicle;
    _agent setBehaviour _behaviour;

    _agent setVariable [QGVAR(pathTargetId), _id];
    _agent setVariable [QGVAR(pathFromPos), _fromPos];
    _agent setVariable [QGVAR(pathToPos), _toPos];
    _agent setVariable [QGVAR(pathSlot), _slot];
    _agent setVariable [QGVAR(pathVehicle), _vehicle];

    private _fnc_finish = {
        params ["_agent", "_reason", "_storedCount"];
        if (_agent getVariable [QGVAR(pathComplete), false]) exitWith {};
        _agent setVariable [QGVAR(pathComplete), true];

        private _vehicle = _agent getVariable [QGVAR(pathVehicle), objNull];
        private _id = _agent getVariable [QGVAR(pathTargetId), ""];
        private _slot = _agent getVariable [QGVAR(pathSlot), []];

        deleteVehicle _agent;
        if (!isNull _vehicle) then { deleteVehicle _vehicle };

        TRACE_3("path expansion completed",_id,_slot,_reason);
        [QGVAR(pathExpansionCompleted), [_id, _slot, _reason, _storedCount]] call CBA_fnc_localEvent;
    };

    _agent setVariable [QGVAR(pathFinish), _fnc_finish];

    _agent addEventHandler ["PathCalculated", {
        params ["_agent", "_path"];

        if (_agent getVariable [QGVAR(pathComplete), false]) exitWith {};

        private _id = _agent getVariable [QGVAR(pathTargetId), ""];
        private _fromPos = _agent getVariable [QGVAR(pathFromPos), [0,0,0]];
        private _toPos = _agent getVariable [QGVAR(pathToPos), [0,0,0]];
        private _slot = _agent getVariable [QGVAR(pathSlot), []];

        if (_id == "") exitWith {
            [_agent, "no_id", 0] call (_agent getVariable [QGVAR(pathFinish), {}]);
        };

        private _entry = GVAR(groupDataMap) get _id;
        if (isNil "_entry") exitWith {
            [_agent, "skipped_recreated", 0] call (_agent getVariable [QGVAR(pathFinish), {}]);
        };

        private _intermediate = +_path;
        if (count _intermediate > 0 && {((_intermediate#0) distance _fromPos) < 1}) then {
            _intermediate deleteAt 0;
        };
        if (count _intermediate > 0 && {((_intermediate#(count _intermediate - 1)) distance _toPos) < 1}) then {
            _intermediate deleteAt (count _intermediate - 1);
        };

        switch (_slot#0) do {
            case "linear": {
                private _waypointIndex = _slot#1;
                private _pathLinear = _entry#11;
                if (_waypointIndex >= 0 && {_waypointIndex < count _pathLinear}) then {
                    _pathLinear set [_waypointIndex, _intermediate];
                };
            };
            case "cycleReturn": {
                _entry set [12, _intermediate];
            };
        };

        [_agent, "stored", count _intermediate] call (_agent getVariable [QGVAR(pathFinish), {}]);
    }];

    [{
        params ["_agent"];
        if (_agent getVariable [QGVAR(pathComplete), false]) exitWith {};
        [_agent, "timeout", 0] call (_agent getVariable [QGVAR(pathFinish), {}]);
    }, [_agent], AGENT_TIMEOUT] call CBA_fnc_waitAndExecute;

    _agent setDestination [_toPos, "LEADER PLANNED", true];
} forEach _segments;
