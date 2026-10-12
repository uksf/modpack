#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_compat_cup_vehicles",
            "ace_compat_cup_vehicles_fastroping",
            "ace_compat_cup_vehicles_refuel",
            "ace_compat_cup_vehicles_repair",
            "ace_compat_cup_vehicles_trenches",
            "CUP_AirVehciles_Cessna",
            "CUP_AirVehciles_KA60",
            "CUP_AirVehciles_MH47E",
            "CUP_AirVehciles_UH1Y",
            "CUP_AirVehicles_412",
            "CUP_AirVehicles_A10",
            "CUP_AirVehicles_AH6",
            "CUP_AirVehicles_AmbientPlanes",
            "CUP_AirVehicles_AN2",
            "CUP_AirVehicles_C130J",
            "CUP_AirVehicles_DC3",
            "CUP_AirVehicles_HC3",
            "CUP_AirVehicles_Ka52",
            "CUP_AirVehicles_L39",
            "CUP_AirVehicles_MH60S",
            "CUP_AirVehicles_MI6",
            "CUP_AirVehicles_Mi8",
            "CUP_AirVehicles_MV22",
            "CUP_AirVehicles_UH1H",
            "CUP_AirVehicles_UH60",
            "CUP_TrackedVehicles_2S6M",
            "CUP_TrackedVehicles_AAV",
            "CUP_TrackedVehicles_BMP",
            "CUP_TrackedVehicles_BMP3",
            "CUP_TrackedVehicles_Bradley",
            "CUP_TrackedVehicles_Bulldog",
            "CUP_TrackedVehicles_ChallengerII",
            "CUP_TrackedVehicles_FV510",
            "CUP_TrackedVehicles_LCAC",
            "CUP_TrackedVehicles_Leopard1",
            "CUP_TrackedVehicles_Leopard2",
            "CUP_TrackedVehicles_M1_Abrams",
            "CUP_TrackedVehicles_M113",
            "CUP_TrackedVehicles_M1A2Abrams",
            "CUP_TrackedVehicles_M1Abrams",
            "CUP_TrackedVehicles_M270",
            "CUP_TrackedVehicles_M60",
            "CUP_TrackedVehicles_MCV80",
            "CUP_TrackedVehicles_MTLB",
            "CUP_TrackedVehicles_NewM113",
            "CUP_TrackedVehicles_T34",
            "CUP_TrackedVehicles_T55",
            "CUP_TrackedVehicles_T72",
            "CUP_TrackedVehicles_T90",
            "CUP_TrackedVehicles_T90M",
            "CUP_TrackedVehicles_ZSU23",
            "CUP_WaterVehicles_Core",
            "CUP_WaterVehicles_Fishing_Boat",
            "CUP_WaterVehicles_Fregata",
            "CUP_WaterVehicles_LCU1600",
            "CUP_WaterVehicles_LCVP",
            "CUP_WaterVehicles_LHD",
            "CUP_WaterVehicles_MK10",
            "CUP_WaterVehicles_RHIB",
            "CUP_WaterVehicles_Seafox",
            "CUP_WaterVehicles_Zubr",
            "CUP_Wheeled_SUV",
            "CUP_WheeledVehicles_Boxer",
            "CUP_WheeledVehicles_BRDM2",
            "CUP_WheeledVehicles_BTR40",
            "CUP_WheeledVehicles_BTR60",
            "CUP_WheeledVehicles_BTR80",
            "CUP_WheeledVehicles_BTR90",
            "CUP_WheeledVehicles_Datsun",
            "CUP_WheeledVehicles_GAZTigr",
            "CUP_WheeledVehicles_Hilux",
            "CUP_WheeledVehicles_HMMWV",
            "CUP_WheeledVehicles_Jackal",
            "CUP_WheeledVehicles_LAV25",
            "CUP_WheeledVehicles_LR",
            "CUP_WheeledVehicles_M1151",
            "CUP_WheeledVehicles_M1240",
            "CUP_WheeledVehicles_M151",
            "CUP_WheeledVehicles_Mastiff",
            "CUP_WheeledVehicles_NewHMMWV",
            "CUP_WheeledVehicles_NewM1036",
            "CUP_WheeledVehicles_NewM1097",
            "CUP_WheeledVehicles_NewM998",
            "CUP_WheeledVehicles_NewSOV",
            "CUP_WheeledVehicles_RG31",
            "CUP_WheeledVehicles_Ridgeback",
            "CUP_WheeledVehicles_RM70",
            "CUP_WheeledVehicles_Strider",
            "CUP_WheeledVehicles_Stryker",
            "CUP_WheeledVehicles_T810",
            "CUP_WheeledVehicles_UAZ",
            "CUP_WheeledVehicles_UpHMMWV",
            "CUP_WheeledVehicles_Ural",
            "CUP_WheeledVehicles_Vodnik",
            "CUP_WheeledVehicles_Wolfhound",
            "uksf_air_patches",
            "uksf_air_weapons",
            "uksf_radios",
            "uksf_vehicles"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    #include "CfgVehicles_base.hpp"
    #include "CfgVehicles_land.hpp"
    #include "CfgVehicles_other_1.hpp"
    #include "CfgVehicles_other_2.hpp"
    #include "CfgVehicles_other_3.hpp"
    #include "CfgVehicles_other_4.hpp"
};
