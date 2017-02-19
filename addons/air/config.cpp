#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "CUP_B_Merlin_HC3_GB",
            "CUP_B_Merlin_HC3_VIV_GB",
            "CUP_B_Merlin_HC3_Armed_GB"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "uksf_gear",
            "CUP_AirVehicles_CH47",
            "CUP_AirVehicles_HC3",
            "CUP_AirVehicles_Merlin",
            "CUP_AirVehciles_AW159",
            "CUP_AirVehicles_C130J"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class RscInGameUI {
    class RscUnitInfo;
    class Rsc_UKSF_Air_Limited: RscUnitInfo {
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
