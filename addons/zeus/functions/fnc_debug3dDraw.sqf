#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Debug 3D draw orchestrator. Runs every frame while Zeus is open.
        Delegates actual drawing to registered provider functions.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_zeus_fnc_debug3dDraw
*/
if (GVAR(debugKill)) exitWith {};

// Zeus backspace toggles showHUD — mirror that for our HUD controls
private _hudVisible = (shownHUD)#0;
if (!_hudVisible) exitWith {
    {_x ctrlShow false} forEach GVAR(debugHudControls);
};

private _cameraPosition = positionCameraToWorld [0,0,0];
private _maxDistance = if (GVAR(debugDistanceLimited)) then {5000} else {100000};
private _iconSpacing = 0.0125;
private _hudIndex = 0;

private _activeKeys = call FUNC(debugGetSortedActiveKeys);

{
    private _providerKey = _x;
    private _provider = GVAR(debugProviders) get _providerKey;
    if (isNil "_provider") then { continue };
    private _fnc_draw3d = _provider get "draw3d";
    if (isNil "_fnc_draw3d") then { continue };

    private _data = GVAR(debugData) getOrDefault [_providerKey, []];
    if ("serverGetter" in _provider && {_data isEqualTo []}) then { continue };

    private _fnc_drawHud = _provider getOrDefault ["drawHud", {}];

    [_data, _cameraPosition, _maxDistance, _iconSpacing] call _fnc_draw3d;

    if (_fnc_drawHud isNotEqualTo {}) then {
        if (_hudIndex < count GVAR(debugHudControls)) then {
            private _control = GVAR(debugHudControls) select _hudIndex;
            [_data, _control] call _fnc_drawHud;
            _control ctrlShow true;
            _hudIndex = _hudIndex + 1;
        };
    };
} forEach _activeKeys;

for "_i" from _hudIndex to (count GVAR(debugHudControls) - 1) do {
    (GVAR(debugHudControls) select _i) ctrlShow false;
};
