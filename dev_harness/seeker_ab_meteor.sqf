// Meteor dual-mode A/B:
//   slots 0-2 OPEN HOLD: target stays visible, wingman nearby -> expect target
//   slots 3-5 HIDE REACQUIRE: target hides in WIP mid-flight -> expect wingman
// 3 volleys x 6 = 18 shots. VR.
uksf_dev_resultPosted = true;
[] spawn {
    private _results = [];
    private _logs = [];
    private _fnLog = { params ['_m']; _logs pushBack _m; [_m] call uksf_dev_fnc_logLine; };

    private _wipType = 'Land_WIP_F';
    private _heloType = 'O_Heli_Light_02_F';
    private _launcherType = 'uksf_air_f35_raf';
    private _weapon = 'rksla3_wpn_meteor';

    for '_v' from 1 to 3 do {
        [format ['=== volley %1 ===', _v]] call _fnLog;
        private _slots = [];
        private _cleanup = [];

        for '_i' from 0 to 5 do {
            private _hide = _i >= 3;
            private _mode = if (_hide) then { 'hide' } else { 'open' };
            private _cx = 1000 + _i * 500;
            private _range = 15000;

            private _grpT = createGroup [east, true];
            private _grpL = createGroup [west, true];

            private _wip = objNull;
            if (_hide) then {
                _wip = createVehicle [_wipType, [_cx, 6500, 0], [], 0, 'NONE'];
                _wip setDir (30 + 20 * _i);
                _cleanup pushBack _wip;
            };

            private _target = createVehicle [_heloType, [_cx, 6200, 50], [], 0, 'FLY'];
            _target setPosASL [_cx, 6200, 50];
            createVehicleCrew _target;
            (crew _target) joinSilent _grpT;
            { _x disableAI 'ALL' } forEach (crew _target);
            _target allowDamage false;
            _target engineOn true;

            private _wingPos = if (_hide) then { [_cx + 15, 6490, 20] } else { [_cx + 25, 6220, 50] };
            private _wingman = createVehicle [_heloType, _wingPos, [], 0, 'FLY'];
            _wingman setPosASL _wingPos;
            createVehicleCrew _wingman;
            (crew _wingman) joinSilent _grpT;
            { _x disableAI 'ALL' } forEach (crew _wingman);
            _wingman allowDamage false;
            _wingman engineOn true;

            private _launcherPos = [_cx, 6200 - _range, 2500];
            private _launcher = createVehicle [_launcherType, _launcherPos, [], 0, 'FLY'];
            _launcher setPosASL _launcherPos;
            _launcher setDir 0;
            _launcher setVelocity [0, 300, 0];
            createVehicleCrew _launcher;
            (crew _launcher) joinSilent _grpL;
            { _x disableAI 'TARGET'; _x disableAI 'AUTOTARGET'; _x disableAI 'AUTOCOMBAT' } forEach (crew _launcher);
            { _launcher setPylonLoadout [_x, 'rksla3_mag_meteor_directx1', true] } forEach [4, 7];

            private _state = createHashMapFromArray [
                ['slot', _i], ['mode', _mode], ['hide', _hide], ['range', _range], ['volley', _v],
                ['launcher', _launcher], ['target', _target], ['distractor', _wingman],
                ['proj', objNull], ['events', []], ['lastMT', objNull], ['explodePos', []],
                ['fired', false], ['hoverAlt', 50]
            ];
            _launcher setVariable ['uksf_ab_state', _state];

            _launcher addEventHandler ['Fired', {
                params ['_unit', '', '', '', '', '', '_proj'];
                private _st = _unit getVariable 'uksf_ab_state';
                _st set ['proj', _proj];
                _st set ['fired', true];
                _proj setVariable ['uksf_ab_state', _st];
                _proj addEventHandler ['Explode', {
                    params ['_p', '_pos', ''];
                    private _st2 = _p getVariable ['uksf_ab_state', createHashMap];
                    _st2 set ['explodePos', _pos];
                }];
            }];

            _slots pushBack _state;
            _cleanup append [_target, _wingman, _launcher];
        };

        [format ['volley %1 spawned', _v]] call _fnLog;

        private _pfh = [{
            params ['_a', '_h'];
            _a params ['_sl'];
            {
                private _l = _x get 'launcher';
                if (!isNull _l && {alive _l}) then {
                    _l setVelocity [0, 300, (2500 - ((getPosASL _l) select 2)) * 0.5];
                };
                private _t = _x get 'target';
                if (!isNull _t && {alive _t} && {(_x get 'hoverAlt') > 2}) then {
                    private _ha = _x get 'hoverAlt';
                    _t setVelocity [0, 0, (_ha - ((getPosASL _t) select 2)) * 0.5];
                };
                private _p = _x get 'proj';
                if (!isNull _p && {alive _p}) then {
                    private _mt = missileTarget _p;
                    private _last = _x get 'lastMT';
                    if (_mt isNotEqualTo _last) then {
                        (_x get 'events') pushBack (format ['t=%1 %2>%3 dtg=%4',
                            CBA_missionTime toFixed 1,
                            if (isNull _last) then { 'null' } else { typeOf _last },
                            if (isNull _mt) then { 'null' } else { typeOf _mt },
                            (_p distance (_x get 'target')) toFixed 0]);
                        _x set ['lastMT', _mt];
                    };
                };
            } forEach _sl;
        }, 0.05, [_slots]] call CBA_fnc_addPerFrameHandler;

        sleep 2;

        {
            private _st = _x;
            private _l = _st get 'launcher';
            private _t = _st get 'target';
            private _pilot = driver _l;
            _pilot setVariable ['ace_missileguidance_target', _t];
            _pilot setVariable ['ace_missileguidance_vanilla_target', _t];
            _l setVariable ['ace_missileguidance_target', _t];
            _l setVariable ['ace_missileguidance_vanilla_target', _t];
            { _x setVariable ['ace_missileguidance_target', _t]; _x setVariable ['ace_missileguidance_vanilla_target', _t] } forEach (crew _l);
            _l fireAtTarget [_t, _weapon];
            sleep 0.4;
            if (!(_st get 'fired')) then {
                _l fire [_weapon, _weapon, 'rksla3_mag_meteor_directx1'];
                sleep 0.3;
            };
            if (!(_st get 'fired')) then {
                _l fire [_weapon, _weapon, 'rksla3_mag_meteor_lau127x1'];
                sleep 0.3;
            };
            [format ['  slot %1 mode=%2 fired=%3', _st get 'slot', _st get 'mode', _st get 'fired']] call _fnLog;
        } forEach _slots;

        sleep 8;

        {
            private _st = _x;
            if (_st get 'hide') then {
                private _t = _st get 'target';
                _t setPosATL [(getPosATL _t) select 0, 6500, 1];
                _t setVelocity [0, 0, 0];
                _st set ['hoverAlt', 0];
            };
        } forEach _slots;
        ['  hide applied (hide slots only)'] call _fnLog;

        private _waitT = diag_tickTime;
        waitUntil {
            sleep 2;
            private _open = _slots select {
                private _p = _x get 'proj';
                (_x get 'fired') && { count (_x get 'explodePos') == 0 } && { !isNull _p }
            };
            (count _open == 0) || { (diag_tickTime - _waitT) > 55 }
        };

        sleep 2;
        [_pfh] call CBA_fnc_removePerFrameHandler;

        {
            private _st = _x;
            private _ep = _st get 'explodePos';
            private _outcome = 'noexplode';
            private _dT = -1;
            private _dD = -1;
            if (!(_st get 'fired')) then { _outcome = 'nofire' };
            if (count _ep > 0) then {
                _dT = _ep distance (_st get 'target');
                _dD = _ep distance (_st get 'distractor');
                _outcome = if (_dT < _dD) then { 'target' } else { 'distractor' };
            };
            _results pushBack createHashMapFromArray [
                ['volley', _st get 'volley'], ['slot', _st get 'slot'], ['mode', _st get 'mode'],
                ['range', _st get 'range'], ['fired', _st get 'fired'], ['outcome', _outcome],
                ['distToTarget', _dT], ['distToDistractor', _dD],
                ['events', _st get 'events'],
                ['finalMT', if (isNull (_st get 'lastMT')) then { 'null' } else { typeOf (_st get 'lastMT') }]
            ];
            [format ['  slot %1 mode=%2 outcome=%3 dT=%4 dD=%5 events=[%6]',
                _st get 'slot', _st get 'mode', _outcome, _dT toFixed 1, _dD toFixed 1,
                (_st get 'events') joinString ' | ']] call _fnLog;
        } forEach _slots;

        { deleteVehicle _x } forEach _cleanup;
        { deleteVehicle (_x get 'proj') } forEach _slots;
        { deleteVehicle _x } forEach allUnits;
        sleep 2;
        [format ['=== volley %1 done ===', _v]] call _fnLog;
    };

    [createHashMapFromArray [['results', _results], ['logs', _logs]]] call uksf_dev_fnc_postResult;
};
