#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_O_Rifleman",
            "UKSF_O_MG",
            "UKSF_O_AT",
            "UKSF_O_AA",
            "UKSF_O_HMMWV_M2_VR_Rubber",
            "UKSF_O_M1A2_TUSK_MG_VR_Rubber",
            "UKSF_O_M6LineBacker_VR_Rubber"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "CUP_WheeledVehicles_HMMWV",
            "CUP_TrackedVehicles_M1_Abrams",
            "CUP_TrackedVehicles_Bradley"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
