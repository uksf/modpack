class CfgMovesBasic {
    class Actions {
        class RifleAdjustProneBaseActions;
        class RifleAdjustFProneActions : RifleAdjustProneBaseActions {
            HLC_GestureReloadAWM[] = { "HLC_GestureReloadAWM_Context", "Gesture" };
            HLC_GestureRechamberAWM[] = { "HLC_GestureRechamberAWM_Context", "Gesture" };
            CUP_GestureReloadM249[] = { "CUP_GestureReloadM249_Context", "Gesture" };
            CUP_GestureReloadM249STANAG[] = { "CUP_GestureReloadM249STANAG_Context", "Gesture" };
            CUP_GestureReloadM60[] = { "CUP_GestureReloadM60", "Gesture" };
            CUP_GestureReloadM14[] = { "CUP_GestureReloadM14_Prone", "Gesture" };
            CUP_GestureReloadG36A1[] = { "CUP_GestureReloadG36A1_Context", "Gesture" };
            CUP_GestureReloadAG36[] = { "CUP_GestureReloadAG36_Context", "Gesture" };
            CUP_GestureReloadSA80[] = { "CUP_GestureReloadSA80", "Gesture" };
            CUP_GestureReloadFAL[] = { "CUP_GestureReloadFAL_Context", "Gesture" };
            CUP_GestureReloadVSS[] = { "CUP_GestureReloadVSS_Context", "Gesture" };
            CUP_GestureReloadAK[] = { "CUP_GestureReloadAK_Context", "Gesture" };
            CUP_GestureReloadSA61[] = { "CUP_GestureReloadSA61_Context", "Gesture" };
            CUP_GestureReloadSA61SMG[] = { "CUP_GestureReloadSA61SMG_Context", "Gesture" };
            CUP_GestureReloadPDW[] = { "CUP_GestureReloadPDW_Context", "Gesture" };
            CUP_GestureBoltActionFire[] = { "CUP_BoltCycle_Context", "Gesture" };
            CUP_GestureReloadG3[] = { "CUP_GestureReloadG3_Context", "Gesture" };
            CUP_GestureReloadAUG[] = { "CUP_GestureReloadAUG_Context", "Gesture" };
            CUP_GestureReloadM4[] = { "CUP_GestureReloadM4_Context", "Gesture" };
            CUP_GestureReloadM1014_8Rnd[] = { "CUP_GestureReloadM1014_8Rnd_Context", "Gesture" };
            CUP_GestureReloadM1014_6Rnd[] = { "CUP_GestureReloadM1014_6Rnd_Context", "Gesture" };
            CUP_GestureReloadM1014_2Rnd[] = { "CUP_GestureReloadM1014_2Rnd_Context", "Gesture" };
            CUP_GestureReloadM1014_1Rnd[] = { "CUP_GestureReloadM1014_1Rnd_Context", "Gesture" };
            CUP_GestureReloadAWM[] = { "CUP_GestureReloadAWM_Context", "Gesture" };
            CUP_GestureRechamberAWM[] = { "CUP_GestureRechamberAWM_Context", "Gesture" };
            CUP_GestureReloadBolt1[] = { "CUP_GestureReloadBolt1_Context", "Gesture" };
            CUP_GestureRechamberKSVK[] = { "CUP_GestureRechamberKSVK_Context", "Gesture" };
            CUP_GestureReloadDSAOSW[] = { "CUP_GestureReloadDSAOSW_Context", "Gesture" };
            CUP_GestureRechamberMosin[] = { "CUP_GestureRechamberMosin_Context", "Gesture" };
            CUP_GestureReloadMosin[] = { "CUP_GestureReloadMosin_Context", "Gesture" };
            CUP_GestureReloadSKS[] = { "CUP_GestureReloadSKS_Context", "Gesture" };
            CUP_GestureReloadSlamfire[] = { "CUP_GestureReloadSlamfire_Context", "Gesture" };
            CUP_GestureReloadDSAGL[] = { "CUP_GestureReloadDSAGL_Context", "Gesture" };
            CUP_GestureReloadACR[] = { "CUP_GestureReloadACR_Context", "Gesture" };
            CUP_GestureReloadMG3[] = { "CUP_GestureReloadMG3_Context", "Gesture" };
            CUP_GestureReloadXM8[] = { "CUP_GestureReloadXM8_Context", "Gesture" };
            CUP_GestureReloadXM320[] = { "CUP_GestureReloadXM320_Context", "Gesture" };
        };
    };
};
class CfgMovesMaleSdr : CfgMovesBasic {
    class States {
        class Crew;
        class RKSLA3_AW159_Pilot : Crew {
            interpolateTo[] = { "Unconscious", 0.02 };
        };
    };
};

class CfgGesturesMale {
    class States {
        class acre_sys_gestures_base;
        class acre_sys_gestures_helmet : acre_sys_gestures_base {
            looped = 1;
        };
        class acre_sys_gestures_vest : acre_sys_gestures_base {
            looped = 1;
        };
        class CUP_GestureReloadM249STANAG;
        class CUP_GestureReloadM249STANAG_Context : CUP_GestureReloadM249STANAG {
            mask = "handsWeapon_context";
        };
        class UK3CB_GestureReloadM249STANAG;
        class UK3CB_GestureReloadM249STANAG_Context : UK3CB_GestureReloadM249STANAG {
            mask = "handsWeapon_context";
        };
        class GestureHold_UK3CB_L7_Deployed_prone;
        class GestureHold_UK3CB_L7_Deployed_prone_Context : GestureHold_UK3CB_L7_Deployed_prone {
            mask = "handsWeapon_context";
        };
    };
};
