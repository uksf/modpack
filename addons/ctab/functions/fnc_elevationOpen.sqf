#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Elevation app panel.
        A click on the map places the observer. The app then maps, within the radius, the ground the observer can see or the terrain height against the observer.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>
        2: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group, _map] call uksf_ctab_fnc_elevationOpen
*/
params ["", "_group", "_map"];

[_group, "cTab_RscText", [0.04, 0.02, 0.92, 0.09], "Elevation"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(elevationInfo), [_group, [0.04, 0.12, 0.92, 0.42]] call FUNC(createInfo)];

[_group, [0.04, 0.56, 0.92, 0.09], [["Visible ground", "visible"], ["Height against observer", "height"]], GVAR(elevationMode), {
    params ["_mode"];
    GVAR(elevationMode) = _mode;
}] call FUNC(createCombo);

[_group, [0.04, 0.67, 0.44, 0.09], [["Eye 2 m", 2], ["Eye 10 m", 10], ["Eye 30 m", 30], ["Eye 100 m", 100]], GVAR(elevationEye), {
    params ["_eye"];
    GVAR(elevationEye) = _eye;
    call FUNC(elevationCalculate);
}] call FUNC(createCombo);

[_group, [0.52, 0.67, 0.44, 0.09], [["Radius 500 m", 500], ["Radius 1 km", 1000], ["Radius 2 km", 2000], ["Radius 4 km", 4000]], GVAR(elevationRadius), {
    params ["_radius"];
    GVAR(elevationRadius) = _radius;
    call FUNC(elevationCalculate);
}] call FUNC(createCombo);

[_group, [0.04, 0.8, 0.44, 0.1], "Observer on me", {
    GVAR(elevationObserver) = getPosASL cTab_player;
    call FUNC(elevationCalculate);
}] call FUNC(createButton);

[_group, [0.52, 0.8, 0.44, 0.1], "Clear", {
    GVAR(elevationObserver) = [];
    call FUNC(elevationCalculate);
}] call FUNC(createButton);

[_map, {
    params ["_position"];
    GVAR(elevationObserver) = _position;
    call FUNC(elevationCalculate);
}] call FUNC(addMapClickHandler);

call FUNC(elevationRefresh);
