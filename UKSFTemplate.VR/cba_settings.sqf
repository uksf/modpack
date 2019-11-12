// Change to false for side ops
force uksf_common_mainOp = true;

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
