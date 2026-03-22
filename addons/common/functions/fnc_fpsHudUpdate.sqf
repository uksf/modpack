#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the FPS debug HUD with data received from the server.
        Called as a CBA event handler when the server responds to a HUD data request.

    Parameter(s):
        0: FPS data array <ARRAY> - [[identifier, fps, type], ...]

    Return Value:
        None

    Example:
        [_data] call uksf_common_fnc_fpsHudUpdate
*/
params [["_data", [], [[]]]];

if (GVAR(fpsHudMode) isEqualTo 0) exitWith {};
if (isNull GVAR(fpsHudControl)) exitWith {};

disableSerialization;

private _lines = [];

// Sort: server first, then HCs, then players
private _serverEntries = _data select {_x#2 isEqualTo "server"};
private _headlessClientEntries = _data select {_x#2 isEqualTo "hc"};
private _playerEntries = _data select {_x#2 isEqualTo "player"};

// Server
{
    _x params ["", "_fps"];
    private _colour = if (_fps <= 15) then { "#ff0000" } else { "#ffffff" };
    _lines pushBack format ["<t color='%1' size='0.9'>Server: %2 FPS</t>", _colour, _fps];
} forEach _serverEntries;

// HCs
{
    _x params ["_identifier", "_fps"];
    private _colour = if (_fps <= 15) then { "#ff0000" } else { "#ffffff" };
    _lines pushBack format ["<t color='%1' size='0.9'>%2: %3 FPS</t>", _colour, _identifier, _fps];
} forEach _headlessClientEntries;

// Players — mode 2 shows low FPS only, mode 3 shows all
if (GVAR(fpsHudMode) >= 2) then {
    {
        _x params ["_identifier", "_fps"];
        if (GVAR(fpsHudMode) isEqualTo 2 && {_fps > 25}) then { continue };

        private _name = _identifier;
        {
            if (getPlayerUID _x isEqualTo _identifier) exitWith {
                private _playerName = name _x;
                if (_playerName isNotEqualTo "") then {
                    _name = _playerName;
                };
            };
        } forEach ALL_PLAYERS;

        private _colour = if (_fps <= 15) then { "#ff0000" } else { if (_fps <= 25) then { "#ffaa00" } else { "#ffffff" } };
        _lines pushBack format ["<t color='%1' size='0.9'>%2: %3 FPS</t>", _colour, _name, _fps];
    } forEach _playerEntries;
};

private _text = _lines joinString "<br/>";
GVAR(fpsHudControl) ctrlSetStructuredText parseText _text;

// Resize control height to fit content
private _lineCount = count _lines max 1;
private _height = _lineCount * 0.018 + 0.01;
private _position = ctrlPosition GVAR(fpsHudControl);
_position set [3, _height];
GVAR(fpsHudControl) ctrlSetPosition _position;
GVAR(fpsHudControl) ctrlCommit 0;
