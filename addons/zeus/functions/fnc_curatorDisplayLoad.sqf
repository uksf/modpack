#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Zeus display load

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None

    Example:
        [_display] call uksf_zeus_fnc_curatorDisplayLoad
*/
params ["_display"];

[true, player] call ace_common_fnc_setVolume;

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(debugMapDrawID)];
GVAR(debugMapDrawID) = (_display displayCtrl 50) ctrlAddEventHandler ["Draw", {
    call FUNC(debugMapDraw);
}];

[GVAR(debugPFH)] call CBA_fnc_removePerFrameHandler;
GVAR(debugPFH) = [{
    call FUNC(debug3dDraw);
}, 0] call CBA_fnc_addPerFrameHandler;

// Create HUD controls for screen-fixed text overlay
{ctrlDelete _x} forEach GVAR(debugHudControls);
GVAR(debugHudControls) = [];
for "_i" from 0 to 4 do {
    private _control = _display ctrlCreate ["RscStructuredText", 30000 + _i];
    _control ctrlSetPosition [
        safezoneX + 0.3 * safezoneW,
        safezoneY + 0.09 * safezoneH + _i * 0.025 * safezoneH,
        0.4 * safezoneW,
        0.025 * safezoneH
    ];
    _control ctrlSetBackgroundColor [0, 0, 0, 0];
    _control ctrlCommit 0;
    _control ctrlShow false;
    GVAR(debugHudControls) pushBack _control;
};

// Always enable FPS and unconscious display while Zeus is open
GVAR(debugActiveToggles) set [QGVAR(fps), true];
GVAR(debugActiveToggles) set [QGVAR(unconscious), true];

// Re-subscribe server data streams for any active providers
{
    if (_x in GVAR(debugServerGetters)) then {
        [QGVAR(debugStreamToggle), [player, _x, true]] call CBA_fnc_serverEvent;
    };
} forEach (keys GVAR(debugActiveToggles));
