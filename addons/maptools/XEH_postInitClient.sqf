#include "script_component.hpp"

if (!hasInterface) exitWith {};

[
    "UKSF",
    "drawShape",
    [
        "Draw shape (hold to start)",
        "Hold to start a shape on next LMB drag. Releasing does not cancel an in-progress shape. Requires ACE Map Tools."
    ],
    {
        if (!visibleMap) exitWith { false };
        GVAR(drawKeyHeld) = true;
        private _mapControl = (findDisplay 12) displayCtrl 51;
        if (!isNull _mapControl) then { _mapControl ctrlMapCursor ["Track", "Move"] };
        call FUNC(renderHint);
        false
    },
    {
        GVAR(drawKeyHeld) = false;
        private _mapControl = (findDisplay 12) displayCtrl 51;
        if (!isNull _mapControl) then { _mapControl ctrlMapCursor ["Track", "Track"] };
        false
    },
    [0x2B, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "UKSF",
    "cycleShapeMode",
    [
        "Cycle shape mode",
        "Advance to the next shape mode (Circle / Ellipse / Race-track / Cone)."
    ],
    {
        if (!visibleMap) exitWith { false };
        call FUNC(cycleMode);
        systemChat format ["Shape: %1", GVAR(currentModeLabel)];
        false
    },
    {false},
    [0x2B, [false, true, false]]
] call CBA_fnc_addKeybind;

["visibleMap", {
    params ["", "_mapOn"];
    private _display = findDisplay 12;
    private _mapControl = if (isNull _display) then { controlNull } else { _display displayCtrl 51 };

    if (_mapOn) then {
        if (isNull _mapControl) exitWith {};
        private _downId = _mapControl ctrlAddEventHandler ["MouseButtonDown", {[1, _this] call FUNC(handleMouseButton)}];
        private _upId   = _mapControl ctrlAddEventHandler ["MouseButtonUp",   {[0, _this] call FUNC(handleMouseButton)}];
        private _moveId = _mapControl ctrlAddEventHandler ["MouseMoving",     {call FUNC(handleMouseMove)}];
        uiNamespace setVariable [QGVAR(mapEHs), [_downId, _upId, _moveId]];

        call FUNC(initHeaderDropdown);
    } else {
        private _ehs = uiNamespace getVariable [QGVAR(mapEHs), []];
        if (!isNull _mapControl && {count _ehs == 3}) then {
            _mapControl ctrlRemoveEventHandler ["MouseButtonDown", _ehs#0];
            _mapControl ctrlRemoveEventHandler ["MouseButtonUp",   _ehs#1];
            _mapControl ctrlRemoveEventHandler ["MouseMoving",     _ehs#2];
        };
        uiNamespace setVariable [QGVAR(mapEHs), []];
        uiNamespace setVariable [QGVAR(headerDropdown), controlNull];

        GVAR(state) = "idle";
        { deleteMarkerLocal _x } forEach GVAR(previewMarkers);
        GVAR(previewMarkers) = [];
    };
}] call CBA_fnc_addPlayerEventHandler;
