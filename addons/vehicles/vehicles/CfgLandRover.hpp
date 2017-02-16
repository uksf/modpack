class CUP_LR_Base : Car_F {};
class CUP_LR_MG_Base : CUP_LR_Base {};
class CUP_LR_Special_Base : CUP_LR_Base {};
class CUP_LR_Ambulance_Base : CUP_LR_Base {};
class CUP_B_LR_MG_GB_W : CUP_LR_MG_Base {
    NET_ACTIONS
};
class CUP_B_LR_Special_M2_GB_W : CUP_LR_Special_Base {
    NET_ACTIONS
};
class CUP_B_LR_Special_GMG_GB_W : CUP_LR_Special_Base {
    NET_ACTIONS
};
class CUP_B_LR_Ambulance_GB_W : CUP_LR_Ambulance_Base {
    class TransportItems {
        class _xx_ACE_EarPlugs {
            name = "ACE_EarPlugs";
            count = 10;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 50;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 50;
        };
        class _xx_ACE_morphine {
            name = "ACE_morphine";
            count = 30;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 30;
        };
        class _xx_ACE_bloodIVItem {
            name = "ACE_bloodIVItem";
            count = 20;
        };
        class _xx_ACE_personalAidKit {
            name = "ACE_personalAidKit";
            count = 10;
        };
    };
    NET_MEDICAL_ACTIONS
};
class CUP_B_LR_Ambulance_GB_D : CUP_LR_Ambulance_Base {
    class TransportItems {
        class _xx_ACE_EarPlugs {
            name = "ACE_EarPlugs";
            count = 10;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 50;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 50;
        };
        class _xx_ACE_morphine {
            name = "ACE_morphine";
            count = 30;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 30;
        };
        class _xx_ACE_bloodIVItem {
            name = "ACE_bloodIVItem";
            count = 20;
        };
        class _xx_ACE_personalAidKit {
            name = "ACE_personalAidKit";
            count = 10;
        };
    };
    NET_MEDICAL_ACTIONS
};
