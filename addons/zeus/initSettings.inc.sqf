[
    QGVAR(watchSmoothing),
    "SLIDER",
    ["Watch Camera Smoothing", "How heavily the Watch camera smooths target follow. Higher values are smoother (less motion sickness, more follow lag); lower values are snappier. Default 0.78."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 0.95, 0.78, 2],
    0
] call CBA_fnc_addSetting;

[
    QGVAR(watchInvertY),
    "CHECKBOX",
    ["Watch Invert Y Axis", "Invert the vertical axis when orbiting the Watch camera (Left Shift + mouse). Off = pitch up by moving mouse up."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    0
] call CBA_fnc_addSetting;
