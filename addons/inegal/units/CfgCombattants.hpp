class Inegal_F: Inegal_Soldier_Base {
    scope = 2;
    displayName = "Fusilier";
    editorSubcategory = QEGVAR(common,combattants);
    editorPreview = QPATHTOEF(common,data\previews\Inegal_F.jpg);
    uniformClass = "U_BG_Guerilla2_3";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    backpack = "Inegal_B_F";
    weapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade"
    };
    respawnMagazines[] = {
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_tourniquet",
        "ACE_tourniquet"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_tourniquet",
        "ACE_tourniquet"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_C: Inegal_F {
    displayName = "Commander";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_C.jpg);
    uniformClass = "U_BG_Guerilla3_1";
    icon = "iconManLeader";
    backpack = "Inegal_B_C";
    weapons[] = {
        "CUP_arifle_Mk16_STD_EGLM_black",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_STD_EGLM_black",
        "Throw",
        "Put"
    };
};
class Inegal_O: Inegal_F {
    displayName = "Officer";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_O.jpg);
    icon = "iconManOfficer";
    uniformClass = "U_Marshal";
    model = "\A3\Characters_F\Civil\c_poloshirtpants.p3d";
    backpack = "";
    weapons[] = {
        "CUP_arifle_Mk16_CQC_EGLM_black_Aimpoint",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_CQC_EGLM_black_Aimpoint",
        "Throw",
        "Put"
    };
    magazines[] = {
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "HandGrenade",
        "HandGrenade"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Banana",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Banana",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage"
    };
    linkedItems[] = {
        "H_Cap_oli_hs",
        "V_TacVest_oli",
        "SP_MouthScarf_Green",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_Cap_oli_hs",
        "V_TacVest_oli",
        "SP_MouthScarf_Green",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_MED: Inegal_F {
    displayName = "Medic";
    icon = "iconManMedic";
    attendant = 1;
    editorPreview = QPATHTOEF(common,data\previews\Inegal_MED.jpg);
    picture = "pictureHeal";
    uniformClass = "U_BG_Guerilla2_1";
    backpack = "Inegal_B_Med";
    weapons[] = {
        "CUP_arifle_Mk16_STD_black_Aimpoint",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_STD_black_Aimpoint",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag"
    };
    respawnMagazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag"
    };
    items[] = {
        "ACE_EarPlugs"
    };
    respawnItems[] = {
        "ACE_EarPlugs"
    };
    linkedItems[] = {
        "H_HelmetB_Enh_tna_F",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_Enh_tna_F",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_MG: Inegal_F {
    displayName = "Machinegunner";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_MG.jpg);
    uniformClass = "U_BG_Guerilla2_2";
    icon = "iconManMG";
    backpack = "Inegal_B_MG";
    weapons[] = {
        "CUP_lmg_Mk48_des_Aimpoint",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_lmg_Mk48_des_Aimpoint",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade"
    };
    respawnMagazines[] = {
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "SP_MouthScarf_Green",
        "UK3CB_BAF_G_Tactical_Orange",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "SP_MouthScarf_Green",
        "UK3CB_BAF_G_Tactical_Orange",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Mark: Inegal_F {
    displayName = "Marksman";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Mark.jpg);
    uniformClass = "U_BG_Guerilla2_3";
    backpack = "Inegal_B_Mark";
    weapons[] = {
        "CUP_srifle_M110_Leupold",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_srifle_M110_Leupold",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade",
        "ACE_M84",
        "ACE_M84"
    };
    respawnMagazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade",
        "ACE_M84",
        "ACE_M84"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Clear",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Clear",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_AA: Inegal_F {
    displayName = "Anti-Air";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_AA.jpg);
    uniformClass = "U_BG_Guerilla3_1";
    icon = "iconManAT";
    threat[] = { 1,0.1,1 };
    weapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "CUP_launch_FIM92Stinger",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "CUP_launch_FIM92Stinger",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "G_Bandanna_aviator",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "G_Bandanna_aviator",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_ATE: Inegal_F {
    displayName = "Anti-Tank (AT13)";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_ATE.jpg);
    uniformClass = "U_BG_Guerilla2_1";
    icon = "iconManAT";
    threat[] = { 1,0.9,0.9 };
    backpack = "Inegal_B_AT_AT13";
    weapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "CUP_launch_Metis",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "CUP_launch_Metis",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Yellow",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Yellow",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_ATJ: Inegal_F {
    displayName = "Anti-Tank (Javelin)";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_ATJ.jpg);
    uniformClass = "U_BG_Guerilla2_3";
    icon = "iconManAT";
    threat[] = { 1,0.9,0.9 };
    weapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "UK3CB_BAF_Javelin_Launcher",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_STD_FG_black_Aimpoint",
        "UK3CB_BAF_Javelin_Launcher",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade",
        "Laserbatteries",
        "UK3CB_BAF_Javelin_Mag"
    };
    respawnMagazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "MiniGrenade",
        "MiniGrenade",
        "Laserbatteries",
        "UK3CB_BAF_Javelin_Mag"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Yellow",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Yellow",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Sniper: Inegal_F {
    displayName = "Sniper";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Sniper.jpg);
    uniformClass = "U_I_FullGhillie_sard";
    backpack = "Inegal_B_Sniper";
    weapons[] = {
        "srifle_DMR_02_F_PMII",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "srifle_DMR_02_F_PMII",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "SP_MouthScarf_Green",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "SP_MouthScarf_Green",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_FAC: Inegal_F {
    displayName = "FAC";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FAC.jpg);
    uniformClass = "U_BG_Guerilla2_2";
    backpack = "Inegal_B_FAC";
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Grey",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_PlateCarrier1_rgr_noflag_F",
        "NVGogglesB_grn_F",
        "UK3CB_BAF_G_Tactical_Grey",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
