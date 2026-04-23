#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Renders server and headless client FPS data received from the server
        as a hintSilent display.

    Parameter(s):
        0: FPS data array <ARRAY> - [[identifier, fps, type], ...]

    Return Value:
        None

    Example:
        [_data] call uksf_common_fnc_fpsHint
*/
params [["_data", [], [[]]]];

if (!GVAR(fpsHintActive)) exitWith {};

private _serverLines = [];
private _hcLines = [];

{
    _x params ["_identifier", "_fps", "_type"];
    switch (_type) do {
        case "server": {
            _serverLines pushBack format ["Server: %1", _fps];
        };
        case "hc": {
            _hcLines pushBack format ["%1: %2", _identifier, _fps];
        };
    };
} forEach _data;

private _lines = ["FPS"] + _serverLines + _hcLines;
hintSilent parseText (_lines joinString "<br/>");
