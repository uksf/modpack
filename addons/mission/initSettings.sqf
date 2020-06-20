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

// Dynamic Patrols
[
    QGVAR(dynamicPatrolEnabled),
    "CHECKBOX",
    ["Dynamic Patrols Enbled", "Determines if basic dynamic patrol spawning is enabled"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    false,
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolCooldown),
    "SLIDER",
    ["Dynamic Patrol Spawn Cooldown", "Time in seconds between dynamic patrol group spawns"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [60, 3600, 600, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolGroupLimit),
    "SLIDER",
    ["Dynamic Patrol Group Limit", "Maximum number of active dynamic patrol groups allowed"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [1, 15, 10, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolVehicleProbability),
    "SLIDER",
    ["Dynamic Patrol Vehicle Spawn Probability", "Probability of spawning a vehicle in place of a group"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [0, 1, 0.2, 2],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolCombatMode),
    "LIST",
    ["Dynamic Patrol Group Combat Mode", "Combat mode of spawned dynamic patrol groups"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [
        ["SAFE", "AWARE", "COMBAT"],
        ["SAFE", "AWARE", "COMBAT"],
        0
    ],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolSpeed),
    "LIST",
    ["Dynamic Patrol Group Speed", "Speed of spawned dynamic patrol groups"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [
        ["LIMITED","NORMAL","FULL"],
        ["LIMITED","NORMAL","FULL"],
        0
    ],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolSafeZoneDistance),
    "SLIDER",
    ["Dynamic Patrol Safe Zone Distance", "Dynamic patrols will not spawn near the player if they are within this distance to safe zones (respawn points by default)"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [1500, 7500, 3000, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolDistance),
    "SLIDER",
    ["Dynamic Patrol Spawn Distance", "Dynamic patrols will spawn beyond this distance from the player"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [500, 1500, 750, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolVehicleDistanceCoef),
    "SLIDER",
    ["Dynamic Patrol Vehicle Spawn Distance Coef", "Dynamic patrol vehicles will spawn beyond the base spawn distance multiplied by this coefficient from the player"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [0.1, 5, 2, 1],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolWaypointDistance),
    "SLIDER",
    ["Dynamic Patrol Waypoint Distance", "Distance away from a player for the waypoint of a dynamic patrol"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [10, 500, 100, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolVehicleWaypointDistance),
    "SLIDER",
    ["Dynamic Patrol Vehicle Waypoint Distance", "Distance away from a player for the waypoint of a dynamic vehicle patrol"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [50, 750, 200, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolMinUnits),
    "SLIDER",
    ["Dynamic Patrol Minimum Units", "Minimum number of units per dynamic patrol group. There will be random deviations above this number"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [2, 11, 3, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolMaxUnits),
    "SLIDER",
    ["Dynamic Patrol Maximum Units", "Maximum number of units per dynamic patrol group. There will be random deviations below this number"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [4, 12, 6, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolMinGroups),
    "SLIDER",
    ["Dynamic Patrol Minimum Groups", "Minimum number of groups per dynamic patrol. There will be random deviations above this number"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [1, 3, 1, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolMaxGroups),
    "SLIDER",
    ["Dynamic Patrol Maximum Groups", "Maximum number of units per dynamic patrol. There will be random deviations below this number"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [1, 4, 2, 0],
    1
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolUnitPoolString),
    "EDITBOX",
    ["Dynamic Patrol Units Pool", "Class names of units that can spawn in dynamic patrol groups. Comma-separated list of class names in single quotes, no spaces"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    "['O_Soldier_F']",
    1,
    {GVAR(dynamicPatrolUnitPool) = call compile _this;}
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolVehiclePoolString),
    "EDITBOX",
    ["Dynamic Patrol Vehicles Pool", "Class names of vehicles that can spawn in dynamic patrol groups. Comma-separated list of class names in single quotes, no spaces"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    "['O_MBT_02_cannon_F']",
    1,
    {GVAR(dynamicPatrolVehiclePool) = call compile _this;}
] call CBA_settings_fnc_init;

[
    QGVAR(dynamicPatrolUnitSide),
    "LIST",
    ["Dynamic Patrol Side", "Side of spawned dynamic patrol groups"],
    [COMPONENT_NAME, "Dynamic Patrol"],
    [
        [0, 1, 2],
        ["East", "Independent", "West"],
        0
    ],
    1,
    {GVAR(dynamicPatrolSide) = ([EAST, INDEPENDENT, WEST]#_this);}
] call CBA_Settings_fnc_init;
