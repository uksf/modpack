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

private _idealCamPos = [];
private _aimPoint = [];
private _orbitAnchor = [];
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
                _orbitAnchor = _eyePos;
                _useTurretFrame = true;
            };
        };
    };
};
if (!_useTurretFrame) then {
    private _focusPosASL = getPosASLVisual _focus;
    private _frontPoint = _focus modelToWorldVisualWorld [0, 1, 0];
    private _bodyDir = _frontPoint vectorDiff _focusPosASL;
    private _yawDirNT = [_bodyDir # 0, _bodyDir # 1, 0];
    private _yawNTMag = vectorMagnitude _yawDirNT;
    if (_yawNTMag > 0) then {
        _yawDirNT = _yawDirNT vectorMultiply (1 / _yawNTMag);
    } else {
        _yawDirNT = [0, 1, 0];
    };
    private _rightNT = _yawDirNT vectorCrossProduct [0, 0, 1];
    _aimPoint = _focusPosASL vectorAdd [0, 0, _centerZ + 0.4];
    _orbitAnchor = _aimPoint;
    _idealCamPos = _aimPoint
        vectorAdd (_yawDirNT vectorMultiply (-_behindAmt))
        vectorAdd (_rightNT vectorMultiply _rightAmt)
        vectorAdd [0, 0, _upAmt];
};

private _orbitNow = GVAR(watchOrbitActive) || GVAR(watchLastFrameOrbitActive);

// Orbit input: measure cursor offset from screen centre, then recentre the
// cursor every frame. Reading absolute cursor position directly would stall
// at the screen edge once the free curator cursor clips against it.
if (GVAR(watchOrbitActive) && !visibleMap) then {
    private _mousePos = getMousePosition;
    if (GVAR(watchPrevFrameMouseInit)) then {
        private _dx = (_mousePos # 0) - 0.5;
        private _dy = (_mousePos # 1) - 0.5;
        if (GVAR(watchInvertY)) then { _dy = -_dy };
        GVAR(watchOrbitYaw) = GVAR(watchOrbitYaw) + (_dx * 360);
        GVAR(watchOrbitPitch) = ((GVAR(watchOrbitPitch) + (_dy * 360)) max -80) min 80;
    };
    setMousePosition [0.5, 0.5];
    GVAR(watchPrevFrameMouseInit) = true;
} else {
    GVAR(watchPrevFrameMouseInit) = false;
};

private _orbitSmoothFactor = 0.275;
GVAR(watchOrbitYawSmooth) = GVAR(watchOrbitYawSmooth) + (GVAR(watchOrbitYaw) - GVAR(watchOrbitYawSmooth)) * _orbitSmoothFactor;
GVAR(watchOrbitPitchSmooth) = GVAR(watchOrbitPitchSmooth) + (GVAR(watchOrbitPitch) - GVAR(watchOrbitPitchSmooth)) * _orbitSmoothFactor;
private _camPos = if (GVAR(watchSmoothPosInit)) then {
    private _posDelta = _idealCamPos vectorDiff GVAR(watchSmoothPos);
    private _posMag = vectorMagnitude _posDelta;
    private _baseFactor = 1 - GVAR(watchSmoothing);

    // Angular boost: ramp catch-up speed up as the cam's seat around the subject
    // lags the desired bearing (e.g. subject turns rapidly).
    private _angFactor = _baseFactor;
    private _desiredOrbit = _idealCamPos vectorDiff _orbitAnchor;
    private _currentOrbit = GVAR(watchSmoothPos) vectorDiff _orbitAnchor;
    private _desiredMag = vectorMagnitude _desiredOrbit;
    private _currentMag = vectorMagnitude _currentOrbit;
    if (_desiredMag > 0 && {_currentMag > 0}) then {
        private _cosAngle = ((_desiredOrbit vectorDotProduct _currentOrbit) / (_desiredMag * _currentMag)) max -1 min 1;
        private _angleRamp = (((acos _cosAngle) - 45) / 90) max 0 min 1;
        _angFactor = _baseFactor + (_angleRamp * ((0.6 max _baseFactor) - _baseFactor));
    };

    // Translational boost: ramp catch-up speed up over large positional gaps
    // (teleport, target swap) so it converges in a few frames without snapping.
    private _distRamp = ((_posMag - 10) / 90) max 0 min 1;
    private _distFactor = _baseFactor + (_distRamp * ((0.9 max _baseFactor) - _baseFactor));

    private _factor = _angFactor max _distFactor;
    private _posDeadband = 0.2;
    private _posRamp = if (_posMag >= _posDeadband) then {1} else {((_posMag / _posDeadband) ^ 2)};
    GVAR(watchSmoothPos) vectorAdd (_posDelta vectorMultiply (_factor * _posRamp))
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

private _smoothDir = if (GVAR(watchSmoothInit)) then {
    private _dirDelta = _idealDir vectorDiff GVAR(watchSmoothDir);
    private _dirMag = vectorMagnitude _dirDelta;
    private _dirFactor = 1 - GVAR(watchSmoothing);
    private _dirDeadband = 0.02;
    private _baseDirCap = 0.04;
    private _maxDirStep = if (_dirMag > 0.35 || _orbitNow) then {1e6} else {_baseDirCap};
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
