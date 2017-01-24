//Special Forces
class GENFOR_SF_R: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_R";
    scope = 2;
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_R.jpg);
    displayName = "Rifleman";
    editorSubcategory = QEGVAR(common,sf);
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_SF_R";
    weapons[] = {
        "arifle_mas_m4_acog",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_mas_m4_acog",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    respawnMagazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SF_A: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_A";
    scope = 2;
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_A.jpg);
    displayName = "Assault";
    editorSubcategory = QEGVAR(common,sf);
    uniformClass = "SP_0000_Standard_FieldUniform_Black";
    backpack = "GENFOR_B_SF_R";
    weapons[] = {
        "arifle_mas_m4c_holo",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_mas_m4c_holo",
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
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84"
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
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_ZSH1Helmet_Black2",
        "SP_Balaclava_Black",
        "SP_PlateCarrier1_Black",
        "SP_Kneepads_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_ZSH1Helmet_Black2",
        "SP_Balaclava_Black",
        "SP_PlateCarrier1_Black",
        "SP_Kneepads_Black",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SF_Patrol: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_Patrol";
    scope = 2;
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_Patrol.jpg);
    displayName = "Patrol";
    editorSubcategory = QEGVAR(common,sf);
    uniformClass = "SP_0000_Standard_FieldUniform_ATacsFG";
    backpack = "GENFOR_B_SF_P";
    weapons[] = {
        "rhs_weap_ak105_npz_acog",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak105_npz_acog",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84"
    };
    respawnMagazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_BoonieHat_ATacsFG",
        "G_Aviator",
        "SP_PlateCarrier1_ATacsFG",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_BoonieHat_ATacsFG",
        "G_Aviator",
        "SP_PlateCarrier1_ATacsFG",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SF_SL: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_SL";
    scope = 2;
    displayName = "Section Leader";
    editorSubcategory = QEGVAR(common,sf);
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_SL.jpg);
    icon = "iconManLeader";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_SF_R";
    weapons[] = {
        "arifle_mas_m4_gl_acog",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_mas_m4_gl_acog",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
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
        "1Rnd_Smoke_Grenade_shell",
        "1Rnd_Smoke_Grenade_shell",
        "1Rnd_SmokeRed_Grenade_shell",
        "1Rnd_SmokeRed_Grenade_shell",
        "1Rnd_SmokeGreen_Grenade_shell",
        "1Rnd_SmokeGreen_Grenade_shell",
        "1Rnd_SmokeYellow_Grenade_shell",
        "1Rnd_SmokeYellow_Grenade_shell",
        "1Rnd_SmokePurple_Grenade_shell",
        "1Rnd_SmokePurple_Grenade_shell",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    respawnMagazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
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
        "1Rnd_Smoke_Grenade_shell",
        "1Rnd_Smoke_Grenade_shell",
        "1Rnd_SmokeRed_Grenade_shell",
        "1Rnd_SmokeRed_Grenade_shell",
        "1Rnd_SmokeGreen_Grenade_shell",
        "1Rnd_SmokeGreen_Grenade_shell",
        "1Rnd_SmokeYellow_Grenade_shell",
        "1Rnd_SmokeYellow_Grenade_shell",
        "1Rnd_SmokePurple_Grenade_shell",
        "1Rnd_SmokePurple_Grenade_shell",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SF_MED: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_MED";
    scope = 2;
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_MED.jpg);
    displayName = "Medic";
    editorSubcategory = QEGVAR(common,sf);
    icon = "iconManMedic";
    picture = "pictureHeal";
    attendant = 1;
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_Med";
    weapons[] = {
        "arifle_mas_m4c_holo",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_mas_m4c_holo",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    respawnMagazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SF_MG: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_MG";
    scope = 2;
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_MG.jpg);
    displayName = "Machinegunner";
    editorSubcategory = QEGVAR(common,sf);
    icon = "iconManMG";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_SF_MG";
    weapons[] = {
        "LMG_Mk200_MRCO_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "LMG_Mk200_MRCO_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "200Rnd_65x39_cased_Box_Tracer",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black"
    };
    respawnMagazines[] = {
        "200Rnd_65x39_cased_Box_Tracer",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "V_TacVest_camo",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "V_TacVest_camo",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SF_Mark: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_Mark";
    scope = 2;
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_Mark.jpg);
    displayName = "Marksman";
    editorSubcategory = QEGVAR(common,sf);
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_SF_RNOMAG";
    weapons[] = {
        "srifle_DMR_06_camo_F_dms",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "srifle_DMR_06_camo_F_dms",
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
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    respawnMagazines[] = {
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "20Rnd_762x51_Mag",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SF_AT: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SF_AT";
    scope = 2;
    displayName = "AT Specialist";
    editorSubcategory = QEGVAR(common,sf);
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SF_AT.jpg);
    icon = "iconManAT";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_SF_AT";
    threat[] = { 1,0.9,0.9 };
    weapons[] = {
        "arifle_mas_m4_acog",
        "launch_RPG32_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_mas_m4_acog",
        "launch_RPG32_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    respawnMagazines[] = {
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "30Rnd_556x45_Stanag_Tracer_Green",
        "rhs_mag_rgd5",
        "rhs_mag_rgd5",
        "rhs_mag_rgn",
        "rhs_mag_rgn",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_white",
        "rhs_mag_rdg2_black",
        "rhs_mag_rdg2_black"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Morphine",
        "ACE_Morphine",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot",
        "ACE_quikClot"
    };
    linkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_MichHelmet_Green2",
        "SP_GasMask_Black",
        "SP_PlateCarrier1_Green",
        "SP_Kneepads_Green",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
