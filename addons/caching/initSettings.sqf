[
    QGVAR(enabled),
    "CHECKBOX",
    ["Caching", "Enables AI Caching"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(distance),
    "SLIDER",
    ["Caching Distance", "Sets distance from players in metres within which AI will uncache"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1000, 5000, 2000, 0],
    1
] call CBA_settings_fnc_init;
