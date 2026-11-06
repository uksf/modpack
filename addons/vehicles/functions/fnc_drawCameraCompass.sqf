#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame handler. Draws N, E, S and W markers on the ground around the point
        under the camera centre, at a fixed screen size for any range and zoom, while updateCameraOverlay keeps it.
        Skips frames where the player is not looking through this vehicle's camera. Draws nothing while the camera centre is on the sky.

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Per-frame handler ID <NUMBER>

    Return Value:
        Nothing

    Example:
        [_vehicle, _idPFH] call uksf_vehicles_fnc_drawCameraCompass
*/
params ["_vehicle", "_idPFH"];

if (isNull _vehicle || {call FUNC(cameraOverlayVehicle) != _vehicle}) exitWith {};

private _center = screenToWorld [0.5, 0.5];
private _cameraDistance = (positionCameraToWorld [0, 0, 0]) distance _center;
if (_cameraDistance > viewDistance * 0.98) exitWith {};

private _spacing = 0.25 * _cameraDistance * ((call CBA_fnc_getFov) select 0);
private _halfSpacing = _spacing / 2;
{
    _x params ["_letter", "_color", "_markerOffset", "_dotOffset"];
    drawIcon3D ["", _color, _center vectorAdd _markerOffset, 0, 0, 0, _letter, 2, 0.05, "PuristaMedium"];
    drawIcon3D ["", _color, _center vectorAdd _dotOffset, 0, 0, 0, ".", 2, 0.05, "PuristaMedium"];
} forEach [
    ["N", [1, 1, 1, 1], [0, _spacing, 0], [0, _halfSpacing, 0]],
    ["S", [1, 1, 1, 0.7], [0, -_spacing, 0], [0, -_halfSpacing, 0]],
    ["E", [1, 1, 1, 0.7], [_spacing, 0, 0], [_halfSpacing, 0, 0]],
    ["W", [1, 1, 1, 0.7], [-_spacing, 0, 0], [-_halfSpacing, 0, 0]]
];
