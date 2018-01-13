[
    QGVAR(enabled),
    "CHECKBOX",
    ["Cleanup", "Enables cleanup of dead units/vehicles"],
    "UKSF",
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(delay),
    "SLIDER",
    ["Cleanup Delay", "Delay in seconds between death and cleanup"],
    "UKSF",
    [5, 600, 300, 0],
    1
] call CBA_settings_fnc_init;
