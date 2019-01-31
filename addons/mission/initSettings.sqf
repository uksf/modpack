[
    QGVAR(support),
    "CHECKBOX",
    ["Support", "Determines if this op should use AI support functions"],
    "UKSF",
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(conspicuity),
    "CHECKBOX",
    ["Conspicuity", "Determines if this op should use conspicuity checks"],
    "UKSF",
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(conspicuityGearWhitelistString),
    "EDITBOX",
    ["Conspicuity gear whitelist", "Allows items to be ignored in conspicuity checks. Supports weapons and backpacks only"],
    "UKSF",
    "[]",
    1
] call CBA_settings_fnc_init;
