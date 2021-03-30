#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_B_L39",
            "UKSF_B_L39_Unarmed",
            "CUP_B_C130J_GB",
            "CUP_B_C130J_Cargo_GB",
            QGVAR(dauphin)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "uksf_units",
            "CUP_AirVehicles_AV8B",
            "CUP_AirVehciles_AW159",
            "CUP_AirVehicles_CH47",
            "CUP_AirVehicles_HC3",
            "CUP_AirVehicles_L39",
            "CUP_AirVehicles_Merlin",
            "CUP_AirVehicles_MV22",
            "CUP_AirVehciles_SA330",
            "CUP_AirVehciles_StaticLine",
            "UK3CB_BAF_Vehicles_Merlin",
            "UK3CB_BAF_Vehicles_Wildcat",
            "rksla3_pumahc",
            "rksla3_aw159",
            "MEA_Panther",
            "HAFM_EC635",
            QGVAR(prep)
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
    class UK3CB_BAF_Vehicles_Apache {
        name = "UK3CB_BAF_Vehicles_Apache";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {};
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class RscInGameUI {
    class RscUnitInfoAir;
    class RscUnitInfoNoSpeed : RscUnitInfoAir {
        controls[] = { "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_VehicleTogglesBackground", "CA_VehicleToggles", "CA_ValueFuel", "WeaponInfoControlsGroupRight" };
    };
    class RscUnitInfoAirPlane;
    class RscUnitInfoAirPlaneNoSpeed : RscUnitInfoAirPlane {
        controls[] = { "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_VehicleTogglesBackground", "CA_VehicleToggles", "CA_ValueFuel", "WeaponInfoControlsGroupRight", "CA_Throttle" };
    };
};
#include "CfgCloudlets.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
