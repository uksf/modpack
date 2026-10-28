#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the report formats of the Reports app.
        Each field has a label and a default: "grid" for the player's grid, "time" for the cTab time, "callsign" for the player's group, or "" for none.
        A grid field also adds a cTab marker at that grid for each recipient.

    Parameter(s):
        None

    Return Value:
        Report formats as [title, [[label, default], ...]] <ARRAY>

    Example:
        call uksf_ctab_fnc_reportTypes
*/
[
    ["TIC", [["Location", "grid"], ["Callsign", "callsign"], ["Enemy", ""], ["Direction and distance", ""], ["Friendly status", ""], ["Request", ""]]],
    ["TIC CLEAR", [["Location", "grid"], ["Callsign", "callsign"], ["Friendly status", ""], ["Remarks", ""]]],
    ["EAGLE DOWN", [["Location", "grid"], ["Aircraft", ""], ["Crew status", ""], ["Enemy in area", ""], ["Remarks", ""]]],
    ["BDA", [["Target location", "grid"], ["Target", ""], ["Effect", ""], ["Re-attack", ""], ["Remarks", ""]]],
    ["SALUTE", [["Size", ""], ["Activity", ""], ["Location", "grid"], ["Unit", ""], ["Time", "time"], ["Equipment", ""]]],
    ["FRAGO", [["Situation", ""], ["Mission", ""], ["Execution", ""], ["Sustainment", ""], ["Command and signal", "callsign"]]]
]
