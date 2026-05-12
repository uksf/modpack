[
    QGVAR(modEnabled),
    "CHECKBOX",
    ["Enable Uncon Dialog", "Master toggle for the unconscious player dialog."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(showSpectator),
    "CHECKBOX",
    ["Show Spectator Tab", "Display the spectator tab while unconscious."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(showHealth),
    "CHECKBOX",
    ["Show Health Tab", "Display the medical readout tab while unconscious."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(spectatorDistance),
    "SLIDER",
    ["Spectator Max Distance", "Maximum distance to consider an ally for spectating, in metres."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [10, 500, 50, 0],
    0
] call CBA_fnc_addSetting;

[
    QGVAR(spectatorNVGMode),
    "LIST",
    ["Spectator NVG Mode", "Camera vision mode while spectating."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [[0, 1], ["Normal", "Force Unit Perspective"], 0],
    0
] call CBA_fnc_addSetting;

[
    QGVAR(showHR),
    "CHECKBOX",
    ["Show Heart Rate", "Display heart rate in the health tab."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(showBP),
    "CHECKBOX",
    ["Show Blood Pressure", "Display blood pressure in the health tab."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(showResp),
    "CHECKBOX",
    ["Show Respiration Rate", "Display respiration rate in the health tab."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(showSpO2),
    "CHECKBOX",
    ["Show SpO2", "Display blood oxygen saturation in the health tab."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(showStateTimer),
    "CHECKBOX",
    ["Show State Timer", "Display coma / cardiac arrest countdown."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(soundOnStateChange),
    "CHECKBOX",
    ["Sound On State Change", "Play a cue when transitioning between uncon / cardiac / coma."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    true,
    0
] call CBA_fnc_addSetting;

[
    QGVAR(defaultTab),
    "LIST",
    ["Default Tab", "Tab shown when the dialog opens."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [["spectator", "health"], ["Spectator", "Health"], 0],
    0
] call CBA_fnc_addSetting;

[
    QGVAR(viewModeDefault),
    "LIST",
    ["Health View Default", "Default display mode for the health tab."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [["full", "minimal"], ["Full", "Minimal"], 0],
    0
] call CBA_fnc_addSetting;
