class CfgWeapons {
    class ItemCore;
    class InventoryFlashLightItem_Base_F;
    class UK3CB_BAF_L105A1_LLM_VL_R : ItemCore {
        ACE_laserpointer = 0;
        class ItemInfo : InventoryFlashLightItem_Base_F {
            class Pointer {
                irLaserPos = "flash";
                irLaserEnd = "flash dir";
                irDistance = 5;
                isIR = 0;
                irDotSize = 0.025;
                beamThickness = 0;
                beamMaxLength = 50;
                dotColor[] = { 16384, 0, 0 };
                beamColor[] = { 0, 0, 0 };
            };
        };
    };
    class UK3CB_BAF_L105A1_LLM_VL_G : UK3CB_BAF_L105A1_LLM_VL_R {
        ACE_laserpointer = 0;
        class ItemInfo : ItemInfo {
            class Pointer : Pointer {
                beamMaxLength = 75;
                dotColor[] = { 0, 16384, 0 };
            };
        };
    };
    class missiles_Zephyr;
    class EAWS_AIM120 : missiles_Zephyr {
        magazines[] = { "EAWS_AIM120_x2" };
    };
    class MissileLauncher;
    class rksla3_wpn_brimstone_dm : MissileLauncher {
        magazines[] = { "rksla3_mag_brimstone_dm_sglrail_x1", "rksla3_mag_brimstone_dm_sglrailuav_x1", "rksla3_mag_brimstone_dm_agml_x3", "rksla3_mag_brimstone_dm_agmlrear_x3" };
    };
    class VSM_MBSS_PACA;
    class VSM_MBSS_Green;
    class dr_MBSS_PACA : VSM_MBSS_PACA {
        scope = 1;
        scopeArsenal = 0;
    };
    class dr_MBSS_Green : VSM_MBSS_Green {
        scope = 1;
        scopeArsenal = 0;
    };
    class BLK_MBSS_PACA : VSM_MBSS_PACA {
        scope = 1;
        scopeArsenal = 0;
    };
    class BLK_MBSS_Green : VSM_MBSS_Green {
        scope = 1;
        scopeArsenal = 0;
    };
    class Rifle_Base_F;
    class CUP_arifle_SCAR_Base : Rifle_Base_F {
        modes[] = { "SCAR_L_Single", "SCAR_L_FullAuto" };
    };
};
