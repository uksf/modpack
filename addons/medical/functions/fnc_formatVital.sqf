#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Formats a single vital reading as parseText structured text with colour-state.

    Parameter(s):
        0: Label <STRING>
        1: Value <STRING>
        2: Unit <STRING>
        3: Severity <STRING> — "normal" | "warn" | "critical"

    Return Value:
        Formatted string ready for ctrlSetStructuredText <STRING>

    Example:
        ["HR", "72", "bpm", "normal"] call uksf_medical_fnc_formatVital
*/
params ["_label", "_value", "_unitText", "_severity"];

private _colour = switch (_severity) do {
    case "warn": { "#ff9900" };
    case "critical": { "#ff3333" };
    default { "#ffffff" };
};

format ["<t color='#aaaaaa'>%1:</t> <t color='%2'>%3 %4</t>", _label, _colour, _value, _unitText]
