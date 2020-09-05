class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = ADDON;
        class AttributesBase;
    };
    class GVAR(commanderModule) : GVAR(module) {
        scope = 2;
        displayName = "(GC) Commander Module";
        icon = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        function = QFUNC(moduleCommander);
        class Attributes : AttributesBase {
            class GVAR(skill) {
                property = QGVAR(skill);
                displayName = "Commander Skill";
                tooltip = "Defines the skill of the AI commander, high skill = more frequent responses. Debug does very fast responses for testing (~3mins)";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(interval),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 1;
                class values {
                    class Low {
                        name = "Low";
                        value = 1200;
                    };
                    class Medium {
                        name = "Medium";
                        value = 900;
                    };
                    class High {
                        name = "High";
                        value = 600;
                    };
                    class Debug {
                        name = "Debug";
                        value = 180;
                    };
                };
            };
        };
    };
    class GVAR(infantrySpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(GC) Infantry Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_inf.paa";
        function = QFUNC(moduleInfantrySpawn);
    };
    class GVAR(carSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(GC) Car Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        function = QFUNC(moduleCarSpawn);
    };
    class GVAR(apcSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(GC) APC Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
        function = QFUNC(moduleAPCSpawn);
    };
    class GVAR(tankSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(GC) Tank Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_armor.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_armor.paa";
        function = QFUNC(moduleTankSpawn);
    };
    class GVAR(stagingAreaModule) : GVAR(module) {
        scope = 2;
        displayName = "(GC) Staging Area";
        icon = "A3\ui_f\data\map\markers\military\join_ca.paa";
        portrait = "A3\ui_f\data\map\markers\military\join_ca.paa";
        function = QFUNC(moduleStagingArea);
    };
};
