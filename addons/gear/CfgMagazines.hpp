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
    class 1Rnd_GBU12_LGB : 2Rnd_GBU12_LGB {
        count = 1;
    };
};
