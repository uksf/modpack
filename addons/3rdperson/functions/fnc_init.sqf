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
    if (cameraView == "EXTERNAL" && vehicle player == player && isNull (getConnectedUAV player)) then {
        player switchCamera "INTERNAL";
    };
}, 0, []] call CBA_fnc_addPerFrameHandler;