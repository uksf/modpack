#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "uksf_ni_Rifleman",
            "uksf_ni_Team_Leader",
            "uksf_ni_Grenadier",
            "uksf_ni_Rifleman_AT",
            "uksf_ni_Machinegunner_HMG",
            "uksf_ni_Marksman",
            "uksf_ni_Officer",
            "uksf_ni_Machinegunner_LMG",
            "uksf_ni_Sniper",
            "uksf_ni_Armoured_Crewman",
            "uksf_ni_Crewman",

            "uksf_ni_Jeep_LMG",
            "uksf_ni_Offroad_AT",
            "uksf_ni_Hilux",
            "uksf_ni_Hilux_GMG",
            "uksf_ni_Transport_Van",
            "uksf_ni_MT_LB",
            "uksf_ni_Dshkm",
            "uksf_ni_Dshkm_Mini",
            "uksf_ni_AGS_30",
            "uksf_ni_SPG",
            "uksf_ni_Podnos",
            "uksf_ni_BRDM"
        };
        weapons[] = {
            "uksf_ni_CUP_srifle_LeeEnfield_rail_LeupoldMk4"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_common",
            "ace_medical_treatment",
            "ace_hearing",
            "CUP_Weapons_LoadOrder",
            "CUP_Creatures_People_LoadOrder"
        };
        author = QUOTE(UKSF);
        authors[] = { "Downey.R", "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgFactionClasses {
    class uksf_ni {
        icon = "";
        displayName = "N'Ziwasogo Insurgents";
        side = 2;
        priority = 1;
    };
};

class CfgWeapons {
    class CUP_srifle_LeeEnfield_rail;
    class uksf_ni_CUP_srifle_LeeEnfield_rail_LeupoldMk4 : CUP_srifle_LeeEnfield_rail {
        displayName = "No.4 Mk.I (RIS)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_LeupoldMk4";
            };
        };
    };
};

class CfgVehicles {
    // Men
    class I_C_Soldier_Bandit_4_F;
    class uksf_ni_base : I_C_Soldier_Bandit_4_F {
        scope = 1;
        scopeCurator = 1;
        side = 2;
        faction = "uksf_ni";
        editorSubcategory = "EdSubcat_Personnel";
        displayName = "Soldier";
        icon = "iconMan";
        uniformClass = "U_I_C_Soldier_Bandit_3_F";
        backpack = "";
        weapons[] = { "CUP_arifle_Sa58V", "Put", "Throw" };
        respawnWeapons[] = { "CUP_arifle_Sa58V", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_mgrn", "CUP_V_O_SLA_M23_1_OD" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_mgrn", "CUP_V_O_SLA_M23_1_OD" };
        EGVAR(equipment,randomUniforms)[] = {
            "U_I_C_Soldier_Para_1_F", 1,
            "U_I_C_Soldier_Para_3_F", 1,
            "U_I_C_Soldier_Para_5_F", 1,
            "U_I_C_Soldier_Bandit_3_F", 1,
            "U_I_L_Uniform_01_deserter_F", 1,
            "U_I_L_Uniform_01_tshirt_olive_F", 1,
            "U_I_L_Uniform_01_tshirt_black_F", 1,
            "U_I_C_Soldier_Bandit_1_F", 1,
            "CUP_U_O_TK_MixedCamo", 1
        };
    };

    class uksf_ni_Rifleman : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Rifleman";
        uniformClass = "U_I_C_Soldier_Para_3_F";
        backpack = "";
        weapons[] = { "CUP_arifle_Sa58V_wood", "Put", "Throw" };
        respawnWeapons[] = { "CUP_arifle_Sa58V_wood", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacVest_oli" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacVest_oli" };
        EGVAR(equipment,randomVests)[] = {
            "V_Chestrig_rgr", 1,
            "V_TacVest_camo", 1,
            "V_TacChestrig_grn_F", 1,
            "CUP_V_OI_TKI_Jacket3_06", 1
        };
    };

    class uksf_ni_Team_Leader : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Team Leader";
        icon = "iconManLeader";
        backpack = "";
        weapons[] = { "CUP_arifle_Sa58V", "Put", "Throw" };
        respawnWeapons[] = { "CUP_arifle_Sa58V", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_mgrn", "CUP_V_O_SLA_M23_1_OD" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_mgrn", "CUP_V_O_SLA_M23_1_OD" };
        EGVAR(equipment,randomVests)[] = {
            "V_Chestrig_rgr", 1,
            "V_TacVest_camo", 1,
            "V_TacChestrig_grn_F", 1,
            "CUP_V_OI_TKI_Jacket3_06", 1
        };
    };

    class uksf_ni_Grenadier : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Grenadier";
        uniformClass = "U_I_L_Uniform_01_tshirt_olive_F";
        backpack = "";
        weapons[] = { "CUP_arifle_Sa58RIS2_gl_desert", "Put", "Throw" };
        respawnWeapons[] = { "CUP_arifle_Sa58RIS2_gl_desert", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Bandanna_khk", "CUP_V_RUS_Smersh_New_Buttpack_Spectre" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Bandanna_khk", "CUP_V_RUS_Smersh_New_Buttpack_Spectre" };
    };

    class uksf_ni_Rifleman_AT : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Rifleman AT";
        icon = "iconManAT";
        uniformClass = "CUP_U_O_TK_MixedCamo";
        backpack = "uksf_ni_Rifleman_AT_pack";
        weapons[] = { "CUP_arifle_Sa58_sporter_compact", "launch_RPG7_F", "Put", "Throw" };
        respawnWeapons[] = { "CUP_arifle_Sa58_sporter_compact", "launch_RPG7_F", "Put", "Throw" };
        items[] = { "FirstAidKit", "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "FirstAidKit", "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "MiniGrenade", "MiniGrenade", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "MiniGrenade", "MiniGrenade", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_I_G_resistanceLeader_F" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_I_G_resistanceLeader_F" };
    };

    class uksf_ni_Machinegunner_HMG : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Machinegunner HMG";
        icon = "iconManMG";
        uniformClass = "U_I_L_Uniform_01_tshirt_black_F";
        backpack = "uksf_ni_Machinegunner_HMG_pack";
        weapons[] = { "CUP_lmg_PKM", "Put", "Throw" };
        respawnWeapons[] = { "CUP_lmg_PKM", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
        respawnMagazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_I_Guerilla_Jacket" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_I_Guerilla_Jacket" };
    };

    class uksf_ni_Machinegunner_LMG : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Machinegunner LMG";
        icon = "iconManMG";
        uniformClass = "U_I_C_Soldier_Para_5_F";
        backpack = "uksf_ni_Machinegunner_LMG_pack";
        weapons[] = { "CUP_arifle_RPK74", "Put", "Throw" };
        respawnWeapons[] = { "CUP_arifle_RPK74", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacChestrig_grn_F", "CUP_FR_NeckScarf" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacChestrig_grn_F", "CUP_FR_NeckScarf" };
    };

    class uksf_ni_Marksman : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Marksman";
        uniformClass = "CUP_U_I_GUE_Woodland1";
        backpack = "";
        weapons[] = { "CUP_srifle_SVD_pso", "Put", "Throw" };
        respawnWeapons[] = { "CUP_srifle_SVD_pso", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_SLA_Boonie", "V_TacVest_camo", "CUP_FR_NeckScarf" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_SLA_Boonie", "V_TacVest_camo", "CUP_FR_NeckScarf" };
    };

    class uksf_ni_Officer : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Officer";
        icon = "iconManOfficer";
        uniformClass = "U_I_C_Soldier_Para_3_F";
        backpack = "";
        weapons[] = { "CUP_arifle_Sa58V_camo", "Put", "Throw" };
        respawnWeapons[] = { "CUP_arifle_Sa58V_camo", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_oli", "CUP_V_OI_TKI_Jacket3_04", "G_Aviator" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_oli", "CUP_V_OI_TKI_Jacket3_04", "G_Aviator" };
        EGVAR(equipment,skipRandomization) = 1;
    };

    class uksf_ni_Sniper : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Sniper";
        uniformClass = "U_BG_Guerilla3_1";
        backpack = "";
        weapons[] = { "uksf_ni_CUP_srifle_LeeEnfield_rail_LeupoldMk4", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_srifle_LeeEnfield_rail_LeupoldMk4", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
        respawnMagazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_RUS_Cap_EMR", "V_TacChestrig_grn_F" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_RUS_Cap_EMR", "V_TacChestrig_grn_F" };
        EGVAR(equipment,skipRandomization) = 1;
    };

    class uksf_ni_Crewman : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Crewman";
        uniformClass = "U_I_C_Soldier_Bandit_1_F";
        backpack = "";
        weapons[] = { "CUP_smg_SA61", "Put", "Throw" };
        respawnWeapons[] = { "CUP_smg_SA61", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        respawnMagazines[] = { "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_TacChestrig_grn_F" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_TacChestrig_grn_F" };
        EGVAR(equipment,randomVests)[] = {
            "V_Chestrig_rgr", 1,
            "V_TacVest_camo", 1,
            "V_TacChestrig_grn_F", 1,
            "CUP_V_OI_TKI_Jacket3_06", 1
        };
    };

    class uksf_ni_Armoured_Crewman : uksf_ni_base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Armoured Crewman";
        icon = "iconManEngineer";
        uniformClass = "U_C_E_LooterJacket_01_F";
        backpack = "";
        weapons[] = { "CUP_smg_SA61", "Put", "Throw" };
        respawnWeapons[] = { "CUP_smg_SA61", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "MiniGrenade", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        respawnMagazines[] = { "MiniGrenade", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_O_SLA_M23_1_OD" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_O_SLA_M23_1_OD" };
        EGVAR(equipment,skipRandomization) = 1;
    };

    // Vehicles
    class I_C_Offroad_02_LMG_F;
    class uksf_ni_Jeep_LMG : I_C_Offroad_02_LMG_F {
        side = 2;
        faction = "uksf_ni";
        displayName = "Jeep LMG";
        hiddenSelectionsTextures[] = { "a3\soft_f_exp\offroad_02\data\offroad_02_ext_brown_co.paa", "a3\soft_f_exp\offroad_02\data\offroad_02_ext_brown_co.paa", "a3\soft_f_exp\offroad_02\data\offroad_02_int_brown_co.paa", "a3\soft_f_exp\offroad_02\data\offroad_02_int_brown_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class I_G_Offroad_01_AT_F;
    class uksf_ni_Offroad_AT : I_G_Offroad_01_AT_F {
        side = 2;
        faction = "uksf_ni";
        displayName = "Offroad AT";
        hiddenSelectionsTextures[] = { "a3\soft_f_bootcamp\offroad_01\data\offroad_01_ext_ig_01_co.paa", "a3\soft_f_bootcamp\offroad_01\data\offroad_01_ext_ig_01_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_Hilux_unarmed_IND_G_F;
    class uksf_ni_Hilux : CUP_I_Hilux_unarmed_IND_G_F {
        side = 2;
        faction = "uksf_ni";
        displayName = "Hilux";
        hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\body_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\hilux_casemate_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_Hilux_AGS30_IND_G_F;
    class uksf_ni_Hilux_GMG : CUP_I_Hilux_AGS30_IND_G_F {
        side = 2;
        faction = "uksf_ni";
        displayName = "Hilux GMG";
        hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\body_camo_2_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\hilux_casemate_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class I_G_Van_02_transport_F;
    class uksf_ni_Transport_Van : I_G_Van_02_transport_F {
        side = 2;
        faction = "uksf_ni";
        displayName = "Transport Van";
        hiddenSelectionsTextures[] = { "a3\soft_f_orange\van_02\data\van_body_fia_02_co.paa", "a3\soft_f_orange\van_02\data\van_wheel_transport_co.paa", "a3\soft_f_orange\van_02\data\van_glass_transport_ca.paa", "a3\soft_f_orange\van_02\data\van_body_fia_02_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_MTLB_pk_SYNDIKAT;
    class uksf_ni_MT_LB : CUP_I_MTLB_pk_SYNDIKAT {
        side = 2;
        faction = "uksf_ni";
        displayName = "MT LB";
        hiddenSelectionsTextures[] = { "cup\trackedvehicles\cup_trackedvehicles_mtlb\data\textures\indep\body_new_syndikat_co.paa", "cup\trackedvehicles\cup_trackedvehicles_mtlb\data\textures\indep\pk_mod_new_syndikat_co.paa" };
        crew = "uksf_ni_Armoured_Crewman";
        typicalCargo[] = { "uksf_ni_Armoured_Crewman" };
    };

    class CUP_I_DSHKM_TK_GUE;
    class uksf_ni_Dshkm : CUP_I_DSHKM_TK_GUE {
        side = 2;
        faction = "uksf_ni";
        displayName = "Dshkm";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_DSHkM_MiniTriPod_TK_GUE;
    class uksf_ni_Dshkm_Mini : CUP_I_DSHkM_MiniTriPod_TK_GUE {
        side = 2;
        faction = "uksf_ni";
        displayName = "Dshkm Mini";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_AGS_TK_GUE;
    class uksf_ni_AGS_30 : CUP_I_AGS_TK_GUE {
        side = 2;
        faction = "uksf_ni";
        displayName = "AGS 30";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_SPG9_TK_GUE;
    class uksf_ni_SPG : CUP_I_SPG9_TK_GUE {
        side = 2;
        faction = "uksf_ni";
        displayName = "SPG";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_2b14_82mm_TK_GUE;
    class uksf_ni_Podnos : CUP_I_2b14_82mm_TK_GUE {
        side = 2;
        faction = "uksf_ni";
        displayName = "Podnos";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class CUP_I_BRDM2_HQ_NAPA;
    class uksf_ni_BRDM : CUP_I_BRDM2_HQ_NAPA {
        side = 2;
        faction = "uksf_ni";
        displayName = "BRDM";
        hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_brdm2\data\textures\sla_brdm2_01_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_brdm2\data\brdm2_02_co.paa" };
        crew = "uksf_ni_Crewman";
        typicalCargo[] = { "uksf_ni_Crewman" };
    };

    // Backpacks
    class CUP_B_RPGPack_Khaki;
    class uksf_ni_Rifleman_AT_pack : CUP_B_RPGPack_Khaki {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(RPG7_F,4);
        };
    };

    class B_FieldPack_green_F;
    class uksf_ni_Machinegunner_HMG_pack : B_FieldPack_green_F {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M,4);
        };
    };

    class CUP_B_AlicePack_OD;
    class uksf_ni_Machinegunner_LMG_pack : CUP_B_AlicePack_OD {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M,6);
        };
    };
};

class CfgGroups {
    class INDEP {
        name = "Independent";
        class Nziwasogo_Insurgents {
            name = "Nziwasogo Insurgents";
            class Infantry {
                name = "Infantry";
                class uksf_R_Weapon_Team {
                    name = "Weapon Team";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Team_Leader";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman_AT";
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = "uksf_ni_Grenadier";
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = "uksf_ni_Machinegunner_LMG";
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = "uksf_ni_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                };
                class uksf_R_AT_Team {
                    name = "AT Team";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Team_Leader";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman_AT";
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman_AT";
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class uksf_R_Patrol {
                    name = "Patrol";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Team_Leader";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Grenadier";
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                };
                class uksf_R_Sniper_Team {
                    name = "Sniper Team";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Sniper";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                };
                class uksf_R_MG_Team {
                    name = "MG Team";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Team_Leader";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Machinegunner_HMG";
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = "uksf_ni_Machinegunner_LMG";
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class uksf_R_Infantry_Team {
                    name = "Infantry Team";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Team_Leader";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = "uksf_ni_Grenadier";
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman_AT";
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = "uksf_ni_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                };
            };
            class Motorized {
                name = "Motorized";
                class uksf_R_Raiding_Van {
                    name = "Raiding Van";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Transport_Van";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Team_Leader";
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = "uksf_ni_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = "uksf_ni_Machinegunner_HMG";
                        rank = "PRIVATE";
                        position[] = { 0, -60, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = "uksf_ni_Grenadier";
                        rank = "PRIVATE";
                        position[] = { 0, -75, 0 };
                    };
                };
                class uksf_R_Jeep_Team {
                    name = "Jeep Team";
                    faction = "uksf_ni";
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = "uksf_ni_Jeep_LMG";
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = "uksf_ni_Jeep_LMG";
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
            // class Mechanized {
            //     name = "Mechanized";
            // };
            // class Armored {
            //     name = "Armored";
            // };
            // class SpecOps {
            //     name = "Special Forces";
            // };
            // class Support {
            //     name = "Support Infantry";
            // };
            // class Airborne {
            //     name = "Airborne";
            // };
            // class Air {
            //     name = "Air";
            // };
        };
    };
};
