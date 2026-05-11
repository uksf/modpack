[
    QGVAR(suppression_enabled),
    "CHECKBOX",
    ["Enable the mod", "Enables player suppression effects"],
    [COMPONENT_NAME, "Suppression"],
    true,
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(suppression_recoveryFactor),
    "SLIDER",
    ["Recovery speed", "How slow or quick you recover from being suppressed. Lower value = longer lasting effects. (0.25 - 3)"],
    [COMPONENT_NAME, "Suppression"],
    [0.25, 3, 1, 2],
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(suppression_buildup),
    "SLIDER",
    ["Suppression build-up speed", "How fast the player will get suppressed. (0.25 - 3)"],
    [COMPONENT_NAME, "Suppression"],
    [0.25, 3, 1, 2],
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(suppression_intensity),
    "SLIDER",
    ["Suppression effect Intensity", "Overall intensity of the suppression effect. (0 - 3)"],
    [COMPONENT_NAME, "Suppression"],
    [0, 3, 1, 2],
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(suppression_flyByIntensity),
    "SLIDER",
    ["Flyby effect Intensity", "Overall intensity of the flyby effect. (0 - 3)"],
    [COMPONENT_NAME, "Suppression"],
    [0, 3, 1, 2],
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(suppression_haltRecovery),
    "CHECKBOX",
    ["Halt recovery when getting shot", "When turned on, recovery of suppression effects stagnates for a while when being shot at again."],
    [COMPONENT_NAME, "Suppression"],
    true,
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(closeMiss_enabled),
    "CHECKBOX",
    ["Enable close-miss reactions", "When a round passes within ~1m (or ~2m for .50 cal+) of the player, apply a small lateral aim flinch and camshake. First reaction is severe, repeated triggers within sustained fire diminish via inverse-square decay, full recovery after ~5min of silence. If the player has fired their own weapon recently, first reaction is reduced (already focused)."],
    [COMPONENT_NAME, "Close-miss"],
    false,
    1
] call CBA_Settings_fnc_init;
