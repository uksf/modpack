#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shows the fields of a report format in the Reports app and fills each field with its default.

    Parameter(s):
        0: Report format as [title, fields] <ARRAY>

    Return Value:
        Nothing

    Example:
        [(call uksf_ctab_fnc_reportTypes) select 0] call uksf_ctab_fnc_reportsSetType
*/
params ["_type"];
_type params ["", "_fields"];

{
    _x params ["_label", "_edit"];
    private _field = _fields param [_forEachIndex, []];
    _label ctrlShow (_field isNotEqualTo []);
    _edit ctrlShow (_field isNotEqualTo []);
    if (_field isEqualTo []) then {continue};

    _field params ["_title", "_default"];
    _label ctrlSetText _title;
    _edit ctrlSetText (switch (_default) do {
        case "grid": {[getPosASL cTab_player] call ctab_core_fnc_gridPosition};
        case "time": {call cTab_fnc_currentTime};
        case "callsign": {groupId group cTab_player};
        default {""};
    });
} forEach APP_CTRL(reportRows);

[APP_CTRL(reportStatus), []] call FUNC(setInfo);
