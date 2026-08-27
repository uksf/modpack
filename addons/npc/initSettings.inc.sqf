// Silence gap (seconds) before a room's utterances are batched into a turn — server-scoped.
[
    QGVAR(debounceSeconds),
    "SLIDER",
    ["NPC turn debounce (s)", "Silence gap before sending an NPC turn to the API."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 5, 0.6, 1],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(audioRange),
    "SLIDER",
    ["NPC audio range (m)", "Push NPC speech to players within this range."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [5, 100, 30, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(hearingRadius),
    "SLIDER",
    ["NPC hearing radius (m)", "How far a spoken utterance carries to talkable NPCs."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [5, 50, 15, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(gateScanRadius),
    "SLIDER",
    ["NPC gate scan (m)", "Upper bound for the addressing scan. Each NPC still uses its own gate range."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [5, 50, 25, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(gateRange),
    "SLIDER",
    ["NPC default gate range (m)", "Fallback addressing range when the unit has no own value."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 25, 4, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(gateFov),
    "SLIDER",
    ["NPC default gate FOV (deg)", "Fallback addressing cone when the unit has no own value."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [10, 180, 90, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(gateSwitchMargin),
    "SLIDER",
    ["NPC gate switch margin", "How much closer to the crosshair a rival must be before the target can change."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 0.05, 0.004, 3],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(gateSwitchFrames),
    "SLIDER",
    ["NPC gate switch frames", "How many gate ticks a rival must lead before the target changes."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 20, 8, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(watchHold),
    "SLIDER",
    ["NPC watch hold (s)", "How long an NPC keeps watching the last speaker."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 30, 10, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(emoteHold),
    "SLIDER",
    ["NPC emote hold (s)", "How long a floating emote stays up."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 20, 6, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(hintHold),
    "SLIDER",
    ["NPC hint hold (s)", "How long a test state hint stays up."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 60, 15, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(fillerDelay),
    "SLIDER",
    ["NPC filler delay (s)", "Silence before the first filler chance."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 10, 3.5, 1],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(fillerChance),
    "SLIDER",
    ["NPC filler chance", "Chance a wait-point plays a filler."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 1, 0.3, 2],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(fillerShortWindow),
    "SLIDER",
    ["NPC filler short window (s)", "Inside this window a filler uses the short noise class."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 15, 5, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(fillerGapMin),
    "SLIDER",
    ["NPC filler gap min (s)", "Minimum pause after a filler before another can fire."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0.5, 10, 2.6, 1],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(fillerGapSpread),
    "SLIDER",
    ["NPC filler gap spread (s)", "Random extra pause after a filler."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 10, 3, 1],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(fillerMaxPerTurn),
    "SLIDER",
    ["NPC fillers per turn", "Hard cap on fillers for one turn."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [1, 8, 4, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(streamStale),
    "SLIDER",
    ["NPC stream retain (s)", "How long a completed stream is kept for walk-up replay."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [5, 120, 30, 0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(speechPrebuffer),
    "SLIDER",
    ["NPC speech prebuffer (s)", "Delay before the mouth starts on a streamed reply."],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    [0, 1, 0.2, 2],
    1
] call CBA_fnc_addSetting;
