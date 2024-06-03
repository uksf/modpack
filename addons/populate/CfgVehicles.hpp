class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = ADDON;
        class AttributesBase;
    };
    class GVAR(populateAreaModule) : GVAR(module) {
        scope = 2;
        displayName = "(AP) Auto Populate)";
        icon = "A3\ui_f\data\map\markers\nato\o_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_inf.paa";
        function = QFUNC(modulePopulateArea);
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        class AttributeValues {
            size3[] = { 200, 200, -1 };
            isRectangle = 1;
        };
        class Attributes : AttributesBase {
            class GVAR(numberOfUnits) {
                property = QGVAR(numberOfUnits);
                displayName = "Number of Units";
                tooltip = "The number of units to spawn";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = 30;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(numberOfUnits),_value,true)]);
            };
            class GVAR(patrolRadius) {
                property = QGVAR(patrolRadius);
                displayName = "Patrol Radius";
                tooltip = "The radius any left over units will patrol around the module location. Used for when positions to occupy isn't 100%";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = 50;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(patrolRadius),_value,true)]);
            };
             class GVAR(patrolSize) {
                property = QGVAR(patrolSize);
                displayName = "Patrol Size";
                tooltip = "The number of units in each patrol. Patrols occur once all building positions are filled.";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = 6;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(patrolSize),_value,true)]);
            };
            class GVAR(unitPoolString) {
                property = QGVAR(unitPoolString);
                displayName = "Unit Pool";
                tooltip = "Class names of units to spawn for counter-mortar groups. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(unitPoolString),_value,true)]);
            };
            class GVAR(occupyStaticGunsBool) {
                property = QGVAR(occupyStaticGunsBool);
                displayName = "Occupy Static Weapons";
                tooltip = "Should units man placed static weapons";
                control = "CheckBox";
                typeName = "BOOL";
                defaultValue = "(false)";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(occupyStaticGunsBool),_value,true)]);
            };
            class GVAR(percentageOfPositionsToOccupy) {
                property = QGVAR(percentageOfPositionsToOccupy);
                displayName = "Percentage of Positions to Occupy";
                tooltip = "What percentage of the total positions will be occupied - low % may result in units being spread out";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = 30;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(percentageOfPositionsToOccupy),_value,true)]);
            };
            class GVAR(side) {
                property = QGVAR(side);
                displayName = "Side";
                tooltip = "Side of spawned units";
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
                        name = "INDEPENDENT";
                        value = 1;
                    };
                    class West {
                        name = "BLUFOR";
                        value = 2;
                    };
                };
            };
        };
    };
};
