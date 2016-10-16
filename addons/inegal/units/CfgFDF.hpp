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
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"UK3CB_BAF_9_17Rnd",
		"UK3CB_BAF_9_17Rnd",
		"UK3CB_BAF_9_17Rnd",
		"HandGrenade",
		"HandGrenade",
		"SmokeShellBlue",
		"SmokeShellRed"
	};
	respawnMagazines[] = {
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
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
	scope = 2;
	displayName = "Veteran";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_V.jpg);
	icon = "iconManLeader";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
	uniformClass = "U_I_G_resistanceLeader_F";
	backpack = "";
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
	scope = 2;
	displayName = "Brute";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_B.jpg);
	icon = "iconManMG";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
	uniformClass = "U_BG_Guerilla2_2";
	backpack = "Inegal_B_FDF_B";
	weapons[] = {
		"R3F_Minimi_762_Aimpoint",
		"Throw",
		"Put"
	};
	respawnWeapons[] = {
		"R3F_Minimi_762_Aimpoint",
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
	scope = 2;
	displayName = "Sharpshooter";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_Sh.jpg);
	uniformClass = "U_C_HunterBody_grn";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
	backpack = "";
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
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"HandGrenade",
		"HandGrenade",
		"SmokeShellBlue",
		"SmokeShellRed"
	};
	respawnMagazines[] = {
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
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
	scope = 2;
	displayName = "Arsonist";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_A.jpg);
	icon = "iconManAT";
	threat[] = { 1,0.9,0.9 };
	uniformClass = "U_Marshal";
	model = "\A3\Characters_F\Civil\c_poloshirtpants.p3d";
	backpack = "Inegal_B_FDF_A";
	weapons[] = {
		"arifle_SPAR_01_blk_F_eotech_lamp_bipod",
		"R3F_AT4CS",
		"Throw",
		"Put"
	};
	respawnWeapons[] = {
		"arifle_SPAR_01_blk_F_eotech_lamp_bipod",
		"R3F_AT4CS",
		"Throw",
		"Put"
	};
	magazines[] = {
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"DemoCharge_Remote_Mag",
		"HandGrenade",
		"SmokeShellBlue",
		"SmokeShellRed"
	};
	respawnMagazines[] = {
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
		"ACE_10Rnd_762x51_Mk316_Mod_0_Mag",
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
	scope = 2;
	displayName = "Sentinel";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_FDF_Se.jpg);
	uniformClass = "U_I_C_Soldier_Bandit_3_F";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
	backpack = "";
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
