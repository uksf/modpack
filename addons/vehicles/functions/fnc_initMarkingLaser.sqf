#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gives a ground vehicle or boat the ACE IR marking laser when ACE finds a suitable turret.
        ACE's own turret rule decides. Classes without one are skipped quietly and cached.
        ACE only draws the beam while a laser designator lases, so a turret without a designator
        is added to the UKSF beam renderer on each client instead.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None

    Example:
        [vehicle player] call uksf_vehicles_fnc_initMarkingLaser
*/
params ["_vehicle"];

private _laser = GVAR(markingLaserClasses) getOrDefaultCall [typeOf _vehicle, {
    ([configOf _vehicle] call ace_markinglaser_fnc_findTurret) params [["_turret", []], ["_config", configNull]];
    if (_turret isEqualTo []) exitWith {[]};
    private _hasDesignator = (getArray (_config >> "weapons")) findIf {getNumber (configFile >> "CfgWeapons" >> _x >> "laser") == 1} != -1;
    private _muzzle = getText (_config >> "gunBeg");
    private _optics = getText (_config >> "memoryPointGunnerOptics");
    [_turret, _hasDesignator, [_optics, _muzzle] select (_optics isEqualTo ""), _muzzle, getText (_config >> "gunEnd")]
}, true];

if (_laser isEqualTo []) exitWith {};
[_vehicle] call ace_markinglaser_fnc_onAircraftInit;

if (!hasInterface || {_laser#1}) exitWith {};
GVAR(markingLasers) pushBack _vehicle;
if (GVAR(markingLaserHandle) == -1) then {
    GVAR(markingLaserHandle) = [FUNC(renderMarkingLasers), 0] call CBA_fnc_addPerFrameHandler;
};
