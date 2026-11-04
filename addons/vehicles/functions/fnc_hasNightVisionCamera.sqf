#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether the seat the player looks from, their own or the UAV role they
        control, has optics with a night vision mode: an aircraft pilot camera, driver
        optics, or turret optics (OpticsIn or ViewOptics). Seats that only see through the
        player's own NVG goggles, such as door gunners, and thermal-only sights return false.
        Results are cached per vehicle class and seat.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Night vision camera available <BOOL>

    Example:
        [cameraOn] call uksf_vehicles_fnc_hasNightVisionCamera
*/
params ["_vehicle"];

if (isNull _vehicle || {_vehicle isKindOf "CAManBase"}) exitWith {false};

private _unit = [focusOn, ACE_player] select (_vehicle == vehicle ACE_player);
private _turret = _vehicle unitTurret _unit;
if (_turret isEqualTo []) exitWith {false};

private _type = typeOf _vehicle;
GVAR(nightVisionCameraCache) getOrDefaultCall [[_type, _turret], {
    private _vehicleConfig = configOf _vehicle;
    private _modes = [];
    if (_turret isEqualTo [-1]) then {
        if (_vehicle isKindOf "Air") then {
            {
                _modes append getArray (_x >> "visionMode");
            } forEach ("true" configClasses (_vehicleConfig >> "pilotCamera" >> "OpticsIn"));
        } else {
            _modes append getArray (_vehicleConfig >> "ViewOptics" >> "visionMode");
        };
    } else {
        private _turretConfig = [_type, _turret] call BIS_fnc_turretConfig;
        _modes append getArray (_turretConfig >> "ViewOptics" >> "visionMode");
        {
            _modes append getArray (_x >> "visionMode");
        } forEach ("true" configClasses (_turretConfig >> "OpticsIn"));
    };
    (_modes findIf {_x == "NVG"}) != -1
}, true]
