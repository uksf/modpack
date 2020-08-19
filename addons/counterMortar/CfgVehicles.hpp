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
};
