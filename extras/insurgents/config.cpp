class cfgPatches {
    class uksf_ni {
        units[] = { "uksf_ni_Team_Leader", "uksf_ni_Grenadier", "uksf_ni_Rifleman", "uksf_ni_Rifleman_AT", "uksf_ni_Machinegunner_HMG", "uksf_ni_Marksman", "uksf_ni_Officer", "uksf_ni_Machinegunner_LMG", "uksf_ni_Sniper", "uksf_ni_Armoured_Crewman", "uksf_ni_Crewman", "uksf_ni_Jeep_LMG", "uksf_ni_Offroad_AT", "uksf_ni_Hilux", "uksf_ni_Hilux_GMG", "uksf_ni_Transport_Van", "uksf_ni_MT_LB", "uksf_ni_Dshkm", "uksf_ni_Dshkm_Mini", "uksf_ni_AGS_30", "uksf_ni_SPG", "uksf_ni_Podnos", "uksf_ni_BRDM" };
        weapons[] = { "uksf_ni_CUP_arifle_Sa58V", "uksf_ni_CUP_arifle_Sa58RIS2_gl_desert", "uksf_ni_CUP_arifle_Sa58V_wood", "uksf_ni_CUP_arifle_Sa58_sporter_compact", "uksf_ni_launch_RPG7_F", "uksf_ni_CUP_lmg_PKM", "uksf_ni_CUP_srifle_SVD_CUP_optic_PSO_1", "uksf_ni_CUP_arifle_Sa58V_camo", "uksf_ni_CUP_arifle_RPK74", "uksf_ni_CUP_srifle_LeeEnfield_rail_CUP_optic_LeupoldMk4", "uksf_ni_CUP_smg_SA61" };
        requiredVersion = 0.1;
        requiredAddons[] = { "ace_medical_treatment", "A3_Weapons_F", "CUP_Weapons_Sa58", "A3_Characters_F_Exp", "CUP_Creatures_Military_SLA", "A3_Characters_F_Enoch_Headgear", "A3_Characters_F_Enoch", "CUP_Creatures_Military_Russia", "A3_Characters_F", "A3_Weapons_F_Items", "ace_hearing", "A3_Weapons_F_Exp_Launchers_RPG7", "CUP_Creatures_Military_Taki", "CUP_Weapons_PK", "CUP_Creatures_Military_NAPA", "CUP_Weapons_SVD", "CUP_Creatures_Military_TakiInsurgents", "CUP_Weapons_AK", "A3_Characters_F_Exp_Vests", "CUP_Weapons_LeeEnfield", "CUP_Weapons_SA61" };
    };
};

class cfgFactionClasses {
    class uksf_ni {
        icon = "";
        displayName = "Nziwasogo Insurgents";
        side = 2;
        priority = 1;
    };
};

class cfgWeapons {
    class CUP_arifle_Sa58V;
    class CUP_arifle_Sa58RIS2_gl_desert;
    class CUP_arifle_Sa58V_wood;
    class CUP_arifle_Sa58_sporter_compact;
    class launch_RPG7_F;
    class CUP_lmg_PKM;
    class CUP_srifle_SVD;
    class CUP_arifle_Sa58V_camo;
    class CUP_arifle_RPK74;
    class CUP_srifle_LeeEnfield_rail;
    class CUP_smg_SA61;

    class uksf_ni_CUP_arifle_Sa58V : CUP_arifle_Sa58V {
        displayName = "Sa vz. 58V";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_CUP_arifle_Sa58RIS2_gl_desert : CUP_arifle_Sa58RIS2_gl_desert {
        displayName = "Sa vz. 58V RIS G1 (Desert)";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_CUP_arifle_Sa58V_wood : CUP_arifle_Sa58V_wood {
        displayName = "Sa vz. 58V (Wood)";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_CUP_arifle_Sa58_sporter_compact : CUP_arifle_Sa58_sporter_compact {
        displayName = "Sa vz. 58 Sporter COMPACT";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_launch_RPG7_F : launch_RPG7_F {
        displayName = "RPG-7";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_CUP_lmg_PKM : CUP_lmg_PKM {
        displayName = "PKM";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_CUP_srifle_SVD_CUP_optic_PSO_1 : CUP_srifle_SVD {
        displayName = "SVD";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_PSO_1";
            };
        };
    };

    class uksf_ni_CUP_arifle_Sa58V_camo : CUP_arifle_Sa58V_camo {
        displayName = "Sa vz. 58V (Desert)";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_CUP_arifle_RPK74 : CUP_arifle_RPK74 {
        displayName = "RPK";
        scope = 1;
        class LinkedItems {
        };
    };

    class uksf_ni_CUP_srifle_LeeEnfield_rail_CUP_optic_LeupoldMk4 : CUP_srifle_LeeEnfield_rail {
        displayName = "No.4 Mk. I (RIS)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_LeupoldMk4";
            };
        };
    };

    class uksf_ni_CUP_smg_SA61 : CUP_smg_SA61 {
        displayName = "Sa vz. 61";
        scope = 1;
        class LinkedItems {
        };
    };
};

class cfgVehicles {
    class I_C_Soldier_Bandit_7_F;
    class CUP_B_RPGPack_Khaki;
    class B_FieldPack_green_F;
    class CUP_B_AlicePack_OD;
    class I_C_Offroad_02_LMG_F;
    class I_G_Offroad_01_AT_F;
    class CUP_I_Hilux_unarmed_IND_G_F;
    class CUP_I_Hilux_AGS30_IND_G_F;
    class I_G_Van_02_transport_F;
    class CUP_I_MTLB_pk_SYNDIKAT;
    class CUP_I_DSHKM_TK_GUE;
    class CUP_I_DSHkM_MiniTriPod_TK_GUE;
    class CUP_I_AGS_TK_GUE;
    class CUP_I_SPG9_TK_GUE;
    class CUP_I_2b14_82mm_TK_GUE;
    class CUP_I_BRDM2_HQ_NAPA;

    // men

    class I_C_Soldier_Bandit_4_F : I_C_Soldier_Bandit_7_F {
        uksf_equipment_randomUniforms[] = {
            "U_I_C_Soldier_Para_1_F", 1,
            "U_I_C_Soldier_Bandit_3_F", 1,
            "U_BG_Guerilla3_1", 1,
            "U_I_L_Uniform_01_deserter_F", 1
        };
    };

    class uksf_ni_Team_Leader : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Team Leader";
        uniformClass = "U_I_C_Soldier_Bandit_3_F";
        weapons[] = { "uksf_ni_CUP_arifle_Sa58V", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_arifle_Sa58V", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_mgrn", "CUP_V_O_SLA_M23_1_OD" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_mgrn", "CUP_V_O_SLA_M23_1_OD" };
        backpack = "";
    };

    class uksf_ni_Grenadier : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Grenadier";
        uniformClass = "U_I_L_Uniform_01_tshirt_olive_F";
        weapons[] = { "uksf_ni_CUP_arifle_Sa58RIS2_gl_desert", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_arifle_Sa58RIS2_gl_desert", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Bandanna_khk", "CUP_V_RUS_Smersh_New_Buttpack_Spectre" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Bandanna_khk", "CUP_V_RUS_Smersh_New_Buttpack_Spectre" };
        backpack = "";
    };

    class uksf_ni_Rifleman : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Rifleman";
        uniformClass = "U_I_C_Soldier_Para_3_F";
        weapons[] = { "uksf_ni_CUP_arifle_Sa58V_wood", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_arifle_Sa58V_wood", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacVest_oli" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacVest_oli" };
        backpack = "";
    };

    class uksf_ni_Rifleman_AT : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Rifleman AT";
        uniformClass = "CUP_U_O_TK_MixedCamo";
        weapons[] = { "uksf_ni_CUP_arifle_Sa58_sporter_compact", "uksf_ni_launch_RPG7_F", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_arifle_Sa58_sporter_compact", "uksf_ni_launch_RPG7_F", "Put", "Throw" };
        items[] = { "FirstAidKit", "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "FirstAidKit", "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "MiniGrenade", "MiniGrenade", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "SmokeShell", "SmokeShell", "SmokeShell", "RPG7_F", "RPG7_F", "RPG7_F", "RPG7_F" };
        respawnMagazines[] = { "MiniGrenade", "MiniGrenade", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "CUP_30Rnd_Sa58_M_TracerG", "SmokeShell", "SmokeShell", "SmokeShell", "RPG7_F", "RPG7_F", "RPG7_F", "RPG7_F" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_I_G_resistanceLeader_F" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_I_G_resistanceLeader_F" };
        backpack = "uksf_ni_Rifleman_AT_pack";
    };

    class uksf_ni_Machinegunner_HMG : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Machinegunner HMG";
        uniformClass = "U_I_L_Uniform_01_tshirt_black_F";
        weapons[] = { "uksf_ni_CUP_lmg_PKM", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_lmg_PKM", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M" };
        respawnMagazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M", "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_I_Guerilla_Jacket" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_I_Guerilla_Jacket" };
        backpack = "uksf_ni_Machinegunner_HMG_pack";
    };

    class uksf_ni_Marksman : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Marksman";
        uniformClass = "CUP_U_I_GUE_Woodland1";
        weapons[] = { "uksf_ni_CUP_srifle_SVD_CUP_optic_PSO_1", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_srifle_SVD_CUP_optic_PSO_1", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_SLA_Boonie", "V_TacVest_camo", "CUP_FR_NeckScarf" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_SLA_Boonie", "V_TacVest_camo", "CUP_FR_NeckScarf" };
        backpack = "";
    };

    class uksf_ni_Officer : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Officer";
        uniformClass = "U_I_C_Soldier_Para_3_F";
        weapons[] = { "uksf_ni_CUP_arifle_Sa58V_camo", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_arifle_Sa58V_camo", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        respawnMagazines[] = { "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_30Rnd_Sa58_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_oli", "CUP_V_OI_TKI_Jacket3_04", "G_Aviator" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_oli", "CUP_V_OI_TKI_Jacket3_04", "G_Aviator" };
        backpack = "";
    };

    class uksf_ni_Machinegunner_LMG : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Machinegunner LMG";
        uniformClass = "U_I_C_Soldier_Para_5_F";
        weapons[] = { "uksf_ni_CUP_arifle_RPK74", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_arifle_RPK74", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M" };
        respawnMagazines[] = { "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "SmokeShell", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M", "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacChestrig_grn_F", "CUP_FR_NeckScarf" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_Cap_oli", "V_TacChestrig_grn_F", "CUP_FR_NeckScarf" };
        backpack = "uksf_ni_Machinegunner_LMG_pack";
    };

    class uksf_ni_Sniper : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Sniper";
        uniformClass = "U_BG_Guerilla3_1";
        weapons[] = { "uksf_ni_CUP_srifle_LeeEnfield_rail_CUP_optic_LeupoldMk4", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_srifle_LeeEnfield_rail_CUP_optic_LeupoldMk4", "Put", "Throw" };
        items[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_EarPlugs", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
        respawnMagazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_RUS_Cap_EMR", "V_TacChestrig_grn_F" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_H_RUS_Cap_EMR", "V_TacChestrig_grn_F" };
        backpack = "";
    };

    class uksf_ni_Armoured_Crewman : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Armoured Crewman";
        uniformClass = "U_C_E_LooterJacket_01_F";
        weapons[] = { "uksf_ni_CUP_smg_SA61", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_smg_SA61", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "MiniGrenade", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        respawnMagazines[] = { "MiniGrenade", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_O_SLA_M23_1_OD" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_V_O_SLA_M23_1_OD" };
        backpack = "";
    };

    class uksf_ni_Crewman : I_C_Soldier_Bandit_4_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Crewman";
        uniformClass = "U_I_C_Soldier_Bandit_1_F";
        weapons[] = { "uksf_ni_CUP_smg_SA61", "Put", "Throw" };
        respawnWeapons[] = { "uksf_ni_CUP_smg_SA61", "Put", "Throw" };
        items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing", "ACE_fieldDressing" };
        magazines[] = { "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        respawnMagazines[] = { "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M", "CUP_20Rnd_B_765x17_Ball_M" };
        linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_TacChestrig_grn_F" };
        respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "V_TacChestrig_grn_F" };
        backpack = "";
    };

    //vehicles

    class uksf_ni_Jeep_LMG : I_C_Offroad_02_LMG_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Jeep LMG";
        hiddenSelectionsTextures[] = { "a3\soft_f_exp\offroad_02\data\offroad_02_ext_brown_co.paa", "a3\soft_f_exp\offroad_02\data\offroad_02_ext_brown_co.paa", "a3\soft_f_exp\offroad_02\data\offroad_02_int_brown_co.paa", "a3\soft_f_exp\offroad_02\data\offroad_02_int_brown_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_Offroad_AT : I_G_Offroad_01_AT_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Offroad AT";
        hiddenSelectionsTextures[] = { "a3\soft_f_bootcamp\offroad_01\data\offroad_01_ext_ig_01_co.paa", "a3\soft_f_bootcamp\offroad_01\data\offroad_01_ext_ig_01_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_Hilux : CUP_I_Hilux_unarmed_IND_G_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Hilux";
        hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\body_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\hilux_casemate_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_Hilux_GMG : CUP_I_Hilux_AGS30_IND_G_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Hilux GMG";
        hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\body_camo_2_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_hilux\data\v2\hilux_casemate_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_Transport_Van : I_G_Van_02_transport_F {
        faction = "uksf_ni";
        side = 2;
        displayName = "Transport Van";
        hiddenSelectionsTextures[] = { "a3\soft_f_orange\van_02\data\van_body_fia_02_co.paa", "a3\soft_f_orange\van_02\data\van_wheel_transport_co.paa", "a3\soft_f_orange\van_02\data\van_glass_transport_ca.paa", "a3\soft_f_orange\van_02\data\van_body_fia_02_co.paa" };
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_MT_LB : CUP_I_MTLB_pk_SYNDIKAT {
        faction = "uksf_ni";
        side = 2;
        displayName = "MT LB";
        hiddenSelectionsTextures[] = { "cup\trackedvehicles\cup_trackedvehicles_mtlb\data\textures\indep\body_new_syndikat_co.paa", "cup\trackedvehicles\cup_trackedvehicles_mtlb\data\textures\indep\pk_mod_new_syndikat_co.paa" };
        crew = "uksf_ni_Armoured_Crewman";
        typicalCargo[] = { "uksf_ni_Armoured_Crewman" };
    };

    class uksf_ni_Dshkm : CUP_I_DSHKM_TK_GUE {
        faction = "uksf_ni";
        side = 2;
        displayName = "Dshkm";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_Dshkm_Mini : CUP_I_DSHkM_MiniTriPod_TK_GUE {
        faction = "uksf_ni";
        side = 2;
        displayName = "Dshkm Mini";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_AGS_30 : CUP_I_AGS_TK_GUE {
        faction = "uksf_ni";
        side = 2;
        displayName = "AGS 30";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_SPG : CUP_I_SPG9_TK_GUE {
        faction = "uksf_ni";
        side = 2;
        displayName = "SPG";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_Podnos : CUP_I_2b14_82mm_TK_GUE {
        faction = "uksf_ni";
        side = 2;
        displayName = "Podnos";
        hiddenSelectionsTextures[] = {};
        crew = "uksf_ni_Rifleman";
        typicalCargo[] = { "uksf_ni_Rifleman" };
    };

    class uksf_ni_BRDM : CUP_I_BRDM2_HQ_NAPA {
        faction = "uksf_ni";
        side = 2;
        displayName = "BRDM";
        hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_brdm2\data\textures\sla_brdm2_01_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_brdm2\data\brdm2_02_co.paa" };
        crew = "uksf_ni_Crewman";
        typicalCargo[] = { "uksf_ni_Crewman" };
    };

    class uksf_ni_Rifleman_AT_pack : CUP_B_RPGPack_Khaki {
        scope = 1;
        class TransportMagazines {
            class _xx_RPG7_F {
                count = 4;
                magazine = "RPG7_F";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };

    class uksf_ni_Machinegunner_HMG_pack : B_FieldPack_green_F {
        scope = 1;
        class TransportMagazines {
            class _xx_CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M {
                count = 4;
                magazine = "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };

    class uksf_ni_Machinegunner_LMG_pack : CUP_B_AlicePack_OD {
        scope = 1;
        class TransportMagazines {
            class _xx_CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M {
                count = 6;
                magazine = "CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
};

//////////////// Paste cfgGroups after this line ////////////////
class cfgGroups {
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
            class Mechanized {
                name = "Mechanized";
            };
            class Armored {
                name = "Armored";
            };
            class SpecOps {
                name = "Special Forces";
            };
            class Support {
                name = "Support Infantry";
            };
            class Airborne {
                name = "Airborne";
            };
            class Air {
                name = "Air";
            };
        };
    };
};

// Regearing

class Extended_InitPost_EventHandlers {
    class uksf_ni_Rifleman {
        class ADDON {
            init = (_this select 0)addVest(selectRandom["V_Chestrig_rgr","V_TacVest_camo","V_TacChestrig_grn_F","CUP_V_OI_TKI_Jacket3_06"]);
        };
    };
    class uksf_ni_Team_Leader {
        class ADDON {
            init = (_this select 0)addVest(selectRandom["V_Chestrig_rgr","V_TacVest_camo","V_TacChestrig_grn_F","CUP_V_OI_TKI_Jacket3_06"]);
        };
    };
    class uksf_ni_Crewman {
        class ADDON {
            init = (_this select 0)addVest(selectRandom["V_Chestrig_rgr","V_TacVest_camo","V_TacChestrig_grn_F","CUP_V_OI_TKI_Jacket3_06"]);
        };
    };
};
