class CfgDifficultyPresets {
    class Custom;
    class GVAR(uksf) : Custom {
        description = "Difficulty preset for UKSF operations";
        displayName = "UKSF";
        optionDescription = "Difficulty preset for UKSF operations";
        levelAI = QGVAR(uksf);
        class Options {
            autoReport = 0;
            cameraShake = 1;
            commands = 0;
            deathMessages = 0;
            detectedMines = 0;
            enemyTags = 0;
            friendlyTags = 0;
            groupIndicators = 0;
            mapContent = 0;
            mapContentEnemy = 0;
            mapContentFriendly = 0;
            mapContentMines = 0;
            mapContentPing = 0;
            multipleSaves = 0;
            reducedDamage = 0;
            scoreTable = 0;
            squadRadar = 0;
            staminaBar = 0;
            stanceIndicator = 1;
            tacticalPing = 0;
            thirdPersonView = 1;
            visionAid = 0;
            vonID = 0;
            waypoints = 0;
            weaponCrosshair = 0;
            weaponInfo = 1;
        };
    };
    defaultPreset = QGVAR(uksf);
};
