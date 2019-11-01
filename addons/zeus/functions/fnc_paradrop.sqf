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
    [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' color = '#00CC00'>STANDBY FOR PICKUP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
} forEach _units;

private _vectorDirection = _positionStart vectorFromTo _positionEnd;
private _heading = (_vectorDirection#0 atan2 _vectorDirection#1);
private _start = _positionStart getPos [1500, _heading - 180];
private _end = _positionEnd getPos [1000, _heading];
_start set [2, _altitude];
_end set [2, _altitude];
private _distanceToTravel = vectorMagnitude (_start vectorDiff _end);
private _timeToTake = _distanceToTravel / (BASE_SPEED + (random 10));
private _frameStep = _distanceToTravel / (_timeToTake * diag_fps);

private _plane = createVehicle ["CUP_B_C130J_GB", [0, 0, _altitude], [], 0, "NONE"];
_plane engineOn true;
_plane setDir _heading;
_plane setVectorDirAndUp [_vectorDirection, [0,0,1]];
_plane setPosASL _start;

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_units", "_start", "_end", "_vectorDirection", "_frameStep", "_positionStart", "_positionEnd", "_previousPosition", "_startReached", "_endReached"];

    if (!(alive _plane) || {(_previousPosition distance2D _end) < 25}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        deleteVehicle _plane;
    };

    private _unitsIn = _plane getVariable [QGVAR(unitsIn), false];
    if (!_unitsIn && {(_previousPosition distance2D _positionStart) < 1000}) then {
        _plane setVariable [QGVAR(unitsIn), true, true];
        {
            [{
                [QGVAR(moveInCargo), _this, _this#0] call CBA_fnc_targetEvent;
            }, [_x, _plane], (1 * _forEachIndex) + 1] call CBA_fnc_waitAndExecute;
        } forEach _units;
    };

    private _positionPreStartReached = _plane getVariable [QGVAR(positionPreAReached), false];
    if (!_positionPreStartReached && {(_previousPosition distance2D _positionStart) < 500}) then {
        _positionPreStartReached = true;
        _plane setVariable [QGVAR(positionPreAReached), _positionPreStartReached, true];
        _plane animate ["ramp_top", 1];
        _plane animate ["ramp_bottom", 0.7];
        {
            [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' color = '#FF0000'>STANDBY TO JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
        } forEach _units;
    };
    if (_positionPreStartReached && {!_startReached} && {(_previousPosition distance2D _positionStart) < 25}) then {
        _args set [9, true];
        {
            [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' color = '#00CC00'>GREEN LIGHT - JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5], _x] call CBA_fnc_targetEvent;
        } forEach _units;
    };
    if (_positionPreStartReached && {_startReached} && {!_endReached} && {(_previousPosition distance2D _positionEnd) < 25}) then {
        _args set [10, true];
        _plane animate ["ramp_top", 0];
        _plane animate ["ramp_bottom", 0];
    };

    private _newPosition = _previousPosition vectorAdd (_vectorDirection vectorMultiply _frameStep);
    _plane setPosASL _newPosition;
    _plane setVectorUp [0,0,1];
    _args set [8, _newPosition];
}, 0, [_plane, _units, _start, _end, _vectorDirection, _frameStep, _positionStart, _positionEnd, _start, false, false]] call CBA_fnc_addPerFrameHandler;
