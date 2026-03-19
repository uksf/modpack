[
    QGVAR(enabled),
    "CHECKBOX",
    ["Enabled", "Enable blast overpressure damage for large explosions"],
    [COMPONENT_NAME, "General"],
    true,
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(threshold),
    "SLIDER",
    ["Explosion threshold", "Minimum explosion power to trigger overpressure. Formula: indirectHit * sqrt(indirectHitRange). Lower = more explosions processed. (10 - 200)"],
    [COMPONENT_NAME, "General"],
    [10, 200, 50, 0],
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(rangeMultiplier),
    "SLIDER",
    ["Range multiplier", "How far beyond indirectHitRange the overpressure extends. (1.0 - 3.0)"],
    [COMPONENT_NAME, "General"],
    [1, 3, 1.5, 1],
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(damageMultiplier),
    "SLIDER",
    ["Damage multiplier", "Global scaling for overpressure damage. (0.1 - 2.0)"],
    [COMPONENT_NAME, "General"],
    [0.1, 2, 1, 1],
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(surfaceBounceEnabled),
    "CHECKBOX",
    ["Surface bounce tracing", "Enable Phase 2 surface bounce tracing for units inside buildings. Disable for performance."],
    [COMPONENT_NAME, "General"],
    true,
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(mode),
    "LIST",
    ["Processing mode", "Pressure wave simulates blast propagation per-unit. Path trace is lighter on performance."],
    [COMPONENT_NAME, "General"],
    [["path_trace", "pressure_wave"], ["Path Trace", "Pressure Wave"], 1],
    1
] call CBA_Settings_fnc_init;
