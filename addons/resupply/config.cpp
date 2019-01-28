#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_S_Empty",
            "UKSF_S_Arsenal",
            "UKSF_S_R1",
            "UKSF_S_R2",
            "UKSF_S_R3",
            "UKSF_S_R4",
            "UKSF_S_R5",
            "UKSF_S_R6",
            "UKSF_S_RT",
            "UKSF_S_MedicalBox",
            "UKSF_S_Ammo",
            "UKSF_S_AmmoMedic",
            "UKSF_S_Medic"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "UK3CB_BAF_Equipment",
            "UK3CB_BAF_Weapons",
            "UK3CB_BAF_Weapons_Ammo",
            "UK3CB_BAF_Weapons_L110",
            "UK3CB_BAF_Weapons_L115",
            "UK3CB_BAF_Weapons_L119",
            "UK3CB_BAF_Weapons_L1A1",
            "UK3CB_BAF_Weapons_Launchers",
            "UK3CB_BAF_Weapons_SmallArms",
            "UK3CB_BAF_Weapons_Static",
            "UK3CB_BAF_Weapons_Accessories",
            "UK3CB_BAF_Weapons_ACE"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
