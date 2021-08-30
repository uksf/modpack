class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = ADDON;
        class AttributesBase;
    };
    class GVAR(logisticsDestination) : GVAR(module) {
        scope = 2;
        displayName = "(L) Logistics Destination";
        icon = "A3\ui_f\data\map\markers\military\end_ca.paa";
        portrait = "A3\ui_f\data\map\markers\military\end_ca.paa";
    };
    class GVAR(logisticsStart) : GVAR(module) {
        scope = 2;
        displayName = "(L) Logistics Start";
        icon = "A3\ui_f\data\map\markers\military\start_ca.paa";
        portrait = "A3\ui_f\data\map\markers\military\start_ca.paa";
        function = QFUNC(moduleLogisticsStart);
        class Attributes : AttributesBase {
            class GVAR(driverUnitPoolString) {
                property = QGVAR(driverUnitPoolString);
                displayName = "Driver Pool";
                tooltip = "Class names of units to use as drivers. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(driverUnitPoolString),_value,true)]);
            };
            class GVAR(logisticVehiclePoolString) {
                property = QGVAR(logisticVehiclePoolString);
                displayName = "Vehicle Pool";
                tooltip = "Class names of ground vehicles used for logistics. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(logisticVehiclePoolString),_value,true)]);
            };
            class GVAR(routePickets) {
                property = QGVAR(routePickets);
                displayName = "Route Picket";
                tooltip = "Tick if you want stages of the route to be guarded by patrols.";
                control = "Checkbox";
                defaultValue = false;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(routePickets),_value,true)]);
            };
            class GVAR(logisticsTimeout) {
                property = QGVAR(logisticsTimeout);
                displayName = "Logistics Timeout";
                tooltip = "Time between logistic runs. Uses min, mid, max format.";
                control = "Timeout";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(logisticsTimeout),_value,true)]);
            };
            class GVAR(side) {
                property = QGVAR(side);
                displayName = "Side";
                tooltip = "Side of spawned units.";
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
                };
            };
        };
    };
        class GVAR(logisticsPicketGroup) : GVAR(module) {
        scope = 2;
        displayName = "(L) Logistics Picket Group";
        icon = "A3\ui_f\data\map\markers\nato\respawn_inf_ca.paa";
        portrait = "A3\ui_f\data\map\markers\nato\respawn_inf_ca.paa";
        class Attributes : AttributesBase {
            class GVAR(picketUnitPoolString) {
                property = QGVAR(picketUnitPoolString);
                displayName = "Picket Unit Pool";
                tooltip = "Class names of units used to picket route. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(picketUnitPoolString),_value,true)]);
            };
            class GVAR(picketGroupSize) {
                property = QGVAR(picketGroupSize);
                displayName = "Picket Group Size";
                tooltip = "Number of units in picket group. Comma-separated list of class names in single quotes, no spaces";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "4";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(picketGroupSize),_value,true)]);
            };
            class GVAR(side) {
                property = QGVAR(side);
                displayName = "Side";
                tooltip = "Side of spawned units.";
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
                };
            };
            class GVAR(behaviour) {
                property = QGVAR(behaviour);
                displayName = "Behaviour";
                tooltip = "Patrol radius: 200m - Camp radius: 100m - Defend radius: 200m";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(behaviour),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class Patrol {
                        name = "Patrol";
                        value = 0;
                    };
                    class Camp {
                        name = "Camp (requires LAMBs)";
                        value = 1;
                    };
                    class Defend {
                        name = "Defend";
                        value = 2;
                    };
                };
            };
        };
    };
};
