#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_O_TK_INS_Suicide_Driver",
            "UKSF_O_TK_INS_Suicide",
            "UKSF_O_TK_INS_Suicide_Deadman",
            "UKSF_O_Skoda_Base",
            "UKSF_O_Skoda_CarBomb",
            "UKSF_O_Skoda_CarBomb_Deadman",
            "UKSF_O_Skoda_CarBomb_Empty",
            "UKSF_Target_Nopopup"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "Cfg3den.hpp"
#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
