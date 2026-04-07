#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Called during client sync to flush the sampler series arrays as a single
        samplerBatch event, then reset them. Skips emission entirely if all
        three series are empty (e.g. fresh mission with no ticks yet).

    Parameters:
        None

    Return Value:
        None
*/
private _onFoot = GVAR(samplerDistanceOnFoot);
private _inVehicle = GVAR(samplerDistanceInVehicle);
private _fuel = GVAR(samplerFuelLitres);

if (_onFoot isEqualTo [] && {_inVehicle isEqualTo []} && {_fuel isEqualTo []}) exitWith {};

[createHashMapFromArray [
    ["type", "samplerBatch"],
    ["distanceOnFoot", +_onFoot],
    ["distanceInVehicle", +_inVehicle],
    ["fuelLitres", +_fuel]
]] call FUNC(addEvent);

GVAR(samplerDistanceOnFoot) = [];
GVAR(samplerDistanceInVehicle) = [];
GVAR(samplerFuelLitres) = [];
