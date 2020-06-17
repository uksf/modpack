[
    QGVAR(allowDebug),
    "CHECKBOX",
    ["Allow Debug", "Allows debug to run"],
    COMPONENT_NAME,
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(enableGestures),
    "CHECKBOX",
    ["Enable Gestures", "Enables gesture interaction with civilians"],
    COMPONENT_NAME,
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(enableEscort),
    "CHECKBOX",
    ["Enable Escort", "Enables captive escort animations"],
    COMPONENT_NAME,
    true,
    1
] call CBA_settings_fnc_init;
