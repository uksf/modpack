class GVAR(Rifleman_Woodland) : GVAR(Soldier_Base_Woodland) {
    scope = 2;
    displayName = "Rifleman";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_B_BDUv2_gloves_dirty_Tigerstripe", 1,
        "CUP_U_B_BDUv2_Tigerstripe", 1
    };
    weapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_black", "CUP_H_PASGTv2_NVG_tigerstripe", "CUP_Vest_RUS_6B45_Sh117_Green", "CUP_G_Scarf_Face_Grn" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_black", "CUP_H_PASGTv2_NVG_tigerstripe", "CUP_Vest_RUS_6B45_Sh117_Green", "CUP_G_Scarf_Face_Grn" };
    backpack = "";
};
class GVAR(Squad_Leader_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Squad Leader";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    weapons[] = { QGVAR(CUP_arifle_M4A1_BUIS_camo_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A1_BUIS_camo_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag" };
    backpack = QGVAR(Squad_Leader_pack_Woodland);
    icon = "iconManLeader";
};
class GVAR(Machine_Gunner_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Machine Gunner";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    weapons[] = { QGVAR(LMG_Zafir_F_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(LMG_Zafir_F_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    backpack = QGVAR(Machine_Gunner_pack_Woodland);
    icon = "iconManMG";
};
class GVAR(Rifleman_LAT_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Rifleman LAT";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    weapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"UK3CB_BAF_AT4_CS_AP_Launcher","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"UK3CB_BAF_AT4_CS_AP_Launcher","Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    icon = "iconManAT";
    uksf_equipment_randomSecondaryWeapons[] = {
        "UK3CB_BAF_AT4_CS_AP_Launcher", 0.33,
        "UK3CB_BAF_AT4_CS_AT_Launcher", 0.66
    };
};
class GVAR(Sharpshooter_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Sharpshooter";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    weapons[] = { QGVAR(CUP_srifle_M14_DMR_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_srifle_M14_DMR_CUP_optic_HensoldtZO_RDS),"Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag", "20Rnd_762x51_Mag" };
    backpack = "";
};
class GVAR(Armour_Crewman_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Armour Crewman";
    uniformClass = "UK3CB_BAF_U_CrewmanCoveralls_RTR";
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_black", "H_Tank_black_F", "CUP_V_B_BAF_DPM_Osprey_Mk3_Empty" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_black", "H_Tank_black_F", "CUP_V_B_BAF_DPM_Osprey_Mk3_Empty" };
    backpack = "";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Officer_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Officer";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_US_patrol_cap_tigerstripe", "CUP_Vest_RUS_6B45_Sh117_Green", "CUP_G_Scarf_Face_Grn" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_US_patrol_cap_tigerstripe", "CUP_Vest_RUS_6B45_Sh117_Green", "CUP_G_Scarf_Face_Grn" };
    backpack = "";
    icon = "iconManOfficer";
};
class GVAR(Signaller_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Signaller";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_black", "CUP_H_PASGTv2_NVG_tigerstripe", "CUP_Vest_RUS_6B45_Sh117_Green", "CUP_G_Scarf_Face_Grn" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_black", "CUP_H_PASGTv2_NVG_tigerstripe", "CUP_Vest_RUS_6B45_Sh117_Green", "CUP_G_Scarf_Face_Grn" };
    backpack = QGVAR(Signaller_pack_Woodland);
};
class GVAR(Heli_Pilot_Woodland) : GVAR(Armour_Crewman_Woodland) {
    displayName = "Heli Pilot";
    uniformClass = "UK3CB_BAF_U_CrewmanCoveralls_RTR";
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_CrewHelmetHeli_B", "CUP_V_B_BAF_DPM_Osprey_Mk3_Empty" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_CrewHelmetHeli_B", "CUP_V_B_BAF_DPM_Osprey_Mk3_Empty" };
    backpack = "";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Sniper_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Sniper";
    uniformClass = "U_I_FullGhillie_lsh";
    weapons[] = { QGVAR(CUP_srifle_G22_blk_ACE_optic_LRPS_2D),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_srifle_G22_blk_ACE_optic_LRPS_2D),"Put","Throw" };
    magazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22" };
    respawnMagazines[] = { "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22", "CUP_5Rnd_762x67_G22" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_Hide", "CUP_H_PASGTv2_NVG_tigerstripe", "UK3CB_BAF_V_PLCE_Webbing_Plate_OLI", "CUP_PMC_Facewrap_Tropical" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_PVS15_Hide", "CUP_H_PASGTv2_NVG_tigerstripe", "UK3CB_BAF_V_PLCE_Webbing_Plate_OLI", "CUP_PMC_Facewrap_Tropical" };
    backpack = "";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Crewman_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Crewman";
    EGVAR(equipment,skipRandomization) = 1;
};
class GVAR(Rifleman_AA_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Rifleman AA";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    weapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"CUP_launch_FIM92Stinger_Loaded","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"CUP_launch_FIM92Stinger_Loaded","Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "SmokeShell", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    backpack = "";
    icon = "iconManAT";
};
class GVAR(Rifleman_HAT_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Rifleman HAT";
    uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    weapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"launch_NLAW_F","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),"launch_NLAW_F","Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_30Rnd_556x45_Emag", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    icon = "iconManAT";
};
class GVAR(Operator_Woodland) : GVAR(Rifleman_Woodland) {
    displayName = "Operator";
    uniformClass = "CUP_U_CRYE_G3C_RGR";
    weapons[] = { QGVAR(CUP_arifle_HK_M27_VFG_CUP_optic_HensoldtZO_RDS_muzzle_snds_M),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_HK_M27_VFG_CUP_optic_HensoldtZO_RDS_muzzle_snds_M),"Put","Throw" };
    magazines[] = { "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_30Rnd_556x45_PMAG_QP", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_GPNVG_black", "CUP_H_OpsCore_Covered_Tigerstripe", "CUP_V_CPC_tlbelt_rngr", "G_Bandanna_Skull2" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_NVG_GPNVG_black", "CUP_H_OpsCore_Covered_Tigerstripe", "CUP_V_CPC_tlbelt_rngr", "G_Bandanna_Skull2" };
    backpack = QGVAR(Operator_Pack_Woodland);
    EGVAR(equipment,skipRandomization) = 1;
};
