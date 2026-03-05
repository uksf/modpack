#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sampler provider setup. Starts a PFH that runs every 10 seconds to sample:
        - Player position for distance tracking (accumulated metres)
        - Vehicle fuel level for fuel consumption tracking
        - diag_fps for FPS tracking

        Distance and fuel are accumulated between syncs and emitted as events
        during client sync. FPS is emitted as an event each sample.

    Parameters:
        None

    Return Value:
        None
*/
GVAR(lastPosition) = getPosATL player;

GVAR(samplerPFH) = [{
    private _startTime = diag_tickTime;

    // Distance tracking
    private _currentPosition = getPosATL player;
    private _distanceMoved = GVAR(lastPosition) distance _currentPosition;

    // Filter out teleports (e.g. respawn, parachute insertion) — threshold 500m in 10s
    if (_distanceMoved < 500) then {
        GVAR(accumulatedDistance) = GVAR(accumulatedDistance) + _distanceMoved;
    };
    GVAR(lastPosition) = _currentPosition;

    // Fuel tracking
    private _vehicle = vehicle player;
    if (_vehicle isNotEqualTo player) then {
        private _currentFuel = fuel _vehicle;
        if (_vehicle isEqualTo GVAR(lastFuelVehicle) && {GVAR(lastFuelLevel) >= 0}) then {
            private _fuelConsumed = GVAR(lastFuelLevel) - _currentFuel;
            if (_fuelConsumed > 0) then {
                GVAR(accumulatedFuel) = GVAR(accumulatedFuel) + _fuelConsumed;
            };
        };
        GVAR(lastFuelLevel) = _currentFuel;
        GVAR(lastFuelVehicle) = _vehicle;
    } else {
        // Not in vehicle — reset tracking
        GVAR(lastFuelLevel) = -1;
        GVAR(lastFuelVehicle) = objNull;
    };

    // FPS sample — emit directly as event
    [createHashMapFromArray [
        ["type", "fps"],
        ["value", round diag_fps]
    ]] call FUNC(addEvent);

    ["sampler", _startTime] call FUNC(addProviderTiming);
}, 10, []] call CBA_fnc_addPerFrameHandler;
