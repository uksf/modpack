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
    #include "CfgVehicles_houses_c.hpp"
    #include "CfgVehicles_houses.hpp"
    #include "CfgVehicles_civilian.hpp"
    #include "CfgVehicles_commercial.hpp"
    #include "CfgVehicles_industrial.hpp"
    #include "CfgVehicles_military.hpp"
    #include "CfgVehicles_a1_buildings.hpp"
    #include "CfgVehicles_walls.hpp"
    #include "CfgVehicles_misc.hpp"
};
