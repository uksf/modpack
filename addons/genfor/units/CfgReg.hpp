//Normal
class GENFOR_R: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_R";
    scope = 2;
    displayName = "Rifleman";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_R.jpg);
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_R";
    weapons[] = {
        "rhs_weap_ak74m_pkas",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_pkas",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
        "rhs_30Rnd_545x39_AK_green",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
        "rhs_30Rnd_545x39_AK_green",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_S: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_S";
    scope = 2;
    displayName = "Scout";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_S.jpg);
    uniformClass = "SP_0000_Standard_TacticalUniform_Hunter2_TS";
    backpack = "GENFOR_B_RNOMAG";
    weapons[] = {
        "rhs_weap_ak74m_folded",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_folded",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_BandollierB_oli",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_BandollierB_oli",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_SL: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_SL";
    scope = 2;
    displayName = "Section Leader";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_SL.jpg);
    icon = "iconManLeader";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_Sl";
    weapons[] = {
        "rhs_weap_ak74m_gp25_pkas",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_gp25_pkas",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
        "rhs_VOG25",
        "rhs_VOG25",
        "rhs_VOG25",
        "rhs_VOG25",
        "rhs_VOG25",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
        "rhs_VOG25",
        "rhs_VOG25",
        "rhs_VOG25",
        "rhs_VOG25",
        "rhs_VOG25",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_O: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_O";
    scope = 2;
    displayName = "Officer";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_O.jpg);
    icon = "iconManOfficer";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2_SS";
    backpack = "";
    weapons[] = {
        "rhs_weap_ak74m_1p63",
        "hgun_Pistol_heavy_02_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_1p63",
        "hgun_Pistol_heavy_02_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "6Rnd_45ACP_Cylinder",
        "6Rnd_45ACP_Cylinder",
        "6Rnd_45ACP_Cylinder",
        "6Rnd_45ACP_Cylinder",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "6Rnd_45ACP_Cylinder",
        "6Rnd_45ACP_Cylinder",
        "6Rnd_45ACP_Cylinder",
        "6Rnd_45ACP_Cylinder",
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
        "SP_Beret_Black",
        "G_Shades_Black",
        "V_TacVest_camo",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_Beret_Black",
        "G_Shades_Black",
        "V_TacVest_camo",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_MED: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_MED";
    scope = 2;
    displayName = "Medic";
    icon = "iconManMedic";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_MED.jpg);
    picture = "pictureHeal";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_Med";
    attendant = 1;
    weapons[] = {
        "rhs_weap_ak74m_pkas",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_pkas",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_AR: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_AR";
    scope = 2;
    displayName = "Auto Rifleman";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_AR.jpg);
    icon = "iconManMG";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_MG";
    weapons[] = {
        "rhs_weap_pkm",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_pkm",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_100Rnd_762x54mmR_green",
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
        "rhs_100Rnd_762x54mmR_green",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_MG: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_MG";
    scope = 2;
    displayName = "Machinegunner";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_MG.jpg);
    icon = "iconManMG";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_MG";
    weapons[] = {
        "rhs_weap_pkp_pkas",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_pkp_pkas",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_100Rnd_762x54mmR_green",
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
        "rhs_100Rnd_762x54mmR_green",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_Mark: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_Mark";
    scope = 2;
    displayName = "Marksman";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_Mark.jpg);
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_Mark";
    weapons[] = {
        "rhs_weap_ak103_pso",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak103_pso",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
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
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
        "rhs_30Rnd_762x39mm_tracer",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_AA: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_AA";
    scope = 2;
    displayName = "AA Specialist";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_AA.jpg);
    icon = "iconManAT";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_AA";
    weapons[] = {
        "rhs_weap_ak74m_pkas",
        "rhs_weap_igla",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_pkas",
        "rhs_weap_igla",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_AT_18: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_AT_18";
    scope = 2;
    displayName = "AT (RPG18)";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_AT_18.jpg);
    icon = "iconManAT";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_R";
    threat[] = { 1,0.9,0.9 };
    weapons[] = {
        "rhs_weap_ak74m_pkas",
        "rhs_weap_rpg18",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_pkas",
        "rhs_weap_rpg18",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_rpg18_mag",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_rpg18_mag",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_AT_7: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_AT_7";
    scope = 2;
    displayName = "AT (RPG7)";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_AT_7.jpg);
    icon = "iconManAT";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_AT7";
    threat[] = { 1,0.9,0.9 };
    weapons[] = {
        "rhs_weap_ak74m_pkas",
        "rhs_weap_rpg7",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_pkas",
        "rhs_weap_rpg7",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_AT: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_AT";
    scope = 2;
    displayName = "AT (Titan)";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_AT.jpg);
    icon = "iconManAT";
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_AT";
    threat[] = { 1,0.9,0.9 };
    weapons[] = {
        "rhs_weap_ak74m_pkas",
        "launch_O_Titan_short_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_pkas",
        "launch_O_Titan_short_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_Sniper: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_Sniper";
    scope = 2;
    displayName = "Sniper";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_Sniper.jpg);
    uniformClass = "U_O_FullGhillie_sard";
    backpack = "GENFOR_B_RNOMAG";
    weapons[] = {
        "rhs_weap_svdp_pso1",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_svdp_pso1",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
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
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
        "rhs_10Rnd_762x54mmR_7N1",
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
        "SP_GhillieHat_Tropical",
        "SP_Balaclava_ATacsFG",
        "V_HarnessO_brn",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_GhillieHat_Tropical",
        "SP_Balaclava_ATacsFG",
        "V_HarnessO_brn",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_Sniper_AM: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_Sniper_AM";
    scope = 2;
    displayName = "Sniper Anti-Materiel";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_Sniper_AM.jpg);
    uniformClass = "U_O_FullGhillie_sard";
    backpack = "GENFOR_B_RNOMAG";
    weapons[] = {
        "srifle_GM6_LRPS_F",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "srifle_GM6_LRPS_F",
        "Throw",
        "Put"
    };
    magazines[] = {
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
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
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
        "5Rnd_127x108_Mag",
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
        "SP_GhillieHat_Tropical",
        "SP_Balaclava_ATacsFG",
        "V_HarnessO_brn",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_GhillieHat_Tropical",
        "SP_Balaclava_ATacsFG",
        "V_HarnessO_brn",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_Spotter: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_Spotter";
    scope = 2;
    displayName = "Spotter";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_Spotter.jpg);
    uniformClass = "U_O_FullGhillie_sard";
    backpack = "GENFOR_B_R";
    weapons[] = {
        "rhs_weap_ak74m_1p63",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_1p63",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
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
        "SP_GhillieHat_Tropical",
        "SP_Balaclava_ATacsFG",
        "V_TacVest_camo",
        "rhs_pdu4",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_GhillieHat_Tropical",
        "SP_Balaclava_ATacsFG",
        "V_TacVest_camo",
        "rhs_pdu4",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};
class GENFOR_RTO: GENFOR_Soldier_Base {
    _generalMacro = "GENFOR_RTO";
    scope = 2;
    displayName = "RTO";
    editorPreview = QPATHTOEF(common,data\previews\GENFOR_RTO.jpg);
    uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
    backpack = "GENFOR_B_Radio";
    weapons[] = {
        "rhs_weap_ak74m_pkas",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "rhs_weap_ak74m_pkas",
        "Throw",
        "Put"
    };
    magazines[] = {
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
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
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK",
        "rhs_30Rnd_545x39_AK_green",
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
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "SP_M88PSMHelmet_Green2",
        "G_Shades_Black",
        "V_TacVest_camo",
        "NVGoggles_OPFOR",
        "ItemMap",
        "ItemCompass",
        "ItemWatch"
    };
};