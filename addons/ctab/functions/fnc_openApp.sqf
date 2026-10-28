#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens a registered app in the cTab Android dialog.
        A map app gets the side panel over cTab's map. Any other app gets the whole screen.
        Returns to the launcher if the app is not registered.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App id <STRING>

    Return Value:
        Nothing

    Example:
        [_display, "route"] call uksf_ctab_fnc_openApp
*/
params ["_display", "_id"];

private _index = GVAR(apps) findIf {_x select 0 == _id};
if (_index == -1) exitWith {
    WARNING_1("cTab app %1 is not registered",_id);
    private _full = _display displayCtrl IDC_APPS_GROUP;
    _full ctrlShow true;
    [_display, _full] call FUNC(showLauncher);
};

(GVAR(apps) select _index) params ["", "", "_onOpen", "_onClose", "_usesMap"];

private _map = controlNull;
private _container = _display displayCtrl IDC_APPS_GROUP;
if (_usesMap) then {
    _map = [_display] call FUNC(currentMap);
    _map ctrlShow true;
    _container = _display displayCtrl IDC_APPS_PANEL;
};
_container ctrlShow true;

private _group = _display ctrlCreate ["RscControlsGroupNoScrollbars", -1, _container];
(ctrlPosition _container) params ["", "", "_width", "_height"];
_group ctrlSetPosition [0, 0, _width, _height];
_group ctrlCommit 0;

private _background = _display ctrlCreate ["cTab_RscText", -1, _group];
_background ctrlSetPosition [0, 0, _width, _height];
_background ctrlSetBackgroundColor [0.05, 0.05, 0.05, [1, 0.85] select _usesMap];
_background ctrlCommit 0;

GVAR(content) = [_group, _onClose];
GVAR(mapHandlers) = [];
[_display, _group, _map] call _onOpen;
