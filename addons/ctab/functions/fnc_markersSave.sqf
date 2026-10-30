#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Places a cTab user marker from the Markers app editor, or replaces an existing marker with it.
        cTab has no marker edit, so an update deletes the old marker and adds the new one. An empty text uses the current time, the same as cTab.

    Parameter(s):
        0: cTab marker ID to replace, or -1 for a new marker <NUMBER>

    Return Value:
        Nothing

    Example:
        [-1] call uksf_ctab_fnc_markersSave
*/
params ["_replace"];

if (GVAR(markerPoint) isEqualTo []) exitWith {
    [APP_CTRL(markerInfo), ["Click the map to set the position first."]] call FUNC(setInfo);
};

private _key = call cTab_fnc_getPlayerEncryptionKey;
private _text = ctrlText APP_CTRL(markerText);
if (_text == "") then {
    _text = call cTab_fnc_currentTime;
};

if (_replace >= 0) then {
    [_key, _replace] call cTab_fnc_deleteUserMarker;
};
[_key, [+GVAR(markerPoint), GVAR(markerIcon), GVAR(markerSize), GVAR(markerDir), _text, cTab_player]] call cTab_fnc_addUserMarker;
[FUNC(markersRefresh), [], MARKER_REFRESH_DELAY] call CBA_fnc_waitAndExecute;
