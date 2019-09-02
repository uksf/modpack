#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            // Units
            "PROR_R",
            "PROR_AR",
            "PROR_MG",
            "PROR_Medic",
            "PROR_AT_L",
            "PROR_AT_H",
            "PROR_Marksman",
            "PROR_Officer",
            "PROR_SL",
            "PROR_FOO",
            "PROR_FAC",
            "PROR_Sniper",
            "PROR_AA",
            "PROR_Para",
            "PROR_Para_SL",
            "PROR_Para_AR",
            "PROR_Para_Marks",
            "PROR_Para_AT",
            "PROR_SF_R",
            "PROR_SF_TL",
            "PROR_SF_Med",
            "PROR_SF_Marks",
            "PROR_SF_AR",
            "PROR_Crew",
            "PROR_Jet_Pilot",
            "PROR_Heli_Pilot",

            // Vehicles
            "PROR_MRAP_Unarmed",
            "PROR_MRAP_HMG",
            "PROR_MRAP_GMG",
            "PROR_Polaris_HMG",
            "PROR_Striker_GMG",
            "PROR_Striker_HMG",
            "PROR_LAV",
            "PROR_M60",
            "PROR_AA_Radar",
            "PROR_AA_Ozelot",
            "PROR_TRM_Covered",
            "PROR_TRM_Open",
            "PROR_TRM_Ammo",
            "PROR_TRM_Repair",
            "PROR_TRM_Fuel",
            "PROR_Jet_Harrier",
            "PROR_Heli_Huey",
            "PROR_Heli_Chinook",
            "PROR_Static_M119",
            "PROR_Static_HMG_High",
            "PROR_Static_HMG_Low",
            "PROR_Static_GMG_Low",
            "PROR_Static_GMG_High",
            "PROR_Static_AA",

            // Backpacks
            "PROR_B_MG_Carryall",
            "PROR_B_ATL_Carryall",
            "PROR_B_ATH_Carryall",
            "PROR_B_AA_Carryall",
            "PROR_B_SF_AssPack",
            "PROR_B_SF_TL_AssPack",
            "PROR_B_SF_Kitbag_AR",
            "PROR_B_SF_MedicBag"
        };
        weapons[] = {
            "arifle_CTAR_blk_F_aco_grn",
            "arifle_CTAR_GL_blk_F_aco_grn",
            "arifle_CTARS_blk_F_aimpoint",
            "srifle_DMR_06_olive_F_khssrifle_DMR_06_olive_F_khs",
            "mmg_02_black_f_sig_bravo4",
            "CUP_lmg_m249_SQuantoon_LDS",
            "srifle_LRR_tna_F_NXS",
            "CUP_arifle_mk18_black_acog",
            "CUP_arifle_mk18_m203_black_acog",
            "arifle_SPAR_03_blk_F_leupold"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
