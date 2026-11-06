#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Lists the cTab user markers on the player's side in the Markers app, with each marker's text and grid.
        The value of each entry is the cTab marker ID.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_markersRefresh
*/
if (isNull APP_CTRL(markerList)) exitWith {};

lbClear APP_CTRL(markerList);
{
    _x params ["_id", "_data"];
    _data params ["_position", "_icon", "", "", "_text"];
    private _name = (MARKER_ICONS select {_x select 1 == _icon}) param [0, ["Marker"]] select 0;
    private _entry = APP_CTRL(markerList) lbAdd format ["%1 - %2 (%3)", _text, _name, [_position] call ctab_core_fnc_gridPosition];
    APP_CTRL(markerList) lbSetValue [_entry, _id];
} forEach ([cTab_userMarkerLists, call cTab_fnc_getPlayerEncryptionKey, []] call cTab_fnc_getFromPairs);
