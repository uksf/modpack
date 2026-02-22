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
*/
params ["_display"];

[true, player] call ace_common_fnc_setVolume;

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(visualiseMapDrawID)];
GVAR(visualiseMapDrawID) = (_display displayCtrl 50) ctrlAddEventHandler ["Draw", {
    call FUNC(visualiseMapDraw);
}];

[GVAR(visualisePFH)] call CBA_fnc_removePerFrameHandler;
GVAR(visualisePFH) = [{
    call FUNC(visualise3dDraw);
}, 0] call CBA_fnc_addPerFrameHandler;

// Create HUD controls for screen-fixed text overlay
{ctrlDelete _x} forEach GVAR(visualiseHudControls);
GVAR(visualiseHudControls) = [];
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
    GVAR(visualiseHudControls) pushBack _control;
};

// Re-subscribe server data streams for any active visualisations
{
    private _providerKeys = switch (_x) do {
        case "aicommander": { ["aicommander_ground", "aicommander_air"] };
        case "rebronetwork": { ["rebroconnections", "rebronetwork"] };
        default { [_x] };
    };
    if (GVAR(visualiseActiveToggles) get _x) then {
        {
            [QGVAR(visualiseStreamToggle), [player, _x, true]] call CBA_fnc_serverEvent;
        } forEach _providerKeys;
    };
} forEach (keys GVAR(visualiseActiveToggles));

// FPS_COLLECTDATA = true;
// FPS_PFHID = [{

//     if !(FPS_COLLECTDATA) exitWith {};

//     private _frameData = [];
//     {
//         private _fps = _x getVariable ["uksf_zeus_fps", 0];
//         private _name = name _x;

//         _frameData pushBack [_name, _fps];
//     } forEach (allPlayers - entities "HeadlessClient_F");

//     private _allUnits = allUnits select {!(isPlayer _x)};
//     private _simulatedUnits = {simulationEnabled _x} count _allUnits;
//     private _allGroups = allGroups select {!(isPlayer (leader _x))};
//     private _simulatedGroups = {simulationEnabled (leader _x)} count _allGroups;
//     diag_log ["FPS DATA FRAME", CBA_missionTime, count _allUnits, _simulatedUnits, count _allGroups, _simulatedGroups, _frameData];
// }, 1, []] call CBA_fnc_addPerFrameHandler;
