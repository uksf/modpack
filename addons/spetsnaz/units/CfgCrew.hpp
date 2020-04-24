class GVAR(crew_jet) : GVAR(base) {
    scope = 2;
    displayName = "Jet Pilot";
    editorPreview = QPATHTOEF(common,data\previews\GVAR(crew_jet).jpg);
    editorSubcategory = QEGVAR(common,crew);
    uniformClass = "CUP_U_B_CZ_Pilot_WDL";
    backpack = "ACE_NonSteerableParachute";
    weapons[] = { "SMG_02_ACO_F_ACO_grn" };
    respawnWeapons[] = { "SMG_02_ACO_F_ACO_grn" };
    magazines[] = { "30Rnd_9x21_Mag_SMG_02_Tracer_Green", "30Rnd_9x21_Mag_SMG_02_Tracer_Green", "30Rnd_9x21_Mag_SMG_02_Tracer_Green", "SmokeShell", "Chemlight_red" };
    respawnMagazines[] = { "30Rnd_9x21_Mag_SMG_02_Tracer_Green", "30Rnd_9x21_Mag_SMG_02_Tracer_Green", "30Rnd_9x21_Mag_SMG_02_Tracer_Green", "SmokeShell", "Chemlight_red" };
    items[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_morphine" };
    respawnItems[] = { "ACE_fieldDressing", "ACE_fieldDressing", "ACE_morphine" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_PilotHelmetFighter_O" };
    resapwnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_PilotHelmetFighter_O" };
};
class GVAR(crew_heli) : GVAR(crew_jet) {
    displayName = "Heli Pilot";
    editorPreview = QPATHTOEF(common,data\previews\GVAR(crew_heli).jpg);
    uniformClass = "CUP_U_B_CZ_Pilot_WDL";
    backpack = "";
    weapons[] = { "CUP_arifle_AKS74U" };
    respawnWeapons[] = { "CUP_arifle_AKS74U" };
    magazines[] = { "CUP_30Rnd_545x39_AK74_plum_M", "CUP_30Rnd_545x39_AK74_plum_M", "CUP_30Rnd_545x39_AK74_plum_M", "CUP_20Rnd_545x39_AKSU_M", "CUP_20Rnd_545x39_AKSU_M", "CUP_20Rnd_545x39_AKSU_M", "CUP_20Rnd_545x39_AKSU_M" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74_plum_M", "CUP_30Rnd_545x39_AK74_plum_M", "CUP_30Rnd_545x39_AK74_plum_M", "CUP_20Rnd_545x39_AKSU_M", "CUP_20Rnd_545x39_AKSU_M", "CUP_20Rnd_545x39_AKSU_M", "CUP_20Rnd_545x39_AKSU_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "ItemGPS", "CUP_H_RUS_ZSH_Shield_Up", "CUP_V_CZ_vest20" };
    resapwnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "ItemGPS", "CUP_H_RUS_ZSH_Shield_Up", "CUP_V_CZ_vest20" };
};
