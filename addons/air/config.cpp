#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class RscInGameUI {
    class RscUnitInfo;
    class Rsc_UKSF_Air_Limited : RscUnitInfo {
        controls[] = {
            "WeaponInfoControlsGroupRight",
            "CA_TextFlaresMode",
            "CA_TextFlares",
            "CA_VehicleToggles",
            "CA_Radar"
        };
    };
};

#include "CfgVehicles.hpp"
