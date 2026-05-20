if (!isNil "uksf_zeus_watchPFH" && {uksf_zeus_watchPFH isEqualType 0} && {uksf_zeus_watchPFH > -1}) then {
    [uksf_zeus_watchPFH] call CBA_fnc_removePerFrameHandler;
};
if (isNil "uksf_zeus_watchInvertY") then { uksf_zeus_watchInvertY = false };
uksf_zeus_watchPFH = -1;
uksf_zeus_watchTarget = objNull;
uksf_zeus_watchHasExpected = false;
uksf_zeus_watchExpectedPos = [0, 0, 0];
uksf_zeus_watchExpectedDir = [0, 1, 0];
uksf_zeus_watchSmoothDir = [0, 1, 0];
uksf_zeus_watchSmoothInit = false;
uksf_zeus_watchSmoothPos = [0, 0, 0];
uksf_zeus_watchSmoothPosInit = false;
uksf_zeus_watchSmoothFocusSpeed = 0;
uksf_zeus_watchZoom = 0;
uksf_zeus_watchScrolledFrame = false;
uksf_zeus_watchOrbitYaw = 0;
uksf_zeus_watchOrbitPitch = 0;
uksf_zeus_watchOrbitYawSmooth = 0;
uksf_zeus_watchOrbitPitchSmooth = 0;
uksf_zeus_watchOrbitActive = false;
uksf_zeus_watchLastFrameOrbitActive = false;
uksf_zeus_watchPrevFrameMouseX = 0;
uksf_zeus_watchPrevFrameMouseY = 0;
uksf_zeus_watchPrevFrameMouseInit = false;
uksf_zeus_watchKeyDownEHId = -1;
uksf_zeus_watchKeyUpEHId = -1;

private _existingDisplay = findDisplay 312;
if (!isNil "uksf_zeus_watchScrollEHId" && {uksf_zeus_watchScrollEHId > -1} && {!isNull _existingDisplay}) then {
    _existingDisplay displayRemoveEventHandler ["MouseZChanged", uksf_zeus_watchScrollEHId];
};
if (!isNil "uksf_zeus_watchKeyDownEHId" && {uksf_zeus_watchKeyDownEHId > -1} && {!isNull _existingDisplay}) then {
    _existingDisplay displayRemoveEventHandler ["KeyDown", uksf_zeus_watchKeyDownEHId];
};
if (!isNil "uksf_zeus_watchKeyUpEHId" && {uksf_zeus_watchKeyUpEHId > -1} && {!isNull _existingDisplay}) then {
    _existingDisplay displayRemoveEventHandler ["KeyUp", uksf_zeus_watchKeyUpEHId];
};
uksf_zeus_watchScrollEHId = -1;
uksf_zeus_watchKeyDownEHId = -1;
uksf_zeus_watchKeyUpEHId = -1;

if (!isNil "uksf_zeus_watchDisplayLoadedId") then {
    ["zen_curatorDisplayLoaded", uksf_zeus_watchDisplayLoadedId] call CBA_fnc_removeEventHandler;
};
uksf_zeus_watchDisplayLoadedId = nil;

if (!isNil "uksf_zeus_watchRegistered") then {
    [["uksf_zeus_watch"]] call zen_context_menu_fnc_removeAction;
};
uksf_zeus_watchRegistered = true;

uksf_zeus_watchScrollHandler = {
    if (isNil "uksf_zeus_watchPFH" || {uksf_zeus_watchPFH < 0}) exitWith {false};
    if (visibleMap) exitWith {false};
    params ["", "_scroll"];
    uksf_zeus_watchZoom = ((uksf_zeus_watchZoom + (-_scroll * 1.0)) max -50) min 50;
    uksf_zeus_watchScrolledFrame = true;
    true
};

uksf_zeus_watchAttachEHs = {
    private _display = findDisplay 312;
    if (uksf_zeus_watchScrollEHId > -1 && {!isNull _display}) then {
        _display displayRemoveEventHandler ["MouseZChanged", uksf_zeus_watchScrollEHId];
    };
    if (uksf_zeus_watchKeyDownEHId > -1 && {!isNull _display}) then {
        _display displayRemoveEventHandler ["KeyDown", uksf_zeus_watchKeyDownEHId];
    };
    if (uksf_zeus_watchKeyUpEHId > -1 && {!isNull _display}) then {
        _display displayRemoveEventHandler ["KeyUp", uksf_zeus_watchKeyUpEHId];
    };
    uksf_zeus_watchScrollEHId = -1;
    uksf_zeus_watchKeyDownEHId = -1;
    uksf_zeus_watchKeyUpEHId = -1;
    if (isNull _display) exitWith {};
    uksf_zeus_watchScrollEHId = _display displayAddEventHandler ["MouseZChanged", {call uksf_zeus_watchScrollHandler}];
    uksf_zeus_watchKeyDownEHId = _display displayAddEventHandler ["KeyDown", {
        params ["", "_key"];
        if (_key in [42, 54]) then {
            uksf_zeus_watchOrbitActive = true;
            uksf_zeus_watchPrevFrameMouseInit = false;
        };
        false
    }];
    uksf_zeus_watchKeyUpEHId = _display displayAddEventHandler ["KeyUp", {
        params ["", "_key"];
        if (_key in [42, 54]) then {
            uksf_zeus_watchOrbitActive = false;
        };
        false
    }];
};

call uksf_zeus_watchAttachEHs;
uksf_zeus_watchDisplayLoadedId = ["zen_curatorDisplayLoaded", {call uksf_zeus_watchAttachEHs}] call CBA_fnc_addEventHandler;

private _action = ["uksf_zeus_watch", "Watch", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {
    params ["", "_selectedObjects"];

    private _target = (_selectedObjects select {!isNull _x && {alive _x}}) param [0, objNull];
    if (isNull _target) then {
        private _selectedFromCurator = (curatorSelected param [0, []]) select {!isNull _x && {alive _x}};
        _target = _selectedFromCurator param [0, objNull];
    };
    if (isNull _target) then {_target = cursorObject};
    if (isNull _target || {!alive _target}) exitWith {
        systemChat "Watch: no target";
    };

    if (!isNil "uksf_zeus_watchPFH" && {uksf_zeus_watchPFH isEqualType 0} && {uksf_zeus_watchPFH > -1}) then {
        [uksf_zeus_watchPFH] call CBA_fnc_removePerFrameHandler;
    };
    uksf_zeus_watchPFH = -1;
    uksf_zeus_watchTarget = _target;
    uksf_zeus_watchHasExpected = false;
    uksf_zeus_watchExpectedPos = [0, 0, 0];
    uksf_zeus_watchExpectedDir = [0, 1, 0];
    uksf_zeus_watchSmoothDir = [0, 1, 0];
    uksf_zeus_watchSmoothInit = false;
    uksf_zeus_watchSmoothPos = [0, 0, 0];
    uksf_zeus_watchSmoothPosInit = false;
    uksf_zeus_watchSmoothFocusSpeed = 0;
    uksf_zeus_watchZoom = 0;
    uksf_zeus_watchScrolledFrame = false;
    uksf_zeus_watchOrbitYaw = 0;
    uksf_zeus_watchOrbitPitch = 0;
    uksf_zeus_watchOrbitYawSmooth = 0;
    uksf_zeus_watchOrbitPitchSmooth = 0;
    uksf_zeus_watchOrbitActive = false;
    uksf_zeus_watchLastFrameOrbitActive = false;

    uksf_zeus_watchPFH = [{
        params ["", "_idPFH"];
        private _camera = curatorCamera;
        private _target = uksf_zeus_watchTarget;

        private _shouldStop = false;
        if (isNull _camera || {isNull _target} || {!alive _target} || {isNull (getAssignedCuratorLogic player)}) then {
            _shouldStop = true;
        };
        if (!_shouldStop && uksf_zeus_watchHasExpected) then {
            if (uksf_zeus_watchScrolledFrame) then {
                uksf_zeus_watchScrolledFrame = false;
            } else {
                if (((getPosASL _camera) vectorDistance uksf_zeus_watchExpectedPos) > 0.15) then {
                    _shouldStop = true;
                };
            };
            if (!_shouldStop && {!uksf_zeus_watchOrbitActive && !uksf_zeus_watchLastFrameOrbitActive} && {((vectorDir _camera) vectorDotProduct uksf_zeus_watchExpectedDir) < 0.998}) then {
                _shouldStop = true;
            };
        };
        uksf_zeus_watchLastFrameOrbitActive = uksf_zeus_watchOrbitActive;
        if (_shouldStop) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            uksf_zeus_watchPFH = -1;
            uksf_zeus_watchTarget = objNull;
            uksf_zeus_watchHasExpected = false;
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

        private _effectiveYaw = _baseYawDeg + uksf_zeus_watchOrbitYawSmooth;
        private _effectivePitch = ((_basePitchDeg + uksf_zeus_watchOrbitPitchSmooth) max -85) min 85;
        private _distance = (_baseDistance + uksf_zeus_watchZoom) max 1.0;
        private _cosP = cos _effectivePitch;
        private _behindAmt = _distance * (cos _effectiveYaw) * _cosP;
        private _rightAmt = _distance * (sin _effectiveYaw) * _cosP;
        private _upAmt = _distance * (sin _effectivePitch);

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
        if (!_useTurretFrame) then {
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
            _aimPoint = _focusPosASL vectorAdd [0, 0, _centerZ + 0.4];
            _idealCamPos = _aimPoint
                vectorAdd (_yawDirNT vectorMultiply (-_behindAmt))
                vectorAdd (_rightNT vectorMultiply _rightAmt)
                vectorAdd [0, 0, _upAmt];
        };

        if (_onFoot && {_target isKindOf "CAManBase"}) then {
            private _eyeDir = eyeDirection _target;
            _aimPoint set [2, (_aimPoint # 2) + ((_eyeDir # 2) * 2.5)];
        };

        private _instantSpeed = vectorMagnitude (velocity _focus);
        uksf_zeus_watchSmoothFocusSpeed = if (uksf_zeus_watchSmoothPosInit) then {
            uksf_zeus_watchSmoothFocusSpeed + (_instantSpeed - uksf_zeus_watchSmoothFocusSpeed) * 0.22
        } else {
            _instantSpeed
        };

        private _orbitNow = uksf_zeus_watchOrbitActive || uksf_zeus_watchLastFrameOrbitActive;

        private _mousePos = getMousePosition;
        private _mouseX = _mousePos # 0;
        private _mouseY = _mousePos # 1;
        if (uksf_zeus_watchOrbitActive && uksf_zeus_watchPrevFrameMouseInit && !visibleMap) then {
            private _dx = _mouseX - uksf_zeus_watchPrevFrameMouseX;
            private _dy = _mouseY - uksf_zeus_watchPrevFrameMouseY;
            if (uksf_zeus_watchInvertY) then { _dy = -_dy };
            uksf_zeus_watchOrbitYaw = uksf_zeus_watchOrbitYaw + (_dx * 360);
            uksf_zeus_watchOrbitPitch = ((uksf_zeus_watchOrbitPitch + (_dy * 360)) max -80) min 80;
        };
        uksf_zeus_watchPrevFrameMouseX = _mouseX;
        uksf_zeus_watchPrevFrameMouseY = _mouseY;
        uksf_zeus_watchPrevFrameMouseInit = true;

        private _orbitSmoothFactor = 0.275;
        uksf_zeus_watchOrbitYawSmooth = uksf_zeus_watchOrbitYawSmooth + (uksf_zeus_watchOrbitYaw - uksf_zeus_watchOrbitYawSmooth) * _orbitSmoothFactor;
        uksf_zeus_watchOrbitPitchSmooth = uksf_zeus_watchOrbitPitchSmooth + (uksf_zeus_watchOrbitPitch - uksf_zeus_watchOrbitPitchSmooth) * _orbitSmoothFactor;
        private _camPos = if (uksf_zeus_watchSmoothPosInit && !_orbitNow) then {
            private _posDelta = _idealCamPos vectorDiff uksf_zeus_watchSmoothPos;
            private _posMag = vectorMagnitude _posDelta;
            private _posFactor = 0.22;
            private _posDeadband = 0.2;
            private _baseCap = (uksf_zeus_watchSmoothFocusSpeed * diag_deltaTime * 1.5) max 0.3;
            private _maxPosStep = if (_posMag > 5) then {1e6} else {_baseCap};
            private _posRamp = if (_posMag >= _posDeadband) then {1} else {((_posMag / _posDeadband) ^ 2)};
            private _posStep = _posDelta vectorMultiply (_posFactor * _posRamp);
            private _posStepMag = vectorMagnitude _posStep;
            if (_posStepMag > _maxPosStep) then {
                _posStep = _posStep vectorMultiply (_maxPosStep / _posStepMag);
            };
            uksf_zeus_watchSmoothPos vectorAdd _posStep
        } else {
            +_idealCamPos
        };

        private _terrainZ = getTerrainHeightASL [_camPos # 0, _camPos # 1];
        if ((_camPos # 2) < _terrainZ + 0.5) then {
            _camPos set [2, _terrainZ + 0.5];
        };
        uksf_zeus_watchSmoothPos = _camPos;
        uksf_zeus_watchSmoothPosInit = true;

        private _idealDir = [
            (_aimPoint # 0) - (_camPos # 0),
            (_aimPoint # 1) - (_camPos # 1),
            (_aimPoint # 2) - (_camPos # 2)
        ];
        private _idealLen = vectorMagnitude _idealDir;
        if (_idealLen <= 0) exitWith {};
        _idealDir = _idealDir vectorMultiply (1 / _idealLen);

        private _smoothDir = if (uksf_zeus_watchSmoothInit && !_orbitNow) then {
            private _dirDelta = _idealDir vectorDiff uksf_zeus_watchSmoothDir;
            private _dirMag = vectorMagnitude _dirDelta;
            private _dirFactor = 0.22;
            private _dirDeadband = 0.02;
            private _baseDirCap = 0.04;
            private _maxDirStep = if (_dirMag > 0.35) then {1e6} else {_baseDirCap};
            private _dirRamp = if (_dirMag >= _dirDeadband) then {1} else {((_dirMag / _dirDeadband) ^ 2)};
            private _dirStep = _dirDelta vectorMultiply (_dirFactor * _dirRamp);
            private _dirStepMag = vectorMagnitude _dirStep;
            if (_dirStepMag > _maxDirStep) then {
                _dirStep = _dirStep vectorMultiply (_maxDirStep / _dirStepMag);
            };
            private _blended = uksf_zeus_watchSmoothDir vectorAdd _dirStep;
            private _blendedLen = vectorMagnitude _blended;
            if (_blendedLen > 0) then {_blended vectorMultiply (1 / _blendedLen)} else {_idealDir};
        } else {
            _idealDir
        };
        uksf_zeus_watchSmoothDir = _smoothDir;
        uksf_zeus_watchSmoothInit = true;

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

        uksf_zeus_watchExpectedPos = getPosASL _camera;
        uksf_zeus_watchExpectedDir = vectorDir _camera;
        uksf_zeus_watchHasExpected = true;
    }, 0, []] call CBA_fnc_addPerFrameHandler;

    systemChat format ["Watch: %1", _target];
}, {
    params ["", "_selectedObjects"];
    _selectedObjects isNotEqualTo [] && {alive (_selectedObjects # 0)}
}] call zen_context_menu_fnc_createAction;
[_action, [], -650] call zen_context_menu_fnc_addAction;

systemChat "Watch context action registered.";
