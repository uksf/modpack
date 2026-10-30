#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Markers app, an editor for cTab user markers on the player's side.
        Click the map to set the position, choose the icon, size, direction, and text, then place the marker.
        Select a marker in the list to load it, then update or delete it. Markers use cTab's shared marker list, so every cTab device on the side sees them.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>
        2: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group, _map] call uksf_ctab_fnc_markersOpen
*/
params ["", "_group", "_map"];

[_group, "cTab_RscText", [0.04, 0.02, 0.92, 0.07], "Markers"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(markerIconCombo), [_group, [0.04, 0.1, 0.92, 0.07], MARKER_ICONS, GVAR(markerIcon), {GVAR(markerIcon) = _this select 0}] call FUNC(createCombo)];
uiNamespace setVariable [QGVAR(markerSizeCombo), [_group, [0.04, 0.18, 0.45, 0.07], MARKER_SIZES, GVAR(markerSize), {GVAR(markerSize) = _this select 0}] call FUNC(createCombo)];
uiNamespace setVariable [QGVAR(markerDirCombo), [_group, [0.51, 0.18, 0.45, 0.07], MARKER_DIRECTIONS, GVAR(markerDir), {GVAR(markerDir) = _this select 0}] call FUNC(createCombo)];
uiNamespace setVariable [QGVAR(markerText), [_group, "cTab_RscEdit", [0.04, 0.26, 0.92, 0.07]] call FUNC(createCtrl)];
uiNamespace setVariable [QGVAR(markerInfo), [_group, [0.04, 0.34, 0.92, 0.07]] call FUNC(createInfo)];

[_group, [0.04, 0.42, 0.29, 0.08], "Place", {[-1] call FUNC(markersSave)}] call FUNC(createButton);
[_group, [0.355, 0.42, 0.29, 0.08], "Update", {
    private _index = lbCurSel APP_CTRL(markerList);
    if (_index >= 0) then {[APP_CTRL(markerList) lbValue _index] call FUNC(markersSave)};
}] call FUNC(createButton);
[_group, [0.67, 0.42, 0.29, 0.08], "Delete", {
    private _index = lbCurSel APP_CTRL(markerList);
    if (_index < 0) exitWith {};
    [call cTab_fnc_getPlayerEncryptionKey, APP_CTRL(markerList) lbValue _index] call cTab_fnc_deleteUserMarker;
    [FUNC(markersRefresh), [], MARKER_REFRESH_DELAY] call CBA_fnc_waitAndExecute;
}] call FUNC(createButton);

uiNamespace setVariable [QGVAR(markerList), [_group, QGVAR(listBox), [0.04, 0.52, 0.92, 0.46]] call FUNC(createCtrl)];
APP_CTRL(markerList) ctrlAddEventHandler ["LBSelChanged", {
    params ["_list", "_index"];
    if (_index < 0) exitWith {};
    [_list lbValue _index] call FUNC(markersLoad);
}];

[_map, {
    params ["_position"];
    GVAR(markerPoint) = _position;
    [APP_CTRL(markerInfo), [format ["Position: %1", [_position] call ctab_core_fnc_gridPosition]]] call FUNC(setInfo);
}] call FUNC(addMapClickHandler);

[APP_CTRL(markerInfo), ["Click the map to set the position."]] call FUNC(setInfo);
call FUNC(markersRefresh);
