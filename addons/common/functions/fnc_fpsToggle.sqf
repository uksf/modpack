/*
    Author:
        Tim Beswick

    Description:
        Display FPS of all connected headless clients // diag_fps

    Parameters:
        None

    Return value:
        None
*/
#include "script_component.hpp"

GVAR(fpsState) = !GVAR(fpsState);

if (GVAR(fpsState)) then {
    GVAR(fpsEventID) = [QGVAR(fpsSet), {_this call FUNC(fpsSet)}] call CBA_fnc_addEventHandler;
    [{
        params ["_args", "_idPFH"];

        if (!GVAR(fpsState)) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        {
            [QGVAR(fpsGet), [player], _x] call CBA_fnc_targetEvent;
            false
        } count GVAR(HCs);
        [QGVAR(fpsGet), [player]] call CBA_fnc_serverEvent;

        private _text = [lineBreak, "FPS Debug:", lineBreak, lineBreak];
        {
            if ((_forEachIndex mod 2) isEqualTo 0) then {
                _text append [format ["%1: %2", _x, (GVAR(fpsArray) select (_forEachIndex + 1))], lineBreak];
            };
        } forEach GVAR(fpsArray);
        _text append [lineBreak];
        hintSilent (composeText _text);
    }, 0.5, []] call CBA_fnc_addPerFrameHandler;
} else {
    [QGVAR(fpsSet), GVAR(fpsEventID)] call CBA_fnc_removeEventHandler;
};
