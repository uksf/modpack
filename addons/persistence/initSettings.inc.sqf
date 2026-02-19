[
    QGVAR(overrideSavedDateTime),
    "CHECKBOX",
    ["Override Datetime", "Overrides saved datetime with mission datetime"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(loadMapMarkers),
    "CHECKBOX",
    ["Load markers", "Loads markers from saved data. Use only for missions that are known to be across more than one day"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    1
] call CBA_settings_fnc_init;
