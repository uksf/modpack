#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gives a ground vehicle or boat the ACE IR marking laser when ACE finds a suitable turret.
        ACE's own turret rule decides. Classes without one are skipped quietly and cached.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None

    Example:
        [vehicle player] call uksf_vehicles_fnc_initMarkingLaser
*/
params ["_vehicle"];

if (GVAR(markingLaserClasses) getOrDefaultCall [typeOf _vehicle, {
    ([configOf _vehicle] call ace_markinglaser_fnc_findTurret) isNotEqualTo []
}, true]) then {
    [_vehicle] call ace_markinglaser_fnc_onAircraftInit;
};
