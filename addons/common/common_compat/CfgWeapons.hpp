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
};
