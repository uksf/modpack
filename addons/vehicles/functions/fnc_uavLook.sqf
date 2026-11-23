#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves the UAV gunner view and camera lock while the player looks through
        the gunner camera, and restores them when gunner control is taken again.
        A saved camera lock is restored as a lock. A free view is held on its saved
        target until the camera points within ALIGNED_DOT of it, or HOLD_TIMEOUT
        seconds pass, because the turret slews at a limited speed.

    Parameters:
        0: UAV <OBJECT>
        1: Seat unit <OBJECT>
        2: Turret path <ARRAY>
        3: Control position <STRING>

    Return value:
        Nothing

    Example:
        [_uav, _seat, _turret, _position] call uksf_vehicles_fnc_uavLook
*/

#define ALIGNED_DOT 0.9995
#define HOLD_TIMEOUT 5

params ["_uav", "_seat", "_turret", "_position"];

GVAR(uavLookEndRestore) = {
    if (GVAR(uavLookRestore) isEqualTo []) exitWith {};
    GVAR(uavLookRestore) params ["_handle", "_uav", "_path"];
    GVAR(uavLookRestore) = [];
    [_handle] call CBA_fnc_removePerFrameHandler;
    if (isNull _uav) exitWith {};
    _uav lockCameraTo [objNull, _path, true];
    _uav setVariable [QGVAR(uavLookHold), false];
};

GVAR(uavLookStop) = {
    call GVAR(uavLookEndRestore);
    GVAR(uavLookSession) = [];
    if (GVAR(uavLookPFH) < 0) exitWith {};
    [GVAR(uavLookPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(uavLookPFH) = -1;
};

private _path = [];
if (!isNull _uav && {!isNull _seat}) then {
    _path = _uav unitTurret _seat;
    if (_path isEqualTo []) then { _path = _turret };
};

if (_position == "gunner" && {GVAR(uavLookPFH) >= 0} && {GVAR(uavLookSession) isEqualTo [_uav, _seat, _path]}) exitWith {};

call GVAR(uavLookStop);

if (_position != "gunner" || {isNull _uav} || {isNull _seat}) exitWith {};

GVAR(uavLookSession) = [_uav, _seat, _path];

private _saved = _uav getVariable [QGVAR(uavLook), []];
if (_saved isNotEqualTo [] && {(_saved select 0) isEqualTo _path}) then {
    _saved params ["", "", "", "", "_lock"];
    if (!isNil "_lock") exitWith {
        _uav lockCameraTo [_lock, _path, false];
    };
    _uav setVariable [QGVAR(uavLookHold), true];
    private _handle = [{
        params ["_args"];
        _args params ["_uav", "_seat", "_path", "_saved", "_start"];
        if (isNull _uav || {isNull _seat}) exitWith { call GVAR(uavLookStop) };
        _saved params ["", "_surface", "_asl", "_modelDir"];
        private _aim = _asl;
        if (!_surface) then {
            _aim = (getPosASL _uav) vectorAdd ((_uav vectorModelToWorldVisual _modelDir) vectorMultiply 1000);
        };
        private _eye = AGLToASL (positionCameraToWorld [0, 0, 0]);
        private _view = _eye vectorFromTo AGLToASL (positionCameraToWorld [0, 0, 1000]);
        private _aligned = cameraOn isEqualTo _uav && {(_view vectorDotProduct (_eye vectorFromTo _aim)) > ALIGNED_DOT};
        if (_aligned || {CBA_missionTime - _start > HOLD_TIMEOUT}) exitWith { call GVAR(uavLookEndRestore) };
        _uav lockCameraTo [_aim, _path, true];
    }, 0, [_uav, _seat, _path, _saved, CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
    GVAR(uavLookRestore) = [_handle, _uav, _path];
};

GVAR(uavLookPFH) = [{
    params ["_args"];
    _args params ["_uav", "_seat", "_path"];
    if (isNull _uav || {isNull _seat}) exitWith { call GVAR(uavLookStop) };
    if (_uav getVariable [QGVAR(uavLookHold), false]) exitWith {};
    if (cameraOn isNotEqualTo _uav || {visibleMap}) exitWith {};
    private _from = AGLToASL (positionCameraToWorld [0, 0, 0]);
    private _to = AGLToASL (positionCameraToWorld [0, 0, 4000]);
    private _dir = _from vectorFromTo _to;
    private _hits = lineIntersectsSurfaces [_from, _to, _uav, _seat, true, 1, "VIEW", "NONE"];
    private _surface = _hits isNotEqualTo [];
    private _asl = if (_surface) then { _hits select 0 select 0 } else { _to };
    _uav setVariable [QGVAR(uavLook), [_path, _surface, _asl, _uav vectorWorldToModel _dir, _uav lockedCameraTo _path]];
}, 0.1, [_uav, _seat, _path]] call CBA_fnc_addPerFrameHandler;
