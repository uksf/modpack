#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs paradrop procedure from paradrop module

    Parameter(s):
        0: Units to drop <ARRAY>
        1: Start position <ARRAY>
        2: End position <ARRAY>
        3: Drop altitude <SCALAR>

    Return Value:
        None
*/
#define BASE_SPEED 60

params ["_units", "_positionStart", "_positionEnd", ["_altitude", 6000]];

if (!isServer) exitWith {
    [QGVAR(paradrop), _this] call CBA_fnc_serverEvent;
};

_altitude = _altitude / 3.28084; // Convert feet to metres

["Dropping in %1 units", count _units] call ace_zeus_fnc_showMessage;
{
    [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#00CC00'>STANDBY FOR C-130 PICKUP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
} forEach _units;

private _speed = BASE_SPEED + (random 10);
private _vectorDirection = _positionStart vectorFromTo _positionEnd;
private _heading = (_vectorDirection#0 atan2 _vectorDirection#1);
private _start = _positionStart getPos [1500, _heading - 180];
private _end = _positionEnd getPos [1000, _heading];
private _fail = _positionStart getPos [(_positionStart distance2D _positionEnd) / 2, _heading];
_start set [2, _altitude];
_end set [2, _altitude];
_fail set [2, 0.05];

private _plane = createVehicle ["CUP_B_C130J_GB", [0, 0, _altitude], [], 0, "FLY"];
createVehicleCrew _plane;
_plane setVariable ["acex_headless_blacklist", true, true];
_plane setPosASL _start;
_plane setVectorDirAndUp [_vectorDirection, [0, 0, 1]];
_plane setVelocity (_vectorDirection vectorMultiply _speed);
_plane setSpeedMode "LIMITED";
_plane setBehaviour "CARELESS";
_plane doMove _end;
_plane flyInHeightASL [_altitude, _altitude, _altitude];
_plane forceSpeed _speed;

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_units", "_positionStart", "_positionEnd", "_end", "_fail", ["_previousDistanceStart", 99999], ["_previousDistanceEnd", 99999], ["_states", [false, false, false, false, false]]];
    _states params ["_unitsIn", "_positionPreStartReached", "_startReached", "_endReached"];

    private _position = getPosASL _plane;
    if (!(alive _plane) || {(_position distance2D _end) < 50}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        private _remainingUnits = assignedCargo _plane;
        {
            [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FF0000'>FAILED TO JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5], _x] call CBA_fnc_targetEvent;
            _x setPosATL _fail;
        } forEach _remainingUnits;
        {deleteVehicle _x} forEach (crew _plane);
        deleteVehicle _plane;
    };

    if (!_unitsIn && {(_position distance2D _positionStart) < 1000}) then {
        _states set [0, true];
        {
            [{
                [QGVAR(moveInCargo), _this, _this#0] call CBA_fnc_targetEvent;
            }, [_x, _plane], (0.1 * _forEachIndex) + 1] call CBA_fnc_waitAndExecute;
        } forEach _units;
    };

    if (!_positionPreStartReached && {(_position distance2D _positionStart) < 500}) then {
        _positionPreStartReached = true;
        _states set [1, true];
        _plane animate ["ramp_top", 1];
        _plane animate ["ramp_bottom", 0.7];
        {
            [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FFFF00'>STANDBY FOR JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
        } forEach _units;
    };

    if (_positionPreStartReached && !_startReached) then {
        private _distance = _position distance2D _positionStart;
        if (_distance > _previousDistanceStart) then {
            _states set [2, true];
            {
                [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#00CC00'>GREEN LIGHT - JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
            } forEach _units;
        };

        _args set [6, _distance];
    };

    if (_positionPreStartReached && _startReached && !_endReached) then {
        private _distance = _position distance2D _positionEnd;
        if (_distance > _previousDistanceEnd) then {
            _states set [3, true];
            _plane animate ["ramp_top", 0];
            _plane animate ["ramp_bottom", 0];
            private _remainingUnits = assignedCargo _plane;
            {
                [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FF0000'>RED LIGHT - DON'T JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5], _x] call CBA_fnc_targetEvent;
            } forEach _remainingUnits;
        };

        _args set [7, _distance];
    };

    _args set [8, _states];
}, 0, [_plane, _units, _positionStart, _positionEnd, _end, _fail]] call CBA_fnc_addPerFrameHandler;
