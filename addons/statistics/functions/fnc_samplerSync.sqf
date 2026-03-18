#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Called during client sync to emit accumulated distance and fuel events,
        then reset the accumulators.

    Parameters:
        None

    Return Value:
        None
*/
if (GVAR(accumulatedDistanceOnFoot) > 0) then {
    [createHashMapFromArray [
        ["type", "distanceOnFoot"],
        ["metres", round GVAR(accumulatedDistanceOnFoot)]
    ]] call FUNC(addEvent);
    GVAR(accumulatedDistanceOnFoot) = 0;
};

if (GVAR(accumulatedDistanceInVehicle) > 0) then {
    [createHashMapFromArray [
        ["type", "distanceInVehicle"],
        ["metres", round GVAR(accumulatedDistanceInVehicle)]
    ]] call FUNC(addEvent);
    GVAR(accumulatedDistanceInVehicle) = 0;
};

if (GVAR(accumulatedFuel) > 0 && {!isNull GVAR(lastFuelVehicle)}) then {
    [createHashMapFromArray [
        ["type", "fuelConsumed"],
        ["amount", GVAR(accumulatedFuel)],
        ["vehicleClassname", typeOf GVAR(lastFuelVehicle)]
    ]] call FUNC(addEvent);
    GVAR(accumulatedFuel) = 0;
};
