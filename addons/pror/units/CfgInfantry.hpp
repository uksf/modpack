class PROR_R : PROR_Soldier_Base {
    scope = 2;
    displayName = "Rifleman";
    editorSubcategory = "EdSubcat_Personnel";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    backpack = "";
    weapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
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
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_tourniquet",
        "ACE_tourniquet"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_AR : PROR_R {
    displayName = "Autorifleman";
    editorPreview = QPATHTOEF(common,data\previews\PROR_AR.jpg);
    icon = "iconManMG";
    backpack = "B_TacticalPack_blk";
    weapons[] = {
        "arifle_CTARS_blk_F_aimpoint",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTARS_blk_F_aimpoint",
        "Throw",
        "Put"
    };
    magazines[] = {
        "100Rnd_580x42_Mag_Tracer_F",
        "100Rnd_580x42_Mag_Tracer_F",
        "100Rnd_580x42_Mag_F",
        "100Rnd_580x42_Mag_F",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "100Rnd_580x42_Mag_Tracer_F",
        "100Rnd_580x42_Mag_Tracer_F",
        "100Rnd_580x42_Mag_F",
        "100Rnd_580x42_Mag_F",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_MG : PROR_R {
    displayName = "Machinegunner";
    editorPreview = QPATHTOEF(common,data\previews\PROR_MG.jpg);
    icon = "iconManMG";
    backpack = "PROR_B_MG_Carryall";
    weapons[] = {
        "mmg_02_black_f_sig_bravo4",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "mmg_02_black_f_sig_bravo4",
        "Throw",
        "Put"
    };
    magazines[] = {
        "130Rnd_338_Mag",
        "130Rnd_338_Mag",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "130Rnd_338_Mag",
        "130Rnd_338_Mag",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Medic : PROR_R {
    displayName = "Medic";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Medic.jpg);
    icon = "iconManMedic";
    attendant = 1;
    picture = "pictureHeal";
    backpack = "CUP_B_Kombat_Olive";
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Medic",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Medic",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_AT_L : PROR_R {
    displayName = "AT (Light)";
    editorPreview = QPATHTOEF(common,data\previews\PROR_AT_L.jpg);
    icon = "iconManAT";
    backpack = "PROR_B_ATL_Carryall";
    weapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "launch_MRAWS_green_rail_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "launch_MRAWS_green_rail_F",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_AT_H : PROR_R {
    displayName = "AT (Heavy)";
    editorPreview = QPATHTOEF(common,data\previews\PROR_AT_H.jpg);
    icon = "iconManAT";
    backpack = "PROR_B_ATH_Carryall";
    weapons[] = {
        "launch_O_Vorona_green_F",
        "arifle_CTAR_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "launch_O_Vorona_green_F",
        "arifle_CTAR_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Marksman : PROR_R {
    displayName = "Marksman";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Marksman.jpg);
    weapons[] = {
        "srifle_DMR_06_olive_F_khs",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "srifle_DMR_06_olive_F_khs",
        "Throw",
        "Put"
    };
    magazines[] = {
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Officer : PROR_R {
    displayName = "Officer";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Officer.jpg);
    icon = "iconManOfficer";
    backpack = "CUP_B_Kombat_Olive";
    weapons[] = {
        "arifle_CTAR_GL_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_GL_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    magazines[] = {
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "CUP_V_B_RRV_Officer",
        "CUP_H_US_patrol_cap_WDL",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CUP_V_B_RRV_Officer",
        "CUP_H_US_patrol_cap_WDL",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_SL : PROR_Officer {
    displayName = "Section Leader";
    editorPreview = QPATHTOEF(common,data\previews\PROR_SL.jpg);
    icon = "iconManLeader";
    backpack = "CUP_B_Kombat_Radio_Olive";
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_TL",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_TL",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_FOO : PROR_R {
    displayName = "Forward Observer";
    editorPreview = QPATHTOEF(common,data\previews\PROR_FOO.jpg);
    backpack = "UK3CB_BAF_B_Bergen_OLI_JTAC_A";
    weapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "Throw",
        "Put"
    };
    magazines[] = {
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "1Rnd_HE_Grenade_shell",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_TL",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_TL",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_FAC : PROR_FOO {
    displayName = "FAC";
    editorPreview = QPATHTOEF(common,data\previews\PROR_FAC.jpg);
    backpack = "UK3CB_BAF_B_Bergen_OLI_JTAC_H_A";
};
class PROR_Sniper : PROR_R {
    displayName = "Sniper";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Sniper.jpg);
    uniformClass = "U_I_FullGhillie_lsh";
    backpack = "B_TacticalPack_blk";
    weapons[] = {
        "srifle_LRR_tna_F_NXS",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "srifle_LRR_tna_F_NXS",
        "Throw",
        "Put"
    };
    magazines[] = {
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "7Rnd_408_Mag",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "CUP_PMC_Facewrap_Tropical",
        "CUP_NVG_PVS15_green",
        "V_TacVest_oli",
        "Rangefinder"
    };
    respawnLinkedItems[] = {
        "CUP_PMC_Facewrap_Tropical",
        "CUP_NVG_PVS15_green",
        "V_TacVest_oli",
        "Rangefinder"
    };
};
class PROR_AA : PROR_R {
    displayName = "AA";
    editorPreview = QPATHTOEF(common,data\previews\PROR_AA.jpg);
    icon = "iconManAT";
    backpack = "PROR_B_AA_Carryall";
    weapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "launch_B_Titan_tna_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_blk_F_aco_grn",
        "launch_B_Titan_tna_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CUP_NVG_PVS15_black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
