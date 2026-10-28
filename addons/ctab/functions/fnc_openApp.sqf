#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens a registered app in the cTab Android dialog.
        Creates a content group that fills the screen and passes it to the app's open code.
        Returns to the launcher if the app is not registered.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: UKSF container group <CONTROL>
        2: App id <STRING>

    Return Value:
        Nothing

    Example:
        [_display, _container, "route"] call uksf_ctab_fnc_openApp
*/
params ["_display", "_container", "_id"];

private _index = GVAR(apps) findIf {_x select 0 == _id};
if (_index == -1) exitWith {
    WARNING_1("cTab app %1 is not registered",_id);
    [_display, _container] call FUNC(showLauncher);
};

(GVAR(apps) select _index) params ["", "", "_onOpen", "_onClose"];

private _group = _display ctrlCreate ["RscControlsGroupNoScrollbars", -1, _container];
(ctrlPosition _container) params ["", "", "_width", "_height"];
_group ctrlSetPosition [0, 0, _width, _height];
_group ctrlCommit 0;

GVAR(content) = [_group, _onClose];
[_display, _group] call _onOpen;
