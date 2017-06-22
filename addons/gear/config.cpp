#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_B_Bergen_Medic",
            "UKSF_B_Bergen_ATC",
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
            "Supply1000",
            "UKSF_S_Empty",
            "UKSF_S_Ammo",
            "UKSF_S_Medic",
            "UKSF_S_AmmoMedic",
            "UKSF_S_Radios",
            "UKSF_Target_Nopopup"
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
            "UKSF_V_Pilot",
            "ACE_NVG_Pilot",
            "UK3CB_BAF_L85A2_RIS_Elcan",
            "UK3CB_BAF_L22A2_Elcan",
            "UK3CB_BAF_L85A2_UGL_Elcan",
            "UK3CB_BAF_L110A3_Elcan",
            "UK3CB_BAF_L129A1_Grippod_Acog",
            "UK3CB_BAF_L115A3_LRPS",
            "UK3CB_BAF_L115A3_DE_LRPS",
            "UK3CB_BAF_L135A1_LRPS",
            "CUP_arifle_M4A1_Acog",
            "CUP_lmg_M240_LDS",
            "CUP_launch_Mk153Mod0_Rubber",
            "CUP_launch_FIM92Stinger_Rubber",
            "CUP_AGM114L_Hellfire_II_Launcher_W",
            "CUP_AGM114N_Hellfire_II_Launcher_W"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "UK3CB_BAF_Equipment",
            "UK3CB_BAF_Equipment_ACRE_compatibility",
            "UK3CB_BAF_Weapons",
            "UK3CB_BAF_Weapons_Ammo",
            "UK3CB_BAF_Weapons_L110",
            "UK3CB_BAF_Weapons_L115",
            "UK3CB_BAF_Weapons_L119",
            "UK3CB_BAF_Weapons_L1A1",
            "UK3CB_BAF_Weapons_Launchers",
            "UK3CB_BAF_Weapons_SmallArms",
            "UK3CB_BAF_Weapons_Static",
            "UK3CB_BAF_Weapons_Accessories",
            "UK3CB_BAF_Weapons_ACE",
            "CUP_Weapons_Stinger",
            "CUP_Weapons_Curator",
            "CUP_Weapons_Ammunition",
            "CUP_Weapons_VehicleWeapons",
            "CUP_Creatures_StaticWeapons",
            "CUP_Weapons_M16",
            "CUP_Weapons_SMAW",
            "CUP_Weapons_M240",
            "DynaSound_DS_w_30mmgatling",
            "DynaSound_DS_m_Explosions",
            "DynaSound_DS_w_MINIGUN762",
            "DynaSound_DS_w_HMG",
            "DynaSound_DS_w_GMG",
            "DynaSound_DS_w_CoaxMG",
            "DynaSound_DS_w_LRR",
            "DynaSound_DS_w_Zafir"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class cba_Extended_EventHandlers;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
#include "CfgAmmo.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
