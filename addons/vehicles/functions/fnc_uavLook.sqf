#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves the UAV gunner look target while the player holds gunner control,
        and restores it when gunner control is taken again. The camera stays locked
        on the saved target until the turret points within ALIGNED_DOT of it, or
        HOLD_TIMEOUT seconds pass, because the turret slews at a limited speed.

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
        private _weapon = _uav currentWeaponTurret _path;
        private _aligned = _weapon != "" && {((_uav weaponDirection _weapon) vectorDotProduct ((getPosASL _uav) vectorFromTo _aim)) > ALIGNED_DOT};
        if (_aligned || {CBA_missionTime - _start > HOLD_TIMEOUT}) exitWith { call GVAR(uavLookEndRestore) };
        _uav lockCameraTo [_aim, _path, true];
        if (hasPilotCamera _uav) then {
            _uav setPilotCameraTarget ASLToAGL _aim;
        };
    }, 0, [_uav, _seat, _path, _saved, CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
    GVAR(uavLookRestore) = [_handle, _uav, _path];
};

GVAR(uavLookPFH) = [{
    params ["_args"];
    _args params ["_uav", "_seat", "_path"];
    if (isNull _uav || {isNull _seat}) exitWith { call GVAR(uavLookStop) };
    if (_uav getVariable [QGVAR(uavLookHold), false]) exitWith {};
    private _weapon = _uav currentWeaponTurret _path;
    if (_weapon == "") exitWith {};
    private _dir = _uav weaponDirection _weapon;
    if (_dir isEqualTo [0, 0, 0]) exitWith {};
    private _from = getPosASL _uav;
    private _to = _from vectorAdd (_dir vectorMultiply 4000);
    private _hits = lineIntersectsSurfaces [_from, _to, _uav, _seat, true, 1, "VIEW", "NONE"];
    private _surface = _hits isNotEqualTo [];
    private _asl = if (_surface) then { _hits select 0 select 0 } else { _to };
    _uav setVariable [QGVAR(uavLook), [_path, _surface, _asl, _uav vectorWorldToModel _dir]];
}, 0.1, [_uav, _seat, _path]] call CBA_fnc_addPerFrameHandler;
