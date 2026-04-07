#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sampler provider setup. Starts a PFH that runs every 10 seconds to sample:
        - Player position for distance tracking (on foot vs in vehicle, metres per tick)
        - Vehicle fuel level converted to litres consumed per tick

        Each tick result is appended to a per-metric flat array via the
        sampledSeriesAppend helper, which gap-compacts trailing zero runs.
        The arrays are flushed by samplerSync as a single samplerBatch event.

    Parameters:
        None

    Return Value:
        None
*/
GVAR(lastPosition) = getPosATL player;
GVAR(samplerInitialized) = false;

GVAR(samplerPFH) = [{
    private _startTime = diag_tickTime;
    private _currentPosition = getPosATL player;
    private _currentVehicle = vehicle player;

    if (!GVAR(samplerInitialized)) exitWith {
        GVAR(lastPosition) = _currentPosition;
        GVAR(samplerInitialized) = true;
        ["sampler", _startTime] call FUNC(addProviderTiming);
    };

    private _distanceMoved = GVAR(lastPosition) distance _currentPosition;
    GVAR(lastPosition) = _currentPosition;

    private _onFootTick = 0;
    private _inVehicleTick = 0;
    if (_currentVehicle isEqualTo player) then {
        if (_distanceMoved <= 100) then { _onFootTick = round _distanceMoved };
    } else {
        _inVehicleTick = round _distanceMoved;
    };

    [GVAR(samplerDistanceOnFoot), _onFootTick] call EFUNC(common,sampledSeriesAppend);
    [GVAR(samplerDistanceInVehicle), _inVehicleTick] call EFUNC(common,sampledSeriesAppend);

    private _fuelTick = 0;
    if (_currentVehicle isNotEqualTo player) then {
        private _typeOf = typeOf _currentVehicle;
        private _capacity = [
            format ["fuelTank_%1", _typeOf],
            {
                private _aceConfig = configFile >> "CfgVehicles" >> _typeOf >> "ace_refuel_fuelCapacity";
                if (getNumber _aceConfig > 0) exitWith {_aceConfig};
                configFile >> "CfgVehicles" >> _typeOf >> "fuelCapacity"
            },
            0
        ] call EFUNC(common,readCacheValues);
        if (_capacity > 0) then {
            private _currentFuel = fuel _currentVehicle;
            if (_currentVehicle isEqualTo GVAR(lastFuelVehicle) && {GVAR(lastFuelLevel) >= 0}) then {
                private _fractionConsumed = GVAR(lastFuelLevel) - _currentFuel;
                if (_fractionConsumed > 0) then {
                    _fuelTick = round (_fractionConsumed * _capacity);
                };
            };
            GVAR(lastFuelLevel) = _currentFuel;
            GVAR(lastFuelVehicle) = _currentVehicle;
        } else {
            GVAR(lastFuelLevel) = -1;
            GVAR(lastFuelVehicle) = objNull;
        };
    } else {
        GVAR(lastFuelLevel) = -1;
        GVAR(lastFuelVehicle) = objNull;
    };

    [GVAR(samplerFuelLitres), _fuelTick] call EFUNC(common,sampledSeriesAppend);

    ["sampler", _startTime] call FUNC(addProviderTiming);
}, 10, []] call CBA_fnc_addPerFrameHandler;
