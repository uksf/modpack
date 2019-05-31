[
    QGVAR(enabled),
    "CHECKBOX",
    ["Caching", "Enables AI Caching"],
    "UKSF",
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(distance),
    "SLIDER",
    ["Caching Distance", "Sets distance from players in metres within which AI will always uncache"],
    "UKSF",
    [300, 2000, 750, 0],
    1
] call CBA_settings_fnc_init;
