#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "CUP_O_RU_JTAC_Flora",
            "CUP_O_RU_JTAC_EMR",
            "CUP_O_RU_RTO_EMR"
        };
        weapons[] = {
            "CUP_srifle_SVD_Bridg"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T", "Bridgford.A" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
