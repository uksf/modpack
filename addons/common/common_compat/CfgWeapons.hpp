// UK3CB visible lasers still use the removed ACE_laserpointer config, so ACE blocks the mode.
// Same beam as ACE POINTER_VISIBLE_*, on the memory points the L105A1 IR laser uses.
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
    // EAWS and the RKSL Brimstone list magazines whose classes are gone (see CfgMagazines.hpp) or never existed.
    class missiles_Zephyr;
    class EAWS_AIM120 : missiles_Zephyr {
        magazines[] = { "EAWS_AIM120_x2" };
    };
    class MissileLauncher;
    class rksla3_wpn_brimstone_dm : MissileLauncher {
        magazines[] = { "rksla3_mag_brimstone_dm_sglrail_x1", "rksla3_mag_brimstone_dm_sglrailuav_x1", "rksla3_mag_brimstone_dm_agml_x3", "rksla3_mag_brimstone_dm_agmlrear_x3" };
    };
    // The Alpine and Black MBSS vests inherit VSM vests that our VSM subset does not ship, so they have no
    // model or stats. Hidden until a VSM source is added. delete does not work on these CfgWeapons classes.
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
};
