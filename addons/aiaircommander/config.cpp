#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(commanderModule),
            QGVAR(airspaceCentreModule),
            QGVAR(enemyAirfieldModule),
            QGVAR(planeSpawnModule),
            QGVAR(heliSpawnModule),
            QGVAR(aaSiteModule),
            QGVAR(aaSpawnModule)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {};
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

// #include "Cfg3den.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
