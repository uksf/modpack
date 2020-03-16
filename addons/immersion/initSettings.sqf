[
    QGVAR(force),
    "CHECKBOX",
    ["Enable Weapon Force", "Adds a slight radial blur and darkens the screen a bit for a split second when firing"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(recoil),
    "CHECKBOX",
    ["Enable Recoil", "Adds a slight CamShake when shooting, should make shooting the guns feel more satisfying"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    1
] call CBA_settings_fnc_init;
