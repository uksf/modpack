[
    QGVAR(curatorsLocked),
    "CHECKBOX",
    ["Curators Locked", "Locks access to curators on mission start"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(curatorsMax),
    "SLIDER",
    ["Maximum Curators", "Maximum number of curators allowed"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 10, 8, 0],
    1
] call CBA_settings_fnc_init;
