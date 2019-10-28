class CfgVehicles {
    class ModuleRespawnPosition_F;
    class UKSFModuleRespawnPosition_F: ModuleRespawnPosition_F {
        scope = 2;
        displayName = "UKSF Respawn";
        icon = "\a3\ui_f\data\map\markers\flags\UK_ca.paa";
        portrait = "\a3\ui_f\data\map\markers\flags\UK_ca.paa";
        function = QFUNC(moduleRespawnPosition);
        class Arguments {
            class Name {
                displayName = "Name";
                description = "Name shown in the respawn menu and on the map";
                defaultValue = "UKSF";
            };
        };
    };

    class NonStrategic;
    class HouseBase: NonStrategic {
        class DestructionEffects;
    };
    class House: HouseBase {
        class DestructionEffects: DestructionEffects {
            class Smoke1 {
                qualityLevel = 2;
                simulation = "particles";
                type = "HouseDestructionSmoke1";
                position = "destructionEffect1";
                intensity = 0.15;
                interval = 1;
                lifeTime = 0.05;
            };
        };
    };

    class Land_MBG_Killhouse_1;
    class MBG_Killhouse_1_InEditor: Land_MBG_Killhouse_1 {
        scopeCurator = 2;
    };
    class Land_MBG_Killhouse_2;
    class MBG_Killhouse_2_InEditor: Land_MBG_Killhouse_2 {
        scopeCurator = 2;
    };
    class Land_MBG_Killhouse_3;
    class MBG_Killhouse_3_InEditor: Land_MBG_Killhouse_3 {
        scopeCurator = 2;
    };
    class Land_MBG_Killhouse_4;
    class MBG_Killhouse_4_InEditor: Land_MBG_Killhouse_4 {
        scopeCurator = 2;
    };
    class Land_MBG_Killhouse_5;
    class MBG_Killhouse_5_InEditor: Land_MBG_Killhouse_5 {
        scopeCurator = 2;
    };
    class Land_MBG_Warehouse;
    class MBG_Warehouse_InEditor: Land_MBG_Warehouse {
        scopeCurator = 2;
    };
    class Land_MBG_Shoothouse_1: House {
        scopeCurator = 2;
    };
    class Land_MBG_Cinderwall_5;
    class MBG_Cinderwall_5_InEditor: Land_MBG_Cinderwall_5 {
        scopeCurator = 2;
    };
    class Land_MBG_Cinderwall_5_Corner;
    class MBG_Cinderwall_5_Corner_InEditor: Land_MBG_Cinderwall_5_Corner {
        scopeCurator = 2;
    };
    class Land_MBG_Cinderwall_2p5;
    class MBG_Cinderwall_2p5_InEditor: Land_MBG_Cinderwall_2p5 {
        scopeCurator = 2;
    };
    class Land_mbg_cinderwall_5_low;
    class mbg_cinderwall_5_low_InEditor: Land_mbg_cinderwall_5_low {
        scopeCurator = 2;
    };
    class Land_MBG_Cinderwall_5_WoodDoor;
    class MBG_Cinderwall_5_WoodDoor_InEditor: Land_MBG_Cinderwall_5_WoodDoor {
        scopeCurator = 2;
    };
    class Land_MBG_Cinderwall_5_SteelDoor;
    class MBG_Cinderwall_5_SteelDoor_InEditor: Land_MBG_Cinderwall_5_SteelDoor {
        scopeCurator = 2;
    };
    class Land_MBG_Cinderwall_5_Gate;
    class MBG_Cinderwall_5_Gate_InEditor: Land_MBG_Cinderwall_5_Gate {
        scopeCurator = 2;
    };
    class Land_MBG_Woodplanks: House {
        scopeCurator = 2;
    };

    // Acre antenna
    class acre_oe_303: House {
        scopeCurator = 2;
    };

    // Disable lambs fsm temporarily
    class CAManBase;
    class SoldierWB: CAManBase {
        fsmDanger = "-";
    };
    class SoldierEB: CAManBase {
        fsmDanger = "-";
    };
    class SoldierGB: CAManBase {
        fsmDanger = "-";
    };
    class Civilian_F : CAManBase {
        fsmDanger = "A3\characters_f\scripts\formationCDanger.fsm";
    };
};
