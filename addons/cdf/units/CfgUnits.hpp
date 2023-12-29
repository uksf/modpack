//Units
class GVAR(Rifleman) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Rifleman";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_B_BDUv2_gloves_dirty_Winter", 1,
        "CUP_U_B_BDUv2_gloves_Winter", 1
    };
    weapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "CUP_H_PASGTv2_NVG_winter", "dr_ALPfacp_op", "CUP_G_Scarf_Face_White" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "CUP_H_PASGTv2_NVG_winter", "dr_ALPfacp_op", "CUP_G_Scarf_Face_White" };
    backpack = "";
};
class GVAR(Squad_Leader) : GVAR(Rifleman) {
    displayName = "Squad Leader";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    weapons[] = { QGVAR(CUP_arifle_M4A1_BUIS_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_BUIS_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag" };
    backpack = QGVAR(Squad_Leader_pack);
    icon = "iconManLeader";
};
class GVAR(Machine_Gunner) : GVAR(Rifleman) {
    displayName = "Machine Gunner";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    weapons[] = { QGVAR(LMG_Zafir_F_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(LMG_Zafir_F_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    backpack = QGVAR(Machine_Gunner_pack);
    icon = "iconManMG";
};
class GVAR(Rifleman_LAT) : GVAR(Rifleman) {
    displayName = "Rifleman LAT";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    weapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"UK3CB_BAF_AT4_CS_AP_Launcher","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"UK3CB_BAF_AT4_CS_AP_Launcher","Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    icon = "iconManAT";
};
class GVAR(Sharpshooter) : GVAR(Rifleman) {
    displayName = "Sharpshooter";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    weapons[] = { QGVAR(CUP_srifle_M14_DMR_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_srifle_M14_DMR_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag" };
    backpack = "";
};
class GVAR(Armour_Crewman) : GVAR(Rifleman) {
    displayName = "Armour Crewman";
    uniformClass = "UK3CB_BAF_U_CrewmanCoveralls_RTR";
    weapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS), "Put", "Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS), "Put", "Throw" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "H_Tank_black_F", "UK3CB_BAF_V_Osprey_Winter" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "H_Tank_black_F", "UK3CB_BAF_V_Osprey_Winter" };
    backpack = "";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Officer) : GVAR(Rifleman) {
    displayName = "Officer";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    linkedItems[] = { "ItemMap", "ItemCompass", "H_Watchcap_blk", "dr_ALPfacp_op", "CUP_FR_NeckScarf4" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_CZ_Patrol_Cap", "dr_ALPfacp_op", "CUP_FR_NeckScarf4" };
    backpack = "";
    icon = "iconManOfficer";
};
class GVAR(Signaller) : GVAR(Rifleman) {
    displayName = "Signaller";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "CUP_H_PASGTv2_NVG_winter", "dr_ALPfacp_op", "CUP_G_Scarf_Face_White" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "CUP_H_PASGTv2_NVG_winter", "dr_ALPfacp_op", "CUP_G_Scarf_Face_White" };
    backpack = QGVAR(Signaller_pack);
};
class GVAR(Heli_Pilot) : GVAR(Armour_Crewman) {
    displayName = "Heli Pilot";
    uniformClass = "UK3CB_BAF_U_CrewmanCoveralls_RTR";
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_CrewHelmetHeli_B", "UK3CB_BAF_V_Osprey_Winter" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_CrewHelmetHeli_B", "UK3CB_BAF_V_Osprey_Winter" };
    backpack = "";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Sniper) : GVAR(Rifleman) {
    displayName = "Sniper";
    uniformClass = "UK3CB_BAF_U_CombatUniform_Arctic_Ghillie_RM";
    weapons[] = { QGVAR(CUP_srifle_G22_blk_ACE_optic_LRPS_2D),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_srifle_G22_blk_ACE_optic_LRPS_2D),"Put","Throw" };
    magazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22" };
    respawnMagazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "CUP_H_PASGTv2_NVG_winter", "UK3CB_BAF_V_PLCE_Webbing_Plate_Winter", "CUP_G_Scarf_Face_White" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_winter_WP", "CUP_H_PASGTv2_NVG_winter", "UK3CB_BAF_V_PLCE_Webbing_Plate_Winter", "CUP_G_Scarf_Face_White" };
    backpack = "";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Crewman) : GVAR(Rifleman) {
    displayName = "Crewman";
    uniformClass = "CUP_U_B_BDUv2_gloves_dirty_Winter";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Jet_Pilot) : GVAR(Rifleman) {
    displayName = "Jet Pilot";
    uniformClass = "U_B_PilotCoveralls";
    weapons[] = { "CUP_hgun_CZ75", "Put", "Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS), "CUP_hgun_CZ75", "Put", "Throw" };
    magazines[] = { "SmokeShell", "SmokeShell", "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75" };
    respawnMagazines[] = { "SmokeShell", "SmokeShell", "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_PilotHelmetFighter_B" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_PilotHelmetFighter_B" };
    backpack = "B_Parachute";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Rifleman_AA) : GVAR(Rifleman) {
    displayName = "Rifleman AA";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    weapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"CUP_launch_FIM92Stinger_Loaded","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"CUP_launch_FIM92Stinger_Loaded","Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    backpack = "";
    icon = "iconManAT";
};
class GVAR(Rifleman_HAT) : GVAR(Rifleman) {
    displayName = "Rifleman HAT";
    uniformClass = "CUP_U_B_BDUv2_gloves_Winter";
    weapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"launch_NLAW_F","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"launch_NLAW_F","Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    icon = "iconManAT";
};
class GVAR(Operator) : GVAR(Rifleman) {
    displayName = "Operator";
    uniformClass = "Alpine_Crye_Camo";
    weapons[] = { QGVAR(CUP_arifle_HK_M27_VFG_CUP_optic_HensoldtZO_RDS_muzzle_snds_M),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_HK_M27_VFG_CUP_optic_HensoldtZO_RDS_muzzle_snds_M),"Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_GPNVG_black", "CUP_H_PASGTv2_NVG_winter", "dr_ALPpar_op", "G_Bandanna_Skull2" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_GPNVG_black", "CUP_H_PASGTv2_NVG_winter", "dr_ALPpar_op", "G_Bandanna_Skull2" };
    backpack = QGVAR(Operator_Pack);
    EGVAR(equipment,skipRandomization) = 1;
};
