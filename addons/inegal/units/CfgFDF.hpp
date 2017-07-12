class Inegal_FDF_S: Inegal_Soldier_Base {
    _generalMacro = "Inegal_FDF_S";
    scope = 2;
    displayName = "Specialist";
    editorSubcategory = QEGVAR(common,fdf);
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_S.jpg);
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_BG_Guerilla2_3";
    backpack = "";
    weapons[] = {
        "arifle_SPAR_01_blk_F_eotech_lamp_bipod",
        "UK3CB_BAF_L131A1",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_blk_F_eotech_lamp_bipod",
        "UK3CB_BAF_L131A1",
        "Throw",
        "Put"
    };
    magazines[] = {
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "UK3CB_BAF_9_17Rnd",
        "UK3CB_BAF_9_17Rnd",
        "UK3CB_BAF_9_17Rnd",
        "HandGrenade",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    respawnMagazines[] = {
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "UK3CB_BAF_9_17Rnd",
        "UK3CB_BAF_9_17Rnd",
        "UK3CB_BAF_9_17Rnd",
        "HandGrenade",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine"
    };
    linkedItems[] = {
        "H_Cap_grn",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Green",
        "G_Aviator",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_Cap_grn",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Green",
        "G_Aviator",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_FDF_V: Inegal_FDF_S {
    _generalMacro = "Inegal_FDF_V";
    displayName = "Veteran";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_V.jpg);
    icon = "iconManLeader";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_I_G_resistanceLeader_F";
    weapons[] = {
        "arifle_SPAR_01_GL_blk_F_eotech",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_GL_blk_F_eotech",
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
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellRed",
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
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "ACE_30Rnd_556x45_Stanag_Mk262_mag",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellRed",
        "HandGrenade"
    };
    linkedItems[] = {
        "H_Cap_blk_CMMG",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Black",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_Cap_blk_CMMG",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Black",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_FDF_B: Inegal_FDF_S {
    _generalMacro = "Inegal_FDF_B";
    displayName = "Brute";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_B.jpg);
    icon = "iconManMG";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_BG_Guerilla2_2";
    backpack = "Inegal_B_FDF_B";
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
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    respawnMagazines[] = {
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    linkedItems[] = {
        "H_HelmetSpecB",
        "V_PlateCarrierGL_blk",
        "NVGogglesB_blk_F",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetSpecB",
        "V_PlateCarrierGL_blk",
        "NVGogglesB_blk_F",
        "UK3CB_BAF_G_Tactical_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_FDF_Sh: Inegal_FDF_S {
    _generalMacro = "Inegal_FDF_Sh";
    displayName = "Sharpshooter";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_Sh.jpg);
    uniformClass = "U_C_HunterBody_grn";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    weapons[] = {
        "arifle_SPAR_03_blk_F_dms_bipod",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_03_blk_F_dms_bipod",
        "Throw",
        "Put"
    };
    magazines[] = {
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "HandGrenade",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    respawnMagazines[] = {
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "HandGrenade",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    linkedItems[] = {
        "H_Booniehat_khk_hs",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Tan",
        "UK3CB_BAF_G_Tactical_Clear",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_Booniehat_khk_hs",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Tan",
        "UK3CB_BAF_G_Tactical_Clear",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_FDF_A: Inegal_FDF_S {
    _generalMacro = "Inegal_ATE";
    displayName = "Arsonist";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_A.jpg);
    icon = "iconManAT";
    threat[] = { 1,0.9,0.9 };
    uniformClass = "U_Marshal";
    model = "\A3\Characters_F\Civil\c_poloshirtpants.p3d";
    backpack = "Inegal_B_FDF_A";
    weapons[] = {
        "arifle_SPAR_01_blk_F_eotech_lamp_bipod",
        "CUP_launch_MAAWS_Scope",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_blk_F_eotech_lamp_bipod",
        "CUP_launch_MAAWS_Scope",
        "Throw",
        "Put"
    };
    magazines[] = {
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "DemoCharge_Remote_Mag",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    respawnMagazines[] = {
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
        "DemoCharge_Remote_Mag",
        "HandGrenade",
        "SmokeShellBlue",
        "SmokeShellRed"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_DefusalKit",
        "ACE_Clacker"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_DefusalKit",
        "ACE_Clacker"
    };
    linkedItems[] = {
        "H_Cap_blk",
        "V_TacVestIR_blk",
        "SP_MouthScarf_White",
        "G_Spectacles",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_Cap_blk",
        "V_TacVestIR_blk",
        "SP_MouthScarf_White",
        "G_Spectacles",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_FDF_Se: Inegal_FDF_S {
    _generalMacro = "Inegal_FDF_Se";
    displayName = "Sentinel";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_Se.jpg);
    uniformClass = "U_I_C_Soldier_Bandit_3_F";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    weapons[] = {
        "arifle_SPAR_01_blk_F_eotech_lamp_bipod",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_blk_F_eotech_lamp_bipod",
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
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShell",
        "SmokeShell",
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
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "H_Cap_tan",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Black",
        "G_Squares_Tinted",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_Cap_tan",
        "V_TacVestIR_blk",
        "SP_MouthScarf_Black",
        "G_Squares_Tinted",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
