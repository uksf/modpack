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

// Sort active toggles by provider priority for deterministic HUD ordering
private _activeKeys = keys GVAR(debugActiveToggles);
_activeKeys sort true;
_activeKeys = _activeKeys apply {
    private _provider = GVAR(debugProviders) getOrDefault [_x, []];
    private _priority = if (_provider isEqualTo []) then {0} else {_provider#1};
    [_priority, _x]
};
_activeKeys sort false;
_activeKeys = _activeKeys apply {_x#1};

{
    private _providerKey = _x;
    private _provider = GVAR(debugProviders) getOrDefault [_providerKey, []];
    if (_provider isEqualTo []) then { continue };

    private _data = GVAR(debugData) getOrDefault [_providerKey, []];
    _provider params ["", "", "", "_fnc_serverGetter", "", "_fnc_draw3d", "", "_fnc_drawHud"];
    private _clientOnly = _fnc_serverGetter isEqualTo {};
    if (!_clientOnly && {_data isEqualTo []}) then { continue };

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
