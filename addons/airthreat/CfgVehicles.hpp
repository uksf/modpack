class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = QUOTE(ADDON);
        class AttributesBase;
    };
    class GVAR(controllerModule) : GVAR(module) {
        scope = 2;
        displayName = "(AT) Controller";
        icon = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        function = QFUNC(moduleController);
        class Attributes : AttributesBase {
            class GVAR(capReconBaseTime) {
                property = QGVAR(capReconBaseTime);
                displayName = "CAP/Recon Base Interval";
                tooltip = "Minimum time in seconds between CAP/recon mission spawns (300 - 3600, default: 1200)";
                control = "EditShort";
                validate = "NUMBER";
                min = 300;
                max = 3600;
                defaultValue = "1200";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(capReconBaseTime),_value,true)]);
            };
            class GVAR(capReconOffsetTime) {
                property = QGVAR(capReconOffsetTime);
                displayName = "CAP/Recon Offset Interval";
                tooltip = "Random additional time in seconds added to CAP/recon interval (0 - 1800, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 1800;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(capReconOffsetTime),_value,true)]);
            };
            class GVAR(initialDelay) {
                property = QGVAR(initialDelay);
                displayName = "Initial Delay";
                tooltip = "Time in seconds before the first CAP/recon mission spawns (0 - 7200, default: 1800)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 7200;
                defaultValue = "1800";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(initialDelay),_value,true)]);
            };
            class GVAR(initialDelayOffset) {
                property = QGVAR(initialDelayOffset);
                displayName = "Initial Delay Offset";
                tooltip = "Random additional time in seconds added to initial delay (0 - 3600, default: 900)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 3600;
                defaultValue = "900";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(initialDelayOffset),_value,true)]);
            };
            class GVAR(interceptCooldown) {
                property = QGVAR(interceptCooldown);
                displayName = "Intercept Cooldown";
                tooltip = "Minimum time in seconds between intercept spawns (60 - 3600, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
                min = 60;
                max = 3600;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(interceptCooldown),_value,true)]);
            };
            class GVAR(interceptCooldownOffset) {
                property = QGVAR(interceptCooldownOffset);
                displayName = "Intercept Cooldown Offset";
                tooltip = "Random additional time in seconds added to intercept cooldown (0 - 1800, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 1800;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(interceptCooldownOffset),_value,true)]);
            };
            class GVAR(maxConcurrentMissions) {
                property = QGVAR(maxConcurrentMissions);
                displayName = "Max Concurrent Missions";
                tooltip = "Maximum number of active air threat missions at once (1 - 10, default: 3)";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 10;
                defaultValue = "3";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(maxConcurrentMissions),_value,true)]);
            };
            class GVAR(fighterClassnames) {
                property = QGVAR(fighterClassnames);
                displayName = "Fighter Classnames";
                tooltip = "Array of aircraft classnames for CAP and intercept missions. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(fighterClassnames),_value,true)]);
            };
            class GVAR(casClassnames) {
                property = QGVAR(casClassnames);
                displayName = "CAS Classnames";
                tooltip = "Array of helicopter classnames for CAS missions. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(casClassnames),_value,true)]);
            };
            class GVAR(strikeClassnames) {
                property = QGVAR(strikeClassnames);
                displayName = "Strike Classnames";
                tooltip = "Array of jet classnames for strike/bombing missions. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(strikeClassnames),_value,true)]);
            };
            class GVAR(reconClassnames) {
                property = QGVAR(reconClassnames);
                displayName = "Recon Classnames";
                tooltip = "Array of drone/aircraft classnames for recon missions. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(reconClassnames),_value,true)]);
            };
            class GVAR(excludedClasses) {
                property = QGVAR(excludedClasses);
                displayName = "Excluded Player Classes";
                tooltip = "Array of unit classnames excluded from targeting. Players with these classes won't be selected as mission targets. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(excludedClasses),_value,true)]);
            };
            class GVAR(exclusionMarkers) {
                property = QGVAR(exclusionMarkers);
                displayName = "Exclusion Markers";
                tooltip = "Array of marker names. Players inside these markers won't be selected as mission targets. Format: ['marker1','marker2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(exclusionMarkers),_value,true)]);
            };
        };
    };
};
