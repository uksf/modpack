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
private _frequency = _channelData getOrDefault ["frequencyTX", 0];
private _power = _channelData getOrDefault ["power", 0];

if (_frequency == 0) exitWith {
    hint "Could not get radio frequency data";
};

// Spawn vehicle 500m ahead of player
private _playerDirection = getDir player;
private _vehiclePosition = player getPos [500, _playerDirection];
private _vehicle = createVehicle ["B_MRAP_01_F", _vehiclePosition, [], 0, "NONE"];
_vehicle setDir (_playerDirection + 180);
GVAR(testVehicle) = _vehicle;

// Add ACRE rack with radio to the test vehicle
[_vehicle, ["ACRE_VRC103", "Test", "Test", false, ["external"], [], "ACRE_PRC117F", [], []], true] call acre_api_fnc_addRackToVehicle;

// Create rebro station box at 250m (halfway), then assemble it
private _rebroPosition = player getPos [250, _playerDirection];
private _box = createVehicle [QGVAR(rebroStationBox), _rebroPosition, [], 0, "NONE"];
_box setDir _playerDirection;
[_box] call FUNC(assembleRebroStation);

hint "Setting up test environment...";

// Wait for vehicle rack and rebro station to initialise
[{
    params ["_vehicle", "_rebroPosition"];

    // Check vehicle has initialised racks with a mounted radio
    private _vehicleReady = _vehicle getVariable ["acre_sys_rack_initialized", false]
        && {
            private _vehicleRacks = [_vehicle] call acre_api_fnc_getVehicleRacks;
            _vehicleRacks isEqualType [] && {count _vehicleRacks > 0} && {
                private _radioId = [_vehicleRacks#0] call acre_api_fnc_getMountedRackRadio;
                !isNil "_radioId" && {_radioId isEqualType "" && {_radioId != ""}}
            }
        };

    // Check rebro station has initialised (a mast exists near the rebro position in rebroStations)
    private _rebroReady = GVAR(rebroStations) findIf {
        _x isKindOf QGVAR(rebroStationMast) && {_x distance2D _rebroPosition < 50}
    } != -1;

    _vehicleReady && _rebroReady
}, {
    params ["_vehicle", "_rebroPosition", "_frequency", "_power", "_playerRadioId"];

    // Get vehicle radio ID
    private _vehicleRacks = [_vehicle] call acre_api_fnc_getVehicleRacks;
    private _vehicleRadioId = [_vehicleRacks#0] call acre_api_fnc_getMountedRackRadio;

    if (isNil "_vehicleRadioId" || {!(_vehicleRadioId isEqualType "")} || {_vehicleRadioId == ""}) exitWith {
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
        params ["_args"];
        _args params ["_frequency", "_power", "_vehicleRadioId", "_playerRadioId", "_vehicle"];

        if (!alive _vehicle) exitWith {
            [] call FUNC(testRebroSignal);
        };

        [_frequency, _power, _vehicleRadioId, _playerRadioId] call FUNC(handleCustomSignal);

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

}, [_vehicle, _rebroPosition, _frequency, _power, _playerRadioId], 30, {
    hint "Test setup timed out - cleaning up";

    params ["_vehicle"];
    if (!isNull _vehicle) then {
        deleteVehicle _vehicle;
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
