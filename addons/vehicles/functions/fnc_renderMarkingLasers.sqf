#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame handler that draws the ACE IR marking laser for vehicle turrets without a laser designator.
        Draws only while the local camera is in night vision. Uses ACE's laser mode, flash cycle and beam style.
        The gunner looking through the sight gets the sight direction, so the beam holds on the reticle.
        Other viewers get the gun direction averaged over five frames, as ACE does for aircraft.
        Removes itself when no registered vehicle remains.

    Parameter(s):
        0: Arguments, unused <ARRAY>
        1: Handler ID <NUMBER>

    Return Value:
        None

    Example:
        [uksf_vehicles_fnc_renderMarkingLasers, 0] call CBA_fnc_addPerFrameHandler
*/
#define LASER_MAX 3000
#define MODE_OFF 0
#define MODE_FLASH 2

params ["", "_handle"];

GVAR(markingLasers) = GVAR(markingLasers) select {!isNull _x};
if (GVAR(markingLasers) isEqualTo []) exitWith {
    [_handle] call CBA_fnc_removePerFrameHandler;
    GVAR(markingLaserHandle) = -1;
};
if (currentVisionMode focusOn != 1) exitWith {};

{
    private _mode = _x getVariable ["ace_markinglaser_laserMode", MODE_OFF];
    if (_mode == MODE_OFF || {!alive _x}) then { continue };
    if (_mode == MODE_FLASH && {(CBA_missionTime % (1/3)) > 1/6}) then { continue };

    (GVAR(markingLaserClasses) get typeOf _x) params ["_turret", "", "_optics", "_muzzle", "_breech"];
    private _gunner = _x turretUnit _turret;
    if (isNull _gunner) then { continue };

    private _origin = _x modelToWorldVisualWorld (_x selectionPosition _optics);
    private _direction = if (_gunner == focusOn && {cameraOn == _x} && {cameraView == "GUNNER"}) then {
        (AGLToASL positionCameraToWorld [0, 0, 0]) vectorFromTo (AGLToASL positionCameraToWorld [0, 0, 1000])
    } else {
        (_x getVariable [QGVAR(markingLaserHistory), [-1, []]]) params ["_lastFrame", "_history"];
        if (_lastFrame != diag_frameNo - 1) then { _history = [] };
        _history pushBack vectorNormalized ((_x modelToWorldVisualWorld (_x selectionPosition _muzzle)) vectorDiff (_x modelToWorldVisualWorld (_x selectionPosition _breech)));
        if (count _history > 5) then { _history deleteAt 0 };
        _x setVariable [QGVAR(markingLaserHistory), [diag_frameNo, _history]];
        private _sum = [0, 0, 0];
        { _sum = _sum vectorAdd _x } forEach _history;
        vectorNormalized _sum
    };
    drawLaser [_origin vectorAdd (_direction vectorMultiply 0.25), _direction, [250, 0, 0, 1], [], 0.5, 1, LASER_MAX, true];
} forEach GVAR(markingLasers);
