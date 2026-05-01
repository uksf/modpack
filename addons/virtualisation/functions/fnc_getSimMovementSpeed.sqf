#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Computes composition-based movement speed in m/s for a virtualised group.
        Mixed infantry + vehicle groups are infantry-paced (dismounts can't keep up).
        Pure vehicle groups use the slowest vehicle's maxSpeed x cruise factor (convoy speed).
        Called once per group at virtualisation time.

    Parameter(s):
        0: Side <SIDE>
        1: Vehicle details <ARRAY> (output of fnc_getVehicleDetails)
        2: Infantry details <ARRAY> (output of fnc_getInfantryDetails — already excludes crewed-in-vic units)

    Return Value:
        Base movement speed in m/s <NUMBER>

    Example:
        [_side, _vehicleDetails, _infantryDetails] call uksf_virtualisation_fnc_getSimMovementSpeed
*/
params ["_side", "_vehicleDetails", "_infantryDetails"];

private _hasInfantry = _infantryDetails isNotEqualTo [];
private _hasVehicles = _vehicleDetails isNotEqualTo [];

if (_hasInfantry || !_hasVehicles) exitWith { INFANTRY_BASE_MS };

private _baseKph = 999;
{
    private _maxKph = getNumber (configFile >> "CfgVehicles" >> (_x#0) >> "maxSpeed");
    if (_maxKph > 0 && _maxKph < _baseKph) then { _baseKph = _maxKph };
} forEach _vehicleDetails;

if (_baseKph >= 999) exitWith { INFANTRY_BASE_MS };

(_baseKph / 3.6) * VEHICLE_CRUISE_FACTOR
