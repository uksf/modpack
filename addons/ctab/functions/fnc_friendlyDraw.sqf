#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws friendly names and headings on the map while the Friendly app is open.
        Uses only cTab's BFT lists, so it shows the same people that BFT shows: group members who carry a personnel device, and the leaders of other groups that carry a leader device.
        Positions follow the cTab BFT mode: live in real-time mode, and the last synchronised position otherwise.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_friendlyDraw
*/
params ["_map"];

if (GVAR(currentApp) != "friendly" || {ctab_core_bft_mode == 0}) exitWith {};

private _live = ctab_core_bft_mode == 1;
private _arrowLength = (_map ctrlMapScreenToWorld [0, 0]) distance2D (_map ctrlMapScreenToWorld [0.03, 0]);
private _draw = {
    params ["_unit", "_text", "_position", "_direction"];
    if (_live) then {
        _position = getPosASLVisual vehicle _unit;
        _direction = getDirVisual vehicle _unit;
    };
    _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", COLOUR_FRIENDLY, _position, 24, 24, 0, _text, 1, 0.035, "RobotoCondensed", "left"];
    if (_direction < 0) exitWith {};
    _map drawArrow [_position, _position getPos [_arrowLength, _direction], COLOUR_FRIENDLY];
};

{
    _x params ["_unit", "", "", "_name", "", "_position", "_direction"];
    if (alive _unit && {group _unit == group cTab_player}) then {
        [_unit, _name, _position, _direction] call _draw;
    };
} forEach (missionNamespace getVariable ["cTabBFTmembers", []]);

{
    _x params ["_leader", "", "", "_groupName", "", "_position"];
    if (alive _leader) then {
        [_leader, format ["%1: %2", _groupName, name _leader], _position, [-1, getDirVisual vehicle _leader] select _live] call _draw;
    };
} forEach (missionNamespace getVariable ["cTabBFTgroups", []]);
