class CfgMagazines {
    class UK3CB_BAF_762_100Rnd;
    class UK3CB_BAF_762_100Rnd_EL : UK3CB_BAF_762_100Rnd {
        displayname = "7.62mm 100rnd EL Belt";
        displaynameshort = "7.62mm EL";
        ammo = "UK3CB_BAF_762_Ball_EL";
    };
    class UK3CB_BAF_762_100Rnd_T;
    class UK3CB_BAF_762_100Rnd_T_EL : UK3CB_BAF_762_100Rnd_T {
        displayname = "7.62mm 100rnd EL Tracer Belt";
        displaynameshort = "7.62mm EL Tracer";
        ammo = "UK3CB_BAF_762_Ball_Tracer_Red_EL";
    };
    class UK3CB_BAF_762_200Rnd;
    class UK3CB_BAF_762_200Rnd_EL : UK3CB_BAF_762_200Rnd {
        displayname = "7.62mm 200rnd EL Belt";
        displaynameshort = "7.62mm EL";
        ammo = "UK3CB_BAF_762_Ball_EL";
    };
    class UK3CB_BAF_762_200Rnd_T;
    class UK3CB_BAF_762_200Rnd_T_EL : UK3CB_BAF_762_200Rnd_T {
        displayname = "7.62mm 200rnd EL Tracer Belt";
        displaynameshort = "7.62mm EL Tracer";
        ammo = "UK3CB_BAF_762_Ball_Tracer_Red_EL";
    };
    class UK3CB_BAF_127_10Rnd;
    class UK3CB_BAF_127_10Rnd_T : UK3CB_BAF_127_10Rnd {
        displayname = "12.7mm 10rnd Tracer Mag";
        displaynameshort = "12.7mm Tracer";
        ammo = "UK3CB_BAF_B_127x99_T";
        tracersEvery = 1;
    };

    class 7Rnd_408_Mag;
    class UK3CB_BAF_338_5Rnd: 7Rnd_408_Mag {
        tracersevery = 0;
    };

    // Javelin
    class CA_LauncherMagazine;
    class UK3CB_BAF_Javelin_Mag : CA_LauncherMagazine {
        mass = 260;
    };
    // MAAWS
    class MRAWS_HEAT_F : CA_LauncherMagazine {
        mass = 75;
    };
    class MRAWS_HE_F : MRAWS_HEAT_F {
        mass = 44;
    };
    class MRAWS_HEAT55_F : MRAWS_HEAT_F {
        mass = 55;
    };

    class DemoCharge_Remote_Mag;
    class BreachCharge_Remote_Mag : DemoCharge_Remote_Mag {
        author = "UKSF";
        mass = 10;
        ammo = "BreachCharge_Remote_Ammo";
        class Library {
            libTextDesc = "Breaching Charge. It can be set to detonate either by the built-in timer or a remote detonator.";
        };
        type = "2 * 256";
        allowedSlots[] = { 901, 701 };
        displayName = "Breaching Charge";
        ace_explosives_SetupObject = "ACE_Explosives_Place_BreachCharge";
    };

    class VehicleMagazine;
    class CUP_100Rnd_127x99_M : VehicleMagazine {
        picture = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Ammo\data\gear_magazine_belt_tracer_ca.paa";
    };
    class 200Rnd_40mm_G_belt : VehicleMagazine {
        picture = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Ammo\data\gear_magazine_belt_tracer_ca.paa";
    };

    class 8Rnd_82mm_Mo_shells;
    class UK3CB_BAF_1Rnd_81mm_Mo_Shells : 8Rnd_82mm_Mo_shells {
        initSpeed = 305;  // 200
    };
    class UK3CB_BAF_1Rnd_81mm_Mo_AB_Shells : 8Rnd_82mm_Mo_shells {
        initSpeed = 305;  // 200
    };
    class 8Rnd_82mm_Mo_Flare_white;
    class UK3CB_BAF_1Rnd_81mm_Mo_Flare_White : 8Rnd_82mm_Mo_Flare_white {
        initSpeed = 305;  // 200
    };
    class UK3CB_BAF_1Rnd_81mm_Mo_IRFlare_White : 8Rnd_82mm_Mo_Flare_white {
        initSpeed = 305;  // 200
    };
    class 8Rnd_82mm_Mo_Smoke_white;
    class UK3CB_BAF_1Rnd_81mm_Mo_Smoke_White : 8Rnd_82mm_Mo_Smoke_white {
        initSpeed = 305;  // 200
    };
    class UK3CB_BAF_1Rnd_81mm_Mo_WPSmoke_White : 8Rnd_82mm_Mo_Smoke_white {
        initSpeed = 305;  // 200
    };
    class 8Rnd_82mm_Mo_guided;
    class UK3CB_BAF_1Rnd_81mm_Mo_Guided : 8Rnd_82mm_Mo_guided {
        initSpeed = 305;  // 200
    };
    class 8Rnd_82mm_Mo_LG;
    class UK3CB_BAF_1Rnd_81mm_Mo_LG : 8Rnd_82mm_Mo_LG {
        initSpeed = 305;  // 200
    };
};
