class CUP_BAF_Jackal2_BASE_D: Car_F {
    class Turrets: Turrets {
        class MainTurret;
        class M240_Turret: MainTurret {
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    maximumLoad = 4000;
    crewCrashProtection = 0.1;
    armor = 100;
    armorStructural = 3;
    armorWheels = 0.5;
    class HitPoints: HitPoints {
        class HitBody {
            armor = 1.5;
        };
        class HitEngine {
            armor = 4;
        };
        class HitFuel {
            armor = 2;
        };
    };
};
class CUP_BAF_Jackal2_GMG_D: CUP_BAF_Jackal2_BASE_D {
    class Turrets: Turrets {
        class GMG_Turret: MainTurret {
            magazines[] = { "UK3CB_BAF_32Rnd_40mm_G_Box" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
        class M240_Turret: M240_Turret {
            magazines[] = { "UK3CB_BAF_762_200Rnd_T", "SmokeLauncherMag", "SmokeLauncherMag" };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_32Rnd_40mm_G_Box {
            magazine = "UK3CB_BAF_32Rnd_40mm_G_Box";
            count = 5;
        };
        class _xx_UK3CB_BAF_762_200Rnd_T {
            magazine = "UK3CB_BAF_762_200Rnd_T";
            count = 5;
        };
    };
    REARM_ACTIONS
    FUEL_CAPACITY
};
class CUP_BAF_Jackal2_L2A1_D: CUP_BAF_Jackal2_BASE_D {
    class Turrets: Turrets {
        class M2_Turret: MainTurret {
            magazines[] = { "UK3CB_BAF_127_100Rnd" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
        class M240_Turret: M240_Turret {
            magazines[] = { "UK3CB_BAF_762_200Rnd_T", "SmokeLauncherMag", "SmokeLauncherMag" };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
        class _xx_UK3CB_BAF_762_200Rnd_T {
            magazine = "UK3CB_BAF_762_200Rnd_T";
            count = 5;
        };
    };
    REARM_ACTIONS
    FUEL_CAPACITY
};
