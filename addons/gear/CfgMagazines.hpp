class CfgMagazines {
    class UK3CB_BAF_762_100Rnd;
    class UK3CB_BAF_762_100Rnd_EL: UK3CB_BAF_762_100Rnd {
        displayname = "7.62mm 100rnd EL Belt";
        displaynameshort = "7.62mm EL";
        ammo = "UK3CB_BAF_762_Ball_EL";
    };
    class UK3CB_BAF_762_100Rnd_T;
    class UK3CB_BAF_762_100Rnd_T_EL: UK3CB_BAF_762_100Rnd_T {
        displayname = "7.62mm 100rnd EL Tracer Belt";
        displaynameshort = "7.62mm EL Tracer";
        ammo = "UK3CB_BAF_762_Ball_Tracer_Red_EL";
    };
    class UK3CB_BAF_762_200Rnd;
    class UK3CB_BAF_762_200Rnd_EL: UK3CB_BAF_762_200Rnd {
        displayname = "7.62mm 200rnd EL Belt";
        displaynameshort = "7.62mm EL";
        ammo = "UK3CB_BAF_762_Ball_EL";
    };
    class UK3CB_BAF_762_200Rnd_T;
    class UK3CB_BAF_762_200Rnd_T_EL: UK3CB_BAF_762_200Rnd_T {
        displayname = "7.62mm 200rnd EL Tracer Belt";
        displaynameshort = "7.62mm EL Tracer";
        ammo = "UK3CB_BAF_762_Ball_Tracer_Red_EL";
    };

    class VehicleMagazine;
    class CUP_8Rnd_AGM114K_Hellfire_II_M: VehicleMagazine {
        displayName = "AGM-114K";
        displayNameShort = "HEAT";
        displayNameMagazine = "HEAT";
        sound[] = {};
        soundFly[] = {};
        lockingTargetSound[] = {};
        lockedTargetSound[] = {};
        reloadSound[] = {};
        nameSound = "missiles";
    };
    class CUP_8Rnd_AGM114N_Hellfire_II_M: CUP_8Rnd_AGM114K_Hellfire_II_M {
        displayName = "AGM-114N";
        displayNameShort = "Thermobaric";
        displayNameMagazine = "Thermobaric";
        ammo = "CUP_M_AGM_114N_Hellfire_II_AT";
    };
    class CUP_4Rnd_AGM114N_Hellfire_II_M: CUP_8Rnd_AGM114N_Hellfire_II_M {
        count = 4;
    };

    class 2Rnd_GBU12_LGB;
    class 1Rnd_GBU12_LGB: 2Rnd_GBU12_LGB {
        count = 1;
    };   

    class CUP_14Rnd_FFAR_M;
    class CUP_12Rnd_CRV7_FAT_M: CUP_14Rnd_FFAR_M {
        initSpeed = 30;
        maxLeadSpeed = 650;
    };
    class CUP_12Rnd_CRV7_HEISAP_M: CUP_12Rnd_CRV7_FAT_M {
        count = 12;
        ammo = "CUP_R_CRV7_HEISAP";
        displayName = "CRV7-HEISAP";
        displayNameShort = "HEISAP";
        descriptionShort = "CRV7 High Explosive Incendiary Semi-Armour Piercing Rocket";
    };
    class CUP_14Rnd_CRV7_FAT_M: CUP_12Rnd_CRV7_HEISAP_M {
        count = 14;
    };
    class CUP_19Rnd_CRV7_FAT_M: CUP_12Rnd_CRV7_HEISAP_M {
        count = 19;
    };
    class CUP_24Rnd_CRV7_FAT_M: CUP_12Rnd_CRV7_HEISAP_M {
        count = 24;
    };
    class CUP_38Rnd_CRV7_FAT_M: CUP_12Rnd_CRV7_HEISAP_M {
        count = 38;
    };
    class CUP_48Rnd_CRV7_FAT_M: CUP_12Rnd_CRV7_HEISAP_M {
        count = 48;
    };
    class CUP_76Rnd_CRV7_FAT_M: CUP_12Rnd_CRV7_HEISAP_M {
        count = 76;
    };
    class CUP_114Rnd_CRV7_FAT_M: CUP_12Rnd_CRV7_HEISAP_M {
        count = 114;
    };

    class CUP_100Rnd_127x99_M: VehicleMagazine {
        picture = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Ammo\data\gear_magazine_belt_tracer_ca.paa";
    };
    class 200Rnd_40mm_G_belt: VehicleMagazine {
        picture = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Ammo\data\gear_magazine_belt_tracer_ca.paa";
    };

    /*class 30Rnd_556x45_Stanag;
    class 30Rnd_556x45_Stanag_Rubber: 30Rnd_556x45_Stanag {
        scopeArsenal = 1;
        displayname = "5.56mm 30Rnd Rubber";
        displaynameshort = "5.56mm Rubber";
        ammo = "B_556x45_Ball_Rubber";
    };
    class CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M;
    class CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M_Rubber: CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M {
        scopeArsenal = 1;
        displayName = "100Rnd. M240 Belt TE4 Rubber (White)";
        ammo = "CUP_B_762x51_Tracer_White_Rubber";
    };
    class CUP_100Rnd_TE4_Red_Tracer_127x99_M;
    class CUP_100Rnd_TE4_White_Tracer_127x99_M_Rubber: CUP_100Rnd_TE4_Red_Tracer_127x99_M {
        displayName = "100Rnd 127x99mm Tracer White Rubber";
        ammo = "B_127x99_Ball_Tracer_White_Rubber";
    };
    class CUP_SMAW_HEDP_M;
    class CUP_SMAW_HEAA_M: CUP_SMAW_HEDP_M {
        displayname = "SMAW-HEAT";
        displaynameshort = "HEAT";
    };
    class CUP_SMAW_HEAT_M_Rubber: CUP_SMAW_HEAA_M {
        scopeArsenal = 1;
        displayname = "SMAW-HEAT Rubber";
        displaynameshort = "HEAT Rubber";
        ammo = "CUP_R_SMAW_HEAT_N_Rubber";
    };*/
    class CUP_Stinger_M;
    class CUP_Stinger_M_Rubber: CUP_Stinger_M {
        scopeArsenal = 1;
        displayName = "FIM-92F Stinger Rubber";
        displayNameShort = "AA Rubber";
        ammo = "CUP_M_Stinger_AA_Rubber";
    };/*
    class CUP_20Rnd_TE1_Red_Tracer_120mmSABOT_M256_Cannon_M;
    class CUP_20Rnd_TE1_White_Tracer_120mmSABOT_M256_Cannon_M_Rubber: CUP_20Rnd_TE1_Red_Tracer_120mmSABOT_M256_Cannon_M {        
        displayName = "120mm APFSDS-T Rubber";
        displayNameShort = "APFSDS-T Rubber";
        ammo = "Sh_120mm_APFSDS_Tracer_White_Rubber";
    };
    class CUP_20Rnd_TE1_Red_Tracer_120mmHE_M256_Cannon_M;
    class CUP_20Rnd_TE1_White_Tracer_120mmHE_M256_Cannon_M_Rubber: CUP_20Rnd_TE1_Red_Tracer_120mmHE_M256_Cannon_M {        
        displayName = "120mm HEAT-MP-T Rubber";
        displayNameShort = "HEAT-MP-T Rubber";
        ammo = "Sh_120mm_HE_Tracer_White_Rubber";
    };
    class CUP_210Rnd_TE1_Red_Tracer_25mm_M242_HE;
    class CUP_210Rnd_TE1_White_Tracer_25mm_M242_HE_Rubber: CUP_210Rnd_TE1_Red_Tracer_25mm_M242_HE {
        displayName = "M242 25mm HEI-T Magazine";
        displayNameShort = "M242 HEI-T Rubber";
        ammo = "CUP_B_25mm_HE_White_Tracer_Rubber";
    };
    class CUP_210Rnd_TE1_Red_Tracer_25mm_M242_APFSDS;
    class CUP_210Rnd_TE1_White_Tracer_25mm_M242_APFSDS_Rubber: CUP_210Rnd_TE1_Red_Tracer_25mm_M242_APFSDS {
        displayName = "M242 25mm APFSDS-T Magazine";
        displayNameShort = "M242 APFSDS-T Rubber";
        ammo = "CUP_B_25mm_APFSDS_White_Tracer_Rubber";
    };*/
    class CUP_4Rnd_Stinger_M;
    class CUP_4Rnd_Stinger_M_Rubber: CUP_4Rnd_Stinger_M {
        displayName = "FIM-92F Stinger Rubber";
        displayNameShort = "AA Rubber";
        ammo = "CUP_M_Stinger_AA_Rubber";
    };
};
