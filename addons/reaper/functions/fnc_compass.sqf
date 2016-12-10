/*
	Author:
		Tim Beswick

	Description:
		Shows or hides 3D compass

	Parameter(s):
		0: UAV <OBJECT>
		1: Compass state <BOOL>

	Return Value:
		Nothing
*/
#include "script_component.hpp"

params ["_uav", "_state"];

if (_state) then {
	GVAR(handlerCompass) = [{
		params ["_args"];
		_args params ["_uav"];
		if (cameraView == "GUNNER" && cameraOn == _uav) then {
			_zoom = (call CBA_fnc_getFov) select 1;
			_factor = 500 / _zoom;
			_halfFactor = _factor / 2;
			{
				_center = screenToWorld [0.5,0.5];
				_x params ["_letter", "_color", "_offset1", "_offset2"];
				drawIcon3D ["", _color, _center vectorAdd _offset1, 0, 0, 0, _letter, 2, 0.05, "PuristaMedium"];
				drawIcon3D ["", _color, _center vectorAdd _offset2, 0, 0, 0, ".", 2, 0.05, "PuristaMedium"];
			} count [
				["N", [1,1,1,1], [0,_factor,0], [0,_halfFactor,0]],
				["S", [1,1,1,0.7], [0,-_factor,0], [0,-_halfFactor,0]],
				["E", [1,1,1,0.7], [_factor,0,0], [_halfFactor,0,0]],
				["W", [1,1,1,0.7], [-_factor,0,0], [-_halfFactor,0,0]]
			];
		};
		
	}, 0, [_uav]] call CBA_fnc_addPerFrameHandler;
	_uav setVariable [QGVAR(compassState), true];
} else {
	[GVAR(handlerCompass)] call CBA_fnc_removePerFrameHandler;
	_uav setVariable [QGVAR(compassState), false];
};
