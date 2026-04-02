private _player = (allPlayers - entities "HeadlessClient_F") select 0;
if (isNull _player) exitWith { diag_log "[TEST] No players connected" };

private _playerDirection = getDir _player;
private _vehiclePosition = _player getPos [500, _playerDirection];
private _rebroPosition = _player getPos [250, _playerDirection];


private _vehicle = createVehicle ["B_MRAP_01_F", _vehiclePosition, [], 0, "NONE"];
_vehicle setDir (_playerDirection + 180);
uksf_radios_testVehicle = _vehicle;
publicVariable "uksf_radios_testVehicle";
diag_log format ["[TEST] Vehicle created: %1 at %2", _vehicle, _vehiclePosition];


diag_log format ["[TEST] Calling addRackToVehicle, player for init: %1", _player];
[_vehicle, ["ACRE_VRC103", "Test", "Test", false, ["external"], [], "ACRE_PRC117F", [], []], true, {true}] call acre_api_fnc_addRackToVehicle;
diag_log "[TEST] addRackToVehicle returned";


private _box = createVehicle ["uksf_radios_rebroStationBox", _rebroPosition, [], 0, "NONE"];
_box setDir _playerDirection;
[_box] call uksf_radios_fnc_assembleRebroStation;
diag_log format ["[TEST] Rebro assembled at %1", _rebroPosition];


[{
    private _vehicle = uksf_radios_testVehicle;
    if (isNull _vehicle) exitWith { diag_log "[TEST-MONITOR] Vehicle is null!" };

    private _initialized = _vehicle getVariable ["acre_sys_rack_initialized", false];
    private _vehicleRacks = _vehicle getVariable ["acre_sys_rack_vehicleRacks", []];
    private _initPlayer = _vehicle getVariable ["acre_sys_rack_initPlayer", objNull];
    private _queue = _vehicle getVariable ["acre_sys_rack_queue", []];

    diag_log format ["[TEST-MONITOR] initialized=%1, racks=%2, initPlayer=%3 (local=%4), queue=%5",
        _initialized, _vehicleRacks, _initPlayer, local _initPlayer, _queue];

    if (_vehicleRacks isNotEqualTo []) then {
        {
            private _mountedRadio = [_x, "getState", "mountedRadio"] call acre_sys_data_fnc_dataEvent;
            private _radioData = acre_sys_data_radioData getVariable [_x, nil];
            diag_log format ["[TEST-MONITOR] Rack %1: mountedRadio=%2, hasRadioData=%3", _x, _mountedRadio, !isNil "_radioData"];
        } forEach _vehicleRacks;
    };

    private _rebroReady = uksf_radios_rebroStations findIf {_x isKindOf "uksf_radios_rebroStationMast"} != -1;
    diag_log format ["[TEST-MONITOR] rebroReady=%1, rebroStations=%2", _rebroReady, uksf_radios_rebroStations];

    if (_initialized && {_vehicleRacks isNotEqualTo []} && {_rebroReady}) then {
        diag_log "[TEST-MONITOR] Setup complete!";
        true
    } else {
        false
    };
}, {
    diag_log "[TEST-MONITOR] All done - run client script now";
}, [], 60, {
    diag_log "[TEST-MONITOR] TIMED OUT after 60s";
}] call CBA_fnc_waitUntilAndExecute;
