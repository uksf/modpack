// Change to false for side ops
force uksf_common_mainOp = true;

// Change to false where specific pre-defined DPs for HAHO are mission-critical and cannot be defined during the mission based on measured wind
force ace_weather_windSimulation = true;

// For special missions only. Set value to 0 to disable vehicle weapon overpressure. Use this for tank battles etc
force ace_overpressure_overpressureDistanceCoefficient = 1;

// For special missions only. Set value to false to disable weapon overheating
force ace_overheating_enabled = true;

// For training missions only. 0 = Always, 1 = Cardiac Arrest, 2 = Never
force ace_medical_statemachine_fatalInjuriesAI = 0;
// For training missions only. Set to True to allow AI to go unconscious, instead of always dying
force ace_medical_statemachine_AIUnconsciousness = false;

// Change these per mission if required
force uksf_caching_enabled = false;
force uksf_caching_distance = 750;
force uksf_cleanup_enabled = true;
force uksf_cleanup_delay = 300;
force uksf_curator_curatorsMax = 8;

force uksf_virtualisation_enabled = false;
force uksf_virtualisation_distance = 3000;

// Change to true to laod map markers from saved data. Only enable this if this mission is a direct continuation of the previous mission
force uksf_persistence_loadMapMarkers = false;
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

// Determines if basic dynamic patrol spawning is enabled
force uksf_mission_dynamicPatrolEnabled = false;
// Time in seconds between dynamic patrol group spawns [60, 3600, 600, 0]
force uksf_mission_dynamicPatrolCooldown = 60;
// Maximum number of active dynamic patrol groups allowed [1, 15, 10, 0]
force uksf_mission_dynamicPatrolGroupLimit = 10;
// Probability of spawning a vehicle in place of a group [0, 1, 0.2, 2]
force uksf_mission_dynamicPatrolVehicleProbability = 0.2;
// Combat mode of spawned dynamic patrol groups ["SAFE", "AWARE", "COMBAT"]
force uksf_mission_dynamicPatrolCombatMode = "SAFE";
// Speed of spawned dynamic patrol groups ["LIMITED","NORMAL","FULL"]
force uksf_mission_dynamicPatrolSpeed = "LIMITED";
// Dynamic patrols will not spawn near the player if they are within this distance to safe zones (respawn points) [250, 7500, 3000, 0]
force uksf_mission_dynamicPatrolSafeZoneDistance = 3000;
// Dynamic patrols will spawn beyond this distance from the player [100, 1500, 750, 0]
force uksf_mission_dynamicPatrolDistance = 750;
// Dynamic patrol vehicles will spawn beyond the base spawn distance multiplied by this coefficient from the player [0.1, 5, 2, 1]
force uksf_mission_dynamicPatrolVehicleDistanceCoef = 2;
// Distance away from a player for the waypoint of a dynamic patrol [10, 500, 100, 0]
force uksf_mission_dynamicPatrolWaypointDistance = 100;
// Distance away from a player for the waypoint of a dynamic vehicle patrol [50, 750, 200, 0]
force uksf_mission_dynamicPatrolVehicleWaypointDistance = 200;
// Minimum number of groups per dynamic patrol. There will be random deviations above this number [1, 3, 1, 0]
force uksf_mission_dynamicPatrolMinGroups = 1;
// Maximum number of units per dynamic patrol. There will be random deviations below this number [1, 4, 2, 0]
force uksf_mission_dynamicPatrolMaxGroups = 2;
// Minimum number of units per dynamic patrol group. There will be random deviations above this number [2, 11, 3, 0]
force uksf_mission_dynamicPatrolMinUnits = 3;
// Maximum number of units per dynamic patrol group. There will be random deviations below this number [4, 12, 6, 0]
force uksf_mission_dynamicPatrolMaxUnits = 6;
// Class names of units that can spawn in dynamic patrol groups. Comma-separated list of class names in single quotes, no spaces
force uksf_mission_dynamicPatrolUnitPoolString = "['O_Soldier_F']";
// Class names of vehicles that can spawn in dynamic patrol groups. Comma-separated list of class names in single quotes, no spaces
force uksf_mission_dynamicPatrolVehiclePoolString = "['O_MBT_02_cannon_F']";
// Side of spawned dynamic patrol groups [0: EAST, 1: INDEPENDENT, 2: WEST]
force uksf_mission_dynamicPatrolUnitSide = 0;
// Time in minutes to delay running the dynamic patrol system from the start of the mission [0, 120, 0, 0]
force uksf_mission_dynamicPatrolStartDelay = 0;
