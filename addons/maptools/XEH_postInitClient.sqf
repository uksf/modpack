#include "script_component.hpp"

if (!hasInterface) exitWith {};

[{
    params ["_args", "_idPFH"];
    if (visibleMap) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        private _mapControl = (findDisplay 12) displayCtrl 51;
        _mapControl ctrlAddEventHandler ["MouseButtonDown", {[1, _this] call FUNC(handleMouseButton)}];
        _mapControl ctrlAddEventHandler ["MouseButtonUp",   {[0, _this] call FUNC(handleMouseButton)}];
        _mapControl ctrlAddEventHandler ["MouseMoving", {
            params ["_ctrl", "_xPos", "_yPos"];
            [_ctrl, _xPos, _yPos] call FUNC(handleMouseMove);
        }];
    };
}, 1, []] call CBA_fnc_addPerFrameHandler;

[
    "UKSF",
    "drawShape",
    [
        "Draw shape (hold)",
        "Hold to enter shape-draw on next LMB drag. Requires ACE Map Tools."
    ],
    {
        GVAR(drawKeyHeld) = true;
        false
    },
    {
        GVAR(drawKeyHeld) = false;
        if (GVAR(state) isNotEqualTo "idle") then {
            GVAR(state) = "idle";
            call FUNC(updatePreview);
        };
        false
    },
    [0x38, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "UKSF",
    "cycleShapeMode",
    [
        "Cycle shape mode",
        "Advance to the next shape mode (Circle / Ellipse / Race-track / Cone)."
    ],
    {
        call FUNC(cycleMode);
        false
    },
    {false},
    [0x38, [true, false, false]]
] call CBA_fnc_addKeybind;
