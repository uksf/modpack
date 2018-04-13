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

    class Chemlight_red;
    class ACE_Chemlight_HiRed: Chemlight_red {
        descriptionShort = "Type: Light - Red Hi<br />Rounds: 1<br />Used in: Hand";
    };
    class Chemlight_yellow;
    class ACE_Chemlight_HiYellow: Chemlight_yellow {
        descriptionShort = "Type: Light - Yellow Hi<br />Rounds: 1<br />Used in: Hand";
    };
    class ACE_Chemlight_Orange;
    class ACE_Chemlight_HiOrange: ACE_Chemlight_Orange {
        descriptionShort = "Type: Light - Orange Hi<br />Rounds: 1<br />Used in: Hand";
    };
    class ACE_Chemlight_White;
    class ACE_Chemlight_HiWhite: ACE_Chemlight_White {
        descriptionShort = "Type: Light - White Hi<br />Rounds: 1<br />Used in: Hand";
    };
    class Chemlight_blue;
    class ACE_Chemlight_HiBlue: Chemlight_blue {
        ACE_Attachable = "ACE_G_Chemlight_HiBlue";
        ACE_Chemlight_Shield = "";
        author = "ACE-Team";
        ammo = "ACE_G_Chemlight_HiBlue";
        displayName = "Chemlight (Hi Blue)";
        displayNameShort = "Blue Hi Light";
        descriptionShort = "Type: Light - Blue Hi<br />Rounds: 1<br />Used in: Hand";
    };
    class Chemlight_green;
    class ACE_Chemlight_HiGreen: Chemlight_green {
        ACE_Attachable = "ACE_G_Chemlight_HiGreen";
        ACE_Chemlight_Shield = "";
        author = "ACE-Team";
        ammo = "ACE_G_Chemlight_HiGreen";
        displayName = "Chemlight (Hi Green)";
        displayNameShort = "Green Hi Light";
        descriptionShort = "Type: Light - Green Hi<br />Rounds: 1<br />Used in: Hand";
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
    class 4Rnd_ACE_Hellfire_AGM114K_drone: 4Rnd_ACE_Hellfire_AGM114K {
        ammo = "ACE_Hellfire_AGM114K_drone";
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
    class PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone: PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "2x AGM-114K";
        ammo = "ACE_Hellfire_AGM114K_drone";
        model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
        count = 2;
        pylonWeapon = "ace_hellfire_launcher_drone";
        hardpoints[] = { "B_HELLFIRE_DRONE" };
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
    class 4Rnd_ACE_Hellfire_AGM114N_drone: 4Rnd_ACE_Hellfire_AGM114N {
        ammo = "ACE_Hellfire_AGM114N_drone";
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114N: PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "4x AGM-114N";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        pylonWeapon = "ace_hellfire_launcher_N";
    };
    class PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone: PylonRack_4Rnd_ACE_Hellfire_AGM114N {
        displayName = "2x AGM-114N";
        ammo = "ACE_Hellfire_AGM114N_drone";
        model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
        count = 2;
        pylonWeapon = "ace_hellfire_launcher_drone_N";
        hardpoints[] = { "B_HELLFIRE_DRONE" };
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
    class DemoCharge_Remote_Mag;
    class BreachCharge_Remote_Mag: DemoCharge_Remote_Mag {
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
