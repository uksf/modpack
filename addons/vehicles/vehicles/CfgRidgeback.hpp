class CUP_Ridgback_Base: Wheeled_APC_F {
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
    fuelCapacity = 25; //45
    REARM_ACTIONS
};
class CUP_B_Ridgback_HMG_GB_D: CUP_Ridgback_Base {
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_Ridgback_HMG_GB_W: CUP_Ridgback_Base {
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_Ridgback_GMG_GB_D: CUP_Ridgback_Base {
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
class CUP_B_Ridgback_GMG_GB_W: CUP_Ridgback_Base {
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
class CUP_B_Ridgback_LMG_GB_D: CUP_Ridgback_Base {
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
class CUP_B_Ridgback_LMG_GB_W: CUP_Ridgback_Base {
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
