class PROR_R : PROR_Soldier_Base {
    _generalMacro = "PROR_R";
    scope = 2;
    displayName = "Rifleman";
    editorSubcategory = "EdSubcat_Personnel";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_F.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    backpack = "";
    weapons[] = {
        "arifle_CTAR_blk_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_blk_F_optic_aco_grn",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "30Rnd_580x42_Mag_Tracer_F",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
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
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout2",
        "CFP_ANPVS15_Camo_V3",
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
        "CFP_ANPVS15_Camo_V3",
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
    _generalMacro = "PROR_AR";
    displayName = "Autorifleman";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_C.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    icon = "iconMan";
    backpack = "B_TacticalPack_blk";
    weapons[] = {
        "arifle_CTARS_blk_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTARS_blk_F",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_Scout",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_MG : PROR_R {
    _generalMacro = "PROR_MG";
    displayName = "Machinegunner";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_O.jpg);
    icon = "iconMan";
    uniformClass = "CFP_U_FieldUniform_M81light";
    backpack = "UK3CB_BAF_B_Carryall_Oli";
    weapons[] = {
        "MMG_02_black_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "MMG_02_black_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "130Rnd_338_Mag",
        "130Rnd_338_Mag",
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
        "130Rnd_338_Mag",
        "130Rnd_338_Mag",
        "SmokeShell",
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
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage"
    };
    linkedItems[] = {
        "CUP_V_B_RRV_Scout2",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CUP_V_B_RRV_Scout2",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Medic : PROR_R {
    _generalMacro = "PROR_Medic";
    displayName = "Medic";
    icon = "iconManMedic";
    attendant = 1;
    editorPreview = QPATHTOEF(common,data\previews\Inegal_MED.jpg);
    picture = "pictureHeal";
    uniformClass = "CFP_U_FieldUniform_M81light";
    backpack = "CUP_B_Kombat_Olive";

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
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_personalAidKit",
        "ACE_surgicalKit",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500"
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
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_quickclot",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_personalAidKit",
        "ACE_surgicalKit",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_Epinephrine",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_250",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500",
        "ACE_BloodIV_500"
    };
    linkedItems[] = {
        "CUP_V_B_RRV_Medic",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CUP_V_B_RRV_Medic",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_AT_L : PROR_R {
    _generalMacro = "PROR_AT_L";
    displayName = "AT (Light)";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_MG.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    icon = "iconManAT";
    backpack = "B_AssaultPack_rgr";
    weapons[] = {
        "launch_MRAWS_green_rail_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "launch_MRAWS_green_rail_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "MRAWS_HE_F",
        "MRAWS_HE_F",
        "MRAWS_HEAT_F"
    };
    respawnMagazines[] = {
        "MRAWS_HE_F",
        "MRAWS_HE_F",
        "MRAWS_HEAT_F"
    };
    linkedItems[] = {
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_AT_H : PROR_R {
    _generalMacro = "PROR_AT_H";
    displayName = "AT (Heavy)";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Mark.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    backpack = "B_TacticalPack_blk";
    weapons[] = {
        "launch_O_Vorona_green_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "launch_O_Vorona_green_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "Vorona_HEAT",
        "Vorona_HEAT"
    };
    respawnMagazines[] = {
        "Vorona_HEAT",
        "Vorona_HEAT"
    };
    linkedItems[] = {
        "CUP_V_B_RRV_Scout2",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CUP_V_B_RRV_Scout2",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Marksman : PROR_R {
    _generalMacro = "PROR_Marksman";
    displayName = "Marksman";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_AA.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    icon = "iconMan";
    weapons[] = {
        "srifle_DMR_06_olive_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "srifle_DMR_06_olive_F",
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
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Officer : PROR_R {
    _generalMacro = "PROR_Officer";
    displayName = "Officer";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_ATE.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    icon = "iconManOfficer";
    backpack = "CUP_B_Kombat_Olive";
    weapons[] = {
        "arifle_CTAR_GL_blk_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_GL_blk_F",
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
    _generalMacro = "PROR_SL";
    displayName = "Section Leader";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_ATJ.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    icon = "iconManLeader";
    linkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_TL"
    };
    respawnLinkedItems[] = {
        "CFP_Basic_Helmet_M81",
        "CUP_V_B_RRV_TL"
    };
};
class PROR_FOO : PROR_R {
    _generalMacro = "PROR_FOO";
    displayName = "Forward Observer";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Sniper.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    backpack = "UK3CB_BAF_B_Bergen_OLI_JTAC_A";
    weapons[] = {
        "arifle_CTAR_GL_blk_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_CTAR_GL_blk_F",
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
        "Laserdesignator_03",
        "CUP_V_B_RRV_Officer"
    };
    respawnLinkedItems[] = {
        "Laserdesignator_03",
        "CUP_V_B_RRV_Officer"
    };
};
class PROR_FAC : PROR_FOO {
    _generalMacro = "PROR_FAC";
    displayName = "FAC";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FAC.jpg);
    uniformClass = "CFP_U_FieldUniform_M81light";
    backpack = "UK3CB_BAF_B_Bergen_OLI_JTAC_H_A";
    linkedItems[] = {
        "CUP_V_B_RRV_TL"
    };
    respawnLinkedItems[] = {
        "CUP_V_B_RRV_TL"
    };
};
class PROR_Sniper : PROR_R {
    _generalMacro = "PROR_Sniper";
    displayName = "Sniper";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_FAC.jpg);
    uniformClass = "U_I_FullGhillie_lsh";
    backpack = "B_TacticalPack_blk";
    weapons[] = {
        "srifle_LRR_tna_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "srifle_LRR_tna_F",
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
        "Rangefinder"
    };
    respawnLinkedItems[] = {
        "CUP_PMC_Facewrap_Tropical",
        "CUP_NVG_PVS15_green",
        "Rangefinder"
    };
};
