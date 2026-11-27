[
    QGVAR(emptyDynamicSimulation),
    "CHECKBOX",
    ["Empty vehicle dynamic simulation", "Stops simulating empty land vehicles while no player is near. A vehicle wakes when a player comes within the empty vehicle dynamic simulation distance, and leaves dynamic simulation when anyone gets in."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    1
] call CBA_settings_fnc_init;
