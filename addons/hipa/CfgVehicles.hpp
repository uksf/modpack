class CfgVehicles {
    class O_Soldier_base_F;
    class GVAR(Soldier_Underwear) : O_Soldier_base_F {
        scope = 1;
        author = QUOTE(UKSF);
        displayName = "Soldier (Underwear)";
        model = "\A3\Characters_F\Common\basicbody";
        uniformClass = "U_BasicBody";
        weapons[] = {};
        respawnWeapons[] = {};
        magazines[] = {};
        respawnMagazines[] = {};
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
    };

    class GVAR(Soldier_Base) : O_Soldier_base_F {
        scope = 0;
        author = QUOTE(UKSF);
        displayName = "Soldier Base";
        genericNames = "FrenchMen";
        identityTypes[] = {"LanguageFRE_F", "Head_Euro", "G_Euro"};
        faction = QUOTE(ADDON);
        side = 0;
        minSkill = 0.4;
        maxSkill = 0.6;
        nakedUniform = "U_BasicBody";
        uniformClass = "CUP_U_B_USMC_MCCUU_M81_gloves";
        weapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "Put", "Throw"};
        respawnWeapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "Put", "Throw"};
        magazines[] = {
            "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
            "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
            "SmokeShell", "HandGrenade", "HandGrenade"
        };
        respawnMagazines[] = {
            "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
            "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
            "SmokeShell", "HandGrenade", "HandGrenade"
        };
        items[] = {
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
        };
        respawnItems[] = {
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
        };
        linkedItems[] = {"CUP_V_B_PASGT", "CUP_H_PASGTv2_NVG_WDL", "CUP_G_RUS_Ratnik_Balaclava_Green_1", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
        respawnLinkedItems[] = {"CUP_V_B_PASGT", "CUP_H_PASGTv2_NVG_WDL", "CUP_G_RUS_Ratnik_Balaclava_Green_1", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    };

    class GVAR(Soldier_SF_Base) : O_Soldier_base_F {
        scope = 0;
        author = QUOTE(UKSF);
        displayName = "Soldier Base";
        genericNames = "FrenchMen";
        identityTypes[] = {"LanguageFRE_F", "Head_Euro", "G_Euro"};
        faction = QUOTE(ADDON);
        editorSubcategory = QGVAR(sf);
        side = 0;
        minSkill = 0.4;
        maxSkill = 0.6;
        nakedUniform = "U_BasicBody";
        uniformClass = "CUP_U_CRYE_G3C_M81";
        weapons[] = {QGVAR(CUP_arifle_G36C_VFG_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed), "Put","Throw"};
        respawnWeapons[] = {QGVAR(CUP_arifle_G36C_VFG_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed), "Put","Throw"};
        magazines[] = {
            "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8","CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
            "SmokeShell", "HandGrenade", "HandGrenade"
        };
        respawnMagazines[] = {
            "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8","CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
            "SmokeShell", "HandGrenade", "HandGrenade"
        };
        items[] = {
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
        };
        respawnItems[] = {
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
        };
        linkedItems[] = {"CUP_V_B_PASGT", "CUP_H_PASGTv2_NVG_WDL", "CUP_G_RUS_Ratnik_Balaclava_Green_1", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_OPFOR"};
        respawnLinkedItems[] = {"CUP_V_B_PASGT", "CUP_H_PASGTv2_NVG_WDL", "CUP_G_RUS_Ratnik_Balaclava_Green_1", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_OPFOR"};
    };

    // backpacks
    class B_AssaultPack_rgr;
    class CUP_B_Kombat_Radio_Olive;
    class GVAR(sf_pack) : B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(SmokeShell,4);
            MACRO_ADDMAGAZINE(HandGrenade,2);
            MACRO_ADDMAGAZINE(ACE_CTS9,3);
        };
    };

    class GVAR(sf_mg_pack) : B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(SmokeShell,4);
            MACRO_ADDMAGAZINE(HandGrenade,2);
            MACRO_ADDMAGAZINE(ACE_CTS9,3);
            MACRO_ADDMAGAZINE(CUP_100Rnd_556x45_BetaCMag,4);
        };
    };

    class GVAR(sl_backpack) : CUP_B_Kombat_Radio_Olive {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,4);
            MACRO_ADDMAGAZINE(CUP_FlareYellow_M203,3);
            MACRO_ADDMAGAZINE(1Rnd_Smoke_Grenade_shell,3);
        };
    };

    class GVAR(mg_backpack) : B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M,3);
            MACRO_ADDMAGAZINE(SmokeShell,2);
        };
    };

    class GVAR(lat_backpack) : B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_SMAW_HEDP_M,1);
        };
    };

    class GVAR(hat_backpack) : B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(RPG32_F,2);
        };
    };

    class GVAR(aa_backpack) : B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(Titan_AA,1);
        };
    };

    #include "units\CfgUnitsMen.hpp"
    #include "units\CfgUnitsMenSF.hpp"
    #include "units\CfgUnitsMenSpecialists.hpp"

    #include "vehicles\CfgTrucks.hpp"
    #include "vehicles\CfgCars.hpp"
    #include "vehicles\CfgStatic.hpp"
    #include "vehicles\CfgArmored.hpp"
    #include "vehicles\CfgAircraft.hpp"
};
