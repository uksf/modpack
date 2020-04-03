[
    QGVAR(enableGestures),
    "CHECKBOX",
    ["Cleanup", "Enables gesture interaction with civilians"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(delay),
    "SLIDER",
    ["Cleanup Delay", "Delay in seconds between death and cleanup"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [5, 600, 300, 0],
    1
] call CBA_settings_fnc_init;
