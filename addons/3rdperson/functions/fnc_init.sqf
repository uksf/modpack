/*
	Author:
		Tim Beswick

	Description:
		Disables 3rd person except when in vehicles

	Parameter(s):
		None

	Return Value:
		None
*/
#include "script_component.hpp"

[{
    if (cameraView == "EXTERNAL" && cameraOn == player && vehicle player == player) then {
        cameraOn switchCamera "INTERNAL";
    };
}, 0, []] call CBA_fnc_addPerFrameHandler;