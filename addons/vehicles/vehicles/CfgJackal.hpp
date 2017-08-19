class CUP_BAF_Jackal2_BASE_D: Car_F {
    class Turrets: Turrets {
        class MainTurret;
        class M240_Turret: MainTurret {
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    maximumLoad = 4000; // Default: 2000
    camouflage = 1.8; // Default: 2
    hullDamageCauseExplosion = 0; // Default: 1
    crewCrashProtection = 0.1; // Default: 0.15
    armor = 100; // Default: 80
    armorStructural = 3; // Default: 2
    armorWheels = 0.5; // Default: 0.1
    class HitPoints: HitPoints {
        class HitBody {
            armor = 1.5; // Default: 0.7
        };
        class HitEngine {
            armor = 4; // Default: 2
        };
        class HitFuel {
            armor = 2; // Default: 1
        };
    };
    class complexGearbox {
        GearboxRatios[] = { "R1",-3.182, "N",0, "D1",4.182, "D2",2.318, "D3",1.85, "D4",1.55, "D5",1.25, "D6",1 };
        TransmissionRatios[] = { "High", 5.539 };
        gearBoxMode = "auto";
        moveOffGear = 1;
        driveString = "D";
        neutralString = "N";
        reverseString = "R";
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
