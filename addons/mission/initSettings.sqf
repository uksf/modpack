// Conspicuity
[
    QGVAR(conspicuity),
    "CHECKBOX",
    ["Conspicuity", "Determines if this op should use player conspicuity checks"],
    ["UKSF", "Conspicuity"],
    false,
    1,
    {
        params ["_value"];

        if (hasInterface) then {
            if (_value) then {
                GVAR(conspicuityLoadoutEHID) = ["loadout", {[_this#0] call FUNC(conspicuity)}] call CBA_fnc_addPlayerEventHandler;
                GVAR(conspicuityWeaponEHID) = ["weapon", {call FUNC(conspicuity)}, true] call CBA_fnc_addPlayerEventHandler;
            } else {
                ["loadout", GVAR(conspicuityLoadoutEHID)] call CBA_fnc_removePlayerEventHandler;
                ["weapon", GVAR(conspicuityWeaponEHID)] call CBA_fnc_removePlayerEventHandler;
            };
        };
    }
] call CBA_settings_fnc_init;

[
    QGVAR(conspicuityGearWhitelistString),
    "EDITBOX",
    ["Conspicuity gear whitelist", "Allows items to be ignored in conspicuity checks. Supports weapons, backpacks, and uniforms only"],
    ["UKSF", "Conspicuity"],
    "[]",
    1,
    {
        params ["_value"];
        GVAR(conspicuityGearWhitelist) = call compile _value;
        GVAR(conspicuityGearWhitelist) append CONSPICUITY_DEFAULT_WHITELIST;
    }
] call CBA_settings_fnc_init;

// Basic support
[
    QGVAR(support),
    "CHECKBOX",
    ["Support", "Determines if basic AI support functionality is used"],
    ["UKSF", "Support"],
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(supportChance),
    "SLIDER",
    ["Support Chance", "Chance for support to be called in by AI"],
    ["UKSF", "Support"],
    [0, 50, 25, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(supportDistance),
    "SLIDER",
    ["Support Distance", "Defines distance (m) that AI groups will support each other. Emulates short-range radio communications. Larger values could adversely affect performance"],
    ["UKSF", "Support"],
    [250, 1500, 500, 0],
    1
] call CBA_settings_fnc_init;

// Artillery Support
[
    QGVAR(artillerySupport),
    "CHECKBOX",
    ["Artillery Support", "Determines if AI should be able to call in artillery support"],
    ["UKSF", "Artillery Support"],
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportChance),
    "SLIDER",
    ["Artillery Support Chance", "Chance for artillery to be called in by AI"],
    ["UKSF", "Artillery Support"],
    [0, 50, 5, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportBaseDistance),
    "SLIDER",
    ["Artillery Base Distance", "Distance (m) to determine if artillery is in radio range. Defined as radius around unit"],
    ["UKSF", "Artillery Support"],
    [500, 2000, 500, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportRtoDistance),
    "SLIDER",
    ["Artillery RTO Distance", "Distance (m) to determine if artillery is in radio range of an RTO. Defined as radius around unit"],
    ["UKSF", "Artillery Support"],
    [500, 5000, 1000, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportMastDistance),
    "SLIDER",
    ["Artillery Mast Distance", "Distance (m) to determine if artillery is in radio range of a mast. Defined as radius around object"],
    ["UKSF", "Artillery Support"],
    [500, 10000, 2000, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportRtoBackpacksString),
    "EDITBOX",
    ["RTO Backpacks", "Class names for backpacks that determine if a unit is an RTO"],
    ["UKSF", "Artillery Support"],
    "['UK3CB_BAF_B_Bergen_OLI_JTAC_A']",
    1,
    {
        params ["_value"];
        GVAR(artillerySupportRtoBackpacks) = call compile _value;
    }
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportFoBackpacksString),
    "EDITBOX",
    ["FO Backpacks", "Class names for backpacks that determine if a unit is a FO"],
    ["UKSF", "Artillery Support"],
    "['UK3CB_BAF_B_Bergen_OLI_JTAC_H_A']",
    1,
    {
        params ["_value"];
        GVAR(artillerySupportRtoBackpacks) = call compile _value;
    }
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportMastObjectsString),
    "EDITBOX",
    ["Mast Objects", "Class names for mast objects"],
    ["UKSF", "Artillery Support"],
    "['Land_antenna','Land_Communication_F','acre_oe_303']",
    1,
    {
        params ["_value"];
        GVAR(artillerySupportRtoBackpacks) = call compile _value;
    }
] call CBA_settings_fnc_init;
