[
    QGVAR(support),
    "CHECKBOX",
    ["Support", "Determines if this op should use AI support functionality"],
    ["UKSF", "Support"],
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(supportDistance),
    "SLIDER",
    ["Support", "Defines distance in metres that AI groups will support each other. Emulates short-range radio communications. Larger values could affect performance."],
    ["UKSF", "Support"],
    [250, 1500, 500, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(conspicuity),
    "CHECKBOX",
    ["Conspicuity", "Determines if this op should use player conspicuity checks"],
    ["UKSF", "Conspicuity"],
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(conspicuityGearWhitelistString),
    "EDITBOX",
    ["Conspicuity gear whitelist", "Allows items to be ignored in conspicuity checks. Supports weapons, backpacks, and uniforms only"],
    ["UKSF", "Conspicuity"],
    "[]",
    1
] call CBA_settings_fnc_init;
