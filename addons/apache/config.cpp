#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_Apache_AH1"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "CUP_AirVehicles_AH64",
            "uksf_weapons",
            "Starstreak",
            "ATASK"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgMoves.hpp"
#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
