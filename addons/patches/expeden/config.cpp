#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "Air_Globe_Heli_Light_01",
            "Air_Globe_UAV_02",
            "Armor_Globe_APC_Tracked_02",
            "cba_jr",
            "Props_Globe_Civilian_Camping",
            "Props_Globe_Humanitarian_Camps",
            "Props_Globe_Humanitarian_Supplies",
            "Props_Globe_Items_Electronics",
            "Props_Globe_Items_Tools",
            "Props_Globe_Particles",
            "Soft_Globe_LSV_01",
            "Soft_Globe_LSV_02",
            "Structures_Globe_Civilian_Constructions",
            "Structures_Globe_Industrial_PowerLines",
            "Structures_Globe_Industrial_Tanks",
            "Structures_Globe_Items_Airport",
            "Structures_Globe_Items_Sport",
            "Structures_Globe_Military_Fortifications",
            "Structures_Globe_Signs_City_Road",
            "Structures_Globe_Training_SkeetMachine",
            "Structures_Globe_Wreks",
            "Weapons_Globe_ACC"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers_base;

#include "CfgRoot.hpp"

class CfgVehicles {
    #include "CfgVehicles.hpp"
};
