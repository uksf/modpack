#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(aiGroundCommanderModule),
            QGVAR(infantryLocationsModule),
            QGVAR(carLocationsModule),
            QGVAR(apcLocationsModule),
            QGVAR(tankLocationsModule),
            QGVAR(stagingAreaModule)
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

#include "CfgEventHandlers.hpp"
#include "Cfg3den.hpp"
#include "CfgVehicles.hpp"
#include "CfgFactionClasses.hpp"