[
    QGVAR(tissueSaturationMultiplier),
    "SLIDER",
    ["Tissue Saturation Multiplier", "Scales inert gas load above surface level when calculating the ceiling. 1 is real Buhlmann ZH-L16C. Default 1.25."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 1.75, 1.25, 2],
    1
] call CBA_fnc_addSetting;
