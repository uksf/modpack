#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the Zeus over-the-shoulder Watch on a selected unit or vehicle.
        The curator camera is locked to a fixed offset behind the target each
        frame. Standard Zeus camera input (WASD movement, RMB drag rotation)
        breaks the lock by divergence detection. Mouse wheel zooms along the
        offset axis without breaking the lock.

    Parameter(s):
        0: Action Parameters

    Return Value:
        None

    Example:
        [_selectedObjects, _selectedGroups] call uksf_zeus_fnc_contextWatch
*/
params ["", "_selectedObjects"];

private _target = (_selectedObjects select {!isNull _x && {alive _x}}) param [0, objNull];
if (isNull _target) exitWith {};

if (GVAR(watchPFH) > -1) then {
    [GVAR(watchPFH)] call CBA_fnc_removePerFrameHandler;
};
GVAR(watchPFH) = -1;
GVAR(watchTarget) = _target;
GVAR(watchHasExpected) = false;
GVAR(watchExpectedPos) = [0, 0, 0];
GVAR(watchExpectedDir) = [0, 1, 0];
GVAR(watchSmoothDir) = [0, 1, 0];
GVAR(watchSmoothInit) = false;
GVAR(watchSmoothPos) = [0, 0, 0];
GVAR(watchSmoothPosInit) = false;
GVAR(watchZoom) = 0;
GVAR(watchScrolledFrame) = false;
GVAR(watchOrbitYaw) = 0;
GVAR(watchOrbitPitch) = 0;
GVAR(watchOrbitYawSmooth) = 0;
GVAR(watchOrbitPitchSmooth) = 0;
GVAR(watchOrbitActive) = false;
GVAR(watchLastFrameOrbitActive) = false;

GVAR(watchPFH) = [FUNC(contextWatchTick), 0] call CBA_fnc_addPerFrameHandler;
