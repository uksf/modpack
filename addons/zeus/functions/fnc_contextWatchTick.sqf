#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame Watch tick. Detects camera divergence (user input) to break
        the lock, then computes the locked over-the-shoulder pose using the
        target's visual transform and applies it to the curator camera. Cam +
        aim are lifted in world Z and clamped above terrain. Direction is
        smoothed by a fixed-factor lerp.

    Parameter(s):
        0: PFH Args
        1: PFH ID

    Return Value:
        None

    Example:
        Registered via CBA_fnc_addPerFrameHandler in uksf_zeus_fnc_contextWatch
*/
params ["", "_idPFH"];

private _camera = curatorCamera;
private _target = GVAR(watchTarget);

private _shouldStop = false;
if (isNull _camera || {isNull _target} || {!alive _target} || {isNull (getAssignedCuratorLogic player)}) then {
    _shouldStop = true;
};
if (!_shouldStop && GVAR(watchHasExpected)) then {
    if (GVAR(watchScrolledFrame)) then {
        GVAR(watchScrolledFrame) = false;
    } else {
        if (((getPosASL _camera) vectorDistance GVAR(watchExpectedPos)) > 0.15) then {
            _shouldStop = true;
        };
    };
    if (!_shouldStop && {!GVAR(watchOrbitActive) && !GVAR(watchLastFrameOrbitActive)} && {((vectorDir _camera) vectorDotProduct GVAR(watchExpectedDir)) < 0.998}) then {
        _shouldStop = true;
    };
};
GVAR(watchLastFrameOrbitActive) = GVAR(watchOrbitActive);
if (_shouldStop) exitWith {
    [_idPFH] call CBA_fnc_removePerFrameHandler;
    GVAR(watchPFH) = -1;
    GVAR(watchTarget) = objNull;
    GVAR(watchHasExpected) = false;
};

private _focus = vehicle _target;
private _onFoot = _focus isEqualTo _target;
private _onTurret = !_onFoot;

private _bbox = 0 boundingBoxReal _focus;
_bbox params ["_bbMin", "_bbMax"];
private _length = (_bbMax # 1) - (_bbMin # 1);
private _centerZ = ((_bbMax # 2) + (_bbMin # 2)) * 0.5;
private _aimZ = _centerZ + 0.4;

private _baseBack = if (_onTurret) then {5} else {5 max (_length * 1.6)};
private _baseSide = 0.6;
private _basePitch = _baseBack * 0.2;
private _baseHorizDist = sqrt ((_baseSide * _baseSide) + (_baseBack * _baseBack));
private _baseDistance = sqrt ((_baseHorizDist * _baseHorizDist) + (_basePitch * _basePitch));
private _baseYawDeg = atan (_baseSide / _baseBack);
private _basePitchDeg = atan (_basePitch / _baseHorizDist);

private _effectiveYaw = _baseYawDeg + GVAR(watchOrbitYawSmooth);
private _effectivePitch = ((_basePitchDeg + GVAR(watchOrbitPitchSmooth)) max -85) min 85;
private _distance = (_baseDistance + GVAR(watchZoom)) max 1.0;
private _cosP = cos _effectivePitch;
private _behindAmt = _distance * (cos _effectiveYaw) * _cosP;
private _rightAmt = _distance * (sin _effectiveYaw) * _cosP;
private _upAmt = _distance * (sin _effectivePitch);
private _camOffset = [_rightAmt, -_behindAmt, _upAmt];

private _idealCamPos = [];
private _aimPoint = [];
private _useTurretFrame = false;
if (_onTurret) then {
    private _lookDir = [0, 0, 0];
    private _lookMag = 0;
    private _vehicleWeapon = currentWeapon _focus;
    if (_vehicleWeapon != "") then {
        _lookDir = _focus weaponDirection _vehicleWeapon;
        _lookMag = vectorMagnitude _lookDir;
    };
    if (_lookMag <= 0.1) then {
        private _unitWeapon = currentWeapon _target;
        if (_unitWeapon != "") then {
            _lookDir = _target weaponDirection _unitWeapon;
            _lookMag = vectorMagnitude _lookDir;
        };
    };
    if (_lookMag <= 0.1) then {
        _lookDir = eyeDirection _target;
        _lookMag = vectorMagnitude _lookDir;
    };
    if (_lookMag <= 0.1) then {
        _lookDir = vectorDir _focus;
        _lookMag = vectorMagnitude _lookDir;
    };
    if (_lookMag > 0) then {
        _lookDir = _lookDir vectorMultiply (1 / _lookMag);
        private _yawDir = [_lookDir # 0, _lookDir # 1, 0];
        private _yawMag = vectorMagnitude _yawDir;
        if (_yawMag > 0) then {
            _yawDir = _yawDir vectorMultiply (1 / _yawMag);
            private _right = _yawDir vectorCrossProduct [0, 0, 1];
            private _rightMag = vectorMagnitude _right;
            if (_rightMag > 0) then {
                _right = _right vectorMultiply (1 / _rightMag);
                private _eyePos = eyePos _target;
                _idealCamPos = _eyePos
                    vectorAdd (_yawDir vectorMultiply (-_behindAmt))
                    vectorAdd (_right vectorMultiply _rightAmt)
                    vectorAdd [0, 0, _upAmt];
                _aimPoint = _eyePos vectorAdd (_lookDir vectorMultiply 5);
                _useTurretFrame = true;
            };
        };
    };
};
private _flyingEyeBlend = 0;
if (!_useTurretFrame) then {
    private _flyingEyeMin = 12;
    private _flyingEyeMax = 18;
    _flyingEyeBlend = (((_distance - _flyingEyeMin) / (_flyingEyeMax - _flyingEyeMin)) max 0) min 1;

    private _camPosA = _focus modelToWorldVisualWorld [_camOffset # 0, _camOffset # 1, _aimZ + (_camOffset # 2)];
    private _aimPointA = _focus modelToWorldVisualWorld [0, 0, _aimZ];
    private _worldLift = 0.7;
    _camPosA set [2, (_camPosA # 2) + _worldLift];
    _aimPointA set [2, (_aimPointA # 2) + _worldLift];

    private _bodyDir = vectorDir _focus;
    private _yawDirNT = [_bodyDir # 0, _bodyDir # 1, 0];
    private _yawNTMag = vectorMagnitude _yawDirNT;
    if (_yawNTMag > 0) then {
        _yawDirNT = _yawDirNT vectorMultiply (1 / _yawNTMag);
    } else {
        _yawDirNT = [0, 1, 0];
    };
    private _rightNT = _yawDirNT vectorCrossProduct [0, 0, 1];
    private _focusPosASL = getPosASLVisual _focus;
    private _aimPointB = _focusPosASL vectorAdd [0, 0, _centerZ + 0.4];
    private _camPosB = _aimPointB
        vectorAdd (_yawDirNT vectorMultiply (-_behindAmt))
        vectorAdd (_rightNT vectorMultiply _rightAmt)
        vectorAdd [0, 0, _upAmt];

    _idealCamPos = [
        ((_camPosA # 0) * (1 - _flyingEyeBlend)) + ((_camPosB # 0) * _flyingEyeBlend),
        ((_camPosA # 1) * (1 - _flyingEyeBlend)) + ((_camPosB # 1) * _flyingEyeBlend),
        ((_camPosA # 2) * (1 - _flyingEyeBlend)) + ((_camPosB # 2) * _flyingEyeBlend)
    ];
    _aimPoint = [
        ((_aimPointA # 0) * (1 - _flyingEyeBlend)) + ((_aimPointB # 0) * _flyingEyeBlend),
        ((_aimPointA # 1) * (1 - _flyingEyeBlend)) + ((_aimPointB # 1) * _flyingEyeBlend),
        ((_aimPointA # 2) * (1 - _flyingEyeBlend)) + ((_aimPointB # 2) * _flyingEyeBlend)
    ];
};

if (_onFoot && {_target isKindOf "CAManBase"}) then {
    private _eyeDir = eyeDirection _target;
    _aimPoint set [2, (_aimPoint # 2) + ((_eyeDir # 2) * 2.5 * (1 - _flyingEyeBlend))];
};

private _instantSpeed = vectorMagnitude (velocity _focus);
GVAR(watchSmoothFocusSpeed) = if (GVAR(watchSmoothPosInit)) then {
    GVAR(watchSmoothFocusSpeed) + (_instantSpeed - GVAR(watchSmoothFocusSpeed)) * 0.2
} else {
    _instantSpeed
};

private _orbitNow = GVAR(watchOrbitActive) || GVAR(watchLastFrameOrbitActive);

private _mousePos = getMousePosition;
private _mouseX = _mousePos # 0;
private _mouseY = _mousePos # 1;
if (GVAR(watchOrbitActive) && GVAR(watchPrevFrameMouseInit) && !visibleMap) then {
    private _dx = _mouseX - GVAR(watchPrevFrameMouseX);
    private _dy = _mouseY - GVAR(watchPrevFrameMouseY);
    GVAR(watchOrbitYaw) = GVAR(watchOrbitYaw) + (_dx * 360);
    GVAR(watchOrbitPitch) = ((GVAR(watchOrbitPitch) - (_dy * 360)) max -80) min 80;
};
GVAR(watchPrevFrameMouseX) = _mouseX;
GVAR(watchPrevFrameMouseY) = _mouseY;
GVAR(watchPrevFrameMouseInit) = true;

private _orbitSmoothFactor = 0.25;
GVAR(watchOrbitYawSmooth) = GVAR(watchOrbitYawSmooth) + (GVAR(watchOrbitYaw) - GVAR(watchOrbitYawSmooth)) * _orbitSmoothFactor;
GVAR(watchOrbitPitchSmooth) = GVAR(watchOrbitPitchSmooth) + (GVAR(watchOrbitPitch) - GVAR(watchOrbitPitchSmooth)) * _orbitSmoothFactor;
private _posFactor = 0.2;
private _posDeadband = 0.2;
private _maxPosStep = if (_orbitNow) then {1e6} else {(GVAR(watchSmoothFocusSpeed) * diag_deltaTime * 1.5) max 0.3};
private _camPos = if (GVAR(watchSmoothPosInit)) then {
    private _posDelta = _idealCamPos vectorDiff GVAR(watchSmoothPos);
    private _posMag = vectorMagnitude _posDelta;
    private _posRamp = if (_posMag >= _posDeadband) then {1} else {((_posMag / _posDeadband) ^ 2)};
    private _posStep = _posDelta vectorMultiply (_posFactor * _posRamp);
    private _posStepMag = vectorMagnitude _posStep;
    if (_posStepMag > _maxPosStep) then {
        _posStep = _posStep vectorMultiply (_maxPosStep / _posStepMag);
    };
    GVAR(watchSmoothPos) vectorAdd _posStep
} else {
    +_idealCamPos
};

private _terrainZ = getTerrainHeightASL [_camPos # 0, _camPos # 1];
if ((_camPos # 2) < _terrainZ + 0.5) then {
    _camPos set [2, _terrainZ + 0.5];
};
GVAR(watchSmoothPos) = _camPos;
GVAR(watchSmoothPosInit) = true;

private _idealDir = [
    (_aimPoint # 0) - (_camPos # 0),
    (_aimPoint # 1) - (_camPos # 1),
    (_aimPoint # 2) - (_camPos # 2)
];
private _idealLen = vectorMagnitude _idealDir;
if (_idealLen <= 0) exitWith {};
_idealDir = _idealDir vectorMultiply (1 / _idealLen);

private _dirFactor = 0.2;
private _dirDeadband = 0.02;
private _maxDirStep = if (_orbitNow) then {1e6} else {0.04};
private _smoothDir = if (GVAR(watchSmoothInit)) then {
    private _dirDelta = _idealDir vectorDiff GVAR(watchSmoothDir);
    private _dirMag = vectorMagnitude _dirDelta;
    private _dirRamp = if (_dirMag >= _dirDeadband) then {1} else {((_dirMag / _dirDeadband) ^ 2)};
    private _dirStep = _dirDelta vectorMultiply (_dirFactor * _dirRamp);
    private _dirStepMag = vectorMagnitude _dirStep;
    if (_dirStepMag > _maxDirStep) then {
        _dirStep = _dirStep vectorMultiply (_maxDirStep / _dirStepMag);
    };
    private _blended = GVAR(watchSmoothDir) vectorAdd _dirStep;
    private _blendedLen = vectorMagnitude _blended;
    if (_blendedLen > 0) then {_blended vectorMultiply (1 / _blendedLen)} else {_idealDir};
} else {
    _idealDir
};
GVAR(watchSmoothDir) = _smoothDir;
GVAR(watchSmoothInit) = true;

private _right = _smoothDir vectorCrossProduct [0, 0, 1];
private _rightLen = vectorMagnitude _right;
private _up = if (_rightLen > 0) then {
    _right = _right vectorMultiply (1 / _rightLen);
    private _u = _right vectorCrossProduct _smoothDir;
    private _uLen = vectorMagnitude _u;
    if (_uLen > 0) then {_u vectorMultiply (1 / _uLen)} else {[0, 0, 1]};
} else {
    [0, 1, 0];
};

_camera setPosASL _camPos;
_camera setVectorDirAndUp [_smoothDir, _up];

GVAR(watchExpectedPos) = getPosASL _camera;
GVAR(watchExpectedDir) = vectorDir _camera;
GVAR(watchHasExpected) = true;
