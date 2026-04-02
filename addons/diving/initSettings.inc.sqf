[
    QGVAR(tissueSaturationMultiplier),
    "SLIDER",
    ["Tissue Saturation Multiplier", "Scales how aggressively tissues saturate with inert gas. Higher values mean faster deco obligations. Default 1.5."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0.5, 5, 1.5, 1],
    1
] call CBA_fnc_addSetting;
