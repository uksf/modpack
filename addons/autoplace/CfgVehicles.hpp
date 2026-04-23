class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase {
            class ModuleDescription;
        };
        class ModuleDescription;
    };

    class GVAR(moduleAutoplace) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Autoplace";
        icon = "A3\Modules_F\Data\portraitsector_ca.paa";
        portrait = "A3\Modules_F\Data\portraitsector_ca.paa";
        function = QFUNC(moduleAutoplace);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = QEGVAR(common,eden);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
        class ModuleDescription : ModuleDescription {
            description = "Populates the module area with AI using CBA_BuildingPos helpers, optional static gunners and optional patrols. Requires virtualisation to be enabled; will not run under caching-only missions.";
        };
        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
            class GVAR(unitListString) {
                property = QGVAR(unitListString);
                displayName = "Unit List";
                tooltip = "Class names of units that can spawn. Comma-separated list of class names in single quotes, no spaces.";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(unitListString),_value,true)]);
            };
            class GVAR(side) {
                property = QGVAR(side);
                displayName = "Side";
                tooltip = "Side of spawned groups";
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
            class GVAR(coveragePercent) {
                property = QGVAR(coveragePercent);
                displayName = "% of Coverage";
                tooltip = "Percentage of found CBA_BuildingPos positions to populate (0-100). Very sparse layouts can briefly create many small groups until virtualisation sweeps.";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 100;
                defaultValue = "100";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(coveragePercent),_value,true)]);
            };
            class GVAR(enablePatrols) {
                property = QGVAR(enablePatrols);
                control = "Checkbox";
                displayName = "Patrols";
                tooltip = "Enable patrol group spawning.";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(enablePatrols),_value,true)]);
                typeName = "BOOL";
                defaultValue = "(false)";
            };
            class GVAR(numberOfPatrols) {
                property = QGVAR(numberOfPatrols);
                displayName = "Number of Patrols";
                tooltip = "Number of patrol groups to spawn.";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                defaultValue = "0";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(numberOfPatrols),_value,true)]);
            };
            class GVAR(patrolRadius) {
                property = QGVAR(patrolRadius);
                displayName = "Patrol Radius Around Spawn Point";
                tooltip = "Radius for patrol waypoints around patrol spawn positions.";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                defaultValue = "150";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(patrolRadius),_value,true)]);
            };
            class GVAR(patrolSoldierCount) {
                property = QGVAR(patrolSoldierCount);
                displayName = "Number of Soldiers in a Patrol";
                tooltip = "Number of soldiers in each patrol group. Capped at 10.";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 10;
                defaultValue = "4";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(patrolSoldierCount),_value,true)]);
            };
            class GVAR(occupyEmptyStatics) {
                property = QGVAR(occupyEmptyStatics);
                control = "Checkbox";
                displayName = "Occupy Empty Statics";
                tooltip = "Occupy empty static weapons in the module area.";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(occupyEmptyStatics),_value,true)]);
                typeName = "BOOL";
                defaultValue = "(false)";
            };
        };
    };
};
