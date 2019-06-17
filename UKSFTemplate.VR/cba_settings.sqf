// Change to false for side ops
force uksf_common_mainOp = true;

// Change these per mission if required
force uksf_caching_enabled = false;
force uksf_caching_distance = 750;
force uksf_cleanup_enabled = true;
force uksf_cleanup_delay = 300;
force uksf_curator_curatorsMax = 8;

// Change to true to use mission datetime with a persistence save
force uksf_persistence_overrideSavedDateTime = false;

// Change to false to disable AI support functions
force uksf_mission_support = true;
// Defines distance in metres that AI groups will support each other. Larger values could affect performance. min 250, max 1500
force uksf_mission_supportDistance = 500;

// Change to true to enable conspicuity
force uksf_mission_conspicuity = false;
// Add class names of gear to whitelist in conspicuity checks. Works with weapon, backpack, and uniform classnames ONLY. e.g "['B_fieldPack_blk','Rangefinder']"
force uksf_mission_conspicuityGearWhitelistString = "[]";
