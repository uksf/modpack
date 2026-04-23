class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };

    class GVAR(modulePatrolSpawn) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Vehicle Patrol Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        function = QFUNC(modulePatrolSpawn);
        functionPriority = 25;
        canSetArea = 0;
        category = QEGVAR(common,eden);

        class Attributes : AttributesBase {
            class GVAR(patrolUnitClasses) {
                property = QGVAR(patrolUnitClasses);
                displayName = "Patrol Unit Classes";
                tooltip = "Array of unit class names for passengers. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(patrolUnitClasses),_value,true)]);
            };
            class GVAR(patrolVehicleClasses) {
                property = QGVAR(patrolVehicleClasses);
                displayName = "Patrol Vehicle Classes";
                tooltip = "Array of vehicle class names. Format: ['Class1','Class2']";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(patrolVehicleClasses),_value,true)]);
            };
            class GVAR(spawnRate) {
                property = QGVAR(spawnRate);
                displayName = "Spawn Rate";
                tooltip = "Base spawn interval in seconds";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                defaultValue = "120";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(spawnRate),_value,true)]);
            };
            class GVAR(spawnOffset) {
                property = QGVAR(spawnOffset);
                displayName = "Spawn Offset";
                tooltip = "Random extra delay in seconds added to spawn rate";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                defaultValue = "30";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(spawnOffset),_value,true)]);
            };
            class GVAR(condition) {
                property = QGVAR(condition);
                displayName = "Condition";
                tooltip = "Code that must return true to allow spawning. Arguments: [_logic].";
                defaultValue = "'true'";
                value = "'true'";
                control = "EditCodeMulti3";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(condition),_value,true)]);
            };
            class GVAR(turnAround) {
                property = QGVAR(turnAround);
                displayName = "Turn Around";
                tooltip = "If true, patrol returns to spawn after destination before deletion";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(turnAround),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class false {
                        name = "FALSE";
                        value = 0;
                    };
                    class true {
                        name = "TRUE";
                        value = 1;
                    };
                };
            };
            class GVAR(fillPercentage) {
                property = QGVAR(fillPercentage);
                displayName = "Fill Percentage";
                tooltip = "Percentage of cargo seats to fill with passengers (0 - 100)";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 100;
                defaultValue = "100";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(fillPercentage),_value,true)]);
            };
            class GVAR(waypointBehaviour) {
                property = QGVAR(waypointBehaviour);
                displayName = "Waypoint Behaviour";
                tooltip = "Behaviour for vehicle waypoint movement";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(waypointBehaviour),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class safe {
                        name = "SAFE";
                        value = 0;
                    };
                    class aware {
                        name = "AWARE";
                        value = 1;
                    };
                    class combat {
                        name = "COMBAT";
                        value = 2;
                    };
                };
            };
            class GVAR(waypointSpeed) {
                property = QGVAR(waypointSpeed);
                displayName = "Waypoint Speed";
                tooltip = "Speed mode for vehicle waypoint movement";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(waypointSpeed),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 1;
                class values {
                    class limited {
                        name = "LIMITED";
                        value = 0;
                    };
                    class normal {
                        name = "NORMAL";
                        value = 1;
                    };
                    class full {
                        name = "FULL";
                        value = 2;
                    };
                };
            };
            class GVAR(startDelay) {
                property = QGVAR(startDelay);
                displayName = "Start Delay";
                tooltip = "Delay in seconds before this module starts spawning";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                defaultValue = "0";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(startDelay),_value,true)]);
            };
            class GVAR(vehiclesPerWave) {
                property = QGVAR(vehiclesPerWave);
                displayName = "Vehicles Per Wave";
                tooltip = "How many vehicles spawn in each wave.";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                defaultValue = "1";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(vehiclesPerWave),_value,true)]);
            };
            class GVAR(waveSpawnDelay) {
                property = QGVAR(waveSpawnDelay);
                displayName = "Wave Spawn Delay";
                tooltip = "Delay in seconds between each vehicle in a wave.";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                defaultValue = "7";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(waveSpawnDelay),_value,true)]);
            };
            class GVAR(side) {
                property = QGVAR(side);
                displayName = "Side";
                tooltip = "Side for spawned patrol groups";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(side),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class opfor {
                        name = "OPFOR";
                        value = 0;
                    };
                    class independent {
                        name = "Independent";
                        value = 1;
                    };
                    class blufor {
                        name = "BLUFOR";
                        value = 2;
                    };
                };
            };
        };
    };

    class GVAR(modulePatrolDestination) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Vehicle Patrol Destination";
        icon = "A3\ui_f\data\map\markers\military\join_ca.paa";
        portrait = "A3\ui_f\data\map\markers\military\join_ca.paa";
        functionPriority = 25;
        canSetArea = 0;
        category = QEGVAR(common,eden);
    };
};
