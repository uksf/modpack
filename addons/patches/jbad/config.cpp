#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "Jbad_Cat_Dumper",
            "Jbad_ConstructionCrane",
            "Jbad_Forklift",
            "Jbad_Ind_Garage01",
            "Jbad_Misc_Powerline"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers_base;

class CfgVehicles {
    #include "CfgVehicles.hpp"
};
