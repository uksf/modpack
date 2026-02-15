class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = QUOTE(ADDON);
        class AttributesBase;
    };
    class GVAR(counterBatteryUnitsModule) : GVAR(module) {
        scope = 2;
        displayName = "(CM) Counter Battery Units";
        icon = "A3\ui_f\data\map\markers\nato\o_mortar.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_mortar.paa";
        function = QFUNC(moduleCounterBatteryUnits);
    };
    class GVAR(airSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(CM) Air Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_air.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_air.paa";
        function = QFUNC(moduleAirSpawn);
    };
    class GVAR(groundSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(CM) Ground Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        function = QFUNC(moduleGroundSpawn);
    };
    class GVAR(unitPoolsModule) : GVAR(module) {
        scope = 2;
        displayName = "(CM) Unit Pools";
        icon = "\a3\modules_f_bootcamp\data\portraitpunishment.paa";
        portrait = "\a3\modules_f_bootcamp\data\portraitpunishment.paa";
        function = QFUNC(moduleUnitPools);
        class Attributes : AttributesBase {
            class GVAR(unitPoolString) {
                property = QGVAR(unitPoolString);
                displayName = "Unit Pool";
                tooltip = "Class names of units to spawn for counter-mortar groups. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(unitPoolString),_value,true)]);
            };
            class GVAR(groundVehiclePoolString) {
                property = QGVAR(groundVehiclePoolString);
                displayName = "Ground Vehicle Pool";
                tooltip = "Class names of ground vehicles used to counter player mortars. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(groundVehiclePoolString),_value,true)]);
            };
            class GVAR(airVehiclePoolString) {
                property = QGVAR(airVehiclePoolString);
                displayName = "Air Vehicle Pool";
                tooltip = "Class names of air vehicles used to counter player mortars. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(airVehiclePoolString),_value,true)]);
            };
        };
    };
};
