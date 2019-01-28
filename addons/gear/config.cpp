#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_B_Bergen_Medic",
            "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR",
            "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_MG",
            "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AA",
            "UK3CB_BAF_B_Bergen_MTP_Engineer_L_A_Toolkit",
            "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR",
            "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_MG",
            "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AA",
            "UKSF_B_Bergen_Medic_DPMW",
            "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_Toolkit",
            "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR",
            "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_MG",
            "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AA",
            "UKSF_B_Bergen_Medic_DDPM",
            "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_Toolkit",
            "B_AssaultPack_VR_AT",
            "B_AssaultPack_VR_AA",
            "UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base",
            "UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base",
            "UK3CB_BAF_Soldier_MTP_CSMR_LongSleeve_base",
            "UK3CB_BAF_Soldier_MTP_CSMR_ShortSleeve_base",
            "UK3CB_BAF_Soldier_MTP_Path_LongSleeve_base",
            "UK3CB_BAF_Soldier_MTP_Path_ShortSleeve_base",
            "UK3CB_BAF_Soldier_MTP_Sig_LongSleeve_base",
            "UK3CB_BAF_Soldier_MTP_Sig_ShortSleeve_base",
            "UK3CB_BAF_HeliPilot_RAF_base",
            "UKSF_B_ATC_base",
            "Supply1000"
        };
        weapons[] = {
            "UK3CB_BAF_U_CombatUniform_MTP_1Para",
            "UK3CB_BAF_U_CombatUniform_MTP_1Para_ShortSleeve",
            "UK3CB_BAF_U_CombatUniform_MTP_CSMR",
            "UK3CB_BAF_U_CombatUniform_MTP_CSMR_ShortSleeve",
            "UK3CB_BAF_U_CombatUniform_MTP_Path",
            "UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve",
            "UK3CB_BAF_U_CombatUniform_MTP_Sig",
            "UK3CB_BAF_U_CombatUniform_MTP_Sig_ShortSleeve",
            "UK3CB_BAF_U_HeliPilotCoveralls_RAF",
            "UKSF_U_PilotCoveralls_7",
            "UKSF_U_PilotUniform_656",
            "UKSF_U_PilotGSuit_617",
            "UKSF_U_RAF_Blues",
            "UKSF_H_RAFBeret",
            "UKSF_H_AACBeret",
            "UKSF_V_Pilot"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "C_Gen3_Characters"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
