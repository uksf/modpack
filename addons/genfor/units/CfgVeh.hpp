//Vehicle
class GENFOR_P: GENFOR_Soldier_Base {
	_generalMacro = "GENFOR_P";
	scope = 2;
	displayName = "Pilot";
	editorSubcategory = QEGVAR(common,crew);
	editorPreview = QPATHTOEF(common,data\previews\GENFOR_P.jpg);
	uniformClass = "SP_0000_Standard_FieldUniform_Black";
	backpack = "";
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
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
	};
	respawnMagazines[] = {
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
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
		"SP_SPH4Helmet_Black",
		"SP_PlateCarrier1_Black",
		"NVGoggles_OPFOR",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
	respawnLinkedItems[] = {
		"SP_SPH4Helmet_Black",
		"SP_PlateCarrier1_Black",
		"NVGoggles_OPFOR",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
};
class GENFOR_FP: GENFOR_Soldier_Base {
	_generalMacro = "GENFOR_FP";
	scope = 2;
	displayName = "Fighter Pilot";
	editorSubcategory = QEGVAR(common,crew);
	editorPreview = QPATHTOEF(common,data\previews\GENFOR_FP.jpg);
	uniformClass = "U_O_PilotCoveralls";
	backpack = "ACE_ReserveParachute";
	weapons[] = {
		"Throw",
		"Put"
	};
	respawnWeapons[] = {
		"Throw",
		"Put"
	};
	magazines[] = {
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
	};
	respawnMagazines[] = {
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
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
		"H_PilotHelmetFighter_O",
		"SP_PlateCarrier1_Black",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
	respawnLinkedItems[] = {
		"H_PilotHelmetFighter_O",
		"SP_PlateCarrier1_Black",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
};
class GENFOR_C: GENFOR_Soldier_Base {
	_generalMacro = "GENFOR_C";
	scope = 2;
	displayName = "Heli Crew";
	editorSubcategory = QEGVAR(common,crew);
	editorPreview = QPATHTOEF(common,data\previews\GENFOR_C.jpg);
	uniformClass = "SP_0000_Standard_FieldUniform_Black_SS";
	backpack = "";
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
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
	};
	respawnMagazines[] = {
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
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
		"SP_SPH4Helmet_Black",
		"SP_PlateCarrier1_Black",
		"NVGoggles_OPFOR",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
	respawnLinkedItems[] = {
		"SP_SPH4Helmet_Black",
		"SP_PlateCarrier1_Black",
		"NVGoggles_OPFOR",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
};
class GENFOR_TC: GENFOR_Soldier_Base {
	_generalMacro = "GENFOR_TC";
	scope = 2;
	displayName = "Tank Crew";
	editorSubcategory = QEGVAR(common,crew);
	editorPreview = QPATHTOEF(common,data\previews\GENFOR_TC.jpg);
	icon = "iconManEngineer";
	engineer = 1;
	uniformClass = "SP_0000_Standard_FieldUniform_Tan";
	backpack = "";
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
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_mag_rgd5",
		"rhs_mag_rgd5",
		"rhs_mag_rgd5",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
	};
	respawnMagazines[] = {
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_30Rnd_545x39_AK",
		"rhs_mag_rgd5",
		"rhs_mag_rgd5",
		"rhs_mag_rgd5",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white",
		"rhs_mag_rdg2_white"
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
		"SP_TSH04Helmet_Black",
		"SP_PlateCarrier1_Tan",
		"NVGoggles_OPFOR",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
	respawnLinkedItems[] = {
		"SP_TSH04Helmet_Black",
		"SP_PlateCarrier1_Tan",
		"NVGoggles_OPFOR",
		"ItemMap",
		"ItemCompass",
		"ItemWatch"
	};
};
