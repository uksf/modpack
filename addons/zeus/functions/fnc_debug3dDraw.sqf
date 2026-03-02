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
*/
if (GVAR(debugKill)) exitWith {};

private _cameraPosition = positionCameraToWorld [0,0,0];
private _maxDistance = if (GVAR(debugDistanceLimited)) then {5000} else {100000};
private _hudIndex = 0;

private _activeKeys = call FUNC(debugGetSortedActiveKeys);

{
    private _providerKey = _x;
    private _drawData = GVAR(debugDraws) getOrDefault [_providerKey, []];
    if (_drawData isEqualTo []) then { continue };

    private _data = GVAR(debugData) getOrDefault [_providerKey, []];
    private _hasServerGetter = _providerKey in GVAR(debugServerGetters);
    if (_hasServerGetter && {_data isEqualTo []}) then { continue };

    _drawData params ["_fnc_draw3d", "", "_fnc_drawHud"];

    [_data, _cameraPosition, _maxDistance] call _fnc_draw3d;

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
