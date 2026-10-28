#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an app in the cTab Android launcher.
        The launcher lists apps in registration order. Registering an id again replaces that app.

    Parameter(s):
        0: Id, unique, used in the cTab mode name <STRING>
        1: Title shown in the launcher <STRING>
        2: Open code, called with [display, content group, map] when the app opens. The map is null for a full-screen app <CODE>
        3: Close code, called with [display, content group] before the content group is deleted (Optional, default {}) <CODE>
        4: Uses the map, so the app gets a side panel over cTab's map (Optional, default false) <BOOL>

    Return Value:
        Nothing

    Example:
        ["route", "Route", {params ["_display", "_group", "_map"]}, {}, true] call uksf_ctab_fnc_registerApp
*/
params [["_id", "", [""]], ["_title", "", [""]], ["_onOpen", {}, [{}]], ["_onClose", {}, [{}]], ["_usesMap", false, [false]]];

if (_id == "") exitWith {
    ERROR("Cannot register a cTab app without an id");
};

private _index = GVAR(apps) findIf {_x select 0 == _id};
private _app = [_id, _title, _onOpen, _onClose, _usesMap];
if (_index == -1) then {
    GVAR(apps) pushBack _app;
} else {
    GVAR(apps) set [_index, _app];
};
