#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_B_L39_CAP",
            "UKSF_B_L39_BMB",
            "USAF_F35A"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "uksf_units",
            "CUP_AirVehicles_AV8B",
            "CUP_AirVehciles_AW159",
            "CUP_AirVehicles_C130J",
            "CUP_AirVehicles_CH47",
            "CUP_AirVehicles_F35",
            "CUP_AirVehicles_HC3",
            "CUP_AirVehicles_L39",
            "CUP_AirVehicles_Merlin",
            "CUP_AirVehciles_SA330"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class RscInGameUI {
    class RscUnitInfoAir;
    class RscUnitInfoNoSpeed: RscUnitInfoAir {
        controls[] = { "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_VehicleTogglesBackground", "CA_VehicleToggles", "CA_ValueFuel", "WeaponInfoControlsGroupRight" };
    };
};
#include "CfgVehicles.hpp"
