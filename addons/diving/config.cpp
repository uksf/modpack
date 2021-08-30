#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(bag),

            // Deprecated
            "ade_item_bag"
        };
        weapons[] = {
            QGVAR(goggles),
            QGVAR(rebreather),
            QGVAR(diveComputer),

            QGVAR(cylinderSingleEmpty),
            QGVAR(cylinderDoubleEmpty),
            QGVAR(cylinderSingleCompressedAir),
            QGVAR(cylinderDoubleCompressedAir),
            QGVAR(cylinderSingleEan28),
            QGVAR(cylinderDoubleEan28),
            QGVAR(cylinderSingleEan32),
            QGVAR(cylinderDoubleEan32),
            QGVAR(cylinderSingleEan36),
            QGVAR(cylinderDoubleEan36),
            QGVAR(cylinderSingleEan40),
            QGVAR(cylinderDoubleEan40),
            QGVAR(cylinderSingleHeliox85),
            QGVAR(cylinderDoubleHeliox85),
            QGVAR(cylinderSingleHeliox12),
            QGVAR(cylinderDoubleHeliox12),
            QGVAR(cylinderSingleHeliox21),
            QGVAR(cylinderDoubleHeliox21),
            QGVAR(cylinderSingleTx2135),
            QGVAR(cylinderDoubleTx2135),
            QGVAR(cylinderSingleTx1845),
            QGVAR(cylinderDoubleTx1845),
            QGVAR(cylinderSingleTx1555),
            QGVAR(cylinderDoubleTx1555),
            QGVAR(cylinderSingleTx1265),
            QGVAR(cylinderDoubleTx1265),
            QGVAR(cylinderDoubleTx1070),
            QGVAR(cylinderSingleTx1070),

            // Deprecated
            "ade_item_goggles"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "ade_core"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgRscTitles.hpp"
#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
