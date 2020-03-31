// Conspicuity
[
    QGVAR(conspicuity),
    "CHECKBOX",
    ["Conspicuity", "Determines if this op should use player conspicuity checks"],
    [COMPONENT_NAME, "Conspicuity"],
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
    [COMPONENT_NAME, "Conspicuity"],
    "[]",
    1,
    {
        GVAR(conspicuityGearWhitelist) = call compile _this;
        GVAR(conspicuityGearWhitelist) append CONSPICUITY_DEFAULT_WHITELIST;
    }
] call CBA_settings_fnc_init;

// Basic support
[
    QGVAR(support),
    "CHECKBOX",
    ["Support", "Determines if basic AI support functionality is used"],
    [COMPONENT_NAME, "Support"],
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(supportChance),
    "SLIDER",
    ["Support Chance", "Chance for support to be called in by AI"],
    [COMPONENT_NAME, "Support"],
    [0, 50, 25, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(supportDistance),
    "SLIDER",
    ["Support Distance", "Defines distance (m) that AI groups will support each other. Emulates short-range radio communications. Larger values could adversely affect performance"],
    [COMPONENT_NAME, "Support"],
    [250, 1500, 500, 0],
    1
] call CBA_settings_fnc_init;

// Artillery Support
[
    QGVAR(artillerySupport),
    "CHECKBOX",
    ["Artillery Support", "Determines if AI should be able to call in artillery support"],
    [COMPONENT_NAME, "Artillery Support"],
    true,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportChance),
    "SLIDER",
    ["Artillery Support Chance", "Chance for artillery to be called in by AI"],
    [COMPONENT_NAME, "Artillery Support"],
    [0, 50, 5, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportBaseDistance),
    "SLIDER",
    ["Artillery Base Distance", "Distance (m) to determine if artillery is in radio range. Defined as radius around unit"],
    [COMPONENT_NAME, "Artillery Support"],
    [500, 2000, 500, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportRtoDistance),
    "SLIDER",
    ["Artillery RTO Distance", "Distance (m) to determine if artillery is in radio range of an RTO. Defined as radius around unit"],
    [COMPONENT_NAME, "Artillery Support"],
    [500, 5000, 1000, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportMastDistance),
    "SLIDER",
    ["Artillery Mast Distance", "Distance (m) to determine if artillery is in radio range of a mast. Defined as radius around object"],
    [COMPONENT_NAME, "Artillery Support"],
    [500, 10000, 2000, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportRtoBackpacksString),
    "EDITBOX",
    ["RTO Backpacks", "Class names for backpacks that determine if a unit is an RTO"],
    [COMPONENT_NAME, "Artillery Support"],
    "['UK3CB_BAF_B_Bergen_OLI_JTAC_A']",
    1,
    {GVAR(artillerySupportRtoBackpacks) = call compile _this;}
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportFoBackpacksString),
    "EDITBOX",
    ["FO Backpacks", "Class names for backpacks that determine if a unit is a FO"],
    [COMPONENT_NAME, "Artillery Support"],
    "['UK3CB_BAF_B_Bergen_OLI_JTAC_H_A']",
    1,
    {GVAR(artillerySupportFoBackpacks) = call compile _this;}
] call CBA_settings_fnc_init;

[
    QGVAR(artillerySupportMastObjectsString),
    "EDITBOX",
    ["Mast Objects", "Class names for mast objects"],
    [COMPONENT_NAME, "Artillery Support"],
    "['Land_antenna','Land_Communication_F','acre_oe_303']",
    1,
    {GVAR(artillerySupportMastObjects) = call compile _this;}
] call CBA_settings_fnc_init;

// Patrols
[
    QGVAR(patrolEnabled),
    "CHECKBOX",
    ["Patrols Enbled", "Determines if basic random patrol spawning is enabled"],
    [COMPONENT_NAME, "Patrol"],
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolCooldown),
    "SLIDER",
    ["Patrol Spawn Cooldown", "Time in seconds between patrol group spawns"],
    [COMPONENT_NAME, "Patrol"],
    [60, 3600, 600, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolGroupLimit),
    "SLIDER",
    ["Patrol Group Limit", "Maximum number of active patrol groups allowed"],
    [COMPONENT_NAME, "Patrol"],
    [1, 15, 10, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolVehicleProbability),
    "SLIDER",
    ["Patrol Vehicle Spawn Probability", "Probability of spawning a vehicle in place of a group"],
    [COMPONENT_NAME, "Patrol"],
    [0, 1, 0.2, 2],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolCombatMode),
    "LIST",
    ["Patrol Group Combat Mode", "Combat mode of spawned patrol groups"],
    [COMPONENT_NAME, "Patrol"],
    [
        ["SAFE", "AWARE", "COMBAT"],
        ["SAFE", "AWARE", "COMBAT"],
        0
    ],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolSpeed),
    "LIST",
    ["Patrol Group Speed", "Speed of spawned patrol groups"],
    [COMPONENT_NAME, "Patrol"],
    [
        ["LIMITED","NORMAL","FULL"],
        ["LIMITED","NORMAL","FULL"],
        0
    ],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolSafeZoneDistance),
    "SLIDER",
    ["Patrol Safe Zone Distance", "Patrols will not spawn near the player if they are within this distance to safe zones (respawn points by default)"],
    [COMPONENT_NAME, "Patrol"],
    [1500, 7500, 3000, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolDistance),
    "SLIDER",
    ["Patrol Spawn Distance", "Patrols will spawn beyond this distance from the player"],
    [COMPONENT_NAME, "Patrol"],
    [500, 1500, 750, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolVehicleDistanceCoef),
    "SLIDER",
    ["Patrol Vehicle Spawn Distance Coef", "Patrol vehicles will spawn beyond the base spawn distance multiplied by this coefficient from the player"],
    [COMPONENT_NAME, "Patrol"],
    [0.1, 5, 2, 1],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolMinUnits),
    "SLIDER",
    ["Patrol Minimum Units", "Minimum number of units per patrol group. There will be random deviations above this number"],
    [COMPONENT_NAME, "Patrol"],
    [2, 11, 3, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolMaxUnits),
    "SLIDER",
    ["Patrol Maximum Units", "Maximum number of units per patrol group. There will be random deviations below this number"],
    [COMPONENT_NAME, "Patrol"],
    [4, 12, 6, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolMinGroups),
    "SLIDER",
    ["Patrol Minimum Groups", "Minimum number of groups per patrol. There will be random deviations above this number"],
    [COMPONENT_NAME, "Patrol"],
    [1, 3, 1, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolMaxGroups),
    "SLIDER",
    ["Patrol Maximum Groups", "Maximum number of units per patrol. There will be random deviations below this number"],
    [COMPONENT_NAME, "Patrol"],
    [1, 4, 2, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(patrolUnitPoolString),
    "EDITBOX",
    ["Patrol Units Pool", "Class names of units that can spawn in patrol groups. Comma-separated list of class names in single quotes, no spaces"],
    [COMPONENT_NAME, "Patrol"],
    "['O_Soldier_F']",
    1,
    {GVAR(patrolUnitPool) = call compile _this;}
] call CBA_settings_fnc_init;

[
    QGVAR(patrolVehiclePoolString),
    "EDITBOX",
    ["Patrol Vehicles Pool", "Class names of vehicles that can spawn in patrol groups. Comma-separated list of class names in single quotes, no spaces"],
    [COMPONENT_NAME, "Patrol"],
    "['O_MBT_02_cannon_F']",
    1,
    {GVAR(patrolVehiclePool) = call compile _this;}
] call CBA_settings_fnc_init;

[
    QGVAR(patrolUnitSide),
    "LIST",
    ["Player and Enemy Sides", "Side of spawned patrol groups"],
    [COMPONENT_NAME, "Patrol"],
    [
        [EAST, INDEPENDENT, WEST],
        ["East", "Independent", "West"],
        0
    ],
    1,
    {GVAR(patrolSide) = _this;}
] call CBA_Settings_fnc_init;
