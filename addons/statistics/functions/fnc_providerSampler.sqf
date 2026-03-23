#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sampler provider setup. Starts a PFH that runs every 10 seconds to sample:
        - Player position for distance tracking (on foot vs in vehicle, accumulated metres)
        - Vehicle fuel level for fuel consumption tracking

        Distance and fuel are accumulated between syncs and emitted as events
        during client sync.

    Parameters:
        None

    Return Value:
        None
*/
GVAR(lastPosition) = getPosATL player;

GVAR(samplerPFH) = [{
    private _startTime = diag_tickTime;

    // Distance tracking — split by on foot vs in vehicle
    private _currentPosition = getPosATL player;
    private _distanceMoved = GVAR(lastPosition) distance _currentPosition;

    // Filter out teleports (e.g. respawn, parachute insertion) — threshold 500m in 10s
    if (_distanceMoved < 500) then {
        private _currentVehicle = vehicle player;
        if (_currentVehicle isEqualTo player) then {
            GVAR(accumulatedDistanceOnFoot) = GVAR(accumulatedDistanceOnFoot) + _distanceMoved;
        } else {
            GVAR(accumulatedDistanceInVehicle) = GVAR(accumulatedDistanceInVehicle) + _distanceMoved;
        };
    };
    GVAR(lastPosition) = _currentPosition;

    // Fuel tracking
    private _currentVehicle = vehicle player;
    if (_currentVehicle isNotEqualTo player) then {
        private _currentFuel = fuel _currentVehicle;
        if (_currentVehicle isEqualTo GVAR(lastFuelVehicle) && {GVAR(lastFuelLevel) >= 0}) then {
            private _fuelConsumed = GVAR(lastFuelLevel) - _currentFuel;
            if (_fuelConsumed > 0) then {
                GVAR(accumulatedFuel) = GVAR(accumulatedFuel) + _fuelConsumed;
            };
        };
        GVAR(lastFuelLevel) = _currentFuel;
        GVAR(lastFuelVehicle) = _currentVehicle;
    } else {
        GVAR(lastFuelLevel) = -1;
        GVAR(lastFuelVehicle) = objNull;
    };

    ["sampler", _startTime] call FUNC(addProviderTiming);
}, 10, []] call CBA_fnc_addPerFrameHandler;
