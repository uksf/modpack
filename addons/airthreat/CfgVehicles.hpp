class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = QUOTE(ADDON);
        class AttributesBase : AttributesBase {
            class ModuleDescription;
        };
        class ModuleDescription;
    };
    class GVAR(controllerModule) : GVAR(module) {
        scope = 2;
        displayName = "(AT) Controller";
        icon = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        function = QFUNC(moduleController);
        class ModuleDescription : ModuleDescription {
            description = "Central controller for the air threat system. Place exactly one per mission. Configures mission timing, aircraft classnames, target exclusions, and concurrency limits. All other AT modules require this to function.";
        };
        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
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
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(fighterClassnames),_value,true)]);
            };
            class GVAR(helicopterClassnames) {
                property = QGVAR(helicopterClassnames);
                displayName = "Helicopter Classnames (CAS)";
                tooltip = "Array of helicopter classnames for CAS missions. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(helicopterClassnames),_value,true)]);
            };
            class GVAR(jetClassnames) {
                property = QGVAR(jetClassnames);
                displayName = "Jet Classnames (Strike)";
                tooltip = "Array of jet classnames for strike/bombing missions. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(jetClassnames),_value,true)]);
            };
            class GVAR(reconClassnames) {
                property = QGVAR(reconClassnames);
                displayName = "Recon Classnames";
                tooltip = "Array of drone/aircraft classnames for recon missions. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(reconClassnames),_value,true)]);
            };
            class GVAR(excludedClasses) {
                property = QGVAR(excludedClasses);
                displayName = "Excluded Player Classes";
                tooltip = "Array of unit classnames excluded from targeting. Players with these classes won't be selected as mission targets. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(excludedClasses),_value,true)]);
            };
            class GVAR(capTimeout) {
                property = QGVAR(capTimeout);
                displayName = "CAP Timeout";
                tooltip = "Time in seconds before a CAP mission RTBs (60 - 3600, default: 900)";
                control = "EditShort";
                validate = "NUMBER";
                min = 60;
                max = 3600;
                defaultValue = "900";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(capTimeout),_value,true)]);
            };
            class GVAR(reconTimeout) {
                property = QGVAR(reconTimeout);
                displayName = "Recon Timeout";
                tooltip = "Time in seconds before a recon mission RTBs (60 - 3600, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
                min = 60;
                max = 3600;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(reconTimeout),_value,true)]);
            };
            class GVAR(casTimeout) {
                property = QGVAR(casTimeout);
                displayName = "CAS Timeout";
                tooltip = "Time in seconds before a CAS mission RTBs (60 - 3600, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
                min = 60;
                max = 3600;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(casTimeout),_value,true)]);
            };
            class GVAR(strikeTimeout) {
                property = QGVAR(strikeTimeout);
                displayName = "Strike Timeout";
                tooltip = "Time in seconds before a strike mission cleans up (60 - 3600, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
                min = 60;
                max = 3600;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(strikeTimeout),_value,true)]);
            };
            class GVAR(interceptTimeout) {
                property = QGVAR(interceptTimeout);
                displayName = "Intercept Timeout";
                tooltip = "Time in seconds before an intercept mission RTBs (60 - 3600, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
                min = 60;
                max = 3600;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(interceptTimeout),_value,true)]);
            };
        };
    };
    class GVAR(spawnPointModule) : GVAR(module) {
        scope = 2;
        displayName = "(AT) Spawn Point";
        icon = "A3\ui_f\data\map\markers\nato\o_plane.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_plane.paa";
        function = QFUNC(moduleSpawnPoint);
        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
        };
        class ModuleDescription : ModuleDescription {
            description = "Spawn/despawn point for enemy aircraft. Place at the edge of the map where aircraft should appear from and return to. Multiple spawn points can be placed — missions will use the nearest one to their target.";
            position = 1;
            duplicate = 1;
        };
    };
    class GVAR(airspaceModule) : GVAR(module) {
        scope = 2;
        displayName = "(AT) Airspace";
        icon = "A3\modules_f\data\iconmodule_ca.paa";
        portrait = "A3\modules_f\data\iconmodule_ca.paa";
        function = QFUNC(moduleAirspace);
        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
        };
        class ModuleDescription : ModuleDescription {
            description = "Defines an airspace zone where CAP and recon missions patrol. Enemy aircraft will fly waypoints within this area. Resize the area to cover the region you want patrolled.";
            position = 1;
            duplicate = 1;
        };
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        class AttributeValues {
            size3[] = { 2000, 2000, -1 };
            isRectangle = 0;
        };
    };
    class GVAR(casStrikeZoneModule) : GVAR(module) {
        scope = 2;
        displayName = "(AT) CAS/Strike Zone";
        icon = "A3\ui_f\data\map\markers\nato\o_support.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_support.paa";
        function = QFUNC(moduleCasStrikeZone);
        class ModuleDescription : ModuleDescription {
            description = "Defines an area where CAS helicopters or strike jets can be called against players. When a player is inside this zone, the system may spawn a CAS or strike mission targeting them. The CAS Probability attribute controls the chance of a helicopter vs a jet.";
            position = 1;
            duplicate = 1;
        };
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
            class GVAR(casProbability) {
                property = QGVAR(casProbability);
                displayName = "CAS Probability";
                tooltip = "Percentage chance that a CAS helicopter spawns instead of a strike jet (0 - 100, default: 50)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 100;
                defaultValue = "50";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(casProbability),_value,true)]);
            };
        };
    };
    class GVAR(interceptZoneModule) : GVAR(module) {
        scope = 2;
        displayName = "(AT) Intercept Zone";
        icon = "A3\ui_f\data\map\markers\nato\o_air.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_air.paa";
        function = QFUNC(moduleInterceptZone);
        class ModuleDescription : ModuleDescription {
            description = "Defines an area where player aircraft will be intercepted by enemy fighters. When a player flies within this zone, interceptors scramble from the nearest spawn point to engage. Max Concurrent Intercepts limits how many intercept groups can be active from this zone at once.";
            position = 1;
            duplicate = 1;
        };
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        class AttributeValues {
            size3[] = { 10000, 10000, -1 };
            isRectangle = 1;
        };
        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
            class GVAR(maxConcurrentIntercepts) {
                property = QGVAR(maxConcurrentIntercepts);
                displayName = "Max Concurrent Intercepts";
                tooltip = "Maximum intercept groups active from this zone at once (1 - 4, default: 2)";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 4;
                defaultValue = "2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(maxConcurrentIntercepts),_value,true)]);
            };
        };
    };
    class GVAR(exclusionZoneModule) : GVAR(module) {
        scope = 2;
        displayName = "(AT) Exclusion Zone";
        icon = "A3\modules_f\data\iconmodule_ca.paa";
        portrait = "A3\modules_f\data\iconmodule_ca.paa";
        function = QFUNC(moduleExclusionZone);
        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
        };
        class ModuleDescription : ModuleDescription {
            description = "Defines a safe area where players will not be targeted by air threat missions. Place over bases, staging areas, or any location where air attacks should not occur.";
            position = 1;
            duplicate = 1;
        };
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
    };
};
