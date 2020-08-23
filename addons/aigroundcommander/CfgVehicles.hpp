class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(aiGroundCommanderModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Commander Module";
        icon = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        function = QFUNC(moduleAiGroundCommanderInit);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiGroundCommander);
        class Attributes : AttributesBase {
            class GVAR(aiGroundCommanderSkill) {
                property = QGVAR(aiGroundCommanderSkill);
                displayName = "Commander Skill";
                tooltip = "Defines the skill of the AI commander, high skill = more frequent responses. Debug does very fast responses for testing (~3mins)";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(aiGroundCommanderSkill),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 1;
                class values
                {
                    class Low
                    {
                        name = "Low";
                        value = 1;
                    };
                    class Medium
                    {
                        name = "Medium";
                        value = 2;
                    };
                    class High 
                    {
                        name = "High";
                        value = 3;
                    };
                    class Debug 
                    {
                        name = "Debug";
                        value = 10;
                    };
                };
            };
        };
    };
    class GVAR(infantryLocationsModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Infantry Locations";
        icon = "A3\ui_f\data\map\markers\nato\o_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_inf.paa";
        function = QFUNC(moduleInfantryLocations);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiGroundCommander);
    };
    class GVAR(carLocationsModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Car Locations";
        icon = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
        function = QFUNC(moduleCarLocations);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiGroundCommander);
    };
    class GVAR(apcLocationsModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "APC Locations";
        icon = "A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
        function = QFUNC(moduleAPCLocations);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiGroundCommander);
    };
    class GVAR(tankLocationsModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Tank Locations";
        icon = "A3\ui_f\data\map\markers\nato\o_armor.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_armor.paa";
        function = QFUNC(moduleTankLocations);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiGroundCommander);
    };
    class GVAR(stagingAreaModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Staging Area";
        icon = "A3\ui_f\data\map\markers\military\join_ca.paa";
        portrait = "A3\ui_f\data\map\markers\military\join_ca.paa";
        function = QFUNC(moduleStagingArea);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiGroundCommander);
    };
};
