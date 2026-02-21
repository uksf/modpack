class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(moduleSpawnArea) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Spawn Area";
        icon = "A3\Modules_F\Data\portraitsector_ca.paa";
        portrait = "A3\Modules_F\Data\portraitsector_ca.paa";
        function = QFUNC(moduleSpawn);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = QEGVAR(common,eden);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class GVAR(maxGroups) {
                property = QGVAR(maxGroups);
                displayName = "Max Spawned Groups";
                tooltip = "Defines the maximum number of groups that will be spawned in the area at one time.";
                control = "Edit";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(maxGroups),_value,true)]);
                defaultValue = "4";
            };
            class GVAR(groupPool) {
                property = QGVAR(groupPool);
                displayName = "Group Pool Size";
                tooltip = "Defines the total number of groups that will spawn in this area.";
                control = "Edit";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(groupPool),_value,true)]);
                defaultValue = "8";
            };
            class GVAR(faction) {
                property = QGVAR(faction);
                displayName = "Faction Class Name";
                tooltip = "Determines the faction of the groups which spawn. Must be the class name.";
                control = "Edit";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(faction),_value,true)]);
                defaultValue = "OPF_F";
            };
        };
    };
    class GVAR(moduleDynamicPatrolExcludeArea) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Patrol Exclude Area";
        icon = QPATHTOF(data\ui\Icon_Module_PatrolArea_Exclude_ca.paa);
        portrait = QPATHTOF(data\ui\Icon_Module_PatrolArea_Exclude_ca.paa);
        function = QFUNC(moduleDynamicPatrolExcludeArea);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = QEGVAR(common,eden);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
    };
    class GVAR(moduleDynamicPatrolIncludeArea) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Patrol Include Area";
        icon = QPATHTOF(data\ui\Icon_Module_PatrolArea_Include_ca.paa);
        portrait = QPATHTOF(data\ui\Icon_Module_PatrolArea_Include_ca.paa);
        function = QFUNC(moduleDynamicPatrolIncludeArea);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = QEGVAR(common,eden);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class GVAR(spawnChance) {
                property = QGVAR(spawnChance);
                displayName = "Spawn Chance";
                tooltip = "Defines the percentage chance for a patrol spawn when players are in this area.";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "100";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(spawnChance),_value,true)]);
            };
        };
    };
    class GVAR(moduleDynamicPatrolArea) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Dynamic Patrol Area";
        icon = QPATHTOF(data\ui\Icon_Module_PatrolArea_ca.paa);
        portrait = QPATHTOF(data\ui\Icon_Module_PatrolArea_ca.paa);
        function = QFUNC(moduleDynamicPatrolArea);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = QEGVAR(common,eden);
        class AttributeValues {
            size3[] = { 2000, 2000, -1 };
            isRectangle = 1;
        };
        class Attributes : AttributesBase {
            // TODO: Add active validation for min and max values
            class GVAR(cooldown) {
                property = QGVAR(cooldown);
                displayName = "Spawn Cooldown";
                tooltip = "Time in seconds between dynamic patrol group spawns (60 - 3600, default: 600)";
                control = "EditShort";
                validate = "NUMBER";
#ifdef DEBUG_MODE_ANALYSIS
                min = 10;
#else
                min = 60;
#endif
                max = 3600;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(cooldown),_value,true)]);
            };
            class GVAR(distance) {
                property = QGVAR(distance);
                displayName = "Spawn Distance";
                tooltip = "Dynamic patrols will spawn beyond this distance from the player (100 - 1500, default: 750)";
                control = "EditShort";
                validate = "NUMBER";
                min = 100;
                max = 1500;
                defaultValue = "750";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(distance),_value,true)]);
            };
            class GVAR(groupLimit) {
                property = QGVAR(groupLimit);
                displayName = "Group Limit";
                tooltip = "Maximum number of active dynamic patrol groups allowed in this zone (1 - 10, default: 5)";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 10;
                defaultValue = "5";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(groupLimit),_value,true)]);
            };
            class GVAR(minUnits) {
                property = QGVAR(minUnits);
                displayName = "Minimum Patrol Units";
                tooltip = "Minimum number of units per dynamic patrol group. There will be random deviations above this number (2 - 11, default: 3)";
                control = "EditShort";
                validate = "NUMBER";
                min = 2;
                max = 11;
                defaultValue = "3";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(minUnits),_value,true)]);
            };
            class GVAR(maxUnits) {
                property = QGVAR(maxUnits);
                displayName = "Maximum Patrol Units";
                tooltip = "Maximum number of units per dynamic patrol group. There will be random deviations below this number (4 - 12, default: 6)";
                control = "EditShort";
                validate = "NUMBER";
                min = 4;
                max = 12;
                defaultValue = "6";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(maxUnits),_value,true)]);
            };
            class GVAR(minGroups) {
                property = QGVAR(minGroups);
                displayName = "Minimum Groups Per patrol";
                tooltip = "Minimum number of groups per dynamic patrol. There will be random deviations above this number (1 - 3, default: 1)";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 3;
                defaultValue = "1";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(minGroups),_value,true)]);
            };
            class GVAR(maxGroups) {
                property = QGVAR(maxGroups);
                displayName = "Maximum Groups Per patrol";
                tooltip = "Maximum number of units per dynamic patrol. There will be random deviations below this number (1 - 4, default: 2)";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 4;
                defaultValue = "2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(maxGroups),_value,true)]);
            };
            class GVAR(vehicleProbability) {
                property = QGVAR(vehicleProbability);
                displayName = "Vehicle Spawn Probability";
                tooltip = "Probability of spawning a vehicle in place of a group (0 - 1, default: 0.2)";
                control = "Slider";
                defaultValue = "0.2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(vehicleProbability),_value,true)]);
            };
            class GVAR(vehicleDistanceCoef) {
                property = QGVAR(vehicleDistanceCoef);
                displayName = "Vehicle Spawn Distance Coef";
                tooltip = "Dynamic patrol vehicles will spawn beyond the base spawn distance multiplied by this coefficient from the player (0.1 - 5, default: 2)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0.1;
                max = 5;
                defaultValue = "2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(vehicleDistanceCoef),_value,true)]);
            };
            class GVAR(waypointDistance) {
                property = QGVAR(waypointDistance);
                displayName = "Waypoint Distance";
                tooltip = "Distance away from a player for the waypoint of a dynamic patrol (10 - 500, default: 100)";
                control = "EditShort";
                validate = "NUMBER";
                min = 10;
                max = 500;
                defaultValue = "100";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(waypointDistance),_value,true)]);
            };
            class GVAR(vehicleWaypointDistance) {
                property = QGVAR(vehicleWaypointDistance);
                displayName = "Vehicle Waypoint Distance";
                tooltip = "Distance away from a player for the waypoint of a dynamic vehicle patrol (50 - 750, default: 200)";
                control = "EditShort";
                validate = "NUMBER";
                min = 50;
                max = 750;
                defaultValue = "200";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(vehicleWaypointDistance),_value,true)]);
            };
            class GVAR(unitPoolString) {
                property = QGVAR(unitPoolString);
                displayName = "Units Pool";
                tooltip = "Class names of units that can spawn in dynamic patrol groups. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(unitPoolString),_value,true)]);
            };
            class GVAR(vehiclePoolString) {
                property = QGVAR(vehiclePoolString);
                displayName = "Vehicles Pool";
                tooltip = "Class names of vehicles that can spawn in dynamic patrol groups. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(vehiclePoolString),_value,true)]);
            };
            class GVAR(combatMode) {
                property = QGVAR(combatMode);
                displayName = "Group Combat Mode";
                tooltip = "Combat mode of spawned dynamic patrol groups";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(combatMode),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class East {
                        name = "SAFE";
                        value = 0;
                    };
                    class Guer {
                        name = "AWARE";
                        value = 1;
                    };
                    class West {
                        name = "COMBAT";
                        value = 2;
                    };
                };
            };
            class GVAR(patrolSpeed) {
                property = QGVAR(patrolSpeed);
                displayName = "Group Speed";
                tooltip = "Speed of spawned dynamic patrol groups";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(patrolSpeed),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class East {
                        name = "LIMITED";
                        value = 0;
                    };
                    class Guer {
                        name = "NORMAL";
                        value = 1;
                    };
                    class West {
                        name = "FULL";
                        value = 2;
                    };
                };
            };
            class GVAR(side) {
                property = QGVAR(side);
                displayName = "Side";
                tooltip = "Side of spawned dynamic patrol groups";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(side),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class East {
                        name = "OPFOR";
                        value = 0;
                    };
                    class Guer {
                        name = "Independent";
                        value = 1;
                    };
                    class West {
                        name = "BLUFOR";
                        value = 2;
                    };
                };
            };
            class GVAR(startDelay) {
                property = QGVAR(startDelay);
                displayName = "Start Delay";
                tooltip = "Time in minutes to delay running the dynamic patrol system from the start of the mission (0 - 120, default: 0)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 120;
                defaultValue = "0";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(startDelay),_value,true)]);
            };
            class GVAR(condition) {
                property = QGVAR(condition);
                defaultValue = "'true'";
                value = "'true'";
                control = "EditCodeMulti3";
                displayName = "Spawn condition";
                tooltip = "Code required to evaluate to true for spawning to run. Must return a boolean. Condition is evaluate every iteration. This is optional, leave as 'true' if not needed. Make the code as short as possible or call a function if more than 1 line.\n\nThe following arguments are passed to the condition: ['_values', '_logic', '_area', '_players'].\n'_players' is an array of players that meet the spawning requirements for this area.";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(condition),_value,true)]);
            };
        };
    };
    class GVAR(moduleAmbientArtillery) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Ambient Artillery";
        // icon = QPATHTOF(data\ui\Icon_Module_PatrolArea_Include_ca.paa);
        // portrait = QPATHTOF(data\ui\Icon_Module_PatrolArea_Include_ca.paa);
        function = QFUNC(moduleAmbientArtillery);
        functionPriority = 25;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = EGVAR(common,eden);
        class Attributes : AttributesBase {
            class GVAR(ambientArtilleryInterval) {
                property = QGVAR(ambientArtilleryInterval);
                displayName = "Interval";
                tooltip = "Defines the time between fire missions in seconds";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientArtilleryInterval),_value,true)]);
            };
            class GVAR(ambientArtilleryMinimumNumberOfRounds) {
                property = QGVAR(ambientArtilleryMinimumNumberOfRounds);
                displayName = "Minimum Number of Rounds";
                tooltip = "Defines the minimum number of rounds to fire";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "4";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientArtilleryMinimumNumberOfRounds),_value,true)]);
            };
            class GVAR(ambientArtilleryRandomNumberOfRounds) {
                property = QGVAR(ambientArtilleryRandomNumberOfRounds);
                displayName = "Random Number of Rounds";
                tooltip = "Defines a random number of rounds to fire on top of the minimum rounds. E.g. if set at 2, artillery will fire from 4 - 6 rounds";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientArtilleryRandomNumberOfRounds),_value,true)]);
            };
            class GVAR(ambientArtilleryDeleteShell) {
                property = QGVAR(ambientArtilleryDeleteShell);
                displayName = "Delete Shell";
                tooltip = "Deletes the shell on firing so theres no splash";
                control = "Checkbox";
                defaultValue = false;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientArtilleryDeleteShell),_value,true)]);
            };
        };
    };
    class GVAR(moduleAmbientArtilleryTargetArea) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Ambient Artillery Target Area";
        // icon = QPATHTOF(data\ui\Icon_Module_PatrolArea_Exclude_ca.paa);
        // portrait = QPATHTOF(data\ui\Icon_Module_PatrolArea_Exclude_ca.paa);
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 1;
        };
    };
    class GVAR(moduleAmbientLogisticsSpawn) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Ambient Logistics (Spawn Location)";
        // icon = QPATHTOF(data\ui\Icon_Module_PatrolArea_Include_ca.paa);
        // portrait = QPATHTOF(data\ui\Icon_Module_PatrolArea_Include_ca.paa);
        function = QFUNC(moduleAmbientLogistics);
        functionPriority = 25;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = EGVAR(common,eden);
        class Attributes : AttributesBase {
            class GVAR(ambientLogisticsInterval) {
                property = QGVAR(ambientLogisticsInterval);
                displayName = "Interval";
                tooltip = "Defines the time between logistic runs";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientLogisticsInterval),_value,true)]);
            };
            class GVAR(ambientLogisticsUnitPoolString) {
                property = QGVAR(ambientLogisticsUnitPoolString);
                displayName = "Units Pool";
                tooltip = "Class names of units that can spawn as crew for logistic vehicles. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientLogisticsUnitPoolString),_value,true)]);
            };
            class GVAR(ambientLogisticsVehiclePoolString) {
                property = QGVAR(ambientLogisticsVehiclePoolString);
                displayName = "Vehicles Pool";
                tooltip = "Class names of vehicles to use. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientLogisticsVehiclePoolString),_value,true)]);
            };
            class GVAR(ambientLogisticsSide) {
                property = QGVAR(ambientLogisticsSide);
                displayName = "Side";
                tooltip = "Side of logistic units, must match the side of the unit pool";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientLogisticsSide),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class East {
                        name = "OPFOR";
                        value = 0;
                    };
                    class Guer {
                        name = "Independent";
                        value = 1;
                    };
                    class West {
                        name = "BLUFOR";
                        value = 2;
                    };
                };
            };
            class GVAR(ambientLogisticsNumberOfRuns) {
                property = QGVAR(ambientLogisticsNumberOfRuns);
                displayName = "Number of Runs";
                tooltip = "Max number of runs this module will spawn";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "10";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ambientLogisticsNumberOfRuns),_value,true)]);
            };
        };
    };

    class GVAR(moduleAmbientLogisticsDestination) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Ambient Logistics (Destination)";
        // icon = QPATHTOF(data\ui\Icon_Module_PatrolArea_Exclude_ca.paa);
        // portrait = QPATHTOF(data\ui\Icon_Module_PatrolArea_Exclude_ca.paa);
        // function = QFUNC(moduleDynamicPatrolExcludeArea);
        functionPriority = 25;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = EGVAR(common,eden);
    };
};
