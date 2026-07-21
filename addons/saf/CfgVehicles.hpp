class CfgVehicles {
    class B_Soldier_base_F;
    class GVAR(Soldier_Underwear) : B_Soldier_base_F {
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

    class GVAR(Soldier_Base) : B_Soldier_base_F {
        scope = 0;
        author = QUOTE(UKSF);
        displayName = "Soldier Base";
        genericNames = "PolishMen";
        identityTypes[] = {"LanguagePOL", "Head_Euro", "G_Euro"};
        faction = QUOTE(ADDON);
        side = 1;
        minSkill = 0.4;
        maxSkill = 0.6;
        nakedUniform = "U_BasicBody";
        uniformClass = "CUP_U_B_BDUv2_gloves_ERDL_highland";
        weapons[] = {QGVAR(grot), "Put", "Throw"};
        respawnWeapons[] = {QGVAR(grot), "Put", "Throw"};
        magazines[] = {
            "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
            "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer",
            "SmokeShell", "HandGrenade", "HandGrenade"
        };
        respawnMagazines[] = {
            "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
            "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer",
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
        linkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F", "CUP_H_PASGTv2_ERDL_highland", "CUP_TK_NeckScarf", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
        respawnLinkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F", "CUP_H_PASGTv2_ERDL_highland", "CUP_TK_NeckScarf", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    };

    class GVAR(Soldier_SF_Base) : B_Soldier_base_F {
        scope = 0;
        author = QUOTE(UKSF);
        displayName = "Soldier SF Base";
        genericNames = "PolishMen";
        identityTypes[] = {"LanguagePOL_F", "Head_Euro", "G_Euro"};
        faction = QUOTE(ADDON);
        editorSubcategory = QGVAR(sf);
        side = 1;
        minSkill = 0.4;
        maxSkill = 0.6;
        nakedUniform = "U_BasicBody";
        uniformClass = "CUP_U_CRYE_G3C_MC_V3";
        weapons[] = {QGVAR(hk416), "Put","Throw"};
        respawnWeapons[] = {QGVAR(hk416), "Put","Throw"};
        magazines[] = {
            "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL","CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL",
            "SmokeShell", "HandGrenade", "HandGrenade"
        };
        respawnMagazines[] = {
            "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL","CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL", "CUP_30Rnd_556x45_PMAG_OD_PULL",
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
        linkedItems[] = {"CUP_V_CPC_Fastbelt_mc", "CUP_H_OpsCore_Covered_MCAM", "CUP_G_ESS_RGR_Facewrap_Ranger", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_NVG_GPNVG_Hide"};
        respawnLinkedItems[] = {"CUP_V_CPC_Fastbelt_mc", "CUP_H_OpsCore_Covered_MCAM", "CUP_G_ESS_RGR_Facewrap_Ranger", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_NVG_GPNVG_Hide"};
    };

    // backpacks
    class UK3CB_BAF_B_Kitbag_OLI;
    class GVAR(mg_backpack) : UK3CB_BAF_B_Kitbag_OLI {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M,5);
            MACRO_ADDMAGAZINE(SmokeShell,2);
        };
    };

    class GVAR(lat_backpack) : UK3CB_BAF_B_Kitbag_OLI {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_OG7_M,2);
            MACRO_ADDMAGAZINE(CUP_PG7V_M,2);
        };
    };

    class GVAR(hat_backpack) : UK3CB_BAF_B_Kitbag_OLI {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_MAAWS_HEDP_M,2);
            MACRO_ADDMAGAZINE(CUP_MAAWS_HEAT_M,1);
        };
    };

    class GVAR(grenadier_backpack) : UK3CB_BAF_B_Kitbag_OLI {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,8);
            MACRO_ADDMAGAZINE(UK3CB_BAF_UGL_FlareWhite_F,3);
        };
    };

    class VSM_Multicam_Backpack_Compact;
    class GVAR(sf_lmg_backpack) : VSM_Multicam_Backpack_Compact {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(200Rnd_556x45_Box_Red_F,3);
            MACRO_ADDMAGAZINE(SmokeShell,2);
        };
    };

    class GVAR(sf_hat_backpack) : VSM_Multicam_Backpack_Compact {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_MAAWS_HEDP_M,2);
        };
    };

    class GVAR(sf_grenadier_backpack) : VSM_Multicam_Backpack_Compact {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,8);
            MACRO_ADDMAGAZINE(1Rnd_HE_CUP_1Rnd_Smoke_M203_Grenade_shell,4);
            MACRO_ADDMAGAZINE(CUP_1Rnd_StarFlare_White_M203,4);
        };
    };

    #include "units\CfgUnitsMen.hpp"
    #include "units\CfgUnitsMenSF.hpp"
    #include "units\CfgUnitsMenSpecialists.hpp"

    #include "vehicles\CfgAntiAir.hpp"
    #include "vehicles\CfgAPCs.hpp"
    #include "vehicles\CfgArtillery.hpp"
    #include "vehicles\CfgCars.hpp"
    #include "vehicles\CfgHelis.hpp"
    #include "vehicles\CfgPlanes.hpp"
    #include "vehicles\CfgStatic.hpp"
    #include "vehicles\CfgTanks.hpp"
    #include "vehicles\CfgTrucks.hpp"
};
