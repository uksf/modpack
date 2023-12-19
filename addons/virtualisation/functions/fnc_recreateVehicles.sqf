#include "script_component.hpp"
/*
    Author:
        Bridg, Tim Beswick

    Description:
        Recreates vehicles for a group

    Parameters:
        0: Group <SCALAR>
        1: Vehicle details <ARRAY>
        2: Completed callback <CODE>
        3: Callback args <ANY>

    Return value:
        Nothing
*/
#define SPAWN_DELAY 1
#define TIMEOUT 60

params ["_group", "_vehicleDetails", "_callback", "_callbackArgs"];

[{
    params ["_args", "_idPFH"];
    _args params ["_time", "_group", "_vehicleDetails", ["_currentVehicleData", []], "_callback", "_callbackArgs"];

    if (isNull _group) exitWith {
        TRACE_1("Group deleted whilst recreating vehicles",_group);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if ((_vehicleDetails isEqualTo [] && _currentVehicleData isEqualTo []) || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_1("All vehicles recreated, or timed out",_group);
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        _callbackArgs call _callback;
    };

    if (_currentVehicleData isEqualTo []) then {
        _currentVehicleData = _vehicleDetails deleteAt 0;
        _currentVehicleData params ["_type", "_position", "_direction", "_engineState", "_fuel"];

        private _vehicle = createVehicle [_type, [0,0,0], [], 0, "NONE"];
        _vehicle setDir _direction;
        _vehicle setPosASL _position;
        _vehicle setVectorUp (surfaceNormal (getPos _vehicle));
        _vehicle setFuel _fuel;
        _vehicle engineOn _engineState;
        _group addVehicle _vehicle;
        TRACE_2("Recreate vehicle created vehicle",_group,_vehicle);

        _currentVehicleData set [0, _vehicle];
        _args set [3, _currentVehicleData];
    };

    _currentVehicleData params ["_vehicle", "", "", "", "", "_crew"];
    if (_crew isEqualTo []) exitWith {
        TRACE_2("All units for vehicle recreated",_group,_vehicle);

        _args set [3, []];
    };

    TRACE_1("Current vehicle crew data",_crew);
    private _crewData = _crew deleteAt 0;
    _crewData params ["_crewType", "_role", "_cargoIndex", "_turretPath"];

    private _unit = _group createUnit [_crewType, [0,0,0], [], 0, "NONE"];

    switch (_role) do {
        case "driver": {
            _unit assignAsDriver _vehicle;
            _unit moveInDriver _vehicle;
        };
        case "commander": {
            _unit assignAsCommander _vehicle;
            _unit moveInCommander _vehicle;
        };
        case "gunner": {
            _unit assignAsGunner _vehicle;
            _unit moveInGunner _vehicle;
        };
        case "turret": {
            _unit assignAsTurret [_vehicle, _turretPath];
            _unit moveInTurret [_vehicle, _turretPath];
        };
        case "cargo": {
            _unit assignAsCargoIndex [_vehicle, _cargoIndex];
            _unit moveInCargo [_vehicle, _cargoIndex, true];
        };
        default {
            _unit assignAsCargo _vehicle;
            _unit moveInCargo _vehicle;
        };
    };

    // Fallback for units that haven't been moved inside the vehicle for whatever reason
    if (vehicle _unit != _vehicle) then {
        _unit setPos (getPos _vehicle);
    };
    TRACE_4("Recreate vehicle created crew",_group,_vehicle,_crewType,_role);

}, SPAWN_DELAY, [time, _group, _vehicleDetails, [], _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
