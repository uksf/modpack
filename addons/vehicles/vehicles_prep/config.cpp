#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class CUP_Mastiff_Base;
    RESET_INVENTORY(CUP_B_Mastiff_HMG_GB_D,CUP_Mastiff_Base);
    RESET_INVENTORY(CUP_B_Mastiff_HMG_GB_W,CUP_Mastiff_Base);
    RESET_INVENTORY(CUP_B_Mastiff_GMG_GB_D,CUP_Mastiff_Base);
    RESET_INVENTORY(CUP_B_Mastiff_GMG_GB_W,CUP_Mastiff_Base);
    RESET_INVENTORY(CUP_B_Mastiff_LMG_GB_D,CUP_Mastiff_Base);
    RESET_INVENTORY(CUP_B_Mastiff_LMG_GB_W,CUP_Mastiff_Base);

    class CUP_Ridgback_Base;
    RESET_INVENTORY(CUP_B_Ridgback_HMG_GB_D,CUP_Ridgback_Base);
    RESET_INVENTORY(CUP_B_Ridgback_HMG_GB_W,CUP_Ridgback_Base);
    RESET_INVENTORY(CUP_B_Ridgback_GMG_GB_D,CUP_Ridgback_Base);
    RESET_INVENTORY(CUP_B_Ridgback_GMG_GB_W,CUP_Ridgback_Base);
    RESET_INVENTORY(CUP_B_Ridgback_LMG_GB_D,CUP_Ridgback_Base);
    RESET_INVENTORY(CUP_B_Ridgback_LMG_GB_W,CUP_Ridgback_Base);

    class CUP_Wolfhound_Base;
    RESET_INVENTORY(CUP_B_Wolfhound_HMG_GB_D,CUP_Wolfhound_Base);
    RESET_INVENTORY(CUP_B_Wolfhound_HMG_GB_W,CUP_Wolfhound_Base);
    RESET_INVENTORY(CUP_B_Wolfhound_GMG_GB_D,CUP_Wolfhound_Base);
    RESET_INVENTORY(CUP_B_Wolfhound_GMG_GB_W,CUP_Wolfhound_Base);
    RESET_INVENTORY(CUP_B_Wolfhound_LMG_GB_D,CUP_Wolfhound_Base);
    RESET_INVENTORY(CUP_B_Wolfhound_LMG_GB_W,CUP_Wolfhound_Base);
};
