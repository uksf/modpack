#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(rappelling_helper)
        };
        weapons[] = {
            "UK3CB_BAF_LLM_Flashlight_Far_Black",
            "ACE_NVG_Pilot",
            "ACE_NVG_Pilot_WP",
            "CUP_NVG_PVS15_black_WP",
            "CUP_NVG_PVS15_green_WP",
            "CUP_NVG_PVS15_tan_WP",
            "CUP_NVG_PVS15_winter_WP",
            "UK3CB_BAF_HMNVS_WP",
            "NVGoggles_mas_ukl_hv18_wp",
            "NVGoggles_mas_ukl_hv_wp",
            "CUP_NVG_GPNVG_black_wp",
            "CUP_NVG_GPNVG_green_wp",
            "CUP_NVG_GPNVG_tan_wp",
            "UK3CB_BAF_L85A3_Grippod_Elcan",
            "UK3CB_BAF_L22A2_Elcan",
            "UK3CB_BAF_L85A3_UGL_Elcan",
            "UK3CB_BAF_L110A3_Elcan",
            "UK3CB_BAF_L129A1_Grippod_Acog",
            "UK3CB_BAF_L115A3_LRPS",
            "UK3CB_BAF_L115A3_DE_LRPS",
            "UK3CB_BAF_L135A1_LRPS",
            "UK3CB_BAF_Javelin_CLU"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QGVAR(prep),
            "tbd_mortars_105mm_round_he"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFunctions.hpp"
#include "CfgMagazineWells.hpp"
#include "CfgMagazines.hpp"
#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
