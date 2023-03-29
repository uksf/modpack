[
    QGVAR(enabled),
    "CHECKBOX",
    ["Caching", "Enables AI Caching"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    1
] call CBA_fnc_addSetting;

[
    QGVAR(distance),
    "SLIDER",
    ["Caching Distance", "Sets distance from players in metres within which AI will always uncache"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [300, 2000, 750, 0],
    1
] call CBA_fnc_addSetting;
