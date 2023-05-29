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
    magazines[] = { "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "30Rnd_545x39_Mag_Green_F", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
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
    magazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
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
    magazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
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
    magazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
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
    magazines[] = { "CUP_64Rnd_9x19_Bizon_M", "CUP_64Rnd_9x19_Bizon_M", "CUP_64Rnd_9x19_Bizon_M" };
    respawnMagazines[] = { "CUP_64Rnd_9x19_Bizon_M", "CUP_64Rnd_9x19_Bizon_M", "CUP_64Rnd_9x19_Bizon_M" };
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


class GVAR(militia_ak74_gl) : GVAR(Soldier_Base) {
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
    magazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_PMC_Cap_Burberry", "CUP_V_O_TK_OfficerBelt", "G_Bandanna_beast" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_PMC_Cap_Burberry", "CUP_V_O_TK_OfficerBelt", "G_Bandanna_beast" };
    backpack = QGVAR(GL_pack);
};


class GVAR(militia_rpk) : GVAR(Soldier_Base) {
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
    magazines[] = { "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_PMC_CIRAS_Black_Empty", "G_Balaclava_blk" };
    backpack = QGVAR(Autorifleman_pack);
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


// armed civs
class GVAR(armed_civ_1911) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Armed Civ (1911)";
    uniformClass = "CUP_U_C_Citizen_03";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_C_Tracksuit_02", 1,
        "CUP_U_C_Tracksuit_04", 1,
        "U_BG_Guerilla3_1", 1,
        "U_C_HunterBody_grn", 1,
        "U_I_C_Soldier_Bandit_2_F", 1,
        "U_I_C_Soldier_Bandit_3_F", 1
    };
    weapons[] = { "CUP_hgun_Colt1911","Put","Throw" };
    respawnWeapons[] = { "CUP_hgun_Colt1911","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911" };
    respawnMagazines[] = { "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
};

class GVAR(armed_civ_cz75) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Armed Civ (Cz75)";
    uniformClass = "CUP_U_C_Citizen_03";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_C_Tracksuit_02", 1,
        "CUP_U_C_Tracksuit_04", 1,
        "U_BG_Guerilla3_1", 1,
        "U_C_HunterBody_grn", 1,
        "U_I_C_Soldier_Bandit_2_F", 1,
        "U_I_C_Soldier_Bandit_3_F", 1
    };
    weapons[] = { "CUP_hgun_CZ75","Put","Throw" };
    respawnWeapons[] = { "CUP_hgun_CZ75","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75" };
    respawnMagazines[] = { "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
};

class GVAR(armed_civ_cz550) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Armed Civ (Cz550)";
    uniformClass = "U_C_HunterBody_grn";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_C_Tracksuit_02", 1,
        "CUP_U_C_Tracksuit_04", 1,
        "U_BG_Guerilla3_1", 1,
        "U_C_HunterBody_grn", 1,
        "U_I_C_Soldier_Bandit_2_F", 1,
        "U_I_C_Soldier_Bandit_3_F", 1
    };
    weapons[] = { "CUP_srifle_CZ550","Put","Throw" };
    respawnWeapons[] = { "CUP_srifle_CZ550","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M" };
    respawnMagazines[] = { "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_C_MAGA_01", "", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_C_MAGA_01", "", "" };
};

// commandos
class GVAR(commando_g3a3) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (G3)";
    uniformClass = "CUP_I_B_PMC_Unit_13";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(G3A3_modern_ris_black_burris_anpeq_flash_hider), "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(G3A3_modern_ris_black_burris_anpeq_flash_hider), "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_20Rnd_762x51_G3", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Shemag_olive", "V_SmershVest_01_F", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Shemag_olive", "V_SmershVest_01_F", "" };
    backpack = "";
};

class GVAR(commando_mp5_bunkerfaust) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (AT)";
    uniformClass = "CUP_I_B_PMC_Unit_20";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(MP5A5_t1), "CUP_launch_BF3", "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(MP5A5_t1), "CUP_launch_BF3", "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_30Rnd_9x19_MP5", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_CarrierRigKBT_01_light_Olive_F", "G_Bandanna_oli" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_CarrierRigKBT_01_light_Olive_F", "G_Bandanna_oli" };
    icon = "iconManAT";
};

class GVAR(commando_g36_gl) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (SL)";
    uniformClass = "CUP_I_B_PMC_Unit_42";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(G36A3_AG36_t1_laser), "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(G36A3_AG36_t1_laser), "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_30Rnd_556x45_G36", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_CarrierRigKBT_01_light_Olive_F", "CUP_RUS_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_CarrierRigKBT_01_light_Olive_F", "CUP_RUS_Balaclava_blk" };
    backpack = "";
    icon = "iconManLeader";
};

class GVAR(commando_hk416) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (HK416)";
    uniformClass = "CUP_I_B_PMC_Unit_24";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(HK416_CQB_Black_t1_laser), "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(HK416_CQB_Black_t1_laser), "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_MilCap_grn", "V_CarrierRigKBT_01_light_Olive_F", "G_Bandanna_oli" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_MilCap_grn", "V_CarrierRigKBT_01_light_Olive_F", "G_Bandanna_oli" };
};

class GVAR(commando_hk416_drum) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (AR)";
    uniformClass = "CUP_I_B_PMC_Unit_11";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(HK416_Black_barska_laser), "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(HK416_Black_barska_laser), "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "V_SmershVest_01_F", "CUP_RUS_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "V_SmershVest_01_F", "CUP_RUS_Balaclava_blk" };
    backpack = "";
    icon = "IconManMG";
};

class GVAR(commando_vintorez) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (VSS)";
    uniformClass = "CUP_I_B_PMC_Unit_13";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(VSSVintorez_VFG_pso1_laser), "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(VSSVintorez_VFG_pso1_laser), "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_20Rnd_9x39_SP5_VSS_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Shemag_olive", "V_SmershVest_01_F", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Shemag_olive", "V_SmershVest_01_F", "" };
    backpack = "";
};

class GVAR(commando_ak74_rpg) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (RPG)";
    uniformClass = "CUP_I_B_PMC_Unit_20";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { "CUP_arifle_AK74M", "CUP_launch_RPG7V", "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AK74M", "CUP_launch_RPG7V", "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_CarrierRigKBT_01_light_Olive_F", "G_Bandanna_oli" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_CarrierRigKBT_01_light_Olive_F", "G_Bandanna_oli" };
    backpack = QGVAR(LAT_pack);
    icon = "IconManAT";
};

class GVAR(commando_saiga) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (Saiga)";
    uniformClass = "CUP_I_B_PMC_Unit_42";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(saiga9_1p87), "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(saiga9_1p87), "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_10Rnd_9x19_Saiga9", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_SmershVest_01_radio_F", "CUP_RUS_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_Booniehat_mgrn", "V_SmershVest_01_radio_F", "CUP_RUS_Balaclava_blk" };
    backpack = "";
};

class GVAR(commando_ak74) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (AK74)";
    uniformClass = "CUP_I_B_PMC_Unit_24";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { "CUP_arifle_AK74M", "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AK74M", "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_MilCap_grn", "V_SmershVest_01_radio_F", "G_Bandanna_oli" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_MilCap_grn", "V_SmershVest_01_radio_F", "G_Bandanna_oli" };
    backpack = "";
};

class GVAR(commando_rpk) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Commando (RPK)";
    uniformClass = "CUP_I_B_PMC_Unit_11";
    // uksf_equipment_randomUniforms[] = {
    //     "U_I_L_Uniform_01_tshirt_skull_F", 1,
    //     "CUP_I_B_PMC_Unit_11", 1,
    //     "U_C_E_LooterJacket_01_F", 1,
    //     "U_C_ArtTShirt_01_v4_F", 1,
    //     "CUP_O_TKI_Khet_Jeans_04", 1

    // };
    weapons[] = { QGVAR(RPK74M_1p63_laser), "CUP_hgun_M9", "Put","Throw" };
    respawnWeapons[] = { QGVAR(RPK74M_1p63_laser), "CUP_hgun_M9", "Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "V_SmershVest_01_radio_F", "CUP_RUS_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "V_SmershVest_01_radio_F", "CUP_RUS_Balaclava_blk" };
    backpack = "";
    icon = "IconManMG";
};

// couriers
class GVAR(courier_mac10) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Courier (Mac10)";
    uniformClass = "U_C_E_LooterJacket_01_F";
    // uksf_equipment_randomUniforms[] = {
    //     "CUP_U_C_Tracksuit_02", 1,
    //     "CUP_U_C_Tracksuit_04", 1,
    //     "U_BG_Guerilla3_1", 1,
    //     "U_C_HunterBody_grn", 1,
    //     "U_I_C_Soldier_Bandit_2_F", 1,
    //     "U_I_C_Soldier_Bandit_3_F", 1
    // };
    weapons[] = { "CUP_smg_Mac10", "Put", "Throw" };
    respawnWeapons[] = { "CUP_smg_Mac10", "Put", "Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M" };
    respawnMagazines[] = { "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M", "CUP_30Rnd_45ACP_MAC10_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_RacingHelmet_3_F", "CUP_V_CDF_OfficerBelt", "CUP_RUS_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_RacingHelmet_3_F", "CUP_V_CDF_OfficerBelt", "CUP_RUS_Balaclava_blk" };
    backpack = "B_Messenger_Black_F";
};

class GVAR(courier_tec9) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Courier (Tec9)";
    uniformClass = "U_C_E_LooterJacket_01_F";
    // uksf_equipment_randomUniforms[] = {
    //     "CUP_U_C_Tracksuit_02", 1,
    //     "CUP_U_C_Tracksuit_04", 1,
    //     "U_BG_Guerilla3_1", 1,
    //     "U_C_HunterBody_grn", 1,
    //     "U_I_C_Soldier_Bandit_2_F", 1,
    //     "U_I_C_Soldier_Bandit_3_F", 1
    // };
    weapons[] = { "CUP_hgun_TEC9_FA", "Put", "Throw" };
    respawnWeapons[] = { "CUP_hgun_TEC9_FA", "Put", "Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_32Rnd_9x19_TEC9", "CUP_32Rnd_9x19_TEC9", "CUP_32Rnd_9x19_TEC9" };
    respawnMagazines[] = { "CUP_32Rnd_9x19_TEC9", "CUP_32Rnd_9x19_TEC9", "CUP_32Rnd_9x19_TEC9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "H_RacingHelmet_1_black_F", "CUP_V_CDF_OfficerBelt", "CUP_RUS_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_RacingHelmet_1_black_F", "CUP_V_CDF_OfficerBelt", "CUP_RUS_Balaclava_blk" };
    backpack = "B_Messenger_Black_F";
};
