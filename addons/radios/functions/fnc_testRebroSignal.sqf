#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggle function for testing the rebro signal pipeline.
        Spawns a vehicle at distance with an ACRE rack radio, places a rebro station
        in between, then runs a PFH that continuously calls handleCustomSignal to
        exercise the full signal pipeline. Draws 3D visualisation of signal paths.
        Run again to stop and clean up.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_radios_fnc_testRebroSignal
*/

// Toggle off if already running
if (GVAR(testRebroPfhHandle) != -1) exitWith {
    [GVAR(testRebroPfhHandle)] call CBA_fnc_removePerFrameHandler;
    GVAR(testRebroPfhHandle) = -1;

    GVAR(debugReportingEnabled) = false;
    GVAR(rebroDebugging) = false;

    if (!isNull GVAR(testVehicle)) then {
        deleteVehicle GVAR(testVehicle);
    };

    if (!isNull GVAR(testRebroMast)) then {
        private _equipment = GVAR(testRebroMast) getVariable [QGVAR(rebroEquipment), objNull];
        [QGVAR(deinitialiseRebroStation), [GVAR(testRebroMast)]] call CBA_fnc_serverEvent;

        if (!isNull _equipment) then {
            private _objects = _equipment getVariable [QGVAR(rebroObjects), []];
            {deleteVehicle _x} forEach _objects;
            deleteVehicle _equipment;
        };
        deleteVehicle GVAR(testRebroMast);
    };

    GVAR(testVehicle) = objNull;
    GVAR(testRebroMast) = objNull;

    hint "Test stopped";
};

// Get player's first radio
private _playerRadios = [] call acre_api_fnc_getCurrentRadioList;
if (_playerRadios isEqualTo []) exitWith {
    hint "No ACRE radios found on player";
};
private _playerRadioId = _playerRadios#0;

// Get radio frequency and power from current channel
private _channelData = [_playerRadioId, "getCurrentChannelData"] call acre_sys_data_fnc_dataEvent;
private _frequency = _channelData getVariable ["frequencyTX", 0];
private _power = _channelData getVariable ["power", 0];

if (_frequency == 0) exitWith {
    hint "Could not get radio frequency data";
};

// Spawn vehicle 500m ahead of player on server, add ACRE rack with radio
private _playerDirection = getDir player;
private _vehiclePosition = player getPos [500, _playerDirection];
[{
    params ["_position", "_direction"];
    private _vehicle = createVehicle ["B_MRAP_01_F", _position, [], 0, "NONE"];
    _vehicle setDir _direction;
    missionNamespace setVariable [QGVAR(testVehicle), _vehicle, true];
    [_vehicle, ["ACRE_VRC103", "Test", "Test", false, ["external"], [], "ACRE_PRC117F", [], []], true, {true}] call acre_api_fnc_addRackToVehicle;
}, [_vehiclePosition, _playerDirection + 180]] remoteExec ["BIS_fnc_call", 2];

// Create rebro station box at 250m (halfway), then assemble it
private _rebroPosition = player getPos [250, _playerDirection];
private _box = createVehicle [QGVAR(rebroStationBox), _rebroPosition, [], 0, "NONE"];
_box setDir _playerDirection;
[_box] call FUNC(assembleRebroStation);

hint "Setting up test environment...";

// Wait for vehicle rack and rebro station to initialise
[{
    params ["_rebroPosition"];

    // Wait for server to broadcast the vehicle reference
    private _vehicle = GVAR(testVehicle);
    if (isNull _vehicle) exitWith {false};

    // Check vehicle has initialised racks with a mounted VRC103 radio
    private _vehicleReady = _vehicle getVariable ["acre_sys_rack_initialized", false]
        && {
            private _vehicleRacks = [_vehicle] call acre_api_fnc_getVehicleRacks;
            _vehicleRacks isEqualType [] && {
                _vehicleRacks findIf {
                    private _radioId = [_x] call acre_api_fnc_getMountedRackRadio;
                    !isNil "_radioId" && {_radioId isEqualType "" && {_radioId != "" && {_radioId select [0, 15] == "acre_prc117f_id"}}}
                } != -1
            }
        };

    // Check rebro station has initialised (a mast exists near the rebro position in rebroStations)
    private _rebroReady = GVAR(rebroStations) findIf {
        _x isKindOf QGVAR(rebroStationMast) && {_x distance2D _rebroPosition < 50}
    } != -1;

    _vehicleReady && _rebroReady
}, {
    params ["_rebroPosition", "_frequency", "_power", "_playerRadioId"];

    private _vehicle = GVAR(testVehicle);

    // Find the VRC103 rack with a mounted PRC117F radio
    private _vehicleRacks = [_vehicle] call acre_api_fnc_getVehicleRacks;
    private _vehicleRadioId = "";
    {
        private _radioId = [_x] call acre_api_fnc_getMountedRackRadio;
        if (!isNil "_radioId" && {_radioId isEqualType "" && {_radioId select [0, 15] == "acre_prc117f_id"}}) exitWith {
            _vehicleRadioId = _radioId;
        };
    } forEach _vehicleRacks;

    if (_vehicleRadioId == "") exitWith {
        hint "Failed to get vehicle radio ID";
        deleteVehicle _vehicle;
        GVAR(testVehicle) = objNull;
    };

    // Find the rebro mast
    private _rebroMast = objNull;
    private _bestDistance = 1e10;
    {
        if (_x isKindOf QGVAR(rebroStationMast)) then {
            private _distance = _x distance2D _rebroPosition;
            if (_distance < _bestDistance) then {
                _bestDistance = _distance;
                _rebroMast = _x;
            };
        };
    } forEach GVAR(rebroStations);

    GVAR(testRebroMast) = _rebroMast;

    // Enable debug
    GVAR(rebroDebugging) = true;
    GVAR(debugReportingEnabled) = true;

    // Start PFH — continuously pumps signal data through the pipeline
    GVAR(testRebroPfhHandle) = [{
        params ["_args", "_idPFH"];
        _args params ["_frequency", "_power", "_vehicleRadioId", "_playerRadioId", "_vehicle"];

        if (!alive _vehicle) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            GVAR(testRebroPfhHandle) = -1;
            GVAR(rebroDebugging) = false;
            GVAR(debugReportingEnabled) = false;
            hint "Test stopped - vehicle destroyed";
        };

        [_frequency, _power, _playerRadioId, _vehicleRadioId] call FUNC(handleCustomSignal);

    }, 0, [_frequency, _power, _vehicleRadioId, _playerRadioId, _vehicle]] call CBA_fnc_addPerFrameHandler;

    hint parseText format [
        "<t size='1.2' align='center'>Rebro Signal Test Running</t><br/><br/>" +
        "Player radio: %1<br/>" +
        "Vehicle radio: %2<br/>" +
        "Frequency: %3 MHz<br/><br/>" +
        "<t color='#aaaaaa'>Run again to stop</t>",
        _playerRadioId,
        _vehicleRadioId,
        _frequency / 1e6
    ];

}, [_rebroPosition, _frequency, _power, _playerRadioId], 30, {
    hint "Test setup timed out - cleaning up";

    if (!isNull GVAR(testVehicle)) then {
        deleteVehicle GVAR(testVehicle);
    };
    GVAR(testVehicle) = objNull;

    // Clean up any rebro objects that may have been created
    if (!isNull GVAR(testRebroMast)) then {
        private _equipment = GVAR(testRebroMast) getVariable [QGVAR(rebroEquipment), objNull];
        [QGVAR(deinitialiseRebroStation), [GVAR(testRebroMast)]] call CBA_fnc_serverEvent;
        if (!isNull _equipment) then {
            private _objects = _equipment getVariable [QGVAR(rebroObjects), []];
            {deleteVehicle _x} forEach _objects;
            deleteVehicle _equipment;
        };
        deleteVehicle GVAR(testRebroMast);
        GVAR(testRebroMast) = objNull;
    };
}] call CBA_fnc_waitUntilAndExecute;
