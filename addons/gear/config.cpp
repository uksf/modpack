#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_B_Medic",
			"UKSF_B_Radio",
			"UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base",
			"UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base",
			"UK3CB_BAF_Soldier_MTP_CSMR_LongSleeve_base",
			"UK3CB_BAF_Soldier_MTP_CSMR_ShortSleeve_base",
			"UK3CB_BAF_Soldier_MTP_Path_LongSleeve_base",
			"UK3CB_BAF_Soldier_MTP_Path_ShortSleeve_base",
			"UK3CB_BAF_Soldier_MTP_Sig_LongSleeve_base",
			"UK3CB_BAF_Soldier_MTP_Sig_ShortSleeve_base",
            "UK3CB_BAF_HeliPilot_RAF_base",
			"UKSF_Soldier_ATC_base",
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
			"UKSF_U_ATC",
            "UKSF_H_RAFBeret",
            "UKSF_H_AACBeret",
            "UKSF_V_Pilot",
            "UKSF_V_Flight"
			"ACE_NVG_Pilot"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main", 
            "uksf_common",
            "UK3CB_BAF_Weapons",
            "UK3CB_BAF_Weapons_Accessories",
            "UK3CB_BAF_Equipment",
            "RKSL_LDS"
        };
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"