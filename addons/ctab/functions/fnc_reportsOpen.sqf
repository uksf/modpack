#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Reports app.
        The player picks a report format, fills its fields, picks recipients, and sends the report as a cTab message.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group] call uksf_ctab_fnc_reportsOpen
*/
params ["", "_group"];

private _types = call FUNC(reportTypes);
private _rows = [];
for "_row" from 0 to REPORT_FIELDS - 1 do {
    private _top = 0.14 + _row * 0.12;
    _rows pushBack [
        [_group, "cTab_RscText", [0.02, _top, 0.22, 0.1]] call FUNC(createCtrl),
        [_group, "cTab_RscEdit", [0.25, _top, 0.35, 0.1]] call FUNC(createCtrl)
    ];
};
uiNamespace setVariable [QGVAR(reportRows), _rows];

[_group, [0.02, 0.03, 0.58, 0.08], _types apply {[_x select 0, _x]}, GVAR(reportType), {
    params ["_type"];
    GVAR(reportType) = _type;
    [_type] call FUNC(reportsSetType);
}] call FUNC(createCombo);

[_group, "cTab_RscText", [0.63, 0.03, 0.35, 0.08], "Send to"] call FUNC(createCtrl);
private _recipients = [_group, QGVAR(listBoxMulti), [0.63, 0.12, 0.35, 0.56]] call FUNC(createCtrl);
[_recipients] call ctab_messaging_fnc_fillRecipientList;
uiNamespace setVariable [QGVAR(reportRecipients), _recipients];

uiNamespace setVariable [QGVAR(reportStatus), [_group, [0.63, 0.83, 0.35, 0.14]] call FUNC(createInfo)];
[_group, [0.63, 0.71, 0.35, 0.1], "Send", {call FUNC(reportsSend)}] call FUNC(createButton);

if (GVAR(reportType) isEqualTo []) then {
    GVAR(reportType) = _types select 0;
};
[GVAR(reportType)] call FUNC(reportsSetType);
