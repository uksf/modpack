// Visual test harness. Helpers for test.sqf; see dev_harness/client/run.js.
vc_fnc_log = { diag_log text format ["[vclient] %1", _this] };

// [eyeASL, targetASL or object, fov(0.75)] call vc_fnc_cam. Waits for streaming and LODs to settle.
vc_fnc_cam = {
    params ["_eye", "_target", ["_fov", 0.75], ["_settle", 1.5]];
    if (isNil "vc_cam") then {
        vc_cam = "camera" camCreate ASLToAGL _eye;
        vc_cam cameraEffect ["internal", "back"];
        showCinemaBorder false;
    };
    private _to = if (_target isEqualType objNull) then { AGLToASL (_target modelToWorldVisual (boundingCenter _target)) } else { _target };
    vc_cam setPosASL _eye;
    vc_cam setVectorDirAndUp [vectorNormalized (_to vectorDiff _eye), [0, 0, 1]];
    vc_cam camSetFov _fov;
    vc_cam camCommit 0;
    uiSleep _settle;
};

// [object, azimuth, elevation, distance, fov] call vc_fnc_orbit. Camera looks at the object's centre.
// Azimuth is relative to the object's heading (0 = in front, 90 = its right side). distance <= 0 frames
// the whole object; a positive distance is in metres.
vc_fnc_orbit = {
    params ["_obj", "_az", "_el", ["_dist", 0], ["_fov", 0.75], ["_settle", 1.5]];
    if (_dist <= 0) then { _dist = (boundingBoxReal _obj select 2) * 0.6 / _fov };
    _az = _az + getDir _obj;
    private _c = AGLToASL (_obj modelToWorldVisual (boundingCenter _obj));
    private _eye = _c vectorAdd [_dist * cos _el * sin _az, _dist * cos _el * cos _az, _dist * sin _el];
    [_eye, _c, _fov, _settle] call vc_fnc_cam;
};

// "name" call vc_fnc_shot. Writes <name>.png; waits so the file is complete before the next move.
vc_fnc_shot = {
    private _ok = screenshot (vc_runId + "_" + _this + ".png");
    uiSleep 0.5;
    format ["shot %1 %2", _this, _ok] call vc_fnc_log;
};

vc_fnc_done = { "done" call vc_fnc_log };

[] spawn {
    waitUntil { time > 0 && !isNull player };
    showHUD [false, false, false, false, false, false, false, false];
    if (!isNil "uksf_screenshot_fnc_toggle") then { [false] call uksf_screenshot_fnc_toggle };
    clearRadio; enableRadio false; enableSentences false;
    player allowDamage false; player hideObject true;
    "start" call vc_fnc_log;
    private _err = [] execVM "test.sqf";
};
