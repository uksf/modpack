#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            // Units
            QGVAR(rifleman),
            QGVAR(grenadier),
            QGVAR(sl),
            QGVAR(tl),
            QGVAR(officer),
            QGVAR(mg),
            QGVAR(medic),
            QGVAR(marksman),
            QGVAR(sniper),
            QGVAR(at),
            QGVAR(aa),
            QGVAR(crewman),
            QGVAR(crew_heli),
            QGVAR(crew_jet),

            // Vehicles
            QGVAR(pandur),
            QGVAR(landrover_transport),
            QGVAR(landrover_mg),
            QGVAR(landrover_gmg),
            QGVAR(kamaz_transport),
            QGVAR(kamaz_transport_covered),
            QGVAR(kamaz_fuel),
            QGVAR(kamaz_repair),
            QGVAR(kasatka),
            QGVAR(gripen)
        };
        weapons[] = {
            "arifle_AK12_F_optic_MRCO",
            "CUP_srifle_SVD_des_GOSHAWK",
            "srifle_EBR_F_snds_MRCO",
            "arifle_Mk20_GL_ACO_F_grn",
            "hgun_PDW2000_Holo_F_Holosight"
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
