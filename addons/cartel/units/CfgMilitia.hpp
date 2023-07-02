// militia
class GVAR(militia_aksu) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (AKSU)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "arifle_AKS_F","Put","Throw" };
    respawnWeapons[] = { "arifle_AKS_F","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_FR_BandanaGreen", "CUP_V_PMC_CIRAS_OD_Empty", "G_Bandanna_oli" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_FR_BandanaGreen", "CUP_V_PMC_CIRAS_OD_Empty", "G_Bandanna_oli" };
    backpack = "";
};

class GVAR(militia_mac10_rshg) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (RSHG)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { QGVAR(Mac10_suppressed), "CUP_launch_RShG2", "Put","Throw" };
    respawnWeapons[] = { QGVAR(Mac10_suppressed), "CUP_launch_RShG2", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M" };
    respawnMagazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_OD_Empty", "G_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    backpack = "";
};

class GVAR(militia_mac10) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (Mac10)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { QGVAR(Mac10_suppressed), "Put","Throw" };
    respawnWeapons[] = { QGVAR(Mac10_suppressed), "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_OD_Empty", "G_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    backpack = "";
};

class GVAR(militia_aks74) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (AKS74)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_arifle_AKS74_Early","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AKS74_Early","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Cap_red", "CUP_V_PMC_CIRAS_Black_Empty", "CUP_G_Scarf_Face_Blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Cap_red", "CUP_V_PMC_CIRAS_Black_Empty", "CUP_G_Scarf_Face_Blk" };
    backpack = "";
};


class GVAR(militia_bizon) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (Bizon)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_smg_bizon","Put","Throw" };
    respawnWeapons[] = { "CUP_smg_bizon","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_64Rnd_9x19_Bizon_M", "CUP_64Rnd_9x19_Bizon_M" };
    respawnMagazines[] = { "CUP_64Rnd_9x19_Bizon_M", "CUP_64Rnd_9x19_Bizon_M", };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_O_TK_OfficerBelt", "G_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_O_TK_OfficerBelt", "G_Balaclava_blk" };
    backpack = "";
};


class GVAR(militia_enfield) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (Enfield)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { QGVAR(LeeEnfield_no32),"Put","Throw" };
    respawnWeapons[] = { QGVAR(LeeEnfield_no32),"Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M" };
    respawnMagazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_PMC_Cap_Burberry", "CUP_V_OI_TKI_Jacket3_03", "G_Bandanna_beast" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_PMC_Cap_Burberry", "CUP_V_OI_TKI_Jacket3_03", "G_Bandanna_beast" };
    backpack = "";
};


class GVAR(militia_vikhr) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (Vikhr)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_arifle_SR3M_Vikhr_VFG","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_SR3M_Vikhr_VFG","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M" };
    respawnMagazines[] = { "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M", "CUP_30Rnd_9x39_SP5_VIKHR_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_FR_BandanaGreen", "CUP_V_O_Ins_Carrier_Rig", "G_Bandanna_oli" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_FR_BandanaGreen", "CUP_V_O_Ins_Carrier_Rig", "G_Bandanna_oli" };
    backpack = "";
};


class GVAR(militia_mp5) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (MP5)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_smg_MP5A5","Put","Throw" };
    respawnWeapons[] = { "CUP_smg_MP5A5","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5" };
    respawnMagazines[] = { "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    backpack = "";
};


class GVAR(militia_galil) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (Galil 5.56)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_arifle_Galil_556_black","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_Galil_556_black","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag" };
    respawnMagazines[] = { "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag", "CUP_35Rnd_556x45_Galil_Mag" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_FR_BandanaGreen", "CUP_V_PMC_CIRAS_OD_Empty", "G_Bandanna_oli" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_FR_BandanaGreen", "CUP_V_PMC_CIRAS_OD_Empty", "G_Bandanna_oli" };
    backpack = "";
};


class GVAR(militia_rpk) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (RPK)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_arifle_RPK74_45","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_RPK74_45","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_PMC_Cap_Burberry", "CUP_V_O_TK_OfficerBelt", "G_Bandanna_beast" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_PMC_Cap_Burberry", "CUP_V_O_TK_OfficerBelt", "G_Bandanna_beast" };
    backpack = QGVAR(Autorifleman_pack);
};


class GVAR(militia_ak74_gl) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (AKS74GL)";
    uniformClass = "U_I_C_Soldier_Bandit_2_F";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_arifle_AKS74_GL_Early","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AKS74_GL_Early","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    backpack = QGVAR(GL_pack);
};


class GVAR(militia_aks) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (AKS)";
    uniformClass = "CUP_O_TKI_Khet_Jeans_04";
    uksf_equipment_randomUniforms[] = {
        "U_I_L_Uniform_01_tshirt_skull_F", 1,
        "CUP_I_B_PMC_Unit_11", 1,
        "U_C_E_LooterJacket_01_F", 1,
        "U_C_ArtTShirt_01_v4_F", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_arifle_AKS","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AKS","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Cap_red", "CUP_V_PMC_CIRAS_Black_Empty", "CUP_G_Scarf_Face_Blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Cap_red", "CUP_V_PMC_CIRAS_Black_Empty", "CUP_G_Scarf_Face_Blk" };
    backpack = QGVAR(Autorifleman_pack);
};
