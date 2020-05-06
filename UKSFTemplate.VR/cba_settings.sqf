// Change to false for side ops
force uksf_common_mainOp = true;

// Change to false where specific pre-defined DPs for HAHO are mission-critical and cannot be defined during the mission based on measured wind
force ace_weather_windSimulation = true;

// Change these per mission if required
force uksf_caching_enabled = false;
force uksf_caching_distance = 750;
force uksf_cleanup_enabled = true;
force uksf_cleanup_delay = 300;
force uksf_curator_curatorsMax = 4;

// Change to true to use mission datetime with a persistence save
force uksf_persistence_overrideSavedDateTime = false;

// Determines if basic AI support functionality is used
force uksf_mission_support = true;
// Chance for support to be called in by AI. Min 0, Max 50
force uksf_mission_supportChance = 25;
// Defines distance (m) that AI groups will support each other. Emulates short-range radio communications. Larger values could adversely affect performance. Min 250, Max 1500
force uksf_mission_supportDistance = 500;

// Determines if AI should be able to call in artillery support
force uksf_mission_artillerySupport = true;
// Chance for artillery to be called in by AI. Min 0, Max 50
force uksf_mission_artillerySupportChance = 5;
// Distance (m) to determine if artillery is in radio range. Defined as radius around unit. Min 500, Max 2000
force uksf_mission_artillerySupportBaseDistance = 500;
// Distance (m) to determine if artillery is in radio range of an RTO. Defined as radius around unit. Min 500, Max 5000
force uksf_mission_artillerySupportRtoDistance = 1000;
// Distance (m) to determine if artillery is in radio range of a mast. Defined as radius around object. Min 500, Max 10000
force uksf_mission_artillerySupportMastDistance = 2000;
// Class names for backpacks that determine if a unit is an RTO. e.g "['UK3CB_BAF_B_Bergen_OLI_JTAC_A','UK3CB_BAF_B_Bergen_OLI_JTAC_H_A']"
force uksf_mission_artillerySupportRtoBackpacksString = "['UK3CB_BAF_B_Bergen_OLI_JTAC_A']";
// Class names for backpacks that determine if a unit is a FO. e.g "['UK3CB_BAF_B_Bergen_OLI_JTAC_A','UK3CB_BAF_B_Bergen_OLI_JTAC_H_A']"
force uksf_mission_artillerySupportFoBackpacksString = "['UK3CB_BAF_B_Bergen_OLI_JTAC_H_A']";
// Class names for mast objects. e.g "['Land_antenna','Land_Communication_F','acre_oe_303']"
force uksf_mission_artillerySupportMastObjectsString = "['Land_antenna','Land_Communication_F','acre_oe_303']";

// Determines if this op should use player conspicuity checks
force uksf_mission_conspicuity = false;
// Allows items to be ignored in conspicuity checks. Supports weapons, backpacks, and uniforms only. e.g "['B_fieldPack_blk','Rangefinder']"
force uksf_mission_conspicuityGearWhitelistString = "[]";

// Determines if basic random patrol spawning is enabled
force uksf_mission_patrolEnabled = false;
// Time in seconds between patrol group spawns [60, 3600, 600, 0]
force uksf_mission_patrolCooldown = 60;
// Maximum number of active patrol groups allowed [1, 15, 10, 0]
force uksf_mission_patrolGroupLimit = 10;
// Probability of spawning a vehicle in place of a group [0, 1, 0.2, 2]
force uksf_mission_patrolVehicleProbability = 0.2;
// Combat mode of spawned patrol groups ["SAFE", "AWARE", "COMBAT"]
force uksf_mission_patrolCombatMode = "SAFE";
// Speed of spawned patrol groups ["LIMITED","NORMAL","FULL"]
force uksf_mission_patrolSpeed = "LIMITED";
// Patrols will not spawn near the player if they are within this distance to safe zones (respawn points) [1500, 7500, 3000, 0]
force uksf_mission_patrolSafeZoneDistance = 3000;
// Patrols will spawn beyond this distance from the player [500, 1500, 750, 0]
force uksf_mission_patrolDistance = 750;
// Patrol vehicles will spawn beyond the base spawn distance multiplied by this coefficient from the player [0.1, 5, 2, 1]
force uksf_mission_patrolVehicleDistanceCoef = 2;
// Distance away from a player for the waypoint of a patrol [10, 500, 100, 0]
force uksf_mission_patrolWaypointDistance = 100;
// Distance away from a player for the waypoint of a vehicle patrol [50, 750, 200, 0]
force uksf_mission_patrolVehicleWaypointDistance = 200;
// Minimum number of groups per patrol. There will be random deviations above this number [1, 3, 1, 0]
force uksf_mission_patrolMinGroups = 1;
// Maximum number of units per patrol. There will be random deviations below this number [1, 4, 2, 0]
force uksf_mission_patrolMaxGroups = 2;
// Minimum number of units per patrol group. There will be random deviations above this number [2, 11, 3, 0]
force uksf_mission_patrolMinUnits = 3;
// Maximum number of units per patrol group. There will be random deviations below this number [4, 12, 6, 0]
force uksf_mission_patrolMaxUnits = 6;
// Class names of units that can spawn in patrol groups. Comma-separated list of class names in single quotes, no spaces
force uksf_mission_patrolUnitPoolString = "['O_Soldier_F']";
// Class names of vehicles that can spawn in patrol groups. Comma-separated list of class names in single quotes, no spaces
force uksf_mission_patrolVehiclePoolString = "['O_MBT_02_cannon_F']";
// Side of spawned patrol groups [0: EAST, 1: INDEPENDENT, 2: WEST]
force uksf_mission_patrolUnitSide = 0;
