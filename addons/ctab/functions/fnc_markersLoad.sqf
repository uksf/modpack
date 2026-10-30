#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads one cTab user marker into the Markers app editor, so that Update changes it.

    Parameter(s):
        0: cTab marker ID <NUMBER>

    Return Value:
        Nothing

    Example:
        [21] call uksf_ctab_fnc_markersLoad
*/
params ["_id"];

private _markers = [cTab_userMarkerLists, call cTab_fnc_getPlayerEncryptionKey, []] call cTab_fnc_getFromPairs;
private _marker = _markers param [_markers findIf {_x select 0 == _id}, []];
if (_marker isEqualTo []) exitWith {};
(_marker select 1) params ["_position", "_icon", "_size", "_dir", "_text"];

{
    _x params ["_combo", "_value"];
    _combo lbSetCurSel (0 max ((_combo getVariable QGVAR(values)) find _value));
} forEach [[APP_CTRL(markerIconCombo), _icon], [APP_CTRL(markerSizeCombo), _size], [APP_CTRL(markerDirCombo), _dir]];
APP_CTRL(markerText) ctrlSetText _text;
GVAR(markerPoint) = _position;
[APP_CTRL(markerInfo), [format ["Position: %1", [_position] call ctab_core_fnc_gridPosition]]] call FUNC(setInfo);
