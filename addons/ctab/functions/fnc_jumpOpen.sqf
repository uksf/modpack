#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the HAHO/HALO planner panel.
        A click on the map sets the drop zone. The planner shows the release point, the opening point, the fall and canopy times, and the canopy glide range.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>
        2: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group, _map] call uksf_ctab_fnc_jumpOpen
*/
params ["", "_group", "_map"];

[_group, "cTab_RscText", [0.04, 0.02, 0.92, 0.09], "HAHO / HALO"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(jumpInfo), [_group, [0.04, 0.12, 0.92, 0.5]] call FUNC(createInfo)];

[_group, [0.04, 0.64, 0.44, 0.09], [["HALO", "HALO"], ["HAHO", "HAHO"]], GVAR(jumpMode), {
    params ["_mode"];
    GVAR(jumpMode) = _mode;
    GVAR(jumpOpening) = [JUMP_HALO_OPENING, JUMP_HAHO_OPENING] select (_mode == "HAHO");
    call FUNC(jumpCalculate);
}] call FUNC(createCombo);

private _altitudes = [];
for "_altitude" from 1000 to 9000 step 500 do {
    _altitudes pushBack [format ["Exit %1 m", _altitude], _altitude];
};
[_group, [0.52, 0.64, 0.44, 0.09], _altitudes, GVAR(jumpRelease), {
    params ["_altitude"];
    GVAR(jumpRelease) = _altitude;
    call FUNC(jumpCalculate);
}] call FUNC(createCombo);

private _headings = [["Track downwind", -1]];
{
    _headings pushBack [format ["Track %1", _x], _forEachIndex * 45];
} forEach ["N", "NE", "E", "SE", "S", "SW", "W", "NW"];
[_group, [0.04, 0.75, 0.92, 0.09], _headings, GVAR(jumpHeading), {
    params ["_heading"];
    GVAR(jumpHeading) = _heading;
    call FUNC(jumpCalculate);
}] call FUNC(createCombo);

[_group, [0.04, 0.86, 0.92, 0.1], "Clear", {
    GVAR(jumpZone) = [];
    call FUNC(jumpCalculate);
}] call FUNC(createButton);

[_map, {
    params ["_position"];
    GVAR(jumpZone) = _position;
    call FUNC(jumpCalculate);
}] call FUNC(addMapClickHandler);

call FUNC(jumpCalculate);
