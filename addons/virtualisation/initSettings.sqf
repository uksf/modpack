[
    QGVAR(enabled),
    "CHECKBOX",
    ["Virtualisation", "Enables AI Virtualisation"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    1
] call CBA_fnc_addSetting;

[
    QGVAR(distance),
    "SLIDER",
    ["Virtualisation Distance", "Sets distance from players in metres beyond which AI will be virtualised"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1000, 5000, 3000, 0],
    1
] call CBA_fnc_addSetting;
