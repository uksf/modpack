#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            // Vanilla
            "A3_Data_F_Tank_Loadorder",

            // CBA
            "cba_jr",
            "cba_main",
            "cba_ui",
            "cba_xeh",

            // ACE
            "ace_aircraft",
            "ace_arsenal",
            "ace_cargo",
            "ace_chemlights",
            "ace_common",
            "ace_dragging",
            "ace_hearing",
            "ace_hellfire",
            "ace_interaction",
            "ace_main",
            "ace_medical_treatment",
            "ace_rearm",
            "ace_refuel",
            "ace_zeus",

            // CUP
            "CUP_Creatures_Military_ACR",
            "CUP_Creatures_Military_BAF",
            "CUP_Creatures_Military_CDF",
            "CUP_Creatures_Military_Chedaki",
            "CUP_Creatures_Military_Germany",
            "CUP_Creatures_Military_NAPA",
            "CUP_Creatures_Military_PMC",
            "CUP_Creatures_Military_RACS",
            "CUP_Creatures_Military_Russia",
            "CUP_Creatures_Military_SLA",
            "CUP_Creatures_Military_Taki",
            "CUP_Creatures_Military_TakiInsurgents",
            "CUP_Creatures_Military_USArmy",
            "CUP_Creatures_Military_USMC",
            "CUP_Creatures_People_Civil_Chernarus",
            "CUP_Creatures_People_Civil_Russia",
            "CUP_Creatures_People_LoadOrder",
            "CUP_Creatures_People_Military_DummyInfantrySet",
            "CUP_Creatures_StaticWeapons",
            "CUP_TrackedVehicles_Bulldog",
            "CUP_TrackedVehicles_FV510",
            "CUP_TrackedVehicles_MCV80",
            "CUP_Vehicles_cfgGroups",
            "CUP_Vehicles_LoadOrder",
            "CUP_Weapons_AK",
            "CUP_Weapons_Ammunition",
            "CUP_Weapons_Curator",
            "CUP_Weapons_DynamicLoadout",
            "CUP_Weapons_LoadOrder",
            "CUP_Weapons_M16",
            "CUP_Weapons_M240",
            "CUP_Weapons_SMAW",
            "CUP_Weapons_Stinger",
            "CUP_Weapons_VehicleWeapons",
            "CUP_WheeledVehicles_Coyote",
            "CUP_WheeledVehicles_Jackal",
            "CUP_WheeledVehicles_LoadOrder",
            "CUP_WheeledVehicles_LR",
            "CUP_WheeledVehicles_Mastiff",
            "CUP_WheeledVehicles_Ridgeback",
            "CUP_WheeledVehicles_Skoda",
            "CUP_WheeledVehicles_Wolfhound",

            // 3CB
            "3CB_L135A1",
            "3CB_L7A2",
            "UK3CB_BAF_Equipment",
            "UK3CB_BAF_Equipment_ACRE_compatibility",
            "UK3CB_BAF_Vehicles_Coyote_Jackal",
            "UK3CB_BAF_Vehicles_Husky",
            "UK3CB_BAF_Vehicles_LandRover",
            "UK3CB_BAF_Vehicles_LoadOrder",
            "UK3CB_BAF_Vehicles_MAN",
            "UK3CB_BAF_Vehicles_Panther",
            "UK3CB_BAF_Vehicles_RHIB",
            "UK3CB_BAF_Vehicles_Warrior_a3",
            "UK3CB_BAF_Vehicles_Weapons",
            "UK3CB_BAF_Weapons",
            "UK3CB_BAF_Weapons_Accessories",
            "UK3CB_BAF_Weapons_ACE",
            "UK3CB_BAF_Weapons_Ammo",
            "UK3CB_BAF_Weapons_L110",
            "UK3CB_BAF_Weapons_L115",
            "UK3CB_BAF_Weapons_L119",
            "UK3CB_BAF_Weapons_L131a1",
            "UK3CB_BAF_Weapons_L1A1",
            "UK3CB_BAF_Weapons_Launchers",
            "UK3CB_BAF_Weapons_SmallArms",
            "UK3CB_BAF_Weapons_Static",

            // Other
            "3denEnhanced",
            "acre_sys_gsa",
            "acre_sys_prc117f",
            "acre_sys_radio",
            "ade_core",
            "Black_Config",
            "Blastcore_VEP",
            "diwako_dui_main",
            "DynaSound_DS_w_CoaxMG",
            "DynaSound_DS_w_GMG",
            "DynaSound_DS_w_HMG",
            "DynaSound_DS_w_LRR",
            "DynaSound_DS_w_MINIGUN762",
            "DynaSound_DS_w_Zafir",
            "JSRS_SOUNDMOD_Explosions",
            "lambs_danger",
            "mas_usa_lite_common",
            "RHICC",
            "rksla3_aircraft_tug",
            "RKSL_EOT552",
            "RKSL_LDS",
            "RKSL_PMII",
            "RKSL_PMII_525",
            "sps_ai_axmc_ace_compat",
            "SSQN_DMR_Pack",
            "SSQN_L119A1sPack",
            "SSQN_MachinegunsPack",
            "tfw_radios_acre_ilbe",
            "zen_compat_ace",
            "zen_context_menu",
            "zen_custom_modules",
            "zen_dialog",
            "zen_modules",
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};