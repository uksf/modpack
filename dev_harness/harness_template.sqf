// Reusable air-to-air missile test harness skeleton.
// Replace <<SCENARIOS>>, <<LAUNCHER_TYPE>>, <<WEAPON>>, <<MAGAZINES>>, <<ITERATIONS>>, <<WAIT_S>> per run.
// All idioms baked in: lock injection, fired-EH global, AI gating, multi-mag fire fallback, sub-tick PFH, race-safe wrapper.

uksf_dev_resultPosted = true;
[] spawn {
    private _results = [];
    private _logs = [];
    private _fnLog = {
        params ['_msg'];
        _logs pushBack _msg;
        [_msg] call uksf_dev_fnc_logLine;
    };

    private _fnRun = {
        params ['_name', '_targetType', '_targetPos', '_targetDir', '_targetSpeed', '_launcherPos', '_launcherDir'];
        [format ['=== %1 ===', _name]] call _fnLog;

        private _grpL = createGroup [west, true];
        private _launcher = createVehicle ['<<LAUNCHER_TYPE>>', _launcherPos, [], 0, 'FLY'];
        _launcher setDir _launcherDir;
        _launcher setPosASL _launcherPos;
        _launcher setVelocity [sin _launcherDir * 250, cos _launcherDir * 250, 0];
        createVehicleCrew _launcher;
        (crew _launcher) joinSilent _grpL;
        private _pilot = driver _launcher;
        { _x disableAI 'TARGET'; _x disableAI 'AUTOTARGET'; _x disableAI 'AUTOCOMBAT' } forEach (crew _launcher);

        private _grpT = createGroup [east, true];
        private _target = createVehicle [_targetType, _targetPos, [], 0, 'FLY'];
        _target setDir _targetDir;
        _target setPosASL _targetPos;
        _target setVelocity [sin _targetDir * _targetSpeed, cos _targetDir * _targetSpeed, 0];
        createVehicleCrew _target;
        (crew _target) joinSilent _grpT;
        { _x disableAI 'TARGET'; _x disableAI 'AUTOTARGET'; _x disableAI 'AUTOCOMBAT' } forEach (crew _target);

        [format ['  spawn: launcher=%1 target=%2 dist=%3', alive _launcher, alive _target, (_launcher distance _target) toFixed 0]] call _fnLog;

        private _state = createHashMap;
        _state set ['minDist', 1e9];
        _state set ['hit', false];

        uksf_dev_probe_lastProj = objNull;
        _launcher addEventHandler ['Fired', {
            params ['', '', '', '', '', '', '_proj'];
            uksf_dev_probe_lastProj = _proj;
        }];

        [{
            params ['_args', '_pfh'];
            _args params ['_l', '_t', '_d', '_s', '_st'];
            if (isNull _l || !alive _l || isNull _t) exitWith { [_pfh] call CBA_fnc_removePerFrameHandler };
            _t setVelocity [sin _d * _s, cos _d * _s, 0];
            _l setDir _d;
            private _vel = velocity _l;
            _l setVelocity [sin _d * 250, cos _d * 250, _vel#2];
            private _proj = uksf_dev_probe_lastProj;
            if (!isNull _proj && alive _proj) then {
                private _md = _st get 'minDist';
                private _dd = _proj distance _t;
                if (_dd < _md) then { _st set ['minDist', _dd] };
            };
        }, 0.05, [_launcher, _target, _targetDir, _targetSpeed, _state]] call CBA_fnc_addPerFrameHandler;

        sleep 1.5;
        // Lock injection — pilot, all crew, launcher; ace + vanilla variant
        _pilot setVariable ['ace_missileguidance_target', _target];
        _pilot setVariable ['ace_missileguidance_vanilla_target', _target];
        _launcher setVariable ['ace_missileguidance_target', _target];
        {
            _x setVariable ['ace_missileguidance_target', _target];
            _x setVariable ['ace_missileguidance_vanilla_target', _target];
        } forEach (crew _launcher);
        sleep 0.5;

        // Multi-magazine fire fallback
        private _fired = false;
        private _mags = <<MAGAZINES>>; // e.g. ['rksla3_wpn_meteor_2x', 'rksla3_wpn_meteor']
        {
            if (!_fired) then {
                _launcher fire ['<<WEAPON>>', '<<WEAPON>>', _x];
                sleep 0.3;
                if (!isNull uksf_dev_probe_lastProj) then { _fired = true };
            };
        } forEach _mags;
        if (!_fired) then {
            _pilot fire ['<<WEAPON>>', '<<WEAPON>>', _mags select 0];
            sleep 0.3;
            if (!isNull uksf_dev_probe_lastProj) then { _fired = true };
        };
        if (!_fired) then { ['  FIRE FAILED'] call _fnLog };

        private _initDmg = damage _target;
        private _t0 = diag_tickTime;
        while { (diag_tickTime - _t0) < <<WAIT_S>> && alive _target } do {
            private _proj = uksf_dev_probe_lastProj;
            if (!isNull _proj && !alive _proj) exitWith {};
            sleep 0.2;
        };
        sleep 1.5;

        private _finalDmg = damage _target;
        private _killed = !alive _target || _finalDmg >= 0.9;
        private _minDist = _state get 'minDist';

        [format ['  result: minDist=%1 dmg=%2 killed=%3 fired=%4', _minDist toFixed 1, _finalDmg toFixed 2, _killed, _fired]] call _fnLog;
        _results pushBack createHashMapFromArray [
            ['name', _name],
            ['minDist', _minDist],
            ['dmgDelta', _finalDmg - _initDmg],
            ['killed', _killed],
            ['fired', _fired]
        ];

        deleteVehicle _target;
        deleteVehicle _launcher;
        sleep 1;
    };

    // <<SCENARIOS>> — array of [name, targetType, targetPos, targetDir, targetSpeed, launcherPos, launcherDir]
    private _scenarios = <<SCENARIOS>>;

    for '_runIdx' from 1 to <<ITERATIONS>> do {
        {
            _x params ['_n', '_tt', '_tp', '_td', '_ts', '_lp', '_ld'];
            [format ['%1#%2', _n, _runIdx], _tt, _tp, _td, _ts, _lp, _ld] call _fnRun;
        } forEach _scenarios;
        [format ['== runIdx %1 complete ==', _runIdx]] call _fnLog;
    };

    [createHashMapFromArray [['results', _results], ['logs', _logs]]] call uksf_dev_fnc_postResult;
};
