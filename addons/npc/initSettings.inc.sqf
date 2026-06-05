// Silence gap (seconds) before a room's utterances are batched into a turn — server-scoped.
[
    QGVAR(debounceSeconds),
    "SLIDER",
    ["NPC turn debounce (s)", "Silence gap before sending an NPC turn to the API."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0.5, 5, 1.5, 1],
    1
] call CBA_fnc_addSetting;

// Maximum distance (metres) at which audio is pushed to nearby clients — server-scoped.
[
    QGVAR(audioRange),
    "SLIDER",
    ["NPC audio range (m)", "Push NPC speech to players within this range."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [5, 100, 30, 0],
    1
] call CBA_fnc_addSetting;
