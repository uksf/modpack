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
GVAR(samplerInitialized) = false;

GVAR(samplerPFH) = [{
    private _startTime = diag_tickTime;
    private _currentPosition = getPosATL player;
    private _currentVehicle = vehicle player;

    // Anchor first tick without accumulating — player may not be at mission slot yet
    if (!GVAR(samplerInitialized)) exitWith {
        GVAR(lastPosition) = _currentPosition;
        GVAR(samplerInitialized) = true;
        ["sampler", _startTime] call FUNC(addProviderTiming);
    };

    private _distanceMoved = GVAR(lastPosition) distance _currentPosition;
    GVAR(lastPosition) = _currentPosition;

    // On foot capped at 100m/tick to filter teleports; in-vehicle trusted for fast jets
    if (_currentVehicle isEqualTo player) then {
        if (_distanceMoved <= 100) then {
            GVAR(accumulatedDistanceOnFoot) = GVAR(accumulatedDistanceOnFoot) + _distanceMoved;
        };
    } else {
        GVAR(accumulatedDistanceInVehicle) = GVAR(accumulatedDistanceInVehicle) + _distanceMoved;
    };

    // Fuel tracking
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
