[
    QGVAR(modEnabled),
    "CHECKBOX",
    ["Enable Uncon Dialog", "Master toggle for the unconscious player dialog."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(spectatorDistance),
    "SLIDER",
    ["Spectator Max Distance", "Maximum distance to consider an ally for spectating, in metres."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [10, 500, 50, 0],
    0
] call CBA_fnc_addSetting;

[
    QGVAR(spectatorNVGMode),
    "LIST",
    ["Spectator NVG Mode", "Camera vision mode while spectating."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [[0, 1], ["Normal", "Force Unit Perspective"], 0],
    0
] call CBA_fnc_addSetting;
