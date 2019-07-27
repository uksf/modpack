#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            // Units
            QGVAR(tl),
            QGVAR(mg),
            QGVAR(medic),
            QGVAR(at),
            QGVAR(marksman),
            QGVAR(diver),
            QGVAR(explosive_specialist),
            QGVAR(sniper),
            QGVAR(civ_undercover_1),
            QGVAR(civ_undercover_2),
            QGVAR(civ_undercover_3),
            QGVAR(civ_undercover_4),
            QGVAR(civ_sniper),
            QGVAR(crew_jet),
            QGVAR(crew_heli),

            // Vehicles
            QGVAR(lmv),
            QGVAR(mk6),
            QGVAR(kasatka),
            QGVAR(su34)
        };
        weapons[] = {
            "CUP_arifle_AK74M_camo_acc_flashlight",
            "CUP_srifle_SVD_des_PSO_camo",
            "SMG_02_ACO_F_ACO_grn",
            "CUP_srifle_SVD_PSO_camo"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
