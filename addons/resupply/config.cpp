#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(container),
            QGVAR(rx),
            QGVAR(arsenal),
            QGVAR(r1),
            QGVAR(r2),
            QGVAR(r3),
            QGVAR(r4),
            QGVAR(r5),
            QGVAR(r6),
            QGVAR(r7),
            QGVAR(r8),
            QGVAR(r9),
            QGVAR(rt),
            QGVAR(rb),
            QGVAR(gx),
            QGVAR(g1),
            QGVAR(g2),
            QGVAR(g3),
            QGVAR(g4),
            QGVAR(g5),
            QGVAR(g6),
            QGVAR(g7),
            QGVAR(g8),
            QGVAR(g9),
            QGVAR(g10),
            QGVAR(g11),
            QGVAR(g12),
            QGVAR(g13),
            QGVAR(g14),
            QGVAR(g14ba),
            QGVAR(g14bl),
            QGVAR(g14d)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_radios",
            "uksf_vehicles",
            "tbd_mortars_105mm_box",
            "tbd_mortars_105mm_box_dpicm",
            "tbd_mortars_105mm_box_laser",
            "tbd_mortars_105mm_box_smoke"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
