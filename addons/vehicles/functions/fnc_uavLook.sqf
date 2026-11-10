#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves the visible UAV gunner camera target while gunner control is active,
        and restores it when gunner control is taken again.

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

params ["_uav", "_seat", "_turret", "_position"];

private _fnc_stop = {
    if (GVAR(uavLookPFH) < 0) exitWith {};
    [GVAR(uavLookPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(uavLookPFH) = -1;
};

if (_position != "gunner" || {isNull _uav} || {isNull _seat}) exitWith {
    call _fnc_stop;
};

private _path = _uav unitTurret _seat;
if (_path isEqualTo []) then { _path = _turret };

private _saved = _uav getVariable [QGVAR(uavLook), []];
if (_saved isNotEqualTo [] && {(_saved select 0) isEqualTo _path}) then {
    _uav setVariable [QGVAR(uavLookHold), true];
    [{
        params ["_uav", "_path", "_saved"];
        if (isNull _uav) exitWith {};
        _saved params ["", "_surface", "_asl", "_modelDir"];
        private _aim = _asl;
        if (!_surface) then {
            _aim = (getPosASL _uav) vectorAdd ((_uav vectorModelToWorldVisual _modelDir) vectorMultiply 1000);
        };
        _uav lockCameraTo [_aim, _path, true];
        if (hasPilotCamera _uav) then {
            _uav setPilotCameraTarget ASLToAGL _aim;
        };
        [{
            params ["_uav", "_path"];
            if (isNull _uav) exitWith {};
            _uav lockCameraTo [objNull, _path, true];
            _uav setVariable [QGVAR(uavLookHold), false];
        }, [_uav, _path], 0.2] call CBA_fnc_waitAndExecute;
    }, [_uav, _path, _saved]] call CBA_fnc_execNextFrame;
};

if (GVAR(uavLookPFH) >= 0) exitWith {};

GVAR(uavLookPFH) = [{
    params ["_args"];
    _args params ["_uav", "_seat", "_path"];
    if (isNull _uav || {isNull _seat} || {_uav getVariable [QGVAR(uavLookHold), false]}) exitWith {};
    if (visibleMap || {cameraView != "GUNNER"} || {cameraOn isNotEqualTo _uav}) exitWith {};
    private _from = AGLToASL positionCameraToWorld [0, 0, 0];
    private _dir = vectorNormalized ((positionCameraToWorld [0, 0, 1]) vectorDiff (positionCameraToWorld [0, 0, 0]));
    if (_dir isEqualTo [0, 0, 0]) exitWith {};
    private _to = _from vectorAdd (_dir vectorMultiply 4000);
    private _hits = lineIntersectsSurfaces [_from, _to, _uav, _seat, true, 1, "VIEW", "NONE"];
    private _surface = _hits isNotEqualTo [];
    private _asl = if (_surface) then { _hits select 0 select 0 } else { _to };
    _uav setVariable [QGVAR(uavLook), [_path, _surface, _asl, _uav vectorWorldToModel _dir]];
}, 0.1, [_uav, _seat, _path]] call CBA_fnc_addPerFrameHandler;
