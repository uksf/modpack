class CUP_Mastiff_Base: Wheeled_APC_F {
    class Turrets {
        class MainTurret: NewTurret {
            magazines[] = { "UK3CB_BAF_127_100Rnd" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    fuelCapacity = 25; // 45
    ace_cargo_space = 8; // 4
    maxSpeed = 90; // 80
    class complexGearbox {
        GearboxRatios[] = { "R1",-10.094, "N",0, "D1",5.562, "D2",3.456, "D3",2.623, "D4",1.678, "D5",1.078, "D6",1 };
        TransmissionRatios[] = { "High", 5.0 };
        gearBoxMode = "auto";
        moveOffGear = 1;
        driveString = "D";
        neutralString = "N";
        reverseString = "R";
    };
    REARM_ACTIONS
};
class CUP_B_Mastiff_HMG_GB_D: CUP_Mastiff_Base {
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_Mastiff_HMG_GB_W: CUP_Mastiff_Base {
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_Mastiff_GMG_GB_D: CUP_Mastiff_Base {
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_32Rnd_40mm_G_Box" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_32Rnd_40mm_G_Box {
            magazine = "UK3CB_BAF_32Rnd_40mm_G_Box";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_Mastiff_GMG_GB_W: CUP_Mastiff_Base {
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_32Rnd_40mm_G_Box" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_32Rnd_40mm_G_Box {
            magazine = "UK3CB_BAF_32Rnd_40mm_G_Box";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_Mastiff_LMG_GB_D: CUP_Mastiff_Base {
    class Turrets: Turrets {
        class Mainturret: NewTurret {
            magazines[] = { "UK3CB_BAF_762_100Rnd_T" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_762_100Rnd_T {
            magazine = "UK3CB_BAF_762_100Rnd_T";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_Mastiff_LMG_GB_W: CUP_Mastiff_Base {
    class Turrets: Turrets {
        class Mainturret: NewTurret {
            magazines[] = { "UK3CB_BAF_762_100Rnd_T" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_762_100Rnd_T {
            magazine = "UK3CB_BAF_762_100Rnd_T";
            count = 5;
        };
    };
    REARM_ACTIONS
};
