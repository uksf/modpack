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

    // Hellfire K
    class 12Rnd_PG_missiles;
    class 6Rnd_ACE_Hellfire_AGM114K: 12Rnd_PG_missiles {
        displayName = "AGM-114K";
    };
    class 4Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K";
        count = 4;
    };
    class 2Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K";
        count = 2;
    };
    class PylonMissile_1Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "1x AGM-114K";
        hardpoints[] = { "SCALPEL_1RND" };
    };
    class PylonRack_1Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "1x AGM-114K";
        hardpoints[] = { "B_MISSILE_PYLON", "SCALPEL_1RND_EJECTOR", "B_ASRRAM_EJECTOR", "UNI_SCALPEL" };
    };
    class PylonRack_3Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "3x AGM-114K";
        hardpoints[] = { "B_MISSILE_PYLON", "UNI_SCALPEL" };
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "4x AGM-114K";
        hardpoints[] = { "UNI_SCALPEL", "B_HELLFIRE" };
    };
    // Hellfire N
    class 6Rnd_ACE_Hellfire_AGM114N: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114N";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
    };
    class 2Rnd_ACE_Hellfire_AGM114N: 6Rnd_ACE_Hellfire_AGM114N {
        count = 2;
    };
    class 4Rnd_ACE_Hellfire_AGM114N: 6Rnd_ACE_Hellfire_AGM114N {
        count = 4;
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114N: PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "4x AGM-114N";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        pylonWeapon = "ace_hellfire_launcher_N";
    };
    // Hellfire L
    class 6Rnd_ACE_Hellfire_AGM114L: 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114L";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
        ammo = "ACE_Hellfire_AGM114L";
    };
    class 2Rnd_ACE_Hellfire_AGM114L: 6Rnd_ACE_Hellfire_AGM114L {
        count = 2;
    };
    class 4Rnd_ACE_Hellfire_AGM114L: 6Rnd_ACE_Hellfire_AGM114L {
        count = 4;
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114L: PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "4x AGM-114L";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
        pylonWeapon = "ace_hellfire_launcher_L";
        ammo = "ACE_Hellfire_AGM114L";
    };

    class CUP_19Rnd_CRV7_FAT_M;
    class CUP_PylonPod_19Rnd_CRV7_FAT_M: CUP_19Rnd_CRV7_FAT_M {
        hardpoints[] += { "B_CRV7" };
        model = QPATHTOEF(apache,PylonRocket_19Rnd_CRV7_HEISAP.p3d);
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };
    class CUP_PylonPod_12Rnd_CRV7_FAT_M: CUP_19Rnd_CRV7_FAT_M {
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };
    class CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M;
    class CUP_PylonPod_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M: CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M {
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };

    class VehicleMagazine;
    class CUP_100Rnd_127x99_M: VehicleMagazine {
        picture = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Ammo\data\gear_magazine_belt_tracer_ca.paa";
    };
    class 200Rnd_40mm_G_belt: VehicleMagazine {
        picture = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Ammo\data\gear_magazine_belt_tracer_ca.paa";
    };

    class CUP_Stinger_M;
    class CUP_Stinger_M_Rubber: CUP_Stinger_M {
        scopeArsenal = 1;
        displayName = "FIM-92F Stinger Rubber";
        displayNameShort = "AA Rubber";
        ammo = "CUP_M_Stinger_AA_Rubber";
    };
    class CUP_4Rnd_Stinger_M;
    class CUP_4Rnd_Stinger_M_Rubber: CUP_4Rnd_Stinger_M {
        displayName = "FIM-92F Stinger Rubber";
        displayNameShort = "AA Rubber";
        ammo = "CUP_M_Stinger_AA_Rubber";
    };
};
