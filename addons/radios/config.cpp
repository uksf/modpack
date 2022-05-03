#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(rebroStationBox),
            QGVAR(rebroStationMast),
            QGVAR(rebroStationEquipment)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "uksf_vehicles",
            "uksf_persistence",
            "acre_sys_radio",
            "acre_sys_gsa"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgChannels.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
