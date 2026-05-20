[
    QGVAR(segmentTargetMetres),
    "SLIDER",
    ["Curve segment length (m)", "Lower = smoother shape curves and more polyline points per shape."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [5, 100, 25, 0],
    0
] call CBA_settings_fnc_init;
