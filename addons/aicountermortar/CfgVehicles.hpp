class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(counterBatteryModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Counter Battery Units";
        icon = "A3\ui_f\data\map\markers\nato\o_mortar.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_mortar.paa";
        function = QFUNC(moduleAddCounterBatteryUnits);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = EGVAR(common,eden);
    };
    class GVAR(airSpawnModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Counter Mortar Heli Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_air.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_air.paa";
        function = QFUNC(moduleHeliSpawn);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = EGVAR(common,eden);
    };
    class GVAR(groundSpawnModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Counter Mortar Ground Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        function = QFUNC(moduleGroundSpawn);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = EGVAR(common,eden);
    };
    class GVAR(unitPoolsModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Counter Mortar Unit Pools";
        icon = "\a3\modules_f_bootcamp\data\portraitpunishment.paa";
        portrait = "\a3\modules_f_bootcamp\data\portraitpunishment.paa";
        function = QFUNC(moduleUnitPools);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = EGVAR(common,eden);

        class Attributes : AttributesBase {
            class GVAR(unitPoolString) {
                property = QGVAR(unitPoolString);
                displayName = "Unit Pool";
                tooltip = "Class names of units that can spawn in dynamic patrol groups. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1; // This is a custom value used specifically in the dynamic area module function
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(unitPoolString),_value,true)]);
            };
        class GVAR(groundVehiclePoolString) {
                property = QGVAR(groundVehiclePoolString);
                displayName = "Ground Vehicle Pool";
                tooltip = "Class names of ground vehicles that will be created to counter mortars. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(groundVehiclePoolString),_value,true)]);
            };
        class GVAR(airVehiclePoolString) {
                property = QGVAR(airVehiclePoolString);
                displayName = "Air Vehicle Pool";
                tooltip = "Class names of air vehicles that will be created to counter mortars. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                compileString = 1;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(airVehiclePoolString),_value,true)]);
            };
        };
    };
};
