#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "CUP_A1_EditorObjects",
            "CUP_A2_EditorObjects",
            "CUP_CAMisc_ACR_Dog",
            "CUP_CAStructures_E_Mil",
            "CUP_CAStructures_Mil",
            "CUP_Ind_Mlyn",
            "CUP_StandaloneTerrains_Core_Faction"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    #include "CfgVehicles_base.hpp"
    #include "CfgVehicles_men.hpp"
    #include "CfgVehicles_structures.hpp"
    #include "CfgVehicles_other_1.hpp"
    #include "CfgVehicles_other_2.hpp"
    #include "CfgVehicles_other_3.hpp"
    #include "CfgVehicles_other_4.hpp"
    #include "CfgVehicles_other_5.hpp"
};
