// Visual test harness. Helpers for test.sqf; see dev_harness/client/run.js.
vc_fnc_log = { diag_log text format ["[vclient] %1", _this] };

// [eyeASL, targetASL or object, fov(0.75)] call vc_fnc_cam. Waits for streaming and LODs to settle.
vc_fnc_cam = {
    params ["_eye", "_target", ["_fov", 0.75], ["_settle", 1.5]];
    if (isNil "vc_cam" || {isNull vc_cam}) then { vc_cam = "camera" camCreate ASLToAGL _eye };
    // re-attach every call: a respawn or vehicle switch drops the camera effect
    vc_cam cameraEffect ["internal", "back"];
    showCinemaBorder false;
    private _to = if (_target isEqualType objNull) then { AGLToASL (_target modelToWorldVisual (boundingCenter _target)) } else { _target };
    vc_cam setPosASL _eye;
    [_eye] call vc_fnc_park;
    // up is world up made perpendicular to the view; looking straight down or up, north is up
    private _dir = vectorNormalized (_to vectorDiff _eye);
    private _side = _dir vectorCrossProduct [0, 0, 1];
    if (vectorMagnitude _side < 0.05) then { _side = _dir vectorCrossProduct [0, 1, 0] };
    vc_cam setVectorDirAndUp [_dir, vectorNormalized (_side vectorCrossProduct _dir)];
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

// Keeps the hidden player on dry land under the camera. A player in water drowns, and the engine
// blurs the view more and more even though damage is off.
vc_fnc_park = {
    params ["_pos"];
    if (vehicle player != player) exitWith {};
    _pos = [_pos select 0, _pos select 1, 0];
    if (surfaceIsWater _pos) then {
        private _land = [_pos, 0, 3000, 1, 0, 0.5, 0, [], [[], []]] call BIS_fnc_findSafePos;
        if (count _land == 2) then { _pos = _land + [0] } else { _pos = [] };
    };
    if (_pos isEqualTo []) exitWith {};
    // never inside the vehicle under test: a parked player pushed into it dies and respawns
    private _clear = _pos findEmptyPosition [0, 30, typeOf player];
    if (_clear isNotEqualTo []) then { _pos = _clear };
    player setPosATL _pos;
};

[] spawn {
    waitUntil { time > 0 && !isNull player };
    [getArray (configFile >> "CfgWorlds" >> worldName >> "centerPosition")] call vc_fnc_park;
    [] spawn { while { true } do { player setOxygenRemaining 1; uiSleep 1 } };
    showHUD [false, false, false, false, false, false, false, false];
    if (!isNil "uksf_screenshot_fnc_toggle") then { [false] call uksf_screenshot_fnc_toggle };
    clearRadio; enableRadio false; enableSentences false;
    player allowDamage false; player hideObject true;
    "start" call vc_fnc_log;
    private _err = [] execVM "test.sqf";
};
