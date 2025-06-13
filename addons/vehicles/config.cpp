#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "Land_CanisterFuel_F",
            "CargoNet_01_barrels_F",
            "UK3CB_BAF_MAN_HX58_Rearm_Green",
            "UK3CB_BAF_MAN_HX58_Rearm_Sand",
            "UK3CB_BAF_MAN_HX60_Rearm_Green",
            "UK3CB_BAF_MAN_HX60_Rearm_Sand",
            QGVAR(rhicc_green),
            QGVAR(rhicc_grey),
            QGVAR(L119),
            QGVAR(landrover_lightgun_green),
            QGVAR(landrover_lightgun_greenblack),
            QGVAR(landrover_lightgun_sand)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QGVAR(prep),
            "tbd_m119_m119"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
