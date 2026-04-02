if (uksf_radios_testRebroPfhHandle != -1) exitWith {
    [uksf_radios_testRebroPfhHandle] call CBA_fnc_removePerFrameHandler;
    uksf_radios_testRebroPfhHandle = -1;
    uksf_radios_debugReportingEnabled = false;
    uksf_radios_rebroDebugging = false;
    hint "Test stopped";
};

private _vehicle = uksf_radios_testVehicle;
if (isNull _vehicle) exitWith { hint "No test vehicle - run server script first" };

private _playerRadios = [] call acre_api_fnc_getCurrentRadioList;
if (_playerRadios isEqualTo []) exitWith { hint "No ACRE radios found on player" };
private _playerRadioId = _playerRadios#0;

private _channelData = [_playerRadioId, "getCurrentChannelData"] call acre_sys_data_fnc_dataEvent;
private _frequency = _channelData getVariable ["frequencyTX", 0];
private _power = _channelData getVariable ["power", 0];
if (_frequency == 0) exitWith { hint "Could not get radio frequency data" };

diag_log format ["[TEST] Player radio: %1, frequency: %2, power: %3", _playerRadioId, _frequency, _power];

private _vehicleRacks = [_vehicle] call acre_api_fnc_getVehicleRacks;
diag_log format ["[TEST] Vehicle racks: %1", _vehicleRacks];

private _vehicleRadioId = "";
{
    private _radioId = [_x] call acre_api_fnc_getMountedRackRadio;
    diag_log format ["[TEST] Rack %1: mountedRadio=%2", _x, _radioId];
    if (!isNil "_radioId" && {_radioId isEqualType "" && {_radioId select [0, 15] == "acre_prc117f_id"}}) exitWith {
        _vehicleRadioId = _radioId;
    };
} forEach _vehicleRacks;

if (_vehicleRadioId == "") exitWith {
    hint "No PRC117F radio found in any rack";
    diag_log format ["[TEST] FAILED: no PRC117F in racks %1", _vehicleRacks];
};

private _rebroMast = objNull;
private _bestDistance = 1e10;
{
    if (_x isKindOf "uksf_radios_rebroStationMast") then {
        private _distance = _x distance2D _vehicle;
        if (_distance < _bestDistance) then {
            _bestDistance = _distance;
            _rebroMast = _x;
        };
    };
} forEach uksf_radios_rebroStations;

if (isNull _rebroMast) exitWith {
    hint "No rebro station found";
    diag_log format ["[TEST] FAILED: no rebro mast, stations: %1", uksf_radios_rebroStations];
};

uksf_radios_testRebroMast = _rebroMast;
uksf_radios_rebroDebugging = true;
uksf_radios_debugReportingEnabled = true;

diag_log format ["[TEST] Starting PFH. Vehicle radio: %1, player radio: %2, rebro: %3", _vehicleRadioId, _playerRadioId, _rebroMast];

uksf_radios_testRebroPfhHandle = [{
    params ["_args", "_idPFH"];
    _args params ["_frequency", "_power", "_vehicleRadioId", "_playerRadioId", "_vehicle"];
    if (!alive _vehicle) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        uksf_radios_testRebroPfhHandle = -1;
        uksf_radios_debugReportingEnabled = false;
        uksf_radios_rebroDebugging = false;
        hint "Test stopped - vehicle destroyed";
    };
    [_frequency, _power, _playerRadioId, _vehicleRadioId] call uksf_radios_fnc_handleCustomSignal;
}, 0, [_frequency, _power, _vehicleRadioId, _playerRadioId, _vehicle]] call CBA_fnc_addPerFrameHandler;

hint parseText format [
    "<t size='1.2' align='center'>Rebro Signal Test Running</t><br/><br/>" +
    "Player radio: %1<br/>Vehicle radio: %2<br/>Frequency: %3 MHz<br/>Rebro: %4<br/><br/>" +
    "<t color='#aaaaaa'>Run again to stop</t>",
    _playerRadioId, _vehicleRadioId, _frequency / 1e6, _rebroMast
];
