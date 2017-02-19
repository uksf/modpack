class CUP_LR_Base : Car_F {    
    class Turrets: Turrets {
        class MainTurret;
    };
};
class CUP_LR_MG_Base : CUP_LR_Base {    
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_127_100Rnd" };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_LR_Special_Base : CUP_LR_Base {
    class Turrets: Turrets {
        class PK_Turret;
    };
};
class CUP_LR_Ambulance_Base : CUP_LR_Base {};
class CUP_B_LR_MG_GB_W : CUP_LR_MG_Base {
    NET_ACTIONS
};
class CUP_B_LR_Special_M2_GB_W : CUP_LR_Special_Base {
    NET_ACTIONS
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_127_100Rnd" };
        };
        class PK_Turret: PK_Turret {
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
};
class CUP_B_LR_Special_GMG_GB_W : CUP_LR_Special_Base {
    NET_ACTIONS
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_32Rnd_40mm_G_Box" };
        };
        class PK_Turret: PK_Turret {
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
};
class CUP_B_LR_Ambulance_GB_W : CUP_LR_Ambulance_Base {
    class TransportItems {
        class _xx_ACE_EarPlugs {
            name = "ACE_EarPlugs";
            count = 10;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 50;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 50;
        };
        class _xx_ACE_morphine {
            name = "ACE_morphine";
            count = 30;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 30;
        };
        class _xx_ACE_bloodIVItem {
            name = "ACE_bloodIVItem";
            count = 20;
        };
        class _xx_ACE_personalAidKit {
            name = "ACE_personalAidKit";
            count = 10;
        };
    };
    NET_MEDICAL_ACTIONS
};
class CUP_B_LR_Ambulance_GB_D : CUP_LR_Ambulance_Base {
    class TransportItems {
        class _xx_ACE_EarPlugs {
            name = "ACE_EarPlugs";
            count = 10;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 50;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 50;
        };
        class _xx_ACE_morphine {
            name = "ACE_morphine";
            count = 30;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 30;
        };
        class _xx_ACE_bloodIVItem {
            name = "ACE_bloodIVItem";
            count = 20;
        };
        class _xx_ACE_personalAidKit {
            name = "ACE_personalAidKit";
            count = 10;
        };
    };
    NET_MEDICAL_ACTIONS
};
